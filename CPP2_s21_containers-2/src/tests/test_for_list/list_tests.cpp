#include <gtest/gtest.h>
#include <my_list.h>

TEST(ListTest, DefaultConstructor) {
  my_list<int> l;
  EXPECT_TRUE(l.empty());
  EXPECT_EQ(0, l.size());
}

TEST(ListTest, SizeConstructor) {
  my_list<int> l(5);
  EXPECT_FALSE(l.empty());
  EXPECT_EQ(5, l.size());
}

TEST(ListTest, InitializerListConstructor) {
  my_list<char> l{'a', 'b', 'c'};
  EXPECT_FALSE(l.empty());
  EXPECT_EQ(3, l.size());
}

TEST(ListTest, CopyConstructor) {
  my_list<int> original{1, 2, 3};
  my_list<int> copy(original);
  EXPECT_FALSE(copy.empty());
  EXPECT_EQ(3, copy.size());
  EXPECT_EQ(1, copy.front());
  EXPECT_EQ(3, copy.back());
}

TEST(ListTest, MoveConstructor) {
  my_list<std::string> original{"Hello", "world"};
  my_list<std::string> moved(std::move(original));
  EXPECT_TRUE(original.empty());
  EXPECT_FALSE(moved.empty());
  EXPECT_EQ(2, moved.size());
  EXPECT_EQ("Hello", moved.front());
  EXPECT_EQ("world", moved.back());
}

TEST(ListTest, AssignmentOperator) {
  my_list<int> original{1, 2, 3};
  my_list<int> copy;
  copy = original;
  EXPECT_FALSE(copy.empty());
  EXPECT_EQ(3, copy.size());
  EXPECT_EQ(1, copy.front());
  EXPECT_EQ(3, copy.back());
}

TEST(ListTest, MoveAssignmentOperator) {
  my_list<std::string> original{"Hello", "world"};
  my_list<std::string> moved;
  moved = std::move(original);
  EXPECT_TRUE(original.empty());
  EXPECT_FALSE(moved.empty());
  EXPECT_EQ(2, moved.size());
  EXPECT_EQ("Hello", moved.front());
  EXPECT_EQ("world", moved.back());
}

TEST(ListTest, FrontAndBack) {
  my_list<int> l{5, 10, 15};
  EXPECT_EQ(5, l.front());
  EXPECT_EQ(15, l.back());
}

TEST(ListTest, Iterator) {
  my_list<int> l{1, 2, 3};
  auto it = l.begin();
  EXPECT_EQ(1, *it);
  ++it;
  EXPECT_EQ(2, *it);
  ++it;
  EXPECT_EQ(3, *it);
}

TEST(ListTest, ConstIterator) {
  const my_list<int> l{1, 2, 3};
  auto it = l.begin();
  EXPECT_EQ(1, *it);
  ++it;
  EXPECT_EQ(2, *it);
  ++it;
  EXPECT_EQ(3, *it);
}

TEST(ListTest, Empty) {
  my_list<int> l;
  EXPECT_TRUE(l.empty());
  l.push_back(5);
  EXPECT_FALSE(l.empty());
}

TEST(ListTest, Size) {
  my_list<int> l{1, 2, 3};
  EXPECT_EQ(3, l.size());
  l.push_front(0);
  EXPECT_EQ(4, l.size());
}

TEST(ListTest, Clear) {
  my_list<int> l{1, 2, 3};
  EXPECT_FALSE(l.empty());
  l.clear();
  EXPECT_TRUE(l.empty());
  EXPECT_EQ(0, l.size());
}

TEST(ListTest, Insert) {
  my_list<int> l{1, 3, 4};
  auto it = l.begin();
  ++it;
  l.insert(it, 2);
  EXPECT_EQ(4, l.size());
  EXPECT_EQ(2, *++it);
}

TEST(ListTest, Erase) {
  my_list<int> l{1, 2, 3};
  auto it = l.begin();
  ++it;
  l.erase(it);
  EXPECT_EQ(2, l.size());
  EXPECT_EQ(3, l.back());
}

TEST(ListTest, PushBack) {
  my_list<int> l{1, 2};
  l.push_back(3);
  EXPECT_EQ(3, l.size());
  EXPECT_EQ(3, l.back());
}

TEST(ListTest, PopBack) {
  my_list<int> l{1, 2, 3};
  l.pop_back();
  EXPECT_EQ(2, l.size());
  EXPECT_EQ(2, l.back());
}

TEST(ListTest, PushFront) {
  my_list<int> l{2, 3};
  l.push_front(1);
  EXPECT_EQ(3, l.size());
  EXPECT_EQ(1, l.front());
}

TEST(ListTest, PopFront) {
  my_list<int> l{1, 2, 3};
  l.pop_front();
  EXPECT_EQ(2, l.size());
  EXPECT_EQ(2, l.front());
}

TEST(ListTest, Swap) {
  my_list<int> first{1, 2, 3};
  my_list<int> second{4, 5};
  first.swap(second);
  EXPECT_EQ(2, first.size());
  EXPECT_EQ(4, first.front());
  EXPECT_EQ(5, first.back());
  EXPECT_EQ(3, second.size());
  EXPECT_EQ(1, second.front());
  EXPECT_EQ(3, second.back());
}

