#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#define WIDTH 2
#define LENGTH 3

int sum(const int a, const int b)
{
    return a+b;
}

double sum_double(const double a, const double b)
{
    return a+b;
}

int sum(const int a, const int b, const int c)
{
    return a+b+c;
}

int sum(const int a, const int b, const int c, const int d)
{
    return a+b+c+d;
}

int sum_initiallized(const int a, const int b, const int c=0, const int d=0)
{
    return a+b+c+d;
}

int ssum(int ent[], int len)
{
    int acumulador=0;
    for(int i=0;i<len;i++)
        acumulador+=ent[i];
    return acumulador;
}

int rsum(int ent[], int len)
{
    if (len==1)
        return ent[0];
    else
        return ent[len-1]+rsum(ent,--len);
}

double dart_game(const int n)
{
    srand(time(NULL));
    int cont=0,i;
    double x,y;
    i=n;
    while(i>0)
    {
        x=(double)rand()/RAND_MAX;
        y=(double)rand()/RAND_MAX;
        if (sqrt(pow(x,2)+pow(y,2))<=1)
            ++cont;
        --i;
    }
    return (cont/static_cast<double>(n))*4;
}

void print_array_int(int arr[], int len)
{
    std::cout << *arr++;
    --len;
    while(len!=0)
    {
        std::cout << ", " << *arr++;
        --len;
    }
}

void reverse_array_int(int arr[],const int len)
{
    int temp,i;
    for(i=0;i<len/2;i++)
    {
        temp=arr[i];
        arr[i]=arr[len-i-1];
        arr[len-i-1]=temp;
    }
}

void transpose(const int arr1[][LENGTH], int arr2[][WIDTH])
{
    for(int i=0;i<LENGTH;i++)
        for(int j=0;j<WIDTH;j++)
            arr2[i][j]=arr1[j][i];
}

void reverse2(int arr[], const int len)
{
    int *p=arr;
    int temp;
    for (int i=0;i<(len/2);i++)
    {
        temp=*(p+i);
        *(p+i)=*(p+len-i-1);
        *(p+len-i-1)=temp;
    }
}

int lenght(char *arr)
{
    int i=0;
    while((*arr++)!=NULL)
        ++i;
    return i;
}
void swapp(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void swapp2(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void swapp3(int **a, int **b)
{
    int temp;
    temp=**a;
    **a=**b;
    **b=temp;
}

int main(){
    char *oddOrEven = "Never odd or even";
    char *nthCharPtr=&oddOrEven[5];
    nthCharPtr-=2;
    std::cout << *nthCharPtr;
    char **pointerPtr=&nthCharPtr;
    std::cout << '\n' << pointerPtr;
    std::cout << '\n' << **pointerPtr;
    std::cout << '\n' << (nthCharPtr-oddOrEven);
    return 0;
}
