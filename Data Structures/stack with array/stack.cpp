#include "stack.h"
#include "array.h"
#include "array.cpp"
// default constructor
template<class T>
stack<T>::stack(): data(new array<T>()) {}

// params: size : number of elements in the stack
//         value : a placeholder for all the positions
template<class T>
stack<T>::stack(unsigned int size, T value): data(new array<T>(size, value)) {}

// return:
// 0 : no element in stack
// 1 : there is at least one element
template<class T>
bool stack<T>::empty() const {
  return data->empty();
}

// return : number of elements in the stack
template<class T>
unsigned int stack<T>::size() const {
  return data->size();
}

// return last element added to the stack
template<class T>
T& stack<T>::top() const {
  return data->back();
}

// add new element to the end of the stack
template<class T>
void stack<T>::push(T value) {
  data->push_back(value);
}

// remove the last element in the stack
template<class T>
void stack<T>::pop() {
  data->pop_back();
}

// swap two stacks
template<class T>
void stack<T>::swap(stack<T> second_stack) {
  this->swap(second_stack);
}



template<class T>
stack<T>::~stack()
{
  delete data;
}
