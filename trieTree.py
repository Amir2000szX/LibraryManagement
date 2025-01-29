import json
class Node:
    def __init__(self, value, parent=None, childs=None, isAWord=0):
        self.value = value
        self.parent = parent
        self.childs = childs if childs is not None else []
        self.isAWord = isAWord

    def __repr__(self):
        return self.value

    def __eq__(self, other):
        if not isinstance(other, Node):
            return False
        return self.value == other.value

    def toDict(self):
        # Convert children nodes to their dict representation
        children_dicts = [child.toDict() for child in self.childs]
        # Handle parent safely: store only the value, or None if no parent
        parent_value = self.parent.value if self.parent else None
        return {
            "value": self.value,
            "children": children_dicts,
            "parent": parent_value,  # None if no parent
            "isAWord": self.isAWord
        }
class TrieTree:
    def __init__(self):
        self.root = Node(None)
    def toDict(self):
        dictFile = self.root.toDict()
        with open("TrieTree.json",'w') as file:
            json.dump(dictFile,file,indent=4)

    def addWord(self,lstLetter,root:Node):
        if len(lstLetter) == 1:
            if Node(lstLetter[0]) not in root.childs:
                root.childs.append(Node(lstLetter[0]))
                root.childs[-1].isAWord = 1
                root.childs[-1].parent = root
            else:
                for i in range(len(root.childs)):
                    if root.childs[i] == lstLetter[0]:
                        root.childs[i].isAWord = 1
                        root.childs[i].parent = root
        
        elif Node(lstLetter[0]) not in root.childs:
            root.childs.append(Node(lstLetter[0]))
            root.childs[-1].parent = root
            self.addWord(lstLetter[1:],root.childs[-1])
            
        else:
            for i in range(len(root.childs)):
                if root.childs[i] == Node(lstLetter[0]):
                    self.addWord(lstLetter[1:],root.childs[i])

    def deleteWord(self,lstLetter):
        root = self.root
        for i in range(len(lstLetter)):
            flag = False
            for j in range(len(root.childs)):
                if Node(lstLetter[i]) == root.childs[j]:
                    root = root.childs[j]
                    flag == True
                    break
            if flag == False:
                break
        else:
            root.isAWord = 0
        while root.isAWord != 1 and len(root.childs)==0 :
            root = root.parent
            root.childs = []

lstWord1 = ['c','a','l','l']
lstWord2 = ['c','a','r']
lstWord3 = ['t','e','a']
tree = TrieTree()
tree.addWord(lstWord1,tree.root)
tree.addWord(lstWord2,tree.root)
tree.addWord(lstWord3,tree.root)
tree.toDict()

        

        

        
