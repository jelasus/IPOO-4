#include <iostream>

using namespace std;

main(){
    int i=0;
    while(true)
    {
        cin >> i;
        if (i<=-1)
        {
            cout << "GoodBye!" << '\n';
            break;
        }
        else if ((i%5)!=0)
            continue;
        cout << i/5 << '\n';
    }
    return 0;
}
