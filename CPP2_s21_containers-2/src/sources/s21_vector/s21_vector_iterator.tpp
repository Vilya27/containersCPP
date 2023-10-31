namespace s21 {

template <typename T>
typename vector<T>::VectorIterator::reference
vector<T>::VectorIterator::operator*() const noexcept {
  return *ptr_;
}

template <typename T>
typename vector<T>::VectorIterator::pointer
vector<T>::VectorIterator::operator->() const noexcept {
  return ptr_;
}

<<<<<<< HEAD
=======
// Префикс
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
template <typename T>
typename vector<T>::VectorIterator&
vector<T>::VectorIterator::operator++() noexcept {
  ++ptr_;
  return *this;
}

<<<<<<< HEAD
=======
// Постфикс
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
template <typename T>
typename vector<T>::VectorIterator vector<T>::VectorIterator::operator++(
    int) noexcept {
  VectorIterator it(ptr_);
  ++ptr_;
  return it;
}

template <typename T>
typename vector<T>::VectorIterator&
vector<T>::VectorIterator::operator--() noexcept {
  --ptr_;
  return *this;
}

template <typename T>
typename vector<T>::VectorIterator vector<T>::VectorIterator::operator--(
    int) noexcept {
  VectorIterator it(ptr_);
  --ptr_;
  return it;
}

template <typename T>
typename vector<T>::VectorIterator vector<T>::VectorIterator::operator+(
    difference_type n) const noexcept {
  return VectorIterator(ptr_ + n);
}

template <typename T>
typename vector<T>::VectorIterator vector<T>::VectorIterator::operator-(
    difference_type n) const noexcept {
  return VectorIterator(ptr_ - n);
}

template <typename T>
typename vector<T>::VectorIterator& vector<T>::VectorIterator::operator+=(
    difference_type n) noexcept {
  ptr_ += n;
  return *this;
}

template <typename T>
typename vector<T>::VectorIterator& vector<T>::VectorIterator::operator-=(
    difference_type n) noexcept {
  ptr_ -= n;
  return *this;
}

template <typename T>
typename vector<T>::VectorIterator::difference_type
vector<T>::VectorIterator::operator-(
    const VectorIterator& other) const noexcept {
  return ptr_ - other.ptr_;
}

template <typename T>
bool vector<T>::VectorIterator::operator==(
    const VectorIterator& other) const noexcept {
  return ptr_ == other.ptr_;
}

template <typename T>
bool vector<T>::VectorIterator::operator!=(
    const VectorIterator& other) const noexcept {
  return !(*this == other);
}

template <typename T>
bool vector<T>::VectorIterator::operator<(
    const VectorIterator& other) const noexcept {
  return ptr_ < other.ptr_;
}

template <typename T>
bool vector<T>::VectorIterator::operator>(
    const VectorIterator& other) const noexcept {
  return ptr_ > other.ptr_;
}

template <typename T>
bool vector<T>::VectorIterator::operator<=(
    const VectorIterator& other) const noexcept {
  return ptr_ <= other.ptr_;
}

template <typename T>
bool vector<T>::VectorIterator::operator>=(
    const VectorIterator& other) const noexcept {
  return ptr_ >= other.ptr_;
}
<<<<<<< HEAD
// конст
=======
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4

template <typename T>
typename vector<T>::ConstVectorIterator::reference
vector<T>::ConstVectorIterator::operator*() const noexcept {
  return *ptr_;
}

template <typename T>
typename vector<T>::ConstVectorIterator::pointer
vector<T>::ConstVectorIterator::operator->() const noexcept {
  return ptr_;
}

template <typename T>
typename vector<T>::ConstVectorIterator&
vector<T>::ConstVectorIterator::operator++() noexcept {
  ++ptr_;
  return *this;
}

template <typename T>
typename vector<T>::ConstVectorIterator
vector<T>::ConstVectorIterator::operator++(int) noexcept {
  ConstVectorIterator it(ptr_);
  ++ptr_;
  return it;
}

template <typename T>
typename vector<T>::ConstVectorIterator&
vector<T>::ConstVectorIterator::operator--() noexcept {
  --ptr_;
  return *this;
}

template <typename T>
typename vector<T>::ConstVectorIterator
vector<T>::ConstVectorIterator::operator--(int) noexcept {
  ConstVectorIterator it(ptr_);
  --ptr_;
  return it;
}

template <typename T>
typename vector<T>::ConstVectorIterator
vector<T>::ConstVectorIterator::operator+(difference_type n) const noexcept {
  return ConstVectorIterator(ptr_ + n);
}

template <typename T>
typename vector<T>::ConstVectorIterator
vector<T>::ConstVectorIterator::operator-(difference_type n) const noexcept {
  return ConstVectorIterator(ptr_ - n);
}

template <typename T>
typename vector<T>::ConstVectorIterator&
vector<T>::ConstVectorIterator::operator+=(difference_type n) noexcept {
  ptr_ += n;
  return *this;
}

template <typename T>
typename vector<T>::ConstVectorIterator&
vector<T>::ConstVectorIterator::operator-=(difference_type n) noexcept {
  ptr_ -= n;
  return *this;
}

template <typename T>
typename vector<T>::ConstVectorIterator::difference_type
vector<T>::ConstVectorIterator::operator-(
    const ConstVectorIterator& other) const noexcept {
  return ptr_ - other.ptr_;
}

template <typename T>
bool vector<T>::ConstVectorIterator::operator==(
    const ConstVectorIterator& other) const noexcept {
  return ptr_ == other.ptr_;
}

template <typename T>
bool vector<T>::ConstVectorIterator::operator!=(
    const ConstVectorIterator& other) const noexcept {
  return !(*this == other);
}

template <typename T>
bool vector<T>::ConstVectorIterator::operator<(
    const ConstVectorIterator& other) const noexcept {
  return ptr_ < other.ptr_;
}

template <typename T>
bool vector<T>::ConstVectorIterator::operator>(
    const ConstVectorIterator& other) const noexcept {
  return ptr_ > other.ptr_;
}

template <typename T>
bool vector<T>::ConstVectorIterator::operator<=(
    const ConstVectorIterator& other) const noexcept {
  return ptr_ <= other.ptr_;
}

template <typename T>
bool vector<T>::ConstVectorIterator::operator>=(
    const ConstVectorIterator& other) const noexcept {
  return ptr_ >= other.ptr_;
}
}  // namespace s21
