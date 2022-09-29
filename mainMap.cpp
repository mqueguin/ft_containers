#include <iostream>
#include "map.hpp"
#include <map>

using namespace std;

int main ()
{
  ft::map<char,int> mymap;

  mymap.insert(ft::pair<char, int>('a', 22));
  mymap.insert(ft::pair<char, int>('b', 11));
  mymap.insert(ft::pair<char, int>('c', 43));
  mymap.insert(ft::pair<char, int>('d', 0));
  mymap.insert(ft::pair<char, int>('e', 15));
  mymap.insert(ft::pair<char, int>('f', 26));
  mymap.insert(ft::pair<char, int>('g', 47));

  ft::map<char, int>::iterator it = mymap.begin();
  cout << "Valeur de it->first: " << it->first << " et valeur de it->second: " << it->second << std::endl;
  ++it;
  cout << "Dans le main valeur de it->first: " << it->first << " => " << it->second << std::endl;
  /* cout << "Map contains: " << std::endl;
  for (it = mymap.begin(); it != mymap.end(); ++it)
    cout << "Valeur de it->first: " << it->first << " et de it->second: " << it->second << std::endl; */
/*   std::cout << "mymap contains:\n";
 */
  /* for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
    std::cout << "Valeur de " << it->first << " est " << it->second << std::endl; */

  //std::cout << "Valeur de it->first: " << ++(it->first) << " et valeur de it->second: " << ++(it->second) << std::endl;
  
  return 0;
}