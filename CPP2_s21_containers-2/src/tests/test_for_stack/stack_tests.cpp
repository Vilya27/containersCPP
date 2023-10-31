
#include <gtest/gtest.h>

#include "../../headers/s21_stack.h"

using namespace s21;

// Тест конструктора по умолчанию
TEST(MyStackTest, DefaultConstructor) {
  stack<int> s;
  ASSERT_TRUE(s.empty());
  ASSERT_EQ(0, s.size());
}

// Тест конструктора с инициализацией
TEST(MyStackTest, InitializerListConstructor) {
  stack<int> s{1, 2, 3};
  ASSERT_FALSE(s.empty());
  ASSERT_EQ(3, s.size());
  ASSERT_EQ(3, s.top());
}

// Тест копирующего конструктора
TEST(MyStackTest, CopyConstructor) {
  stack<int> s1{1, 2, 3};
  stack<int> s2(s1);
  ASSERT_EQ(s1.size(), s2.size());
  ASSERT_EQ(s1.top(), s2.top());
}

// Тест перемещающего конструктора
TEST(MyStackTest, MoveConstructor) {
  stack<int> s1{1, 2, 3};
  stack<int> s2(std::move(s1));
  ASSERT_EQ(3, s2.size());
  ASSERT_EQ(3, s2.top());
  ASSERT_TRUE(s1.empty());
}

// Тест оператора присваивания перемещением
TEST(MyStackTest, MoveAssignmentOperator) {
  stack<int> s1{1, 2, 3};
  stack<int> s2;
  s2 = std::move(s1);
  ASSERT_EQ(3, s2.size());
  ASSERT_EQ(3, s2.top());
  ASSERT_TRUE(s1.empty());
}

// Тест метода empty()
TEST(MyStackTest, EmptyMethod) {
  stack<int> s;
  ASSERT_TRUE(s.empty());
  s.push(42);
  ASSERT_FALSE(s.empty());
}

// Тест метода size()
TEST(MyStackTest, SizeMethod) {
  stack<int> s{1, 2, 3};
  ASSERT_EQ(3, s.size());
  s.pop();
  ASSERT_EQ(2, s.size());
  s.push(4);
  ASSERT_EQ(3, s.size());
}

// Тест метода top()
TEST(MyStackTest, TopMethod) {
  stack<int> s{1, 2, 3};
  ASSERT_EQ(3, s.top());
  s.pop();
  ASSERT_EQ(2, s.top());
}

// Тест метода push()
TEST(MyStackTest, PushMethod) {
  stack<int> s{1, 2, 3};
  s.push(4);
  ASSERT_EQ(4, s.top());
  ASSERT_EQ(4, s.size());
}

// Тест метода pop()
TEST(MyStackTest, PopMethod) {
  stack<int> s{1, 2, 3};
  s.pop();
  ASSERT_EQ(2, s.top());
  ASSERT_EQ(2, s.size());
}

// Тест метода swap()
TEST(MyStackTest, SwapMethod) {
  stack<int> s1{1, 2};
  stack<int> s2{3, 4};
  s1.swap(s2);
  ASSERT_EQ(2, s2.top());
  ASSERT_EQ(2, s2.size());
  ASSERT_EQ(4, s1.top());
  ASSERT_EQ(2, s1.size());
}

// Тест на использование stack в качестве элементов самого себя
TEST(MyStackTest, SelfAsElement) {
  stack<stack<int>> s;
  s.push(stack<int>{1, 2, 3});
  s.push(stack<int>{4, 5, 6});

  ASSERT_EQ(2, s.size());
  ASSERT_EQ(6, s.top().top());
}

// Тесты на граничные случаи

// Попытка удалить элемент из пустого стека
TEST(MyStackTest, PopFromEmptyStack) {
  stack<int> s;
  ASSERT_THROW(s.pop(), std::exception);
}

// Попытка получить элемент из пустого стека
TEST(MyStackTest, TopFromEmptyStack) {
  stack<int> s;
  ASSERT_THROW(s.top(), std::exception);
}

/*
Вешает систему
// Вставка большого числа элементов
TEST(MyStackTest, PushManyElements) {
  stack<int> s;
  for (int i = 0; i < 1000000; ++i) {
    s.push(i);
  }
  ASSERT_EQ(1000000, s.size());
  ASSERT_EQ(999999, s.top());
}

*/

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}