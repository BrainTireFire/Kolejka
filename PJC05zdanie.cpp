#include <iostream>
#include "Rect.h"

//Zad 2

template<typename T>
class Queue {
    struct Node {
        T data;
        Node* next;
    };
    Node* head;
    Node* tail;
public:
    Queue();
    bool empty() const;
    void put(const T& data);
    T get();
    ~Queue();
};

template<typename T>
Queue<T>::Queue() {
    head = nullptr;
    tail = nullptr;
}

template<typename T>
bool Queue<T>::empty() const {
    if (head == nullptr) return true;
    return false;
}

template<typename T>
void Queue<T>::put(const T& data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    if (empty()) {
        tail = newNode;
        head = tail;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

template<typename T>
T Queue<T>::get() {
    T data = head->data;
    Node* newHead = head->next;
    delete head;
    head = newHead;
    return data;
}

template<typename T>
Queue<T>::~Queue() {
    while (!empty()) {
        std::cout << "Del:" << get() << " ";
    }
}

//Zad 3 
template <typename T>
struct Node { 
    T data; 
    Node* next; 
};

template <typename T>
Node<T>* arrayToList(const T arr[], size_t size); 

template <typename T, typename Pred>
void removeBad(Node<T>*& head, Pred p); 

template <typename T>
void showList(const Node<T>* head); 

template <typename T>
void deleteList(Node<T>*& head);

int main() {

    //Zad 1
    Rect* rect = new Rect(5,25);
    
    std::cout << "Bok A: " << rect->getA() << std::endl;
    std::cout << "Bok B: " << rect->getB() << std::endl;
    std::cout << "Pole: " << rect->getArea() << std::endl;
    std::cout << "Bok: " << rect->getDiagonal() << std::endl;
    rect->info();
    std::cout << std::endl;

    //Zad 2
    int data1, data2;

    Queue<int>* q = new Queue<int>();
    q->put(1);
    data1 = q->get();
    std::cout << " data1=" << data1 << std::endl;

    q->put(1);
    q->put(2);
    data1 = q->get();
    data2 = q->get();
    std::cout << " data1=" << data1
        << " data2=" << data2 << std::endl;

    q->put(1); q->put(2); q->put(3);
    q->put(4); q->put(5); q->put(6);
    while (!q->empty())
        std::cout << " " << q->get();
    std::cout << std::endl;

    q->put(1); q->put(2); q->put(3);
    delete q;
    std::cout << std::endl;

    //Zad 3
    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }; 
    size_t size = std::size(arr); 
    Node<int>* head = arrayToList(arr, size); 
    showList(head); 
    removeBad(head, [](int n) {return n % 2 != 0; }); 
    showList(head); 
    removeBad(head, [](int n) {return n < 5; }); 
    showList(head); 
    removeBad(head, [](int n) {return n > 9; }); 
    showList(head); 
    deleteList(head); 
    showList(head);

}
