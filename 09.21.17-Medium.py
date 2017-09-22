class Solution(object):
    def findDuplicate(self, paths):
        _dict = {}
        for path in paths:
            _dir = path.split()[0]
            for files in path.split()[1:]:
                _file, _content = files.split('(')[0], files.split('(')[1].replace(")", "")
                file_path = _dir + '/' + _file
                if _content not in _dict:
                    _dict[_content] = [file_path]
                else:
                    _dict[_content].append(file_path)

        return [_dict[idx] for idx in _dict if len(_dict[idx]) > 1]