
#include <list>
// #include "../../headers/s21_list.h"
// #include "../../sources/s21_list/s21_list.tpp"
#include "fake/s21_list.h"
#include "fake/s21_list.tpp"

int main() {

    std::list<int> std_list {1, 2, 3, 4, 5};
    s21::list<int> my_list {1, 2, 3, 4, 5};
  
for ( auto const &v : std_list)
        std::cout << v << " ";
std::cout << "\n";
for ( auto const &v : my_list)
        std::cout << v << " ";
std::cout << "\n";


 s21::list<int> test{1,2};
std::cout << test.size();
std::cout << "\n";
test.print();
return 0;
}