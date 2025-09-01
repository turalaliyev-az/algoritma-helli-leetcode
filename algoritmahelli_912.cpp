// Sort and Array   O(n log n) time and O(1) space
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
       vector<int> sortArray(vector<int>& nums) {
         int n = nums.size();
        vector<int>temp(n);
        function<void(int, int)> mergeSort = [&](int left, int right) {
            
            if (left >= right) return;
            int mid = left + (right - left) / 2;
            mergeSort(left, mid);
            mergeSort(mid + 1, right);
            merge(nums.begin() + left, nums.begin() + mid + 1, nums.begin() + mid + 1, nums.begin() + right + 1, temp.begin());
            for (int i = left; i <= right; ++i) {
                nums[i] = temp[i - left];   
                }
        };
        mergeSort(0, n - 1);
        return nums;
    }
    
       
};

int main(){
    Solution sol;   
    vector <int> nums = {5,2,3,1};
    vector <int> sorted = sol.sortArray(nums);
    for (int num : sorted) {
        cout << num << " ";
    }
    cout << endl;
    return 0;

   /*
   Input: nums = [5,2,3,1]
Output: [1,2,3,5]
   */
}