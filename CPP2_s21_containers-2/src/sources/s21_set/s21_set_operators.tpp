
namespace s21 {
template <typename Key>
set<Key>& set<Key>::operator=(const set& other) {
  if (this != &other) {
    set tmp{other};
    std::swap(data_, tmp.data_);
  }
  return *this;
}

template <typename Key>
set<Key>& set<Key>::operator=(set&& other) noexcept {
  if (this != &other) {
<<<<<<< HEAD
=======
    // мув - это конвертер в rvalue-ссылку
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
    data_ = std::move(other.data_);
  }
  return *this;
}

}  // namespace s21
