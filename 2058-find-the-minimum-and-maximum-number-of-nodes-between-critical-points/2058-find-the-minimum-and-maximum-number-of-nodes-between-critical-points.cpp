class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;

        ListNode* slow = head;
        ListNode* curr = head->next;
        ListNode* fast = head->next->next;
        int index = 1;
        while (fast != nullptr) {
            if ((slow->val > curr->val && curr->val < fast->val) ||
                (slow->val < curr->val && curr->val > fast->val)) {
                ans.push_back(index);
            }
            slow = slow->next;
            curr = curr->next;
            fast = fast->next;
            index++;
        }
        if (ans.size() < 2) return {-1, -1};
        int mini = INT_MAX;
        for (int i = 1; i < ans.size(); i++) {
            mini = min(mini, ans[i] - ans[i - 1]);
        }
        int maxi = ans.back() - ans.front();
        return {mini, maxi};
    }
};