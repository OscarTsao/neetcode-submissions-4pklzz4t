class Solution {
private: 
    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;

        int mid = l + (r-l) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid+1, r);
        
        merge(nums, l, mid, r);
    }

    void merge(vector<int>& nums, int l, int mid, int r) {
        vector<int> tmp;

        int i = l;
        int j = mid+1;

        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp.push_back(nums[i]);
                i++;
            }
            else {
                tmp.push_back(nums[j]);
                j++;
            }
        }
        while (i <= mid) {
            tmp.push_back(nums[i]);
            i++;
        }
        while (j <= r) {
            tmp.push_back(nums[j]);
            j++;
        }
        for (int k = 0; k < tmp.size(); k++) {
            nums[l+k] = tmp[k];
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};