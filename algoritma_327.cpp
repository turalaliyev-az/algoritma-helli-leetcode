//Count of range sum 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        // high level idea: prefix sums + modified merge sort
        /*
        int n = nums.size();
        vector<long long> prefixSums(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSums[i + 1] = prefixSums[i] + nums[i];
        }
        return countWhileMergeSort(prefixSums, 0, n + 1, lower, upper);
    }

private:
    int countWhileMergeSort(vector<long long>& sums, int left, int right, int lower, int upper) {
        if (right - left <= 1) return 0;
        int mid = (left + right) / 2;
        int count = countWhileMergeSort(sums, left, mid, lower, upper) +
                    countWhileMergeSort(sums, mid, right, lower, upper);

        int j = mid, k = mid;
        vector<long long> temp;
        int t = mid;
        for (int i = left; i < mid; ++i) {
            while (k < right && sums[k] - sums[i] < lower) k++;
            while (j < right && sums[j] - sums[i] <= upper) j++;
            count += j - k;
        }

        // Merge step
        int i = left;
        t = mid;
        while (i < mid && t < right) {
            if (sums[i] <= sums[t]) {
                temp.push_back(sums[i++]);
            } else {
                temp.push_back(sums[t++]);
            }
        }
        while (i < mid) temp.push_back(sums[i++]);
        while (t < right) temp.push_back(sums[t++]);

        // Kopyala
        for (int i = 0; i < temp.size(); ++i) {
            sums[left + i] = temp[i];
        }

        return count;*/

        int n = nums.size();
        vector<long long> prefixSums(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSums[i + 1] = prefixSums[i] + nums[i];    
    }
        return countWhileMergeSort(prefixSums, 0, n + 1, lower, upper);
    }

private:
    int countWhileMergeSort(vector<long long>& sums, int left, int right, int lower, int upper) {
        if (right - left <= 1) return 0;
        int mid = (left + right) / 2;
        int count = countWhileMergeSort(sums, left, mid, lower, upper) +
                    countWhileMergeSort(sums, mid, right, lower, upper);

        int j = mid, k = mid;
        vector<long long> temp;
        int t = mid;
        for (int i = left; i < mid; ++i) {
            while (k < right && sums[k] - sums[i] < lower) k++;
            while (j < right && sums[j] - sums[i] <= upper) j++;
            count += j - k;
        }

        // Merge step
        int i = left;
        t = mid;
        while (i < mid && t < right) {
            if (sums[i] <= sums[t]) {
                temp.push_back(sums[i++]);
            } else {
                temp.push_back(sums[t++]);
            }
        }
        while (i < mid) temp.push_back(sums[i++]);
        while (t < right) temp.push_back(sums[t++]);

        // Kopyala
        for (int i = 0; i < temp.size(); ++i) {
            sums[left + i] = temp[i];
        }

        return count;
    }
};


int main(){
    Solution sol;
        vector<int> nums = {2147483647,-2147483648,-1,0};
        int lower = -1;
        int upper = 0;
        cout << sol.countRangeSum(nums, lower, upper) << endl;    
    return 0;
}