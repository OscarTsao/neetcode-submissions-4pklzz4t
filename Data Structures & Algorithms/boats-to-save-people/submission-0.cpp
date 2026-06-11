class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        int l = 0;
        int r = people.size()-1;
        sort(people.begin(), people.end());
        

        while (l <= r) {
            if (people[l]+people[r] > limit) {
                r--;
            }
            else {
                l++;
                r--;
            }
            ans++;
        }
        return ans;
    }
};