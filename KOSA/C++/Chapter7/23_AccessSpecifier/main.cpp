#include "geo.h"
#include "triangle.h"

int main(void){
    GeometricFigure obj1;
    cout << "obj1의 색: " << obj1.GetColor() << endl;
    obj1.SetColor("green");
    cout << "obj1의 색: " << obj1.GetColor() << endl;
    
    return 0;
}