namespace s21 {

template <typename K, typename T>
<<<<<<< HEAD
void map<K, T>::merge(map& other) {
  if (this->s21_map_ != other.s21_map_) {
    if (this->s21_map_.size() + other.s21_map_.size() > max_size()) {
      throw std::out_of_range("Map size exceeds maximum size");
    }
    this->s21_map_.merge(other.s21_map_);
  }
  s21_map_.unique();
  actual_size_ = s21_map_.size();
}

// Метод поиска узла списка по ключу
template <typename K, typename T>
typename map<K, T>::iterator map<K, T>::find(const K& key) {
  for (auto it = s21_map_.begin(); it != s21_map_.end(); ++it) {
    if (it->first == key) {
      return it;
    }
  }
  return s21_map_.end();
}

template <typename K, typename T>
typename map<K, T>::const_iterator map<K, T>::find(const K& key) const {
  for (auto it = s21_map_.cbegin(); it != s21_map_.cend(); ++it) {
    if (it->first == key) {
      return it;
    }
  }
  return s21_map_.cend();
}

template <typename K, typename T>
std::pair<typename s21::map<K, T>::iterator, bool> s21::map<K, T>::insert(
    const value_type& value) {
  if (s21_map_.size() + 1 > max_size()) {
    throw std::out_of_range("Map size exceeds maximum size");
  }
  const K& key = value.first;
  for (auto it = s21_map_.begin(); it != s21_map_.end(); ++it) {
    // Если ключ найден, отдаем итератор и флаг
    if (it->first == key) {
      //  it->second = value.second;
      return std::make_pair(iterator(it), false);
    } else if (it->first > key) {
      // Если ключ под итератором больше, чем ключ, значит пора вставлять,т.к.
      // список отсортирован.
      s21_map_.insert(it, value);
      return std::make_pair(iterator(--it), true);
    }
  }
  // если дошли до этой точки, значит, элемент последний
  s21_map_.push_back(value);
  auto last_it = --s21_map_.end();
  return std::make_pair(iterator(last_it), true);
}

template <typename K, typename T>
std::pair<typename s21::map<K, T>::iterator, bool> s21::map<K, T>::insert(
    const K& key, const T& obj) {
  value_type value(key, obj);  // создаем пару из ключа и объекта
  return insert(value);  // используем уже реализованный метод insert с парой
}

template <typename K, typename T>
std::pair<typename s21::map<K, T>::iterator, bool>
s21::map<K, T>::insert_or_assign(const K& key, const T& obj) {
  std::pair<typename s21::map<K, T>::iterator, bool> r{nullptr, false};
  auto it = find(key);
  if (it != s21_map_.end()) {
    it->second = obj;
    r.first = it;
  } else {
    if (s21_map_.size() + 1 > max_size()) {
      throw std::out_of_range("Map size exceeds maximum size");
    }
    auto t = std::make_pair(key, obj);
    r = this->insert(t);
  }
  return r;
}

template <typename K, typename T>
void map<K, T>::erase(iterator pos) {
  if (s21_map_.empty()) {
    throw std::out_of_range("Cannot erase element from empty map");
  }
  s21_map_.erase(pos);
=======
void map<K, T>::DBG_MapPrinter(const char* dbg_message) const {
  std::cout << dbg_message << std::endl;
  for (auto it = begin(); it != end(); ++it) {
    const auto& node = *it;
    std::cout << "[" << node.first << ": " << node.second << "]" << std::endl;
  }
}

template <typename K, typename T>
std::pair<typename map<K, T>::iterator, bool> map<K, T>::insert_or_assign(
    const K& key, const T& obj) {
  Node* node = find_node(key);
  if (node) {
    node->data = obj;
    node->key_data_pair.second = obj;
    return std::make_pair(iterator(node), false);
  } else {
    node = insert_node(key, obj);
    return std::make_pair(iterator(node), true);
  }
}

template <typename K, typename T>
typename map<K, T>::Node* map<K, T>::create_node(const key_type& key,
                                                 const mapped_type& data) {
  return new Node(key, data);
}

template <typename K, typename T>
void map<K, T>::destroy_tree(Node* node) {
  if (node) {
    destroy_tree(node->left);
    destroy_tree(node->right);
    delete node;
  }
}

template <typename K, typename T>
typename map<K, T>::Node* map<K, T>::copy_tree(const Node* other_node,
                                               Node* parent) {
  if (!other_node) {
    return nullptr;
  }

  Node* node = new Node(other_node->key, other_node->data);
  node->parent = parent;
  node->left = copy_tree(other_node->left, node);
  node->right = copy_tree(other_node->right, node);

  return node;
}

template <typename K, typename T>
typename s21::map<K, T>::Node* s21::map<K, T>::insert_node(
    const key_type& key, const mapped_type& data) {
  Node** node = &root_;
  Node* parent = nullptr;
  while (*node) {
    parent = *node;
    if (key == parent->key) {
      // Ключ уже есть в дереве, заменяем значение
      parent->data = data;
      parent->key_data_pair.second = data;
      return parent;
    } else if (key < parent->key) {
      node = &(parent->left);
    } else {
      node = &(parent->right);
    }
  }

  auto new_node = create_node(key, data);
  new_node->parent = parent;
  *node = new_node;
  return new_node;
}

template <typename K, typename T>
std::pair<typename map<K, T>::iterator, bool> map<K, T>::insert(
    const value_type& value) {
  // Ищем узел с таким же ключом, если находим - возвращаем его и флаг false
  Node* found_node = find_node(value.first);
  if (found_node != nullptr) {
    return std::make_pair(iterator(found_node), false);
  }

  // Создаем новый узел и добавляем его в дерево
  Node* new_node = insert_node(value.first, value.second);

  // Возвращаем итератор на добавленный элемент и флаг true
  return std::make_pair(iterator(new_node), true);
}

template <typename K, typename T>
std::pair<typename map<K, T>::iterator, bool> map<K, T>::insert(const K& key,
                                                                const T& obj) {
  // Ищем узел с таким же ключом, если находим - возвращаем его и флаг false
  Node* found_node = find_node(key);
  if (found_node != nullptr) {
    return std::make_pair(iterator(found_node), false);
  }

  // Создаем новый узел и добавляем его в дерево
  Node* new_node = insert_node(key, obj);

  // Возвращаем итератор на добавленный элемент и флаг true
  return std::make_pair(iterator(new_node), true);
}

template <typename K, typename T>
typename s21::map<K, T>::Node* s21::map<K, T>::find_node(
    const key_type& key) const {
  Node* current = root_;
  while (current && current->key != key) {
    if (key < current->key)
      current = current->left;
    else
      current = current->right;
  }
  return current;
}

template <typename K, typename T>
typename s21::map<K, T>::Node* s21::map<K, T>::find_min_node(Node* node) const {
  Node* current = node;
  while (current && current->left) {
    current = current->left;
  }
  return current;
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
}

template <typename K, typename T>
typename map<K, T>::iterator map<K, T>::begin() {
<<<<<<< HEAD
  return s21_map_.begin();
=======
  if (root_ == nullptr) return iterator(nullptr);
  Node* min_node = find_min_node(root_);
  return iterator(min_node);
}

template <typename K, typename T>
typename map<K, T>::const_iterator map<K, T>::begin() const {
  if (root_ == nullptr) return const_iterator(nullptr);
  const Node* min_node = find_min_node(root_);
  return const_iterator(min_node);
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
}

template <typename K, typename T>
typename map<K, T>::iterator map<K, T>::end() {
<<<<<<< HEAD
  return s21_map_.end();
=======
  return iterator(nullptr);
}

template <typename K, typename T>
typename map<K, T>::const_iterator map<K, T>::end() const {
  return const_iterator(nullptr);
}

template <typename K, typename T>
void map<K, T>::merge(map& other) {
  if (this == &other) return;
  for (auto& element : other) {
    insert_or_assign(element.first, element.second);
  }
  other.clear();
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
}

template <typename K, typename T>
void map<K, T>::swap(map& other) {
<<<<<<< HEAD
  map<K, T> t = std::move(other);
  other = std::move(*this);
  *this = std::move(t);
=======
  std::swap(root_, other.root_);
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
}

template <typename K, typename T>
typename map<K, T>::size_type map<K, T>::max_size() const {
<<<<<<< HEAD
  return s21_map_.max_size();
}

template <typename K, typename T>
void map<K, T>::clear() {
  s21_map_.clear();
  actual_size_ = 0;
=======
  return std::numeric_limits<size_type>::max() / sizeof(Node);
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
}

template <typename K, typename T>
bool map<K, T>::empty() const {
<<<<<<< HEAD
  return s21_map_.empty();
=======
  return size() == 0;
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
}

template <typename K, typename T>
T& map<K, T>::at(const K& key) {
<<<<<<< HEAD
  auto it = s21_map_.begin();
  while (it != s21_map_.end()) {
    if (it->first == key) {
      return it->second;
    }
    ++it;
  }

  throw std::out_of_range("Key not found in map");
}

template <typename K, typename T>
bool map<K, T>::contains(const K& key) {
  bool is_contain = 0;

  auto it = s21_map_.begin();
  while (it != s21_map_.end()) {
    if (it->first == key) {
      is_contain = 1;
    }
    ++it;
  }

  return is_contain;
=======
  Node* node = find_node(key);
  if (node == nullptr) throw std::invalid_argument("key not found");
  return node->data;
}

template <typename K, typename T>
bool map<K, T>::contains(const K& key) const {
  return find_node(key) != nullptr;
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
}

template <typename K, typename T>
typename map<K, T>::size_type map<K, T>::size() const {
<<<<<<< HEAD
  return s21_map_.size();
}

template <typename K, typename T>
void map<K, T>::DBG_MapPrinter(const char* dbg_message) const {
  std::cout << dbg_message << "\n";
  std::cout << "DBG. s21_map_ contains:"
            << "\n";
  for (const auto& item : s21_map_) {
    std::cout << item.first << ", " << item.second << std::endl;
  }
  std::cout << std::endl;
}

}  // namespace s21
=======
  size_type count = 0;
  for (auto it = begin(); it != end(); ++it) {
    ++count;
  }
  return count;
}

