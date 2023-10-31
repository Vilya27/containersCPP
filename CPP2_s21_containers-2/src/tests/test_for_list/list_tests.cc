#include <gtest/gtest.h>

#include <list>

#include "../../headers/s21_list.h"
using namespace s21;

TEST(ListTest, DefaultConstructor) {
  list<int> l;
  EXPECT_TRUE(l.empty());
  EXPECT_EQ(0, l.size());
}

TEST(ListTest, SizeConstructor) {
  list<int> l(5);
  EXPECT_FALSE(l.empty());
  EXPECT_EQ(5, l.size());
}

TEST(ListTest, InitializerListConstructor) {
  list<char> l{'a', 'b', 'c'};
  EXPECT_FALSE(l.empty());
  EXPECT_EQ(3, l.size());
}

TEST(ListTest, CopyConstructor) {
  list<int> original{1, 2, 3};
  list<int> copy(original);
  EXPECT_FALSE(copy.empty());
  EXPECT_EQ(3, copy.size());
  EXPECT_EQ(1, copy.front());
  EXPECT_EQ(3, copy.back());
}

TEST(ListTest, MoveConstructor) {
  list<std::string> original{"Hello", "world"};
  list<std::string> moved(std::move(original));
  EXPECT_TRUE(original.empty());
  EXPECT_FALSE(moved.empty());
  EXPECT_EQ(2, moved.size());
  EXPECT_EQ("Hello", moved.front());
  EXPECT_EQ("world", moved.back());
}

TEST(ListTest, AssignmentOperator) {
  list<int> original{1, 2, 3};
  list<int> copy;
  copy = original;
  EXPECT_FALSE(copy.empty());
  EXPECT_EQ(3, copy.size());
  EXPECT_EQ(1, copy.front());
  EXPECT_EQ(3, copy.back());
}

TEST(ListTest, MoveAssignmentOperator) {
  list<std::string> original{"Hello", "world"};
  list<std::string> moved;
  moved = std::move(original);
  EXPECT_TRUE(original.empty());
  EXPECT_FALSE(moved.empty());
  EXPECT_EQ(2, moved.size());
  EXPECT_EQ("Hello", moved.front());
  EXPECT_EQ("world", moved.back());
}

TEST(ListTest, FrontAndBack) {
  list<int> l{5, 10, 15};
  EXPECT_EQ(5, l.front());
  EXPECT_EQ(15, l.back());
}

TEST(ListTest, Iterator) {
  list<int> l{1, 2, 3};
  auto it = l.begin();
  EXPECT_EQ(1, *it);
  ++it;
  EXPECT_EQ(2, *it);
  ++it;
  EXPECT_EQ(3, *it);
}

TEST(ListTest, ConstIterator) {
  const list<int> l{1, 2, 3};
  auto it = l.begin();
  EXPECT_EQ(1, *it);
  ++it;
  EXPECT_EQ(2, *it);
  ++it;
  EXPECT_EQ(3, *it);
}

TEST(ListTest, Empty) {
  list<int> l;
  EXPECT_TRUE(l.empty());
  l.push_back(5);
  EXPECT_FALSE(l.empty());
}

TEST(ListTest, Size) {
  list<int> l{1, 2, 3};
  EXPECT_EQ(3, l.size());
  l.push_front(0);
  EXPECT_EQ(4, l.size());
}

TEST(ListTest, Clear) {
  list<int> l{1, 2, 3};
  EXPECT_FALSE(l.empty());
  l.clear();
  EXPECT_TRUE(l.empty());
  EXPECT_EQ(0, l.size());
}

TEST(ListTest, Erase) {
  list<int> l{1, 2, 3};
  auto it = l.begin();
  ++it;
  l.erase(it);
  EXPECT_EQ(2, l.size());
  EXPECT_EQ(3, l.back());
}

TEST(ListTest, PushBack) {
  list<int> l{1, 2};
  l.push_back(3);
  EXPECT_EQ(3, l.size());
  EXPECT_EQ(3, l.back());
}

TEST(ListTest, PopBack) {
  list<int> l{1, 2, 3};
  l.pop_back();
  EXPECT_EQ(2, l.size());
  EXPECT_EQ(2, l.back());
}

TEST(ListTest, PushFront) {
  list<int> l{2, 3};
  l.push_front(1);
  EXPECT_EQ(3, l.size());
  EXPECT_EQ(1, l.front());
}

TEST(ListTest, PopFront) {
  list<int> l{1, 2, 3};
  l.pop_front();
  EXPECT_EQ(2, l.size());
  EXPECT_EQ(2, l.front());
}

