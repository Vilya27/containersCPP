
namespace s21 {

template <typename K, typename T>
typename map<K, T>::iterator::reference map<K, T>::MapIterator::operator*()
    const {
  return current_->key_data_pair;
}

template <typename K, typename T>
typename map<K, T>::iterator::pointer map<K, T>::MapIterator::operator->()
    const {
  return &(operator*());
}

template <typename K, typename T>
typename map<K, T>::iterator& map<K, T>::MapIterator::operator++() {
  if (current_->right) {
    current_ = current_->right;
    while (current_->left) current_ = current_->left;
  } else {
    Node* parent = current_->parent;
    while (parent && current_ == parent->right) {
      current_ = parent;
      parent = parent->parent;
    }
    current_ = parent;
  }
  return *this;
}

template <typename K, typename T>
typename map<K, T>::iterator map<K, T>::MapIterator::operator++(int) {
  MapIterator temp(*this);
  ++(*this);
  return temp;
}

template <typename K, typename T>
typename map<K, T>::iterator map<K, T>::MapIterator::operator++() const {
  MapIterator iter(*this);
  if (iter.current_->right) {
    iter.current_ = iter.current_->right;
    while (iter.current_->left) iter.current_ = iter.current_->left;
  } else {
    Node* parent = iter.current_->parent;
    while (parent && iter.current_ == parent->right) {
      iter.current_ = parent;
      parent = parent->parent;
    }
    iter.current_ = parent;
  }
  return iter;
}

template <typename K, typename T>
const typename map<K, T>::iterator map<K, T>::MapIterator::operator++(
    int) const {
  const MapIterator temp(*this);
  ++temp;
  return temp;
}

template <typename K, typename T>
const typename map<K, T>::iterator& map<K, T>::MapIterator::operator--() const {
  if (current_->left) {
    current_ = current_->left;
    while (current_->right) current_ = current_->right;
  } else {
    Node* const parent = current_->parent;
    while (parent && current_ == parent->left) {
      current_ = parent;
      parent = parent->parent;
    }
    current_ = parent;
  }
  return *this;
}

template <typename K, typename T>
typename map<K, T>::iterator map<K, T>::MapIterator::operator--(int) {
  MapIterator temp(*this);
  --(*this);
  return temp;
}

template <typename K, typename T>
typename map<K, T>::iterator& map<K, T>::MapIterator::operator--() {
  if (current_->left) {
    current_ = current_->left;
    while (current_->right) current_ = current_->right;
  } else {
    Node* parent = current_->parent;
    while (parent && current_ == parent->left) {
      current_ = parent;
      parent = parent->parent;
    }
    current_ = parent;
  }
  return *this;
}

template <typename K, typename T>
bool map<K, T>::MapIterator::operator==(const MapIterator& other) const {
  return current_ == other.current_;
}

template <typename K, typename T>
bool map<K, T>::MapIterator::operator!=(const MapIterator& other) const {
  return !(*this == other);
}

}  // namespace s21
