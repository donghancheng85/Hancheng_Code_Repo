#include <BinaryTree.hpp>
#include <TreeNode.hpp>
#include <deque>
#include <iostream>
#include <string>

// template<class T>
// class TreeNode {
// public:
//     T data;
//     TreeNode<T>* left;
//     TreeNode<T>* right;

//     TreeNode(const T data) : data(data), left(nullptr), right(nullptr) {}
// };

std::string LevelOrderTraversal(TreeNode<int> *root)
{
    if (root == nullptr)
        return {};

    std::string result{};
    std::deque<TreeNode<int> *> currentQ;
    std::deque<TreeNode<int> *> nextQ;

    currentQ.push_back(root);

    while (!currentQ.empty())
    {
        // de-queue currentQ, push children nodes into nextQ
        while (!currentQ.empty())
        {
            auto node = currentQ.front();
            currentQ.pop_front();
            result += std::to_string(node->data);
            // check if "," is needed
            if (!currentQ.empty())
                result += ", ";

            //push children nodes to the nextQ
            if (node->left)
                nextQ.push_back(node->left);

            if (node->right)
                nextQ.push_back(node->right);
        }

        // one level finished, add ":" to result, and swap currentQ and nextQ
        if (!nextQ.empty())
            result += " : ";
        currentQ.swap(nextQ);
    }


    return result;
}


int main()
{
    std::vector<TreeNode<int> *> listOfNodes{new TreeNode<int>(100),
                                             new TreeNode<int>(50),
                                             new TreeNode<int>(200),
                                             new TreeNode<int>(25),
                                             new TreeNode<int>(75),
                                             new TreeNode<int>(350)};

    BinaryTree<int> Tree(listOfNodes);

    std::cout << LevelOrderTraversal(Tree.root) << "\n\n";
}