TEST(ListTest, Swap) {
  list<int> first{1, 2, 3};
  list<int> second{4, 5};
  first.swap(second);
  EXPECT_EQ(2, first.size());
  EXPECT_EQ(4, first.front());
  EXPECT_EQ(5, first.back());
  EXPECT_EQ(3, second.size());
  EXPECT_EQ(1, second.front());
  EXPECT_EQ(3, second.back());
}

TEST(ListTest, Merge) {
  list<int> first{1, 3, 5};
  list<int> second{2, 4, 6};
  first.merge(second);
  EXPECT_TRUE(second.empty());
  EXPECT_EQ(6, first.size());
  EXPECT_EQ(1, first.front());
  EXPECT_EQ(6, first.back());
}

TEST(ListTest, Reverse) {
  list<int> l{1, 2, 3};
  l.reverse();
  EXPECT_EQ(3, l.front());
  EXPECT_EQ(1, l.back());
}

TEST(ListTest, Unique) {
  list<int> l{1, 2, 2, 3};
  l.unique();
  EXPECT_EQ(3, l.size());
  EXPECT_EQ(1, l.front());
  EXPECT_EQ(3, l.back());
}

TEST(ListTest, Sort) {
  list<int> l{3, 1, 2};
  l.sort();
  EXPECT_EQ(1, l.front());
  EXPECT_EQ(3, l.back());
}

// PART II
using namespace s21;
TEST(Constructor, Default) {
  s21::list<double> l;
  EXPECT_EQ(0, l.size());
  EXPECT_EQ(l.begin(), nullptr);
}

TEST(Constructor, With_parameter) {
  s21::list<double> l1(5);
  EXPECT_EQ(l1.size(), 5);
}

TEST(Constructor, Initializer_list) {
  std::list<int> l1 = {1, 2, 3, 4, 5};
  s21::list<int> l2 = {1, 2, 3, 4, 5};
  EXPECT_EQ(l1.front(), l2.front());
  EXPECT_EQ(l1.back(), l2.back());
  EXPECT_EQ(l1.size(), l2.size());
}

TEST(Constructor, Copy) {
  s21::list<int> l2 = {1, 2, 3, 4, 5};
  s21::list<int> l1(l2);
  EXPECT_EQ(l1.front(), l2.front());
  EXPECT_EQ(l1.back(), l2.back());
  EXPECT_EQ(l1.size(), l2.size());
}

TEST(Constructor, Move) {
  s21::list<int> l2 = {1, 2, 3, 4, 5};
  s21::list<int> l1 = std::move(l2);
  EXPECT_EQ(1, l1.front());
  EXPECT_EQ(5, l1.back());
  EXPECT_EQ(0, l2.size());
}

TEST(list_element, front_and_back) {
  std::list<double> l1 = {1.366, 2, 3};
  s21::list<double> l2 = {1.366, 2, 3};
  EXPECT_EQ(l1.front(), l2.front());
  EXPECT_EQ(l1.back(), l2.back());
}

TEST(list_modifier, Clear) {
  std::list<int> l1 = {1, 2, 3, 4, 5};
  s21::list<int> l2 = {1, 2, 3, 4, 5};
  l1.clear();
  l2.clear();
  EXPECT_EQ(l1.size(), l2.size());
  EXPECT_EQ(l2.size(), 0);
}

TEST(list_modifier, empty) {
  std::list<int> l1 = {1, 2, 3, 4, 5};
  s21::list<int> l2 = {1, 2, 3, 4, 5};
  EXPECT_EQ(l1.empty(), l2.empty());
}

TEST(list_count, size) {
  std::list<int> l1 = {1, 2, 3, 4, 5};
  s21::list<int> l2 = {1, 2, 3, 4, 5};
  EXPECT_EQ(l1.size(), l2.size());
}

TEST(list_iterator, Begin) {
  std::list<int> l1 = {1, 2, 3, 4, 5};
  s21::list<int> l2 = {1, 2, 3, 4, 5};
  auto iter1 = l1.begin();
  auto iter2 = l2.begin();
  EXPECT_EQ(*iter1, *iter2);
}

TEST(list_iterator, End) {
  std::list<int> l1 = {1, 2, 3, 4, 5};
  s21::list<int> l2 = {1, 2, 3, 4, 5};
  auto iter1 = l1.end();
  auto iter2 = l2.end();
  EXPECT_EQ(*iter1, *iter2);
}

TEST(list_modifier, Push_back) {
  std::list<int> l1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::list<int> l2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  l1.push_back(11);
  l2.push_back(11);
  EXPECT_EQ(l1.back(), l2.back());
  EXPECT_EQ(l1.size(), l2.size());

  std::list<int> l3;
  s21::list<int> l4;
  l3.push_back(11);
  l4.push_back(11);
  EXPECT_EQ(l3.back(), l4.back());
  EXPECT_EQ(l3.size(), l4.size());
}

