class Solution(object):
    def calcEquation(self, equations, values, queries):
        _equations = collections.defaultdict(dict)
        for (num, dem), val in zip(equations, values):
            _equations[num][num] = _equations[dem][dem] = 1.0
            _equations[num][dem] = val
            _equations[dem][num] = 1.0 / val
        return [self.DFS(num, dem, _equations, []) for num, dem in queries]

    def DFS(self, num, dem, equations, visit):
        if num not in equations or dem not in equations:
            return -1.0
        if dem in equations[num]:
            return equations[num][dem]
        else:
            for key in equations[num]:
                if key not in visit:
                    value = self.DFS(key, dem, equations, visit + [key])
                    if value != -1.0:
                        equations[num][dem] = value * equations[num][key]
                        return equations[num][dem]
            return -1.0