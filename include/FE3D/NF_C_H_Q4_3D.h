/*
    TNodalFunctional3D(NodalFunctional3D id,
                       int n_allfunctionals, int *n_facefunctionals,
                       int n_pointsall, int *n_pointsface,
                       double *xi, double *eta, double *zeta,
                       double **xiarray, double **etaarray,
                       double **zetaarray,
                       double *t, double *s,
                       DoubleFunctVect *evalall,
                       DoubleFunctVect *evalface);
*/

/* for all functionals */
static double NF_C_H_Q4_3D_Xi[125]   = { 
       -1.0, -0.5, 0.0, 0.5, 1.0,
       -1.0, -0.5, 0.0, 0.5, 1.0,
       -1.0, -0.5, 0.0, 0.5, 1.0,
       -1.0, -0.5, 0.0, 0.5, 1.0,
       -1.0, -0.5, 0.0, 0.5, 1.0,
       -1.0, -0.5, 0.0, 0.5, 1.0,
       -1.0, -0.5, 0.0, 0.5, 1.0,
       -1.0, -0.5, 0.0, 0.5, 1.0,
       -1.0, -0.5, 0.0, 0.5, 1.0,
       -1.0, -0.5, 0.0, 0.5, 1.0,
       -1.0, -0.5, 0.0, 0.5, 1.0,
       -1.0, -0.5, 0.0, 0.5, 1.0,
       -1.0, -0.5, 0.0, 0.5, 1.0,
       -1.0, -0.5, 0.0, 0.5, 1.0,
       -1.0, -0.5, 0.0, 0.5, 1.0,
       -1.0, -0.5, 0.0, 0.5, 1.0,
       -1.0, -0.5, 0.0, 0.5, 1.0,
       -1.0, -0.5, 0.0, 0.5, 1.0,
       -1.0, -0.5, 0.0, 0.5, 1.0,
       -1.0, -0.5, 0.0, 0.5, 1.0,
       -1.0, -0.5, 0.0, 0.5, 1.0,
       -1.0, -0.5, 0.0, 0.5, 1.0,
       -1.0, -0.5, 0.0, 0.5, 1.0,
       -1.0, -0.5, 0.0, 0.5, 1.0,
       -1.0, -0.5, 0.0, 0.5, 1.0 };
static double NF_C_H_Q4_3D_Eta[125]  = {
       -1.0, -1.0, -1.0, -1.0, -1.0,
       -0.5, -0.5, -0.5, -0.5, -0.5,
        0.0,  0.0,  0.0,  0.0,  0.0,
        0.5,  0.5,  0.5,  0.5,  0.5,
        1.0,  1.0,  1.0,  1.0,  1.0,
       -1.0, -1.0, -1.0, -1.0, -1.0,
       -0.5, -0.5, -0.5, -0.5, -0.5,
        0.0,  0.0,  0.0,  0.0,  0.0,
        0.5,  0.5,  0.5,  0.5,  0.5,
        1.0,  1.0,  1.0,  1.0,  1.0,
       -1.0, -1.0, -1.0, -1.0, -1.0,
       -0.5, -0.5, -0.5, -0.5, -0.5,
        0.0,  0.0,  0.0,  0.0,  0.0,
        0.5,  0.5,  0.5,  0.5,  0.5,
        1.0,  1.0,  1.0,  1.0,  1.0,
       -1.0, -1.0, -1.0, -1.0, -1.0,
       -0.5, -0.5, -0.5, -0.5, -0.5,
        0.0,  0.0,  0.0,  0.0,  0.0,
        0.5,  0.5,  0.5,  0.5,  0.5,
        1.0,  1.0,  1.0,  1.0,  1.0,
       -1.0, -1.0, -1.0, -1.0, -1.0,
       -0.5, -0.5, -0.5, -0.5, -0.5,
        0.0,  0.0,  0.0,  0.0,  0.0,
        0.5,  0.5,  0.5,  0.5,  0.5,
        1.0,  1.0,  1.0,  1.0,  1.0 };
