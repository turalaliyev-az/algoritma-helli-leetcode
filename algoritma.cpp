#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    //enter the first array
    vector<int> a;
    int num;
  
    while (cin >> num && num != -1) {
        a.push_back(num);
    }   
  // second array
    vector<int> b;
    while (cin >> num && num != -1) {
        b.push_back(num);
    }
// first and second arrey connect 
    vector<int> c(a.size() + b.size());
// calculate the median
    merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
    int n = c.size();
    double median;
    if (n % 2 == 0) {
        median = (c[n / 2 - 1] + c[n / 2]) / 2.0;
    } else {
        median = c[n / 2];
    }
    cout << "Median: " << median << endl;
    cout << "Merged array: ";
    for (int i = 0; i < c.size(); i++) {
        cout << c[i] << " ";
    }
    cout << endl;
    cout << "Size of merged array: " << c.size() << endl;
    cout << "First array size: " << a.size() << endl;
    cout << "Second array size: " << b.size() << endl;
    cout << "First array: ";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Second array: ";
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    cout << "Merged array in reverse order: ";
    for (int i = c.size() - 1; i >= 0; i--) {
        cout << c[i] << " ";
    }
    cout << endl;
    cout << "First array in reverse order: ";
    for (int i = a.size() - 1; i >= 0; i--) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Second array in reverse order: ";
    for (int i = b.size() - 1; i >= 0; i--) {
        cout << b[i] << " ";
    }
    cout << endl;
    cout << "First element of merged array: " << c[0] << endl;
    cout << "Last element of merged array: " << c[c.size() - 1] << endl;
    cout << "First element of first array: " << a[0] << endl;
    cout << "Last element of first array: " << a[a.size() - 1] << endl;
    cout << "First element of second array: " << b[0] << endl;
    cout << "Last element of second array: " << b[b.size() - 1] << endl;
    cout << "Size of first array: " << a.size() << endl;
    cout << "Size of second array: " << b.size() << endl;
    cout << "Size of merged array: " << c.size() << endl;
    cout << "Median of merged array: " << median << endl;
    cout << "Merged array in ascending order: ";
    for (int i = 0; i < c.size(); i++) {
        cout << c[i] << " ";
    }
    cout << endl;
    cout << "Merged array in descending order: ";
    for (int i = c.size() - 1; i >= 0; i--) {
        cout << c[i] << " ";
    }
    cout << endl;
    cout << "First array in ascending order: ";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
