#ifndef DSTACK_H
#define DSTACK_H

#include <iostream>

#define start 10

class dstack
{
  private:
    int *arr;
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
    void push(int number);
    int top();
    void pop();

};

#endif // DSTACK_H
