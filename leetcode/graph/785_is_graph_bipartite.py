# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019-05-27 09:35

"""
思路：
依次遍历所有的节点，二分图的条件是相邻节点的颜色是不同的，所以我们可以依次对每个节点进行涂色，
然后对于其相邻节点，涂另一种颜色，如果相邻节点颜色相同或者某一个节点需要涂不同的颜色，则返回False
"""

class Solution:
    def isBipartite(self, graph) -> bool:
        color = {}
        def dfs(pos):
            for i in graph[pos]:   # 对节点pos的相邻节点遍历
                if i in color:
                    if color[i] == color[pos]:   # 相邻节点颜色相同
                        return False
                else:
                    color[i] = 1 - color[pos]
                    if not dfs(i):
                        return False
            return True
        for i in range(0, len(graph)):   # 依次遍历每个节点
            if i not in color:
                color[i] = 0   # 对每个节点赋0颜色
                if not dfs(i):
                    return False
        return True


if __name__ == '__main__':
    edges = [[1, 3], [0, 2], [1, 3], [0, 2]]
    solution = Solution()
    result = solution.isBipartite(edges)
    print(result)
