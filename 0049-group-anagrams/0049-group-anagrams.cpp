class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> same_word_count;
        int n=strs.size();
        for(int i=0; i<n; i++){
            string sorted_word = strs[i];
            sort(sorted_word.begin(), sorted_word.end());
            same_word_count[sorted_word].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto it: same_word_count){
            vector<string> tmp;
            for(auto ind: it.second){
                tmp.push_back(strs[ind]);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};