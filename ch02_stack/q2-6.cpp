/* code: q2-6.cpp   (v1.18.00) */
#include <iostream>
#include <stack>
using namespace std;

int main () {
  stack < int >s;

  s.push (300);
  s.push (400);
  s.push (500);

  while (!s.empty ()) {
    cout << "pop: ";
    cout << s.top () << "\n";
    s.pop ();
  }

  return 0;
}
