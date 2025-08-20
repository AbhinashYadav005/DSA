from queue import PriorityQueue

G = {
    's': {'t': 10, 'y': 5},
    't': {'y': 2, 'x': 1},
    'x': {'z': 6},
    'y': {'x': 9, 't': 3, 'z': 2},
    'z': {'x': 6, 's': 7}
}

parent = {}
rank = {}

def MAKE_SET(G):
    for v in G.keys():
        parent[v] = v
        rank[v] = 0

def FIND(v):
    if parent[v] != v:
        parent[v] = FIND(parent[v])  # Path compression
    return parent[v]

def UNION(u, v):
    root_u, root_v = FIND(u), FIND(v)
    if root_u != root_v:
        if rank[root_u] < rank[root_v]:
            parent[root_u] = root_v
        elif rank[root_u] > rank[root_v]:
            parent[root_v] = root_u
        else:
            parent[root_v] = root_u
            rank[root_u] += 1


def BUILD_PRIORITY_QUEUE(G):
    edges = set()
    PQ = PriorityQueue()
    for u in G:
        for v, w in G[u].items():
            if (v, u) not in edges:
                PQ.put((w, u, v))
                edges.add((u, v))
    return PQ


def KRUSKAL(G):
    MAKE_SET(G)
    PQ = BUILD_PRIORITY_QUEUE(G)
    MST = []
    total_cost = 0
    
    while not PQ.empty() and len(MST) < len(G) - 1:
        w, u, v = PQ.get()
        if FIND(u) != FIND(v):  # if no cycle
            UNION(u, v)
            MST.append((u, v, w))
            total_cost += w
    
    return MST, total_cost


MST, total_cost = KRUSKAL(G)

print("Edges in MST:", MST)
print("Total cost of MST:", total_cost)
