#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * 参考：https://blog.csdn.net/u011732358/article/details/83892681
 * 思路：先利用dfs找到其中的两块岛屿，将其中的一块所有的陆地标记改为2，
然后将另一块岛屿中的所有陆地添加到一个队列进行bfs，对于队列中的每一个陆地判断四周方向，
若遇到标记为2的陆地则代表相连了，若遇到标记为1的陆地，则继续判断，若遇到标记为0的水，
则将该块标记为1并添加到队列中，代表陆地向该方向搭了一块桥，就这样不断bfs，直到其中
某一块岛屿或者桥四周遇到了标记为2的陆地，即代表两座岛屿连通了，这样我们队列元素
更新了几个周期即代表桥长为几。
 */

class Solution {

    struct Point
    {
        int x;
        int y;
    };

public:
    int shortestBridge(vector<vector<int>>& A) {
        bool found = false;
        int createBridge = 0;
        queue<Point> qe;
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        //dfs区分开两个小岛
        for(int i =0; i < A.size(); i++){
            for(int j =0; j<A.size();j++){
                if(!found && A[i][j] == 1){
                    dfs(A, i, j);
                    found = true;
                }
                if(found && A[i][j] ==1){
                    qe.push(Point{i, j});
                }
            }
        }

        //bfs建立桥梁把两个岛屿连接
        while(!qe.empty()){
            long size = qe.size();
            for(long i =0; i<size;i++){
                Point point = qe.front();
                qe.pop();
                for(int k = 0; k < 4;k++){
                    int x = point.x + directions[k][0];
                    int y = point.y + directions[k][1];
                    if(x < 0 || x >= A.size() || y<0 || y>=A.size() || A[x][y]==1){
                        continue;
                    }else if(A[x][y]==2){
                        return createBridge;
                    }else{
                        A[x][y] = 1;
                        qe.push(Point{x, y});
                    }
                }
            }
            createBridge ++;
        }
        return 1;
    }

    //dfs查找小岛，并把这个小岛的所有值都置为2，为了与值为1的小岛区分。
    void dfs(vector<vector<int>> &A, int x, int y){
        if(x < 0 || x >=A.size() || y < 0 || y>=A.size() || A[x][y]==2 || A[x][y] == 0){
            return;
        }
        A[x][y]=2;
        dfs(A, x+1, y);
        dfs(A, x-1, y);
        dfs(A, x, y+1);
        dfs(A, x, y-1);
    }

};

int main() {
    Solution solution;
    vector<vector<int>> a(5);
    a[0] = vector<int>{1, 1, 1, 1, 1};
    a[1] = vector<int>{1, 0, 0, 0, 1};
    a[2] = vector<int>{1, 0, 1, 0, 1};
    a[3] = vector<int>{1, 0, 0, 0, 1};
    a[4] = vector<int>{1, 1, 1, 1, 1};
//    for(int i =0;i <2;i++)
//        for(int j =0; j< 2; j++){
//            cout << a[i][j] << endl;
//        }
    int res = solution.shortestBridge(a);
    cout << res << endl;
    return 0;
}