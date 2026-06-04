class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 0;

        for (int x: piles) {
            r = max(r, x);
        }

        int ans = r;

        while (l <= r) {
            int mid = (l+r) / 2;
            long long int time = 0;

            for (int x: piles) {
                time += (x / mid) + (x % mid != 0);
            }

            if (time <= h) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};
