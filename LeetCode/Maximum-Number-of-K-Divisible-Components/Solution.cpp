class Solution:
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int)-> int:
        if n == 1:
            return 1
        indegree = [0]*n

        graph = defaultdict(list)

        for [x,y] in edges:
            graph[x].append(y)
            graph[y].append(x)
            indegree[x] += 1
            indegree[y] += 1
        
        q = deque([])

        for node in range(n):

            if indegree[node] == 1:
                q.appendleft(node)
        cnt = 0
        val = [0]*n
        seen = set()
        while  q:

            node = q.pop()
            seen.add(node)

            cur_val = values[node] + val[node]
            if cur_val % k == 0:
                cnt += 1
                cur_val = 0
            
            for adj_node in graph[node]:
                indegree[adj_node] -= 1
                val[adj_node] += cur_val

                if indegree[adj_node] == 1 and adj_node not in seen:
                    q.appendleft(adj_node)
        return cnt
            