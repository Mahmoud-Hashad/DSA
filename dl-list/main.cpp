#include <iostream>
#include "dlist.h"

using namespace std;

int main()
{
  dlist<int> test;
  test.pushBack(1);
  test.pushBack(2);
  test.pushBack(3);
  test.pushBack(4);
  test.print();
  test.reverse();
  test.print();


  return 0;
}
