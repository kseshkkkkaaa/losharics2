#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

ifstream in("документик.txt");   //читаем файл
ofstream out("готовый документик1");  //создаем новый куда будет записываться информация

struct date {   //структура для хранения даты
    int den, mec, god;
};
struct people {  //структура для хранения данных о человеке
    string familia;
    string dolznost;
    date den_rozd;
    int staz;
    int zarplata;
};

date str_date(string str) {   //функция для преобразования строки в структуру date
    date x;
    string temp;
    temp = str.substr(0, 2);  //первые два символа - число
    x.den = atoi(temp.c_str()); //преобразует сроку temp в число и записывает в день структуры x. 
    temp = str.substr(3, 2);  
    x.mec = atoi(temp.c_str());
    temp = str.substr(6, 4);
    x.god = atoi(temp.c_str());
    return x;
}
vector<people> inFile() {  //функция возвращает список (вектор) структур people
    vector<people> x;  //создаем пустой вектор для хранения всех людей
    people temp;   //временная переменная для одного человека
    string tmp;  //временная переменная для хранения даты как строки
    while (in.peek() != EOF) {   //смотрим следующий символ пока не дошли до конца файла
        in >> temp.familia;  //читаем слово и записываем в временную структуру
        in >> temp.dolznost;
        in >> tmp;
        temp.den_rozd = str_date(tmp); //превращаем строку в дату
        in >> temp.staz;
        in >> temp.zarplata;
        x.push_back(temp);  //добавляем временную структуру в конец вектора
    }
    return x;
}
void vivod(people x) {   //выводим все аккуратно
    out << setw(15) << left << x.familia;
    out << setw(16) << left << x.dolznost;
    if (x.den_rozd.den < 10) out << '0' << x.den_rozd.den << ".";
    else out << x.den_rozd.den << ".";
    if (x.den_rozd.mec < 10) out << '0' << x.den_rozd.mec << ".";
    else out << x.den_rozd.mec << ".";
    out << setw(6) << left << x.den_rozd.god;
    out << setw(4) << left << x.staz;
    out << setw(10) << left << x.zarplata << endl;
}
void sort_po_gody(vector<people> &x) {  //функция примает вектор по ссылке, чтобы изменить исходный 
    if (x.empty()) return;  //если вектор пустой выходим
    int mingod = x[0].den_rozd.god;  //присваиваем мин год
    int maxgod = x[0].den_rozd.god;  //присваиваем макс год
    for (int i = 1; i < x.size(); i++) {
        if (x[i].den_rozd.god < mingod) mingod = x[i].den_rozd.god;
        if (x[i].den_rozd.god > maxgod) maxgod = x[i].den_rozd.god;
    }
    int kolvo = maxgod - mingod + 1;  //вычисляем диапозон 
    vector<people> buckets[kolvo];  //создаем массив векторов. каждый вектор хранит людей с одинаковым годом рождения
    for (int i = 0; i < x.size(); i++) {  //проходим по всем людям
        int indexgoda = x[i].den_rozd.god - mingod;  //вычисляем индекс текущего года 
        buckets[indexgoda].push_back(x[i]);  //добавляем человека 
    }
    int index = 0;  //счетчик для заполнения исходного вектора
    for (int y = 0; y < kolvo; y++) {  //цикл по  всем годам
        for (int k = 0; k < buckets[y].size(); k++) {  //цикл по всем людям одного года
            x[index++] = buckets[y][k];  //добавляем человека в исходный вектор на позицию, затем увеличиваем
        }
    }
}
int main() {
    setlocale(LC_ALL,"RUS");

    vector<people> x;  //создаем вектор для хранения всех сотрудников
    x = inFile();   //вызываем функцию чтения из файла
    if (x.empty()) {
        cout << "Файл пустой" << endl;
        return 1;
    }
    sort_po_gody(x);  //сортируем 
    out << "Результат сортировки:\n" << endl;
    for (int i = 0; i < x.size(); i++) {
        vivod(x[i]);  //выводим
    }
    cout << "Результат в файле готовый документик1" << endl;
    return 0;
}