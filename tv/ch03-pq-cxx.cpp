/* code: ch03-pq-cxx.cpp   (v1.18.00) */
#include <iostream>
#include <queue>
#include <string>
using namespace std;

/* ------------------------------------------- */
class pq {
  int priority;
  string str;
public:
    pq () {
    priority = 0;
    str = "";
  } pq (string s, int p) {
    priority = p;
    str = s;
  }

  int getpriority () const {
    return priority;
  } string getstr () const {
    return str;
}};

/* ------------------------------------------- */
bool operator < (const pq & x, const pq & y) {
  return x.getpriority () > y.getpriority ();

}

/* ------------------------------------------- */
int main () {
  priority_queue < pq > mypq;

  mypq.push (pq ("apple", 30));
  mypq.push (pq ("banana", 10));
  mypq.push (pq ("pineapple", 20));

  while (!mypq.empty ()) {
    cout << mypq.top ().getpriority () << "\t";
    cout << mypq.top ().getstr () << "\n";

    mypq.pop ();
  }

  return 0;
}