static double NF_C_H_Q4_3D_Zeta[125] = {
       -1.0, -1.0, -1.0, -1.0, -1.0,
       -1.0, -1.0, -1.0, -1.0, -1.0,
       -1.0, -1.0, -1.0, -1.0, -1.0,
       -1.0, -1.0, -1.0, -1.0, -1.0,
       -1.0, -1.0, -1.0, -1.0, -1.0,
       -0.5, -0.5, -0.5, -0.5, -0.5,
       -0.5, -0.5, -0.5, -0.5, -0.5,
       -0.5, -0.5, -0.5, -0.5, -0.5,
       -0.5, -0.5, -0.5, -0.5, -0.5,
       -0.5, -0.5, -0.5, -0.5, -0.5,
        0.0,  0.0,  0.0,  0.0,  0.0,
        0.0,  0.0,  0.0,  0.0,  0.0,
        0.0,  0.0,  0.0,  0.0,  0.0,
        0.0,  0.0,  0.0,  0.0,  0.0,
        0.0,  0.0,  0.0,  0.0,  0.0,
        0.5,  0.5,  0.5,  0.5,  0.5,
        0.5,  0.5,  0.5,  0.5,  0.5,
        0.5,  0.5,  0.5,  0.5,  0.5,
        0.5,  0.5,  0.5,  0.5,  0.5,
        0.5,  0.5,  0.5,  0.5,  0.5,
        1.0,  1.0,  1.0,  1.0,  1.0,
        1.0,  1.0,  1.0,  1.0,  1.0,
        1.0,  1.0,  1.0,  1.0,  1.0,
        1.0,  1.0,  1.0,  1.0,  1.0,
        1.0,  1.0,  1.0,  1.0,  1.0 };

/* face 0 */
static double NF_C_H_Q4_3D_F0_Xi[]   = {
   -1.0000, -0.5000, 0, 0.5000, 1.0000,
   -1.0000, -0.5000, 0, 0.5000, 1.0000,
   -1.0000, -0.5000, 0, 0.5000, 1.0000,
   -1.0000, -0.5000, 0, 0.5000, 1.0000,
   -1.0000, -0.5000, 0, 0.5000, 1.0000 };

static double NF_C_H_Q4_3D_F0_Eta[]  = {
   -1.0000, -1.0000, -1.0000, -1.0000, -1.0000,
   -0.5000, -0.5000, -0.5000, -0.5000, -0.5000,
         0, 0, 0, 0, 0,
    0.5000, 0.5000, 0.5000, 0.5000, 0.5000,
    1.0000, 1.0000, 1.0000, 1.0000, 1.0000 };

static double NF_C_H_Q4_3D_F0_Zeta[] = {
    -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1 };

/* face 1 */
static double NF_C_H_Q4_3D_F1_Xi[]   = {
   -1.0000, -1.0000, -1.0000, -1.0000, -1.0000,
   -0.5000, -0.5000, -0.5000, -0.5000, -0.5000,
         0, 0, 0, 0, 0,
    0.5000, 0.5000, 0.5000, 0.5000, 0.5000,
    1.0000, 1.0000, 1.0000, 1.0000, 1.0000 };

static double NF_C_H_Q4_3D_F1_Eta[]  = {
    -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1 };

static double NF_C_H_Q4_3D_F1_Zeta[] = {
   -1.0000, -0.5000, 0, 0.5000, 1.0000,
   -1.0000, -0.5000, 0, 0.5000, 1.0000,
   -1.0000, -0.5000, 0, 0.5000, 1.0000,
   -1.0000, -0.5000, 0, 0.5000, 1.0000,
   -1.0000, -0.5000, 0, 0.5000, 1.0000 };


/* face 2 */
static double NF_C_H_Q4_3D_F2_Xi[]   = {
     1, 1, 1, 1, 1,
     1, 1, 1, 1, 1,
     1, 1, 1, 1, 1,
     1, 1, 1, 1, 1,
     1, 1, 1, 1, 1 };

