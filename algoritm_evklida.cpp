#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin>>a;
    cin>>b;
    while(b){
        c = a % b;
        a = b;
        b = c;
    }

    cout << abs(a) << endl;
    return 0;
}
