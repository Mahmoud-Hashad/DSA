#include <iostream>
#include "dstack.h"

using namespace std;

int main()
{
  dstack s1, s2;
  s1.push(1);
  s1.push(2);
  s1.push(3);
  s1.push(4);

  s2.push(5);
  s2.push(6);
  s2.push(7);
  s2.push(8);

  cout << s1.top() << endl;

  s1.swap(&s2);

  cout << s1.top() << endl;

  return 0;
}