static double NF_C_H_Q4_3D_F2_Eta[]  = {
   -1.0000, -1.0000, -1.0000, -1.0000, -1.0000,
   -0.5000, -0.5000, -0.5000, -0.5000, -0.5000,
         0, 0, 0, 0, 0,
    0.5000, 0.5000, 0.5000, 0.5000, 0.5000,
    1.0000, 1.0000, 1.0000, 1.0000, 1.0000 };

static double NF_C_H_Q4_3D_F2_Zeta[] = {
   -1.0000, -0.5000, 0, 0.5000, 1.0000,
   -1.0000, -0.5000, 0, 0.5000, 1.0000,
   -1.0000, -0.5000, 0, 0.5000, 1.0000,
   -1.0000, -0.5000, 0, 0.5000, 1.0000,
   -1.0000, -0.5000, 0, 0.5000, 1.0000 };


/* face 3 */
static double NF_C_H_Q4_3D_F3_Xi[]   = {
    1.0000, 1.0000, 1.0000, 1.0000, 1.0000,
    0.5000, 0.5000, 0.5000, 0.5000, 0.5000,
         0, 0, 0, 0, 0,
   -0.5000, -0.5000, -0.5000, -0.5000, -0.5000,
   -1.0000, -1.0000, -1.0000, -1.0000, -1.0000 };

static double NF_C_H_Q4_3D_F3_Eta[]  = {
     1, 1, 1, 1, 1,
     1, 1, 1, 1, 1,
     1, 1, 1, 1, 1,
     1, 1, 1, 1, 1,
     1, 1, 1, 1, 1 };

static double NF_C_H_Q4_3D_F3_Zeta[] = { 
   -1.0000, -0.5000, 0, 0.5000, 1.0000,
   -1.0000, -0.5000, 0, 0.5000, 1.0000,
   -1.0000, -0.5000, 0, 0.5000, 1.0000,
   -1.0000, -0.5000, 0, 0.5000, 1.0000,
   -1.0000, -0.5000, 0, 0.5000, 1.0000 };


/* face 4 */
static double NF_C_H_Q4_3D_F4_Xi[]   = {
    -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1 };

static double NF_C_H_Q4_3D_F4_Eta[]  = {
   -1.0000, -0.5000, 0, 0.5000, 1.0000,
   -1.0000, -0.5000, 0, 0.5000, 1.0000,
   -1.0000, -0.5000, 0, 0.5000, 1.0000,
   -1.0000, -0.5000, 0, 0.5000, 1.0000,
   -1.0000, -0.5000, 0, 0.5000, 1.0000 };

static double NF_C_H_Q4_3D_F4_Zeta[] = { 
   -1.0000, -1.0000, -1.0000, -1.0000, -1.0000,
   -0.5000, -0.5000, -0.5000, -0.5000, -0.5000,
         0, 0, 0, 0, 0,
    0.5000, 0.5000, 0.5000, 0.5000, 0.5000,
    1.0000, 1.0000, 1.0000, 1.0000, 1.0000 };


/* face 5 */
static double NF_C_H_Q4_3D_F5_Xi[]   = {
   -1.0000, -1.0000, -1.0000, -1.0000, -1.0000,
   -0.5000, -0.5000, -0.5000, -0.5000, -0.5000,
         0, 0, 0, 0, 0,
    0.5000, 0.5000, 0.5000, 0.5000, 0.5000,
    1.0000, 1.0000, 1.0000, 1.0000, 1.0000 };

static double NF_C_H_Q4_3D_F5_Eta[]  = {
   -1.0000, -0.5000, 0, 0.5000, 1.0000,
   -1.0000, -0.5000, 0, 0.5000, 1.0000,
   -1.0000, -0.5000, 0, 0.5000, 1.0000,
   -1.0000, -0.5000, 0, 0.5000, 1.0000,
   -1.0000, -0.5000, 0, 0.5000, 1.0000 };

