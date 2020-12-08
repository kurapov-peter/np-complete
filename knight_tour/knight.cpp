#include "knight.hpp"

#include <cassert>
namespace knight_tour
{
bool validate_moves(std::list<field> moves, int max_letter, int max_num)
{
  board f(max_letter, max_num);
  if(moves.size() < max_letter * max_num)// too small
  {
    return false;
  
  }
  // true if can move
  auto check_field = [&f](int letter, int number)
  {
    return f(letter, number);
  };
  for(field next : moves)
  {
    int letter = next.get_letter();
    int num = next.get_num();
    if(check_field(letter, num))
    {
      return false;
    }
    f(letter, num, true);
  }
  return true;
}

std::list<field> list_available_kight_moves(const board& b, field current_pos, const std::list<field>& already_checked)
{
  int max_letter = b.get_max_letter();
  int max_num = b.get_max_num();
  
  constexpr int d1 = 2;
  constexpr int d2 = 1;

  int pos_letter = current_pos.get_letter();
  int pos_num = current_pos.get_num();
  
  std::list<field> to_check;
  auto check_field = [max_letter, max_num, &b](int letter, int number)
  {
    if(letter < 0 || number < 0)
      return false;
    if(letter >= max_letter || number >= max_num)
      return false;
    return !b(letter, number);// falso - not gone here 
  };
  if(check_field(pos_letter + d1, pos_num + d2))
    to_check.push_back({pos_letter + d1, pos_num + d2});
  if(check_field(pos_letter - d1, pos_num + d2))
    to_check.push_back({pos_letter - d1, pos_num + d2});
  if(check_field(pos_letter + d1, pos_num - d2))
    to_check.push_back({pos_letter + d1, pos_num - d2});
  if(check_field(pos_letter - d1, pos_num - d2))
    to_check.push_back({pos_letter - d1, pos_num - d2});

  if(check_field(pos_letter + d2, pos_num + d1))
    to_check.push_back({pos_letter + d2, pos_num + d1});
  if(check_field(pos_letter - d2, pos_num + d1))
    to_check.push_back({pos_letter - d2, pos_num + d1});
  if(check_field(pos_letter + d2, pos_num - d1))
    to_check.push_back({pos_letter + d2, pos_num - d1});
  if(check_field(pos_letter - d2, pos_num - d1))
    to_check.push_back({pos_letter - d2, pos_num - d1});

  for(field to_erase : already_checked)
    to_check.remove(to_erase);
  return to_check;
}

void dump_movs(const std::list<field>& moves, std::string addition = "")
{
  for(field f : moves)
  {
    std::cout<< addition << "{"<<f.get_letter()<<","<< f.get_num()<< "} ";
  }
  std::cout << "\n";
}
void dump_list(const std::list<std::list<field>>& moves)
{
  std::cout << "----\n";
  for(std::list<field> lf : moves)
  {
    dump_movs(lf, "\t");
  }

  std::cout << "----\n";
}

std::list<field> solve_simple(board& b, field start_pos)
{
  int max_letter = b.get_max_letter();
  int max_num = b.get_max_num();

  std::list<field> path;
  field current_pos = start_pos;
  path.push_back(current_pos);
  b(current_pos.get_letter(), current_pos.get_num(), true);
  // path.size() + 1 always
  std::list<std::list<field>> already_visited = {std::list<field>{}, std::list<field>{}};
  while(!b.check_board())
  {
    std::list<field> available_moves = list_available_kight_moves(b, current_pos, already_visited.back());
    if(!available_moves.empty())
    {// we HAVE mov available
      field mov = *available_moves.begin();
      int letter = mov.get_letter();
      int num = mov.get_num();
      b(letter, num, true);
      path.push_back(mov);
      if(path.size() == already_visited.size())
      {
        std::list<field> new_visited;
        already_visited.push_back(new_visited);
      }
      // update mov
      current_pos = path.back();
      assert((path.size()+1) == already_visited.size());
      continue;
    } else// we do not have mov available, one mov back
    {
      field prev = path.back();
      int letter = prev.get_letter();
      int number = prev.get_num();
      b(letter, number, false);
      if(already_visited.size() == (path.size() + 1) )// back() of already visited is prev step available
      {
        path.pop_back();
        already_visited.pop_back();
        already_visited.back().push_back(prev);
      }else if (already_visited.size() == (path.size() + 2))
      {// more than one step back
        path.pop_back();
        already_visited.pop_back();// remove one set
        already_visited.back().push_back(prev);
      } else
      {
        assert(false && "logic error");
      }
      current_pos = path.back();
      continue;
    }
  }
  return path;
}
}
