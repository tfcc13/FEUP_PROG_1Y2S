/*
Consider the following template class Stack<T> defined in header Stack.h:

template <typename T>
struct node { 
  T value;
  node<T>* next; 
};

template <typename T>
class Stack { 
public:
  Stack(); 
  ~Stack();
  size_t size() const;
  bool peek(T& elem) const;
  bool pop(T& elem);
  void push(const T& elem);
private:
  int size_;
  node<T>* top_;
};

The template is for a stack of elements stored using a singly-linked list of nodes using the node struct type. The stack should have the usual Last-In First-Out (LIFO) discipline: push(v) adds element v to the top of the stack, and pop() removes the element on top of the stack, i.e., the one that has been added to the stack most recently through push().

The class should work as follows:

    The top_ member field should point to the top of the stack, and the size_ member field should indicate the total number of elements in the stack;
    Stack() builds an initially empty stack;
    ~Stack() releases the associated memory to the stack elements;
    size() returns the number of elements stored in the stack;
    push(v) adds an element to the (top of the) stack;
    pop(v):
        if the stack is not empty, removes the element on top of the stack, assigns that element to v, and returns true; or
        simply returns false if the stack is empty, leaving v unchanged.
    peek(v):
        if the stack is not empty, assigns v with the element on top of the stack without removing the element and returns true; or
        simply returns false if the stack is empty, leaving v unchanged.

You should properly use new and delete, for node allocation and release, in order to avoid memory errors such as leaks, dangling references, etc. 
*/

#include "Stack.h"
#include <iostream>

using namespace std;

template <typename T>
Stack<T>::Stack() : size_(0), top_(nullptr) {}


template <typename T>
Stack<T>::~Stack() {
    node<T>* n = top_;
    while(n != nullptr) {
        node<T>* aux = n ->next;
        delete n;
        n = aux;
    }
}


template <typename T>

size_t Stack<T>::size() const {
    return size_;
}


template <typename T>
bool Stack<T>::peek(T& elem) const {
    if (top_ != nullptr) {
        elem = top_->value;
        return true;
    }
    return false;
}


template <typename T> 

bool Stack<T>::pop(T& elem) {
    if (top_ != nullptr) {
        elem = top_->value;
        node<T>* aux = top_->next;
        delete top_;
        top_ = aux;
        size_--;
        return true;
    }
    return false;
}


template <typename T>
void Stack<T>::push(const T& elem) {
    node<T>* aux = new node<T>;
    aux->value = elem;
    aux->next = top_;
    top_=aux;
    size_++;
}

int main() {
  // public tests (1 point each) 
  {
    Stack<int> s;
    const Stack<int>& r = s;
    int v = -1;
    cout << r.size()  << ' ' << boolalpha
         << r.peek(v) << ' ' << v << ' '
         << s.pop(v)  << ' ' << v << ' '
         << s.size() << '\n';
  } // -> 0 false -1 false -1 0
  {
    Stack<int> s;
    int v = -1;
    s.push(123);
    cout << s.size()  << ' ' << boolalpha
         << s.peek(v) << ' ' << v << ' '
         << s.pop(v)  << ' ' << v << ' '
         << s.size() << '\n';
  } // -> 1 true 123 true 123 0
  {
    Stack<string> s; string v;
    s.push("a"); s.push("b"); s.push("c");
    cout << s.size();
    while(s.pop(v)) cout << ' ' << v;
    cout << ' ' << s.size() << '\n';
  } // -> 3 c b a 0
  {
    Stack<int> s; int v = -1;
    s.push(111); s.push(222); s.push(333);
    cout << s.size();
    while(s.peek(v)) {
      cout << ' ' << v;
      s.pop(v);
      cout << ' ' << v;
      if (v % 2 != 0) s.push(v + 1);
      cout << ' ' << s.size(); }
    cout << '\n';
  } // -> 3 333 333 3 334 334 2 222 222 1 111 111 1 112 112 0

  cout << '\n';
  // private tests (1000 points each)
  {
    Stack<int> s; int v = -1;
    cout << boolalpha << s.size() << ' '
         << s.pop(v)  << ' ' << v << ' '
         << s.peek(v) << ' ' << v << ' '
         << s.peek(v) << ' ' << v << ' '
         << s.pop(v)  << ' ' << v << ' '
         << s.size()  << '\n';
  } // -> 0 false -1 false -1 false -1 false -1 0
  {
    Stack<int> s;
    for (int i = 0; i < 10; i++) s.push(i);
    cout << s.size();
    for (int v = -1; s.peek(v); s.pop(v)) { cout << v; }
    cout << s.size() << '\n';
  } // -> 1098765432100
  {
    Stack<int> s;
    for (int x = 500; x >= 0; x--) s.push(x);
    int sum = 0;
    for(int x = 0; x != 497; sum += x) { s.pop(x); }
    cout << sum << ' ' << s.size() << ' ';
    for (int x = -1; s.pop(x); cout << x) { }
    cout << ' ' << s.size() << '\n';
  } // -> 123753 3 498499500 0
  {
    Stack<string> s1, s2; string x("x");
    for (char i = '0'; i < '9'; i++) s1.push(x + i);
    for(string v; s1.pop(v); s2.push(v)) cout << v;
    for(string v; s2.pop(v);) cout << v;
    cout << s1.size() << s2.size() << '\n';
  } // -> x8x7x6x5x4x3x2x1x0x0x1x2x3x4x5x6x7x800
  {
    Stack<string> s; string x = "x";
    for (char i = '0'; i < '9'; i++) { s.push(x + i); }
    cout << s.size();
    for (string v = ""; s.pop(v); ) { 
      cout << v;
      if ((v[1] - '0') % 3 == 0) { s.push("X7"); } }
    cout << '\n';
  } // -> 9x8x7x6X7x5x4x3X7x2x1x0X7

  return 0;
}