#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Fenwick {
    int n;
    vector<ll> bit;
    Fenwick(int n=0){ init(n); }
    void init(int n_){
        n = n_;
        bit.assign(n+1, 0);
    }
    void update(int idx, ll delta){
        while(idx <= n){
            bit[idx] += delta;
            idx += idx & -idx;
        }
    }
    ll query(int idx){
        ll s = 0;
        while(idx > 0){
            s += bit[idx];
            idx -= idx & -idx;
        }
        return s;
    }
    ll queryRange(int l, int r){
        if(l > r) return 0;
        return query(r) - query(l-1);
    }
};

long long countPairs(const vector<int>& nums1, const vector<int>& nums2, int diff){
    int n = nums1.size();
    vector<long long> A(n);
    for(int i = 0; i < n; ++i) A[i] = 1LL*nums1[i] - 1LL*nums2[i];

    vector<long long> vals;
    vals.reserve(2*n);
    for(int i = 0; i < n; ++i){
        vals.push_back(A[i]);
        vals.push_back(A[i] + diff);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    auto getIndex = [&](long long x)->int{
        return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin()) + 1;
    };

    Fenwick fw((int)vals.size());
    long long result = 0;

    for(int j = 0; j < n; ++j){
        long long target = A[j] + diff;
        int idx = getIndex(target); // index of target in compressed coords
        ll cnt = fw.query(idx);
        result += cnt;
        int idxAj = getIndex(A[j]);
        fw.update(idxAj, 1);
    }
    return result;
}

int main(){
    vector<int> nums1 = {3,2,5};
    vector<int> nums2 = {2,2,1};
    int diff = 1;
    cout << countPairs(nums1, nums2, diff) << "\n"; 

    vector<int> a2 = {3,-1};
    vector<int> b2 = {-2,2};
    int d2 = -1;
    cout << countPairs(a2, b2, d2) << "\n"; 

    return 0;
}
