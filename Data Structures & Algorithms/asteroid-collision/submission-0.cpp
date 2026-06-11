class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int x : asteroids) {
            bool alive = true;

            while (!st.empty() && x < 0 && st.back() > 0) {
                if (st.back() < -x) {
                    st.pop_back();
                }
                else if (st.back() == -x) {
                    st.pop_back();
                    alive = false;
                    break;
                }
                else {
                    alive = false;
                    break;
                }
            }
            if (alive) {
                st.push_back(x);
            }
        }
        return st;
    }
};