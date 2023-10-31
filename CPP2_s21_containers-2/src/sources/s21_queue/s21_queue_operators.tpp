#include <utility>

namespace s21 {

template <typename T>
bool operator==(const queue<T>& lhs, const queue<T>& rhs) {
  return lhs.data_ == rhs.data_;
}

template <typename T>
bool operator!=(const queue<T>& lhs, const queue<T>& rhs) {
  return !(lhs == rhs);
}

template <typename T>
void swap(queue<T>& lhs, queue<T>& rhs) noexcept {
  lhs.swap(rhs);
}

}  // namespace s21
