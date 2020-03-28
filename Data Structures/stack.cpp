template <typename T>
class stack {
  private:
    T *arr;
    int _capacity;  // max number of element stack can hold
    int _top;
    bool full();
    void grow(); // double allocated memory for the stack

  public:
    stack();
    stack(int size);
    stack(int size, T val);
    ~stack();
    void push(T val);
    T pop();
    T top();
    int size();
    bool empty();
    void clear();
};


template<typename T>
bool stack<T>::full() {
  return this->_capacity == this->_top;
}

template<typename T>
void stack<T>::grow() {
  T *tempArr = new T[this->_capacity * 2];
  
  for(int i = 0; i < this->_capacity; i++)
    tempArr[i] = this->arr[i];
  
  this->_capacity *= 2;
  delete[] this->arr;
  this->arr = tempArr;
}




template<typename T>
stack<T>::stack() {
  this->arr = new T[3];
  this->_capacity = 3;
  this->_top = 0;
}


template<typename T>
stack<T>::stack(int size) {
  this->arr = new T[3];
  this->_capacity = size;
  this->_top = 0;
}

template<typename T>
stack<T>::stack(int size, T val) {
  this->arr = new T[size];
  this->_capacity = size;
  
  for(int i = 0; i < size; i++)
    arr[i] = val;
  
  this->_top = 0;
}


template<typename T>
void stack<T>::push(T val) {
  if(this->full()) this->grow();
  this->arr[this->_top++] = val;
}


template<typename T>
T stack<T>::pop() {
  if(this->empty()) throw "Empty Stack";
  return this->arr[--this->_top];
}

template<typename T>
T stack<T>::top() {
  if(this->empty()) throw "Empty Stack";
  return this->arr[this->_top - 1];
}

template<typename T>
int stack<T>::size() {
  return this->_top;
}

template<typename T>
bool stack<T>::empty() {
  return this->_top == 0;
}


template<typename T>
void stack<T>::clear() {
  delete[] this->arr;
  
  this->arr = new T[3];
  this->_capacity = 3;
  this->_top = 0;
}

template<typename T>
stack<T>::~stack() {
  delete[] this->arr;
  this->arr = 0;
}
