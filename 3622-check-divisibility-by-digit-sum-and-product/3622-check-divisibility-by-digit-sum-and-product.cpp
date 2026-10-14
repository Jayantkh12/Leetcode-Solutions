class Solution {
public:
    bool checkDivisibility(int n) {
        int x = n;
        int sum = 0;
        int pdt = 1;
        while(n>0){
            int rem = n%10;
            n/=10;
            sum+=rem;
            pdt*=rem;
        }
        return (x%(sum+pdt)==0);
    }
};