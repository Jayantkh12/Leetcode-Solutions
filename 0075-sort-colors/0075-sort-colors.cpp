class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroCount =0;
        int oneCount =0;
        int twoCount =0;
        for(int it:nums){
            if(it == 0) zeroCount++;
            else if(it==1) oneCount++;
            else twoCount++;
        }
        int i=0;
        while(zeroCount>0){
            nums[i]=0;
            i++;
            zeroCount--;
        }
        while(oneCount>0){
            nums[i]=1;
            i++;
            oneCount--;
        }
        while(twoCount>0){
            nums[i] = 2 ;
            i++;
            twoCount--;
        }
    }
};