TEST(ListTest, Merge) {
  my_list<int> first{1, 3, 5};
  my_list<int> second{2, 4, 6};
  first.merge(second);
  EXPECT_TRUE(second.empty());
  EXPECT_EQ(6, first.size());
  EXPECT_EQ(1, first.front());
  EXPECT_EQ(6, first.back());
}

TEST(ListTest, Splice) {
  my_list<int> first{1, 2, 3};
  my_list<int> second{4, 5};
  auto it = first.begin();
  ++it;
  first.splice(it, second);
  EXPECT_TRUE(second.empty());
  EXPECT_EQ(5, first.size());
  EXPECT_EQ(1, first.front());
  EXPECT_EQ(5, first.back());
}

TEST(ListTest, Reverse) {
  my_list<int> l{1, 2, 3};
  l.reverse();
  EXPECT_EQ(3, l.front());
  EXPECT_EQ(1, l.back());
}

TEST(ListTest, Unique) {
  my_list<int> l{1, 2, 2, 3};
  l.unique();
  EXPECT_EQ(3, l.size());
  EXPECT_EQ(1, l.front());
  EXPECT_EQ(3, l.back());
}

TEST(ListTest, Sort) {
  my_list<int> l{3, 1, 2};
  l.sort();
  EXPECT_EQ(1, l.front());
  EXPECT_EQ(3, l.back());
}

// Дополнительные тесты для списка, элементами которого являются другие списки :

TEST(ListOfListsTest, DefaultConstructor) {
  my_list<my_list<int>> l;
  EXPECT_TRUE(l.empty());
  EXPECT_EQ(0, l.size());
}

TEST(ListOfListsTest, SizeConstructor) {
  my_list<my_list<int>> l(5);
  EXPECT_FALSE(l.empty());
  EXPECT_EQ(5, l.size());
  for (auto &sublist : l) {
    EXPECT_TRUE(sublist.empty());
    EXPECT_EQ(0, sublist.size());
  }
}

TEST(ListOfListsTest, InitializerListConstructor) {
  my_list<my_list<char>> l{{'a', 'b', 'c'}, {'d', 'e'}, {'f'}};
  EXPECT_FALSE(l.empty());
  EXPECT_EQ(3, l.size());
  auto it = l.begin();
  EXPECT_EQ('a', (*it).front());
  ++it;
  EXPECT_EQ('d', (*it).front());
  ++it;
  EXPECT_EQ('f', (*it).front());
}

TEST(ListOfListsTest, CopyConstructor) {
  my_list<my_list<int>> original{{1, 2}, {3}, {}};
  my_list<my_list<int>> copy(original);
  EXPECT_FALSE(copy.empty());
  EXPECT_EQ(3, copy.size());
  auto it = copy.begin();
  EXPECT_EQ(2, (*it).size());
  EXPECT_EQ(1, (*it).front());
  ++it;
  EXPECT_EQ(1, (*it).size());
  EXPECT_EQ(3, (*it).front());
  ++it;
  EXPECT_TRUE((*it).empty());
}

TEST(ListOfListsTest, MoveConstructor) {
  my_list<my_list<std::string>> original{{"Hello", "world"},
                                         {"OpenAI", "GPT-3"}};
  my_list<my_list<std::string>> moved(std::move(original));
  EXPECT_TRUE(original.empty());
  EXPECT_FALSE(moved.empty());
  EXPECT_EQ(2, moved.size());
  auto it = moved.begin();
  EXPECT_EQ("Hello", (*it).front());
  ++it;
  EXPECT_EQ("OpenAI", (*it).front());
}

TEST(ListOfListsTest, AssignmentOperator) {
  my_list<my_list<int>> original{{1, 2}, {3}, {}};
  my_list<my_list<int>> copy;
  copy = original;
  EXPECT_FALSE(copy.empty());
  EXPECT_EQ(3, copy.size());
  auto it = copy.begin();
  EXPECT_EQ(2, (*it).size());
  EXPECT_EQ(1, (*it).front());
  ++it;
  EXPECT_EQ(1, (*it).size());
  EXPECT_EQ(3, (*it).front());
  ++it;
  EXPECT_TRUE((*it).empty());
}

TEST(ListOfListsTest, MoveAssignmentOperator) {
  my_list<my_list<std::string>> original{{"Hello", "world"},
                                         {"OpenAI", "GPT-3"}};
  my_list<my_list<std::string>> moved;
  moved = std::move(original);
  EXPECT_TRUE(original.empty());
  EXPECT_FALSE(moved.empty());
  EXPECT_EQ(2, moved.size());
  auto it = moved.begin();
  EXPECT_EQ("Hello", (*it).front());
  ++it;
  EXPECT_EQ("OpenAI", (*it).front());
}

TEST(ListOfListsTest, FrontAndBack) {
  my_list<my_list<int>> l{{1, 2}, {3}, {}};
  EXPECT_EQ(2, l.front().back());
  EXPECT_TRUE(l.back().empty());
}

