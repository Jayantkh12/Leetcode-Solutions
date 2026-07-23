class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        string ans ;
        vector<int>last(26,0);
        for(int i =0;i<n;i++){
            last[s[i]-'a'] = i;
        }
        vector<bool> vis(26, false);

        for(int i =0;i<n;i++){
            char c = s[i];
            if(vis[c-'a']) continue;

            while(!ans.empty() && ans.back()>c && last[ans.back()-'a']>i){
                vis[ans.back()-'a'] = false;
                ans.pop_back();
            }
            ans.push_back(c);
            vis[c-'a'] = true;
        }
       
        return ans;
    }
};