// =======================================================================
// @(#)MultiGridIte.C        1.24 06/27/00
//
// Class:       TMultiGridIte
// Purpose:     iteration methods
//
// Author:      Volker John 24.10.2000
//
// History:     24.10.2000 start of implementation
//
// =======================================================================
#include <ItMethod.h>
#include <MultiGridIte.h>
#include <MooNMD_Io.h>
#include <Database.h>
#include <LinAlg.h>
#include <NSE_MultiGrid.h>

#ifdef _MPI
#include <mpi.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/** constructor with initialization */
TMultiGridIte::TMultiGridIte(MatVecProc *MatVec, 
                             DefectProc *Defect, 
                             TItMethod *Prec,
                             int n_aux, int n_dof,
                             TNSE_MultiGrid *MG, int zero_start)
  : TItMethod(MatVec, Defect, Prec, n_aux, n_dof)
                                    
{

  mg = MG;
  N_DOF = n_dof;
  N_Aux = 0;
  Zero_Start=zero_start;
  
  matvec = MatVec;
  matvecdefect = Defect;
}

TMultiGridIte::~TMultiGridIte()
{
}

int TMultiGridIte::Iterate (TSquareMatrix **sqmat,
                            TMatrix **mat, double *sol, 
                            double *rhs)
{
  double res, *mgsol, *mgrhs;
  int umfpack_flag;
  int rank=0;
  
#ifdef _MPI
 MPI_Comm_rank(TDatabase::ParamDB->Comm,&rank);
#endif
  
  mg->GetLevel(mg->GetN_Levels()-1)->GetSolutionVector(mgsol);
  mg->GetLevel(mg->GetN_Levels()-1)->GetRhsVector(mgrhs);
  
// ======================	Zero_Start doesnt matter for GMRES 
//	======================		sol is already set to zero before calling
    
  if (Zero_Start)
    memset(mgsol, 0, N_DOF*SizeOfDouble);
  else
    memcpy(mgsol, sol, N_DOF*SizeOfDouble);

// ======================	
//	======================		End of Zero_Start

     
  memcpy(mgrhs, rhs, N_DOF*SizeOfDouble);
  

  mg->SetDirichletNodes(mg->GetN_Levels()-1);
  mg->SetRecursion(mg->GetN_Levels()-1);
  // one multigrid cycle
  
#ifdef _MPI
  TDatabase::ParamDB->time_MG_start = MPI_Wtime();
#else
  TDatabase::ParamDB->time_MG_start = GetTime();
#endif

  mg->Cycle(mg->GetN_Levels()-1, res);
  
#ifdef _MPI
  TDatabase::ParamDB->time_MG_end = MPI_Wtime();
#else
  TDatabase::ParamDB->time_MG_end = GetTime();
#endif

  TDatabase::ParamDB->time_MG += TDatabase::ParamDB->time_MG_end - TDatabase::ParamDB->time_MG_start; 
  
  if(TDatabase::ParamDB->MG_DEBUG && rank==0)
    printf("==============	Residual at the end of cycle :: %lf =======================\n",res);
  
  // store solution on rhs
  memcpy(sol, mgsol, N_DOF*SizeOfDouble);
  return(0);
}                        
