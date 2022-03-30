#include <iostream>
using namespace std;
void sort(int* a, int past, int future)
{
    int i = past, j = future;
    double op_element = a[(past + future) / 2];

    do {
        while (a[i] < op_element)
            i++;
        while (a[j] > op_element)
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
    int n = 0;
    cout<<"Length of array:"<<endl;
    cin>>n;
    cout<<"Enter array:"<<endl;
    int array[n]={0};
    for (int i=0; i<n; i++){
        cin>>array[i];
    }
    sort(array,0, n);
    for (int i=0; i<n; i++){
        cout<<array[i]<<" ";
    }
}
