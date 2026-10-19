/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;
        stack<ListNode*>st;
        int l = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            l++;
            temp = temp->next;
        }
        temp = head;
        for (int i = 0; i < (l + 1) / 2; i++) {
            temp = temp->next;
        }
        while (temp != NULL) {
            st.push(temp);
            temp = temp->next;
        }

        temp = head;
         while (!st.empty()) {
            ListNode* last = st.top();
            st.pop();

            ListNode* nxt = temp->next;

            temp->next = last;
            last->next = nxt;

            temp = nxt;
        }
        temp->next = NULL;
    }
};