TEST(list_modifier, Push_front) {
  std::list<int> l1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::list<int> l2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  l1.push_front(11);
  l2.push_front(11);
  EXPECT_EQ(l1.front(), l2.front());
  EXPECT_EQ(l1.size(), l2.size());

  std::list<int> l3;
  s21::list<int> l4;
  l3.push_front(11);
  l4.push_front(11);
  EXPECT_EQ(l3.front(), l4.front());
  EXPECT_EQ(l3.size(), l4.size());
}

TEST(list_modifier, insert) {
  std::list<int> l1 = {1, 2, 3, 4, 5};
  s21::list<int> l2 = {1, 2, 3, 4, 5};
  l1.insert(l1.begin(), 7);
  l2.insert(l2.begin(), 7);
  EXPECT_EQ(l1.front(), l2.front());
  EXPECT_EQ(l1.size(), l2.size());
}

TEST(list_modifier, pop_back) {
  std::list<int> l1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::list<int> l2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  l1.pop_back();
  l2.pop_back();
  EXPECT_EQ(l1.back(), l2.back());
  EXPECT_EQ(l1.size(), l2.size());
}

TEST(list_modifier, pop_front) {
  std::list<int> l1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::list<int> l2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  l1.pop_front();
  l2.pop_front();
  EXPECT_EQ(l1.front(), l2.front());
  EXPECT_EQ(l1.size(), l2.size());
}

TEST(list_modifier, erase) {
  std::list<int> l1 = {1, 2, 3, 4, 5};
  s21::list<int> l2 = {1, 2, 3, 4, 5};
  l1.erase(l1.begin());
  l2.erase(l2.begin());
  EXPECT_EQ(l1.front(), l2.front());
  EXPECT_EQ(l1.size(), l2.size());
}

TEST(list_modifier, swap) {
  std::list<int> a1 = {1, 2, 3};
  std::list<int> a2 = {3, 4, 5, 6};
  a1.swap(a2);
  s21::list<int> b1 = {1, 2, 3};
  s21::list<int> b2 = {3, 4, 5, 6};
  b1.swap(b2);

  EXPECT_EQ(a1.front(), b1.front());
  EXPECT_EQ(a1.back(), b1.back());
  EXPECT_EQ(a1.size(), b1.size());
}

TEST(list_modifier, merge) {
  std::list<int> a1 = {1, 2, 3};
  std::list<int> a2 = {3, 4, 5, 6};
  a1.merge(a2);
  s21::list<int> b1 = {1, 2, 3};
  s21::list<int> b2 = {3, 4, 5, 6};
  b1.merge(b2);

  EXPECT_EQ(a1.front(), b1.front());
  EXPECT_EQ(a1.back(), b1.back());
  EXPECT_EQ(a1.size(), b1.size());
}

TEST(list_modifier, splice) {
  std::list<int> a1 = {1, 2, 3};
  std::list<int> a2 = {3, 4, 5, 6};
  a1.splice(a1.begin(), a2);

  s21::list<int> b1 = {1, 2, 3};
  s21::list<int> b2 = {3, 4, 5, 6};
  b1.splice(b1.begin(), b2);

  EXPECT_EQ(a1.front(), b1.front());
  EXPECT_EQ(a1.back(), b1.back());
  EXPECT_EQ(a1.size(), b1.size());
}

TEST(list_modifier, reverce) {
  std::list<int> l1 = {1, 2, 3, 4, 5};
  s21::list<int> l2 = {1, 2, 3, 4, 5};
  l1.reverse();
  l2.reverse();
  EXPECT_EQ(l1.front(), l2.front());
  EXPECT_EQ(l1.back(), l2.back());
  EXPECT_EQ(l1.size(), l2.size());
}

TEST(list_modifier, unique) {
  std::list<int> l1 = {1, 2, 3, 4, 5};
  s21::list<int> l2 = {1, 2, 3, 4, 5};
  l1.unique();
  l2.unique();
  EXPECT_EQ(l1.front(), l2.front());
  EXPECT_EQ(l1.back(), l2.back());
  EXPECT_EQ(l1.size(), l2.size());
}

TEST(list_modifier, sort) {
  std::list<int> l1 = {1, 2, 3, 4, 5};
  s21::list<int> l2 = {1, 2, 3, 4, 5};
  l1.sort();
  l2.sort();
  EXPECT_EQ(l1.front(), l2.front());
  EXPECT_EQ(l1.back(), l2.back());
  EXPECT_EQ(l1.size(), l2.size());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}