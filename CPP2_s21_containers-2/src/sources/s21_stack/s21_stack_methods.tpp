
namespace s21 {

template <typename T>
typename stack<T>::const_reference stack<T>::top() const {
<<<<<<< HEAD
  if (data.empty()) {
    throw std::out_of_range("Attempt to call top() on an empty stack.");
  }
  return data.back();
=======
  if (data_.empty()) {
    throw std::out_of_range("Attempt to call top() on an empty stack.");
  }
  return data_.back();
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
}

template <typename T>
bool stack<T>::empty() const {
<<<<<<< HEAD
  return data.empty();
=======
  return data_.empty();
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
}

template <typename T>
typename stack<T>::size_type stack<T>::size() const {
<<<<<<< HEAD
  return data.size();
=======
  return data_.size();
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
}

template <typename T>
void stack<T>::push(const_reference value) {
<<<<<<< HEAD
  if (data.size() >= data.max_size()) {
    throw std::overflow_error("Stack is full");
  }
  data.push_back(value);
=======
  if (data_.size() >= data_.max_size()) {
    throw std::overflow_error("Stack is full");
  }
  data_.push_back(value);
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
}

template <typename T>
void stack<T>::pop() {
<<<<<<< HEAD
  if (data.empty()) {
    throw std::out_of_range("Attempt to call pop() on an empty stack.");
  }
  data.pop_back();
=======
  if (data_.empty()) {
    throw std::out_of_range("Attempt to call pop() on an empty stack.");
  }
  data_.pop_back();
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
}

template <typename T>
void stack<T>::swap(stack& other) {
<<<<<<< HEAD
  data.swap(other.data);
=======
  data_.swap(other.data_);
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
}

}  // namespace s21
