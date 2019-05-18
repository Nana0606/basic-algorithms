# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019-02-24 18:50

def justify(edges):
    nodes = {}  # key is name, value is color, -1 is red, 1 is white
    for edge in edges:
        if nodes.get(edge[0]):
            if not nodes.get(edge[1]):
                nodes[edge[1]] = nodes[edge[0]] * (-1)
            elif nodes[edge[0]] == nodes[edge[1]]:
                return False
        elif nodes.get(edge[1]):
            if not nodes.get(edge[0]):
                nodes[edge[0]] = nodes[edge[1]] * (-1)
            elif nodes[edge[0]] == nodes[edge[1]]:
                return False
        else:
            nodes[edge[0]] = 1
            nodes[edge[1]] = -1
    return True

if __name__ == '__main__':
    [M, N] = input().split(' ')
    edges = []
    for i in range(0, int(N)):
        [edge_s, edge_e] = input().split(' ')
        edges.append((edge_s, edge_e))
    res = justify(edges)
    print("Yes" if res == True else "No")




