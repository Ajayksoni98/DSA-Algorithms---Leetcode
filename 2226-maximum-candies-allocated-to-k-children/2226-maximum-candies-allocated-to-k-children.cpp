class Solution {
public:

    bool check(vector<int> & candies,long long k, int val)
    {
        long long count = 0;

        for(auto x : candies)
        {
            count += (x/val);
        }

        return count >=k? true: false;


    }
    int maximumCandies(vector<int>& candies, long long k) {

        int n = candies.size();
        int min = 1;
        int max = *max_element(candies.begin(),candies.end());
       // cout<<max<<endl;
        int ans = 0;


        while(min <= max)
        {
           // cout<<ans<<endl;
            int mid = (min + max)/2;
            cout<<"mid="<<mid;
            if(check(candies,k,mid) == true)
            {
                cout<<ans<<endl;
                if(ans < mid)
                {
                    ans = mid;
                }
                min = mid+1;
            }
            else
            {
                max = mid -1;
            }
        }


        return ans;
        
    }
};