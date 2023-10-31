
#include <gtest/gtest.h>

#include "../../headers/s21_vector.h"

using namespace s21;
// Тест конструктора по умолчанию
TEST(MyVectorTest, DefaultConstructor) {
  vector<int> v;
  ASSERT_TRUE(v.empty());
  ASSERT_EQ(0, v.size());
}

// Тест конструктора с размером
TEST(MyVectorTest, SizeConstructor) {
  vector<int> v(5);
  ASSERT_FALSE(v.empty());
  ASSERT_EQ(5, v.size());
  for (int i = 0; i < 5; ++i) {
    ASSERT_EQ(0, v[i]);
  }
}

// Тест инициализации с помощью std::initializer_list
TEST(MyVectorTest, InitializerListConstructor) {
  vector<int> v{1, 2, 3};
  ASSERT_FALSE(v.empty());
  ASSERT_EQ(3, v.size());
  ASSERT_EQ(1, v[0]);
  ASSERT_EQ(2, v[1]);
  ASSERT_EQ(3, v[2]);
}

// Тест копирующего конструктора
TEST(MyVectorTest, CopyConstructor) {
  vector<int> v1{1, 2, 3};
  vector<int> v2(v1);
  ASSERT_EQ(v1.size(), v2.size());
  for (size_t i = 0; i < v1.size(); ++i) {
    ASSERT_EQ(v1[i], v2[i]);
  }
}

// Тест перемещающего конструктора
TEST(MyVectorTest, MoveConstructor) {
  vector<int> v1{1, 2, 3};
  vector<int> v2(std::move(v1));
  ASSERT_EQ(3, v2.size());
  ASSERT_EQ(3, v2[2]);
  ASSERT_TRUE(v1.empty());
}

// Тест оператора присваивания перемещением
TEST(MyVectorTest, MoveAssignmentOperator) {
  vector<int> v1{1, 2, 3};
  vector<int> v2;
  v2 = std::move(v1);
  ASSERT_EQ(3, v2.size());
  ASSERT_EQ(3, v2[2]);
  ASSERT_TRUE(v1.empty());
}

// Тест метода empty()
TEST(MyVectorTest, EmptyMethod) {
  vector<int> v;
  ASSERT_TRUE(v.empty());
  v.push_back(42);
  ASSERT_FALSE(v.empty());
}

// Тест метода size()
TEST(MyVectorTest, SizeMethod) {
  vector<int> v{1, 2, 3};
  ASSERT_EQ(3, v.size());
  v.pop_back();
  ASSERT_EQ(2, v.size());
  v.push_back(4);
  ASSERT_EQ(3, v.size());
}

// Тест метода max_size()
TEST(MyVectorTest, MaxSizeMethod) {
  vector<int> v;

  // В этом примере мы считаем, что размер типа int на вашей платформе равен 4
  // байтам. Если это не так, замените значение 4 на соответствующее значение
  // для вашей платформы.
  ASSERT_LE(v.max_size(),
            std::numeric_limits<std::size_t>::max() / sizeof(int) - 1);
}

// Тест метода reserve()
TEST(MyVectorTest, ReserveMethod) {
  vector<int> v;
  ASSERT_EQ(0, v.capacity());
  v.reserve(100);
  ASSERT_GE(v.capacity(), 100);
}

// Тест метода capacity()
TEST(MyVectorTest, CapacityMethod) {
  vector<int> v{1, 2, 3};
  ASSERT_GE(v.capacity(), 3);
}

// Тест метода shrink_to_fit()
TEST(MyVectorTest, ShrinkToFitMethod) {
  vector<int> v{1, 2, 3};
  v.reserve(100);
  ASSERT_GE(v.capacity(), 100);
  v.shrink_to_fit();
  ASSERT_LE(v.capacity(), 3);
}

// Тест метода at()
TEST(MyVectorTest, AtMethod) {
  vector<int> v{1, 2, 3};
  ASSERT_EQ(2, v.at(1));
  ASSERT_THROW(v.at(5), std::out_of_range);
}

