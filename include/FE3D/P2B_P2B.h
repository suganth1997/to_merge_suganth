// ***********************************************************************
// 
// mapper for tetrahedron faces on both sides
// 
// Author:     Sashikumaar Ganesan
//
// ***********************************************************************

static char P2B_P2B_Name[] = "P2B_P2B";
static char P2B_P2B_Desc[] = "conforming P2 element with face and cell bubbles";
static int P2B_P2B_N0 = 7;
static int P2B_P2B_N1 = 7;
static int P2B_P2B_NPairs = 7;
static int P2B_P2B_Pairs0[][2] = { {0,7}, {1,10}, {2,12},
                                 {3,8}, {4,11}, {5,9}, {6,13} };
static int P2B_P2B_Pairs1[][2] = { {0,9}, {1,8}, {2,7},
                                 {3,11}, {4,10}, {5,12}, {6,13} };
static int P2B_P2B_Pairs2[][2] = { {0,12}, {1,11}, {2,9},
                                 {3,10}, {4,8}, {5,7}, {6,13} };
static int *P2B_P2B_Pairs[3] = { (int *)P2B_P2B_Pairs0, (int *)P2B_P2B_Pairs1,
                               (int *)P2B_P2B_Pairs2 };

static int P2B_P2B_NNodes = 14;

static int P2B_P2B_NNoOpposite = 0;
static int **P2B_P2B_NoOpposite = NULL;

TFE3DMapper *P2B_P2B = new TFE3DMapper(P2B_P2B_Name, P2B_P2B_Desc,
                             P2B_P2B_N0, P2B_P2B_N1,
                             P2B_P2B_NPairs, P2B_P2B_Pairs,
                             P2B_P2B_NNoOpposite, P2B_P2B_NoOpposite,
                             P2B_P2B_NNodes);
