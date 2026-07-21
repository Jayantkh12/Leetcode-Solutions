class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n =  candies.size();
        int low = 1;
        int high =  *max_element(candies.begin(),candies.end());
        int result =0;
        while(low<=high){
            int mid = low + (high-low)/2;
            long long cnt = 0;
            for(auto pile:candies){
                cnt+= pile/mid;
            }
            if(cnt >= k){
                result = mid;
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return result;
    }
};