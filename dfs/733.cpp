/**
 * An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.
 */

/**
 * 最典型的dfs问题，使用一个二维矩阵来保存已经到达过得位置
 */

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.empty()) return image;
        m_row = image.size();
        m_col = image[0].size();
        m_old_color = image[sr][sc];
        m_new_color = newColor;
        m_walk = vector<vector<int>>(m_row, vector<int>(m_col, 0));
        dfs(image, sr, sc);
        return image;
    }

    int m_row;
    int m_col;
    int m_old_color;
    int m_new_color;
    vector<vector<int>> m_walk;

    void dfs(vector<vector<int>>& image, int i, int j) {
        if(i < 0 || i == m_row || j < 0 || j == m_col) return;
        if(image[i][j] != m_old_color || m_walk[i][j] == 1) return;
        image[i][j] = m_new_color;
        m_walk[i][j] = 1;
        dfs(image, i - 1, j);
        dfs(image, i + 1, j);
        dfs(image, i, j - 1);
        dfs(image, i, j + 1);
    }
};