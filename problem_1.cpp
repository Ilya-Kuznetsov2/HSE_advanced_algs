#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <queue>

uint32_t ppow(uint32_t x, uint32_t n) {
    uint32_t res = 1;
    for (uint32_t i = 0; i < n; ++i) {
        res *= x;
    }
    return res;
}

int32_t swap_bit(uint32_t digit, uint32_t first_pos, uint32_t second_pos) {
    uint32_t res;
    res = digit ^ (1u << first_pos);
    res = res ^ (1u << second_pos);
    return res;
}

void get_positions(int height, int width, std::vector<std::vector<int>>& pos) {
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            if (col < width - 1) {
                std::vector<int> tmp_1 {row * width + col, row * width + (col + 1)};
                pos.push_back(tmp_1);
            }
            if (row < height - 1) {

                std::vector<int> tmp_2 {row * width + col, (row + 1) * width + col};
                pos.push_back(tmp_2);
            }
        }
    }
}

void search(std::vector<bool>& visited, std::queue<uint32_t>& start_stack, \
            uint32_t first_finish, uint32_t second_finish, uint32_t& step, \
            bool& is_true, uint32_t& n, uint32_t& m, std::vector<uint32_t>& used_steps, \
             std::vector<std::vector<int>>& pos) {
    size_t len = start_stack.size();
    uint32_t swap_digit_tmp;
    if (len == 0) {
        is_true = false;
        return;
    }
    for (size_t vertex = 0; vertex < len; ++vertex) {
        uint32_t elem = start_stack.front();
        start_stack.pop();
        if ((elem == first_finish) || (elem == second_finish)) {
            is_true = true;
            return;
        } else {
            for (uint32_t next_step = used_steps[elem]; \
            next_step < ( n - 1 ) * m + ( m - 1 ) * n; ++next_step) {
                swap_digit_tmp = \
                swap_bit(elem, pos[next_step][0], pos[next_step][1]);
                if (!visited[swap_digit_tmp]) {
                        start_stack.push(swap_digit_tmp);
                        used_steps[swap_digit_tmp] = next_step + 1;
                        visited[swap_digit_tmp] = true;
                }
            }
        }
    }

    step++;
    search(visited, start_stack, first_finish, second_finish, step, is_true, n, m, used_steps, pos);
}



int main() {


    uint32_t n, m;
    std::cin >> n >> m;
    std::vector<std::string> desk;
    std::string str;
    uint32_t start = 0;
    uint32_t first_finish = 0;
    uint32_t second_finish = 0;

    for (uint32_t row = 0; row < n; ++row) {
        for (uint32_t col = 0; col < m; ++col) {
            if ((col % 2 == 0 && row % 2 == 0) || (col % 2 == 1 && row % 2 == 1)) {
                first_finish = first_finish * 2;
                second_finish = second_finish * 2 + 1;
            } else {
                first_finish = first_finish * 2 + 1;
                second_finish = second_finish * 2;
            }
        }
    }

    for (uint32_t row = 0; row < n; ++row) {
        std::cin >> str;
        desk.push_back(str);

        for (uint32_t col = 0; col < m; ++col) {
            if (str[col] == '0') {
                start = start * 2;
            } else {
                start = start * 2 + 1;
            }
        }
    }

    std::vector<bool> visited (pow(2, m * n), false);
    std::vector<uint32_t> used_steps (pow(2, m * n), 0);
    std::vector<std::vector<int>> pos;
    get_positions(n, m, pos);
    visited[start] = true;
    std::queue<uint32_t> start_queue;
    start_queue.push(start);
    uint32_t step = 0;
    bool is_true = false;
    search(visited, start_queue, first_finish, second_finish, step, is_true, n, m, used_steps, pos);
    if (is_true) {
        std::cout << step << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
    return 0;
}
