class Solution {
public:
    void helper(int index, vector<int>& nums, vector<int>& curr, vector<vector<int>>& res) {
        res.push_back(curr); // include current subset

        for (int i = index; i < nums.size(); i++) {
            // skip duplicates
            if (i > index && nums[i] == nums[i - 1]) continue;

            curr.push_back(nums[i]);
            helper(i + 1, nums, curr, res);
            curr.pop_back(); // backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // important to handle duplicates
        vector<vector<int>> res;
        vector<int> curr;
        helper(0, nums, curr, res);
        return res;
    }
};
