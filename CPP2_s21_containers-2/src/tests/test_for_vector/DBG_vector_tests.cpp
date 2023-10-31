#include <gtest/gtest.h>

#include <vector>

#include "/home/a/21/CPP_branch/containers/s21_containers/Предварительное/src/headers/s21_vector.h"
#include "gtest/gtest.h"

using namespace s21;

TEST(VectorTest, DefaultConstructor) {
  vector<int> v;
  EXPECT_EQ(v.size(), 0);
  EXPECT_EQ(v.capacity(), 0);
  EXPECT_TRUE(v.empty());
}

TEST(VectorTest, SizeConstructor) {
  const size_t n = 5;
  vector<int> v(n);
  //  v.DBG_Printer("size of 5");
  EXPECT_EQ(v.size(), n);
  EXPECT_GE(v.capacity(), n);  // capacity не меньше, чем n
  EXPECT_FALSE(v.empty());

  for (size_t i = 0; i < n; ++i) {
    EXPECT_EQ(v[i], 0);  // все элементы должны быть равны 0
  }
}

TEST(VectorTest, InitializerListConstructor) {
  vector<int> v{1, 2, 3};
  EXPECT_EQ(v.size(), 3);
  EXPECT_GE(v.capacity(), 3);  // capacity не меньше, чем 3
  EXPECT_FALSE(v.empty());
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], 3);
}

TEST(VectorTest, CopyConstructor) {
  vector<int> v1{1, 2, 3};
  vector<int> v2(v1);
  EXPECT_EQ(v2.size(), 3);
  EXPECT_GE(v2.capacity(), 3);  // capacity не меньше, чем 3
  EXPECT_FALSE(v2.empty());
  EXPECT_EQ(v2[0], 1);
  EXPECT_EQ(v2[1], 2);
  EXPECT_EQ(v2[2], 3);
}

TEST(VectorTest, MoveConstructor) {
  vector<int> v1{1, 2, 3};
  const int* data_ptr = v1.data();
  vector<int> v2(std::move(v1));
  EXPECT_EQ(v2.size(), 3);
  EXPECT_GE(v2.capacity(), 3);  // capacity не меньше, чем 3
  EXPECT_FALSE(v2.empty());
  EXPECT_EQ(v2[0], 1);
  EXPECT_EQ(v2[1], 2);
  EXPECT_EQ(v2[2], 3);
  EXPECT_EQ(v1.size(), 0);
  EXPECT_EQ(v1.capacity(), 0);
  EXPECT_EQ(v1.data(), nullptr);
  EXPECT_EQ(v1.begin(), v1.end());
  EXPECT_EQ(v1.cbegin(), v1.cend());
  EXPECT_EQ(data_ptr, v2.data());  // данные должны быть перемещены
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  // ::testing::GTEST_FLAG(filter) = "*InsertOrAssign*";

  return RUN_ALL_TESTS();
}