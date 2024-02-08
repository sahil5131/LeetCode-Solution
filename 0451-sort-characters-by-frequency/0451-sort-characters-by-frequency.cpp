class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m;
        int n = s.size();
        for(int i=0; i<n; i++){
            m[s[i]]++;
        }
        vector<pair<int,char>> v;
        for(auto it: m){
            v.push_back({it.second,it.first});
        }
        sort(v.rbegin(),v.rend());
        string ans="";
        for(auto it : v){
            while(it.first--){
                ans.push_back(it.second);
            }
        }
        return ans;
    }
};