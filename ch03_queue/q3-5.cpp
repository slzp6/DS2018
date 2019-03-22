/* code: q3-5.cpp   (v1.18.00) */
#include <iostream>
#include <queue>
using namespace std;

int main () {
  queue < int >q;

  q.push (100);
  q.push (200);
  q.push (300);
  q.push (400);

  while (!q.empty ()) {
    cout << "dequeue: ";
    cout << q.front () << "\n";
    q.pop ();
  }

  return 0;
}
