#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

void read_input(char *fp, std::vector<int> &l, std::vector<int> &r) {
  std::ifstream ifs(fp);
  int il, ir;
  while (ifs >> il >> ir) {
    l.push_back(il);
    r.push_back(ir);
  }
}

int p1(std::vector<int> l, std::vector<int> r) {
  std::sort(l.begin(), l.end());
  std::sort(r.begin(), r.end());
  int res{};
  for (size_t i = 0; i < l.size(); i++)
    res += (l[i] < r[i] ? r[i] - l[i] : l[i] - r[i]);
  return res;
}

int p2(std::vector<int> &l, std::vector<int> &r) {
  std::unordered_map<int, int> r_count;
  for (int n : r)
    r_count[n] += 1;

  int res{};
  for (int n : l)
    res += (n * r_count[n]);

  return res;
}

int main(int argc, char *argv[]) {
  std::vector<int> l{}, r{};
  read_input(argv[1], l, r);

  std::cout << "Part 1: " << p1(l, r) << "\n";
  std::cout << "Part 2: " << p2(l, r) << "\n";
}
