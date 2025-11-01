class Solution {
public:
    int minNumberOperations(vector<int>& target) {

        int n = target.size();

        int total = target[0];

        for(int i = 1;i<n;i++)
        {
            total += max(0,target[i] - target[i-1]);
        }

        return total;
    }
};