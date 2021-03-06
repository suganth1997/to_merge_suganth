// =======================================================================
// @(#)RefMortarLineDesc.C        1.2 09/13/99
//
// Class:       TRefMortarLineDesc
// Purpose:     refinement descriptor for a mortar line
//
// Author:      Volker Behns  16.01.98
//
// =======================================================================

#ifndef __MORTAR__
#define __MORTAR__
#endif

#include <RefMortarLineDesc.h>

static int DatNewVertexEqOldVertex[] = { 0,  1};
static int DatNewVertexEqOldVertexIndex[] = { 0,  1};

// Constructor
TRefMortarLineDesc::TRefMortarLineDesc(TShapeDesc *shape, int N)
                 : TRefDesc(shape)
{
  int i;
  
  Shapes *DatChildType;

  int *DatChildVertex;
  int *DatVertexChild;
  int *DatVertexChildIndex;
  int *DatVertexChildLen;

  int *DatInteriorVertexOfCell;
  double *DatPositionOfIntVert;

  Type = MortarLine;

  N_Edges = N;
  N_Vertices = N + 1;
  N_Children = N;
  N_NewVertEqOldVert = 2;


  MaxN_VpC = MLINEMAXN_VpC;
  MaxN_CpV = MLINEMAXN_CpV;

  // generate data fields
  DatChildType = new Shapes[N_Children];
  for (i=0;i<N_Children;i++)
    DatChildType[i] = S_Line;

  DatChildVertex = new int[N_Children * MLINEMAXN_VpC];
  for (i=0;i<N_Children;i++)
  {
    DatChildVertex[i*MLINEMAXN_VpC    ] = i;
    DatChildVertex[i*MLINEMAXN_VpC + 1] = i + 1;
  }

  DatVertexChild = new int[N_Vertices * MLINEMAXN_CpV];
  DatVertexChildIndex = new int[N_Vertices * MLINEMAXN_CpV];
  DatVertexChildLen = new int[N_Vertices];

  DatVertexChild[0] = 0;
  DatVertexChildIndex[0] = 0;
  DatVertexChildLen[0] = 1;

  for (i=1;i<N_Children+1;i++)
  {
    DatVertexChild[2*i    ] = i-1;
    DatVertexChild[2*i + 1] = i;
    DatVertexChildIndex[2*i    ] = 1;
    DatVertexChildIndex[2*i + 1] = 0;
    DatVertexChildLen[i] = 2;
  }
  DatVertexChildLen[N_Vertices - 1] = 1;

  DatNewVertexEqOldVertex[1] = N_Vertices - 1;

  DatInteriorVertexOfCell = new int[(N_Vertices - 2)];
  DatPositionOfIntVert = new double[(N_Vertices - 2)*2];

  for (i=0;i<N_Vertices-2;i++)
  {
    DatInteriorVertexOfCell[i] = i + 1;
    DatPositionOfIntVert[2*i    ] = (N_Vertices - i - 2)*1./N_Children;
    DatPositionOfIntVert[2*i + 1] = (i+1)*1./N_Children;
  }
  
  // initialize all pointers
  ChildType = (const Shapes *) DatChildType;

  ChildVertex = (const int *) DatChildVertex;
  VertexChild = (const int *) DatVertexChild;
  VertexChildIndex = (const int *) DatVertexChildIndex;

  NewVertexEqOldVertex = (const int *) DatNewVertexEqOldVertex;
  NewVertexEqOldVertexIndex = (const int *) DatNewVertexEqOldVertexIndex;

  InteriorVertexOfCell = (const int *) DatInteriorVertexOfCell;
  PositionOfIntVert = (const double *) DatPositionOfIntVert;
}

// Methods
