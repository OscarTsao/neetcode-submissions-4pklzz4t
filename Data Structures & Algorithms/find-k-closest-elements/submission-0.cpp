class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() - 1;

        while (r - l > k - 1) {
            if (abs(arr[l] - x) > abs(arr[r]-x)) l++;
            else if (abs(arr[l]-x) < abs(arr[r]-x)) r--;
            else r--;
        }
       return vector<int> (arr.begin()+l, arr.begin()+r+1);
    }
};