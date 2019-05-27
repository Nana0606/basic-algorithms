#include <iostream>
#include <vector>
#include <set>
using namespace std;

/**
 * 本题借助一个set即可，主要思想是如果含义重复元素，则加入元素的set的大小应该等于计数的数目。
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> row = {{}, {}, {}, {}, {}, {}, {}, {}, {}};   //存储每一行的内容
        vector<set<char>> column = {{}, {}, {}, {}, {}, {}, {}, {}, {}};   //存储每一列的内容
        vector<vector<set<char>>> sub_boxes = {{{}, {}, {}}, {{}, {}, {}}, {{}, {}, {}}};   //存储每个子3*3的内容。
        int row_number[9] = {0};  //负责记录每一行的数字的数目
        int column_number[9] = {0};
        int sub_boxes_number[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
        for (int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if (board[i][j] >= '1' and board[i][j] <= '9'){
                    row[i].insert(board[i][j]);
                    row_number[i] ++;
                    column[j].insert(board[i][j]);
                    column_number[j] ++;
                    sub_boxes[i/3][j/3].insert(board[i][j]);
                    sub_boxes_number[i/3][j/3] ++;
                    if (row[i].size() < row_number[i] || column[j].size() < column_number[j] || sub_boxes[i/3][j/3].size() < sub_boxes_number[i/3][j/3]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> board = {
            {'.','.','.','.','5','.','.','1','.'},
            {'.','4','.','3','.','.','.','.','.'},
            {'.','.','.','.','.','3','.','.','1'},
            {'8','.','.','.','.','.','.','2','.'},
            {'.','.','2','.','7','.','.','.','.'},
            {'.','1','5','.','.','.','.','.','.'},
            {'.','.','.','.','.','2','.','.','.'},
            {'.','2','.','9','.','.','.','.','.'},
            {'.','.','4','.','.','.','.','.','.'}
    };

    Solution solution;
    bool res = solution.isValidSudoku(board);
    cout << res << endl;
    return 0;
}