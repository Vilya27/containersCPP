
namespace s21 {

// Operators
template <typename T>
stack<T>& stack<T>::operator=(const stack& other) {
  if (this != &other) {
<<<<<<< HEAD
    data = other.data;
=======
    data_ = other.data_;
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
  }
  return *this;
}

template <typename T>
stack<T>& stack<T>::operator=(stack&& other) noexcept {
  if (this != &other) {
<<<<<<< HEAD
    data = std::move(other.data);
=======
    data_ = std::move(other.data_);
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
  }
  return *this;
}
}  // namespace s21
