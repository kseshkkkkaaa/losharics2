#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    setlocale(LC_ALL,"RUS");
    int n;
    std::cout << "¬ведите размер массива: ";
    std::cin >> n;

    int* a = new int[n];
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++){
        a[i] = rand() % 15;
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    int count = 0;

    for (int i = 0; i < n; i++){
        if (a[i] != 0 && a[i] % 2 == 0 && a[i] % 3 != 0){
            std::cout << i << " ";
            count++;
        }
    }

    if (!count) {
        std::cout << "таких элементов нет" << std::endl;
    }
    return 0;
}