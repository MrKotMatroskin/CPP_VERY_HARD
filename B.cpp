#include <iostream>

using namespace std;

int main()
{
int a = 1;
int c = 0;
while(a!=0){
cin>>a;
if((a%2==0)&&(a!=0)){
c++;
}
}
    cout << c << endl;
    return 0;
}
