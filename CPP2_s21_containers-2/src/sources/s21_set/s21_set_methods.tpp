
namespace s21 {

template <typename Key>
<<<<<<< HEAD
=======
typename set<Key>::const_iterator set<Key>::find(const Key& key) const {
  for (auto it = data_.begin(); it != data_.end(); ++it) {
    if (*it == key) {
      return it;
    }
  }
  return end();
}

template <typename Key>
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
typename set<Key>::iterator set<Key>::begin() {
  return data_.begin();
}

template <typename Key>
typename set<Key>::const_iterator set<Key>::begin() const {
  return data_.cbegin();
}

template <typename Key>
typename set<Key>::iterator set<Key>::end() {
  return data_.end();
}

template <typename Key>
typename set<Key>::const_iterator set<Key>::end() const {
  return data_.cend();
}

template <typename Key>
bool set<Key>::empty() const {
  return data_.empty();
}

template <typename Key>
typename set<Key>::size_type set<Key>::size() const {
  return data_.size();
}

template <typename Key>
typename set<Key>::size_type set<Key>::max_size() const {
  return data_.max_size();
}

template <typename Key>
void set<Key>::clear() {
  data_.clear();
}

template <typename Key>
std::pair<typename set<Key>::iterator, bool> set<Key>::insert(
    const value_type& value) {
  // Поиск элемента в контейнере
<<<<<<< HEAD
  auto it = std::find(data_.begin(), data_.end(), value);
=======
  //  auto it = std::find(data_.begin(), data_.end(), value);
  auto it = data_.find(value);
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
  if (it != data_.end()) {
    return std::make_pair(it, false);
  } else {
    if (data_.size() >= data_.max_size()) {
      throw std::out_of_range("Cannot insert element in full set");
    }
    data_.push_back(value);
    data_.sort();
<<<<<<< HEAD
    return std::make_pair(std::find(data_.begin(), data_.end(), value), true);
=======
    return std::make_pair(data_.find(value), true);
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
  }
}

template <typename Key>
void set<Key>::erase(iterator pos) {
  if (empty()) {
    throw std::out_of_range("Cannot erase element from empty set");
  }
  data_.erase(pos);
}

template <typename Key>
void set<Key>::swap(set& other) {
  data_.swap(other.data_);
}
#include <stdexcept>

template <typename Key>
void set<Key>::merge(set& other) {
  if (&other == this) return;

  if (size() + other.size() > max_size()) {
    throw std::out_of_range("set::merge: merged set exceeds the maximum size");
  }

<<<<<<< HEAD
  std::list<Key> tmp;
  auto it1 = data_.begin();
  auto it2 = other.data_.begin();
  while (it1 != data_.end() && it2 != other.data_.end()) {
    if (*it1 < *it2) {
      tmp.push_back(*it1);
      ++it1;
    } else if (*it2 < *it1) {
      tmp.push_back(*it2);
      ++it2;
    } else {  // Ключи равны
      tmp.push_back(*it1);
      ++it1;
      ++it2;
    }
  }
  // Добавляем оставшиеся элементы из первого контейнера
  while (it1 != data_.end()) {
    tmp.push_back(*it1);
    ++it1;
  }
  // Добавляем оставшиеся элементы из второго контейнера
  while (it2 != other.data_.end()) {
    tmp.push_back(*it2);
    ++it2;
  }

  // Заменяем содержимое текущего контейнера на объединение
  data_ = std::move(tmp);
  data_.unique();
}

template <typename Key>
typename set<Key>::iterator set<Key>::find(const Key& key) {
  return std::lower_bound(data_.begin(), data_.end(), key);
=======
  data_.merge(other.data_);
  data_.sort();
  data_.unique();
  other.clear();
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
}

template <typename Key>
bool set<Key>::contains(const Key& key) const {
<<<<<<< HEAD
  auto it = std::find(data_.begin(), data_.end(), key);
  return (it != data_.end());
=======
  return find(key) != end();
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
}

}  // namespace s21
