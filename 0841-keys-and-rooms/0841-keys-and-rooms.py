class Solution:
    
    def dfs(self, i, keys, rooms: List[List[int]], vis: List[int]):
        vis[i]=1
        for j in rooms[i]:
            if vis[j]==0:
                keys.add(j)
                self.dfs(j, keys, rooms, vis)


    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        n = len(rooms)
        keys = {0}
        # keys.add(0)
        vis = [0]*n

        for i in range(n):
            if i in keys and vis[i]==0:
                self.dfs(i, keys, rooms, vis)
        
        for i in range(n):
            if vis[i]==0:
                return False
        
        return True