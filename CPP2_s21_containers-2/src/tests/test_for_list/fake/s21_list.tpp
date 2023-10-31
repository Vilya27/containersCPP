namespace s21 {

template <typename value_type>
list<value_type>::list(): head(nullptr), tail(nullptr), tail2(nullptr), count(0) {
}

template <typename value_type>
list<value_type>::list(size_type n): head(nullptr), tail(nullptr), tail2(nullptr), count(0) {
  if (n >= max_size()) {
    throw std::out_of_range("Broke the limit");
  }
  tail2 = new Node(count);
  for (size_type i = 0; i < n; ++i) {
    push_back(value_type());
  }
  next_connect();
}

template <typename value_type>
list<value_type>::list(std::initializer_list<value_type> const& items)
    : head(nullptr), tail(nullptr), tail2(nullptr), count(0) {
  tail2 = new Node(count);
  for (const auto& item : items) {
    push_back(item);
    next_connect();
  }
}

template <typename value_type>
list<value_type>::list(const list& l)
    : head(nullptr), tail(nullptr), tail2(nullptr), count(0) {
  tail2 = new Node(count);
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

template <typename value_type>
typename list<value_type>::list& list<value_type>::operator=(list&& l) {
  if (this != &l) {
    clear();
    swap(l);
  }
  return *this;
}




template <typename value_type>
typename list<value_type>::const_reference list<value_type>::front() const {
  if (!head) {
    return tail2->data;
   } else {
    return head->data;
  }
}

template <typename value_type>
typename list<value_type>::const_reference list<value_type>::back() const {
  if (!tail) {
    return tail2->data;
  } else {
    return tail->data;
  }
}




template <typename value_type>
typename list<value_type>::iterator list<value_type>::begin() {
  if (!head) {
    return iterator(tail2);
  } else {
    return iterator(head);
  }
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::end() {
  return iterator(tail2);
}

template <typename value_type>
typename list<value_type>::const_iterator list<value_type>::cbegin() const noexcept{
 if (!head) {
    return const_iterator(tail2);
  } else {
    return const_iterator(head);
  }
}

template <typename value_type>
typename list<value_type>::const_iterator list<value_type>::cend() const noexcept {
  return const_iterator(tail2);
}




template <typename value_type>
bool list<value_type>::empty() {
  return count == 0;
}

template <typename value_type>
typename list<value_type>::size_type list<value_type>::size() {
  return count;
}

template <typename value_type>
typename list<value_type>::size_type list<value_type>::max_size() {
  return (std::numeric_limits<size_type>::max() / sizeof(Node) / 2);
}




template <typename value_type>
void list<value_type>::clear() {
  while (!empty()) {
    pop_back();
  }
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::insert(
    iterator pos, const_reference value) {
  Node* current = pos.ptr_;
  Node* add = new Node(value);
  if (empty()) {
    add->next = tail2;
    add->prev = tail2;
    head = add;
    tail = add;
  } else {
    if (current == head) {
      head = add;
    } else if (current == tail2) {
      tail = add;
    }
    add->next = current;
    add->prev = current->prev;
    current->prev->next = add;
    current->prev = add;
  }
  count++;
  next_connect();
  return iterator(add);
}

template <typename value_type>
void list<value_type>::erase(iterator pos) {
  Node* current = pos.ptr_;
  if (!empty() && current != tail2) {
    if (current == head) {
      if (current->next && current->next != tail2) {
        head = current->next;
      } else {
        head = tail2;
      }
    } else if (current == tail) {
      if (current->prev && current->prev != tail2) {
        tail = current->prev;
      } else {
        tail = tail2;
      }
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    this->count--;
  } else {
    throw std::invalid_argument("Invalid argument");
  }
  next_connect();
}

template <typename value_type>
void list<value_type>::push_back(const_reference value) {
  Node* new_node = new Node(value);
  if (empty()) {
    head = new_node;
    tail = new_node;
  } else {
    new_node->prev = tail;
    tail->next = new_node;
    tail = new_node;
  }
  count++;
  next_connect();
}

template <typename value_type>
void list<value_type>::pop_back() {
  if (empty()) {
    throw std::out_of_range("List is empty");
  }
  Node* last_node = tail;
  if (count == 1) {
    head = nullptr;
    tail = nullptr;
  } else {
    tail = last_node->prev;
    tail->next = nullptr;
  }
  delete last_node;
  count--;
  next_connect();
}

template <typename value_type>
void list<value_type>::push_front(const_reference value) {
  Node* new_node = new Node(value);
  if (empty()) {
    head = new_node;
    tail = new_node;
  } else {
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
  }
  count++;
  next_connect();
}

template <typename value_type>
void list<value_type>::pop_front() {
  if (empty()) {
    throw std::out_of_range("list is empty");
  }
  Node* first_node = head;
  if (count == 1) {
    head = nullptr;
    tail = nullptr;
  } else {
    head = first_node->next;
    head->prev = nullptr;
  }
  delete first_node;
  count--;
  next_connect();
}

template <typename value_type>
void list<value_type>::swap(list& other) {
  std::swap(this->head, other.head);
  std::swap(this->tail, other.tail);
  std::swap(this->count, other.count);
  std::swap(this->tail2, other.tail2);
}

template <typename value_type>
void list<value_type>::merge(list& other) {
  if (!this->empty() && !other.empty()) {
    iterator iter_this = this->begin();
    iterator iter_other = other.begin();
    while (iter_this != this->end()) {
      if (iter_other != other.end()) {
        if (iter_this.ptr_->data >= iter_other.ptr_->data) {
          this->insert(iter_this, iter_other.ptr_->data);
          iter_other++;
        } else {
          iter_this++;
        }
      } else {
        break;
      }
    }
    while (iter_other != other.end()) {
      this->insert(iter_this, iter_other.ptr_->data);
      iter_other++;
    }
  } else if (this->empty() && !other.empty()) {
    Node* current = other.head;
    for (size_type i = 0; i != other.count; i++) {
      push_back(current->data);
      current = current->next;
    }
  }
  other.clear();
}

template <typename value_type>
void list<value_type>::reverse() {
  if (!this->empty()) {
    size_type step = 0;
    for (iterator it = this->begin(); step <= this->size(); ++it) {
      step++;
      std::swap(it.ptr_->prev, it.ptr_->next);
    }
    std::swap(head, tail);
  }
}

template <typename value_type>
void list<value_type>::unique() {
  if (!this->empty()) {
    for (iterator it = this->begin(); it != this->end(); it++) {
      if (it.ptr_->data == it.ptr_->prev->data) {
        iterator del_it = (it - 1);
        this->erase(del_it);
      }
    }
  }
}

template <typename value_type>
void list<value_type>::splice(const_iterator pos, list& other) {
  if (!other.empty()) {
    for (iterator it = other.begin(); it != other.end(); ++it) {
      this->insert(pos, *it);
    }
    other.clear();
  }
}

template <typename value_type>
void list<value_type>::sort() {
 for (iterator i = ++begin(); i != end(); ++i) {
        value_type tmp = *i;
        iterator j = i - 1;
        for (; j.ptr_ != nullptr && *j > tmp; --j) {
            *(j + 1) = *j;
        }
        *(j + 1) = tmp;
    }
}


template <typename value_type>
void list<value_type>::next_connect() {
  if (tail2) {
    tail2->next = head;
    tail2->prev = tail;
    tail2->data = size();
    if (head) {
      head->prev = tail2;
    }
    if (tail) {
      tail->next = tail2;
    }
  }
}


template <typename value_type>
void list<value_type>::print() {
  for ( iterator it = begin(); it != end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";
}

}  // namespace s21