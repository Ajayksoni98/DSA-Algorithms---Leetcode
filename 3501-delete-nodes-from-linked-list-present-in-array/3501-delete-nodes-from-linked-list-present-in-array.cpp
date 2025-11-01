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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

        int n = nums.size();

        unordered_map<int,int> mp;



        ListNode *temp = head;
        for(auto x: nums)
        {
            mp[x]++;
          //  temp = temp-> next;
        }

        temp = NULL;
        ListNode* cur = head;
        while(cur)
        {
            if(cur == head && mp.find(cur->val) != mp.end())
            {
                
                cur = cur->next; 
                head = cur;
            }
            else if(cur && cur->next == NULL && mp.find(cur->val) != mp.end())
            {
                ListNode *node = cur;
                temp->next = NULL;
                delete(node);
                return head;
            }
            else if(mp.find(cur->val) != mp.end())
            {
                temp->next = cur->next;
                ListNode *node = cur;
                cur = temp->next;
                delete(node);
            }
            else
                {
                   temp = cur;
                   cur = cur->next;
                }


        }

        return head;

        
    }
};