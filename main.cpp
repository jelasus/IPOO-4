#include <iostream>
#include "polygonn.h"

using namespace std;

class Pointn
{
    private :
        int x, y;

    public :
        Pointn (int u, int v) : x(u), y(v) {}
        int getX () { return x; }
        int getY () { return y; }
};
int main ()
{
    Pointn *p = new Pointn (5, 3);
    cout << p->getX() << ' ' << p->getY();
    return 0;
}
