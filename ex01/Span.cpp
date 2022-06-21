#include "Span.hpp"

#include <algorithm>
#include <iostream>

Span::~Span() {
}

Span::Span() {
}

Span::Span(unsigned int size) {
  size_ = size;
}

Span::Span(const Span& sp) : std::set<int>(sp), size_(sp.getSize()) {
}

Span& Span::operator=(const Span& sp) {
  this->std::set<int>::operator=(sp);
  size_ = sp.getSize();
  return *this;
}

bool Span::AlreadyIn(int num) {
  if (std::find(this->begin(), this->end(), num) != this->end())
    return true;
  return false;
}

unsigned int Span::getSize() const {
  return size_;
}

void Span::AddNumber(int num) {
  if (AlreadyIn(num))
    return;
  if (this->size() >= size_)
    throw OverCapacityException();
  this->insert(num);
}

void Span::AddNumber(int* arr, int n) {
  for (int i = 0; i < n; i++) {
    AddNumber(arr[i]);
  }
}

void Span::ShowInside() const {
  int cnt = 0;
  for (std::set<int>::iterator itr = this->begin(); itr != this->end(); ++itr) {
    std::cout << cnt << " : " << *itr << '\n';
    cnt++;
  }
}

int Span::ShortestSpan() const {
  if (this->size() == 0 || this->size() == 1)
    throw NoSpanFoundException();

  int                     min = LongestSpan();
  int                     prev = *(this->begin());
  std::set<int>::iterator itr = this->begin();
  ++itr;
  for (; itr != this->end(); ++itr) {
    if (min > (*itr - prev))
      min = *itr - prev;
    prev = *itr;
  }
  return min;
}

int Span::LongestSpan() const {
  if (this->size() == 0 || this->size() == 1)
    throw NoSpanFoundException();
  return *(this->rbegin()) - *(this->begin());
}

const char* Span::OverCapacityException::what() const throw() {
  return "The capacity is full";
}

const char* Span::NoSpanFoundException::what() const throw() {
  return "There is no span";
}