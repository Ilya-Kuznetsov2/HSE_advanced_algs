#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>

int BFS(std::vector<int>& graph, std::queue<int> next_nodes, \
std::queue<int> states, int out_x, int out_y, int& count_rows, \
int& count_columns, std::vector<int>& path, int& final_state) {

    int path_size = 0;
    int next_node;

    while ( !next_nodes.empty() ) {

        std::size_t lim = next_nodes.size();

        for (std::size_t num_node = 0; num_node < lim; \
        ++num_node) {       

            int state = states.front();
            states.pop();
            int node = next_nodes.front();
            next_nodes.pop();
            int pos = node / 8;
          //  std::cout<<pos<<'\n';
          //  std::cout<<node<<'\n';
            if ( node >= ( out_x * count_columns + out_y ) * 8 && \
            node < ( out_x * count_columns + out_y ) * 8 + 8) {
                final_state = state;
                return path_size;
            }

            switch (state)
            {

            case 0: {

                if ( (pos + 1) % count_columns != 0 ) {
                    
                    next_node = node + 8;
                    if (graph[next_node] > 0) {
                        graph[next_node] = 0;
                        next_nodes.push(next_node);
                        states.push(0);
                        if (path[next_node] == -1) {
                            path[next_node] = node;
                        }
                    }
                }

                if ( (pos - count_columns) >= 0 ) {

                    next_node = node - count_columns * 8 + 7;
                    if (graph[next_node] > 0) {
                        graph[next_node] = 0;
                        next_nodes.push(next_node);
                        states.push(7);
                        if (path[next_node] == -1) {
                            path[next_node] = node;
                        }
                    }
                }

                if ( pos % count_columns != 0 ) {

                    next_node = node - 8 + 2;
                    if (graph[next_node] > 0) {
                        graph[next_node] = 0;
                        next_nodes.push(next_node);
                        states.push(2);
                        if (path[next_node] == -1) {
                            path[next_node] = node;
                        }
                    }
                }

                break;
            }

            case 1: {

                if ( (pos - count_columns) >= 0 ) {
                    next_node = node - count_columns * 8 - state + 3;
                    if (graph[next_node] > 0) {
                        graph[next_node] = 0;
                        next_nodes.push(next_node);
                        states.push(3);
                        if (path[next_node] == -1) {
                            path[next_node] = node;
                        }
                    }
                }

                if ( (pos + 1) % count_columns != 0 ) {
                    next_node = node + 8 - state + 4;
                    if (graph[next_node] > 0) {
                        graph[next_node] = 0;
                        next_nodes.push(next_node);
                        states.push(4);
                        if (path[next_node] == -1) {
                            path[next_node] = node;
                        }
                    }
                }   

                if ( (pos + count_columns) < count_rows * count_columns ) {
                    next_node = node + count_columns * 8 - state + 1;
                    if (graph[next_node] > 0) {
                        graph[next_node] = 0;
                        next_nodes.push(next_node);
                        states.push(1);
                        if (path[next_node] == -1) {
                            path[next_node] = node;
                        }
                    }
                }                

                break;
            }

            case 2: {

                if ( (pos + count_columns) < count_rows * count_columns ) {
                    next_node = node + count_columns * 8 - state + 5;
                    if (graph[next_node] > 0) {
                        graph[next_node] = 0;
                        next_nodes.push(next_node);
                        states.push(5);
                        if (path[next_node] == -1) {
                            path[next_node] = node;
                        }
                    }
                }    

                if ( (pos + 1) % count_columns != 0 ) {
                    next_node = node + 8 - state;
                    if (graph[next_node] > 0) {
                        graph[next_node] = 0;
                        next_nodes.push(next_node);
                        states.push(0);
                        if (path[next_node] == -1) {
                            path[next_node] = node;
                        }
                    }
                }   

                if ( pos % count_columns != 0 ) {
                    next_node = node - 8 - state + 2;
                    if (graph[next_node] > 0) {
                        graph[next_node] = 0;
                        next_nodes.push(next_node);
                        states.push(2);
                        if (path[next_node] == -1) {
                            path[next_node] = node;
                        }
                    }
                }                

                break;
            }

            case 3: {

                if ( pos % count_columns != 0 ) {
                    next_node = node - 8 - state + 6;
                    if (graph[next_node] > 0) {
                        graph[next_node] = 0;
                        next_nodes.push(next_node);
                        states.push(6);
                        if (path[next_node] == -1) {
                            path[next_node] = node;
                        }
                    }
                }      

                if ( (pos + count_columns) < count_rows * count_columns ) {
                    next_node = node + count_columns * 8 - state + 1;
                    if (graph[next_node] > 0) {
                        graph[next_node] = 0;
                        next_nodes.push(next_node);
                        states.push(1);
                        if (path[next_node] == -1) {
                            path[next_node] = node;
                        }
                    }
                }
                
                if ( (pos - count_columns) >= 0 ) {
                    next_node = node - count_columns * 8 - state + 3;
                    if (graph[next_node] > 0) {
                        graph[next_node] = 0;
                        next_nodes.push(next_node);
                        states.push(3);
                        if (path[next_node] == -1) {
                            path[next_node] = node;
                        }
                    }
                }                                    

                break;
            }

            case 4: {

                if ( (pos + count_columns) < count_rows * count_columns ) {
                    next_node = node + count_columns * 8 - state + 1;
                    if (graph[next_node] > 0) {
                        graph[next_node] = 0;
                        next_nodes.push(next_node);
                        states.push(1);
                        if (path[next_node] == -1) {
                            path[next_node] = node;
                        }
                    }
                }

                if ( (pos + 1) % count_columns != 0 ) {
                    next_node = node + 8 - state + 4;
                    if (graph[next_node] > 0) {
                        graph[next_node] = 0;
                        next_nodes.push(next_node);
                        states.push(4);
                        if (path[next_node] == -1) {
                            path[next_node] = node;
                        }
                    }
                }

                if ( pos % count_columns != 0 ) {
                    next_node = node - 8 - state + 6;
                    if (graph[next_node] > 0) {
                        graph[next_node] = 0;
                        next_nodes.push(next_node);
                        states.push(6);
                        if (path[next_node] == -1) {
                            path[next_node] = node;
                        }
                    }
                }                

                break;
            }

            case 5: {

                if ( pos % count_columns != 0 ) {
                    next_node = node - 8 - state + 2;
                    if (graph[next_node] > 0) {
                        graph[next_node] = 0;
                        next_nodes.push(next_node);
                        states.push(2);
                        if (path[next_node] == -1) {
                            path[next_node] = node;
                        }
                    }
                }

                if ( (pos + count_columns) < count_rows * count_columns ) {
                    next_node = node + count_columns * 8 - state + 5;
                    if (graph[next_node] > 0) {
                        graph[next_node] = 0;
                        next_nodes.push(next_node);
                        states.push(5);
                        if (path[next_node] == -1) {
                            path[next_node] = node;
                        }
                    }
                }

                if ( (pos - count_columns) >= 0 ) {
                    next_node = node - count_columns * 8 - state + 7;
                    if (graph[next_node] > 0) {
                        graph[next_node] = 0;
                        next_nodes.push(next_node);
                        states.push(7);
                        if (path[next_node] == -1) {
                            path[next_node] = node;
                        }
                    }
                }   

                break;
            }

            case 6: {

                if ( pos % count_columns != 0 ) {
                    next_node = node - 8 - state + 6;
                    if (graph[next_node] > 0) {
                        graph[next_node] = 0;
                        next_nodes.push(next_node);
                        states.push(6);
                        if (path[next_node] == -1) {
                            path[next_node] = node;
                        }
                    }
                }

                if ( (pos - count_columns) >= 0 ) {
                    next_node = node - count_columns * 8 - state + 3;
                    if (graph[next_node] > 0) {
                        graph[next_node] = 0;
                        next_nodes.push(next_node);
                        states.push(3);
                        if (path[next_node] == -1) {
                            path[next_node] = node;
                        }
                    }
                }

                if ( (pos + 1) % count_columns != 0 ) {
                    next_node = node + 8 - state + 4;
                    if (graph[next_node] > 0) {
                        graph[next_node] = 0;
                        next_nodes.push(next_node);
                        states.push(4);
                        if (path[next_node] == -1) {
                            path[next_node] = node;
                        }
                    }
                }                

                break;
            }

            case 7: {

                if ( (pos + count_columns) < count_rows * count_columns ) {
                    next_node = node + count_columns * 8 - state + 5;
                    if (graph[next_node] > 0) {
                        graph[next_node] = 0;
                        next_nodes.push(next_node);
                        states.push(5);
                        if (path[next_node] == -1) {
                            path[next_node] = node;
                        }
                    }
                }

                if ( (pos + 1) % count_columns != 0 ) {
                    next_node = node + 8 - state;
                    if (graph[next_node] > 0) {
                        graph[next_node] = 0;
                        next_nodes.push(next_node);
                        states.push(0);
                        if (path[next_node] == -1) {
                            path[next_node] = node;
                        }
                    }
                }

                if ( (pos - count_columns) >= 0 ) {
                    next_node = node - count_columns * 8 - state + 7;
                    if (graph[next_node] > 0) {
                        graph[next_node] = 0;
                        next_nodes.push(next_node);
                        states.push(7);
                        if (path[next_node] == -1) {
                            path[next_node] = node;
                        }
                    }
                }   

                break;
            }
            
            default:
                break;
            }
        }
        ++path_size;
    }
    return -1;
}

