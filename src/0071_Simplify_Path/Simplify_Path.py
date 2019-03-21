class Solution:
    def simplifyPath(self, path: str) -> str:
        import re
        cleaned_path = re.split(r'/+', path)
        res = []
        for item in cleaned_path:
            if item == '.' or item == '': continue
            elif item == '..':
                if res: res.pop()
            else: res.append(item)
        return '/' + '/'.join(res)
