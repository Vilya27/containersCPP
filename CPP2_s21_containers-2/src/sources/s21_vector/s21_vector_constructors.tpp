namespace s21 {
template <typename T>
vector<T>::vector() noexcept : data_(nullptr), size_(0), capacity_(0) {}

template <typename T>
vector<T>::vector(size_type n)
    : data_(n > 0 ? new T[n]() : nullptr), size_(n), capacity_(n) {}

template <typename T>
vector<T>::vector(std::initializer_list<T> const& items)
    : data_(items.size() > 0 ? new T[items.size()]() : nullptr),
      size_(items.size()),
      capacity_(items.size()) {
  std::copy(items.begin(), items.end(), data_);
}

template <typename T>
vector<T>::vector(const vector& v)
    : data_(v.size_ > 0 ? new T[v.size_] : nullptr),
      size_(v.size_),
      capacity_(v.size_) {
  if (data_) {
    std::uninitialized_copy(v.data_, v.data_ + v.size_, data_);
  }
}

template <typename T>
vector<T>::vector(vector&& v) noexcept
    : data_(nullptr), size_(0), capacity_(0) {
  move_data(std::move(v));
}

template <typename T>
vector<T>::~vector() {
  deallocate();
}

}  // namespace s21