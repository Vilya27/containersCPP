#ifndef SRS_HEADERS_S21_MAP_H_
#define SRS_HEADERS_S21_MAP_H_

#include <initializer_list>
#include <iostream>
<<<<<<< HEAD
#include <list>
#include <utility>

// template <typename X>
// void DBG_printer(const std::string& str, const X& value) {
//   std::cout << str << ": " << value << std::endl;
// }

=======
#include <utility>

>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
namespace s21 {

template <typename K, typename T>
class map {
 public:
  using size_type = std::size_t;
  using key_type = K;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;

<<<<<<< HEAD
  // Итераторы
  using iterator = typename std::list<value_type>::iterator;
  using const_iterator = typename std::list<value_type>::const_iterator;

  // Методы
  iterator begin();
  iterator end();
=======
  class Node {
   public:
    key_type key;
    mapped_type data;
    value_type key_data_pair;

    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
    Node(const key_type& key, const mapped_type& data)
        : key(key), data(data), key_data_pair(std::make_pair(key, data)) {}
  };

  // Итераторы
  class MapIterator {
   public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = s21::map<K, T>::value_type;
    using difference_type = std::ptrdiff_t;
    using pointer = value_type*;
    using reference = value_type&;

    MapIterator(Node* node) : current_(node) {}
    MapIterator(const Node* node) : current_(const_cast<Node*>(node)) {}
    MapIterator(const MapIterator& other) : current_(other.current_) {}
    MapIterator() : current_(nullptr) {}
    MapIterator(std::nullptr_t) : current_(nullptr) {}
    MapIterator& operator++();
    MapIterator operator++(int);
    MapIterator operator++() const;
    const MapIterator operator++(int) const;
    const MapIterator& operator--() const;
    MapIterator operator--(int);
    MapIterator& operator--();
    bool operator==(const MapIterator& other) const;
    bool operator!=(const MapIterator& other) const;
    reference operator*() const;
    pointer operator->() const;

    friend class map<K, T>;

   private:
    Node* current_;
  };
  using iterator = MapIterator;
  using const_iterator = const MapIterator;

  // Методы

  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
  void merge(map& other);
  void swap(map& other);
  size_type max_size() const;
  void clear();
  bool empty() const;
  T& at(const K& key);
<<<<<<< HEAD
  bool contains(const K& key);
=======
  bool contains(const K& key) const;
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
  size_type size() const;
  void erase(iterator pos);
  iterator find(const key_type& key);
  const_iterator find(const key_type& key) const;

  std::pair<iterator, bool> insert(const value_type& value);
  std::pair<iterator, bool> insert(const K& key, const T& obj);
  std::pair<iterator, bool> insert_or_assign(const K& key, const T& obj);

  // Конструкторы
  map();
  map(const map& other);
<<<<<<< HEAD
  // explicit Нужен он тут или необязателен?
  map(std::initializer_list<value_type> ilist);
  map(map&& other) noexcept;
  ~map() = default;
=======
  map(std::initializer_list<value_type> ilist);
  map(map&& other) noexcept;
  ~map();
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4

  // Операторы
  map& operator=(const map& other);
  map& operator=(map&& other) noexcept;
  typename map<K, T>::mapped_type& operator[](const key_type& key);

  // Дебаг-методы
  void DBG_MapPrinter(const char* dbg_message) const;

 private:
  // Служебные методы
<<<<<<< HEAD
  std::list<value_type> merge_sort(std::list<value_type> list);
  std::list<value_type> merge(const std::list<value_type>& left,
                              const std::list<value_type>& right);

  std::list<value_type> s21_map_;
  size_t actual_size_;
=======
  Node* create_node(const key_type& key, const mapped_type& data);
  void destroy_tree(Node* node);
  Node* copy_tree(const Node* other_node, Node* parent);
  Node* find_node(const key_type& key) const;
  Node* insert_node(const key_type& key, const mapped_type& data);
  std::pair<iterator, bool> insert_node_unique(const key_type& key,
                                               const mapped_type& data);
  Node* erase_node(Node* node);
  Node* find_min_node(Node* node) const;
  Node* root_ = nullptr;
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
};

}  // namespace s21

#include "../sources/s21_map/s21_map_constructors.tpp"
<<<<<<< HEAD
=======
#include "../sources/s21_map/s21_map_mapiterator_operators.tpp"
>>>>>>> ec1409eac33b9aa10cddf98906888821875be5a4
#include "../sources/s21_map/s21_map_methods.tpp"
#include "../sources/s21_map/s21_map_operators.tpp"
#endif  // SRS_HEADERS_S21_MAP_H_