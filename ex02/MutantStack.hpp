#ifndef MutantStack_HPP
#define MutantStack_HPP
#include <deque>
#include <stack>

template <typename T, typename Cont = std::deque<T> >
class MutantStack : public std::stack<T> {
 private:
 protected:
  Cont c;

 public:
  ~MutantStack();
  MutantStack();
  MutantStack(const MutantStack<T, Cont>& ms);
  MutantStack<T, Cont>&                         operator=(const MutantStack<T, Cont>& ms);
  typedef Cont                                  container_type;
  typedef typename Cont::value_type             value_type;
  typedef typename Cont::size_type              size_type;
  typedef typename Cont::reference              reference;
  typedef typename Cont::const_reference        const_reference;
  typedef typename Cont::iterator               iterator;
  typedef typename Cont::const_iterator         const_iterator;
  typedef typename Cont::reverse_iterator       reverse_iterator;
  typedef typename Cont::const_reverse_iterator const_reverse_iterator;
  void                                          pop();
  void                                          push(const value_type& value);
  reference                                     top();
  const_reference                               top() const;
  bool                                          empty() const;
  size_type                                     size() const;
  iterator                                      begin();
  iterator                                      end();
  const_iterator                                begin() const;
  const_iterator                                end() const;
  reverse_iterator                              rbegin();
  reverse_iterator                              rend();
  const_reverse_iterator                        rbegin() const;
  const_reverse_iterator                        rend() const;
  const Cont&                                   getCont() const;
};

#include "MutantStack.tpp"

#endif  // MutantStack_HPP