TEST(ListOfListsTest, Iterator) {
  my_list<my_list<int>> l{{1, 2}, {3}, {}};
  auto it = l.begin();
  EXPECT_EQ(1, (*it).front());
  EXPECT_EQ(2, (*it).back());
  ++it;
  EXPECT_EQ(3, (*it).front());
  EXPECT_TRUE((*++it).empty());
}

TEST(ListOfListsTest, ConstIterator) {
  const my_list<my_list<int>> l{{1, 2}, {3}, {}};
  auto it = l.begin();
  EXPECT_EQ(1, (*it).front());
  EXPECT_EQ(2, (*it).back());
  ++it;
  EXPECT_EQ(3, (*it).front());
  EXPECT_TRUE((*++it).empty());
}

TEST(ListOfListsTest, Empty) {
  my_list<my_list<int>> l;
  EXPECT_TRUE(l.empty());
  l.push_back({});
  EXPECT_FALSE(l.empty());
}

TEST(ListOfListsTest, Size) {
  my_list<my_list<int>> l{{1, 2}, {3}, {}};
  EXPECT_EQ(3, l.size());
  l.push_front({});
  EXPECT_EQ(4, l.size());
}

TEST(ListOfListsTest, Clear) {
  my_list<my_list<int>> l{{1, 2}, {3}, {}};
  EXPECT_FALSE(l.empty());
  l.clear();
  EXPECT_TRUE(l.empty());
  EXPECT_EQ(0, l.size());
}

TEST(ListOfListsTest, Insert) {
  my_list<my_list<int>> l{{1, 2}, {4}};
  auto it = l.begin();
  ++it;
  l.insert(it, {3});
  EXPECT_EQ(3, (*it).size());
  EXPECT_EQ(3, (*it).front());
}

TEST(ListOfListsTest, Erase) {
  my_list<my_list<int>> l{{1, 2}, {3}};
  auto it = l.begin();
  ++it;
  l.erase(it);
  EXPECT_EQ(1, l.size());
  EXPECT_EQ(1, l.front().front());
  EXPECT_EQ(2, l.front().back());
}

TEST(ListOfListsTest, PushBack) {
  my_list<my_list<int>> l{{1, 2}};
  l.push_back({3});
  EXPECT_EQ(2, l.front().back());
  EXPECT_EQ(3, l.back().front());
}

TEST(ListOfListsTest, PopBack) {
  my_list<my_list<int>> l{{1, 2}, {3}};
  l.pop_back();
  EXPECT_EQ(1, l.size());
  EXPECT_EQ(2, l.front().back());
}

TEST(ListOfListsTest, PushFront) {
  my_list<my_list<int>> l{{2}};
  l.push_front({1});
  EXPECT_EQ(1, l.front().front());
  EXPECT_EQ(2, l.back().front());
}

TEST(ListOfListsTest, PopFront) {
  my_list<my_list<int>> l{{1}, {2}};
  l.pop_front();
  EXPECT_EQ(1, l.size());
  EXPECT_EQ(2, l.front().front());
}

TEST(ListOfListsTest, Swap) {
  my_list<my_list<int>> first{{1, 2}, {3}};
  my_list<my_list<int>> second{{4}};
  first.swap(second);
  EXPECT_EQ(1, first.size());
  EXPECT_EQ(4, first.front().front());
  EXPECT_EQ(1, second.size());
  EXPECT_EQ(1, second.front().front());
}

TEST(ListOfListsTest, Merge) {
  my_list<my_list<int>> first{{1, 3, 5}};
  my_list<my_list<int>> second{{2, 4, 6}};
  first.merge(second);
  EXPECT_TRUE(second.empty());
  EXPECT_EQ(2, first.size());
  EXPECT_EQ(1, first.front().front());
  EXPECT_EQ(6, first.back().back());
}

TEST(ListOfListsTest, Splice) {
  my_list<my_list<int>> first{{1, 2}, {4}};
  my_list<my_list<int>> second{{3}};
  auto it = first.begin();
  ++it;
  first.splice(it, second);
  EXPECT_TRUE(second.empty());
  EXPECT_EQ(2, first.size());
  EXPECT_EQ(1, first.front().front());
  EXPECT_EQ(3, (*++it).front());
}

TEST(ListOfListsTest, Reverse) {
  my_list<my_list<int>> l{{1, 2}, {3}};
  l.reverse();
  EXPECT_EQ(3, l.front().front());
  EXPECT_EQ(1, l.back().back());
}

TEST(ListOfListsTest, Unique) {
  my_list<my_list<int>> l{{1, 2}, {2, 3}};
  l.unique();
  EXPECT_EQ(1, l.size());
  EXPECT_EQ(1, l.front().front());
  EXPECT_EQ(3, l.front().back());
}

TEST(ListOfListsTest, Sort) {
  my_list<my_list<int>> l{{3, 1}, {2}};
  l.sort();
  EXPECT_EQ(2, l.size());
  EXPECT_EQ(1, l.front().front());
  EXPECT_EQ(3, l.back().back());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}