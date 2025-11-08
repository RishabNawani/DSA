class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int mod = 1e9 + 7;
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> s1, s2;

        // find previous less element count
        for (int i = 0; i < n; i++) {
            while (!s1.empty() && arr[s1.top()] > arr[i]) s1.pop();
            left[i] = s1.empty() ? i + 1 : i - s1.top();
            s1.push(i);
        }

        // find next less element count
        for (int i = n - 1; i >= 0; i--) {
            while (!s2.empty() && arr[s2.top()] >= arr[i]) s2.pop();
            right[i] = s2.empty() ? n - i : s2.top() - i;
            s2.push(i);
        }

        long long res = 0;
        for (int i = 0; i < n; i++) {
            res = (res + (long long)arr[i] * left[i] * right[i]) % mod;
        }
        return (int)res;
    }
};
/*
int mod=1e9+7;
        int sum=0;
        for(int i=0;i<arr.size();i++){
            int mini=arr[i];
            for(int j=i;j<arr.size();j++){
                mini=min(mini,arr[j]);
                sum=(sum+mini)%mod;
            }
            
        }
        return sum;
    }
};

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod= 1e9+7;
        vector<vector<int>> storage;
        int mini=INT_MAX;
        int total=0;
        for(int i=0; i<arr.size();i++){
            for(int j=i;j<arr.size();j++){
                storage.push_back(std::vector<int>(arr.begin()+i,arr.begin()+j+1));
            }
        }
        for(int i=0; i<storage.size();i++){
            mini=INT_MAX;
            for(int j=0; j<storage[i].size();j++){
                mini=min(storage[i][j],mini);
            }
            total+=mini;
        }
        if(total>=INT_MAX) total=total%mod;
        return total;
    }
};
*/