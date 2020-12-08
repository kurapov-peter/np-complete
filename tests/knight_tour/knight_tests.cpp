#include "gtest/gtest.h"
#include "../../knight_tour/knight.hpp"
TEST(init, testInit)
{
  ASSERT_EQ(10, 10);
}
using namespace knight_tour;

TEST(field, a4)
{
  int letter = 0;
  int num = 3;
  field f(letter, num);
  ASSERT_EQ(letter, field(letter, 0).get_letter());
  ASSERT_EQ(letter, f.get_letter());
  ASSERT_EQ(num, f.get_num());
}
TEST(field, b8)
{
  int letter = 1;
  int num = 7;
  field f(letter, num);
  ASSERT_EQ(letter, field(letter, 0).get_letter());
  ASSERT_EQ(letter, f.get_letter());
  ASSERT_EQ(num, f.get_num());
}
TEST(field, c1)
{
  int letter = 2;
  int num = 0;
  field f(letter, num);
  ASSERT_EQ(letter, field(letter, 0).get_letter());
  ASSERT_EQ(letter, f.get_letter());
  ASSERT_EQ(num, f.get_num());
}
TEST(field, operator_eq)
{
  int letter = 2;
  int num = 0;
  int num2 = 10;
  field f1(letter, num);
  field f2(letter, num);
  field f3(letter, num2);
  ASSERT_TRUE(f1 == f2);
  ASSERT_FALSE(f1==f3);
}
TEST(board, letter_number)
{
  int max_letter = 10;
  int max_num = 50;
  board b(max_letter, max_num);
  ASSERT_EQ(b.get_max_letter(), max_letter);
  ASSERT_EQ(b.get_max_num(), max_num);
}
TEST(board, check_board)
{
  int max_letter = 10;
  int max_num = 50;
  board b(max_letter, max_num);
  ASSERT_FALSE(b.check_board());
  for(int i = 0; i < max_letter; ++i)
  {
    ASSERT_FALSE(b.check_board());
    for(int j = 0; j< max_num; ++j)
    {
      b(i,j, true);
    }
  }
  ASSERT_TRUE(b.check_board());
}
TEST(list_moves, clean_board)
{
  int max_letter = 8;
  int max_num = 8;
  board b(max_letter, max_num);
  std::list<field> empty;
  std::list<field> first_check = {{2,1}, {1,2}};
  ASSERT_EQ(first_check, list_available_kight_moves(b, {0,0}, empty));
  ASSERT_EQ(empty, list_available_kight_moves(b, {0,0}, first_check));

  std::list<field> second_check = {{2,3}, {2,1}, {1, 4}, {1, 0}};
  ASSERT_EQ(second_check, list_available_kight_moves(b, {0,2}, empty));
  ASSERT_EQ(empty, list_available_kight_moves(b, {0,2}, second_check));
  std::list<field> second_check2 = {{2,3}, {1, 4}, {1, 0}};
  ASSERT_EQ(second_check2, list_available_kight_moves(b, {0,2}, first_check));

  std::list<field> third_check ={{5,3}, {5,1}, {6,4}, {6,0} };
  ASSERT_EQ(third_check, list_available_kight_moves(b, {7,2}, empty));
  ASSERT_EQ(empty, list_available_kight_moves(b, {7,2}, third_check));


  board b5(5, 5);
  std::list<field> fouth_check = {{3,1}};
  std::list<field> four_visited = {{0,0}, {2,1}, {4,2}, {2,3}, {4,4}, {3,2}, {1,3}, {3,4}, {2,2}, {4,3}};
  for(field v : four_visited)
    b5(v.get_letter(), v.get_num(), true);
  std::list<field> four_already_looked = {{2,4}};
  ASSERT_EQ(fouth_check, list_available_kight_moves(b5, {4,3}, four_already_looked));
}
TEST(validate_moves, moves)
{
  int max_letter = 5;
  int max_num = 5;
  std::list<field> right_path = {{0,0}, {1,2}, {0,4}, {2,3}, {4,4},
                                {3,2}, {4,0}, {2,1}, {0,2}, {1,4},
                                {3,3}, {4,1}, {2,0}, {0,1}, {1,3},
                                {3,4}, {4,2}, {3,0}, {1,1}, {0,3},
                                {2,4}, {4,3}, {3,1}, {1,0}, {2,2}};
  ASSERT_TRUE(validate_moves(right_path, max_letter, max_num));
  std::list<field> double_path = {{0,0}, {1,2}, {0,4}, {2,3}, {4,4},
                                {3,2}, {4,0}, {2,1}, {0,2}, {1,4},
                                {3,3}, {4,1}, {2,0}, {0,1}, {1,3},
                                {3,4}, {4,2}, {3,1}, {1,1}, {0,3},
                                {2,4}, {4,3}, {3,1}, {1,0}, {2,2}};
  ASSERT_FALSE(validate_moves(double_path, max_letter, max_num));
  std::list<field> long_path = {{0,0}, {1,2}, {0,4}, {2,3}, {4,4},
                                {3,2}, {4,0}, {2,1}, {0,2}, {1,4},
                                {3,3}, {4,1}, {2,0}, {0,1}, {1,3},
                                {3,4}, {4,2}, {3,0}, {1,1}, {0,3},
                                {2,4}, {4,3}, {3,1}, {1,0}, {2,2},
                                {0,0}};
  ASSERT_FALSE(validate_moves(long_path, max_letter, max_num));
  std::list<field> short_path = {{0,0}, {1,2}, {0,4}, {2,3}, {4,4},
                                {3,2}, {4,0}, {2,1}, {0,2}, {1,4},
                                {3,3}, {4,1}, {2,0}, {0,1}, {1,3},
                                {3,4}, {4,2}, {3,0}, {1,1}, {0,3},
                                {2,4}, {4,3}, {3,1}, {1,0}};
  ASSERT_FALSE(validate_moves(short_path, max_letter, max_num));
}
TEST(get_solution, solve_simple5)
{
  int max_letter = 5;
  int max_num = 5;
  board b(max_letter, max_num);
  ASSERT_TRUE(validate_moves(solve_simple(b, {0,0}), max_letter, max_num));
}
TEST(get_solution, solve_simple10)
{
  int max_letter = 10;
  int max_num = 10;
  board b(max_letter, max_num);
  ASSERT_TRUE(validate_moves(solve_simple(b, {0,0}), max_letter, max_num));
}


