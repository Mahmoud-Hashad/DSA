#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
  queue test;
  test.push(1);
  test.push(2);
  test.push(3);
  test.push(4);
  test.push(5);


  cout << test.size() << endl;
  cout << test.pop() << endl;
  cout << test.pop() << endl;
  cout << test.size() << endl;
  cout << test.pop() << endl;
  cout << test.pop() << endl;
  cout << test.pop() << endl;
  cout << test.pop() << endl;
  cout << test.pop() << endl;
  cout << test.empty() << endl;
  cout << test.pop() << endl;
  cout << test.empty() << endl;
  return 0;
}
