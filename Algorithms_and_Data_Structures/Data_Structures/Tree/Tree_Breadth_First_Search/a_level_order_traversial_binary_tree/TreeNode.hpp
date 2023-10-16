#pragma once

template <class T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(const T data) : data(data), left(nullptr), right(nullptr)
    {
    }
};
