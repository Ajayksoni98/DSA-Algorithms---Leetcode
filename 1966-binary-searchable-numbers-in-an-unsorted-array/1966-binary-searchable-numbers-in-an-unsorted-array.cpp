class Solution {
public:
    int binarySearchableNumbers(vector<int>& nums) {
        const int n = nums.size();
        // Consider all elements are searchable, and remove those that are not
        vector<bool> searchable(n, true);
        int max = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] >= max)
                max = nums[i];
            else
                // A larger number is at an index j < i. If we search nums[i]
                // and pick the j-th number as a pivot, we'll miss nums[i].
                searchable[i] = false;
        }
        int min = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] <= min)
                min = nums[i];
            else
                // A smaller number is at an index j > i. If we search nums[i]
                // and pick the j-th number as a pivot, we'll miss nums[i].
                searchable[i] = false;
        }
        return std::count(searchable.begin(), searchable.end(), true);
    }
};