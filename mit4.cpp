#include <iostream>

using namespace std;

main(){
    int i=0;
    while(true)
    {
        cin >> i;
        int result= (i%5)==0 ? i/5 : -1;
        cout << result << '\n';
    }
    return 0;
}
