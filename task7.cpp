#include <iostream>
#include <string>
using namespace std;

bool soglasnay(char bykva) {   //провер€ем €вл€етс€ ли символ согласным или нет
    bykva = tolower(bykva);   //дл удобства переводим в нижний регистр
    return isalpha(bykva) && bykva != 'a' && bykva != 'e' && bykva != 'y' && bykva != 'u' && bykva != 'i' && bykva != 'o';   //проевер€ем буква это или нет, и провер€ем что она не гласна€
}

int main() {
    setlocale(LC_ALL,"RUS");
    string predloz;
    cout << "¬ведите строку, содержащую латинские буквы: ";
    getline(cin, predloz);  //считываем строку 
    for (int i = predloz.length()-1; i >= 0; i--) {   //проходим по строке с конца к началу. “ак удобней работать с индексами последующий символов
        if (soglasnay(predloz[i])) {  
            predloz.insert(i+1,1,'!');   //вставл€ем после текущего символа '!'
        }
    }
    cout << "–езультат: " << predloz << endl;
    return 0;
}