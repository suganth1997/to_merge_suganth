/*
    TNodalFunctional3D(NodalFunctional3D id,
                       int n_allfunctionals, int *n_facefunctionals,
                       int n_pointsall, int *n_pointsface,
                       double *xi, double *eta, double *zeta,
                       double **xiarray, double **etaarray,
                       double **zetaarray,
                       DoubleFunctVect *evalall,
                       DoubleFunctVect *evalface);
*/

/* for all functionals */
static double NF_C_T_P3_3D_Xi[]   = {
        0, 0.33333333333333333333, 0.66666666666666666667, 1,
        0, 0.33333333333333333333, 0.66666666666666666667,
        0, 0.33333333333333333333,
        0,
        0, 0.33333333333333333333, 0.66666666666666666667,
        0, 0.33333333333333333333,
        0,
        0, 0.33333333333333333333,
        0,
        0 };
static double NF_C_T_P3_3D_Eta[]  = {
        0, 0, 0, 0,
        0.33333333333333333333, 0.33333333333333333333,
        0.33333333333333333333,
        0.66666666666666666667, 0.66666666666666666667,
        1,
        0, 0, 0,
        0.33333333333333333333, 0.33333333333333333333,
        0.66666666666666666667,
        0, 0,
        0.33333333333333333333,
        0 };
static double NF_C_T_P3_3D_Zeta[] = {
        0, 0, 0, 0,
        0, 0, 0,
        0, 0, 
        0,
        0.33333333333333333333, 0.33333333333333333333,
        0.33333333333333333333, 0.33333333333333333333,
        0.33333333333333333333, 0.33333333333333333333,
        0.66666666666666666667, 0.66666666666666666667,
        0.66666666666666666667,
        1 };

/* face 0 */
static double NF_C_T_P3_3D_F0_Xi[]   = {
   0, 0.33333333333333, 0.66666666666667,
   1, 0, 0.33333333333333, 0.66666666666667,
   0, 0.33333333333333, 0 };
static double NF_C_T_P3_3D_F0_Eta[]  = {
   0, 0, 0, 0,
   0.33333333333333, 0.33333333333333,
   0.33333333333333, 0.66666666666667,
   0.66666666666667, 1 };
static double NF_C_T_P3_3D_F0_Zeta[] = {
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

/* face 1 */
static double NF_C_T_P3_3D_F1_Xi[]   = {
   0, 0, 0, 0,
   0.33333333333333, 0.33333333333333,
   0.33333333333333, 0.66666666666667,
   0.66666666666667, 1 };
static double NF_C_T_P3_3D_F1_Eta[]  = {
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static double NF_C_T_P3_3D_F1_Zeta[] = {
   0, 0.33333333333333, 0.66666666666667,
   1, 0, 0.33333333333333,
   0.66666666666667, 0,
   0.33333333333333, 0 };

/* face 2 */
static double NF_C_T_P3_3D_F2_Xi[]   = {
   0, 0.33333333333333, 0.66666666666667,
   1, 0, 0.33333333333333,
   0.66666666666667, 0,
   0.33333333333333, 0 };
static double NF_C_T_P3_3D_F2_Eta[]  = {
   1, 0.66666666666667, 0.33333333333333,
   0, 0.66666666666667, 0.33333333333333,
   0, 0.33333333333333, 0, 0 };
static double NF_C_T_P3_3D_F2_Zeta[] = {
   0, 0, 0, 0,
   0.33333333333333, 0.33333333333333,
   0.33333333333333, 0.66666666666667,
   0.66666666666667, 1 };

/* face 3 */
static double NF_C_T_P3_3D_F3_Xi[]   = {
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static double NF_C_T_P3_3D_F3_Eta[]  = {
   0, 0.33333333333333, 0.66666666666667,
   1, 0, 0.33333333333333,
   0.66666666666667, 0,
   0.33333333333333, 0 };
static double NF_C_T_P3_3D_F3_Zeta[] = {
   0, 0, 0, 0,
   0.33333333333333, 0.33333333333333,
   0.33333333333333, 0.66666666666667,
   0.66666666666667, 1 };

static double *NF_C_T_P3_3D_XiArray[4] = { 
                        NF_C_T_P3_3D_F0_Xi,
                        NF_C_T_P3_3D_F1_Xi,
                        NF_C_T_P3_3D_F2_Xi,
                        NF_C_T_P3_3D_F3_Xi };

static double *NF_C_T_P3_3D_EtaArray[4] = { 
                        NF_C_T_P3_3D_F0_Eta,
                        NF_C_T_P3_3D_F1_Eta,
                        NF_C_T_P3_3D_F2_Eta,
                        NF_C_T_P3_3D_F3_Eta };

static double *NF_C_T_P3_3D_ZetaArray[4] = { 
                        NF_C_T_P3_3D_F0_Zeta,
                        NF_C_T_P3_3D_F1_Zeta,
                        NF_C_T_P3_3D_F2_Zeta,
                        NF_C_T_P3_3D_F3_Zeta };

static double NF_C_T_P3_3D_T[10] = {
        0, 0.33333333333333333333, 0.66666666666666666667, 1,
        0, 0.33333333333333333333, 0.66666666666666666667,
        0, 0.33333333333333333333,
        0 };
static double NF_C_T_P3_3D_S[10] = {
        0, 0, 0, 0,
        0.33333333333333333333, 0.33333333333333333333,
        0.33333333333333333333,
        0.66666666666666666667, 0.66666666666666666667,
        1 };

void NF_C_T_P3_3D_EvalAll(TCollection *Coll, TBaseCell *Cell,
                          double *PointValues, double *Functionals)
{
  memcpy(Functionals, PointValues, 20*SizeOfDouble);
}

void NF_C_T_P3_3D_EvalFace(TCollection *Coll, TBaseCell *Cell, int Joint, 
                           double *PointValues, double *Functionals)
{
  memcpy(Functionals, PointValues, 10*SizeOfDouble);
}

static int NF_C_T_P3_3D_N_AllFunctionals = 20;
static int NF_C_T_P3_3D_N_PointsAll = 20;
static int NF_C_T_P3_3D_N_FaceFunctionals[] = { 10, 10, 10, 10, 10, 10 };
static int NF_C_T_P3_3D_N_PointsFace[] = { 10, 10, 10, 10, 10, 10 };

TNodalFunctional3D *NF_C_T_P3_3D_Obj = new TNodalFunctional3D
        (NF_C_T_P3_3D, NF_C_T_P3_3D_N_AllFunctionals,
         NF_C_T_P3_3D_N_FaceFunctionals, NF_C_T_P3_3D_N_PointsAll,
         NF_C_T_P3_3D_N_PointsFace,
         NF_C_T_P3_3D_Xi, NF_C_T_P3_3D_Eta, NF_C_T_P3_3D_Zeta,
         NF_C_T_P3_3D_XiArray, NF_C_T_P3_3D_EtaArray,
         NF_C_T_P3_3D_ZetaArray,
         NF_C_T_P3_3D_T, NF_C_T_P3_3D_S,
         NF_C_T_P3_3D_EvalAll, NF_C_T_P3_3D_EvalFace);
