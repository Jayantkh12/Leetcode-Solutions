class Solution {
public:
    int smallestNumber(int n, int t) {

        for(int i = n ; ; i++){
            int pdt = 1;
            int x = i;
            while(x>0){
                pdt *= x%10;
                x/=10;
            }
            if(pdt % t == 0) return i;
        }
        return -1;
    }
};