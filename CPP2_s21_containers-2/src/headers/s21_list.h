#ifndef SRC_HEADERS_S21_LIST_H_
#define SRC_HEADERS_S21_LIST_H_

#include <initializer_list>
#include <iostream>
#include <limits>

namespace s21 {

template <typename T>
class list {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = std::size_t;

 private:
  struct Node {
    value_type data;
    Node *prev, *next;

    Node(const_reference value) : data(value), prev(nullptr), next(nullptr) {}
  };

  Node *head, *tail, *tail2;
  size_type count;

 public:
  template <typename value_type>
  class ListIterator {
   public:
    ListIterator() : ptr_(nullptr) {}
    ListIterator(Node* ptr) : ptr_(ptr){};

    reference operator*() {
      if (!this->ptr_) {
        throw std::invalid_argument("Value is nullptr");
      }
      return this->ptr_->data;
    }

    ListIterator operator++(int) {
      ptr_ = ptr_->next;
      return *this;
    }

    ListIterator operator--(int) {
      ptr_ = ptr_->prev;
      return *this;
    }

    ListIterator& operator++() {
      ptr_ = ptr_->next;
      return *this;
    }

    ListIterator& operator--() {
      ptr_ = ptr_->prev;
      return *this;
    }

    ListIterator operator+(const size_type value) {
      Node* tmp = ptr_;
      for (size_type i = 0; i < value; i++) {
        tmp = tmp->next;
      }

      ListIterator res(tmp);
      return res;
    }

    ListIterator operator-(const size_type value) {
      Node* tmp = ptr_;
      for (size_type i = 0; i < value; i++) {
        tmp = tmp->prev;
      }
      ListIterator res(tmp);
      return res;
    }

    bool operator==(ListIterator other) const {
      return this->ptr_ == other.ptr_;
    }
    bool operator!=(ListIterator other) const {
      return this->ptr_ != other.ptr_;
    }

   private:
    Node* ptr_ = nullptr;
    friend class list<T>;
  };

  template <typename value_type>
  class ListConstIterator : public ListIterator<T> {
   public:
    ListConstIterator(ListIterator<T> other) : ListIterator<T>(other) {}
    const T& operator*() { return ListIterator<T>::operator*(); }
  };

  using iterator = ListIterator<T>;
  using const_iterator = ListConstIterator<T>;

  const_iterator find(const_reference value) const;

  list();
  list(size_type n);
  list(std::initializer_list<value_type> const& items);
  list(const list& l);
  list(list&& l);
  ~list();
  list& operator=(list&& l);
  list& operator=(const list& other);

  const_reference front() const;
  const_reference back() const;

  iterator begin();
  iterator end();
  // перегрузка на константу
  const_iterator begin() const noexcept;
  const_iterator end() const noexcept;

  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;

  bool empty() const;
  size_type size() const;
  size_type max_size() const;

  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list& other);
  void merge(list& other);
  void splice(const_iterator pos, list& other);
  void reverse();
  void unique();
  void sort();
  void print();

 private:
  void next_connect();
};
}  // namespace s21
#include "../sources/s21_list/s21_list_constructors.tpp"
#include "../sources/s21_list/s21_list_methods.tpp"
#include "../sources/s21_list/s21_list_operators.tpp"
#endif  // SRC_HEADERS_S21_LIST_H_
