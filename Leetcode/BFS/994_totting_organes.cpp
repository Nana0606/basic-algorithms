#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * 主要思想：借助BFS的思想
 * Step1：先将所有坏了句子的横纵坐标存储到一个队列。
 * Step2：依次遍历队列中内容point，如果point周围的节点已经坏了或者走到边缘，则不用操作，否则，将邻居节点置为2，即橘子坏了，并将其加入队列。
 * Step3：当队列为空时，如果新鲜橘子数目为0，则返回高度，否则返回-1。
 * 注意：最后返回的是count-1，这是因为最后一个过程时，产生了很多2，对于这些2还需要进行操作，但是结束时最后这一批2没有生成新的坏橘子，说明前一步骤已经可以结束。
 */

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty() || grid.size() == 0) return 0;
        long rows = grid.size();
        long cols = grid[0].size();
        queue<vector<int>> q;
        int count_fresh = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if (grid[i][j] == 2){
                    int temp[ ] = {i, j};
                    vector<int> temp_v(temp, temp + 2);
                    q.push(temp_v);   //先将第一批坏橘子存储入队列
                }else if(grid[i][j]==1){
                    count_fresh++;
                }

            }
        }
        if(count_fresh == 0) return 0;
        int count = 0;
        int directs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};   //可以被坏橘子感染的范围
        while(!q.empty()){
            ++count;
            long size = q.size();
            for(int i = 0; i < size; i++){
                vector<int> point = q.front();
                q.pop();
                for(int i = 0; i < 4; i++){
                    int x = point[0] + directs[i][0];
                    int y = point[1] + directs[i][1];
                    if (x < 0 || y < 0 || x >= rows || y >= cols || grid[x][y] == 0 || grid[x][y] == 2) continue;
                    grid[x][y] = 2;   //橘子变坏
                    int temp[ ] = {x, y};
                    vector<int> temp_v(temp, temp+2);
                    q.push(temp_v);
                    count_fresh --;
                }
            }
        }
        return count_fresh == 0? count - 1 : -1;

    }
};


int main() {
    Solution solution;
    vector<vector<int>> grid;
    int arr1[] = {2, 1, 1};
    int arr2[] = {1, 1, 0};
    int arr3[] = {0, 1, 1};
    vector<int> grid1(arr1, arr1+3);
    vector<int> grid2(arr2, arr2+3);
    vector<int> grid3(arr3, arr3+3);
    grid.push_back(grid1);
    grid.push_back(grid2);
    grid.push_back(grid3);
    int res = solution.orangesRotting(grid);
    cout << res << endl;
    return 0;
}