namespace s21 {
template <typename Key>
set<Key>::set() {}

template <typename Key>
set<Key>::set(std::initializer_list<value_type> const& items) : data_{items} {
  data_.sort();
  data_.unique();
}

template <typename Key>
set<Key>::set(const set& other) : data_{other.data_} {}

template <typename Key>
set<Key>::set(set&& other) noexcept : data_{std::move(other.data_)} {}

template <typename Key>
set<Key>::~set() {}
}  // namespace s21