#include <iostream>

using namespace std;

int main()
{
int n = 0;
float c = 0;
float k = 0;
cin>>n;
for(int i = 1; i < n+1; i++){
    c++;
    k = k + 1/(c*c);
}
cout<<k;
return 0;
}
