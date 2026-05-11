#include <iostream> 

int **sozdanie (int n, int m) {
    int **a = new int *[n];
    for (int i = 0; i < n; i++)
        a[i] = new int [m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            std::cout << "a[" << i << "][";
            std::cout << j << "]=";
            std::cin >> a[i][j];
        }
    return a;
}

void print (int **a, int n, int m) {
    for (int i = 0; i < n; i++, std::cout << std::endl)
        for (int j = 0; j < m; j++)
            std::cout << a[i][j] << " ";
    std::cout << std::endl;
}

void smena (int **a, int n, int m) {
    for (int i = 0; i < n / 2; i++)
        for (int j = 0; j < m; j++)
            std::swap(a[i][j], a[n-1-i][j]);
}

int main() {
    setlocale(LC_ALL,"RUS");
    int n, m;
    std::cout << "¬ведите размер матрицы n: ";
    std::cin >> n;

    std::cout << "¬ведите размер матрицы m: ";
    std::cin >> m;

    int **a = sozdanie(n,m);
    print(a,n,m);
    smena(a,n,m);
    print(a,n,m);

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    
    return 0;
}