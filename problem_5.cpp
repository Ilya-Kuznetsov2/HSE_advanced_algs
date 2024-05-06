#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional> 
 

struct hash {

  size_t operator()(const std::vector<long double>& triag) const {

    size_t h1 = std::hash<long double>{}(triag[0]);
    size_t h2 = std::hash<long double>{}(triag[1]);
    size_t h3 = std::hash<long double>{}(triag[2]);

    return h1 ^ (h2 << 1) ^ (h3 << 2);
  }

};

using map = std::unordered_map<std::vector<long double>, int, hash>;


int main() {

  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int count;
  std::cin>>count;

  map classes_of_triag = map();
  classes_of_triag.reserve(count);
  classes_of_triag.max_load_factor(0.3);

  long double side_a, side_b, side_c;
  std::vector<std::vector<long double>> all_triangles;

  for (int number_triag = 0; number_triag < count; ++number_triag) {

    all_triangles.push_back({});

    std::cin >> side_a >> side_b >> side_c;
    std::vector<long double> triag = {side_a, side_b, side_c};
    std::sort(begin(triag), end(triag));
    for (int side = 0; side < 3; ++side) {
      triag[side] = triag[side] / triag[2];
    }
    ++classes_of_triag[triag];

  }
  std::cout<<classes_of_triag.size();
  return 0;
}