class Solution {
public:
    int findLucky(vector<int>& arr) {

        unordered_map<int,int> mp;
        for(int i = 0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        int maxval = INT_MIN;
        for(auto x : mp)
        {
            if(x.first == x.second)
            maxval = max(maxval,x.first);
        }

        return maxval == INT_MIN ? -1 : maxval;
        
    }
};