# AVL Tree implementation in Python

class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.height = 1   # initial height


class AVLTree:
    # Get height of a node
    def get_height(self, root):
        if not root:
            return 0
        return root.height

    # Get balance factor
    def get_balance(self, root):
        if not root:
            return 0
        return self.get_height(root.left) - self.get_height(root.right)

    # Right rotation
    def right_rotate(self, y):
        x = y.left
        T2 = x.right

        # Perform rotation
        x.right = y
        y.left = T2

        # Update heights
        y.height = 1 + max(self.get_height(y.left), self.get_height(y.right))
        x.height = 1 + max(self.get_height(x.left), self.get_height(x.right))

        return x

    # Left rotation
    def left_rotate(self, x):
        y = x.right
        T2 = y.left

        # Perform rotation
        y.left = x
        x.right = T2

        # Update heights
        x.height = 1 + max(self.get_height(x.left), self.get_height(x.right))
        y.height = 1 + max(self.get_height(y.left), self.get_height(y.right))

        return y

    # Insert node
    def insert(self, root, key):
        # Normal BST insertion
        if not root:
            return Node(key)
        elif key < root.key:
            root.left = self.insert(root.left, key)
        else:
            root.right = self.insert(root.right, key)

        # Update height
        root.height = 1 + max(self.get_height(root.left), self.get_height(root.right))

        # Get balance factor
        balance = self.get_balance(root)

        # Case 1: Left Left
        if balance > 1 and key < root.left.key:
            return self.right_rotate(root)

        # Case 2: Right Right
        if balance < -1 and key > root.right.key:
            return self.left_rotate(root)

        # Case 3: Left Right
        if balance > 1 and key > root.left.key:
            root.left = self.left_rotate(root.left)
            return self.right_rotate(root)

        # Case 4: Right Left
        if balance < -1 and key < root.right.key:
            root.right = self.right_rotate(root.right)
            return self.left_rotate(root)

        return root

    # Pre-order traversal
    def pre_order(self, root):
        if not root:
            return
        print(root.key, end=" ")
        self.pre_order(root.left)
        self.pre_order(root.right)


# Example Usage
if __name__ == "__main__":
    tree = AVLTree()
    root = None

    # Insert nodes
    nums = [10, 20, 30, 40, 50, 25]

    for num in nums:
        root = tree.insert(root, num)

    print("Pre-order traversal of the AVL tree is:")
    tree.pre_order(root)
