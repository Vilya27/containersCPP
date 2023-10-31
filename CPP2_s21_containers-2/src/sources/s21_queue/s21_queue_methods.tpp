namespace s21 {

template <typename T>
typename queue<T>::const_reference queue<T>::front() const {
  if (data_.empty()) {
    throw std::out_of_range("queue is empty");
  }
  return data_.front();
}

template <typename T>
typename queue<T>::const_reference queue<T>::back() const {
  if (data_.empty()) {
    throw std::out_of_range("queue is empty");
  }
  return data_.back();
}

template <typename T>
typename queue<T>::size_type queue<T>::size() const {
  return data_.size();
}

template <typename T>
bool queue<T>::empty() const {
  return data_.empty();
}

template <typename T>
void queue<T>::push(const_reference value) {
  if (size() < data_.max_size()) {
    data_.push_back(value);
  } else {
    throw std::out_of_range("push(). Queue is full");
  }
}

template <typename T>
void queue<T>::pop() {
  if (!data_.empty()) {
    data_.pop_front();
  } else {
    throw std::out_of_range("pop(). Queue is empty");
  }
}

template <typename T>
void queue<T>::swap(queue& other) {
  data_.swap(other.data_);
}

}  // namespace s21
