#ifndef POLYGONN_H
#define POLYGONN_H
#include <iostream>

typedef int number; //tipo de dato entero

class Point{
    private:
    number x,y;
    public:
    Point(); //constructor por defecto
    Point(Point& ); //constructor copia1
    Point(number,number); //constructor
    void setx(const number); //establece la coordenada x
    void sety(const number); //establece la coordenada y
    number getx() const; //obtiene la coordenada x
    number gety() const; //obtiene la coordenada y
};

class PointArray{
    private:
    Point *points;
    number _size;
    void _resize(const number); //modifica el arreglo a un arreglo de tamaño n
    public:
    PointArray(); //constructor por defecto
    PointArray(const Point[],const number); //constructor
    PointArray(const PointArray& ); //constructor copia
    ~PointArray(); //destructor
    void _push_back(const Point& ); //inserta un elemento al final del arreglo
    void _insert(const number,const Point& ); //inserta un elemento en la posicion n
    void _remove(const number); //remueve el elemento de la posicion n
    const number getsize() const; //obtiene la longitud del arreglo
    void _clear(); //remueve todo lo que esta en el arreglo
    Point* get(const number);
    const Point* get(const number) const;
};

class Polygon{
    protected:
    PointArray arrp;
    static number num;
    public:
    Polygon(const PointArray &);
    Polygon(const Point[], const number);
    ~Polygon();
    virtual double Area() const = 0;
    static number getNumPolygons() {return num;}
    number getNumSides();
    const PointArray *getPoints();
};

class Rectangule : public Polygon{
    Rectangule(const Point &,const Point &);
    Rectangule(const int, const int, const int, const int);
    virtual double Area() const;
};

#endif // POLYGONN_H
