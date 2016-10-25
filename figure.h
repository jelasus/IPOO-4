#include <iostream>

class Point{
    private:
    int x,y;
    public:
    Point();
    Point(Point& );
    Point(int,int);
    void setx(int);
    void sety(int);
    const int getx();
    const int gety();
};

class PointArray{
    private:
    Point *points;
    int sizez;
    public:
    PointArray();
    PointArray(Point[],int);
    PointArray(PointArray& );
    ~PointArray();
};

class figure
{
    public:
        figure();
        ~figure();
    protected:

};

