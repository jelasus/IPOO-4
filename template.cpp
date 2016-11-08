#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class Point{
    T x,y;
    public:
    Point() {x=0; y=0;}
    Point(const T _x, const T _y) : x(_x), y(_y) {}
    T getX() {return x;}
    T getY() {return y;}
    void insertX(T _x) {x=_x;}
    void insertY(T _y) {y=_y;}
    Point operator+(const Point o){
        Point<T> temp(0,0);
        temp.x = x + o.x;
        temp.y = y + o.y;
        return temp;
    }
    Point operator-(const Point o){
        Point<T> temp(0,0);
        temp.x = x - o.x;
        temp.y = y - o.y;
        return temp;
    }
    Point operator*(const Point o){
        Point<T> temp(0,0);
        temp.x = x * o.x;
        temp.y = y * o.y;
        return temp;
    }
    Point<T> operator/(const Point o){
        Point temp(0,0);
            temp.x = x / o.x;
            temp.y = y / o.y;
            return temp;
    }

    friend ostream& operator<<(ostream &output, const Point &o){
        output << "{" << o.x << "," << o.y << "}" << endl;
        return output;
    }
};

main(){
    Point<int> p1(8,8);
    Point<int> p2(3,3);
    Point<int> p3=p1/p2;
    Point<int> a[]={p1,p2};
    vector<Point<int> > points;
    points.push_back(p1);
    points.push_back(p2);
    Point<int> p4=p1+p2;
    points.push_back(p4);
    cout << p4;
    return 0;
}
