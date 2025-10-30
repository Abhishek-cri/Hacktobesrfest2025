#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive function to generate all subsets
    void solve(vector<int> nums, vector<vector<int>>& ans, vector<int>& temp, int n) {
        // Base case: when index goes below 0, store current subset
        if (n < 0) {
            ans.push_back(temp);
            return;
        }

        // Exclude current element
        solve(nums, ans, temp, n - 1);

        // Include current element
        temp.push_back(nums[n]);
        solve(nums, ans, temp, n - 1);

        // Backtrack (remove last element)
        temp.pop_back();
    }

    // Function to return all subsets
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<vector<int>> ans;
        vector<int> temp;

        solve(nums, ans, temp, n);
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3}; // input array
    vector<vector<int>> ans = s.subsets(nums);
    for (auto subset : ans) {
        cout << "{ ";
        for (auto val : subset) {
            cout << val << " ";
        }
        cout << "}\n";
    }
}
