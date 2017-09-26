class Solution(object):
    def findItinerary(self, tickets):
        self.list = []
        path = collections.defaultdict(list)
        for frm, to in tickets:
            path[frm].append(to)
        for _list in path:
            path[_list].sort(reverse=True)
        print(path)
        self.DFS(path, 'JFK')
        return self.list[::-1]

    def DFS(self, path, visit):
        while path[visit]:
            self.DFS(path, path[visit].pop())
        self.list.append(visit)
