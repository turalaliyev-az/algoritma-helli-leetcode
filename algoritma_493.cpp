//Reverse Pairs
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
 int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        vector<int>temp(n);
        function<void(int, int)> mergeSort = [&](int left, int right) {
            
            if (left >= right) return;
            int mid = left + (right - left) / 2;
            mergeSort(left, mid);
            mergeSort(mid + 1, right);
            int j = mid + 1;
            for (int i = left; i <= mid; ++i) {
                while (j <= right && (long long)nums[i] > 2 * (long long)nums[j]) {
                    j++;
                }
                count += j - (mid + 1);
            }
            merge(nums.begin() + left, nums.begin() + mid + 1, nums.begin() + mid + 1, nums.begin() + right + 1, temp.begin());
            for (int i = left; i <= right; ++i) {
                nums[i] = temp[i - left];   
                }
        };
        mergeSort(0, n - 1);
        return count;
    }
};

int main(){
    Solution sol;   
    vector<int> nums = {2,4,3,5,1};
    cout << sol.reversePairs(nums) << endl;
    return 0;
}