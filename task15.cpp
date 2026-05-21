#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct kletka {   //хранение клетки
    int x, y;   //координаты клетки
    string path;  //путь до этой клетки
};
int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};  //все 8 возможных ходов
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

void koordinata(string cell, int &x, int &y) {   //переводим клетки "A1" в координаты
    y = cell[0] - 'A' + 1;  //А-1, B-2....
    x = cell[1] - '0';   //"1"-1 .....
}
string getkletka(int x, int y) {  //переводим обратно в клетку
    string res = "";
    res += char('A' + y - 1);
    res += char('0' + x);
    return res;
}
bool nadoske(int x, int y) {
    return (x >=1 && x <= 8 && y >= 1 && y <= 8);
}
int main() {
    setlocale(LC_ALL,"RUS");
    string nachalo, konec;
    cout << "Введите начальную клетку: ";
    cin >> nachalo;
    cout << "Введите конечную клетку: ";
    cin >> konec;

    int nachaloX, nachaloY, konecX, konecY;
    koordinata(nachalo, nachaloX, nachaloY);
    koordinata(konec, konecX, konecY);
    bool visit[9][9] = {false};

    queue<kletka> q;  //очередь хранит клетки для обхода
    kletka first;
    first.x = nachaloX;
    first.y = nachaloY;
    first.path = nachalo;    //путь до начальной - ее название
    visit[nachaloX][nachaloY] = true;   //начальную уже посетили
    q.push(first);   //начальную кладем в очередь

    while (!q.empty()) {
        kletka curr = q.front();   //берем первый элемент из очереди
        q.pop();  //удаляем его из очереди
        if (curr.x == konecX && curr.y == konecY) {  //если текущая - конечная
            cout << "Путь: " << curr.path << endl;
            return 0;
        }
        for (int i = 0; i < 8; i++) {  //все возможные 8 ходов
            int newX = curr.x + dx[i];   //текущая + смещение
            int newY = curr.y + dy[i];   //текущая + смещение
            if (nadoske(newX, newY) && !visit[newX][newY]) {  //если на доске и ее не посез+щали
                visit[newX][newY] = true;  //теперь посетили
                kletka next;   //создали новую клетку
                next.x = newX;
                next.y = newY;
                next.path = curr.path + " " + getkletka(newX, newY);  //старый путь + новая клетка
                q.push(next);  //кладем новую в очередь
            }
        }
    }
    cout << "Путь не найден" << endl;
}