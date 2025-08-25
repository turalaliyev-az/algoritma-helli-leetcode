//Trapping rain water
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int trap(vector<int>& height) {
    /*
   //two pointer approach
   int left = 0, right = height.size() - 1;
   int leftMax = 0, rightMax = 0;
   int water = 0;
   while(left < right){
       if(height[left] < height[right]){
           if(height[left] >= leftMax){
               leftMax = height[left];
           }else{
               water += leftMax - height[left]; 
           }

              left++;
         }else{
           if(height[right] >= rightMax){
               rightMax = height[right];
           }else{
               water += rightMax - height[right]; 
           }
           right--;
         }
   }
   return water;   
   */ 
   //stack approach
   stack<int> st;
   int water = 0;
    for(int i = 0; i < height.size(); i++){
         while(!st.empty() && height[i] > height[st.top()]){
              int top = st.top();
              st.pop();
              if(st.empty()) break;
              int distance = i - st.top() - 1;
              int boundedHeight = min(height[i], height[st.top()]) - height[top];
              water += distance * boundedHeight;
         }
         st.push(i);
    }
    return water;

}
};

int main(){
    Solution sol;
    vector<int> height = {0,1,0,2,1,0,
                            1,3,2,1,2,1};
    cout << sol.trap(height) << endl;
    return 0;
}