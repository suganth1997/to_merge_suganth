// =======================================================================
// @(#)SquareMatrix.h        1.3 11/20/98
// 
// Class:       TSquareMatrix
//
// Purpose:     store a square matrix (ansatz = test space)
//
// Author:      Gunar Matthies
//
// History:     10.08.1998 start implementation
//
// =======================================================================

#ifndef __SQUAREMATRIX__
#define __SQUAREMATRIX__

#include <Matrix.h>
#include <SquareStructure.h>

class TSquareMatrix : public TMatrix
{
  protected:
    /** the sparsity structure of this matrix */
    TSquareStructure *structure;

    /** bound for hanging nodes 
     * @todo is this structure->HangingN_Entries ?? */
    int HangingBound;

    /** ordering of the column entries */
    /** 0 - no special ordering */
    /** 1 - increasing ordering (like used for umfpack) */
    /** 2 - diagonal entry first, then increasing ordering */
    int ColOrder;
  
  public:
    /** generate the matrix */
    TSquareMatrix(TSquareStructure *structure);
    
    /** generate an empty n*n zero matrix */
//     explicit TSquareMatrix(int n);

    /** destructor: free Entries array */
    ~TSquareMatrix();

    /** reset all entries in active rows */
    void ResetActive();
    
    /** @brief set zeros in nonactive rows. 
     * 
     * This is e.g. for the off-diagonal blocks in a Stokes matrix 
     */
    void resetNonActive();

    /** determine renumbering */
    void ReNumbering(int* &Numbers) const;

    /** return ActiveBound */
    int GetActiveBound() const
    { return structure->GetActiveBound(); }
    
    /** return ordering of columns */
    int GetColOrder() const
    { return structure->GetColOrder(); }
    
    void SetStructure(TSquareStructure *structure);
    
    TSquareStructure *GetStructure() const
    { return structure; }

    /** write matrix into file */
    int Write(const char *filename);
    
    /** print matrix */
    void Print();
};

#endif
