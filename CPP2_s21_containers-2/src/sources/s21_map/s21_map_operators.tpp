namespace s21 {

template <typename K, typename T>
map<K, T>& map<K, T>::operator=(const map& other) {
  if (this != &other) {
<<<<<<< HEAD
    s21_map_ = other.s21_map_;
    actual_size_ = other.actual_size_;
=======
    clear();
    root_ = copy_tree(other.root_, nullptr);
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
  }
  return *this;
}

template <typename K, typename T>
map<K, T>& map<K, T>::operator=(map&& other) noexcept {
  if (this != &other) {
<<<<<<< HEAD
    s21_map_ = std::move(other.s21_map_);
    actual_size_ = other.actual_size_;
    other.actual_size_ = 0;
=======
    clear();
    root_ = other.root_;
    other.root_ = nullptr;
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
  }
  return *this;
}

template <typename K, typename T>
<<<<<<< HEAD
typename s21::map<K, T>::mapped_type& s21::map<K, T>::operator[](
    const key_type& key) {
  for (auto& item : s21_map_) {
    if (item.first == key) {
      return item.second;
    }
  }
  // Если ключ не найден, создаем новую пару и добавляем ее в список, с нулевым
  // значением
  auto new_pair = std::make_pair(key, mapped_type{});
  s21_map_.push_back(new_pair);
  auto& back_element = s21_map_.back();
  auto& value = back_element.second;
  ++actual_size_;

  return value;
}
}  // namespace s21
=======
typename map<K, T>::mapped_type& map<K, T>::operator[](const key_type& key) {
  Node* node = find_node(key);
  if (!node) {
    node = insert_node(key, mapped_type());
  }
  return node->data;
}
}  // namespace s21
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
