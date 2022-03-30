#include <iostream>
using namespace std;
struct student {
    char name[20] = {0} ;
    int score = 0;
};
void sort(student* a, int past, int future)
{
    int i = past, j = future;
    int op_element = a[(past + future) / 2].score;

    do {
        while (a[i].score < op_element)
            i++;
        while (a[j].score > op_element)
            j--;

        if (i <= j)
        {
            if (i < j)
            {
                swap(a[i], a[j]);
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < future)
        sort(a, i, future);
    if (past < j)
        sort(a, past, j);
}
int main()
{
    int m = 5;
    int n = 0;
    cin>>n;
    student array[n];
    for (int i = 0; i<n; i++){
        cin>>array[i].name>>array[i].score;
    }
    cin>>m;
    sort(array, 0, n);
    for (int i = 0; i<n; i++) {
        if (array[i].score >= m){
            cout<<array[i].name<<" ";
        }
    }
    cout<<endl;
}
