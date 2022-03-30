#include <iostream>

using namespace std;

struct otrezok {
    double x[2] = {0}; //начало
    double y[2] = {0}; //конец
};

double my_max(double lft, double rht) {
    return lft > rht ? lft : rht;
}

double my_min(double lft, double rht) {
    return lft > rht ? rht : lft;
}

bool intersect(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy) {
    double x1 = ax, y1 = ay, x2 = bx, y2 = by, x3 = cx, y3 = cy, x4 = dx, y4 = dy, tmp; //координаты концов отрезков от 1 до 4
    double X1 = (x2 - x1), Y1 = (y2 - y1), X2 = (x4 - x3), Y2 = (y4 - y3);//координаты векторов
    double opr = X1 * Y2 - X2 * Y1;//смешанное произведение векторов
    double a[2];
    if (opr != 0) { //если смешанное произведение не равно нулю, то отрезки не параллельны
        a[0] = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) /
               ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));//x пересечения прямых
        a[1] = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) /
               ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));//y пересечение прямых
        tmp = my_max(x1, x2), x1 = my_min(x1, x2), x2 = tmp;
        tmp = my_max(y1, y2), y1 = my_min(y1, y2), y2 = tmp;
        tmp = my_max(x3, x4), x3 = my_min(x3, x4), x4 = tmp;
        tmp = my_max(y3, y4), y3 = my_min(y3, y4), y4 = tmp;
        if (a[0] >= x1 and a[0] <= x2 and a[0] >= x3 and a[0] <= x4 and a[1] >= y1 and a[1] <= y2 and a[1] >= y3 and
            a[1] <= y4) {
            return true;
        }
    } else if (((x1 < x3) ? x3 : x1) <= ((x2 < x4) ? x2 : x4)) {
        return true;
    }
    return false;
}

int main() {
    bool flag = false;
    int min_otrezok;
    otrezok array[2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> array[i].x[j] >> array[i].y[j];
        }
    }
    flag = intersect(array[0].x[0], array[0].y[0], array[0].x[1], array[0].y[1], array[1].x[0], array[1].y[0],
                     array[1].x[1], array[1].y[1]);
    if (flag == true) {
        cout << "NO";
    } else {
        cout << "YES";
    }

    return 0;
}