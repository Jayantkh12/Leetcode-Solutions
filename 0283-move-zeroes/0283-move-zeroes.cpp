class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int countZero = 0;
        vector<int>ans;
        for(auto it:nums){
            if(it == 0) countZero++;
            else{
                ans.push_back(it);
            }
        }
        while(countZero>0){
            ans.push_back(0);
            countZero--;
        }
        nums = ans;
    }
};