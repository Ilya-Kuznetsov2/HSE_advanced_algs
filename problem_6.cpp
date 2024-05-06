#include <iostream>
#include <vector>

struct Node {
    int member_number;
    Node* left = 0;
    Node* right = 0;
    Node* parent = 0;
    int weight = 0;
    Node(int member_number) {
        this->member_number = member_number;
    }
};

Node* build_tree(int length, int begin) {

    if (length > 0) {
        int number = begin + length / 2;
        Node* root = new Node(number);
        root->left = build_tree(number - begin, begin);
        root->right = build_tree(length - length / 2 - 1, number + 1);
        root->weight = length;
      //  std::cout<<length<<'\n';

        if (root->left != nullptr) {
            root->left->parent = root;
        }

        if (root->right != nullptr) {
            root->right->parent = root;
        }

        return root;
    }
    else {
        return nullptr;
    }
}

void remove(Node* remove_node, int left_flag) {
    // std::cout << "Remove" << remove_node->member_number <<'\n';
    if (left_flag) {

        if (remove_node->left == nullptr && remove_node->right == nullptr) {
            remove_node->parent->left = nullptr;
            delete(remove_node);
            return;
        }

        else if (remove_node->left == nullptr) {
            remove_node->parent->left = remove_node->right;
            remove_node->right->parent = remove_node->parent;
            delete(remove_node);
            return;
        }

        else if (remove_node->right == nullptr) {
            remove_node->parent->left = remove_node->left;
            remove_node->left->parent = remove_node->parent;
            delete(remove_node);
            return;
        }

        Node* search_node = remove_node->right;
        int flag = 0;
        
        while (search_node->left != nullptr) {
            --(search_node->weight);
            flag = 1;
            search_node = search_node->left;
        }
        remove_node->parent->left = search_node;

        if (flag == 1) {

            if (search_node->right == nullptr) {
                search_node->parent->left = nullptr;
            }
            else {
                search_node->parent->left = search_node->right;
                search_node->right->parent = search_node->parent;
            }
            search_node->right = remove_node->right;
            remove_node->right->parent = search_node;

        }
        search_node->parent = remove_node->parent;
        search_node->left = remove_node->left;
        search_node->weight = remove_node->weight;
        remove_node->left->parent = search_node;
        delete(remove_node);
    }

    else {

        if (remove_node->left == nullptr && remove_node->right == nullptr) {
            remove_node->parent->right = nullptr;
            delete(remove_node);
            return;
        }

        if (remove_node->left == nullptr) {
            remove_node->parent->right = remove_node->right;
            remove_node->right->parent = remove_node->parent;
            delete(remove_node);
            return;
        }

        if (remove_node->right == nullptr) {
            remove_node->parent->right = remove_node->left;
            remove_node->left->parent = remove_node->parent;
            delete(remove_node);
            return;
        }

        Node* search_node = remove_node->right;
        int flag = 0;

        while (search_node->left != nullptr) {
            --(search_node->weight);
            search_node = search_node->left;
            flag = 1;
        }
        remove_node->parent->right = search_node;


        if (flag == 1) {

            if (search_node->right == nullptr) {
                search_node->parent->left = nullptr;
            }
            else {
                search_node->parent->left = search_node->right;
                search_node->right->parent = search_node->parent;
            }
            search_node->right = remove_node->right;
            remove_node->right->parent = search_node;

        }

        search_node->parent = remove_node->parent;
        search_node->left = remove_node->left;
        search_node->weight = remove_node->weight;
        remove_node->left->parent = search_node;
        delete(remove_node); 
    }

        return;
}

int pop_index(Node* root, int index) {

    ++index;
    int result = 0;
    int left_flag = 1;
    Node* res_node = root;
    int left_weight;

    while (true) {

        if (res_node->left == nullptr) {
            left_weight = 0;
        }
        else {
            left_weight = res_node->left->weight;
        } 

        --(res_node->weight); 

        if (index == left_weight + 1) {
            break;
        }
        else if (index <= left_weight) {
            res_node = res_node->left;
            left_flag = 1;            
        }
        else {
            index = index - left_weight - 1;
            res_node = res_node->right;
            left_flag = 0;
        }
    }

    result = res_node->member_number;
    remove(res_node, left_flag);
    return result;
}


std::vector<int> find_order(Node* parent, int count_of_members, int drop_number) {

    std::vector<int> result;
    int index = 0;
    while (count_of_members != 0) {

        Node* root = parent->left;
        index = (index + drop_number - 1) % count_of_members;
        result.push_back(pop_index(root, index));
        --count_of_members;

    }

    return result;
}

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int count_of_members, drop_number;

    std::cin >> count_of_members;
    std::cin >> drop_number;

    Node* root = build_tree(count_of_members, 0);
    root->parent = new Node(-1);
    Node* parent = root->parent;
    root->parent->left = root;



    std::vector<int> result = find_order(parent, count_of_members, drop_number);

    for (size_t member = 0; member < result.size(); ++member) {
        std::cout<< result[member] + 1 << " ";
    }

    delete(parent);
    return 0;
}

