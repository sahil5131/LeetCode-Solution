class Solution {
public:

    bool checkPalindrome(string s){
        int n=s.size();
        for(int i=0; i<n/2; i++){
            if(s[i]!=s[n-i-1]){
                return false;
            }
        }
        return true;
    }

    

    int countSubstrings(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0; i<n; i++){
            string tmp="";
            for(int j=i; j<n; j++){
                tmp+=s[j];
                if(checkPalindrome(tmp)){
                    ans++;
                }
            }
        }
        return ans;
    }
};