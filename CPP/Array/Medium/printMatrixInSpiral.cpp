#include "./../../stdc++.h"
using namespace std;
/**
 * @brief Given a 2D array, print it in spiral form.
 * 
 * @param matrix 
 * @return vector<int> 
 */
vector<int> printSpirally(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<int> ans;

    if (m == 0)
        return ans;

    vector<vector<bool>> seen(m, vector<bool>(n, false));
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};

    int x = 0, y = 0, di = 0;
    for (int i = 0; i < m * n; i++)
    {
        ans.push_back(matrix[x][y]);

        seen[x][y] = true;
        int newX = x + dr[di];
        int newY = y + dc[di];

        if (0 <= newX && newX < m && 0 <= newY && newY < n && !seen[newX][newY])
        {
            x = newX;
            y = newY;
        }
        else
        {
            di = (di + 1) % 4;
            x += dr[di];
            y += dc[di];
        }
    }
    return ans;
}
/*Driver code.*/
int main()
{
    /*10 15 20 25 30
      35 40 45 50 55
      60 65 70 75 80
      85 90 95 100 105*/
    vector<vector<int>> matrix;
    int num = 10;

    for (int i = 0; i < 5; i++)
    {
        vector<int> v1;

        for (int j = 0; j < 5; j++)
        {
            v1.push_back(num);
            num += 5;
        }

        matrix.push_back(v1);
    }
    cout<<"Input matrix :: "<<endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl<< "Travelling matrix spirally :: "<<endl;
    for (int x : printSpirally(matrix))
    {
        cout << x << " ";
    }
    return 0;
}