#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
struct Node
{
    T value;
    Node *left{nullptr}, *right{nullptr}, *parent{nullptr};

    Node(T value) : value(value) {}

    Node(T value, Node<T> *left, Node<T> *right) : value(value), left(left), right(right) {
      left->parent = right->parent = this;
    }

    // traverse the node and its children preorder
    // and put all the results into `result`
    void preorder_traversal(std::vector<Node<T>*>& result)
    {
        result.push_back(this); // pre-order
        if (this->left)
            this->left->preorder_traversal(result);

        //result.push_back(this); //in order

        if (this->right)
            this->right->preorder_traversal(result);
        
        //result.push_back(this); //post order
        
    }

};


int main()
{
    Node<int> *root = new Node<int>{
        1, new Node<int>{2, new Node<int>{4}, new Node<int>{7}} ,
        new Node<int>{3, new Node<int>{5}, new Node<int>{6}}
    };

    std::vector<Node<int>*> result;

    root -> preorder_traversal(result);

    for (auto n : result)
    {
        std::cout << n->value << "  ";
    }

    std::cout << "\n\n";
    // Node<int> two{2};
    // Node<int> three{3};
    // one.left = &two;
    // one.right = &three;
};