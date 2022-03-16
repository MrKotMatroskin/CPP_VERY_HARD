# include <random>
# include <iostream>
# include <fstream>
using namespace std;
int n = 10; //начальная длина кристалла
bool flag = false;//флаг для цикла while
int seed = 0;//сид для локального генератора
double time = 0;//среднее число ходов за 1000 итераций при данной стороне кристалла
int main() {
    mt19937 generator_global(23894728);//глобальный генератор сида для локального сида
    uniform_int_distribution<int> seed_generation(1, 1000000);//диапазон генерации локального сида
    uniform_int_distribution<int> move(1, 4);//диапазон вариантов передвижения
    ofstream file ("C:\\Users\\Kot_Matroskin\\Desktop\\untitled2\\task_three_one_dis.txt");  // Открываем файл для записи
    for (int j = 0; j < 499; j ++) { //главный for, в котором считается среднее число ходов для каждой стороны
        for (int i = 0; i < 1000; i++) {//второй for, в котором считается среднее число ходов
            seed = seed_generation(generator_global);//генерация локального сида
            mt19937 generator(seed);//локальный генератор
            uniform_int_distribution<int> dis_locator(1, n - 2);//диапазон координат
            int x = dis_locator(generator);
            flag = false;
            while (flag == false) {
                if (x == 0 || x == n - 1) {
                    flag = true;
                } else  {
                    int a = move(generator);
                    if (a == 1) {
                        x--;
                        time++;
                    }
                    if (a == 2) {
                        x++;
                        time++;
                    }
                }
            }
        }
        time = time/1000;
        file << n << ";" << time << endl;  // Запись в файл
        n=n+5;
        time = 0;
    }
    file.close();  // Закрывем файл!!!
    return 0;
}
