namespace s21 {

template <typename T>
vector<T>& vector<T>::operator=(const vector& other) {
  if (this != &other) {
    delete[] data_;
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = new T[capacity_];
    std::copy(other.data_, other.data_ + other.size_, data_);
  }
  return *this;
}
<<<<<<< HEAD
=======

>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
template <typename T>
vector<T>& vector<T>::operator=(vector&& other) noexcept {
  if (this != &other) {
    delete[] data_;
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = other.data_;
    other.size_ = 0;
    other.capacity_ = 0;
    other.data_ = nullptr;
  }
  return *this;
}

}  // namespace s21