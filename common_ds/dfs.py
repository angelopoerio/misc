# DFS in python
# Author: Angelo Poerio <angelo.poerio@gmail.com>
from pprint import pprint

def dfs(graph, start, visited=set()):
    visited.add(start)
    for next in graph[start] - visited:
        dfs(graph, next, visited)
    return sorted(visited) 

if __name__ == '__main__':
    graph = {'A': set(['B','E']),
             'B': set(['C']),
             'C': set(['D']),
             'D': set([]),
             'E': set(['K']),
             'K': set(['pippo'])}
    print 'Graph:'
    pprint(graph)
    print 'DFS of the graph starting from the node "A"'
    print dfs(graph,'A') # ['A', 'B', 'C', 'D', 'E', 'K']