template <typename K, typename T>
typename map<K, T>::Node* map<K, T>::erase_node(Node* node) {
  // Сохраняем указатель на родительский узел удаляемого узла.
  Node* parent = node->parent;
  Node* replacement;

  // Если удаляемый узел не имеет потомков, то замена не нужна.
  if (node->left == nullptr && node->right == nullptr) {
    replacement = nullptr;
  } else if (node->left != nullptr && node->right == nullptr) {
    replacement = node->left;  // есть только левый узел
  } else if (node->left == nullptr && node->right != nullptr) {
    replacement = node->right;  // только правый.
  } else {                      // Если есть оба
    // Находим самый левый узел в правом поддереве
    replacement = find_min_node(node->right);
    if (replacement != node->right) {
      replacement->parent->left = replacement->right;
      if (replacement->right != nullptr) {
        // обновляем указатель на нового предка
        replacement->right->parent = replacement->parent;
      }
      replacement->right = node->right;
      node->right->parent = replacement;
    }
    replacement->left = node->left;
    node->left->parent = replacement;
  }

  if (replacement != nullptr) {
    replacement->parent = parent;
  }

  if (parent == nullptr) {
    root_ = replacement;
  } else if (node == parent->left) {
    parent->left = replacement;
  } else {
    parent->right = replacement;
  }

  delete node;
  return replacement;
}

template <typename K, typename T>
void map<K, T>::erase(iterator pos) {
  if (pos == end()) return;
  erase_node(pos.current_);
}

template <typename K, typename T>
typename map<K, T>::iterator map<K, T>::find(const key_type& key) {
  Node* node = find_node(key);
  if (node == nullptr) return iterator(nullptr);
  return iterator(node);
}

template <typename K, typename T>
void map<K, T>::clear() {
  destroy_tree(root_);
  root_ = nullptr;
}

template <typename K, typename T>
typename map<K, T>::const_iterator map<K, T>::find(const K& key) const {
  const Node* node = find_node(key);
  if (node == nullptr) return end();
  return const_iterator(node);
}

}  // namespace s21
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
