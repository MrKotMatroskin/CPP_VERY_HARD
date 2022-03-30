#include <iostream>
using namespace std;
struct student {
    string name = "y";
    int score = 0;
};
int main()
{
    int m = 0;
student array[5];
for (int i = 0; i<5; i++){
    cin>>array[i].name>>array[i].score;
}
cin>>m;
for (int i = 0; i<5; i++) {
    if (array[i].score >= m){
        cout<<array[i].name<<" ";
    }
}
    cout<<endl;
}
