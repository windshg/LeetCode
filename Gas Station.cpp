class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if (gas.size() != cost.size()) return -1;
        int n = gas.size();
        if (n == 0) return -1;
        int sum = 0, minSum = INT_MAX, minSumIdx =  0;
        for (int i = 0; i < n; ++i) {
            sum += gas[i] - cost[i];
            if (sum < minSum) {
                minSum = sum;
                minSumIdx = i;
            }
        }
        if (sum < 0) return -1;
        if (minSumIdx == n-1) return 0;
        return minSumIdx + 1;
    }
};