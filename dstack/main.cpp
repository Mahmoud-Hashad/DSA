#include <iostream>
#include "dstack.h"

using namespace std;

int main()
{
  dstack<float> s1;
  dstack<int> s2;
  s1.push(1.4);
  s1.push(2.4);
  s1.push(3.4);
  s1.push(4.4);

  s2.push(5.4);
  s2.push(6.4);
  s2.push(7.4);
  s2.push(8.4);

  cout << s1.top() << endl;



  cout << s2.top() << endl;

  return 0;
}
