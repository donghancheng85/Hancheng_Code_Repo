#include <iostream>
#include <TreeNode.hpp>
#include <BinaryTree.hpp>

// template<class T>
// class TreeNode {
// public:
//     T data;
//     TreeNode<T>* left;
//     TreeNode<T>* right;

//     TreeNode(const T data) : data(data), left(nullptr), right(nullptr) {}
// };

TreeNode<int> *FlattenTree(TreeNode<int> *root)
{
    if(root == nullptr)
        return nullptr;

    // init current and last (processed) node to root
    auto current = root;
    auto last = root;

    while(current)
    {
        // find the right most node in the left side of the tree
        // this node is the one adjacent to the current node in the sorted order
        if(current->left)
        {
            last = current->left;
            while(last->right)
                last = last->right;

            // Then move the right side of current node to right of the last
            // the "first" right node of current is the one that is adjacent to last->right
            last->right = current->right;
            current->right = nullptr;

            // move the left side of current to right
            current->right = current->left;
            current->left = nullptr;
        }
        current = current->right;
    }

    return root;
}


int main()
{
    std::vector<TreeNode<int>*> listOfNodes {new TreeNode<int>(3), new TreeNode<int>(2), new TreeNode<int>(17),
                                             new TreeNode<int>(1), new TreeNode<int>(4), new TreeNode<int>(19),
                                             new TreeNode<int>(5)};

    BinaryTree<int> Tree(listOfNodes);

    FlattenTree(Tree.root);
}
