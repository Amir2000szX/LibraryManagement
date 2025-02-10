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
        children_dicts = [child.toDict() for child in self.childs]
        parent_value = self.parent.value if self.parent else None
        return {
            "value": self.value,
            "parent": parent_value,
            "isAWord": self.isAWord,
            "children": children_dicts}
    @staticmethod
    def rootMaker(jsonfile):
        if len(jsonfile["children"])==0:
            return Node(jsonfile["value"],jsonfile["parent"],[],jsonfile["isAWord"])
        children = []
        for child in jsonfile["children"]:
            children.append(Node.rootMaker(child))
        return Node(jsonfile["value"],jsonfile["parent"],children,jsonfile["isAWord"])
   
class TrieTree:
    def __init__(self,root=Node(None)):
        self.root = root
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
    @staticmethod
    def makeTree():
        try :
            with open("TrieTree.json",'r') as TreeFile:
                Tree = TrieTree(Node.rootMaker(TreeFile))
            return Tree
        except :
            with open("TrieTree.json",'w') as file:
                Tree = TrieTree()
            return Tree
