#ifndef DLIST_H
#define DLIST_H
#include<iostream>

template <typename T>
class dlist
{
  private:
    class node {
      public:
        T value;
        node * next, *previous;
        // node constructor
        node():next(0), previous(0) {}
    };

    node *head, *tail;
    int total_size;
  public:

    dlist():head(0), tail(0), total_size(0) {}
    ~dlist(){}
    // query method
    bool empty();
    int size();
    T front();
    T back();
    T at(int index);
    bool has(T key);
    int indexOf(T key);
    // add methods
    void pushFront(T value);
    void pushBack(T value);
    void insert(int index, T value);
    // modify methods
    void update(int index, T value);
    void reverse();
    void sort();
    // delete methods
    void popFront();
    void popBack();
    void remove(int index);
    void erase();

    void print();
};

// empty
template <typename T>
bool dlist<T>::empty() {
  return !head;
}

// size
template <typename T>
int dlist<T>::size() {
  return total_size;
}

// front
template <typename T>
T dlist<T>::front(){
  return empty()? INT_MAX : head->value;
}

// back
template <typename T>
T dlist<T>::back() {
  return empty()? INT_MAX : tail->value;
}

// at
template <typename T>
T dlist<T>::at(int index) {
  if(empty() || index < 0 || index >= total_size) return INT_MIN;

  node *temp = head;
  while(index) {
    temp = temp->next;
    index--;
  }

  return temp->value;
}

// has
template<typename T>
bool dlist<T>::has(T key) {
  if(empty()) return false;

  node *temp = head;
  do{
    if(temp->value == key)
      return true;

    temp = temp->next;
  } while(temp);
  return false;
}

// index of
template <typename T>
int dlist<T>::indexOf(T key) {
  if(empty()) return -1;

  int index = 0;
  node *temp = head;
  do{
    if(temp->value == key) return index;
    temp = temp->next;
    index++;
  }while(temp);

  return -1;
}

// push front
template <typename T>
void dlist<T>::pushFront(T value) {
  node *temp = new node;
  temp->value = value;
  temp->next = head;

  empty()? tail = temp : head->previous = temp;

  head = temp;

  total_size++;
}

// push back
template <typename T>
void dlist<T>::pushBack(T value) {
  if(empty()) {
    pushFront(value);
    return;
  }

  node *newNode = new node;
  newNode->value = value;
  newNode->previous = tail;

  tail->next = newNode;
  tail = tail->next;

  total_size++;
}

// insert
template <typename T>
void dlist<T>::insert(int index, T value) {
  if(index < 0 ) return;
  if(index == 0) {
    pushFront(value);
    return;
  }
  if(index >= total_size) {
    pushBack(value);
    return;
  }

  node *temp = head, *newNode = new node;

  while(index > 0 && temp->next) {
    temp = temp->next;
    index--;
  }

  newNode->value = value;
  newNode->next = temp;
  newNode->previous = temp->previous;
  temp->previous->next = newNode;
  temp->previous = newNode;

  total_size++;
}

// update
template <typename T>
void dlist<T>::update(int index , T value) {
  if(index < 0 || index >= total_size || empty()) return;

  node *temp = head;
  while(index) {
    temp = temp->next;
    index--;
  }

  temp->value = value;
}

// reverse
template<typename T>
void dlist<T>::reverse() {
  // swap head with tail
  node *t = head;
  head = tail;
  tail = t;

  node *temp = head;
  // loop over list nodes
  while(temp) {
    // swap next and previous
    t = temp->next;
    temp->next = temp->previous;
    temp->previous = t;

    // change node with the next one
    temp = temp->next;
  }
}

// sort
template <typename T>
void dlist<T>::sort() {
  // check validation conditions
  if(total_size <= 1) return;

  // temp pointer to the current element
  node *temp = head;

  // loop over the list
  for(int i = 0; i < total_size - 1; i++) {
    // loop to compare the current value with each element
    while(temp->next) {
      // if the current element larger than the next one
      if(temp->value > temp->next->value) {
        // swap the two node
        T t = temp->value;
        temp->value = temp->next->value;
        temp->next->value = t;
      }
      temp = temp->next;
    }

    temp = head;
  }
}

// pop front
template <typename T>
void dlist<T>::popFront() {
  if(empty()) return;
  node *temp = head;
  head = head->next;
  if(head) head->previous = 0;
  delete temp;

  total_size--;
}

// pop back
template <typename T>
void dlist<T>::popBack() {
  if(empty()) return;
  node * temp = tail;

  tail = tail->previous;

  tail? tail->next = 0 : head = tail;
  delete temp;

  total_size--;
}

// remove
template <typename T>
void dlist<T>::remove(int index) {
  if(index < 0 || index >= total_size || empty()) return;

  node *temp = head;

  while(index) {
    temp = temp->next;
    index--;
  }

  if(temp->previous) temp->previous->next = temp->next;
  if(temp->next) temp->next->previous = temp->previous;

  delete temp;

  total_size--;
}

// erase
template <typename T>
void dlist<T>::erase() {
  while(!empty()) popFront();
}

// print
template <typename T>
void dlist<T>::print() {
  node *temp = head;
  std::cout << "value \t address \t next \t\t previous" << std::endl;
  while(temp != 0) {
    std::cout << temp->value << "\t"
              << temp << "\t"
              << temp->next << "\t"
              << temp->previous << std::endl << std::endl;
    temp = temp->next;
  }
}



#endif // DLIST_H
