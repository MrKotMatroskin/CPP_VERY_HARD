#include <iostream>

using namespace std;

int main() {
    int n = 0;
    cout << "length of array" << endl;
    cin >> n;
    int array[n] = {0}; //массив
    int left_border = 0;//левая граница
    int right_border = n - 1;//правая граница
    int midl = 0;//середина массива
    int number = 0;//искомое число
    int cell = 0;//номер ячейки с искомым числом (отсчет от 0)
    cout << "enter array" << endl;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
        cout << array[i] << " | ";
    }
    cout << endl;
    cout << "search number: ";
    cin >> number;

    while (cell == 0 && cell != -1) {
        midl = (left_border + right_border) / 2;

        if (number < array[midl])
            right_border = midl - 1;
        else if (number > array[midl])
            left_border = midl + 1;
        else
            cell = midl;

        if (left > right)
            cell = -1;
    }

    if (cell >= 0)
        cout << "found number in cell: " << cell;
    else
        cout << "no such number";

    return 0;
}
