#include <iostream>
#include <vector>
#include <sstream>
 
int find_director(int worker, std::vector<int>& directors) {

    if ( worker == directors[worker] ) {
        return worker;
    } else {
        int res = find_director(directors[worker], directors);
        directors[worker] = res;
        return res;
    }

}

int main() {

    std::ios_base::sync_with_stdio(false);

    int count_workers, count_requests;
    std::cin >> count_workers >> count_requests;

    std::vector<int> directors;

    for (int worker = 0; worker < count_workers; ++worker) {
        directors.push_back(worker);
    }

    std::string str;
    std::getline(std::cin, str);

    for (int num_request = 0; num_request < count_requests; ++num_request) {

        std::vector<int> request;
        std::getline(std::cin, str);
        std::istringstream ss(str);
        int symb;
        while (ss >> symb) {
            request.push_back(symb);
        }

        if ( request.size() == 1 ) {

            --request[0];
            std::cout << find_director(request[0], directors) + 1 << '\n';

        } else {

            int first_worker = request[0] - 1;
            int second_worker = request[1] - 1;

            int first_director = find_director(first_worker, directors);
            int second_director = find_director(second_worker, directors);

            if (first_director != second_director && \
            second_worker == second_director) {

                directors[second_worker] = first_worker;
                std::cout << 1 << '\n';

            }

            else {
                std::cout << 0 << '\n';
            }
        }
    }

    return 0;
}