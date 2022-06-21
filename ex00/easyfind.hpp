#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int target) {
  typename T::iterator result = std::find(container.begin(), container.end(), target);
  if (result == container.end())
    throw std::out_of_range("easyfind: key not found");
  return result;
}
