/*
    TNodalFunctional2D(NodalFunctional2D id,
                       int n_allfunctionals, int n_edgefunctionals,
                       int n_pointsall, int n_pointsedge,
                       double *xi, double *eta, double *t,
                       DoubleFunctVect *evalall,
                       DoubleFunctVect *evaledge);
*/

static double NF_N_T_RT0_2D_Xi[] =  { 0.5, 0.5, 0};
static double NF_N_T_RT0_2D_Eta[] = { 0  , 0.5, 0.5};
static double NF_N_T_RT0_2D_T[] = {0};

void NF_N_T_RT0_2D_EvalAll(TCollection *Coll, TBaseCell *Cell, double *PointValues,
                          double *Functionals)
{
//   static double weights[3] = { 0.5555555555555555555555555555555556,
//                                0.88888888888888888888888888888888889,
//                                0.5555555555555555555555555555555556 };
//   Functionals[0] = ( weights[0]*PointValues[0]
//                     +weights[1]*PointValues[1]
//                     +weights[2]*PointValues[2]) * 0.5;
//   Functionals[1] = ( weights[0]*PointValues[3]
//                     +weights[1]*PointValues[4]
//                     +weights[2]*PointValues[5]) * 0.5;
//   Functionals[2] = ( weights[0]*PointValues[6]
//                     +weights[1]*PointValues[7]
//                     +weights[2]*PointValues[8]) * 0.5;
//   Functionals[3] = ( weights[0]*PointValues[9]
//                     +weights[1]*PointValues[10]
//                     +weights[2]*PointValues[11]) * 0.5;

  Functionals[0] = PointValues[0];
  Functionals[1] = PointValues[1];
  Functionals[2] = PointValues[2];
}

void NF_N_T_RT0_2D_EvalEdge(TCollection *Coll, TBaseCell *Cell, int Joint, double *PointValues,
                           double *Functionals)
{
 // this is needed for setting boundary conditions
  /* the functional
   * int_Joint v.n
   * will be multiplied by the length of the Joint (edge). Otherwise one would
   * ensure int_Joint v.n=PointValues[0]. 
   * Example: If you would like to have u.n=1, then without multiplying by 
   *          the edge length l would result in having int_Joint u.n=1 on each
   *          boundary edge. This would mean one gets u.n=1/l on that 
   *          boundary. To avoid this, we introduce the factor l here. 
   * However I am not sure if this causes trouble elsewhere later. 
   * Be carefull!
   *                                            Ulrich Wilbrandt, 11.05.2012
  */
  double l; // length of joint
  double x0,x1,y0,y1;
  #ifdef __2D__
  Cell->GetVertex(Joint)->GetCoords(x0,y0);
  Cell->GetVertex((Joint+1)%3)->GetCoords(x1,y1);// 3=number of edges
  #endif
  l = sqrt((x0-x1)*(x0-x1) + (y0-y1)*(y0-y1));
  Functionals[0] = PointValues[0]*l;
}

TNodalFunctional2D *NF_N_T_RT0_2D_Obj = new TNodalFunctional2D
        (NF_N_T_RT0_2D, 3, 1, 3, 1, NF_N_T_RT0_2D_Xi, NF_N_T_RT0_2D_Eta,
         NF_N_T_RT0_2D_T, NF_N_T_RT0_2D_EvalAll, NF_N_T_RT0_2D_EvalEdge);
