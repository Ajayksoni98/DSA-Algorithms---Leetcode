class Solution:
    def maximumCost(self, n: int, highways: List[List[int]], k: int) -> int:
        graph = {i:set([]) for i in range(n)}
        graph[-1] = set((i,0) for i in range(n))
        for u,v,t in highways:
            graph[u].add((v,t))
            graph[v].add((u,t))
        @cache
        def dp(i,mask):
            if mask.bit_count()==k+1:
                return 0
            res = -1
            for j,toll in graph[i]:
                if (mask >> j) & 1 == 0:
                    nextcost = dp(j,mask | (1<<j))
                    if nextcost >= 0:
                        res = max(res,nextcost+toll)
            return res
        return dp(-1,0)





        