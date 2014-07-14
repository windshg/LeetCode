/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

 // do a quick sort before merging the intervals.
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        int n = intervals.size();
        if (n < 2) return intervals;
        qsort(intervals, 0, n - 1);
        vector<Interval>::iterator l = intervals.begin();
        vector<Interval>::iterator h = l + 1;
        vector<Interval> ret;
        while (h != intervals.end()) {
            if (h->start <= l->end) {
                h->start = min(l->start, h->start);
                h->end = max(l->end, h->end);
                l = h;
                h ++;
            } else {
                ret.push_back(*l);
                l ++;
                h ++;
            }
        }
        ret.push_back(*l);
        return ret;
    }
    
    int partition(vector<Interval> &a, int l, int h) {
        Interval pvt = a[l];
        while (l < h) {
            while (l < h && a[h].start >= pvt.start) -- h;
            a[l] = a[h];
            while (l < h && a[l].start <= pvt.start) ++ l;
            a[h] = a[l];
        }
        a[l] = pvt;
        return l;
    }
    
    void qsort(vector<Interval> &a, int l, int h) {
        if (l < h) {
            int m = partition(a, l, h);
            qsort(a, l, m - 1);
            qsort(a, m + 1, h);
        }
    }
};

// Shorter version with STL algorithms.
 
bool cmp (Interval l, Interval h) {
    return l.start < h.start;
}
 
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        int n = intervals.size();
        if (n < 2) return intervals;
        vector<Interval> ret;
        sort(intervals.begin(), intervals.end(), cmp);
        int l = 0, h = 1;
        while (h < n) {
            if (intervals[h].start <= intervals[l].end) {
                intervals[h].start = intervals[l].start;
                intervals[h].end = max(intervals[l].end, intervals[h].end);
                l = h; h = l + 1;
            } else {
                ret.push_back(intervals[l]);
                l ++; h ++;
            }
        }
        ret.push_back(intervals[l]);
        return ret;
    }
};
