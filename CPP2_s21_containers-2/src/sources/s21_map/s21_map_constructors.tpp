<<<<<<< HEAD
namespace s21 {

template <typename K, typename T>
map<K, T>::map() : actual_size_(0) {}

template <typename K, typename T>
map<K, T>::map(const map& other)
    : s21_map_(other.s21_map_), actual_size_(other.actual_size_) {}

template <typename K, typename T>
map<K, T>::map(std::initializer_list<value_type> ilist)
    : s21_map_(ilist), actual_size_(0) {
  s21_map_.sort();

  auto it = s21_map_.begin();
  while (it != s21_map_.end()) {
    if (it != s21_map_.begin() && it->first == std::prev(it)->first) {
      it = s21_map_.erase(it);
    } else {
      ++it;
    }
  }

  actual_size_ = std::distance(s21_map_.begin(), s21_map_.end());
}

template <typename K, typename T>
map<K, T>::map(map&& other) noexcept
    : s21_map_(std::move(other.s21_map_)), actual_size_(other.actual_size_) {
  other.actual_size_ = 0;
}
=======
// s21_map_constructors.tpp
namespace s21 {

template <typename K, typename T>
map<K, T>::map() : root_(nullptr) {}

template <typename K, typename T>
map<K, T>::map(const map& other) : root_(copy_tree(other.root_, nullptr)) {}

template <typename K, typename T>
map<K, T>::map(std::initializer_list<value_type> ilist) : root_(nullptr) {
  for (const auto& item : ilist) {
    insert(item);
  }
}

// инициализируем корень чужим корнем, чужой зануляем
template <typename K, typename T>
map<K, T>::map(map&& other) noexcept
    : root_(std::exchange(other.root_, nullptr)) {}

template <typename K, typename T>
map<K, T>::~map() {
  destroy_tree(root_);
}

>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
}  // namespace s21
