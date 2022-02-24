#include <iostream>

using namespace std;

int main()
{
int a = 0;
cin >> a;
while (a%2==0){
a=a/2;
}
if (a==1){
cout << "YES" << endl;
}
else{
cout << "NO" << endl;
}
    return 0;
}
