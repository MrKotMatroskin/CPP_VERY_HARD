# include <random>
# include <iostream>
# include <fstream>

using namespace std;
int n = 100; //сторона кристалла
int cristal[100][100] = {0};//массив кристалла c координатами дислокаций
bool cristal_bool[100][100] = {false};//массив кристалла c информацией о перемещениях
int x[10000] = {0}; //массив координат х
int y[10000] = {0}; //массив координат у
int percent = 0; // доля дислокаций в %
bool flag = false;//флаг для цикла while
int seed = 0;//сид для локального генератора
double time = 0;//среднее число ходов за 100 итераций при данной стороне кристалла

int main() {
    mt19937 generator_global(23894728);//глобальный генератор сида для локального сида
    uniform_int_distribution<int> seed_generation(1, 1000000);//диапазон генерации локального сида
    uniform_int_distribution<int> move(1, 4);//диапазон вариантов передвижения
    ofstream file("task_two_date2.txt");  // Открываем файл для записи
    for (percent = 1;
         percent < 95; ++percent) { //главный for, в котором считается среднее число ходов для каждой доли
        for (int i = 0; i < 100; i++) {//второй for, в котором считается среднее число ходов
            seed = seed_generation(generator_global);//генерация локального сида
            mt19937 generator(seed);//локальный генератор
            uniform_int_distribution<int> dis_locator(1, n - 2);//диапазон координат
            int nam_dis = percent * n * n / 100;
            for (int i = 0; i < nam_dis; i++) { //расстановка дислокаций
                int a = dis_locator(generator);
                int b = dis_locator(generator);
                bool p = false;
                while (p == false) {
                    if (cristal[a][b] == 1) {
                        a = dis_locator(generator);
                        b = dis_locator(generator);
                        p = false;
                    } else {
                        p = true;
                        cristal[a][b] = 1;
                        cristal_bool[a][b] = true;
                        x[i] = a;
                        y[i] = b;
                    }
                }
            }
            int true_counter = 1;
            while (true_counter != 0) {
                true_counter = 0;
                for (int i = 0; i < nam_dis; i++) { //движение дислокаций с учетом узких мест
                    if (cristal_bool[x[i]][y[i]] == true) {
                        int a = move(generator);
                        if (a == 1) {
                            if (cristal[x[i] - 1][y[i]] != 1) {
                                cristal[x[i] - 1][y[i]] = 1;
                                cristal[x[i]][y[i]] = 0;
                                cristal_bool[x[i] - 1][y[i]] = false;
                                cristal_bool[x[i]][y[i]] = false;
                                x[i]--;
                            } else {
                                if (cristal_bool[x[i] - 1][y[i]] == true) {
                                    cristal[x[i]][y[i]] = 0;
                                    cristal_bool[x[i] - 1][y[i]] = false;
                                    cristal_bool[x[i]][y[i]] = false;
                                    x[i]--;
                                }
                            }
                        }
                        if (a == 2) {
                            if (cristal[x[i] + 1][y[i]] != 1) {
                                cristal[x[i] + 1][y[i]] = 1;
                                cristal[x[i]][y[i]] = 0;
                                cristal_bool[x[i] + 1][y[i]] = false;
                                cristal_bool[x[i]][y[i]] = false;
                                x[i]++;
                            } else {
                                if (cristal_bool[x[i] + 1][y[i]] == true) {
                                    cristal[x[i]][y[i]] = 0;
                                    cristal_bool[x[i] + 1][y[i]] = false;
                                    cristal_bool[x[i]][y[i]] = false;
                                    x[i]++;
                                }
                            }
                        }
                        if (a == 3) {
                            if (cristal[x[i]][y[i] - 1] != 1) {
                                cristal[x[i]][y[i] - 1] = 1;
                                cristal[x[i]][y[i]] = 0;
                                cristal_bool[x[i]][y[i] - 1] = false;
                                cristal_bool[x[i]][y[i]] = false;
                                y[i]--;
                            } else {
                                if (cristal_bool[x[i]][y[i] - 1] == true) {
                                    cristal[x[i]][y[i]] = 0;
                                    cristal_bool[x[i]][y[i] - 1] = false;
                                    cristal_bool[x[i]][y[i]] = false;
                                    y[i]--;
                                }
                            }
                        }
                        if (a == 4) {
                            if (cristal[x[i]][y[i] + 1] != 1) {
                                cristal[x[i]][y[i] + 1] = 1;
                                cristal[x[i]][y[i]] = 0;
                                cristal_bool[x[i]][y[i] + 1] = false;
                                cristal_bool[x[i]][y[i]] = false;
                                y[i]++;
                            } else {
                                if (cristal_bool[x[i]][y[i] + 1] == true) {
                                    cristal[x[i]][y[i]] = 0;
                                    cristal_bool[x[i]][y[i] + 1] = false;
                                    cristal_bool[x[i]][y[i]] = false;
                                    y[i]++;
                                }
                            }
                        }
                    } else {
                        cristal_bool[x[i]][y[i]] = false;
                    }

                }
                for (int i = 0; i < nam_dis; i++) { //отключение слипшихся дислокаций
                    if (x[i] == 0 || x[i] == n - 1) {
                        cristal_bool[x[i]][y[i]] = false;
                    } else {
                        if (y[i] == 0 || y[i] == n - 1) {
                            cristal_bool[x[i]][y[i]] = false;
                        } else {
                            int kv_dis =
                                    cristal[x[i] - 1][y[i]] + cristal[x[i] + 1][y[i]] + cristal[x[i]][y[i] - 1] +
                                    cristal[x[i]][y[i] + 1];
                            if (kv_dis == 0) {
                                cristal_bool[x[i]][y[i]] = true;
                                true_counter++;
                            } else cristal_bool[x[i]][y[i]] = false;
                        }
                    }
                }
                time++;
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cristal[i][j] = 0;
                    cristal_bool[i][j] = false;
                }
            }
        }
        time = time / 100;
        file << percent << ";" << time << endl;  // Запись в файл
        cout << time << endl;
        time = 0;
    }
    file.close();  // Закрывем файл!!!
    return 0;
}
