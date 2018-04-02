/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    ListNode* addNewCypher(ListNode *head, int val){
        ListNode *new_head = new ListNode(0);
        ListNode *new_node = new ListNode(val);
        if(!head){
            head = new_node;
            new_head = head;
        }
        else{
            new_head = head;
            while(head->next){
            head = head->next;
            }
            head->next = new_node;
        }
        return new_head;
    }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        bool end_reached = false;
	int rest = 0;


	ListNode* head = new ListNode(0);
	head = NULL;

	while (!end_reached) {
		int num1 = 0, num2 = 0, num = 0;

		if (l1) {
			num1 = l1->val;
			l1 = l1->next;
		}

		if (l2) {
			num2 = l2->val;
			l2 = l2->next;
		}

		num = num1 + num2 + rest;

		head = addNewCypher(head, num % 10);

		rest = num / 10;

		if ((!l1 && !l2) && rest == 0) {
			end_reached = true;
		}
	}
	return head;
        
    }
    
    
};