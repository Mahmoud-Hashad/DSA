#ifndef DSTACK_H
#define DSTACK_H

#include <iostream>

template <typename T>
class dstack
{
  private:
    T *arr;
    int top_pos;
    int stack_size;
    const int growth_factory;

    bool full();
    void expand();

  public:
    dstack();
    ~dstack();

    bool empty();
    int size();
    void push(T number);
    T top();
    void pop();
    void swap(dstack *para);
};


template <typename T>
dstack<T>::dstack(): arr(new T[10]), top_pos(-1), stack_size(10), growth_factory(2) {}
template <typename T>
dstack<T>::~dstack() {
  delete [] arr;
}

/*
  is full
  check if stack is full
*/
template <typename T>
bool dstack<T>::full() {
  return top_pos >= stack_size - 1;
}

/*
  empty
  check if stack is empty (has no items)
*/
template <typename T>
bool dstack<T>::empty(void) {
  return top_pos == -1;
}

/*
  size
  number of element at the stack
*/
template <typename T>
int dstack<T>::size() {
  return top_pos + 1;
}

/*
  expand
  allocate new array with double space
  to store more items
*/
template <typename T>
void dstack<T>::expand(void) {
  stack_size *= growth_factory; // calculate new size

  T *temp = arr;  // put arr at temp

  arr = new T[stack_size]; // allocate array new space

  for(int i = 0; i <= top_pos; i++) // copy all the element to new array
    arr[i] = temp[1];

  delete [] temp;
}

/*
  push
  add an item to end of the stack
*/
template <typename T>
void dstack<T>::push(T number){
  // if stack is full then expand
  if(full()) expand();

  // put the new item in the top of the stack
  arr[++top_pos] = number;
}

/*
  top
  return the item at top of the stack
*/
template <typename T>
T dstack<T>::top() {
  return empty()? 0 : arr[top_pos];
}

/*
  pop
  remove the item at the top of stack
*/
template <typename T>
void dstack<T>::pop(void) {
  top_pos--;
}

/*
  swap
  swap two stack
*/
template <typename T>
void dstack<T>::swap(dstack *para) {
  dstack *temp = para;
  para = this;
  this->arr = temp->arr;
  this->top_pos = temp->top_pos;
  this->stack_size = temp->stack_size;
}

#endif // DSTACK_H
