namespace s21 {
template <typename T>
void vector<T>::allocate_new(size_type new_capacity) {
  T* new_data = new T[new_capacity];
  std::copy(data_, data_ + size_, new_data);
  delete[] data_;
  data_ = new_data;
  capacity_ = new_capacity;
}

template <typename T>
void vector<T>::deallocate() noexcept {
  delete[] data_;
  data_ = nullptr;
  capacity_ = 0;
  size_ = 0;
}

template <typename T>
typename vector<T>::reference vector<T>::front() {
  if (size_ == 0) {
    throw std::out_of_range("vector::front() - vector is empty");
  }
  return data_[0];
}

template <typename T>
typename vector<T>::const_reference vector<T>::front() const {
  if (size_ == 0) {
    throw std::out_of_range("vector::front() - vector is empty");
  }
  return data_[0];
}

template <typename T>
typename vector<T>::reference vector<T>::back() {
  if (size_ == 0) {
    throw std::out_of_range("vector::back() - vector is empty");
  }
  return data_[size_ - 1];
}

template <typename T>
typename vector<T>::const_reference vector<T>::back() const {
  if (size_ == 0) {
    throw std::out_of_range("vector::back() - vector is empty");
  }
  return data_[size_ - 1];
}

template <typename T>
void vector<T>::clear() noexcept {
  for (size_type i = 0; i < size_; ++i) {
    data_[i].~T();
  }
  size_ = 0;
}

template <typename T>
typename vector<T>::iterator vector<T>::insert(const_iterator pos,
                                               const T& value) {
  size_type index = pos - cbegin();
  if (size_ == capacity_) {
    size_type new_capacity;
    if (capacity_ == 0) {
      new_capacity = 1;
    } else {
      new_capacity = capacity_ * 2;
    }
    allocate_new(new_capacity);
  }
  iterator it_pos = begin() + index;
  std::move_backward(it_pos, end(), end() + 1);
  *it_pos = value;
  ++size_;
  return it_pos;
}

template <typename T>
typename vector<T>::iterator vector<T>::erase(const_iterator pos) {
  if (pos == cend()) {
<<<<<<< HEAD
    throw std::out_of_range("Invalid iterator: end()");  // выброс исключения
=======
    throw std::out_of_range("Invalid iterator: end()");
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
  }
  size_type index = pos - cbegin();
  iterator it_pos = begin() + index;
  std::move(it_pos + 1, end(), it_pos);
  pop_back();
  return it_pos;
}

<<<<<<< HEAD
// Добавление нового элемента в конец вектора
=======
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
template <typename T>
void vector<T>::push_back(const T& value) {
  if (size_ == max_size()) {
    throw std::out_of_range("Attempt to push_back on full vector");
  }
  if (size_ == capacity_) {
    size_type new_capacity = capacity_ == 0 ? 1 : capacity_ * 2;
    allocate_new(new_capacity);
  }
  data_[size_] = value;
  ++size_;
}

<<<<<<< HEAD
// Добавление нового элемента в конец вектора с перемещением
=======
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
template <typename T>
void vector<T>::push_back(T&& value) {
  if (size_ == max_size()) {
    throw std::out_of_range("Attempt to push_back on full vector");
  }

  if (size_ == capacity_) {
    size_type new_capacity = capacity_ == 0 ? 1 : capacity_ * 2;
    allocate_new(new_capacity);
  }
  data_[size_] = std::move(value);
  ++size_;
}

<<<<<<< HEAD
// Удаление последнего элемента вектора
=======
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
template <typename T>
void vector<T>::pop_back() {
  if (size_ > 0) {
    --size_;
  } else {
    throw std::out_of_range("Attempt to pop_back from empty vector");
  }
}

<<<<<<< HEAD
// Изменение размера вектора
=======
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
template <typename T>
void vector<T>::resize(size_type count) {
  if (count > max_size()) {
    throw std::out_of_range("resize() - requested size too large");
  }
  resize(count, T());
}

template <typename T>
void vector<T>::resize(size_type count, const T& value) {
  if (count > max_size()) {
    throw std::out_of_range("resize() - requested size too large");
  }
  if (count < size_) {
    size_ = count;
  } else if (count > size_) {
    size_type new_capacity;
    if (capacity_ == 0) {
      new_capacity = count;
    } else {
      new_capacity = capacity_;
    }
    while (new_capacity < count) {
      new_capacity *= 2;
    }
    if (new_capacity > capacity_) {
      allocate_new(new_capacity);
    }
    std::fill(data_ + size_, data_ + count, value);
    size_ = count;
  }
}

template <typename T>
void vector<T>::swap(vector& other) noexcept {
  std::swap(data_, other.data_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}

<<<<<<< HEAD
// Итераторы
=======
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
template <typename value_type>
typename vector<value_type>::iterator vector<value_type>::begin() {
  return iterator(data_);
}

template <typename value_type>
typename vector<value_type>::iterator vector<value_type>::end() {
  return iterator(data_ + size_);
}

template <typename value_type>
typename vector<value_type>::const_iterator vector<value_type>::cbegin() const {
  return const_iterator(data_);
}

template <typename value_type>
typename vector<value_type>::const_iterator vector<value_type>::cend() const {
  return const_iterator(data_ + size_);
}

template <typename value_type>
typename vector<value_type>::iterator vector<value_type>::data() {
  return data_;
}

template <typename T>
bool vector<T>::empty() const {
  return size_ == 0;
}

template <typename T>
typename vector<T>::size_type vector<T>::size() const {
  return size_;
}

template <typename T>
typename vector<T>::size_type vector<T>::max_size() const {
  size_type r = std::numeric_limits<size_type>::max() / sizeof(T) - 1;
  return r;
}

template <typename T>
void vector<T>::reserve(size_type new_cap) {
  if (new_cap > max_size()) {
    throw std::out_of_range("resize() - requested size too large");
  }
  if (new_cap <= capacity_) {
    return;
  }
  allocate_new(new_cap);
}

template <typename T>
typename vector<T>::size_type vector<T>::capacity() const {
  return capacity_;
}

template <typename T>
void vector<T>::shrink_to_fit() {
  if (size_ == capacity_) {
    return;
  }

  if (size_ == 0) {
    deallocate();
    return;
  }

  allocate_new(size_);
}

template <typename T>
typename vector<T>::reference vector<T>::at(size_type pos) {
  if (pos >= size()) {
    throw std::out_of_range("Vector index out of range");
  }
  return data_[pos];
}

<<<<<<< HEAD
// Операторы доступа
=======
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
template <typename T>
typename vector<T>::const_reference vector<T>::at(size_type pos) const {
  if (pos >= size_) {
    throw std::out_of_range("Vector index out of range");
  }
  return data_[pos];
}

template <typename T>
typename vector<T>::reference vector<T>::operator[](size_type pos) {
  return data_[pos];
}

template <typename T>
typename vector<T>::const_reference vector<T>::operator[](size_type pos) const {
  return data_[pos];
}
<<<<<<< HEAD
// Передача ресурсов
=======

>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
template <typename T>
void vector<T>::move_data(vector<T>&& other) noexcept {
  deallocate();
  data_ = other.data_;
  size_ = other.size_;
  capacity_ = other.capacity_;
  other.data_ = nullptr;
  other.size_ = 0;
  other.capacity_ = 0;
}

}  // namespace s21