#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

class Vertex {
public:
    int prior;
    int edges_to;
    std::vector<int> edges;
    Vertex() {
        this->edges = std::vector<int>{};
        this->prior = -1;
        this->edges_to = 0;
    } 
};

void DfsPriors(std::vector<Vertex>& graph, int number_of_vertex, \
std::vector<bool>& visited, std::stack<int>& priors_stack) {
    visited[number_of_vertex] = true;
    size_t len = graph[number_of_vertex].edges.size();
    for (size_t edge = 0; edge < len; ++edge) {
        if (!visited[graph[number_of_vertex].edges[edge]]) {
            DfsPriors(graph, graph[number_of_vertex].edges[edge], \
            visited, priors_stack);
        }
    }
    priors_stack.push(number_of_vertex);
}

void TransposeDfs(std::vector<Vertex>& graph, \
int number_of_vertex, std::vector<int>& components_of_vertexes, \
int& number_of_component, std::vector<int>& volume_of_component, \
std::vector<bool>& is_out_component) {
    components_of_vertexes[number_of_vertex] = number_of_component;
    ++(volume_of_component[number_of_component]);
    size_t len = graph[number_of_vertex].edges.size();
    for (size_t edge = 0; edge < len; ++edge) {
        if (components_of_vertexes[graph[number_of_vertex].edges[edge]] == -1) {
            TransposeDfs(graph, graph[number_of_vertex].edges[edge], \
            components_of_vertexes, number_of_component, volume_of_component, \
            is_out_component);
        }
        else if (components_of_vertexes[graph[number_of_vertex].edges[edge]] \
        != number_of_component) {
            is_out_component[number_of_component] = false;
        }
    }
}

void Kosaraju(std::vector<Vertex>& graph, \
std::vector<Vertex>& transpose_graph, int count_of_vertex, \
std::vector<int>& components_of_vertexes) {
    int number_of_component = 0;
    std::vector<int> volume_of_component;
    std::vector<bool> is_out_component;
    std::vector<bool> visited(count_of_vertex, false);
    std::stack<int> priors_stack;
    for (int number_of_vertex = 0; number_of_vertex \
    < count_of_vertex; ++number_of_vertex) {
        if (!visited[number_of_vertex]) {
            DfsPriors(graph, number_of_vertex, visited, priors_stack);
        }
    }
    size_t len = priors_stack.size();

    for (size_t number_of_vertex = 0; number_of_vertex < len; ++number_of_vertex) {
        int vertex = priors_stack.top();
        priors_stack.pop();
        if (components_of_vertexes[vertex] == -1) {
            volume_of_component.push_back(0);
            is_out_component.push_back(true);
            TransposeDfs(transpose_graph, vertex, \
            components_of_vertexes, number_of_component, volume_of_component, is_out_component);
            ++number_of_component;
        }
    }
    int min_vol = 1000000;
    for (int comp = 0; comp < number_of_component; ++comp) {
        
    //    std::cout << volume_of_component[comp] << "  " << is_out_component[comp] << '\n';

        if (is_out_component[comp]) {
            if (min_vol > volume_of_component[comp]) {
                min_vol = volume_of_component[comp];
            }
        }
    }

    if (min_vol == 1000000) {
        std::cout << 1;
    } else {
        std::cout << count_of_vertex - ( min_vol - 1 );
    }
}

int main() { 


    std::ios_base::sync_with_stdio(false);
    int count_of_vertex, count_of_edges;
    std::cin >> count_of_vertex >> count_of_edges;
    std::vector<Vertex> graph(count_of_vertex, Vertex());
    std::vector<Vertex> transpose_graph(count_of_vertex, Vertex());
    int from_vertex, to_vertex, orientation;
    for (int number_of_edge = 0; number_of_edge < count_of_edges; ++number_of_edge) {
        std::cin >> from_vertex >> to_vertex >> orientation;
        --from_vertex;
        --to_vertex;
        if (orientation == 1) {
            graph[from_vertex].edges.push_back(to_vertex);
            ++graph[to_vertex].edges_to;
            transpose_graph[to_vertex].edges.push_back(from_vertex);
        } else if (orientation == 2) {
            graph[to_vertex].edges.push_back(from_vertex);
            ++graph[from_vertex].edges_to;
            transpose_graph[from_vertex].edges.push_back(to_vertex);
        }
    }
    std::stack<int> priors_stack;
    
    std::vector<bool> visited(count_of_vertex, false);
    std::vector<int> components_of_vertexes(count_of_vertex, -1);
    Kosaraju(graph, transpose_graph, count_of_vertex, components_of_vertexes);

    return 0;
}
