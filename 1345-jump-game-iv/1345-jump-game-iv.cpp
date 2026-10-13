class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>mp;
        int n = arr.size();
        for(int i = 0 ;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        queue<int> q;
        vector<bool> vis(n, false);

        q.push(0);
        vis[0] = true;

        int steps = 0;

        while(!q.empty()){
            int z = q.size();
            while(z--){
                int temp = q.front();
                q.pop();
                if (temp == n - 1) return steps;
                // i+1
                if(temp+1<n && !vis[temp+1]){
                    vis[temp+1] = true;
                    q.push(temp+1);
                }
                //i-1
                if(temp-1>=0 && temp-1<n&& !vis[temp-1]){
                    vis[temp-1] = true;
                    q.push(temp-1);
                }
                //
                for(int next : mp[arr[temp]]){
                    if(!vis[next]){
                        vis[next] = true;
                        q.push(next);
                    }
                }
                mp.erase(arr[temp]);
            }
            steps++;
        }
        return -1;
    }
};