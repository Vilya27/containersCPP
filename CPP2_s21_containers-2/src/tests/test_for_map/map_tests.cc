#include <gtest/gtest.h>

#include <list>
#include <map>

#include "../../headers/s21_map.h"

TEST(mapConstructorTest, DefaultConstructor) {
  s21::map<int, std::string> m;
  EXPECT_EQ(m.size(), 0);
  EXPECT_TRUE(m.empty());
}

TEST(mapConstructorTest, InitializerListConstructor) {
  s21::map<int, std::string> m{{1, "one"}, {2, "two"}, {3, "three"}};
  EXPECT_EQ(m.size(), 3);
  EXPECT_FALSE(m.empty());
  EXPECT_EQ(m.at(1), "one");
  EXPECT_EQ(m.at(2), "two");
  EXPECT_EQ(m.at(3), "three");
}

TEST(mapConstructorTest, CopyConstructor) {
  s21::map<int, std::string> m{{1, "one"}, {2, "two"}, {3, "three"}};
  s21::map<int, std::string> copy_m(m);
  EXPECT_EQ(copy_m.size(), 3);
  EXPECT_FALSE(copy_m.empty());
  EXPECT_EQ(copy_m.at(1), "one");
}

TEST(mapTest, InsertOrAssign) {
  std::map<int, std::string> map;
  auto [it1, inserted1] = map.insert_or_assign(1, "one");
  EXPECT_TRUE(inserted1);
  EXPECT_EQ(it1->first, 1);
  EXPECT_EQ(it1->second, "one");
  auto [it2, inserted2] = map.insert_or_assign(1, "ONE");
  EXPECT_FALSE(inserted2);
  EXPECT_EQ(it2->first, 1);
  EXPECT_EQ(it2->second, "ONE");
  map.insert_or_assign(2, "two");
  map.insert_or_assign(3, "three");
  map.insert_or_assign(4, "four");
  map.insert_or_assign(5, "five");
  EXPECT_EQ(map.size(), 5);
  EXPECT_EQ(map[1], "ONE");
  EXPECT_EQ(map[2], "two");
  EXPECT_EQ(map[3], "three");
  EXPECT_EQ(map[4], "four");
  EXPECT_EQ(map[5], "five");
}

TEST(mapTest, AtAndOperatorBrackets) {
  s21::map<int, std::string> map = {{1, "one"}, {2, "two"}, {3, "three"}};

  EXPECT_EQ(map.at(1), "one");
  EXPECT_EQ(map[2], "two");
  EXPECT_THROW(map.at(4), std::invalid_argument);
  map[4] = "four";
  EXPECT_EQ(map[4], "four");
  map[2] = "TWO";
  EXPECT_EQ(map[2], "TWO");
}

TEST(mapTest, EmptyAndSize) {
  s21::map<int, std::string> empty_map;
  s21::map<int, std::string> map = {{1, "one"}, {2, "two"}, {3, "three"}};

  EXPECT_TRUE(empty_map.empty());
  EXPECT_EQ(empty_map.size(), 0);

  EXPECT_FALSE(map.empty());
  EXPECT_EQ(map.size(), 3);
}

TEST(mapTest, Erase) {
  s21::map<int, std::string> map;

  map.insert({1, "one"});
  map.insert({2, "two"});
  map.insert({3, "three"});
  map.insert({5, "five"});

  auto it1 = map.begin()++;
  map.erase(it1);
  EXPECT_EQ(map.size(), 3);
  EXPECT_FALSE(map.contains(1));
}

TEST(mapTest, Swap) {
  s21::map<int, std::string> map1;
  map1.insert({1, "one"});
  map1.insert({2, "two"});

  s21::map<int, std::string> map2;
  map2.insert({3, "three"});
  map2.insert({4, "four"});

  map1.swap(map2);

  EXPECT_EQ(map1.size(), 2);
  EXPECT_TRUE(map1.contains(3));
  EXPECT_TRUE(map1.contains(4));

  EXPECT_EQ(map2.size(), 2);
  EXPECT_TRUE(map2.contains(1));
  EXPECT_TRUE(map2.contains(2));
}

TEST(mapTest, Merge) {
  s21::map<int, std::string> map1;
  map1.insert({1, "one"});
  map1.insert({2, "two"});

  s21::map<int, std::string> map2;
  map2.insert({3, "three"});
  map2.insert({4, "four"});

  map1.merge(map2);

  EXPECT_EQ(map1.size(), 4);
  EXPECT_TRUE(map1.contains(1));
  EXPECT_TRUE(map1.contains(2));
  EXPECT_TRUE(map1.contains(3));
  EXPECT_TRUE(map1.contains(4));
}

TEST(mapTest, Contains) {
  s21::map<int, std::string> map;

  map.insert({1, "one"});
  map.insert({2, "two"});
  EXPECT_TRUE(map.contains(2));
  EXPECT_FALSE(map.contains(3));
}

// PART II

