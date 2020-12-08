#pragma once
#include <algorithm>
#include <cassert>
#include <iostream>
#include <list>
#include <tuple>
#include <vector>
namespace knight_tour {
class board;
class field;
bool validate_moves(std::list<field> moves, int max_letter, int max_num);

std::list<field> list_available_kight_moves(
    const board& b, field current_pos, const std::list<field>& already_checked);

field chooseForce(const std::list<field>& available, const board& b);
field chooseWarnsdorff(const std::list<field>& available, const board& b);

class field {
  std::tuple<int, int> f;

 public:
  field(int letter, int number) : f({letter, number}) {}
  int get_letter() const { return std::get<0>(f); }
  int get_num() const { return std::get<1>(f); }
  friend bool operator==(const field& lhs, const field& rhs) {
    return (lhs.get_letter() == rhs.get_letter()) &&
           (lhs.get_num() == rhs.get_num());
  }
};
class board {
  std::vector<std::vector<bool>> b;
  int max_letter = 0;
  int max_num = 0;

 public:
  board(int _max_letter, int _max_num)
      : b(std::vector<std::vector<bool>>(_max_letter,
                                         std::vector<bool>(_max_num, 0))),
        max_letter(_max_letter),
        max_num(_max_num){};

  int get_max_letter() const { return max_letter; }
  int get_max_num() const { return max_num; }
  void dump_board() const {
    for (int i = 0; i < max_num; ++i) {
      for (int j = 0; j < max_letter; ++j)
        std::cout << b[j][i] << " ";  // no cache friend
      std::cout << "\n";
    }
  }
  bool check_board() const {
    if (std::all_of(b.begin(), b.end(), [](const std::vector<bool>& v) {
          return std::all_of(v.begin(), v.end(),
                             [](const bool& field) { return field == true; });
        }))
      return true;
    return false;
  }
  bool operator()(int let, int num) const { return b[let][num]; }
  void operator()(int let, int num, bool write) { b[let][num] = write; }
};
using chooseFunc = field (*)(const std::list<field>&, const board&);
template <chooseFunc F>
std::list<field> solve_template(board& b, field start_pos) {
  int max_letter = b.get_max_letter();
  int max_num = b.get_max_num();

  std::list<field> path;
  field current_pos = start_pos;
  path.push_back(current_pos);
  b(current_pos.get_letter(), current_pos.get_num(), true);
  // path.size() + 1 always
  std::list<std::list<field>> already_visited = {std::list<field>{},
                                                 std::list<field>{}};
  while (!b.check_board()) {
    std::list<field> available_moves =
        list_available_kight_moves(b, current_pos, already_visited.back());
    if (!available_moves.empty()) {  // we HAVE mov available
      field mov = F(available_moves, b);
      int letter = mov.get_letter();
      int num = mov.get_num();
      b(letter, num, true);
      path.push_back(mov);
      if (path.size() == already_visited.size()) {
        std::list<field> new_visited;
        already_visited.push_back(new_visited);
      }
      // update mov
      current_pos = path.back();
      assert((path.size() + 1) == already_visited.size());
      continue;
    } else  // we do not have mov available, one mov back
    {
      field prev = path.back();
      int letter = prev.get_letter();
      int number = prev.get_num();
      b(letter, number, false);
      if (already_visited.size() ==
          (path.size() +
           1))  // back() of already visited is prev step available
      {
        path.pop_back();
        already_visited.pop_back();
        already_visited.back().push_back(prev);
      } else if (already_visited.size() ==
                 (path.size() + 2)) {  // more than one step back
        path.pop_back();
        already_visited.pop_back();  // remove one set
        already_visited.back().push_back(prev);
      } else {
        assert(false && "logic error");
      }
      current_pos = path.back();
      continue;
    }
  }
  return path;
}
};  // namespace knight_tour
