#include <iostream>

using namespace std;

int main ()
{
    short number ;
    cout << "Enter a number : ";
    cin >> number ;
    if (number<0)
        cout << "No factorial for negative numbers" << '\n';
    else if (number>20)
        cout << "Big number produces incorrect result\n";
    else
    {
        cout << "The factorial of " << number << " is ";
        int accumulator =  1;
        for (; number > 0; accumulator *= number --);
        cout << accumulator << ".\n";
    }
    return 0;
}
