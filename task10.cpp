#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cctype>
using namespace std;

void risynokpoveshen(int oshibki) {  //функция для рисовки человечка по количеству ошибок
    cout << "\n  --------\n";
    cout << "  |      |\n";
    cout << "  |   ";
    if (oshibki >= 1) {
        cout << "   O";
    }
    cout << "\n";
    cout << "  |  ";
    if (oshibki >= 3) {
        cout << "   /|\\";
    } else if (oshibki >= 2) {
        cout << "    |";
    }
    cout << "\n";
    cout << "  |  ";
    if (oshibki >= 5) {
        cout << "   / \\";
    } else if (oshibki >= 4) {
        cout << "   /";
    }
    cout << "\n";
    cout << " /|\\\n";
    cout << "/ | \\\n\n";
}

int main() {
    setlocale(LC_ALL,"RUS");

    vector<string> spisok = {"happiness", "chocolate", "together", "everything", "badminton", "umbrella", "sleepyhead", "sundress", "generous", "beautiful"};  //список слов для игры

    srand(time(0));  //выбераем случайное слово из списка
    string zagadan_slovo = spisok[rand() % spisok.size()];
    for (int i = 0; i < zagadan_slovo.length(); i++) {
        zagadan_slovo[i] = tolower(zagadan_slovo[i]);
    }

    set<char> alfavit;  //множество для всех букв алфавита
    for (char c = 'a'; c <= 'z'; c++) {
        alfavit.insert(c);
    }

    set<char> yganan_bykvi;  //множество угаданных букв

    string vivod_slovo(zagadan_slovo.length(),'_');  //текущее слово которое угадывает игрок

    int max_oshibki = 6;  //максимальное количество ошибок
    int oshibki = 0;  //счетчик ошибок

    cout << "   Игра 'Виселица'   \n";
    cout << "Слово загадано из " << zagadan_slovo.length() << " букв\n";

    while (oshibki < max_oshibki && vivod_slovo != zagadan_slovo) {  
        cout << "\nСлово: ";  //вывод текущего слова 
        for (char c : vivod_slovo) {
            cout << c << " ";
        }
        cout << "\n";
        cout << "Алфавит: ";  //выводим доступные буквы
        for (char c : alfavit) {
            cout << c << " ";
        }
        cout << "\n";

        risynokpoveshen(oshibki);   //рисуем виселицу

        cout << "Ввести слово целиком(1) или букву(2)? ";
        int vibor;
        cin >> vibor;

        if (vibor == 1) {
            string ygaday;  //слово целиком
            cout << "Введи слово целиком: ";
            cin >> ygaday;
            for (int i = 0; i < ygaday.length(); i++) {
                ygaday[i] = tolower(ygaday[i]);
            }
            if (ygaday == zagadan_slovo) {
                vivod_slovo = zagadan_slovo;
                cout << "Вы угадали слово!\n";
                break;
            } else {
                cout << "Неправильное слово! Вы проиграли.\n";
                oshibki = max_oshibki;  //приравниваем к максимальным ошибкам чтобы закончить игру
                break;
            }
        }
        else if (vibor == 2) {
            char bykva; //угадываем одну букву
            cout << "Введи букву: ";
            cin >> bykva;
            bykva = tolower(bykva);
            if (alfavit.find(bykva) ==alfavit.end()) {  //проверяем есть ли буква в алфавите 
                cout << "Эта буква уже была. Вводите другую\n";
                continue;
            }
            alfavit.erase(bykva);    //удаляем букву 

            if (zagadan_slovo.find(bykva) != string::npos) {  //проверяем есть ли буква в слове 
                cout << "Такая буква есть\n";
                yganan_bykvi.insert(bykva);
                for (size_t i = 0; i < zagadan_slovo.length(); i++) {   //втсавляем букву на нужное место если она есть в слове
                    if (zagadan_slovo[i] == bykva) {
                        vivod_slovo[i] = bykva;
                    }
                }
            } else {
                cout << "Такой буквы нет\n";
                oshibki++;
            }
        } else {
            cout << "Попробуйте снова\n";
        }
    }
    if (vivod_slovo == zagadan_slovo) {
        cout << "\nУра! Вы отгадали слово: " << zagadan_slovo << "\n";
    } else {
        cout << "\nО нет. Вы проиграли. Загаданное слово: " << zagadan_slovo << "\n";
        risynokpoveshen(max_oshibki);
    }
    return 0;
}