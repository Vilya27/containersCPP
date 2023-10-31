
#include <gtest/gtest.h>

#include <map>

#include "../../headers/s21_map.h"
#include "gtest/gtest.h"

using namespace s21;

/*

TEST(MapTest, DefaultConstructor) {
  s21::map<int, int> m;
  m.DBG_MapPrinter("Empty map.");
}
TEST(MapTest, InitializerListConstructor) {
  s21::map<int, int> m{{1, 2}, {3, 4}};
  m.DBG_MapPrinter("Line is:\ns21::map<int, int> m{{1, 2}, {3, 4}};");
}
TEST(MapTest, CopyConstructor) {
  s21::map<int, int> m1{{1, 2}, {3, 4}};
  s21::map<int, int> m2(m1);
  EXPECT_EQ(m1.size(), m2.size());
  m1.DBG_MapPrinter("DBG. m1.");
  m2.DBG_MapPrinter("DBG. m2.");
}
TEST(MapTest, MoveConstructor) {
  s21::map<int, int> m1{{1, 2}, {3, 4}};
  s21::map<int, int> m2(std::move(m1));
  EXPECT_EQ(m1.size(), 0);
  EXPECT_EQ(m2.size(), 2);
  m1.DBG_MapPrinter("DBG. after m1 move to m2 m1 = ");
  m2.DBG_MapPrinter("DBG. after m1 move to m2 m2 = .");
}

TEST(MapTest, at_test) {
  s21::map<int, std::string> m{{3, "ZZZ"}, {2, "QQQ"}, {1, "MMM"}};
  DBG_printer("x", m.at(1));
}
TEST(MapTest, empty) {
  s21::map<int, std::string> m{{3, "ZZZ"}, {2, "QQQ"}, {1, "MMM"}};
  s21::map<int, std::string> mm;
  DBG_printer("x", mm.empty());
}


*/

TEST(MapTest, OperatorIndexing) {
  // Создание отображения
  s21::map<int, std::string> m;

  // Добавление элементов в отображение
  m[1] = "one";
  m[2] = "two";
  m[3] = "three";

  // Проверка значений по ключам
  EXPECT_EQ(m[1], "one");
  EXPECT_EQ(m[2], "two");
  EXPECT_EQ(m[3], "three");

  // Изменение значения по ключу
  m[2] = "new two";
  EXPECT_EQ(m[2], "new two");

  // Попытка доступа к несуществующему ключу
  EXPECT_EQ(m[5], "");
  m[5] = "five";
  std::cout << m[5] << "\n";
  EXPECT_EQ(m[5], "five");
}

TEST(SwapTest, SwapsTwoMaps) {
  // Arrange
  map<int, std::string> m1{{1, "one"}, {2, "two"}, {3, "three"}};
  map<int, std::string> m2{{4, "four"}, {5, "five"}};

  // Act
  m1.swap(m2);

  // Assert
  ASSERT_EQ(m1.size(), 2);
  EXPECT_EQ(m1.at(4), "four");
  EXPECT_EQ(m1.at(5), "five");

  ASSERT_EQ(m2.size(), 3);
  EXPECT_EQ(m2.at(1), "one");
  EXPECT_EQ(m2.at(2), "two");
  EXPECT_EQ(m2.at(3), "three");
}

TEST(SwapTest, SwapsMapsWithDifferentSizes) {
  // Arrange
  map<char, int> m1{{'a', 1}, {'b', 2}};
  map<char, int> m2{{'c', 3}};

  // Act
  m1.swap(m2);

  // Assert
  ASSERT_EQ(m1.size(), 1);
  EXPECT_EQ(m1.at('c'), 3);

  ASSERT_EQ(m2.size(), 2);
  EXPECT_EQ(m2.at('a'), 1);
  EXPECT_EQ(m2.at('b'), 2);
}

TEST(SwapTest, SwapsEmptyMaps) {
  // Arrange
  map<int, double> m1;
  map<int, double> m2;

  // Act
  m1.swap(m2);

  // Assert
  EXPECT_TRUE(m1.empty());
  EXPECT_TRUE(m2.empty());
}

