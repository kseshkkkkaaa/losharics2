#include <iostream>
#include <string>
#include <cmath> 
using namespace std;

int vosm_v_desyat(const string& vosm_str) {   //переводим из восьмиричной в десятичную (из строки в число)
    int result = 0;
    int len = vosm_str.length();
    for(int i = 0; i < len; i++) {
        char c = vosm_str[i];
        int cifra = c - '0';  
        result += cifra * pow(8, len - 1 - i);
    }
    return result;
}

string desyat_v_vosm(int desyat_chislo) {  //переводим обратно (из числа в строку)
    if (desyat_chislo == 0) return "0";
    string result = "";
    while (desyat_chislo > 0) {
        int ostatok = desyat_chislo % 8;
        result = char('0' + ostatok) + result;  
        desyat_chislo = desyat_chislo / 8;
    }
    return result;
}

void slozhenie() {   //складываем
    string a_str, b_str;
    cout << "Введите первое число: ";
    cin >> a_str;
    cout << "Введите второе число: ";
    cin >> b_str;
    int a = vosm_v_desyat(a_str);
    int b = vosm_v_desyat(b_str);
    int summa = a + b;
    cout << a_str << "(8) + " << b_str << "(8) = ";
    cout << desyat_v_vosm(summa) << "(8)" << endl;
}

void vychitanie() {  //вычитаем 
    string a_str, b_str;
    cout << "Введите первое число: ";
    cin >> a_str;
    cout << "Введите второе число: ";
    cin >> b_str;
    int a = vosm_v_desyat(a_str);
    int b = vosm_v_desyat(b_str);
    int raznost = a - b;
    cout << a_str << "(8) - " << b_str << "(8) = ";
    cout << desyat_v_vosm(raznost) << "(8)" << endl;
}

void umnozhenie() {    //умножаем
    string a_str, b_str;
    cout << "Введите первое число: ";
    cin >> a_str;
    cout << "Введите второе число: ";
    cin >> b_str;
    int a = vosm_v_desyat(a_str);
    int b = vosm_v_desyat(b_str);
    int proizvedenie = a * b;
    cout << a_str << "(8) * " << b_str << "(8) = ";
    cout << desyat_v_vosm(proizvedenie) << "(8)" << endl;
}

void delenie() {    //делим
    string a_str, b_str;
    cout << "Введите делимое: ";
    cin >> a_str;
    cout << "Введите делитель: ";
    cin >> b_str;
    int a = vosm_v_desyat(a_str);
    int b = vosm_v_desyat(b_str);
    if (b == 0) {
        cout << "Ошибка: деление на ноль!" << endl;
        return;
    }
    int chastnoe = a / b;
    int ostatok = a % b;
    cout << a_str << "(8) ? " << b_str << "(8) = ";
    cout << desyat_v_vosm(chastnoe) << "(8)" << endl;
    cout << "Остаток: " << desyat_v_vosm(ostatok) << "(8)" << endl;
}

int main() {
    setlocale(LC_ALL, "RUS");
    int vybor;
    do {
        cout << "\nВосьмиричный калькулятор\n";
        cout << "1. Перевод из 8-ой в 10-ую\n";
        cout << "2. Перевод из 10-ой в 8-ую\n";
        cout << "3. Сложение\n";
        cout << "4. Вычитание\n";
        cout << "5. Умножение\n";
        cout << "6. Деление\n";
        cout << "0. Выход\n";
        cout << "Выберите операцию: ";
        cin >> vybor;
        switch(vybor) {
            case 1: {
                string vosm_str;
                cout << "Введите восьмеричное число: ";
                cin >> vosm_str;
                int result = vosm_v_desyat(vosm_str);
                cout << vosm_str << "(8) = " << result << "(10)" << endl;
                break;
            }
            case 2: {
                int desyat_chislo;
                cout << "Введите десятичное число: ";
                cin >> desyat_chislo;
                string result = desyat_v_vosm(desyat_chislo);
                cout << desyat_chislo << "(10) = " << result << "(8)" << endl;
                break;
            }
            case 3: slozhenie(); break;
            case 4: vychitanie(); break;
            case 5: umnozhenie(); break;
            case 6: delenie(); break;
            case 0: cout << "Выход\n"; break;
            default: cout << "Неверный выбор!\n";
        }
    } while(vybor != 0);
    return 0;
}