# include <iostream>

using namespace std;
enum Status {
    pr = ' '
};

//чтобы закончить ввод, введите в конце выражения маленькую латинскую букву, любую
int main() {
    char response_status = 0;
    int max_len = 100;
    int len = 0;
    char *array = new char[max_len];

    cin >> response_status;

    while ('a' > response_status || response_status > 'z') {
        if (len == max_len - 1) {
            char *buff = new char[max_len * 2];
            for (int it = 0; it < len; ++it) {
                buff[it] = array[it];
            }
            max_len *= 2;
            delete[] array;
            array = buff;
        }


        switch (response_status) {
            case Status::pr :
                break;
            default:
                array[len] = response_status;
                len++;
                break;

        }

        cin >> response_status;
    }
    array[len] = '\0';
    cout << array;
    return 0;
}