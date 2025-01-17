import sys
input = sys.stdin.readline
print = sys.stdout.write

def preorder(node, tree):
    if node == '.': return
    index = ord(node) - ord('A')
    
    print(node) 
    for child in tree[index]:
        preorder(child, tree)

def inorder(node, tree):
    if node == '.': return
    index = ord(node) - ord('A')
    
    inorder(tree[index][0], tree)    
    print(node)
    inorder(tree[index][1], tree) 

def postorder(node, tree):
    if node == '.': return
    index = ord(node) - ord('A')
    
    postorder(tree[index][0], tree)
    postorder(tree[index][1], tree)   
    print(node)

n = int(input())
bi_tree = [[] for _ in range(n)]
for _ in range(n):
    row = list(map(str, input().split()))
    index = ord(row[0]) - ord('A')
    bi_tree[index].extend(row[1:])

preorder('A', bi_tree)
print('\n')
inorder('A', bi_tree)
print('\n')
postorder('A', bi_tree)