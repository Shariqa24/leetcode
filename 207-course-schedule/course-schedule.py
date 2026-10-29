
from collections import deque

class Solution:
    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:
        graph = [[] for i in range(numCourses)]
        indegree = [0] * numCourses

        for u, v in prerequisites:
            graph[u].append(v)
            indegree[v] += 1

        q = deque()

        for i in range(numCourses):
            if indegree[i] == 0:
                q.append(i)

        count = 0

        while q:
            node = q.popleft()
            count += 1

            for ngh in graph[node]:
                indegree[ngh] -= 1

                if indegree[ngh] == 0:
                    q.append(ngh)

        return count == numCourses
