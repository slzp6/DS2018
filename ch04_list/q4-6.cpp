/* code: q4-6.cpp   (v1.18.00) */
#include <iostream>
#include <list>
#include <cstdlib>

using namespace std;

int main () {
  list < int >dl;
  list < int >::iterator ptr;
  int i, r;

  for (i = 0; i < 3; i++) {
    r = rand () % 100;
    cout << "push_front: " << r << "\n";
    dl.push_front (r);
  }
  cout << "list (" << dl.size () << ") : ";
  ptr = dl.begin ();
  while (ptr != dl.end ()) {
    cout << *ptr++ << " ";
  }
  cout << "\n\n";

  for (i = 0; i < 3; i++) {
    r = rand () % 100;
    cout << "push_back:  " << r << "\n";
    dl.push_back (r);
  }
  cout << "list (" << dl.size () << ") : ";
  ptr = dl.begin ();
  while (ptr != dl.end ()) {
    cout << *ptr++ << " ";
  }
  cout << "\n\n";

  for (i = 0; i < 3; i++) {
    cout << "pop_front \n";
    dl.pop_front ();
  }
  cout << "list (" << dl.size () << ") : ";
  ptr = dl.begin ();
  while (ptr != dl.end ()) {
    cout << *ptr++ << " ";
  }
  cout << "\n";

  return 0;
}
