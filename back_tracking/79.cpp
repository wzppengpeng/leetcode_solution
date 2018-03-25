/**
 * Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
 */

/**
 * 需要一个相同大小的矩阵来保存当前寻找单词位置是否来过的记录
 * 并且依次从每个位置开始寻找
 */


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty() || word.empty()) return false;
        vector<vector<bool>> walked(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if(helper(board, i, j, word, 0, walked)) return true;
            }
        }
        return false;
    }

    bool helper(const vector<vector<char>>& board, int i, int j, const string& word, int k, vector<vector<bool>>& walked) {
        if(k == word.size()) return true;
        if(i < 0 || i == board.size() || j < 0 || j == board[0].size() ||
            walked[i][j] || board[i][j] != word[k]) return false;
        walked[i][j] = true;
        bool is_find = false;
        is_find |= helper(board, i - 1, j, word, k + 1, walked);
        if(is_find) { walked[i][j] = false; return true; }
        is_find |= helper(board, i + 1, j, word, k + 1, walked);
        if(is_find) { walked[i][j] = false; return true; }
        is_find |= helper(board, i, j - 1, word, k + 1, walked);
        if(is_find) { walked[i][j] = false; return true; }
        is_find |= helper(board, i, j + 1, word, k + 1, walked);
        walked[i][j] = false;
        return is_find;
    }
};