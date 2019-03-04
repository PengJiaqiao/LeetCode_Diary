import os,sys
import pyperclip

# |0143|[Reorder List](https://leetcode.com/problems/reorder-list/) |[c++](./src/0143_Reorder_List/Reorder_List.cpp) |python|Medium|

md_file = './README.md'

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
    text = '|' + sys.argv[1] + '|' + '[' + name + ']' + '(' + sys.argv[-2] + ')' + ' ' + '|' + '[c++](./src/' + sys.argv[1] + '_' + name_ + '/' + name_ + '.cpp) |python|' + sys.argv[-1] + '|' + '\n'
    print(text)
	# pyperclip.copy(text)
    with open(md_file) as f:
        lines = f.readlines()
    count = 0
    for line in lines:
        if line < text:
            count = count + 1
        else:
            break
    lines.insert(count, text)
    f = open(md_file, 'w')
    f.writelines(lines)
    f.close()