using namespace s21;
TEST(MapTest, DefaultConstructor) {
  map<int, int> m;
  EXPECT_EQ(m.size(), 0);
  EXPECT_TRUE(m.empty());
}

TEST(MapTest, InitializerListConstructor) {
  map<int, int> map{{1, 2}, {3, 4}, {5, 6}};
  EXPECT_EQ(map.size(), 3);
  EXPECT_FALSE(map.empty());
  EXPECT_EQ(map.at(1), 2);
  EXPECT_EQ(map.at(3), 4);
  EXPECT_EQ(map.at(5), 6);
}

TEST(MapTest, CopyConstructor) {
  map<int, int> original_map{{1, 2}, {3, 4}, {5, 6}};
  map<int, int> copied_map(original_map);
  EXPECT_EQ(copied_map.size(), 3);
  EXPECT_FALSE(copied_map.empty());
  EXPECT_EQ(copied_map.at(1), 2);
  EXPECT_EQ(copied_map.at(3), 4);
  EXPECT_EQ(copied_map.at(5), 6);
}

TEST(MapTest, MoveConstructor) {
  map<int, int> original_map{{1, 2}, {3, 4}, {5, 6}};
  map<int, int> moved_map(std::move(original_map));
  EXPECT_EQ(moved_map.size(), 3);
  EXPECT_FALSE(moved_map.empty());
  EXPECT_EQ(moved_map.at(1), 2);
  EXPECT_EQ(moved_map.at(3), 4);
  EXPECT_EQ(moved_map.at(5), 6);
}

TEST(MapTest, AssignmentOperatorMove) {
  map<int, int> original_map{{1, 2}, {3, 4}, {5, 6}};
  map<int, int> assigned_map = std::move(original_map);
  EXPECT_EQ(assigned_map.size(), 3);
  EXPECT_FALSE(assigned_map.empty());
  EXPECT_EQ(assigned_map.at(1), 2);
  EXPECT_EQ(assigned_map.at(3), 4);
  EXPECT_EQ(assigned_map.at(5), 6);
}

TEST(MapTest, At) {
  map<int, int> map{{1, 2}, {3, 4}, {5, 6}};
  EXPECT_EQ(map.at(1), 2);
  EXPECT_EQ(map.at(3), 4);
  EXPECT_EQ(map.at(5), 6);
  EXPECT_THROW(map.at(7), std::invalid_argument);
}

TEST(MapTest, SquareBracketsOperator) {
  map<int, int> map{{1, 2}, {3, 4}, {5, 6}};
  EXPECT_EQ(map[1], 2);
  EXPECT_EQ(map[3], 4);
  EXPECT_EQ(map[5], 6);
  map[7] = 8;
  EXPECT_EQ(map[7], 8);
}

TEST(MapTest, Empty) {
  map<int, int> empty_map;
  EXPECT_TRUE(empty_map.empty());
  map<int, int> non_empty_map{{1, 2}};
  EXPECT_FALSE(non_empty_map.empty());
}

TEST(MapTest, Size) {
  map<int, int> empty_map;
  EXPECT_EQ(empty_map.size(), 0);
  map<int, int> map{{1, 2}, {3, 4}, {5, 6}};
  EXPECT_EQ(map.size(), 3);
}

TEST(MapTest, Clear) {
  map<int, int> map{{1, 2}, {3, 4}, {5, 6}};
  map.clear();
  EXPECT_TRUE(map.empty());
}

TEST(MapTest, Insert) {
  map<int, int> map{{1, 2}, {3, 4}, {5, 6}};
  auto insert_result = map.insert({7, 8});
  EXPECT_EQ(insert_result.second, true);
  EXPECT_EQ(insert_result.first->first, 7);
  EXPECT_EQ(insert_result.first->second, 8);
  insert_result = map.insert({1, 100});
  EXPECT_EQ(insert_result.second, false);
  EXPECT_EQ(insert_result.first->first, 1);
  EXPECT_EQ(insert_result.first->second, 2);
}

TEST(MapTest, Erase) {
  map<int, int> map{{1, 2}, {3, 4}, {5, 6}};
  auto it = map.find(3);
  map.erase(it);
  EXPECT_EQ(map.size(), 2);
  EXPECT_FALSE(map.contains(3));
}

TEST(MapTest, Swap) {
  s21::map<int, int> map{{1, 2}, {3, 4}};
  s21::map<int, int> other{{5, 6}};
  map.swap(other);
  EXPECT_FALSE(map.contains(1));
  EXPECT_TRUE(map.contains(5));
  EXPECT_FALSE(other.contains(5));
  EXPECT_TRUE(other.contains(1));
}

TEST(MapTest, Merge) {
  s21::map<int, int> map{{1, 2}, {3, 4}};
  s21::map<int, int> other{{5, 6}, {7, 8}};
  map.merge(other);
  EXPECT_EQ(map.size(), 4);
  EXPECT_TRUE(map.contains(5));
  EXPECT_TRUE(map.contains(7));
}

