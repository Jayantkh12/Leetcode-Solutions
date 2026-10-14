class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int>bit(30);
        long long ans = 0, mod = 1000000007;
        for(int num:nums){
            for(int i = 0;i<30;i++){
                if (num & (1 << i)) bit[i]++;
            }
        }
        while(k--){
            long long x = 0;
            for(int i = 0;i<30;i++){
                if(bit[i]>0){
                    x = x|(1LL<<i);
                    bit[i]--;
                }
            }
            ans = (ans+x*x)%mod;
        }
        return (int)ans;
    }
};