/*
TEST(MapTest, Merge) {
  s21::map<int, int> map1 = {{1, 2}, {3, 4}};
  s21::map<int, int> map2 = {{5, 6}, {7, 8}};
  map1.merge(map2);

  EXPECT_EQ(map1.size(), 4);
  EXPECT_EQ(map1.at(1), 2);
  EXPECT_EQ(map1.at(3), 4);
  EXPECT_EQ(map1.at(5), 6);
  EXPECT_EQ(map1.at(7), 8);

  EXPECT_TRUE(map2.empty());
}


TEST(MapTest, MergeWithDuplicateKeys) {
  s21::map<int, int> map1 = {{1, 2}, {3, 4}};
  s21::map<int, int> map2 = {{3, 6}, {5, 8}};
  map1.DBG_MapPrinter("Before merge");
  map1.merge(map2);
  map1.DBG_MapPrinter("After merge");

  EXPECT_EQ(map1.size(), 3);
  EXPECT_EQ(map1.at(1), 2);
  EXPECT_EQ(map1.at(3), 6);  // значение из map2 перезапишет значение из map1
  EXPECT_EQ(map1.at(5), 8);

  EXPECT_TRUE(map2.empty());
}


*/

TEST(MapTest, IteratorKeysTest) {
  map<char, int> my_map{{'a', 1}, {'b', 2}, {'c', 3}};
  std::string keys;
  for (auto it = my_map.begin(); it != my_map.end(); ++it) {
    keys += it->first;
  }
  EXPECT_EQ(keys, "abc");
}

TEST(MapTest, Erase) {
  // Создаем объект map и заполняем его значениями
  s21::map<int, char> my_map = {{1, 'a'}, {2, 'b'}, {3, 'c'}};

  // Получаем итератор на элемент с ключом 2
  auto it = my_map.begin();
  std::advance(it, 1);

  // Удаляем элемент с ключом 2
  my_map.erase(it);

  // Проверяем размер контейнера и значения оставшихся элементов
  ASSERT_EQ(my_map.size(), 2u);
  EXPECT_EQ(my_map.at(1), 'a');
  EXPECT_EQ(my_map.at(3), 'c');

  // Удаляем последний элемент
  my_map.erase(--my_map.end());

  // Проверяем размер контейнера и значения оставшегося элемента
  ASSERT_EQ(my_map.size(), 1u);
  EXPECT_EQ(my_map.at(1), 'a');

  // Очищаем контейнер и проверяем, что он стал пустым
  my_map.clear();
  ASSERT_TRUE(my_map.empty());
}

TEST(MapTest, InsertTest) {
  map<int, int> my_map;

  // Добавляем элемент в пустую карту
  auto [iter1, inserted1] = my_map.insert({1, 10});
  ASSERT_TRUE(inserted1);
  ASSERT_EQ(iter1->first, 1);
  ASSERT_EQ(iter1->second, 10);

  // Пытаемся добавить существующий элемент
  auto [iter2, inserted2] = my_map.insert({1, 20});
  ASSERT_FALSE(inserted2);
  ASSERT_EQ(iter2->first, 1);
  ASSERT_EQ(iter2->second, 10);

  // Добавляем новый элемент в заполненную карту
  auto [iter3, inserted3] = my_map.insert({2, 20});
  ASSERT_TRUE(inserted3);
  ASSERT_EQ(iter3->first, 2);
  ASSERT_EQ(iter3->second, 20);

  // Проверяем количество элементов
  ASSERT_EQ(my_map.size(), 2);
}

TEST(MapTest, InsertByKey) {
  s21::map<int, std::string> map;
  auto [it1, success1] = map.insert(1, "one");
  ASSERT_TRUE(success1);
  ASSERT_EQ(it1->first, 1);
  ASSERT_EQ(it1->second, "one");

  auto [it2, success2] = map.insert(2, "two");
  ASSERT_TRUE(success2);
  ASSERT_EQ(it2->first, 2);
  ASSERT_EQ(it2->second, "two");

  auto [it3, success3] = map.insert(1, "another one");
  ASSERT_FALSE(success3);
  ASSERT_EQ(it3->first, 1);
  ASSERT_EQ(it3->second, "one");
}

