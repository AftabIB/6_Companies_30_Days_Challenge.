class Solution {
public:
    int subArray(vector<int> &arr, int N, int num) {
        int sum = 1;
        long long element = 0;
        for (int i = 0; i < N; i++) {
            if (element + arr[i] <= num) {
                element += arr[i];
            } else {
                sum += 1;
                element = arr[i];
            }
        }
        return sum;
    }

    int splitArray(vector<int> arr, int N, int K) {
        if (K > N)
            return -1;
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int element = subArray(arr, N, mid);
            if (element > K) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
    int splitArray(vector<int>& nums, int k) {
        return splitArray(nums, nums.size(), k);
    }
};