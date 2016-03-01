#include <iostream>
#include <list>
using namespace std;

int main(void)
{
  list<int> l; // Doubly linked list

  l.push_back(7);  // append element to list
  l.push_back(10); // append element to list
  l.push_front(5); // insert element at begining

  // access front and back element
  cout << "Front element " << l.front()
       << " Back element " << l.back() << endl;

  cout << "List size " << l.size() << endl; // number of elements

  list<int> l2(l); // copy ctor
  // access front and back element
  cout << "Front in L2 " << l2.front()
       << " Back in L2 " << l2.back() << endl;

  cout << "Removing elements in L2" << endl;
  l2.clear();  // remove all items

  cout << l.size() << endl; // check if indeed removed all elements
  if (l2.empty()) {
      cout << "l2 is empty..." << endl;
  }
  if (!l.empty()) {
      cout << "l is not empty..." << endl;
  }

  cout << "Adding some more elements..." << endl;
  l.push_back(15);
  l.push_back(25);
  l.push_back(35);
  l.push_back(45);

  cout << "List size " << l.size() << endl; // number of elements

  // remove first element
  cout << "Front element before deletion " << l.front() << endl;
  l.pop_front();
  cout << "Front element after deletion " << l.front() << endl;

  // remove element with value 25
  l.remove(25);
  cout << "List size after deletion of 25"
       << l.size() << endl; // did it remove 25?

  // iterators
  // Iterators represent semi-open intervals [begin, end) i.e.
  // end doesn't point to last element but beyond last element
  cout << "Printing list using iterators..." << endl;
  for (list<int>::iterator i = l.begin(), e = l.end(); i != e; ++i) {
      cout << *i << " ";
  }
  cout << endl;

  // Insert element after 2rd element.
  list<int>::iterator i = l.begin();
  ++i;
  ++i;

  l.insert(i, 99);
  cout << "Printing list after inserting 99 after 2rd element..." << endl;
  for (list<int>::iterator i = l.begin(), e = l.end(); i != e; ++i) {
      cout << *i << " ";
  }
  cout << endl;

  return 0;
}