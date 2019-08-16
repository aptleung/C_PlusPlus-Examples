 // lab6Ex3.cpp
// 
// ENSF 6 Lab 6 Exercise 3
//

#include <iostream>
using namespace std;

#include "OLList.h"

int main()
{
  OLList the_list;

  cout << "\nList just after creation: ";
  the_list.print();
  the_list.insert(330);
  the_list.insert(440);
  the_list.insert(220);
  the_list.insert(110);

  cout << "\nThe list after adding items: ";
  the_list.print();

  cout << "\nCreating a copy of the list..";
  OLList copycat(the_list);

  cout << "\nThe copied list after creation: ";
  copycat.print();

  copycat.insert(660);
  copycat.insert(770);
  copycat.insert(880);
  copycat.insert(123);
  copycat.insert(2);

  cout << "\nThe Lists after adding some items (660, 770, 880, 123, 2) to the copied list: \n";

  cout << "\nOriginal list: ";
  the_list.print();

  cout << "\nCopied List: ";
  copycat.print();

  copycat.remove(2);
  copycat.remove(110);
  copycat.remove(440);
  copycat.remove(880);
  copycat.insert(1000);
  copycat.remove(220);

  cout << "\nAfter removing some items (2, 110, 440, 880, 220) and adding (1000) on the copied list: ";
  copycat.print();

  the_list.remove(220);
  cout << "\nThe list after removing an item (220) from the original list: ";
  the_list.print();

  OLList empty;
  cout << "\nCreated an empty list, printing the emmpty list: ";
  empty.print();

  OLList empty_copy(empty);
  cout << "\nCopying the empty list, printing the empty list: ";
  empty_copy.print();

  cout << "\nAdding an element (100) to the empty copy, printing the copy: ";
  empty_copy.insert(100);
  empty_copy.print();
  cout << "\nPrinting the original empty list: ";
  empty.print();


  OLList oneitem;
  oneitem.insert(123);

  cout << "\nPrinting list with one item: ";
  oneitem.print();

  OLList one_copy(oneitem);

  cout << "\nPrinting the copy of the 1 item list: ";
  one_copy.print();

  cout << "\nAdding items (456, 789) to the copied list, printing the list: ";
  one_copy.insert(456);
  one_copy.insert(789);
  one_copy.print();

  cout << "\nPrinting the original list with 1 item: ";
  oneitem.print();

  cout << "\nDestroying the copied list..";
  copycat.~OLList();
  cout << "\nPrinting the copied list: ";
  copycat.print();
  
  cout << "\nDesotrying the lists..";
  one_copy.~OLList();
  empty_copy.~OLList();
  oneitem.~OLList();
  the_list.~OLList();
  empty.~OLList();

  system("pause");

  return 0;
}
