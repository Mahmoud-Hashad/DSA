#include "dstack.h"

dstack::dstack(): arr(new int[10]), top_pos(-1), stack_size(10), growth_factory(2) {}
dstack::~dstack() {
  delete [] arr;
}

/*
  is full
  check if stack is full
*/
bool dstack::full() {
  return top_pos >= stack_size - 1;
}

/*
  empty
  check if stack is empty (has no items)
*/
bool dstack::empty(void) {
  return top_pos == -1;
}

/*
  size
  number of element at the stack
*/
int dstack::size() {
  return top_pos + 1;
}

/*
  expand
  allocate new array with double space
  to store more items
*/
void dstack::expand(void) {
  stack_size *= growth_factory; // calculate new size

  int *temp = arr;  // put arr at temp

  arr = new int[stack_size]; // allocate array new space

  for(int i = 0; i <= top_pos; i++) // copy all the element to new array
    arr[i] = temp[1];

  delete [] temp;
}

/*
  push
  add an item to end of the stack
*/
void dstack::push(int number){
  // if stack is full then expand
  if(full()) expand();

  // put the new item in the top of the stack
  arr[++top_pos] = number;
}

/*
  top
  return the item at top of the stack
*/
int dstack::top() {
  return empty()? 0 : arr[top_pos];
}

/*
  pop
  remove the item at the top of stack
*/
void dstack::pop(void) {
  top_pos--;
}

/*
  swap
  swap two stack
*/
void dstack::swap(dstack *para) {
  dstack *temp = para;
  para = this;
  this->arr = temp->arr;
  this->top_pos = temp->top_pos;
  this->stack_size = temp->stack_size;
}

