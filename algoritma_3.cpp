// listleri birlesdirmek 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()  
{

//one list
    vector<int> a{1, 3, 5, 7, 9};

//two list
    vector<int> b{1, 2, 3, 4, 6, 8, 10};      
//thri list
    vector<int> c{11, 12};
//connecting all lists
       vector<int> ab(a.size() + b.size());
       merge(a.begin(), a.end(), b.begin(), b.end(), ab.begin());
       vector<int> d(ab.size() + c.size());
       merge(ab.begin(), ab.end(), c.begin(), c.end(), d.begin());
// Finding the same numbers in the lists and writing them in order from smallest to largest
       vector<int> same;

//fast exit for empty pattern
     
     
       for (int i = 0; i < d.size(); i++) {
           if (i > 0 && d[i] == d[i - 1]) {
               same.push_back(d[i]);
           }
       }
// Finding the same numbers in the lists and writing them in reverse order
       vector<int> same_reverse(same.rbegin(), same.rend());
// Output the results
    cout << "Merged list: ";
    for (int i = 0; i < d.size(); i++) {

        cout << d[i] << " ";
    }
    cout << endl;
  
    return 0; // This is a placeholder to complete the code structure.
}