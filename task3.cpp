#include <iostream>

int main(){
    setlocale(LC_ALL,"RUS");
    int n;
    std::cout << "¬ведите число n: ";
    std::cin >> n;

    int delitel = 2;
    while (n>1){
        if (n%delitel==0){
            std::cout << delitel;
            n /= delitel;
            if (n>1){
                std::cout << " x ";
            }
        } else {
            delitel++;
        }
    }
    return 0;
 }