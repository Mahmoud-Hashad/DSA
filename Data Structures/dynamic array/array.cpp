#include "array.h"
#include <stdexcept>
// a default constructor set data members to default values
template<class T>
array<T>::array():_size(0), _capacity(0), _grow_factory(2), arr(nullptr)
{}

// allocate space of memory that can hold specific number of elements
template<class T>
array<T>::array(const unsigned int capacity):_size(0), _capacity(capacity), _grow_factory(2), arr(nullptr) {
  arr = new T[capacity];
}

// constructor overloading
// params: size - number of elements
//         value - repeated value in all the elements
template<class T>
array<T>::array(const unsigned int size, const T value):_size(size), _capacity(size), _grow_factory(2), arr(nullptr)
{
  arr = new T[size];
  for(int i = 0; i < size; i++)
    arr[i] = value;
}

// return number of elements in the array
template<class T>
unsigned int array<T>::size() const {
  return _size;
}

// return number of allocated elements in memory for the array
// return max number of element can the array hold before need resize
template<class T>
unsigned int array<T>::capacity() const {
  return _capacity;
}

// change the size of the array
// and delete all element over the new size if exists
template<class T>
void array<T>::resize(unsigned int nSize) {
    // allocate new memory with new size
    T *temp_arr = new T[nSize];

    // decide how many elements will transport to the new array
    unsigned len = nSize;
    if (nSize > _size)
      len =  _size;

    // move element to the new allocated memory
    for(unsigned int i = 0; i < len; i++)
      temp_arr[i] = arr[i];

    // free the old array memory then set the new one
    delete arr;
    arr = temp_arr;

    // change the size and capacity
    _size = len;
    _capacity = nSize;
}

// reduce the allocated memory same as the size
template<class T>
void array<T>::shrink_to_fit() {
  resize(_size);
}

// return:
//  1 : there at least one element in the array
//  0 : if no elements in the array
template<class T>
bool array<T>::empty() const {
  return _size == 0;
}

// return reference to the element at specific index
template<class T>
T& array<T>::operator[] (unsigned int index) {
  if(index < 0 || index >= _size)
    throw std::out_of_range("invalid index");

  return arr[index];
}

// return reference to the first element
template<class T>
T& array<T>::front() {
  if(empty())
    throw std::runtime_error("empty array");

  return arr[0];
}

// return reference to the last element
template<class T>
T& array<T>::back() {
  if(empty())
    throw std::runtime_error("empty array");

  return arr[_size - 1];
}

// change the array to an array of specific size and contain repeated element
// params: size - number of elements
//         value - repeated value in all the elements
template<class T>
void array<T>::assign(const unsigned int size, const T value)
{
  // free any allocated memory and change the size an capacity to new values
  delete arr;
  _size = _capacity = size;

  // allocated new pace and set all the elements to the value
  arr = new T[size];
  for(int i = 0; i < size; i++)
    arr[i] = value;
}

// add new element at the end of the array
template<class T>
void array<T>::push_back(const T value) {
  if(full()) grow();

  arr[_size++] = value;
}

// return the last element and remove it
template<class T>
void array<T>::pop_back() {
  if(empty())
    throw std::runtime_error("empty array");

  --_size;
}

// insert element at specific index
template<class T>
void array<T>::insert(unsigned int index, const T value) {
  // valid index or not
  if(index < 0 || index >= size())
    throw std::out_of_range("invalid index");

  // make sure there is enough space
  if(full()) grow();

  // shift all the element after that index
  for(int i = size(); i > index; i--)
    arr[i] = arr[i - 1];

  // but the new element at the index
  arr[index] = value;
  _size++;
}

// insert element at specific index
template<class T>
void array<T>::erase(unsigned int index) {
  // valid index or not
  if(index < 0 || index >= size())
    throw std::out_of_range("invalid index");

  // shift all the element form the index to the end
  for(int i = index, len = size(); i < len; i++)
    arr[i] = arr[i + 1];

  _size--;
}

// delete all the elements of the array
template<class T>
void array<T>::clear() {
  delete arr;
  arr = nullptr;

  _size = 0;
  _capacity = 0;
}

// return:
// 0 : no more space in the array for another element
// 1 : if there still space to add another element
template<class T>
bool array<T>::full() const {
  return _size == _capacity;
}

// allocate new memory
// new space = old space * grow factory
template<class T>
void array<T>::grow() {
  unsigned int nCapacity = _capacity * _grow_factory;
  if (nCapacity == _capacity)
    _capacity += 1;
  else
    _capacity = nCapacity;
  resize(_capacity);
}

// swap two arrays
template<class T>
void array<T>::swap(array &second_array) {
  // temp variables to hod this array data
  unsigned int t_size = _size;
  unsigned int t_capacity = _capacity;
  unsigned int t_grow_factory = _grow_factory;
  T *temp_arr = arr;

  // copy all of second array data to this
  _size = second_array._size;
  _capacity = second_array._capacity;
  _grow_factory = second_array._grow_factory;
  arr = second_array.arr;

  // copy the data in temp variables to second array
  second_array._size = _size;
  second_array._capacity = _capacity;
  second_array._grow_factory = _grow_factory;
  second_array.arr = temp_arr;
}

template<class T>
array<T>::~array()
{
  clear();
}
