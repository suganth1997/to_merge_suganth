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
static double NF_D_H_P1_3D_Xi[]   = {
       -0.5773502691896257645091489,  0.5773502691896257645091489,
       -0.5773502691896257645091489,  0.5773502691896257645091489,
       -0.5773502691896257645091489,  0.5773502691896257645091489,
       -0.5773502691896257645091489,  0.5773502691896257645091489 };
static double NF_D_H_P1_3D_Eta[]  = {
       -0.5773502691896257645091489, -0.5773502691896257645091489,
        0.5773502691896257645091489,  0.5773502691896257645091489,
       -0.5773502691896257645091489, -0.5773502691896257645091489,
        0.5773502691896257645091489,  0.5773502691896257645091489 };
static double NF_D_H_P1_3D_Zeta[] = {
       -0.5773502691896257645091489, -0.5773502691896257645091489,
       -0.5773502691896257645091489, -0.5773502691896257645091489,
        0.5773502691896257645091489,  0.5773502691896257645091489,
        0.5773502691896257645091489,  0.5773502691896257645091489 };

/* face 0                               0 */
static double *NF_D_H_P1_3D_F0_Xi = NULL;
static double *NF_D_H_P1_3D_F0_Eta = NULL;
static double *NF_D_H_P1_3D_F0_Zeta = NULL;

/* face 1                               1 */
static double *NF_D_H_P1_3D_F1_Xi = NULL;
static double *NF_D_H_P1_3D_F1_Eta = NULL;
static double *NF_D_H_P1_3D_F1_Zeta = NULL;

/* face 2                               2 */
static double *NF_D_H_P1_3D_F2_Xi = NULL;
static double *NF_D_H_P1_3D_F2_Eta = NULL;
static double *NF_D_H_P1_3D_F2_Zeta = NULL;

/* face 3                               3 */
static double *NF_D_H_P1_3D_F3_Xi = NULL;
static double *NF_D_H_P1_3D_F3_Eta = NULL;
static double *NF_D_H_P1_3D_F3_Zeta = NULL;

/* face 4                               4 */
static double *NF_D_H_P1_3D_F4_Xi = NULL;
static double *NF_D_H_P1_3D_F4_Eta = NULL;
static double *NF_D_H_P1_3D_F4_Zeta = NULL;

/* face 5                               5 */
static double *NF_D_H_P1_3D_F5_Xi = NULL;
static double *NF_D_H_P1_3D_F5_Eta = NULL;
static double *NF_D_H_P1_3D_F5_Zeta = NULL;

static double *NF_D_H_P1_3D_XiArray[6] = { 
                        NF_D_H_P1_3D_F0_Xi,
                        NF_D_H_P1_3D_F1_Xi,
                        NF_D_H_P1_3D_F2_Xi,
                        NF_D_H_P1_3D_F3_Xi,
                        NF_D_H_P1_3D_F4_Xi,
                        NF_D_H_P1_3D_F5_Xi };

static double *NF_D_H_P1_3D_EtaArray[6] = { 
                        NF_D_H_P1_3D_F0_Eta,
                        NF_D_H_P1_3D_F1_Eta,
                        NF_D_H_P1_3D_F2_Eta,
                        NF_D_H_P1_3D_F3_Eta,
                        NF_D_H_P1_3D_F4_Eta,
                        NF_D_H_P1_3D_F5_Eta };

static double *NF_D_H_P1_3D_ZetaArray[6] = { 
                        NF_D_H_P1_3D_F0_Zeta,
                        NF_D_H_P1_3D_F1_Zeta,
                        NF_D_H_P1_3D_F2_Zeta,
                        NF_D_H_P1_3D_F3_Zeta,
                        NF_D_H_P1_3D_F4_Zeta,
                        NF_D_H_P1_3D_F5_Zeta };

static double *NF_D_H_P1_3D_T = NULL;
static double *NF_D_H_P1_3D_S = NULL;

void NF_D_H_P1_3D_EvalAll(TCollection *Coll, TBaseCell *Cell,
                          double *PointValues, double *Functionals)
{
  Functionals[0] = ( PointValues[0]+PointValues[1]
                    +PointValues[2]+PointValues[3]
                    +PointValues[4]+PointValues[5]
                    +PointValues[6]+PointValues[7] ) * 0.125;
  Functionals[1] = ( PointValues[0]*NF_D_H_P1_3D_Xi[0]
                    +PointValues[1]*NF_D_H_P1_3D_Xi[1]
                    +PointValues[2]*NF_D_H_P1_3D_Xi[2]
                    +PointValues[3]*NF_D_H_P1_3D_Xi[3]
                    +PointValues[4]*NF_D_H_P1_3D_Xi[4]
                    +PointValues[5]*NF_D_H_P1_3D_Xi[5]
                    +PointValues[6]*NF_D_H_P1_3D_Xi[6]
                    +PointValues[7]*NF_D_H_P1_3D_Xi[7] ) * 0.375;
  Functionals[2] = ( PointValues[0]*NF_D_H_P1_3D_Eta[0]
                    +PointValues[1]*NF_D_H_P1_3D_Eta[1]
                    +PointValues[2]*NF_D_H_P1_3D_Eta[2]
                    +PointValues[3]*NF_D_H_P1_3D_Eta[3]
                    +PointValues[4]*NF_D_H_P1_3D_Eta[4]
                    +PointValues[5]*NF_D_H_P1_3D_Eta[5]
                    +PointValues[6]*NF_D_H_P1_3D_Eta[6]
                    +PointValues[7]*NF_D_H_P1_3D_Eta[7] ) * 0.375;
  Functionals[3] = ( PointValues[0]*NF_D_H_P1_3D_Zeta[0]
                    +PointValues[1]*NF_D_H_P1_3D_Zeta[1]
                    +PointValues[2]*NF_D_H_P1_3D_Zeta[2]
                    +PointValues[3]*NF_D_H_P1_3D_Zeta[3]
                    +PointValues[4]*NF_D_H_P1_3D_Zeta[4]
                    +PointValues[5]*NF_D_H_P1_3D_Zeta[5]
                    +PointValues[6]*NF_D_H_P1_3D_Zeta[6]
                    +PointValues[7]*NF_D_H_P1_3D_Zeta[7] ) * 0.375;
}

void NF_D_H_P1_3D_EvalFace(TCollection *Coll, TBaseCell *Cell, int Joint, 
                           double *PointValues, double *Functionals)
{
}

static int NF_D_H_P1_3D_N_AllFunctionals = 4;
static int NF_D_H_P1_3D_N_PointsAll = 8;
static int NF_D_H_P1_3D_N_FaceFunctionals[] = { 0, 0, 0, 0, 0, 0 };
static int NF_D_H_P1_3D_N_PointsFace[] = { 0, 0, 0, 0, 0, 0 };

TNodalFunctional3D *NF_D_H_P1_3D_Obj = new TNodalFunctional3D
        (NF_D_H_P1_3D, NF_D_H_P1_3D_N_AllFunctionals,
         NF_D_H_P1_3D_N_FaceFunctionals, NF_D_H_P1_3D_N_PointsAll,
         NF_D_H_P1_3D_N_PointsFace,
         NF_D_H_P1_3D_Xi, NF_D_H_P1_3D_Eta, NF_D_H_P1_3D_Zeta,
         NF_D_H_P1_3D_XiArray, NF_D_H_P1_3D_EtaArray,
         NF_D_H_P1_3D_ZetaArray,
         NF_D_H_P1_3D_T, NF_D_H_P1_3D_S,
         NF_D_H_P1_3D_EvalAll, NF_D_H_P1_3D_EvalFace);
