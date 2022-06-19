#include <algorithm>

template <typename T>
int easyfind(T& container, int target) {
  int cnt = 0;
  for (typename T::iterator itr = container.begin(); itr != container.end(); ++itr) {
    if (*itr == target)
      return cnt;
    cnt++;
  }
  return -1;
}
