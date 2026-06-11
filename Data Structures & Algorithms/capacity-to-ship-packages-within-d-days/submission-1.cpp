class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0;
        int r = 0;
        for (int x : weights) {
            l = max(l, x);
            r += x;
        }

        while (l <= r) {
            int mid = l + (r-l) / 2;
            int carry_weight = 0;
            int required_days = 1;

            for (int x : weights) {
                if (carry_weight + x > mid) {
                    carry_weight = x;
                    required_days++;
                }
                else {
                    carry_weight += x;
                }
            }
            if (required_days > days) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return l;
    }
};