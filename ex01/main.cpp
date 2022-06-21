#include <iostream>

#include "Span.hpp"

namespace {
void DivTest() {
  std::string n;
  std::cout << "** Pleas Press Enter to do Next Test! **" << std::endl;
  std::getline(std::cin, n);
}
}  // namespace

int main() {
  Span s(20);

  std::cout << "[NoSpanFoundException Test]" << '\n';
  try {
    std::cout << s.LongestSpan() << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  s.AddNumber(8);
  try {
    std::cout << s.ShortestSpan() << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  std::cout << std::endl;

  DivTest();

  std::cout << "[Basic Test]" << '\n';
  int a1[] = {8, 10, 2, 20, 30, 7, 50, 100, -1, -27};
  s.AddNumber(a1, 10);
  s.ShowInside();
  std::cout << "longest  span : " << s.LongestSpan() << '\n';
  std::cout << "shortest span : " << s.ShortestSpan() << '\n';
  std::cout << '\n';

  DivTest();

  int a2[] = {123, 234, 345, 456, 567, 678, 11, 111, 0};
  s.AddNumber(a2, 9);
  s.ShowInside();
  std::cout << "longest  span : " << s.LongestSpan() << '\n';
  std::cout << "shortest span : " << s.ShortestSpan() << '\n';
  std::cout << std::endl;

  DivTest();

  std::cout << "[OverCapacityException Test]" << '\n';
  Span s2(s);
  try {
    s.AddNumber(777);
    s.AddNumber(777);
    s.AddNumber(778);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    int a2[] = {999, 999};
    s2.AddNumber(a2, 2);
    int a3[] = {997, 998};
    s2.AddNumber(a2, 2);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  std::cout << std::endl;
}