class Solution {
public:
    double myPow(double x, int n) {
        if (n==0) return 1.0;
        int sgn=(n>0)?1:-1;
        long long exp=(long long)n*sgn;//avoid of overflow for n=INT_MIN change sign 
        bitset<32> bexp(exp);
        double a=1;
        x=(sgn==1)?x:1.0/x;
        for(int b=31; b>=0; b--){
            a=a*a;
            if (bexp[b]) a*=x;
        }
        return a;
    }
};