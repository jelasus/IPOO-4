#include <iostream>

using namespace std;

main()
{
    const char* hola= "Hello World!";
    cout << hola << '\n';

    int n,i;
    cin >> n;

    for (i=0;i<n;i++)
        cout << hola << '\n';

    i=0;

    while (++i<n)
        cout << hola << '\n';

    do{
        cout << hola << '\n';
        i++;
    } while(i<n);

    return 0;
}

