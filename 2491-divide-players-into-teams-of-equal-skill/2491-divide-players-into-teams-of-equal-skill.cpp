class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans =0;
        int l =0 ;
        int r = skill.size()-1;
        sort(skill.begin(),skill.end());
        int x = skill[l]+skill[r];
        while(l<r){
            if(x!=skill[l]+skill[r])return -1;
            l++;
            r--;
        }
        l = 0,r = skill.size()-1;

        while(l<r){
            ans+=(long long)(skill[l]*skill[r]);
            l++;
            r--;
        }
        return ans;
    }
};