// =======================================================================
// @(#)Mapper.h        1.3 11/15/99
// 
// Class:       TMapper
// Purpose:     mapper for faces of 3D geometric objects
//
// Author:      Volker Behns  25.07.97
//
// =======================================================================

#ifndef __MAPPER__
#define __MAPPER__

#define N_MAPPER  34
enum Mapper {MapTriReg0,  MapTriReg1, MapTriReg2,
             MapTriBis00, MapTriBis01, MapTriBis02,
             MapTriBis10, MapTriBis11, MapTriBis12,
             MapTriBis20, MapTriBis21, MapTriBis22,
             MapTriBis010, MapTriBis011, MapTriBis012,
             MapTriBis020, MapTriBis021, MapTriBis022,
             MapTriBis100, MapTriBis101, MapTriBis102,
             MapTriBis120, MapTriBis121, MapTriBis122,
             MapTriBis200, MapTriBis201, MapTriBis202,
             MapTriBis210, MapTriBis211, MapTriBis212,
             MapQuadReg0, MapQuadReg1, MapQuadReg2, MapQuadReg3};

/** mapper for faces of 3D geometric objects */
class TMapper
{
  protected:
    Mapper Type;

    /** mapping of original vertices */
    const int *MapOrigVerts;
    /** mapping of original edges */
    const int *MapOrigEdges;

    /** mapping of refined vertices */
    const int *MapRefVerts;
    /** mapping of refined edges */
    const int *MapRefEdges;
    /** mapping of refined faces */
    const int *MapRefFaces;

  public:
    //Constructor
    TMapper(Mapper which);

    //Methods
    /** return type of mapper */
    Mapper GetType()
    { return Type; }

    /** return mapper of vertices and faces */
    void GetMapperRef(const int *&MapVerts, const int *&MapFaces)
    {
      MapVerts = MapRefVerts;
      MapFaces = MapRefFaces;
    }

    /** return mapper of original vertices and faces */
    void GetMapperOrig(const int *&MapVerts, const int *&MapEdges)
    {
      MapVerts = MapOrigVerts;
      MapEdges = MapOrigEdges;
    }
};

#endif
