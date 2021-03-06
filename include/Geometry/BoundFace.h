// =======================================================================
// @(#)BoundFace.h        1.3 12/07/99
// 
// Class:       TBoundFace
// Purpose:     face on a boundary component
//
// Author:      Volker Behns  02.08.97
//
// =======================================================================

#ifndef __BOUNDFACE__
#define __BOUNDFACE__

#include <BoundComp3D.h>
#include <Joint.h>

/** face on a boundary component */
class TBoundFace : public TJoint
{
  protected:
    // boundary component to which this face belongs
    TBoundComp3D *BoundComp;

    // parameter values for the vertices
    double Param1[4];
    double Param2[4];

  public:
    // Constructors
    TBoundFace(TBoundComp3D *bdcomp, double *param1, double *param2);

    TBoundFace(TBoundComp3D *bdcomp);

    // Methods
    /** check whether the refinement pattern on both side patch,
        dummy here: there is no neighbour */
    virtual int CheckMatchingRef(TBaseCell *Me, int J_i,
                  struct StoreGeom &Tmp);

    /** create a new instance of this class */
    virtual TJoint *NewInst(double T_0, double T_1, TBaseCell *Me);
    virtual TJoint *NewInst();

    /** return whether this is an interior joint */
    virtual bool InnerJoint()  const
    { return false; }

    /** return boundary component */
    TBoundComp3D *GetBoundComp()
    { return BoundComp; }

    /** return both parameters arrays */
    void GetParameters(double *param1, double *param2);

    void SetParameters(double *param1, double *param2);
};

#endif
