#ifndef SRS_HEADERS_S21_QUEUE_H_
#define SRS_HEADERS_S21_QUEUE_H_

#include <initializer_list>
#include <list>

<<<<<<< HEAD
=======
#include "s21_list.h"

>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
namespace s21 {

template <typename T>
class queue {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = std::size_t;

<<<<<<< HEAD
  // void DBG_Printer(const char* dbg_message) {
  //   std::cout << dbg_message << "\n";
  //   for (const auto& item : data_) {
  //     std::cout << item << " ";
  //   }
  //   std::cout << "\n";
  // }

  queue() = default;
  explicit queue(const std::initializer_list<value_type>& items)
      : data_{items} {}
=======
  queue() = default;
  queue(const std::initializer_list<value_type>& items) : data_{items} {}
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
  queue(const queue& q) = default;
  queue(queue&& q) noexcept = default;
  ~queue() noexcept = default;

  queue& operator=(queue&& other) noexcept = default;

  const_reference front() const;
  const_reference back() const;
  bool empty() const;
  size_type size() const;

  void push(const_reference value);
  void pop();
  void swap(queue& other);

 private:
  std::list<T> data_;
};

}  // namespace s21
#include "../sources/s21_queue/s21_queue_methods.tpp"
<<<<<<< HEAD
=======
#include "../sources/s21_queue/s21_queue_operators.tpp"
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
#endif  // SRS_HEADERS_S21_QUEUE_H_