#include <iostream>

using namespace std;

int main()
{
int a = 0;
int b = 0;
int c = 0;
cin>>a;
b=a/2;
for(int i = b; i > 0; i--){
if((a%i==0)&&(i!=1)){
cout << i <<" ";
}
}
return 0;
}
