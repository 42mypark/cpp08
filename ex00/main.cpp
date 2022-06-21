#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <vector>

#include "easyfind.hpp"

int main() {
  // Sequence containers
  std::cout << "[Sequence containers]" << '\n';
  std::cout << "=vector=" << '\n';
  std::vector<int> v;
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);
  v.push_back(40);

  try {
    std::cout << *easyfind(v, 30) << '\n';
    std::cout << *easyfind(v, 50) << '\n';
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  std::cout << std::endl;

  std::cout << "=list=" << '\n';
  std::list<int> l;
  l.push_back(10);
  l.push_back(20);
  l.push_back(30);
  l.push_back(40);

  try {
    std::cout << *easyfind(l, 20) << '\n';
    std::cout << *easyfind(l, 50) << '\n';
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  std::cout << std::endl;

  std::cout << "=deque=" << '\n';
  std::deque<int> dq;
  dq.push_back(10);
  dq.push_back(20);
  dq.push_back(30);
  dq.push_back(40);

  try {
    std::cout << *easyfind(dq, 30) << '\n';
    std::cout << *easyfind(dq, 50) << '\n';
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  std::cout << std::endl;

  return 0;
}
