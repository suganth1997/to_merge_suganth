// =======================================================================
// @(#)NSE_MGLevel2.h        1.6 07/03/00
//
// Class:       TNSE_MGLevel2
// Purpose:     store all data for one level in a multi grid method
//              for solving a Stokes-/ Navier-Stokes system of
//              type 2 (A, B1, B2, B3, B1T, B2T, B3T)
//
// Author:      Volker John 25.07.2000
//
// History:     25.07.2000 start of implementation
//
// =======================================================================

#ifndef __NSE_MGLEVEL2__
#define __NSE_MGLEVEL2__

#include <NSE_MGLevel.h>

class TNSE_MGLevel2 : public TNSE_MGLevel
{
  protected:
#ifdef __2D__
    /** matrix A */
    TSquareMatrix2D *A;

    /** structure of matrix A */
    TSquareStructure2D *StructureA;

    /** structure of matrix B */
    TStructure2D *StructureB;

    /** matrix B1 */
    TMatrix2D *B1;

    /** matrix B2 */
    TMatrix2D *B2;

    /** structure of matrix BT */
    TStructure2D *StructureBT;

    /** matrix B1T */
    TMatrix2D *B1T;

    /** matrix B2 */
    TMatrix2D *B2T;

    /** structure of matrix C */
    TStructure2D *StructureC;

    /** matrix C */
    TMatrix2D *C;
#endif  

#ifdef __3D__
    /** matrix A */
    TSquareMatrix3D *A;

    /** structure of matrix A */
    TSquareStructure3D *StructureA;

    /** structure of matrix B */
    TStructure3D *StructureB;

    /** matrix B1 */
    TMatrix3D *B1;

    /** matrix B2 */
    TMatrix3D *B2;

    /** matrix B3 */
    TMatrix3D *B3;

    /** structure of matrix BT */
    TStructure3D *StructureBT;

    /** matrix B1T */
    TMatrix3D *B1T;

    /** matrix B2 */
    TMatrix3D *B2T;

    /** matrix B3 */
    TMatrix3D *B3T;

    /** structure of matrix C */
    TStructure3D *StructureC;

    /** matrix C */
    TMatrix3D *C;
#endif  

    /** row pointer for matrix A */
    int *ARowPtr;

    /** column number vector for matrix A */
    int *AKCol;

    /** matrix entries of matrix A */
    double *AEntries;

    /** row pointer for matrix B */
    int *BRowPtr;

    /** column number vector for matrix B */
    int *BKCol;

    /** matrix entries of matrix B1 */
    double *B1Entries;

    /** matrix entries of matrix B2 */
    double *B2Entries;

#ifdef __3D__
    /** matrix entries of matrix B3 */
    double *B3Entries;
#endif  

    /** row pointer for matrix BT */
    int *BTRowPtr;

    /** column number vector for matrix BT */
    int *BTKCol;

    /** matrix entries of matrix BT1 */
    double *B1TEntries;

    /** matrix entries of matrix BT2 */
    double *B2TEntries;

#ifdef __3D__
    /** matrix entries of matrix BT3 */
    double *B3TEntries;
#endif  

    /** row pointer for matrix C */
    int *CRowPtr;

    /** column number vector for matrix C */
    int *CKCol;

    /** matrix entries of matrix C */
    double *CEntries;

  public:
    /** constructor */
#ifdef __2D__
    TNSE_MGLevel2(int level, TSquareMatrix2D *A, 
                  TMatrix2D *B1, TMatrix2D *B2,
                  TMatrix2D *B1T, TMatrix2D *B2T,
                  double *f1, double *u1, 
                  int n_aux, double *al, int VelocitySpace, 
                  int PressureSpace, TCollection *coll,
                  int *dw);

    /** contructor with matrix C */
    TNSE_MGLevel2(int level, TSquareMatrix2D *A, 
                  TMatrix2D *B1, TMatrix2D *B2,
                  TMatrix2D *B1T, TMatrix2D *B2T,
                  TMatrix2D *C,
                  double *f1, double *u1, 
                  int n_aux, double *al, int VelocitySpace, 
                  int PressureSpace, TCollection *coll,
                  int *dw);
#endif  

#ifdef __3D__
    TNSE_MGLevel2(int level, TSquareMatrix3D *A, 
                  TMatrix3D *B1, TMatrix3D *B2, TMatrix3D *B3,
                  TMatrix3D *B1T, TMatrix3D *B2T, TMatrix3D *B3T,
                  double *f1, double *u1, 
                  int n_aux, double *al, int VelocitySpace, 
                  int PressureSpace, TCollection *coll,
                  int *dw);

    /** contructor with matrix C */
    TNSE_MGLevel2(int level, TSquareMatrix3D *A, 
                  TMatrix3D *B1, TMatrix3D *B2, TMatrix3D *B3,
                  TMatrix3D *B1T, TMatrix3D *B2T, TMatrix3D *B3T,
                  TMatrix3D *C,
                  double *f1, double *u1, 
                  int n_aux, double *al, int VelocitySpace, 
                  int PressureSpace, TCollection *coll,
                  int *dw);
#endif  

    /** destructor */
    ~TNSE_MGLevel2();

    /** calculate defect */
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
    virtual void UpdateHaloRhs(double* a, double* b){
      
    }; 
    #endif

};

#endif
