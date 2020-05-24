#ifndef STACK_H
#define STACK_H

#include "array.h"

template<class T>
class stack
{
  public:
    stack();
    stack(unsigned int size, T value);
    ~stack();

    bool empty() const;
    unsigned int size() const;
    T& top() const;
    void push(T value);
    void pop();
    void swap(stack<T>);
  private:
    array<T>* data;
};

#endif // STACK_H
