
namespace s21 {

template <typename value_type>
typename list<value_type>::list& list<value_type>::operator=(
    const list& other) {
  if (this != &other) {
    clear();
    for (const auto& val : other) {
      push_back(val);
    }
  }
  return *this;
}

template <typename value_type>
typename list<value_type>::list& list<value_type>::operator=(list&& l) {
  if (this != &l) {
    clear();
    swap(l);
  }
  return *this;
}

}  // namespace s21
