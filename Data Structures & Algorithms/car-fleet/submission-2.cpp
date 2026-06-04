class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        double latest = 0;
        vector<pair<int, int>> cars;
        int n = position.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend());

        for (int i = 0; i < n; i++) {
            double time = (double)(target-cars[i].first) / cars[i].second;
            if (time > latest) {
                latest = time;
                count++;
            }
        }
        return count;
    }
};
