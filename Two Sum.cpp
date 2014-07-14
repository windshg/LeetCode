// time: O(N) space: O(N)
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret(2);
        unordered_map<long, int> smp;
        long mul;
        for (int i = 0; i < numbers.size(); ++i) {
            mul = numbers[i] * (target - numbers[i]);
            if (smp[mul] > 0) {
                if (numbers[i] + numbers[smp[mul]-1] == target) {
                    ret[0] = smp[mul];
                    ret[1] = i+1;
                    break;
                }
            } else {
                smp[mul] = i+1;
            }
        }
        return ret;
    }
};