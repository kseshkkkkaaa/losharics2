#include <iostream>

int main(){
    setlocale(LC_ALL,"RUS");
    int a,x;
    std::cout << "Введите трёхзначное число a: ";
    std::cin >> a;
    std::cout << "Введите однозначное число x: ";
    std::cin >> x;

    int dig1, dig2, dig3;
    dig1 = a / 100;
    dig2 = (a / 10) % 10;
    dig3 = a % 10;

    if (a < 100 || a > 999 || x > 9){
        std::cout << "Некорректный ввод" << std::endl;
    }
    else if (dig1 > x && dig2 > x && dig3 > x){
        std::cout << (a - 100) << std::endl;
    }
    else if (dig1 > x && dig2 > x){
        std::cout << (a + 100) << std::endl;
    }
    else if (dig1 < x && dig2 < x && dig3 < x){
        std::cout << (a - 50) << std::endl;
    }
    else if (dig2 < x && dig3 < x){
        std::cout << (a + 50) << std::endl;
    }
    else{
        std::cout << (a + 10) << std::endl;
    }
    return 0;
}