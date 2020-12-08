#include "knight.hpp"

#include <cassert>
namespace knight_tour {
bool validate_moves(std::list<field> moves, int max_letter, int max_num) {
  board f(max_letter, max_num);
  if (moves.size() < max_letter * max_num)  // too small
  {
    return false;
  }
  // true if can move
  auto check_field = [&f](int letter, int number) { return f(letter, number); };
  for (field next : moves) {
    int letter = next.get_letter();
    int num = next.get_num();
    if (check_field(letter, num)) {
      return false;
    }
    f(letter, num, true);
  }
  return true;
}

std::list<field> list_available_kight_moves(
    const board& b, field current_pos,
    const std::list<field>& already_checked) {
  int max_letter = b.get_max_letter();
  int max_num = b.get_max_num();

  constexpr int d1 = 2;
  constexpr int d2 = 1;

  int pos_letter = current_pos.get_letter();
  int pos_num = current_pos.get_num();

  std::list<field> to_check;
  auto check_field = [max_letter, max_num, &b](int letter, int number) {
    if (letter < 0 || number < 0) return false;
    if (letter >= max_letter || number >= max_num) return false;
    return !b(letter, number);  // falso - not gone here
  };
  if (check_field(pos_letter + d1, pos_num + d2))
    to_check.push_back({pos_letter + d1, pos_num + d2});
  if (check_field(pos_letter - d1, pos_num + d2))
    to_check.push_back({pos_letter - d1, pos_num + d2});
  if (check_field(pos_letter + d1, pos_num - d2))
    to_check.push_back({pos_letter + d1, pos_num - d2});
  if (check_field(pos_letter - d1, pos_num - d2))
    to_check.push_back({pos_letter - d1, pos_num - d2});

  if (check_field(pos_letter + d2, pos_num + d1))
    to_check.push_back({pos_letter + d2, pos_num + d1});
  if (check_field(pos_letter - d2, pos_num + d1))
    to_check.push_back({pos_letter - d2, pos_num + d1});
  if (check_field(pos_letter + d2, pos_num - d1))
    to_check.push_back({pos_letter + d2, pos_num - d1});
  if (check_field(pos_letter - d2, pos_num - d1))
    to_check.push_back({pos_letter - d2, pos_num - d1});

  for (field to_erase : already_checked) to_check.remove(to_erase);
  return to_check;
}

void dump_movs(const std::list<field>& moves, std::string addition = "") {
  for (field f : moves) {
    std::cout << addition << "{" << f.get_letter() << "," << f.get_num()
              << "} ";
  }
  std::cout << "\n";
}
void dump_list(const std::list<std::list<field>>& moves) {
  std::cout << "----\n";
  for (std::list<field> lf : moves) {
    dump_movs(lf, "\t");
  }

  std::cout << "----\n";
}

void dump_status(const board& b, const std::list<field>& fields,
                 const std::list<std::list<field>>& already_visited,
                 const std::list<field>& available) {
  std::cout << "--start--\n";
  dump_movs(fields);
  b.dump_board();
  dump_list(already_visited);
  dump_movs(available);
  std::cout << "--end--\n";
}

field chooseForce(const std::list<field>& available, const board& b) {
  return *available.begin();
};

field chooseWarnsdorff(const std::list<field>& available, const board& b) {
  int min_size = 10;
  field to_ret = *available.begin();
  std::list<field> empty = {};
  for (const field& f : available) {
    std::list<field> next_step = list_available_kight_moves(b, f, empty);
    if (next_step.size() < min_size) {
      min_size = next_step.size();
      to_ret = f;
    }
  }
  return to_ret;
};
}  // namespace knight_tour
