#ifndef SRS_HEADERS_S21_VECTOR_H_
#define SRS_HEADERS_S21_VECTOR_H_
#include <cstddef>
#include <initializer_list>

namespace s21 {
template <typename T>
class vector {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = T*;
  using const_iterator = const T*;
  using size_type = std::size_t;

  // void DBG_Printer(const char* dbg_message) {
  //   std::cout << dbg_message << "\n";
  //   for (size_t i = 0; i < size_; i++) {
  //     std::cout << data_[i] << " ";
  //   }
  //   std::cout << "\n";
  // }

  class VectorIterator {
   public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    VectorIterator() noexcept;
    explicit VectorIterator(pointer ptr) noexcept;

    reference operator*() const noexcept;
    pointer operator->() const noexcept;
    VectorIterator& operator++() noexcept;
    VectorIterator operator++(int) noexcept;
    VectorIterator& operator--() noexcept;
    VectorIterator operator--(int) noexcept;
    VectorIterator operator+(difference_type n) const noexcept;
    VectorIterator operator-(difference_type n) const noexcept;
    VectorIterator& operator+=(difference_type n) noexcept;
    VectorIterator& operator-=(difference_type n) noexcept;
    difference_type operator-(const VectorIterator& other) const noexcept;
    bool operator==(const VectorIterator& other) const noexcept;
    bool operator!=(const VectorIterator& other) const noexcept;
    bool operator<(const VectorIterator& other) const noexcept;
    bool operator>(const VectorIterator& other) const noexcept;
    bool operator<=(const VectorIterator& other) const noexcept;
    bool operator>=(const VectorIterator& other) const noexcept;

   private:
    pointer ptr_;
  };

  class ConstVectorIterator {
   public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = const T;
    using difference_type = std::ptrdiff_t;
    using pointer = const T*;
    using reference = const T&;

    ConstVectorIterator() noexcept;
    explicit ConstVectorIterator(pointer ptr) noexcept;
    ConstVectorIterator(const VectorIterator& other) noexcept;

    reference operator*() const noexcept;
    pointer operator->() const noexcept;
    ConstVectorIterator& operator++() noexcept;
    ConstVectorIterator operator++(int) noexcept;
    ConstVectorIterator& operator--() noexcept;
    ConstVectorIterator operator--(int) noexcept;
    ConstVectorIterator operator+(difference_type n) const noexcept;
    ConstVectorIterator operator-(difference_type n) const noexcept;
    ConstVectorIterator& operator+=(difference_type n) noexcept;
    ConstVectorIterator& operator-=(difference_type n) noexcept;
    difference_type operator-(const ConstVectorIterator& other) const noexcept;
    bool operator==(const ConstVectorIterator& other) const noexcept;
    bool operator!=(const ConstVectorIterator& other) const noexcept;
    bool operator<(const ConstVectorIterator& other) const noexcept;
    bool operator>(const ConstVectorIterator& other) const noexcept;
    bool operator<=(const ConstVectorIterator& other) const noexcept;
    bool operator>=(const ConstVectorIterator& other) const noexcept;

   private:
    pointer ptr_;
  };

  // Конструкторы и деструкторы
  vector() noexcept;
  explicit vector(size_type n);
  vector(std::initializer_list<T> const& items);
  vector(const vector& v);
  vector(vector&& v) noexcept;
  ~vector();
  vector& operator=(const vector& other);
  vector& operator=(vector&& other) noexcept;

  // Доступ
  reference at(size_type pos);
  const_reference at(size_type pos) const;
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;
  reference front();
  const_reference front() const;
  reference back();
  const_reference back() const;
  T* data();

  // Итераторы

  iterator begin();
  const_iterator begin() const;
  const_iterator cbegin() const;
  iterator end();
  const_iterator end() const;
  const_iterator cend() const;

  // Размеры
  bool empty() const;
  size_type size() const;
  size_type max_size() const;
  void reserve(size_type new_cap);
  size_type capacity() const;
  void shrink_to_fit();

  // Манипуляция данными
  void clear() noexcept;
  iterator insert(const_iterator pos, const T& value);
  iterator erase(const_iterator pos);
  void push_back(const T& value);
  void push_back(T&& value);
  void pop_back();
  void resize(size_type count);
  void resize(size_type count, const T& value);
  void swap(vector& other) noexcept;

 private:
  T* data_;
  size_type size_;
  size_type capacity_;

  void allocate_new(size_type new_capacity);
  void deallocate() noexcept;
  void move_data(vector<T>&& other) noexcept;
};

}  // namespace s21

#include "../sources/s21_vector/s21_vector_constructors.tpp"
#include "../sources/s21_vector/s21_vector_iterator.tpp"
#include "../sources/s21_vector/s21_vector_methods.tpp"
#include "../sources/s21_vector/s21_vector_operators.tpp"
#endif  // SRS_HEADERS_S21_VECTOR_H_