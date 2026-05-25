class Node{
public:
    Node* links[2];

    bool containskey(int ind){
        return links[ind]!=NULL;
    }

    Node* get(int ind){
        return links[ind];
    }

    void put(int ind,Node* node){
        links[ind]=node;
    }
};

class Trie {
private:
    Node* root;

public:
    // Constructor to initialize the trie
    Trie() {
        root = new Node();
    }

    // Function to insert a number into the trie
    void insert(int num) {
        // Start from root
        Node* node = root;

        // Traverse bits from MSB (31) to LSB (0)
        for (int i = 31; i >= 0; i--) {
            // Extract the current bit
            int bit = (num >> i) & 1;

            // If path for this bit doesn't exist, create it
            if (!node->containskey(bit)) {
                node->put(bit, new Node());
            }

            // Move to the next node
            node = node->get(bit);
        }
    }

    // Function to find maximum XOR for a given number
    int findMax(int num) {
        // Start from root
        Node* node = root;

        // Variable to store maximum XOR result
        int maxNum = 0;

        // Traverse bits from MSB to LSB
        for (int i = 31; i >= 0; i--) {
            // Extract the current bit
            int bit = (num >> i) & 1;

            // Try to take the opposite bit for maximizing XOR
            if (node->containskey(!bit)) {
                // Set this bit in the result
                maxNum = maxNum | (1 << i);

                // Move to the opposite branch
                node = node->get(!bit);
            } 
            // If opposite bit doesn't exist, move to same bit branch
            else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        // Result vector to store answers
        vector<int> ans(queries.size(), 0);

        // Vector to store queries in {m, {x, original_index}} format
        vector<pair<int, pair<int,int>>> offlineQueries;

        // Sort the array in ascending order
        sort(nums.begin(), nums.end());

        // Store queries with index for mapping answers later
        int index = 0;
        for (auto &it: queries) {
            offlineQueries.push_back({it[1], {it[0], index++}});
        }

        // Sort queries based on 'm'
        sort(offlineQueries.begin(), offlineQueries.end());

        // Pointer for array traversal
        int i = 0;

        // Size of array
        int n = nums.size();

        // Initialize the trie
        Trie trie;

        // Process each query in sorted order of 'm'
        for (auto &it : offlineQueries) {
            // Insert all elements ≤ m into the trie
            while (i < n && nums[i] <= it.first) {
                trie.insert(nums[i]);
                i++;
            }

            // If trie has at least one element
            if (i != 0)
                ans[it.second.second] = trie.findMax(it.second.first);
            // If no elements ≤ m, return -1
            else
                ans[it.second.second] = -1;
        }
        return ans;
    }
};