TEST(MapTest, Contains) {
  map<int, int> map{{1, 2}, {3, 4}, {5, 6}};
  EXPECT_TRUE(map.contains(1));
  EXPECT_FALSE(map.contains(7));
}

TEST(MapTest, OperatorIndexing) {
  s21::map<int, std::string> m;

  m[1] = "one";
  m[2] = "two";
  m[3] = "three";

  EXPECT_EQ(m[1], "one");
  EXPECT_EQ(m[2], "two");
  EXPECT_EQ(m[3], "three");

  m[2] = "new two";
  EXPECT_EQ(m[2], "new two");

  EXPECT_EQ(m[5], "");
  m[5] = "five";
  EXPECT_EQ(m[5], "five");
}

TEST(SwapTest, SwapsTwoMaps) {
  map<int, std::string> m1{{1, "one"}, {2, "two"}, {3, "three"}};
  map<int, std::string> m2{{4, "four"}, {5, "five"}};

  m1.swap(m2);

  ASSERT_EQ(m1.size(), 2);
  EXPECT_EQ(m1.at(4), "four");
  EXPECT_EQ(m1.at(5), "five");

  ASSERT_EQ(m2.size(), 3);
  EXPECT_EQ(m2.at(1), "one");
  EXPECT_EQ(m2.at(2), "two");
  EXPECT_EQ(m2.at(3), "three");
}

TEST(SwapTest, SwapsMapsWithDifferentSizes) {
  map<char, int> m1{{'a', 1}, {'b', 2}};
  map<char, int> m2{{'c', 3}};

  m1.swap(m2);

  ASSERT_EQ(m1.size(), 1);
  EXPECT_EQ(m1.at('c'), 3);

  ASSERT_EQ(m2.size(), 2);
  EXPECT_EQ(m2.at('a'), 1);
  EXPECT_EQ(m2.at('b'), 2);
}

TEST(SwapTest, SwapsEmptyMaps) {
  map<int, double> m1;
  map<int, double> m2;

  m1.swap(m2);

  EXPECT_TRUE(m1.empty());
  EXPECT_TRUE(m2.empty());
}

TEST(MapTest, Merge2) {
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

  map1.merge(map2);

  EXPECT_EQ(map1.size(), 3);
  EXPECT_EQ(map1.at(1), 2);
  EXPECT_EQ(map1.at(3), 6);
  EXPECT_EQ(map1.at(5), 8);

  EXPECT_TRUE(map2.empty());
}

TEST(MapTest, IteratorKeysTest) {
  map<char, int> my_map{{'a', 1}, {'b', 2}, {'c', 3}};
  std::string keys;
  for (auto it = my_map.begin(); it != my_map.end(); ++it) {
    keys += it->first;
  }
  EXPECT_EQ(keys, "abc");
}

TEST(MapTest, InsertTest) {
  map<int, int> my_map;

  auto [iter1, inserted1] = my_map.insert({1, 10});
  ASSERT_TRUE(inserted1);
  ASSERT_EQ(iter1->first, 1);
  ASSERT_EQ(iter1->second, 10);

  // Пытаемся добавить существующий элемент
  auto [iter2, inserted2] = my_map.insert({1, 20});
  ASSERT_FALSE(inserted2);
  ASSERT_EQ(iter2->first, 1);
  ASSERT_EQ(iter2->second, 10);

  // Добавляем новый элемент в заполненный мап
  auto [iter3, inserted3] = my_map.insert({2, 20});
  ASSERT_TRUE(inserted3);
  ASSERT_EQ(iter3->first, 2);
  ASSERT_EQ(iter3->second, 20);

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

  std::map<key_type, int> stl_map(ilist);
  map<key_type, int> s21_map(ilist);

  EXPECT_EQ(s21_map.size(), stl_map.size());

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
  s21::map<int, int> my_map;

  // Вставляем пару (1, 10)
  auto res1 = my_map.insert_or_assign(1, 10);
  EXPECT_TRUE(res1.second);
  EXPECT_EQ(res1.first->first, 1);

  auto res2 = my_map.insert_or_assign(1, 20);
  EXPECT_FALSE(res2.second);
  EXPECT_EQ(res2.first->second, 20);

  my_map.insert_or_assign(2, 30);
  my_map.insert_or_assign(3, 40);

  EXPECT_EQ(my_map.size(), 3);
  EXPECT_EQ(my_map[1], 20);
  EXPECT_EQ(my_map[2], 30);
  EXPECT_EQ(my_map[3], 40);

  s21::map<int, int> s21_map;
  auto s21_res1 = s21_map.insert_or_assign(1, 10);
  auto s21_res2 = s21_map.insert_or_assign(1, 20);
  EXPECT_FALSE(s21_res2.second);
  EXPECT_EQ(s21_res1.first->second, 20);
  EXPECT_EQ(s21_res2.first->second, 20);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}