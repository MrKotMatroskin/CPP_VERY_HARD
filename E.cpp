#include <iostream>

using namespace std;

int main()
{
int a = 1;
int c = 0;
int b = 0;
while(a!=0){
cin>>a;
if(a>c){
c=a;
b=1;
}
else if(a==c){
b++;
}
}
    cout << b << endl;
    return 0;
}
