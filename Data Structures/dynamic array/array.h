#ifndef ARRAY_H
#define ARRAY_H


template<class T>
class array
{
  public:
    array();
    array(const unsigned int);
    array(const unsigned int, const T);
    ~array();

    unsigned int size() const;
    unsigned int capacity() const;
    void resize(unsigned int);
    void shrink_to_fit();
    bool empty() const;
    T& operator[] (unsigned int);
    T& front();
    T& back();
    void assign(const unsigned int, const T);
    void push_back(const T);
    void pop_back();
    void insert(unsigned int, const T);
    void erase(unsigned int);
    void clear();
    void swap(array&);

  private:
    unsigned int _size;
    unsigned int _capacity;
    unsigned int _grow_factory;
    T *arr;

    void grow();
    bool full() const;



};

#endif // ARRAY_H
