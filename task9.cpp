#include <iostream>
#include <vector>
#include <algorithm>   //для count_if

using namespace std;

bool chislodelnatri(int x) {   //возвращает true, если число делится на 3
    return x % 3 == 0;
}

int main() {
    setlocale(LC_ALL,"RUS");
    int n;

    cout << "Введите количество чисел: ";
    cin >> n;

    vector<int> vec;

    int x;
    for (int i = 0; i < n; i++) {      //заполняем вектор
        cout << "a[" << i << "] = ";
        cin >> x;
        vec.push_back(x);        //добавление элемента в конец вектора
    }

    int count = count_if(vec.begin(), vec.end(),chislodelnatri);   //считаем кол-во элементов, кратных 3-ем. 

    cout << "Количество чисел, делящихся на три: " << count << endl;

    return 0;
}