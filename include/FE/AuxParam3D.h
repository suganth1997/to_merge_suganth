// =======================================================================
// %W% %G%
// 
// Class:       TAuxParam3D
// Purpose:     store parameter functions and FE functions
//
// Author:      Gunar Matthies (06.08.98)
//
// History:     start of implementation 06.08.98 (Gunar Matthies)
//
// =======================================================================

#ifndef __AUXPARAM3D__
#define __AUXPARAM3D__

#include <Constants.h>
#include <FESpace3D.h>
#include <FEFunction3D.h>

/** store parameter functions and FE functions */
class TAuxParam3D
{
  protected:
// =======================================================================
//  numbers of stored objects
// =======================================================================
    /** number of stored FESpace3D */
    int N_FESpace3D;

    /** number of stored FEFunction3D */
    int N_FEFunction3D;

    /** number of stored parameter function (ParamFct) */
    int N_ParamFct;

// =======================================================================
//  array of pointers to stored objects
// =======================================================================
    /** array of stored FESpace3D */
    TFESpace3D **FESpaces3D;

    /** array of stored FEFunction3D */
    TFEFunction3D **FEFunctions3D;

    /** array of stored parameter function */
    ParamFct **ParameterFct;

// =======================================================================
//  information of FE values used by parameter functions
// =======================================================================
    /** number of FE values */
    int N_FEValues;

    /** index of FEFunction3D used for FE value i */
    int *FEValue_FctIndex;

    /** which multiindex is used for FE value i */
    MultiIndex3D *FEValue_MultiIndex;

// =======================================================================
//  information of parameter functions
// =======================================================================
    /** number of all parameters */
    int N_Parameters;

    /** index of first parameter produced by parameter function i */
    int *BeginParameter;

// =======================================================================
//  information of parameter functions
// =======================================================================
    /** storage for temporary FE values */
    double *Temp;

    double **Values;
    double ***OrigValues;
    int **Index;
    int *N_BaseFunct;

  public:
    /** constructor */
    TAuxParam3D(int n_fespace3d, int n_fefunction3d, int n_paramfct,
              int n_fevalues,
              TFESpace3D **fespaces3d, TFEFunction3D **fefunctions3d,
              ParamFct **parameterfct,
              int *fevalue_fctindex, MultiIndex3D *fevalue_multiindex,
              int n_parameters, int *beginparameter);
    /** @brief standard constructor
     * 
     * If you don't need values of a finite element function in your assembling,
     * choose this constructor. This is equivalent to calling 
     * TAuxParam3D(0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, NULL);
     */

    TAuxParam3D(std::string name, TFEFunction3D **fefunctions3d);
    

    /** destructor */
    ~TAuxParam3D();

    /** return all parameters at all quadrature points */
    void GetParameters(int n_points, TBaseCell *cell, int cellnum,
                       double *xi, double *eta, double *zeta,
                       double *x, double *y, double *z,
                       double **Parameters);

    int GetN_Parameters()
    { return N_Parameters; }

};

// standard function to use for Navier-Stokes
void Velocity_Fct(double *inputList, double *outputValues);

#endif // __AUXPARAM3D__
