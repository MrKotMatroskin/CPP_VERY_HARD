#include <iostream>
#include <cmath>
#include <iomanip>
#define T 100.
#define PI 3.14159265359f
#define RESULT 5.641895835
using namespace std;


void gen_arg_array(float start, float end, float dx, int dx_num, float *arg){
    for (int i = 0; i < dx_num; i++){
        arg[i] = start + dx * i;
    }
}

void gen_func_array(float *arg, float *func, int dx_num){
    for (int i = 0; i < dx_num; i++){
        func[i] = exp(-pow(arg[i], 2) / T);
    }
}

void dgen_arg_array(double dstart, double dend, double ddx, int ddx_num, double *darg){
    for (int i = 0; i < ddx_num; i++){
        darg[i] = dstart + ddx * i;
    }
}

void dgen_func_array(double *darg, double *dfunc, int ddx_num){
    for (int i = 0; i < ddx_num; i++){
        dfunc[i] = double(exp(-pow(darg[i], 2) / T));
    }
}

float recurs(int start_index, int end_index, float *arg, float *func){
    if (end_index - start_index  > 1){
        return recurs(start_index, (start_index + end_index) / 2, arg, func) + recurs((start_index + end_index) / 2 + 1, end_index, arg, func);
    }
    else{
        return abs(arg[start_index]) * func[start_index] + abs(arg[end_index]) * func[end_index] * (end_index - start_index);
    }
}

float double_sum(float *arg, float *func, int dx_num){
    float *main = new float[dx_num];
    for (int i = 0; i < dx_num; i++){
        main[i] = abs(arg[i]) * func[i];
    }
    int main_len = dx_num;
    while (main_len > 2){
        int over_len = main_len;
        float *temp = new float[over_len];
        for (int j = 0; j < over_len; j++){
            temp[j] = main[j];
        }
        //for (int j = 0; j < main_len; j++){
        //  cout << temp[j] << " ";
        //}
        //cout << endl;
        if (main_len % 2 == 0){
            main_len = main_len / 2;
        }
        else{
            main_len = main_len / 2 + 1;
        }
        delete [] main;
        main = new float[main_len];
        int k = 0;
        for (int i = 0; i < main_len; i++){
            if (k != over_len - 1){
                main[i] = temp[k] + temp[k + 1];
            }
            else{
                main[i] = temp[k];
            }
            k += 2;
        }
        delete [] temp;
    }
    return main[0] + main[1];

}

float kahan_integration(float *arg, float *func, int dx_num){
    float *main = new float[dx_num];
    for (int i = 0; i < dx_num; i++){
        main[i] = abs(arg[i]) * func[i];
    }
    float sum = 0.f;
    float t = 0.f;
    for (int i = 0; i < dx_num; i++){
        float y = main[i]  - t;
        float z = sum + y;
        t = (z - sum) - y;
        sum = z;
    }
    return sum;
}

float fma_sum(float *arg, float *func, int dx_num){
    float sum = 0.f;
    for (int i = 0; i < dx_num; i++){
        sum = fmaf(abs(arg[i]), func[i], sum);
    }
    return sum;

}
double accurate_sum(double *darg, double *dfunc, int ddx_num){
    double sum = 0.;
    for (int i = 0; i < ddx_num; i++){
        sum += abs(darg[i]) * dfunc[i];
    }
    return sum;
}
int main(){
    float start;
    float end;
    float dx;
    double dstart;
    double dend;
    double ddx;
    cout << "Insert left border for integration" << endl;
    cin >> start;
    cout << "Insert right border for integration" << endl;
    cin >> end;
    cout << "Insert integration interval" << endl;
    cin >> dx;
    dstart = double(start);
    dend = double(end);
    ddx = double(dx);
    int dx_num = int((end - start) / dx);
    int ddx_num = int((dend - dstart) / ddx);
    float *arg = new float[dx_num];
    float *func = new float[dx_num];
    double *darg = new double[ddx_num];
    double *dfunc = new double[ddx_num];
    gen_arg_array(start, end, dx, dx_num, arg);
    gen_func_array(arg, func, dx_num);
    dgen_arg_array(dstart, dend, ddx, ddx_num, darg);
    dgen_func_array(darg, dfunc, ddx_num);
    float recurs1 = recurs(0, dx_num - 1, arg, func) * dx * float(sqrt(1 / T / PI));
    float kahan = kahan_integration(arg, func, dx_num) * dx * float(sqrt(1 / T / PI));
    float fma = fma_sum(arg, func, dx_num) * dx * float(sqrt(1 / T / PI));
    double accurate_sum1 = accurate_sum(darg, dfunc, ddx_num) * ddx * double(sqrt(1 / T / PI));
    float double_sum1 = double_sum(arg, func, dx_num) * dx * float(sqrt(1 / T / PI));
    cout << setprecision(10) <<  recurs1 << " Recursion " << abs(RESULT - recurs1) <<  endl ;
    cout << setprecision(10) <<  double_sum1  << " double sum " << abs(RESULT - double_sum1) <<  endl;
    cout << setprecision(10) <<  kahan << " kahan_integration " << abs(RESULT - kahan) <<  endl;;
    cout << setprecision(10) <<  fma << " fma " << abs(RESULT - fma) <<  endl;
    cout << setprecision(10) <<  accurate_sum1 << " accurate sum " << abs(RESULT - accurate_sum1) <<  endl;
}