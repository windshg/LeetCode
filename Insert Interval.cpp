/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

// straight-forward solution
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int n = intervals.size();
        if (n == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        int l = 0;
        while (l < n && intervals[l].end < newInterval.start) ++l;
        if (l >= n) {
            intervals.push_back(newInterval);
            return intervals;
        }
        int h = n - 1;
        while (h >= 0 && intervals[h].start > newInterval.end) --h;
        if (h < 0) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        newInterval.start = min(newInterval.start, intervals[l].start);
        newInterval.end = max(newInterval.end, intervals[h].end);
        intervals.erase(intervals.begin() + l, intervals.begin() + h + 1);
        intervals.insert(intervals.begin() + l, newInterval);
        return intervals;
    }
};