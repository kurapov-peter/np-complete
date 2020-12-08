#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <list>
namespace knight_tour
{
  class board;
  class field;
  bool validate_moves(std::list<field> moves, int max_letter, int max_num);
  std::list<field> solve_simple(board& b, field start_pos);
  std::list<field> list_available_kight_moves(const board& b, field current_pos, const std::list<field>& already_checked);

    class field
    {
      std::tuple<int, int> f;
      public:
      field(int letter, int number):
        f({letter, number}){}
      int get_letter() const
      {
        return std::get<0>(f);
      }
      int get_num() const
      {
        return std::get<1>(f);
      }
      friend bool operator==(const field& lhs, const field& rhs)
      {
        return (lhs.get_letter() == rhs.get_letter()) && (lhs.get_num() == rhs.get_num());
      }
    };
    class board
    {
      std::vector<std::vector<bool>> b;
      int max_letter = 0;
      int max_num = 0;
      public:
      board(int _max_letter, int _max_num):
      b(std::vector<std::vector<bool>>(_max_letter, std::vector<bool>(_max_num, 0))),
      max_letter(_max_letter), max_num(_max_num){};

      int get_max_letter() const
      {
        return max_letter;
      }
      int get_max_num() const
      {
        return max_num;
      }
      void dump_board() const{
        for(int i = 0; i< max_num; ++i)
        {
          for(int j = 0; j< max_letter;++j)
            std::cout << b[j][i]<< " ";// no cache friend
          std::cout << "\n";
        }
      }
      bool check_board() const{
        if(std::all_of(b.begin(), b.end(), [](const std::vector<bool>& v)
              {
              return std::all_of(v.begin(), v.end(), [](const bool& field)
                  {
                  return field == true;
                  });
              }
              ))
          return true;
        return false;
      }
      bool operator()(int let, int num) const
      {
        return b[let][num];
      }
      void operator()(int let, int num, bool write)
      {
        b[let][num] = write;
      }
    };
};
