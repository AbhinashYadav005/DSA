from collections import deque

# Define graph properly
graph = {}
graph["you"] = ["alice", "bob", "clarie"]
graph["bob"] = ["anuj", "peggy"]
graph["alice"] = ["peggy"]
graph["clarie"] = ["thom", "jonny"]
graph["anuj"] = []
graph["peggy"] = []
graph["thom"] = []
graph["jonny"] = []

# Check if a person is a seller (name ends with 'm')
def person_is_seller(name):
    return name[-1] == 'e'

# BFS
def search(name):
    search_queue = deque()
    search_queue += graph[name]
    searched = set()   # keep track of visited nodes
    while search_queue:
        person = search_queue.popleft()
        if person not in searched:
            if person_is_seller(person):
                print(person + " is a mango seller!")
                return True
            else:
                search_queue += graph.get(person, [])  # safe lookup
                searched.add(person)
    return False

# Run search
search("you")