// Programmer: Dhanush Patel
// Programmer's ID: 1553428

#include <algorithm>
#include <iostream>
using namespace std;

#include<cassert>

#include "DynamicArray.h"
#include "DynamicArray.h"

int main2(){
  cout << "Programmer: Dhanush Patel\n";
  cout << "Programmer's ID: 1553428\n";
  cout << "File: " << __FILE__ << endl;
  cout << endl;

  DynamicArray<int> a(100);
  cout << "Using int values:" << endl;
  cout << "Testing Array::Array\n";
  for (int i = 0; i < a.capacity(); i++){
    assert(a[i] == 0);
  }

  cout << "\nTesting the Array::operator[] setter\n";
  a[1] = 123;
  a[2] = 546;
  cout << "EXPECTED: 123 for a[1]\n";
  cout << "ACTUAL: " << a[1] << endl;
  assert(123 == a[1]);
  cout << "EXPECTED: 546 for a[2]\n";
  cout << "ACTUAL: " << a[2] << endl;
  assert(546 == a[2]);
  a[-1000] = 222;
  cout << "EXPECTED: 222 for a[-1000]\n";
  cout << "ACTUAL: " << a[-1000] << endl;
  assert(123 == a[1]);
  assert(546 == a[2]);
  assert(222 == a[-3]);
  assert(0 == a[100]); // should increase array capacity here and make new values 0 (for int)
  assert(222 != a[11]);
  assert(222 != a[0]);

  cout << "\nTesting the Array::operator[] getter\n";
  const DynamicArray<int> b = a;
  for (int i = 0; i < 10; i++){
    assert(a[i] == b[i]);
  }

  cout << "\nConst object test" << endl;
  const DynamicArray<int> c;
  assert(c.capacity());
  assert(c[0] == c[0]);

  cout << "\nObject copy test\n";
  DynamicArray<int> d(a); // making a copy, c = a would have worked too
  assert(a.capacity() == d.capacity());
  for (int i = 0; i < a.capacity(); i++){
    assert(a[i] == d[i]); // uses the setter version for both a and b
  }

  // object assignment test
  cout << "\nObject assignment test\n";
  DynamicArray<int> e;
  e = a;
  assert(a.capacity() == e.capacity());
  for (int i = 0; i < 10; i++)
    assert(a[i] == e[i]);

}
