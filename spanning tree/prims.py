
G = {
    's': {'t': 10, 'y': 5},
    't': {'y': 2, 'x': 1},
    'x': {'z': 6},
    'y': {'x': 9, 't': 3, 'z': 2},
    'z': {'x': 6, 's': 7}
}

def prim_algorithm(G, start):
    
    cost = {v: float("inf") for v in G}  # Minimum cost to connect each vertex
    parent = {v: None for v in G}        # Store parent in MST
    cost[start] = 0

    in_MST = set()
    MST = []
    total_cost = 0

    
    while len(in_MST) < len(G):
        # Find vertex with minimum cost not in MST
        u = None
        min_cost = float("inf")
        for v in G:
            if v not in in_MST and cost[v] < min_cost:
                min_cost = cost[v]
                u = v

        
        in_MST.add(u)
        if parent[u] is not None:
            MST.append((parent[u], u, cost[u]))
            total_cost += cost[u]

        
        for v, w in G[u].items():
            if v not in in_MST and w < cost[v]:
                cost[v] = w
                parent[v] = u

    return MST, total_cost


start_vertex = 's'
mst_edges, mst_cost = prim_algorithm(G, start_vertex)

print("Edges in MST:", mst_edges)
print("Total cost of MST:", mst_cost)