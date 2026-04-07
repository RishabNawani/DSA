/// this shit can't be solved with dp cause it contains negative elements too , because if total sum is negative then dp will show heap buffer overflow, instead use meet in the middle approach 


/// watch meet in the middle algo video for this and use it , very helpful for this question , the base of the question revolves around it.
/// also watch video to understand this shit.
/// https://www.youtube.com/watch?v=vhmneSd8DiY
/// https://youtu.be/naz_9njI0I0?si=P4h5lURXfVJ_rlDE (meet in the middle)

/*
We’re given an array of size 2n, and we need to split it into two groups of size n such that the difference between their sums is minimum. Instead of directly forming two arrays, it’s easier to think like this: choose n elements whose sum is as close as possible to half of the total sum. That automatically makes the two groups balanced.

To avoid checking all possible combinations (which would be too slow), we divide the array into two halves — left and right. Then, for each half, we generate all possible subset sums using recursion. While doing this, we also keep track of how many elements are used in each subset. So basically, we store sums grouped by subset size.

After generating these, we sort the subset sums of the right half. This helps us use binary search efficiently later.

Now comes the main idea: we try all ways of picking elements. If we pick k elements from the left half, then we must pick n - k elements from the right half. For every sum from the left side, we try to find a matching sum from the right side such that the total is as close as possible to half of the overall sum.

To do this efficiently, we use binary search (lower_bound) on the right side. It gives us the closest value greater than or equal to what we need. We also check the previous value just in case that one gives a better result.

Finally, we compute the difference using the formula:
difference = |total - 2 × chosen_sum|

and keep track of the minimum value.
*/
class Solution {
public:

    // function to generate subset sums
    void findSubsets(int index, int count, int currentSum,
                     vector<int>& arr, vector<vector<int>>& store) {
        
        // base case: reached end
        if(index == arr.size()) {
            store[count].push_back(currentSum);
            return;
        }

        // include current element
        findSubsets(index + 1, count + 1, currentSum + arr[index], arr, store);

        // exclude current element
        findSubsets(index + 1, count, currentSum, arr, store);
    }

    int minimumDifference(vector<int>& nums) {

        int n = nums.size() / 2;

        // split array into two halves
        vector<int> left, right;
        for(int i = 0; i < n; i++) left.push_back(nums[i]);
        for(int i = n; i < 2*n; i++) right.push_back(nums[i]);

        // store subset sums grouped by size
        vector<vector<int>> leftSum(n+1), rightSum(n+1);

        // generate subset sums
        findSubsets(0, 0, 0, left, leftSum);
        findSubsets(0, 0, 0, right, rightSum);

        // sort right side for binary search
        for(int i = 0; i <= n; i++) {
            sort(rightSum[i].begin(), rightSum[i].end());
        }

        // calculate total sum
        int total = 0;
        for(int x : nums) total += x;

        int answer = INT_MAX;

        // try all possibilities
        for(int k = 0; k <= n; k++) {

            // pick k elements from left
            for(int leftValue : leftSum[k]) {

                int target = total / 2 - leftValue;

                vector<int>& vec = rightSum[n - k];

                // binary search
                auto it = lower_bound(vec.begin(), vec.end(), target);

                // check closest values
                if(it != vec.end()) {
                    int sum = leftValue + *it;
                    answer = min(answer, abs(total - 2 * sum));
                }

                if(it != vec.begin()) {
                    it--;
                    int sum = leftValue + *it;
                    answer = min(answer, abs(total - 2 * sum));
                }
            }
        }

        return answer;
    }
};