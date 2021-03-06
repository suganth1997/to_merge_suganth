// =======================================================================
// @(#)NSE_MGLevel3.h        1.6 07/03/00
//
// Class:       TNSE_MGLevel3
// Purpose:     store all data for one level in a multi grid method
//              for solving a Stokes-/ Navier-Stokes system of
//              type 3 (all Aij, B1, B2, B3)
//
// Author:      Volker John 25.07.2000
//
// History:      25.07.2000start of implementation
//
// =======================================================================

#ifndef __NSE_MGLEVEL3__
#define __NSE_MGLEVEL3__

#include <NSE_MGLevel.h>

class TNSE_MGLevel3 : public TNSE_MGLevel
{
  protected:
#ifdef __2D__
    /** matrix A11 */
    TSquareMatrix2D *A11;

    /** matrix A12 */
    TSquareMatrix2D *A12;

    /** matrix A21 */
    TSquareMatrix2D *A21;

    /** matrix A22 */
    TSquareMatrix2D *A22;

    /** structure of matrix A */
    TSquareStructure2D *StructureA;

    /** matrix B1 */
    TMatrix2D *B1;

    /** matrix B2 */
    TMatrix2D *B2;

    /** structure of matrix B */
    TStructure2D *StructureB;

    /** structure of matrix BT */
    TStructure2D *StructureBT;
#endif  

#ifdef __3D__
    /** matrix A11 */
    TSquareMatrix3D *A11;

    /** matrix A12 */
    TSquareMatrix3D *A12;

    /** matrix A13 */
    TSquareMatrix3D *A13;

    /** matrix A21 */
    TSquareMatrix3D *A21;

    /** matrix A22 */
    TSquareMatrix3D *A22;

    /** matrix A23 */
    TSquareMatrix3D *A23;

    /** matrix A31 */
    TSquareMatrix3D *A31;

    /** matrix A32 */
    TSquareMatrix3D *A32;

    /** matrix A33 */
    TSquareMatrix3D *A33;

    /** structure of matrix A */
    TSquareStructure3D *StructureA;

    /** matrix B1 */
    TMatrix3D *B1;

    /** matrix B2 */
    TMatrix3D *B2;

    /** matrix B3 */
    TMatrix3D *B3;

    /** structure of matrix B */
    TStructure3D *StructureB;
 
    /** structure of matrix BT */
    TStructure3D *StructureBT;
#endif  

    /** row pointer for matrix A */
    int *ARowPtr;

    /** column number vector for matrix A */
    int *AKCol;

    /** matrix entries of matrix A */
    double *A11Entries;

    /** matrix entries of matrix A */
    double *A12Entries;

    /** matrix entries of matrix A */
    double *A21Entries;

    /** matrix entries of matrix A */
    double *A22Entries;

    /** matrix entries of matrix B1 */
    double *B1Entries;

    /** matrix entries of matrix B2 */
    double *B2Entries;

#ifdef __3D__
    /** matrix entries of matrix A */
    double *A13Entries;

    /** matrix entries of matrix A */
    double *A23Entries;

    /** matrix entries of matrix A */
    double *A31Entries;

    /** matrix entries of matrix A */
    double *A32Entries;

    /** matrix entries of matrix A */
    double *A33Entries;

    /** matrix entries of matrix B3 */
    double *B3Entries;
#endif  

    /** row pointer for matrix B */
    int *BRowPtr;

    /** column number vector for matrix B */
    int *BKCol;

    /** row pointer for matrix BT */
    int *BTRowPtr;

    /** column number vector for matrix BT */
    int *BTKCol;
    
  public:
    /** constructor */
#ifdef __2D__
    TNSE_MGLevel3(int level, 
                  TSquareMatrix2D *A11, TSquareMatrix2D *A12, 
                  TSquareMatrix2D *A21, TSquareMatrix2D *A22, 
                  TMatrix2D *B1, TMatrix2D *B2,
                  TStructure2D *structureBT, 
                  double *f1, double *u1,
                  int n_aux, double *al, int VelocitySpace, 
                  int PressureSpace, TCollection *coll,
                  int *dw);
#endif  
#ifdef __3D__
    TNSE_MGLevel3(int level, 
                  TSquareMatrix3D *A11, TSquareMatrix3D *A12, 
                  TSquareMatrix3D *A13, 
                  TSquareMatrix3D *A21, TSquareMatrix3D *A22, 
                  TSquareMatrix3D *A23, 
                  TSquareMatrix3D *A31, TSquareMatrix3D *A32, 
                  TSquareMatrix3D *A33, 
                  TMatrix3D *B1, TMatrix3D *B2, TMatrix3D *B3,  
                  TStructure3D *structureBT, 
                  double *f1, double *u1,
                  int n_aux, double *al, int VelocitySpace, 
                  int PressureSpace, TCollection *coll,
                  int *dw);
#endif  

    /** destructor */
    ~TNSE_MGLevel3();

    virtual void Defect(double *u1, double *f1, double *d1, double &res);

    /** correct Dirichlet and hanging nodes */
    virtual void CorrectNodes(double *u1);

    /** Vanka smoother */
    virtual void CellVanka(double *u1, double *rhs1, double *aux, 
        int N_Parameters, double *Parameters, int smoother, int N_Levels);

    /** Vanka smoother */
    virtual void NodalVanka(double *u1, double *rhs1, double *aux, 
        int N_Parameters, double *Parameters, int smoother, int N_Levels);

    /** solve exact on this level */
    virtual void SolveExact(double *u1, double *rhs1);

    /** solve exact on this level */
    virtual void SolveExactUMFPACK(double *u1, double *rhs1, int &umfpack_flag);

    /** Braess Sarazin smoother */
    virtual void BraessSarazin(double *u1, double *rhs1, double *aux,
        int N_Parameters, double *Parameters,int N_Levels);

    /** step length control for Vanka */
    virtual double StepLengthControl(double *u1, double *u1old, double *def1,
                                     int N_Parameters, double *Parameter);

    /** print all matrices and both right hand sides */
    virtual void PrintAll();
#ifdef _MPI
    virtual void UpdateHaloRhs(double* a, double* b)
    {
      
    }; 
#endif
    
};

#endif
