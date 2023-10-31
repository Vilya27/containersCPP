#ifndef SRS_HEADERS_S21_STACK_H_
#define SRS_HEADERS_S21_STACK_H_

#include <cstddef>
#include <initializer_list>
<<<<<<< HEAD
#include <list>
=======

#include "s21_list.h"
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4

namespace s21 {

template <typename T>
class stack {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  stack() {}
  explicit stack(std::initializer_list<value_type> const &items)
<<<<<<< HEAD
      : data(items) {}
  stack(const stack &other) : data(other.data) {}
  stack(stack &&other) noexcept : data(std::move(other.data)) {}
=======
      : data_(items) {}
  stack(const stack &other) : data_(other.data_) {}
  stack(stack &&other) noexcept : data_(std::move(other.data_)) {}
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
  ~stack() {}

  // Операторы
  stack &operator=(const stack &other);
  stack &operator=(stack &&other) noexcept;

  // Методы
  const_reference top() const;
  bool empty() const;
  size_type size() const;
  void push(const_reference value);
  void pop();
  void swap(stack &other);

 private:
<<<<<<< HEAD
  std::list<T> data;
=======
  list<T> data_;
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
};

}  // namespace s21

<<<<<<< HEAD
#include "../sources/s21_stack/s21_stack_constructors.tpp"
=======
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
#include "../sources/s21_stack/s21_stack_methods.tpp"
#include "../sources/s21_stack/s21_stack_operators.tpp"
#endif  // SRS_HEADERS_S21_STACK_H_