# include <iostream>

using namespace std;

void change(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void fix(int* a, int* b, int* c)
{
    if (*b<*a)
        change(b,a);
    if (*b>*c)
        change(b,c);
    if (*b<*a)
        change(b,a);
}

int main()
{
    int a,b,c;
    double mean;
    cin >> a >> b >> c;
    fix(&a,&b,&c);
    mean= (a+b+c)/3;
    cout << "mean: " << mean << '\n' << "min: " << a << '\n' << "max: " << c << '\n' << "range: " << c << '\n' ;
    return 0;
}
