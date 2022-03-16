#include <iostream>

using namespace std;

int main()
{
int a = 0;
int k = 0;
cin>>a;
for(int i = 1; i <= a/2; i++){
    if(a%i==0){
        for(int j = 1; j <= i/2; j++){
            if(i%j==0){
                k++;
            }
        }
        if((k==1)&&(i!=1)){
            cout << i << " ";
        }
        k=0;
}
}
return 0;
}
