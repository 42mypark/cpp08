#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stack>

#include "MutantStack.hpp"

namespace {
void DivTest() {
  std::string n;
  std::cout << "** Pleas Press Enter to do Next Test! **" << std::endl;
  std::getline(std::cin, n);
}

void MyTest() {
  std::cout << "[Interface Test]" << '\n';
  {
    MutantStack<int> ms;
    std::stack<int>  s;
    std::cout << "* initial state *" << '\n';
    std::cout << "MutantStack" << '\t' << "Stack" << '\n';
    std::cout << "size  : " << ms.size() << '\t' << "size  : " << s.size() << '\n';
    std::cout << "empty : " << ms.empty() << '\t' << "empty : " << s.empty() << '\n';
    ms.push(123);
    s.push(123);
    std::cout << "* after push '123' *" << '\n';
    std::cout << "top   : " << ms.top() << '\t' << "top   : " << s.top() << '\n';
    std::cout << "size  : " << ms.size() << '\t' << "size  : " << s.size() << '\n';
    std::cout << "empty : " << ms.empty() << '\t' << "empty : " << s.empty() << '\n';
    ms.pop();
    s.pop();
    std::cout << "* after pop *" << '\n';
    std::cout << "size  : " << ms.size() << '\t' << "size  : " << s.size() << '\n';
    std::cout << "empty : " << ms.empty() << '\t' << "empty : " << s.empty() << '\n';
  }
  std::cout << std::endl;

  DivTest();

  std::cout << "[Iterator Test]" << '\n';
  {
    srand(time(NULL));
    MutantStack<int> ms1;
    ms1.push(rand() % 1000);
    ms1.push(rand() % 1000);
    ms1.push(rand() % 1000);
    ms1.push(rand() % 1000);
    MutantStack<int> ms2(ms1);
    MutantStack<int> ms3 = ms1;
    {
      std::cout << "=iterator=" << '\n';
      MutantStack<int>::iterator itr1 = ms1.begin();
      MutantStack<int>::iterator itr2 = ms2.begin();
      MutantStack<int>::iterator itr3 = ms3.begin();
      std::cout << "ms1" << '\t' << "ms2" << '\t' << "ms3" << '\n';
      while (itr1 != ms1.end() || itr2 != ms2.end() || itr3 != ms3.end()) {
        std::cout << *itr1 << '\t' << *itr2 << '\t' << *itr3 << '\n';
        ++itr1;
        ++itr2;
        ++itr3;
      }
    }
    {
      std::cout << "=reverse iterator=" << '\n';
      MutantStack<int>::reverse_iterator itr1 = ms1.rbegin();
      MutantStack<int>::reverse_iterator itr2 = ms2.rbegin();
      MutantStack<int>::reverse_iterator itr3 = ms3.rbegin();
      std::cout << "ms1" << '\t' << "ms2" << '\t' << "ms3" << '\n';
      while (itr1 != ms1.rend() || itr2 != ms2.rend() || itr3 != ms3.rend()) {
        std::cout << *itr1 << '\t' << *itr2 << '\t' << *itr3 << '\n';
        ++itr1;
        ++itr2;
        ++itr3;
      }
    }
  }
  std::cout << std::endl;

  DivTest();

  std::cout << "[Compare Operator Test]" << '\n';
  {
    std::cout << "=equal=" << '\n';
    {
      MutantStack<int> ms1, ms2;
      std::stack<int>  s1, s2;
      std::cout << "* initial state *" << '\n';
      std::cout << "MutantStack" << '\t' << "Stack" << '\n';
      std::cout << (ms1 == ms2) << "\t\t" << (s1 == s2) << '\n';
      std::cout << "* after push '10' to s1, ms1 *" << '\n';
      s1.push(10);
      ms1.push(10);
      std::cout << (ms1 == ms2) << "\t\t" << (s1 == s2) << '\n';
      std::cout << "* after push '10' to s2, ms2 *" << '\n';
      s2.push(10);
      ms2.push(10);
      std::cout << (ms1 == ms2) << "\t\t" << (s1 == s2) << '\n';
    }
    std::cout << std::endl;

    DivTest();

    std::cout << "=not equal=" << '\n';
    {
      MutantStack<int> ms1, ms2;
      std::stack<int>  s1, s2;
      std::cout << "* initial state *" << '\n';
      std::cout << "MutantStack" << '\t' << "Stack" << '\n';
      std::cout << (ms1 != ms2) << "\t\t" << (s1 != s2) << '\n';
      std::cout << "* after push '10' to s1, ms1 *" << '\n';
      s1.push(10);
      ms1.push(10);
      std::cout << (ms1 != ms2) << "\t\t" << (s1 != s2) << '\n';
      std::cout << "* after push '10' to s2, ms2 *" << '\n';
      s2.push(10);
      ms2.push(10);
      std::cout << (ms1 != ms2) << "\t\t" << (s1 != s2) << '\n';
    }
    std::cout << std::endl;

    std::cout << "=greater=" << '\n';
    {
      MutantStack<int> ms1, ms2;
      std::stack<int>  s1, s2;
      std::cout << "* initial state *" << '\n';
      std::cout << "MutantStack" << '\t' << "Stack" << '\n';
      std::cout << (ms1 > ms2) << "\t\t" << (s1 > s2) << '\n';
      std::cout << "* after push '10' to s1, ms1 *" << '\n';
      s1.push(10);
      ms1.push(10);
      std::cout << (ms1 > ms2) << "\t\t" << (s1 > s2) << '\n';
      std::cout << "* after push '10' to s2, ms2 *" << '\n';
      s2.push(10);
      ms2.push(10);
      std::cout << (ms1 > ms2) << "\t\t" << (s1 > s2) << '\n';
    }
    std::cout << std::endl;

    DivTest();

    std::cout << "=greater equal=" << '\n';
    {
      MutantStack<int> ms1, ms2;
      std::stack<int>  s1, s2;
      std::cout << "* initial state *" << '\n';
      std::cout << "MutantStack" << '\t' << "Stack" << '\n';
      std::cout << (ms1 >= ms2) << "\t\t" << (s1 >= s2) << '\n';
      std::cout << "* after push '10' to s1, ms1 *" << '\n';
      s1.push(10);
      ms1.push(10);
      std::cout << (ms1 >= ms2) << "\t\t" << (s1 >= s2) << '\n';
      std::cout << "* after push '10' to s2, ms2 *" << '\n';
      s2.push(10);
      ms2.push(10);
      std::cout << (ms1 >= ms2) << "\t\t" << (s1 >= s2) << '\n';
    }
    std::cout << std::endl;

    DivTest();

    std::cout << "=less=" << '\n';
    {
      MutantStack<int> ms1, ms2;
      std::stack<int>  s1, s2;
      std::cout << "* initial state *" << '\n';
      std::cout << "MutantStack" << '\t' << "Stack" << '\n';
      std::cout << (ms1 < ms2) << "\t\t" << (s1 < s2) << '\n';
      std::cout << "* after push '10' to s1, ms1 *" << '\n';
      s1.push(10);
      ms1.push(10);
      std::cout << (ms1 < ms2) << "\t\t" << (s1 < s2) << '\n';
      std::cout << "* after push '10' to s2, ms2 *" << '\n';
      s2.push(10);
      ms2.push(10);
      std::cout << (ms1 < ms2) << "\t\t" << (s1 < s2) << '\n';
    }
    std::cout << std::endl;

    DivTest();

    std::cout << "=less equal=" << '\n';
    {
      MutantStack<int> ms1, ms2;
      std::stack<int>  s1, s2;
      std::cout << "* initial state *" << '\n';
      std::cout << "MutantStack" << '\t' << "Stack" << '\n';
      std::cout << (ms1 <= ms2) << "\t\t" << (s1 <= s2) << '\n';
      std::cout << "* after push '10' to s1, ms1 *" << '\n';
      s1.push(10);
      ms1.push(10);
      std::cout << (ms1 <= ms2) << "\t\t" << (s1 <= s2) << '\n';
      std::cout << "* after push '10' to s2, ms2 *" << '\n';
      s2.push(10);
      ms2.push(10);
      std::cout << (ms1 <= ms2) << "\t\t" << (s1 <= s2) << '\n';
    }
    std::cout << std::endl;
  }
}

}  // namespace

int main() {
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);

  DivTest();

  MyTest();
}