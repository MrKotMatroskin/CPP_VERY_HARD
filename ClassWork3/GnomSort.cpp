#include <iostream>

using namespace std;

int main()
{
int n = 0;
int j = 0;
cin>>n;
int a[n]={0};
for (int i = 0; i<n; i++){
    cin>>a[i];
}

for (int i = 1; i<n; i++){
    if (a[i-1]>a[i]){
        j=i;
        while((a[i-1]>a[i]) && i>0){
            a[i]=a[i]+a[i-1];
            a[i-1]=a[i]-a[i-1];
            a[i]=a[i]-a[i-1];
            i--;
        }
    i=j;
    }
}
for (int i = 0; i<n; i++){
    cout<<a[i]<<" ";
}
return 0;
}


