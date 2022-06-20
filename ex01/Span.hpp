#ifndef Span_HPP
#define Span_HPP
#include <set>
#include <stdexcept>
class Span : private std::set<int> {
 private:
  unsigned int size_;
  Span();

 public:
  ~Span();
  Span(unsigned int size);
  Span(const Span& sp);
  Span&        operator=(const Span& sp);
  void         AddNumber(int num);
  void         AddNumber(int* arr, int n);
  void         ShowInside() const;
  unsigned int getSize() const;
  int          ShortestSpan() const;
  int          LongestSpan() const;
  class OverCapacityException : public std::exception {
    virtual const char* what() const throw();
  };
  class NoSpanFoundException : public std::exception {
    virtual const char* what() const throw();
  };
};

#endif  // span_HPP