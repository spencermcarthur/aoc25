#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

void read_input(char *filename, std::vector<int> &l, std::vector<int> &r) {
    std::ifstream ifs(filename);
    int li, ri;
    while (ifs >> li >> ri) {
        l.push_back(li);
        r.push_back(ri);
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
    for (int n : r) r_count[n] += 1;

    int res{};
    for (int n : l) res += (n * r_count[n]);

    return res;
}

int main(int argc, char *argv[]) {
    if (argc != 2) return 1;

    std::vector<int> left{}, right{};
    read_input(argv[1], left, right);

    std::cout << "Part 1: " << p1(left, right) << "\n";
    std::cout << "Part 2: " << p2(left, right) << "\n";
}
