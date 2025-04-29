class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
        {
            return {}; // Return an empty vector if the matrix is empty
        }

        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0, left = 0, bottom = m - 1, right = n - 1;

        while (top <= bottom && left <= right)
        {
            // Traverse right
            for (int i = left; i <= right; i++)
            {
                res.push_back(matrix[top][i]);
            }
            top++;

            // Traverse down
            for (int i = top; i <= bottom; i++)
            {
                res.push_back(matrix[i][right]);
            }
            right--;

            // Traverse left (if not already traversed)
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Traverse up (if not already traversed)
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return res;
    }
};