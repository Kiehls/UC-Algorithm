class Solution:
    def judgeCircle(self, moves):
        verticalCount = 0
        horizonCount = 0
        for idx in range(len(moves)):
            if moves[idx] == 'U':
                verticalCount += 1
            elif moves[idx] == 'D':
                verticalCount -= 1
            elif moves[idx] == 'R':
                horizonCount += 1
            else:
                horizonCount -= 1
        if horizonCount == 0 and verticalCount == 0:
            return True
        else:
            return False
