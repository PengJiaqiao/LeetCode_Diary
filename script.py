import os,sys

# |0143|[Reorder List](https://leetcode.com/problems/reorder-list/) |[c++](./src/0143_Reorder_List/Reorder_List.cpp) |python|Medium|

if __name__ == "__main__":
    name = sys.argv[2]
    name_ = sys.argv[2]
    for arg in sys.argv[3:-2]:
        name = name + ' ' + arg
        name_ = name_ + '_' + arg

    path = './src/' + sys.argv[1] + '_' + name_
    folder = os.path.exists(path)
    if not folder:
        os.makedirs(path)
    file = open(path + '/' + name_ + '.cpp','w')
    file.close()
    print('|' + sys.argv[1] + '|' + '[' + name + ']' + '(' + sys.argv[-2] + ')' + ' ' + '|' + '[c++](./src/' + sys.argv[1] + '_' + name_ + '/' + name_ + '.cpp) |python|' + sys.argv[-1] + '|')
