#include <iostream>

using namespace std;

struct otrezok {
    double a[2] = {0}; //начало и конец
};

int main() {
    bool flag = false;
    int n=0;
    cin>>n;
    otrezok array[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> array[i].a[j];
        }
    }
    for(int i = 0; i<n; i++){
        if (((array[i].a[0] < array[i+1].a[0]) ? array[i+1].a[0] : array[i].a[0]) <= ((array[i].a[1] < array[i+1].a[1]) ? array[i].a[1] : array[i].a[1])) {
            array[i+1].a[0] = (array[i].a[0] >= array[i+1].a[0]) ? array[i+1].a[0] : array[i].a[0];
            array[i+1].a[1] = (array[i].a[1] <= array[i+1].a[1]) ? array[i].a[1] : array[i].a[1];
            flag = true;
        }
        else{
            flag = false;
            break;
        }
    }
    if (flag == true) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
