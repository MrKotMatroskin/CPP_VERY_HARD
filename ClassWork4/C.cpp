#include <iostream>
using namespace std;
static int count = 0;
void counter() {
    count++;
}

int main() {
    for (int i = 0; i < 10; ++i) {
        counter();
    }
    cout<<count;
    return 0;
}
