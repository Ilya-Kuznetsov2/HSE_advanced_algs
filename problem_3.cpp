#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <iomanip>

double dist(uint64_t first_x, uint64_t first_y, uint64_t second_x, uint64_t second_y) {
    double dist = sqrtl(static_cast<long double>( (second_x-first_x) * (second_x-first_x) \
    + (second_y-first_y) * (second_y-first_y) ));
    return dist;
}

void check_connectivity(std::vector<bool>& visited, \
    std::queue<uint64_t>& start_queue, std::vector<std::vector<double>>& edges, \
    double const dist, int16_t& count_of_vertexes, int16_t& count_of_visited, bool& answer) {
    size_t len = start_queue.size();
    if (len == 0) {
        if (count_of_visited == count_of_vertexes) {
            answer = true;
            return;
        } else {
            answer = false;
            return;
        }
    }
    for (size_t index_of_vertex = 0; index_of_vertex < len; ++index_of_vertex) {
        uint64_t vertex = start_queue.front();
        start_queue.pop();
        for (size_t index_of_edge = 0; \
        index_of_edge < static_cast<size_t>(count_of_vertexes); ++index_of_edge) {
                if ((!(visited[index_of_edge])) && edges[vertex][index_of_edge] <= dist) {
                    start_queue.push(index_of_edge);
                    visited[index_of_edge] = true;
                    ++count_of_visited;
                }
        }
    }
    check_connectivity(visited, start_queue, edges, \
    dist, count_of_vertexes, count_of_visited, answer);
}

void find_dist(double const min, double const max, \
    std::vector<std::vector<double>>& edges, \
    int16_t& count_of_vertexes, double& res) {
    double dist = min + (max-min)/2;
    std::vector<bool> visited (count_of_vertexes, false);
    std::queue<uint64_t> start_queue;
    start_queue.push(0);
    int16_t count_of_visited = 0;
    bool answer = false;
    check_connectivity(visited, start_queue, edges, dist+0.0000001, \
    count_of_vertexes, count_of_visited, answer);
    if (answer) {
        if ((max - min) / 2 < 0.000001) {
            res = (min+max)/2;
            return;
        } else {
            find_dist(min, min + (max-min)/2, edges, count_of_vertexes, res);
        }
    }
    else
        find_dist(min+(max-min)/2, max, edges, count_of_vertexes, res);
    return;
}


class Vertex{
public:
    uint64_t x;
    uint64_t y;
    Vertex (uint64_t x, uint64_t y) {
        this->x = x;
        this->y = y;
    }
};

int main() {


    int16_t count_of_vertexes;
    std::cin >> count_of_vertexes;
    std::vector<Vertex> vertexes;
    std::vector<std::vector<double>> edges;
    uint64_t temp_x, temp_y;
    for ( int i = 0; i < count_of_vertexes; ++i ) {
        std::cin >> temp_x >> temp_y;
        vertexes.push_back(Vertex(temp_x, temp_y));
    }
 
    double min_dist = 0;
    double max_dist = 0;
    for (int vert_from_ind = 0; vert_from_ind < count_of_vertexes; ++vert_from_ind) {
        std::vector<double> edge;
        for (int vert_to_ind = 0; vert_to_ind < count_of_vertexes; ++vert_to_ind) {
            double temp_dist = dist(vertexes[vert_from_ind].x, \
            vertexes[vert_from_ind].y, vertexes[vert_to_ind].x, vertexes[vert_to_ind].y);
            if (min_dist > temp_dist)
                min_dist = temp_dist;
            if (max_dist < temp_dist)
                max_dist = temp_dist;
            edge.push_back(temp_dist);
        }
        edges.push_back(edge);
    }

    
    double res = 0;
    find_dist(min_dist, max_dist, edges, count_of_vertexes, res);
    std::cout << std::fixed;
    std::cout << std::setprecision(5);
    std::cout << res <<"\n";
    return 0;
}
