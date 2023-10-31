#include <gtest/gtest.h>

#include "../../headers/s21_queue.h"

using namespace s21;

// Тест конструктора по умолчанию
TEST(MyQueueTest, DefaultConstructor) {
  queue<int> q;
  ASSERT_TRUE(q.empty());
  ASSERT_EQ(0, q.size());
}

// Тест конструктора с инициализацией
TEST(MyQueueTest, InitializerListConstructor) {
  queue<int> q{1, 2, 3};
  ASSERT_FALSE(q.empty());
  ASSERT_EQ(3, q.size());
  ASSERT_EQ(1, q.front());
  ASSERT_EQ(3, q.back());
}

// Тест копирующего конструктора
TEST(MyQueueTest, CopyConstructor) {
  queue<int> q1{1, 2, 3};
  queue<int> q2(q1);
  ASSERT_EQ(q1.size(), q2.size());
  ASSERT_EQ(q1.front(), q2.front());
  ASSERT_EQ(q1.back(), q2.back());
}

// Тест перемещающего конструктора
TEST(MyQueueTest, MoveConstructor) {
  queue<int> q1{1, 2, 3};
  queue<int> q2(std::move(q1));
  ASSERT_EQ(3, q2.size());
  ASSERT_EQ(1, q2.front());
  ASSERT_EQ(3, q2.back());
  ASSERT_TRUE(q1.empty());
}

// Тест оператора присваивания перемещением
TEST(MyQueueTest, MoveAssignmentOperator) {
  queue<int> q1{1, 2, 3};
  queue<int> q2;
  q2 = std::move(q1);
  ASSERT_EQ(3, q2.size());
  ASSERT_EQ(1, q2.front());
  ASSERT_EQ(3, q2.back());
  ASSERT_TRUE(q1.empty());
}

// Тест метода empty()
TEST(MyQueueTest, EmptyMethod) {
  queue<int> q;
  ASSERT_TRUE(q.empty());
  q.push(42);
  ASSERT_FALSE(q.empty());
}

// Тест метода size()
TEST(MyQueueTest, SizeMethod) {
  queue<int> q{1, 2, 3};
  ASSERT_EQ(3, q.size());
  q.pop();
  ASSERT_EQ(2, q.size());
  q.push(4);
  ASSERT_EQ(3, q.size());
}

// Тест метода front()
TEST(MyQueueTest, FrontMethod) {
  queue<int> q{1, 2, 3};
  ASSERT_EQ(1, q.front());
  q.pop();
  ASSERT_EQ(2, q.front());
}

// Тест метода back()
TEST(MyQueueTest, BackMethod) {
  queue<int> q{1, 2, 3};
  ASSERT_EQ(3, q.back());
  q.push(4);
  ASSERT_EQ(4, q.back());
}

// Тест метода push()
TEST(MyQueueTest, PushMethod) {
  queue<int> q{1, 2};
  q.push(3);
  ASSERT_EQ(3, q.back());
  q.push(4);
  ASSERT_EQ(4, q.back());
}

// Тест метода pop()
TEST(MyQueueTest, PopMethod) {
  queue<int> q{1, 2};
  q.pop();
  ASSERT_EQ(2, q.front());
  ASSERT_EQ(1, q.size());
}

// Тест метода swap()
TEST(MyQueueTest, SwapMethod) {
  queue<int> q1{1, 2};
  queue<int> q2{3, 4};
  //  q1.DBG_Printer("Before swap");
  q1.swap(q2);
  //  q1.DBG_Printer("After swap");

  ASSERT_EQ(1, q2.front());
  ASSERT_EQ(3, q1.front());
}

// Тест на использование очереди в качестве элементов самой себя
TEST(MyQueueTest, SelfAsElement) {
  queue<queue<int>> q;
  q.push(queue<int>{1, 2, 3});
  q.push(queue<int>{4, 5, 6});

  ASSERT_EQ(2, q.size());
  ASSERT_EQ(1, q.front().front());
  ASSERT_EQ(6, q.back().back());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
