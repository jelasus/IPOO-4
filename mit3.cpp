#include <iostream>
#include <math.h>

using namespace std;

int raiz(int c)
{
    int i=0;
    while ((i*i)<c)
        ++i;
    return i;
}

void primos(int m)
{
    int i=0, j, k=2, l=2;
    while (i<m)
    {
        for (j=2;j<=raiz(l);++j)
        {
            if ((l%j)==0)
                break;
            else
                ++k;
        }
        if (raiz(l)<2 || k==raiz(l))
        {
            cout << l << '\n';
            ++i;
        }
        k=1;
        ++l;
    }
}

main()
{
    int n;
    cin >> n;
    cout << '\n';
    if (n>0)
    {
        primos(n);
    }
    else
        cout << "No hay primos" << '\n';
    return 0;
}
