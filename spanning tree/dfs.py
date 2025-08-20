
G = {
    's': ['t', 'y'],
    't': ['y', 'x'],
    'x': ['z'],
    'y': ['x', 't', 'z'],
    'z': ['x', 's']
}

def DFS_iterative(G, start):
    visited = set()       # Keep track of visited nodes
    stack = []            # Use a stack for DFS
    order = []            # To store DFS traversal order

    
    stack.append(start)

    
    while stack:
        u = stack.pop()   # Pop the top vertex
        if u not in visited:
            visited.add(u)
            order.append(u)

            # Push neighbors onto stack (reverse order for consistent traversal)
            for v in reversed(G[u]):
                if v not in visited:
                    stack.append(v)

    return order


start_vertex = 's'
dfs_order = DFS_iterative(G, start_vertex)

print("DFS traversal order:", dfs_order)