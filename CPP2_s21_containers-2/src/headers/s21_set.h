#ifndef SRS_HEADERS_S21_SET_H_
#define SRS_HEADERS_S21_SET_H_

#include <initializer_list>
<<<<<<< HEAD
#include <list>
=======

#include "s21_list.h"
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4

namespace s21 {

template <typename Key>
class set {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type&;
  using const_reference = const value_type&;
<<<<<<< HEAD
  using iterator = typename std::list<Key>::iterator;
  using const_iterator = typename std::list<Key>::const_iterator;
  using size_type = std::size_t;
=======
  using iterator = typename list<Key>::iterator;
  using const_iterator = typename list<Key>::const_iterator;
  using size_type = size_t;
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4

  // Конструкторы
  set();
  set(std::initializer_list<value_type> const& items);
  set(const set& other);
  set(set&& other) noexcept;
  ~set();

  // Операторы
  set& operator=(const set& other);
  set& operator=(set&& other) noexcept;

  // Итераторы
  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;

<<<<<<< HEAD
  // Capacity
  bool empty() const;
  size_type size() const;
  size_type max_size() const;

  // Доступ
=======
  // Методы
  bool empty() const;
  size_type size() const;
  size_type max_size() const;
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
  void clear();
  std::pair<iterator, bool> insert(const value_type& value);
  void erase(iterator pos);
  void swap(set& other);
  void merge(set& other);
<<<<<<< HEAD
  iterator find(const Key& key);
  bool contains(const Key& key) const;

 private:
  std::list<Key> data_;
=======
  const_iterator find(const Key& key) const;
  bool contains(const Key& key) const;

 private:
  list<Key> data_;
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
};

}  // namespace s21

#include "../sources/s21_set/s21_set_constructors.tpp"
#include "../sources/s21_set/s21_set_methods.tpp"
#include "../sources/s21_set/s21_set_operators.tpp"
#endif