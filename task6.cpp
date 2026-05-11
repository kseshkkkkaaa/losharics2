#include <iostream>
using namespace std;

long long dvoinoifac(int n) {  //для больших значений факториала
    if (n <= 1) return 1;
    return n * dvoinoifac(n-2);
}

int main() {
    setlocale(LC_ALL,"RUS");
    int n;
    cout << "Введите n: ";
    cin >> n;
    if (n < 0) {
        cout << "Двойной факториал определён для n >= 0" << endl;  
    } else {
        cout << n << "!! = " << dvoinoifac(n) << endl;
    }
    return 0;
}