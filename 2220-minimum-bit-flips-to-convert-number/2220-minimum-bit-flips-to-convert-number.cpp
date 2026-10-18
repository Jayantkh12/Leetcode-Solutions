class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        int x = start^goal;
        for(int  i =0 ;i<32;i++){
            if(x>>i & 1)cnt++;
        }
        return cnt;
    }
};