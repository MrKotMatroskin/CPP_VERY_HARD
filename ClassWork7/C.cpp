#include <iostream>
using namespace std;
struct time {
    int hours[2] = {0};
    int minutes[2] = {0};
    int seconds[2] = {0};
};
int main()
{
    time time;
    int seconds_global = 0;
    for (int i = 0; i<2; i++){
            cin>>time.hours[i]>>time.minutes[i]>>time.seconds[i];
    }
    seconds_global = (time.hours[0]+time.hours[1])*3600+(time.minutes[0]+time.minutes[1])*60+time.seconds[0]+time.seconds[1];
    cout<<(seconds_global/3600)%24<<":";
    seconds_global = seconds_global-(seconds_global/3600)*3600;
    cout<<seconds_global/60<<":";
    seconds_global=seconds_global-(seconds_global/60)*60;
    cout<<seconds_global;


}