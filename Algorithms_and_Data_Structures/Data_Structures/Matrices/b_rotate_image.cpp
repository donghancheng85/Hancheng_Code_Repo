#include <algorithm>
#include <iostream>
#include <vector>

void RotateImage(std::vector<std::vector<int>> &matrix)
{
    // if not a square matrix, return empty
    for (const auto &vec : matrix)
    {
        if (vec.size() != matrix.size())
            return;
    }

    // use nested loop. Outer loop from row to half of the matrix size
    for (std::size_t row = 0; row < matrix.size() / 2; ++row)
    {
        // inner loop, from row to matrix_size - row - 1
        for (std::size_t col = row; col < matrix.size() - row - 1; ++col)
        {
            // swap the top-left with the top-right, use at for debugging since it has range checking
            std::swap(matrix[row][col], matrix[col].at(matrix.size() - row - 1));
            // swap the top-left with bottom-right
            std::swap(matrix[row][col], matrix.at(matrix.size() - row - 1).at(matrix.size() - col - 1));
            // swap the top-left with bottom-left. Note the index of bottom-left
            std::swap(matrix[row][col], matrix.at(matrix.size() - col - 1)[row]);
        }
    }
}

int main()
{
    std::vector<std::vector<int>> matrix{{10, 1, 14, 11, 14},
                                         {13, 4, 8, 2, 13},
                                         {10, 19, 1, 6, 8},
                                         {20, 10, 8, 2, 12},
                                         {15, 6, 8, 8, 18}};

    RotateImage(matrix);

    for (const auto &rowVec : matrix)
    {
        for (const auto num : rowVec)
            std::cout << num << "\t";
        std::cout << "\n";
    }
}
