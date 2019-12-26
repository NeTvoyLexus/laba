#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
class Stack
{
private:
    T* stackPtr;
    int size;
    T top;
    void extend();
public:
    Stack(int = 3);
    ~Stack(); 
    void push(const T); 
    void pop(); 
    void printStack();
};

template <typename T>
Stack<T>::Stack(int s){
    size = s;
    stackPtr = new T[size]; 
    top = -1;
}

template <typename T>
Stack<T>::~Stack(){
    delete[] stackPtr;
}

template<typename T>
inline void Stack<T>::extend(){
    size += 1;
    T* temp = new T[size];
    for (int i = 0; i < size - 1; i++) {
        temp[i] = stackPtr[i];
    }
    delete stackPtr;
    stackPtr = temp;
}

template <typename T> //добавить элемент в конец
void Stack<T>::push(const T value){
    if (top == size - 1) extend();
    top++;
    stackPtr[top] = value;
}

template <typename T> //убрать верхний
void Stack<T>::pop(){
    if (top > -1) { 
        stackPtr[top] = 0; 
        top--; 
    }
}

template <typename T>
void Stack<T>::printStack(){
    for (int k = size - 1; k >= 0; k--)
        cout << "~" << setw(4) << stackPtr[k] << endl;
}