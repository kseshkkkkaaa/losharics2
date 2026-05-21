#include <iostream>
using namespace std;

struct list {
    int inf;
    list *next;
    list *prev;
};
void push(list *&h, list *&t, int x) {  //вставка элемента в конец списка
    list *r = new list;   //создаем новый элемент
    r->inf = x;
    r->next = NULL;    //всегда последний
    if (!h && !t) {    //если список пуст
        r->prev = NULL;    //первый элемент
        h = r;     //это голова
    } else {
        t->next = r;   //r - следующий для хвоста
        r->prev = t;   //хвост - предыдущий для r 
    }
    t = r;   //t теперь хвост
}
void del_node(list *&h, list *&t, list *r) {
    if (r == h && r == t) h = t = NULL;  //единственный элемент
    else if (r == h) {   //удаляем голову списка
        h = h->next;   //сдвигаем голову
        h->prev = NULL;
    }
    else if (r == t) {   //удаляем хвост списка
        t = t->prev;
        if (t) t->next = NULL;
    }
    else {
        r->next->prev = r->prev;  //для следующего от r предыдущим становится r->prev
        r->prev->next = r->next;  //для предыдущего от r следующим становится r->next
    }
    delete r;  //удаляем r
}
list *find_min(list *h) {
    if (!h) return NULL;
    list *p = h;    //указатель на голову
    list *min_node = h;   //первый - минимальный
    int min_value = h->inf;
    while (p) {
        if (p->inf < min_value) {
            min_value = p->inf;
            min_node = p;
        }
        p = p->next;
    }
    return min_node;
}
list *find_lastmin(list *h) {
    if (!h) return NULL;
    list *p = h;
    list *last_min = NULL;
    int min_value = find_min(h)->inf;
    while (p) {
        if (p->inf == min_value) {
            last_min = p;
        }
        p = p->next;
    }
    return last_min;
}
void print (list *h) {
    list *p = h;   //указатель на голову
    while (p) {
        cout << p->inf << " ";
        p = p->next;   //переходим к следующему
    }
    cout << endl;
}
void del_list(list *&h, list *&t) {  //удаление списка
    while (h) {
        list *p = h;     //указатель на голову
        h = h->next;   //переносим голову
        delete p;   //удаляем p
    }
    t = NULL;
}
int main() {
    setlocale(LC_ALL,"RUS");
    list *head = NULL;
    list *tail = NULL;
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    cout << "Введите " << n << " чисел: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        push(head, tail, x);
    }
    list *first_min = find_min(head);
    list *last_min = find_lastmin(head);
    if (last_min == first_min) {
        del_node(head, tail, first_min);
    } else {
        del_node(head, tail, first_min);
        last_min = find_lastmin(head);
        del_node(head, tail, last_min);
    }
    cout << "Результат: ";
    print(head);
    del_list(head, tail);
    return 0;
}