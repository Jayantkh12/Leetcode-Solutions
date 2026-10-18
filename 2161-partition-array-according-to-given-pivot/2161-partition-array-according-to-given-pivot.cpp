class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>ans(n,0);
        int l = 0,r = n-1;
        int i = 0,j= n-1;
        while(l<n && r>=0 && i<n && j>=0){
            if(nums[l]<pivot){
                ans[i] = nums[l];
                i++;
            }
            if(pivot<nums[r]){
                ans[j] = nums[r];
                j--;
            }
            l++;
            r--;
        }
        while(i<=j){
            ans[i] = pivot;
            i++;
        }
        return ans;
    }
};