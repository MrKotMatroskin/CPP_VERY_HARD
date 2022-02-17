#include <iostream>

using namespace std;

int main()
{
int a = 0;
int b = 0;
int c = 0;
cin>>a;
b=a/2;
for(int i = 1; i < b; i++){
if(a%i==0){
c++;
}
}
if(c!=1){
cout << "NO" << endl;
}
else{
cout << "YES" << endl;
}
return 0;
}



