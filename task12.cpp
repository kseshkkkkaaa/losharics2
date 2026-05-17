#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream> 
using namespace std;

void heapify(vector<int>& arr, int n, int i) {  //просеивание в куче
    int biggest = i;  //сначал считаем, что самый большой - это текущий
    int left = 2 * i + 1;   //индекс левого потомка
    int right = 2 * i + 2;   //индекс правого потомка
    
    if (left < n && arr[left] > arr[biggest]) {  //если левый потомок существует и больше текущего максимума
        biggest = left;
    }
    if (right < n && arr[right] > arr[biggest]) {  //если правый потомок больше, обновляем 
        biggest = right;
    }
    if (biggest != i) {  //если нашли элемент больше родителя  
        swap(arr[i], arr[biggest]);
        heapify(arr, n, biggest);
    }
}

void heapsort(vector<int>& arr) {    //пирамидальная сортировка
    int n = arr.size();  //размер массива
    for (int i = n / 2 - 1; i >= 0; i--) {  //идем с середины массива к началу
        heapify(arr, n, i);  //превращаем каждый подмассив в кучу
    }
    for (int i = n - 1; i > 0; i--) { //проходим с конца к началу
        swap(arr[0], arr[i]); // меняем максимальный элемент в конец
        heapify(arr, i, 0);  //восстанавливаем кучу для оставшихся элементов
    }
}

vector<vector<int>> chit_matr(const string& filename) {   //чтение матрицы из файла
    ifstream in(filename);   //создаем объект для чтения файла
    if (!in.is_open()) {  //если файл не открывается
        cerr << "Файл не открывается " << endl;
        exit(1);  //завершаем программу
    }
    
    vector<vector<int>> matriza;  //создаем пустую матрицу
    string line;   //строка для хранения одной строки

    while (getline(in, line)) {   //читаем файл построчно 
        if (line.empty()) continue;   //пустые строки пропускаем
        vector<int> stroka;  //создаем вектор для одной строки матрицы
        stringstream ss(line);  //превращаем строку в поток для удобства
        int chislo;  //переменная для числа
        while (ss >> chislo) {   //пока можем прочитать число из строки 
            stroka.push_back(chislo); 
        }
        if (!stroka.empty()) {  
            matriza.push_back(stroka);
        }
    }
    in.close(); //закрываем файл
    return matriza;
}

void gotov_matriza(const string& filename, const vector<vector<int>>& matriza) {  //записываем матрицу в файл
    ofstream out(filename);   //создаем объект для записи в файл
    if (!out.is_open()) {  //если файл не создался
        cerr << "Не создается файл " << filename << endl;
        exit(1);
    }
    int N = matriza.size();  //получаем размер матрицы, количество строк
    for (int i = 0; i < N; i++) {  //проходим по всем строкам
        for (int j = 0; j < N; j++) {  //проходим по всем столбцам
            out << setw(3) << matriza[i][j];  //выводим число
        }
        out << endl;
    }
    out.close();
}

int main() {
    setlocale(LC_ALL, "RUS");
    
    string inputFilename = "матрица.txt";  //входной файл
    string outputFilename = "готовая1.txt";  //созданный файл
    vector<vector<int>> matriza = chit_matr(inputFilename);   //читаем матрицу
     
    if (matriza.empty()) {
        cerr << "Пустой файл" << endl;
        return 1;
    }
    int N = matriza.size();  //получаем размер матрицы

    for (int j = 0; j < N; j++) {  //проходим по всем столбцам
        vector<int> stolbez;  //создаем вектор для столбца
        for (int i = 0; i < N; i++) {   //по строкам
            stolbez.push_back(matriza[i][j]);   //добавляем элемент в столбец 
        }
        heapsort(stolbez);  //сортруем столбец
        for (int i = 0; i < N; i++) {   //записываем обратно в матрицу
            matriza[i][j] = stolbez[i];  //обновляем элемент 
        }
    }
    gotov_matriza(outputFilename, matriza);  //записываем матрицу
    cout << "\nГотово! Результат в файле " << outputFilename << endl;
    return 0;
}