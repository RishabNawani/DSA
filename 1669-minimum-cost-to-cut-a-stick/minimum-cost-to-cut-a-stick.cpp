class Solution {
public:

// didnt understand shit, watch striver's videos again to understand all of this bullshit , patani bc kya hai ye bakchodi
// watch dp 48, 49 and 50
/// https://www.youtube.com/watch?v=xwomavsC86c&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=51

    // Recursive function with memoization to find minimum cost between indices i and j in cuts
    /*int findMinimumCost(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
        // Base case: no cuts to consider
        if (i > j) {
            return 0;
        }

        // Return precomputed result if available
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int mini = INT_MAX;

        // Try cutting at every position between i and j
        for (int ind = i; ind <= j; ind++) {
            // Calculate cost of current cut plus costs of left and right subproblems
            int ans = cuts[j + 1] - cuts[i - 1] +
                      findMinimumCost(i, ind - 1, cuts, dp) +
                      findMinimumCost(ind + 1, j, cuts, dp);

            // Update minimum cost
            mini = min(mini, ans);
        }

        // Store and return the minimum cost found
        return dp[i][j] = mini;
    }
*/
    int minCost(int n, vector<int>& cuts) {
        /*int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        // Sort the cuts array
        sort(cuts.begin(), cuts.end());

        // Create a DP table initialized with -1
        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));

        // Compute minimum cost to make all cuts between indices 1 and c
        return findMinimumCost(1, c, cuts, dp);
        */

        int c=cuts.size();
        // Add the two ends of the stick to the cuts array
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        // Sort the cuts array
        sort(cuts.begin(), cuts.end());

        // Create a DP table initialized with 0
        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

        // Fill the DP table for all possible segments
        // i traverses backward from c to 1
        for (int i = c; i >= 1; i--) {
            // j traverses forward from i to c
            for (int j = i; j <= c; j++) {
                int mini = INT_MAX;

                // Try making a cut at every position between i and j
                for (int ind = i; ind <= j; ind++) {
                    // Cost of making the current cut plus costs of left and right subproblems
                    int ans = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];

                    // Update minimum cost
                    mini = min(mini, ans);
                }

                // Store the minimum cost in DP table
                dp[i][j] = mini;
            }
        }

        // The answer is the minimum cost to cut between indices 1 and c
        return dp[1][c];
    }
};