class Solution {
    long long int calTrips(vector<int>& time,  long long givenTime){
        long long int trips=0;
        for(auto it: time){

            trips += (givenTime/it);
        }
        return trips;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long int low = 1;
        long long int high = 1e14;

        while(low<=high){
            long long int mid = low +(high-low)/2;
            long long trips = calTrips(time,mid);

            if(trips>=totalTrips){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};