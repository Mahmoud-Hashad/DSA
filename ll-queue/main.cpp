#include <iostream>
#include "queue.h"

using namespace std;

int main()
{


  queue<int> p;
  p.push(1);
  p.push(2);
  p.push(3);
  p.push(4);

  cout << p.size() << endl;
  cout << p.pop() << endl;
  cout << p.pop() << endl;
  cout << p.pop() << endl;
  cout << p.pop() << endl;
  cout << endl << endl;


  queue<float> test;
  test.push(1.2);
  test.push(2.3);
  test.push(3.4);
  test.push(4.6);
  test.push(5.7);

  cout << test.size() << endl;
  cout << test.pop() << endl;
  cout << test.pop() << endl;
  cout << test.pop() << endl;
  cout << test.pop() << endl;
  cout << test.pop() << endl;




  return 0;
}
