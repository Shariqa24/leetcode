
class Solution:
    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:
        graph = [[] for i in range(numCourses)]

        for u, v in prerequisites:
            graph[u].append(v)

        visit = [0] * numCourses

        def dfs(idx):
            if visit[idx] == 1:
                return False

            if visit[idx] == 2:
                return True

            visit[idx] = 1

            for ngh in graph[idx]:
                if not dfs(ngh):
                    return False

            visit[idx] = 2
            return True

        for i in range(numCourses):
            if not dfs(i):
                return False

        return True
