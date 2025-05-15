#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_
#include "geo.h"
// #include "Point.h"

class Triangle : public GeometricFigure{
public:
    Triangle();
    double CalcArea();
    

private:
    double width;
    double height;
    // Point points[3];
};



#endif //_TRIANGLE_H_