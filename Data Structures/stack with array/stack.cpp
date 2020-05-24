#include "stack.h"
#include "array.h"
#include "array.cpp"

template<class T>
stack<T>::stack(): data(new array<T>()) {}

template<class T>
stack<T>::stack(unsigned int size, T value): data(new array<T>(size, value)) {}


template<class T>
bool stack<T>::empty() const {
  return data->empty();
}

template<class T>
unsigned int stack<T>::size() const {
  return data->size();
}

template<class T>
T& stack<T>::top() const {
  return data->back();
}

template<class T>
void stack<T>::push(T value) {
  return data->push_back(value);
}

template<class T>
void stack<T>::pop() {
  return data->pop_back();
}






template<class T>
stack<T>::~stack()
{
  //dtor
}
