#include <bits/stdc++.h>
using namespace std;

// Linked list düğümü
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// İki sayıyı toplama
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0); // Sonucu tutacak dummy baş
    ListNode* curr = dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
    }

    return dummy->next;
}

// Yardımcı fonksiyon: vektörü linked listeye çevirme
ListNode* vectorToList(const vector<int>& v) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    for (int x : v) {
        curr->next = new ListNode(x);
        curr = curr->next;
    }
    return dummy->next;
}

// Yardımcı fonksiyon: linked listeyi yazdırma
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Örnek 1
    vector<int> v1 = {2,4,3};
    vector<int> v2 = {5,6,4};
    ListNode* l1 = vectorToList(v1);
    ListNode* l2 = vectorToList(v2);
    ListNode* res = addTwoNumbers(l1, l2);
    printList(res); // 7 -> 0 -> 8

    // Örnek 2
    vector<int> v3 = {9,9,9,9,9,9,9};
    vector<int> v4 = {9,9,9,9};
    l1 = vectorToList(v3);
    l2 = vectorToList(v4);
    res = addTwoNumbers(l1, l2);
    printList(res); // 8 -> 9 -> 9 -> 9 -> 0 -> 0 -> 0 -> 1
}
