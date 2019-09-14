#include <iostream>
#include "dstack.h"

using namespace std;

int main()
{
  dstack test;
  test.push(0);
  test.push(1);
  test.push(2);
  test.push(3);
  cout << test.top() << endl;
  test.pop();
  cout << test.top() << endl;
  cout << test.size();
  return 0;
}