TEST(MapTest, InitializerListConstruction) {
  using key_type = std::string;
  using value_type = std::pair<const key_type, int>;
  std::initializer_list<value_type> ilist = {
      {"one", 1}, {"two", 2}, {"three", 3}};

  // Test construction
  std::map<key_type, int> stl_map(ilist);
  map<key_type, int> s21_map(ilist);

  EXPECT_EQ(s21_map.size(), stl_map.size());

  // Test contents of the maps are equal
  auto stl_it = stl_map.begin();
  auto s21_it = s21_map.begin();

  for (; s21_it != s21_map.end(); ++s21_it, ++stl_it) {
    EXPECT_EQ(s21_it->first, stl_it->first);
    EXPECT_EQ(s21_it->second, stl_it->second);
  }
}

TEST(MapTest, Merge_DifferentMaps) {
  s21::map<int, int> a{{1, 10}, {2, 20}};
  s21::map<int, int> b{{3, 30}, {4, 40}};
  std::map<int, int> c{{1, 10}, {2, 20}};
  std::map<int, int> d{{3, 30}, {4, 40}};

  a.merge(b);
  c.merge(d);

  EXPECT_EQ(a.size(), c.size());
  for (const auto& [key, value] : c) {
    EXPECT_EQ(a[key], value);
  }
}

TEST(MapTest, Merge_SameMap) {
  s21::map<int, int> a{{1, 10}, {2, 20}};
  s21::map<int, int> b{{1, 10}, {2, 20}};
  std::map<int, int> c{{1, 10}, {2, 20}};
  std::map<int, int> d{{1, 10}, {2, 20}};

  a.merge(a);
  c.merge(c);

  EXPECT_EQ(a.size(), c.size());
  for (const auto& [key, value] : c) {
    EXPECT_EQ(a[key], value);
  }
}

TEST(MapTest, Merge_LargerMaps) {
  s21::map<int, int> a{{1, 10}, {2, 20}, {3, 30}, {4, 40}};
  s21::map<int, int> b{{5, 50}, {6, 60}};
  std::map<int, int> c{{1, 10}, {2, 20}, {3, 30}, {4, 40}};
  std::map<int, int> d{{5, 50}, {6, 60}};

  a.merge(b);
  c.merge(d);

  EXPECT_EQ(a.size(), c.size());
  for (const auto& [key, value] : c) {
    EXPECT_EQ(a[key], value);
  }
}

TEST(MapTest, Merge_DifferentTypes) {
  s21::map<std::string, double> a{{"one", 1.0}, {"two", 2.5}};
  s21::map<std::string, double> b{{"three", 3.0}, {"four", 4.5}};
  std::map<std::string, double> c{{"one", 1.0}, {"two", 2.5}};
  std::map<std::string, double> d{{"three", 3.0}, {"four", 4.5}};

  a.merge(b);
  c.merge(d);

  EXPECT_EQ(a.size(), c.size());
  for (const auto& [key, value] : c) {
    EXPECT_EQ(a[key], value);
  }
}

TEST(MapTest, InsertOrAssign) {
  // Создаем пустую карту с целочисленными ключами и значениями
  s21::map<int, int> my_map;

  // Вставляем пару (1, 10)
  auto res1 = my_map.insert_or_assign(1, 10);
  EXPECT_TRUE(
      res1.second);  // должно вернуться true, потому что элемент был добавлен
  EXPECT_EQ(res1.first->first, 1);  // проверяем ключ

  // Пытаемся вставить ту же пару еще раз
  auto res2 = my_map.insert_or_assign(1, 20);
  EXPECT_FALSE(
      res2.second);  // должно вернуться false, потому что элемент уже есть
  EXPECT_EQ(res2.first->second, 20);  // проверяем значение

  // Добавляем несколько других элементов
  my_map.insert_or_assign(2, 30);
  my_map.insert_or_assign(3, 40);

  // Проверяем, что все элементы присутствуют
  EXPECT_EQ(my_map.size(), 3);
  EXPECT_EQ(my_map[1], 20);
  EXPECT_EQ(my_map[2], 30);
  EXPECT_EQ(my_map[3], 40);

  // Проверяем, что вставка и изменение элементов работает также, как и для
  // std::map
  s21::map<int, int> s21_map;
  auto s21_res1 = s21_map.insert_or_assign(1, 10);
  auto s21_res2 = s21_map.insert_or_assign(1, 20);
  EXPECT_FALSE(s21_res2.second);
  EXPECT_EQ(s21_res1.first->second, 20);
  EXPECT_EQ(s21_res2.first->second, 20);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  // ::testing::GTEST_FLAG(filter) = "*InsertOrAssign*";

  return RUN_ALL_TESTS();
}