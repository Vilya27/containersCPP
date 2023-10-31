
#include <gtest/gtest.h>

#include <string>

#include "../../headers/s21_set.h"

using namespace s21;

#include <gtest/gtest.h>

TEST(setTest, DefaultConstructor) {
  s21::set<int> s;
  EXPECT_TRUE(s.empty());
  EXPECT_EQ(s.size(), 0);
}

TEST(setTest, InitializerListConstructor) {
  s21::set<int> s = {1, 2, 3};
  EXPECT_EQ(s.size(), 3);
  EXPECT_TRUE(s.contains(1));
  EXPECT_TRUE(s.contains(2));
  EXPECT_TRUE(s.contains(3));
}

TEST(setTest, CopyConstructor) {
  s21::set<int> s1 = {1, 2, 3};
  s21::set<int> s2(s1);
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(setTest, MoveConstructor) {
  s21::set<int> s1 = {1, 2, 3};
  s21::set<int> s2(std::move(s1));
  EXPECT_EQ(s2.size(), 3);
  EXPECT_TRUE(s2.contains(1));
  EXPECT_TRUE(s2.contains(2));
  EXPECT_TRUE(s2.contains(3));
}

TEST(setTest, SizeMaxSize) {
  s21::set<int> s{3, 5, 1, 4, 2};
  std::set<int> s1{3, 5, 1, 4, 2};
  ASSERT_EQ(s.size(), 5);
  ASSERT_GE(s.max_size(), s1.max_size());

  s.clear();
  ASSERT_EQ(s.size(), 0);
}
TEST(setTest, Erase) {
  s21::set<int> s{1, 2, 3, 4, 5};
  auto it = s.find(3);
  s.erase(it);
  EXPECT_EQ(s.size(), 4);
  EXPECT_FALSE(s.contains(3));
}

TEST(setTest, Swap) {
  s21::set<int> s1{1, 2, 3};
  s21::set<int> s2{4, 5, 6};
  s1.swap(s2);
  EXPECT_EQ(s1.size(), 3);
  EXPECT_EQ(s2.size(), 3);
  EXPECT_TRUE(s2.contains(1));
  EXPECT_TRUE(s1.contains(4));
}

TEST(setTest, Merge) {
  s21::set<int> s1{1, 2, 3};
  s21::set<int> s2{3, 4, 5};
  s1.merge(s2);
  EXPECT_EQ(s1.size(), 5);
  EXPECT_EQ(s2.size(), 0);
  EXPECT_TRUE(s1.contains(4));
  EXPECT_FALSE(s2.contains(3));
}

TEST(setTest, Find) {
  s21::set<int> s{1, 2, 3};
  auto it1 = s.find(2);
  EXPECT_EQ(*it1, 2);
  auto it2 = s.find(4);
  EXPECT_EQ(it2, s.end());
}
// Part II
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

TEST(MySetTest, EmptyMethod) {
  set<int> s;
  ASSERT_TRUE(s.empty());
  s.insert(42);
  ASSERT_FALSE(s.empty());
}

TEST(MySetTest, SizeMethod) {
  set<int> s{1, 2, 3};
  ASSERT_EQ(3, s.size());
  s.erase(s.find(2));
  ASSERT_EQ(2, s.size());
  s.insert(4);
  ASSERT_EQ(3, s.size());
}

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

TEST(MySetTest, EraseMethod) {
  set<int> s{1, 2, 3};
  s.erase(s.find(2));
  ASSERT_EQ(2, s.size());
  ASSERT_FALSE(s.contains(2));
}

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

TEST(MySetTest, FindMethod) {
  set<int> s{1, 2, 3};
  auto it = s.find(2);
  ASSERT_TRUE(it != s.end());
  ASSERT_EQ(2, *it);
  it = s.find(4);
  ASSERT_TRUE(it == s.end());
}

TEST(MySetTest, MergeMethod) {
  set<int> s1{1, 2};
  set<int> s2{3, 4};
  s1.merge(s2);
  ASSERT_EQ(4, s1.size());
  ASSERT_TRUE(s1.contains(1));
  ASSERT_TRUE(s1.contains(2));
  ASSERT_TRUE(s1.contains(3));
  ASSERT_TRUE(s1.contains(4));
  ASSERT_TRUE(s2.empty());
}

TEST(MySetTest, EraseFromEmptySet) {
  set<int> s;
  EXPECT_THROW(s.erase(s.begin()), std::out_of_range);
}

TEST(MySetTest, MaxSize) {
  set<int> s;
  ASSERT_GE(std::numeric_limits<set<int>::size_type>::max(), s.max_size());
}

// Тест на корректность работы итераторов
TEST(MySetTest, IteratorTest) {
  set<int> s{3, 2, 1};
  auto it = s.begin();
  ASSERT_EQ(1, *it);
  it++;
  ASSERT_EQ(2, *it);
  it++;
  ASSERT_EQ(3, *it);
  it++;
  ASSERT_TRUE(it == s.end());

  // Тест на удаление текущего элемента
  it = s.begin();
  int val = *it;
  s.erase(it);
  ASSERT_FALSE(s.contains(val));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}