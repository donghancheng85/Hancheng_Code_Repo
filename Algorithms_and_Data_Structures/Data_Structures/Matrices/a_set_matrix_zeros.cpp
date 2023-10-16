#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<std::vector<int>> SetMatrixZeros(std::vector<std::vector<int>>& mat)
{
    /*check the first row and column first*/
    bool frow0 {false};
    bool fcol0 {false};
    // first row
    for (std::size_t i = 0; i < mat[0].size(); ++i)
    {
        if(mat[0][i] == 0)
        {
            frow0 = true;
            break;
        }
    }

    // first column
    for (std::size_t j = 0; j < mat.size(); ++j)
    {
        if(mat[j][0] == 0)
        {
            fcol0 = true;
            break;
        }
    }

    /*scan the whole matrix, except the first row and column*/
    for (std::size_t m = 1; m < mat.size(); ++m)
    {
        for (std::size_t n = 1; n < mat[m].size(); ++n)
        {
            if (mat[m][n] == 0)
            {
                mat[m][0] = 0;
                mat[0][n] = 0;
            }
        }
    }

    /*check every row's first element, if it is 0, set the whole row to 0*/
    for (std::size_t j = 0; j < mat.size(); ++j)
    {
        if(mat[j][0] == 0)
            std::for_each(mat[j].begin(), mat[j].end(), [](int& val){ val = 0; });
    }

    /*check every column's first element, if it is 0, set the whole column to 0*/
    for (std::size_t i = 0; i < mat[0].size(); ++i)
    {
        if(mat[0][i] == 0)
        {
            for (std::size_t j = 1; j < mat.size(); ++j)
                mat[j][i] = 0;
        }
    }

    /*check if frow0 and fcol0 are true*/
    if (frow0)
        std::for_each(mat[0].begin(), mat[0].end(), [](int& val){ val = 0; });

    if (fcol0)
    {
        for (std::size_t i = 0; i < mat.size(); ++i)
            mat[i][0] = 0;
    }

    return mat;
}

int main()
{

}
