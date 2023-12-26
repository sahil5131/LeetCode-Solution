class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anargam_map = defaultdict(list)
        for i in range(len(strs)):
            char_count = [0]*26
            for j in strs[i]:
                char_count[ord(j)-ord('a')]+=1
            if tuple(char_count) in anargam_map:
                anargam_map[tuple(char_count)].append(strs[i])
            else:
                anargam_map[tuple(char_count)]=[strs[i]]
        
        return list(anargam_map.values())