// Тест метода operator[]
TEST(MyVectorTest, OperatorBracket) {
  vector<int> v{1, 2, 3};
  ASSERT_EQ(2, v[1]);
  v[1] = 42;
  ASSERT_EQ(42, v[1]);
}

// Тест метода front()
TEST(MyVectorTest, FrontMethod) {
  vector<int> v{1, 2, 3};
  ASSERT_EQ(1, v.front());
}

// Тест метода back()
TEST(MyVectorTest, BackMethod) {
  vector<int> v{1, 2, 3};
  ASSERT_EQ(3, v.back());
}

// Тест метода data()
TEST(MyVectorTest, DataMethod) {
  vector<int> v{1, 2, 3};
  int* ptr = v.data();
  ASSERT_EQ(1, ptr[0]);
  ASSERT_EQ(2, ptr[1]);
  ASSERT_EQ(3, ptr[2]);
}

// Тест метода begin()
TEST(MyVectorTest, BeginMethod) {
  vector<int> v{1, 2, 3};
  ASSERT_EQ(1, *v.begin());
  *v.begin() = 42;
  ASSERT_EQ(42, *v.begin());
}

// Тест метода end()
TEST(MyVectorTest, EndMethod) {
  vector<int> v{1, 2, 3};
  auto it = v.end();
  --it;
  ASSERT_EQ(3, *it);
}

// Тест метода clear()
TEST(MyVectorTest, ClearMethod) {
  vector<int> v{1, 2, 3};
  ASSERT_FALSE(v.empty());
  v.clear();
  ASSERT_TRUE(v.empty());
}

// Тест метода insert()
TEST(MyVectorTest, InsertMethod) {
  vector<int> v{1, 2, 3};
  auto it = v.insert(v.begin() + 1, 42);
  ASSERT_EQ(4, v.size());
  ASSERT_EQ(42, *it);
  ASSERT_EQ(42, v[1]);
}

// Тест метода erase()
TEST(MyVectorTest, EraseMethod) {
  vector<int> v{1, 2, 3};
  auto it = v.erase(v.begin() + 1);
  ASSERT_EQ(2, v.size());
  ASSERT_EQ(3, v[1]);
  ASSERT_EQ(v.begin() + 1, it);
}

// Тест метода push_back()
TEST(MyVectorTest, PushBackMethod) {
  vector<vector<int>> v;
  v.push_back(vector<int>{1, 2, 3});
  ASSERT_EQ(1, v.size());
  ASSERT_EQ(3, v[0].back());
}

// Тест метода pop_back()
TEST(MyVectorTest, PopBackMethod) {
  vector<int> v{1, 2, 3};
  v.pop_back();
  ASSERT_EQ(2, v.size());
  ASSERT_EQ(2, v.back());
}

// Тест метода swap()
TEST(MyVectorTest, SwapMethod) {
  vector<int> v1{1, 2, 3};
  vector<int> v2{4, 5, 6};
  vector<int> v1_ref = v1;
  vector<int> v2_ref = v2;

  int* ref = v1.data();
  v1.swap(v2);

  // Assert that the sizes of the vectors are still the same.
  ASSERT_EQ(v1.size(), v2_ref.size());
  ASSERT_EQ(v2.size(), v1_ref.size());

  // Assert that the elements of the vectors have been swapped correctly.
  for (size_t i = 0; i < v1.size(); i++) {
    ASSERT_EQ(v1[i], v2_ref[i]);
    ASSERT_EQ(v2[i], v1_ref[i]);
  }

  // Assert that the capacity of the vectors is still the same.
  ASSERT_EQ(v1.capacity(), v1_ref.capacity());
  ASSERT_EQ(v2.capacity(), v2_ref.capacity());

  // Assert that the pointers to the data in the vectors have been swapped.
  ASSERT_EQ(ref, v2.data());
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  //  ::testing::GTEST_FLAG(filter) = "*SwapMethod*";
  return RUN_ALL_TESTS();
}
