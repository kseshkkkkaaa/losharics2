#include<iostream>
using namespace std;

struct stack {   //структура для стека
    int inf;      //хранение целого числа
    stack *next;    //указатель на следующий элемент стека
};
void push(stack *&h, int x) {   //&h - ссылка на указатель 
    stack *r = new stack;    //выделяем память под новый узел в динамической памяти
    r->inf = x;   //записываем хначение x
    r->next = h;   //новый элемент указывает на старую голову стека
    h = r;   //теперь новый элемент - голова стека
}
int pop(stack *&h) {    //возвращает int
    int i = h->inf;     // сохраняем значение из головы стека в переменную
    stack *r = h;   //запоминаем текущую
    h = h->next;   //преемещаем голову на следующий
    delete r;  //удаляем старую
    return i;   //возвращаем 
}
void reverse(stack *&h) {   //принимаем ссылку на указатель головы стека
    stack *head1 = NULL;   //создаем пустой временный стек
    while (h)  //пока стек не пуст
        push(head1, pop(h));  //извлекаем из h и добавляем в head1
    h = head1;  //присваиваем указатель на перевернутый стек
}
stack *insertAfterFirstOdd(stack *&h, int newValue) {  //возвращает указатель на новый стек
    if (!h) return NULL;   //если стек пустой, возвращаем null
    reverse(h);  //переворачиваем стек
    stack *result = NULL;   //стек для хранения результата
    bool found = false;   //нашли ли первое нечетное
    stack *temp = NULL;  //временный стек для обхода
    while (h) {   //перекладвываем из h в temp
        int x = pop(h);   //извлекаем из h
        push(temp, x);   //добавляем его в temp
    }
    while (temp) {   //перекладываем из temp в result
        int x = pop(temp);  //извлекаем 
        push(result, x);  //добавляем
        
        if (!found && x % 2 != 0) {   
            found = true;
            push(result, newValue); 
        }
    }
    reverse(result);   //переворачиваем в исходный порядок
    return result;
}
void printStack(stack *&h) {
    stack *temp = NULL;
    while (h) {
        int x = pop(h);
        cout << x << " ";
        push(temp, x);
    }
    while (temp) {
        push(h, pop(temp));
    }
}
int main() {
    setlocale(LC_ALL,"RUS");
    stack *head = NULL;   //создаем указатель на голову стека
    int n, x, newElement;
    cout << "Введите количество элементов: ";
    cin >> n;
    cout << "Введите " << n << " чисел: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        push(head, x);
    }
    reverse(head);
    cout << "Исходный стек: ";
    printStack(head);
    cout << endl;
    cout << "Введите элемент, который нужно вставить после первого нечетного: ";
    cin >> newElement;
    stack *newStack = insertAfterFirstOdd(head, newElement);
    cout << "Стек после вставки элемента " << newElement << " после первого нечетного: ";
    printStack(newStack);
    return 0;
}