static double NF_C_H_Q4_3D_F5_Zeta[] = {
     1, 1, 1, 1, 1,
     1, 1, 1, 1, 1,
     1, 1, 1, 1, 1,
     1, 1, 1, 1, 1,
     1, 1, 1, 1, 1 };


static double *NF_C_H_Q4_3D_XiArray[6] = { 
                        NF_C_H_Q4_3D_F0_Xi,
                        NF_C_H_Q4_3D_F1_Xi,
                        NF_C_H_Q4_3D_F2_Xi,
                        NF_C_H_Q4_3D_F3_Xi,
                        NF_C_H_Q4_3D_F4_Xi,
                        NF_C_H_Q4_3D_F5_Xi };

static double *NF_C_H_Q4_3D_EtaArray[6] = { 
                        NF_C_H_Q4_3D_F0_Eta,
                        NF_C_H_Q4_3D_F1_Eta,
                        NF_C_H_Q4_3D_F2_Eta,
                        NF_C_H_Q4_3D_F3_Eta,
                        NF_C_H_Q4_3D_F4_Eta,
                        NF_C_H_Q4_3D_F5_Eta };

static double *NF_C_H_Q4_3D_ZetaArray[6] = { 
                        NF_C_H_Q4_3D_F0_Zeta,
                        NF_C_H_Q4_3D_F1_Zeta,
                        NF_C_H_Q4_3D_F2_Zeta,
                        NF_C_H_Q4_3D_F3_Zeta,
                        NF_C_H_Q4_3D_F4_Zeta,
                        NF_C_H_Q4_3D_F5_Zeta };

static double NF_C_H_Q4_3D_T[25] = {
         0, 0.25, 0.5, 0.75, 1,
         0, 0.25, 0.5, 0.75, 1,
         0, 0.25, 0.5, 0.75, 1,
         0, 0.25, 0.5, 0.75, 1,
         0, 0.25, 0.5, 0.75, 1 };
static double NF_C_H_Q4_3D_S[25] = {
         0, 0, 0, 0, 0,
         0.25, 0.25, 0.25, 0.25, 0.25,
         0.5, 0.5, 0.5, 0.5, 0.5,
         0.75, 0.75, 0.75, 0.75, 0.75,
         1, 1, 1, 1, 1 };

void NF_C_H_Q4_3D_EvalAll(TCollection *Coll, TBaseCell *Cell,
                          double *PointValues, double *Functionals)
{
  memcpy(Functionals, PointValues, 125*SizeOfDouble);
}

void NF_C_H_Q4_3D_EvalFace(TCollection *Coll, TBaseCell *Cell, int Joint, 
                           double *PointValues, double *Functionals)
{
  memcpy(Functionals, PointValues, 25*SizeOfDouble);
}

static int NF_C_H_Q4_3D_N_AllFunctionals = 125;
static int NF_C_H_Q4_3D_N_PointsAll = 125;
static int NF_C_H_Q4_3D_N_FaceFunctionals[] = { 25, 25, 25, 25, 25, 25 };
static int NF_C_H_Q4_3D_N_PointsFace[] = { 25, 25, 25, 25, 25, 25 };

TNodalFunctional3D *NF_C_H_Q4_3D_Obj = new TNodalFunctional3D
        (NF_C_H_Q4_3D, NF_C_H_Q4_3D_N_AllFunctionals,
         NF_C_H_Q4_3D_N_FaceFunctionals, NF_C_H_Q4_3D_N_PointsAll,
         NF_C_H_Q4_3D_N_PointsFace,
         NF_C_H_Q4_3D_Xi, NF_C_H_Q4_3D_Eta, NF_C_H_Q4_3D_Zeta,
         NF_C_H_Q4_3D_XiArray, NF_C_H_Q4_3D_EtaArray,
         NF_C_H_Q4_3D_ZetaArray,
         NF_C_H_Q4_3D_T, NF_C_H_Q4_3D_S,
         NF_C_H_Q4_3D_EvalAll, NF_C_H_Q4_3D_EvalFace);
