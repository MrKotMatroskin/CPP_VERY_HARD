#include <iostream>
using namespace std;
struct lecture{
    int st = 0;
    int end = 0;
};
bool sravnenie (lecture a, lecture b){
    if (a.end<b.end){
        return true; //a меньше
    }
    else if(a.end>b.end){
        return false;//b меньше
    }
    else {
        if (a.st<b.st){
            return true;// a меньше
        }
        else return false; //b меньше
    }
}
int main() {
    int time = 0;
    int count = 0;
    int n = 0;
    int j = 0;
    cin>>n;
    struct lecture lectures[n];
    for (int i = 0; i<n; i++){
        cin>>lectures[i].st>>lectures[i].end;
    }
    //sort
    for (int i = 1; i<n; i++){
        if (sravnenie(lectures[i-1], lectures[i]) == false){
            j=i;
            while((sravnenie(lectures[i-1], lectures[i]) == false) && i>0){
                lecture m;
                m = lectures[i];
                lectures[i] = lectures[i-1];
                lectures[i-1] = m;
                i--;
            }
            i=j;
        }
    }
    time = lectures[0].end;
    count++;
    for (int i = 1; i<n; i++){
        if(lectures[i].st>=time){
            time = lectures[i].end;
            count++;
        }
    }
    cout<<count;
    return 0;
}
