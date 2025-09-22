#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<long long> bit;
    Fenwick(int n) : n(n), bit(n+1, 0) {}
    
    void update(int i, int delta) {
        i++;
        while (i <= n) {
            bit[i] += delta;
            i += i & -i;
        }
    }
    
    long long query(int i) {
        i++;
        long long s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    
    long long queryRange(int l, int r) {
        if (l > r) return 0;
        return query(r) - (l ? query(l-1) : 0);
    }
};

long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    vector<int> pos2(n);
    for (int i = 0; i < n; i++) pos2[nums2[i]] = i;

    // nums1'i nums2 pozisyonlarına çevir
    vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = pos2[nums1[i]];

    vector<long long> leftSmaller(n), rightLarger(n);

    Fenwick fenLeft(n), fenRight(n);

    // soldan küçük sayıları bul
    for (int i = 0; i < n; i++) {
        leftSmaller[i] = fenLeft.query(arr[i]-1);
        fenLeft.update(arr[i], 1);
    }

    // sağdan büyük sayıları bul
    for (int i = n-1; i >= 0; i--) {
        rightLarger[i] = fenRight.queryRange(arr[i]+1, n-1);
        fenRight.update(arr[i], 1);
    }

    // ortadaki eleman üzerinden üçlü say
    long long result = 0;
    for (int i = 0; i < n; i++) {
        result += leftSmaller[i] * rightLarger[i];
    }
    return result;
}

int main() {
    vector<int> nums1 = {2,0,1,3};
    vector<int> nums2 = {0,1,2,3};
    cout << goodTriplets(nums1, nums2) << endl; // 1

    vector<int> nums3 = {4,0,1,3,2};
    vector<int> nums4 = {4,1,0,2,3};
    cout << goodTriplets(nums3, nums4) << endl; // 4
}
