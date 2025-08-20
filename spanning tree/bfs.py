from queue import Queue


G = {
    's': ['t', 'y'],
    't': ['y', 'x'],
    'x': ['z'],
    'y': ['x', 't', 'z'],
    'z': ['x', 's']
}

def BFS(G, start):
    visited = set()       # Keep track of visited nodes
    q = Queue()           # Create a queue
    order = []            # To store BFS traversal order

    
    q.put(start)
    visited.add(start)

    
    while not q.empty():
        u = q.get()          # Dequeue a vertex
        order.append(u)

        
        for v in G[u]:
            if v not in visited:
                q.put(v)     # Enqueue unvisited neighbors
                visited.add(v)

    return order


start_vertex = 's'
bfs_order = BFS(G, start_vertex)

print("BFS traversal order:", bfs_order)