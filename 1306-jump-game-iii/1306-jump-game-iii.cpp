class Solution {
    bool dfs(vector<int>& arr, int start,vector<bool>& vis){
        if(start>=arr.size() || start<0) return false;
        if(arr[start] == 0) return true;
        if (vis[start]) return false;
        vis[start] = true;
        return dfs(arr,start+arr[start],vis)|| dfs(arr,start-arr[start],vis);
    }
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool>vis(arr.size(),false);
        return dfs(arr,start,vis);
    }
};