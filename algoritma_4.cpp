//Reverse Nodes in k-Group
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {                    
        if (!head || k <= 1) return head; // Check for empty list or k <= 1

        ListNode* current = head;
        int count = 0;

        // Check if there are at least k nodes in the list
   for(current = head; current && count < k; current = current->next) {
        count++;
    }

        // If we have k nodes, reverse them
        if (count == k) {
            ListNode* prev = nullptr;
            ListNode* next = nullptr;
            current = head;

            for (int i = 0; i < k; i++) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }

            // Recursively call for the next part of the list
            if (next) {
                head->next = reverseKGroup(next, k);
            }

            return prev; // New head of the reversed group
        }

        return head; 
    }   
};
           
int main() {
   Solution solution;
   ListNode* head = new ListNode(1);
   head->next = new ListNode(2);
   head->next->next = new ListNode(3);
   head->next->next->next = new ListNode(4);
   head->next->next->next->next = new ListNode(5);
   int k = 2;
   ListNode* newHead = solution.reverseKGroup(head, k); 
}