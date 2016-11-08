#include "polygonn.h"
#include <iostream>
#include <cmath>

using namespace std;

Point::Point(): x(0), y(0) {}
Point::Point(number _x, number _y): x(_x), y(_y) {}
Point::Point(Point &o): x(o.x), y(o.y) {}
void Point::setx(const number _x) {x=_x;}
void Point::sety(const number _y) {x=_y;}
number Point::getx() const {return x;}
number Point::gety() const {return y;}
PointArray::PointArray() {
    _size=0;
    points = new Point[_size];
}
PointArray::PointArray(const Point arr[],const number len) {
    _size=len;
    points = new Point[_size];
    for(int i=0;i<_size;i++)
        points[i]=arr[i];
}
PointArray::PointArray(const PointArray &pv) {
     points = new Point[_size];
     for(int i=0;i<_size;i++)
        points[i]=pv.points[i];
}
PointArray::~PointArray() {delete []points;}
void PointArray::_resize(const number n) {
    Point *p1 =new Point[_size];
    for(int i=0;i<_size;i++)
        p1[i]=points[i]; //llenamos p1 con points
    delete []points; //borramos el contenido de points
    points=new Point[n]; //y creamos points con el tamaño n
    for(int i=0;i<n;i++)
        if(i<_size)
            points[i]=p1[i]; //llenamos points con p1
    delete []p1;
    _size=n; //reajuste del tamaño del arreglo
}
void PointArray::_push_back(const Point &p1) {
    PointArray::_resize(_size+1); //agregamos un espacio a la derecha
    points[_size]=p1; //llenamos ese espacio
    ++_size; //reajuste del tamaño del arreglo
}
void PointArray::_insert(const number pos,const Point &p1) {
    cout << "insert since 1 to pos" << '\n';
    PointArray::_resize(_size+1); //agregamos un valor a la izqierda
    for(int i=_size;_size-i>0;i--)
        points[i]=points[i-1]; //dejamos el espacio de pos vacio
    points[pos]=p1; //llenamos el espacio de pos
    ++_size; //reajuste del tamaño del arreglo
}
void PointArray::_remove(const number pos) {
    cout << "remove since 1 to pos" << '\n';
    for(int i=pos;_size-pos>0;i++)
        points[i+1]=points[i]; //movemos el valor en pos al extremo derecho
    PointArray::_resize(_size-1); //lo eliminamos
    --_size; //reajuste del tamaño del arreglo
}
const number PointArray::getsize() const {return _size;}
void PointArray::_clear() {
    delete []points; //borar contenido
    _size=0; //reajuste del tamaño del arreglo
    points=new Point[_size];
}
Point* PointArray::get(const number pos) {
    Point *p1=NULL;
    if(pos>=0 && pos<_size)
    {
        p1=&points[pos];
        return p1;
    }
    else
        return p1;
}
const Point* PointArray::get(const number pos) const {
    Point *p1=NULL;
    if(pos>=0 && pos<_size)
    {
        p1=&points[pos];
        return p1;
    }
    else
        return p1;
}
number Polygon::num=0;
Polygon::Polygon(const PointArray &cp) : arrp(cp) {++num;}
Polygon::Polygon(const Point spoints[], const number inst) : arrp(spoints, inst) {++num;}
Polygon::~Polygon() {--num;}
number Polygon::getNumSides() {return arrp.getsize();}
const PointArray* Polygon::getPoints() {return &arrp;}

Point constructorPoints[4];
Point *updateConstructorPoints(const Point &p1 , const Point &p2 ,
const Point &p3 , const Point &p4 = Point(0 ,0)) {
    constructorPoints [0] = p1;
    constructorPoints [1] = p2;
    constructorPoints [2] = p3;
    constructorPoints [3] = p4;
    return constructorPoints;
}
