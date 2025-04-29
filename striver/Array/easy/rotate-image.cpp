// Optimal Solution is to take transpose of a matrix and then reverse elements in each row

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int row = matrix.size(), col = matrix[0].size();
        for (int i{}; i < row; i++)
        {
            for (int j{i}; j < col; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i{}; i < row; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
