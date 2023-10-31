namespace s21 {
template <typename value_type>
list<value_type>::list()
    : head(nullptr), tail(nullptr), tail2(nullptr), count(0) {}

template <typename value_type>
list<value_type>::list(size_type n)
    : head(nullptr), tail(nullptr), tail2(nullptr), count(0) {
  if (n >= max_size()) {
    throw std::out_of_range("Broke the limit");
  }
  tail2 = new Node(value_type{});
  for (size_type i = 0; i < n; ++i) {
    push_back(value_type());
  }
  next_connect();
}

template <typename value_type>
list<value_type>::list(std::initializer_list<value_type> const& items)
    : head(nullptr), tail(nullptr), tail2(nullptr), count(0) {
  tail2 = new Node(value_type{});
  for (const auto& item : items) {
    push_back(item);
    next_connect();
  }
}

template <typename value_type>
list<value_type>::list(const list& l)
    : head(nullptr), tail(nullptr), tail2(nullptr), count(0) {
  tail2 = new Node(value_type{});

  Node* current = l.head;
  for (size_type i = 0; i != l.count; i++) {
    push_back(current->data);
    current = current->next;
  }
}

template <typename value_type>
list<value_type>::list(list&& l)
    : head(nullptr), tail(nullptr), tail2(nullptr), count(0) {
  swap(l);
}

template <typename value_type>
list<value_type>::~list() {
  clear();
  delete tail2;
}
}  // namespace s21