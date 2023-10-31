
#include <gtest/gtest.h>

#include <string>

#include "../../headers/s21_set.h"

using namespace s21;

// Тест конструктора по умолчанию
TEST(MySetTest, DefaultConstructor) {
  set<int> s;
  ASSERT_TRUE(s.empty());
  ASSERT_EQ(0, s.size());
}

// Тест конструктора с инициализацией
TEST(MySetTest, InitializerListConstructor) {
  set<int> s{1, 2, 3};
  ASSERT_FALSE(s.empty());
  ASSERT_EQ(3, s.size());
  ASSERT_TRUE(s.contains(1));
  ASSERT_TRUE(s.contains(2));
  ASSERT_TRUE(s.contains(3));
}

// Тест копирующего конструктора
TEST(MySetTest, CopyConstructor) {
  set<int> s1{1, 2, 3};
  set<int> s2(s1);
  ASSERT_EQ(s1.size(), s2.size());
  ASSERT_TRUE(s1.contains(1));
  ASSERT_TRUE(s2.contains(1));
  ASSERT_TRUE(s1.contains(2));
  ASSERT_TRUE(s2.contains(2));
  ASSERT_TRUE(s1.contains(3));
  ASSERT_TRUE(s2.contains(3));
}

// Тест перемещающего конструктора
TEST(MySetTest, MoveConstructor) {
  set<int> s1{1, 2, 3};
  set<int> s2(std::move(s1));
  ASSERT_EQ(3, s2.size());
  ASSERT_TRUE(s2.contains(1));
  ASSERT_TRUE(s2.contains(2));
  ASSERT_TRUE(s2.contains(3));
  ASSERT_TRUE(s1.empty());
}

// Тест оператора присваивания перемещением
TEST(MySetTest, MoveAssignmentOperator) {
  set<int> s1{1, 2, 3};
  set<int> s2;
  s2 = std::move(s1);
  ASSERT_EQ(3, s2.size());
  ASSERT_TRUE(s2.contains(1));
  ASSERT_TRUE(s2.contains(2));
  ASSERT_TRUE(s2.contains(3));
  ASSERT_TRUE(s1.empty());
}

// Тест метода empty()
TEST(MySetTest, EmptyMethod) {
  set<int> s;
  ASSERT_TRUE(s.empty());
  s.insert(42);
  ASSERT_FALSE(s.empty());
}

// Тест метода size()
TEST(MySetTest, SizeMethod) {
  set<int> s{1, 2, 3};
  ASSERT_EQ(3, s.size());
  s.erase(s.find(2));
  ASSERT_EQ(2, s.size());
  s.insert(4);
  ASSERT_EQ(3, s.size());
}

// Тест метода insert()
TEST(MySetTest, InsertMethod) {
  set<int> s{1, 2, 3};
  auto res = s.insert(4);
  ASSERT_EQ(4, s.size());
  ASSERT_TRUE(*res.first == 4);
  ASSERT_TRUE(res.second);
  // Вставка уже существующего элемента
  res = s.insert(2);
  ASSERT_EQ(4, s.size());

  ASSERT_TRUE(*res.first == 2);
  ASSERT_FALSE(res.second);
}

// Тест метода erase()
TEST(MySetTest, EraseMethod) {
  set<int> s{1, 2, 3};
  s.erase(s.find(2));
  ASSERT_EQ(2, s.size());
  ASSERT_FALSE(s.contains(2));
}

// Тест метода swap()
TEST(MySetTest, SwapMethod) {
  set<int> s1{1, 2};
  set<int> s2{3, 4};
  s1.swap(s2);
  ASSERT_EQ(2, s2.size());
  ASSERT_TRUE(s2.contains(1));
  ASSERT_TRUE(s2.contains(2));
  ASSERT_EQ(2, s1.size());
  ASSERT_TRUE(s1.contains(3));
  ASSERT_TRUE(s1.contains(4));
}

// Тест метода find()
TEST(MySetTest, FindMethod) {
  set<int> s{1, 2, 3};
  auto it = s.find(2);
  ASSERT_TRUE(it != s.end());
  ASSERT_EQ(2, *it);
  it = s.find(4);
  ASSERT_TRUE(it == s.end());
}

// Тест метода merge()
TEST(MySetTest, MergeMethod) {
  set<int> s1{1, 2};
  set<int> s2{3, 4};
  s1.merge(s2);
  ASSERT_EQ(4, s1.size());
  ASSERT_TRUE(s1.contains(1));
  ASSERT_TRUE(s1.contains(2));
  ASSERT_TRUE(s1.contains(3));
  ASSERT_TRUE(s1.contains(4));
  ASSERT_FALSE(s2.empty());
}

// Тест на использование set в качестве элементов самого себя
TEST(MySetTest, SelfAsElement) {
  set<std::set<int>> s;
  s.insert(std::set<int>{1, 2, 3});
  s.insert(std::set<int>{4, 5, 6});

  ASSERT_EQ(2, s.size());
  ASSERT_TRUE(s.contains(std::set<int>{1, 2, 3}));
  ASSERT_TRUE(s.contains(std::set<int>{4, 5, 6}));
}

// Тесты на граничные случаи

// Удаление элемента из пустого множества
TEST(MySetTest, EraseFromEmptySet) {
  set<int> s;
  EXPECT_THROW(s.erase(s.begin()), std::out_of_range);
}

/*
Вешает систему

// Вставка в уже полное множество
TEST(S21SetTest, InsertFullSet) {
  s21::set<int> set1;
  const int max_size = set1.max_size();

  for (int i = 0; i < max_size; ++i) {
    auto res = set1.insert(i);
    EXPECT_TRUE(res.second);
  }

  for (int i = 0; i < max_size; ++i) {
    EXPECT_TRUE(set1.contains(i));
  }

  ASSERT_THROW(set1.insert(max_size), std::out_of_range);
}
*/

// Определение максимального размера
TEST(MySetTest, MaxSize) {
  set<int> s;
  ASSERT_GE(std::numeric_limits<set<int>::size_type>::max(), s.max_size());
}

// Тест на корректность работы итераторов
TEST(MySetTest, IteratorTest) {
  set<int> s{3, 2, 1};
  auto it = s.begin();
  ASSERT_EQ(1, *it++);
  ASSERT_EQ(2, *it++);
  ASSERT_EQ(3, *it++);
  ASSERT_TRUE(it == s.end());

  // Тест на удаление текущего элемента
  it = s.begin();
  int val = *it;
  s.erase(it);
  ASSERT_FALSE(s.contains(val));
}

#include <gtest/gtest.h>

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  //  ::testing::GTEST_FLAG(filter) = "*InsertManyElements*";

  return RUN_ALL_TESTS();
}
