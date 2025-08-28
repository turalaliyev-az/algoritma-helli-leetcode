//Count of smaller numbers after self
// YENI ALQORITMANIN TEBIQI

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// Sağındakı kiçikləri saymaq - Bal Arısı Koloniyası Yanaşması
vector<int> countSmallerBeeColony(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 0);

    // 1. Orijinal arrayin kopyasını alıb sıralayırıq
    vector<int> sorted_nums(nums.begin(), nums.end());
    sort(sorted_nums.begin(), sorted_nums.end());

    // 2. Hər elementin sıralı arraydəki indeksini tapmaq (rank)
    unordered_map<int, int> ranks;
    for (int i = 0; i < sorted_nums.size(); ++i) {
        if (ranks.find(sorted_nums[i]) == ranks.end()) {
            ranks[sorted_nums[i]] = i; // hər elementin ən kiçik indeksi
        }
    }

    // 3. Sağdan sola gedirik və hər elementin cavabını yeni arraydə saxlayırıq
    vector<int> tree(sorted_nums.size() + 1, 0);

    auto update = [&](int index) {
        ++index;
        while (index < tree.size()) {
            tree[index] += 1;
            index += index & (-index);
        }
    };

    auto query = [&](int index) {
        ++index;
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & (-index);
        }
        return sum;
    };

    for (int i = n-1; i >= 0; --i) {
        int r = ranks[nums[i]];
        result[i] = query(r-1); // sağında neçə kiçik var
        update(r);
    }

    return result;
}
};

int main() {
    Solution sol;

    vector<int> nums = {5, 2, 6, 1};
    vector<int> result = sol.countSmallerBeeColony(nums);

    cout << "Result: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}









