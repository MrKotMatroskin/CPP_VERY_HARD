# include <random>
# include <iostream>
# include <fstream>

using namespace std;
int n = 10; //начальная сторона кристалла
int cristal[10][10] = {0};//для отладки
bool flag = false;//флаг для цикла while
int seed = 0;//сид для локального генератора
double time = 0.;//среднее число ходов за 1000 итераций при данной стороне кристалла

int main() {
    mt19937 generator_global(23894728);//глобальный генератор сида для локального сида
    uniform_int_distribution<int> seed_generation(1, 1000000);//диапазон генерации локального сида
    uniform_int_distribution<int> move(1, 4);//диапазон вариантов передвижения
    ofstream file("C:\\Users\\Kot_Matroskin\\Desktop\\untitled\\task_one_date.txt");  // Открываем файл для записи
    for (int j = 0; j < 499; j++) { //главный for, в котором считается среднее число ходов для каждой стороны
        for (int i = 0; i < 1000; i++) {//второй for, в котором считается среднее число ходов
            seed = seed_generation(generator_global);//генерация локального сида
            //cout<<seed<<endl; //отладка
            mt19937 generator(seed);//локальный генератор
            uniform_int_distribution<int> dis_locator(1, n - 2);//диапазон координат
            int x = dis_locator(generator);
            int y = dis_locator(generator);
            flag = false;
            /*for (int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    cristal[i][j]=0;
                }
            }*/
            while (flag == false) {
                //cout<<x<<" "<<y<<endl;
                //cristal[x][y]=1;
                if (x == 0 || x == n - 1) {
                    flag = true;
                } else if (y == 0 || y == n - 1) {
                    flag = true;
                } else {
                    int a = move(generator);
                    if (a == 1) {
                        x--;
                    }
                    else if (a == 2) {
                        x++;
                    }
                    if (a == 3) {
                        y--;
                    }
                    if (a == 4) {
                        y++;
                    }
                    time++;
                }
            }
            /*for (int i = 0; i<n; i++){
              for(int j = 0; j<n; j++){
                cout<<cristal[i][j]<<" ";
              }
              cout<<endl;
            }
          cout<<time1;
          cout<<endl;*/
        }
        time = time / 1000;
        file << n << ";" << time << endl;  // Запись в файл
        n += 5;
        time = 0;
    }
    file.close();  // Закрывем файл!!!
    return 0;
}
