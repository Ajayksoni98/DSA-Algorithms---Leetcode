class Solution {
public:

    int is_cube(int n,vector<int> &primes)
    {
        for(int i = 0;i<primes.size();i++)
        {
            int c = primes[i]*primes[i] *primes[i];
            if(n == c )
            return 1 + c + (c / primes[i]) + primes[i] ;
        }
        return -1;
    }
    bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}


   int is_prod(int n) {
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            int q = n / p;
            return q != p && isPrime(p) && isPrime(q)? (p + q):-1;
        }
    }
    return -1;
}



    int sumFourDivisors(vector<int>& nums) {

        int n = nums.size();

        vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            int x = is_cube(nums[i],primes);
            //cout<<nums[i]<<"  is_cube"<<x<<endl;
            int y = is_prod(nums[i]);
            //cout<<nums[i]<<"  is_prod"<<y<<endl;
            if( x != -1)
            {
                ans+=x;
            }
            else if(y != -1)
            {
                ans+=y;
                ans +=1;
                ans += nums[i];
            }
        }

        return ans;

        
    }
};