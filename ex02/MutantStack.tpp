template <typename T, typename Cont>
class MutantStack;

template <typename T, typename Cont>
MutantStack<T, Cont>::~MutantStack() {
}

template <typename T, typename Cont>
MutantStack<T, Cont>::MutantStack() {
}

template <typename T, typename Cont>
MutantStack<T, Cont>::MutantStack(const MutantStack<T, Cont>& ms) : c(ms.getCont()) {
}

template <typename T, typename Cont>
MutantStack<T, Cont>& MutantStack<T, Cont>::operator=(const MutantStack<T, Cont>& ms) {
  this->c = ms.getCont();
  return *this;
}

template <typename T, typename Cont>
void MutantStack<T, Cont>::pop() {
  c.pop_back();
}

template <typename T, typename Cont>
void MutantStack<T, Cont>::push(const MutantStack<T, Cont>::value_type& value) {
  c.push_back(value);
}

template <typename T, typename Cont>
typename MutantStack<T, Cont>::reference MutantStack<T, Cont>::top() {
  return *(c.rbegin());
}

template <typename T, typename Cont>
typename MutantStack<T, Cont>::const_reference MutantStack<T, Cont>::top() const {
  return *(c.rbegin());
}

template <typename T, typename Cont>
bool MutantStack<T, Cont>::empty() const {
  return c.empty();
}

template <typename T, typename Cont>
typename MutantStack<T, Cont>::size_type MutantStack<T, Cont>::size() const {
  return c.size();
}

template <typename T, typename Cont>
typename MutantStack<T, Cont>::iterator MutantStack<T, Cont>::begin() {
  return c.begin();
}

template <typename T, typename Cont>
typename MutantStack<T, Cont>::const_iterator MutantStack<T, Cont>::begin() const {
  return c.begin();
}

template <typename T, typename Cont>
typename MutantStack<T, Cont>::reverse_iterator MutantStack<T, Cont>::rbegin() {
  return c.rbegin();
}
template <typename T, typename Cont>
typename MutantStack<T, Cont>::const_reverse_iterator MutantStack<T, Cont>::rbegin() const {
  return c.rbegin();
}

template <typename T, typename Cont>
typename MutantStack<T, Cont>::iterator MutantStack<T, Cont>::end() {
  return c.end();
}
template <typename T, typename Cont>
typename MutantStack<T, Cont>::const_iterator MutantStack<T, Cont>::end() const {
  return c.end();
}
template <typename T, typename Cont>
typename MutantStack<T, Cont>::reverse_iterator MutantStack<T, Cont>::rend() {
  return c.rend();
}
template <typename T, typename Cont>
typename MutantStack<T, Cont>::const_reverse_iterator MutantStack<T, Cont>::rend() const {
  return c.rend();
}

template <typename T, typename Cont>
const Cont& MutantStack<T, Cont>::getCont() const {
  return (c);
}

template <typename T, typename Cont>
bool operator==(const MutantStack<T, Cont>& a, const MutantStack<T, Cont>& b) {
  return a.getCont() == b.getCont();
}

template <typename T, typename Cont>
bool operator!=(const MutantStack<T, Cont>& a, const MutantStack<T, Cont>& b) {
  return a.getCont() != b.getCont();
}

template <typename T, typename Cont>
bool operator<(const MutantStack<T, Cont>& a, const MutantStack<T, Cont>& b) {
  return a.getCont() < b.getCont();
}

template <typename T, typename Cont>
bool operator<=(const MutantStack<T, Cont>& a, const MutantStack<T, Cont>& b) {
  return a.getCont() <= b.getCont();
}

template <typename T, typename Cont>
bool operator>(const MutantStack<T, Cont>& a, const MutantStack<T, Cont>& b) {
  return a.getCont() > b.getCont();
}

template <typename T, typename Cont>
bool operator>=(const MutantStack<T, Cont>& a, const MutantStack<T, Cont>& b) {
  return a.getCont() >= b.getCont();
}