int main() {

    int count_rows,  count_columns;
    std::cin >> count_rows >> count_columns;


    std::vector<int> nodes(count_rows * count_columns * 8, 0);
    std::string str;

    for (int row_number = 0; row_number < count_rows; ++row_number) {
        str = "";

        std::cin >> str;

        for (int symb = 0; symb < count_columns; ++symb) {

            if (str[symb] == '.') {


                for (int node_class = ( row_number * count_columns + \
                 symb ) * 8 ; node_class < ( row_number * count_columns + \
                 symb ) * 8 + 8; ++node_class) {
                    nodes[node_class] = 1;
                }
            } 
        }
    }

    int in_x, in_y, out_x, out_y;
    std::cin >> in_x >> in_y;
    std::cin >> out_x >> out_y;

    --in_x;
    --in_y;
    --out_x;
    --out_y;

    std::queue<int> next_nodes;
    std::queue<int> states;

    for (int node_class = ( in_x * count_columns + \
        in_y ) * 8; node_class < (in_x * count_columns + \
        in_y ) * 8 + 8; ++node_class) {

        next_nodes.push(node_class);
        states.push(node_class % 8);
        }
    std::vector<int> path(count_rows * count_columns * 8, -1);
    int final_state = 0;
    std::stack<int> final_path;
    int res = BFS(nodes, next_nodes, states, out_x, out_y, \
    count_rows, count_columns, path, final_state);
    std::cout << res <<'\n';
    if ( res != -1 ) {
        int regress = ( out_x * count_columns + out_y ) * 8 + final_state;
        final_path.push(regress / 8);
        while ( (regress / 8) != (in_x * count_columns + in_y) ) {

            regress = path[regress];
            final_path.push(regress / 8);
        }
        
        while (!final_path.empty()) {
            std::cout << final_path.top() / count_columns + 1 << " " << \
            final_path.top() % count_columns + 1 <<'\n';
            final_path.pop();
        }
    } 
    return 0;
}
