#include <iostream>
#include "map.hpp"

int main ()
{
  ft::map<char,int> mymap;

  mymap['x']=1001;
  mymap['y']=2002;
  mymap['z']=3003;

  std::cout << "mymap contains:\n";

  ft::pair<char,int> highest = *mymap.rbegin();          // last element

  ft::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << std::endl;
  } while (mymap.value_comp()(*it++, highest))
    ;

    std::cout << "Size of map: " << mymap.size() << std::endl;
    std::cout << "Max size of map: " << mymap.max_size() << std::endl;

  return 0;
}