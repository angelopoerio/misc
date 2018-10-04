from pprint import pprint

# BST in python

class Tree(object):
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None 

    def insert(self, val):
        if self.val is None:
            self.val = Tree(val)
        else:
            if val < self.val:
                if self.left is None:
                    self.left = Tree(val)
                else:
                    self.left.insert(val)
            elif val > self.val:
                if self.right is None: 
                    self.right = Tree(val)
                else:
                    self.right.insert(val)
    
    
    def __preorder(self, node, lst):
        if node is None:
            return
        lst.append(node.val)
        if self.left:
            self.left.__inorder(self.left, lst) 
        if self.right:
            self.right.__inorder(self.right, lst)

    def preorder(self):
        vls=[]
        self.__inorder(self,vls)
        return vls


if __name__ == "__main__":
    tr=Tree(10)
    tr.insert(2) 
    tr.insert(14) 
    tr.insert(90)         
    print pre.inorder()
            
         
