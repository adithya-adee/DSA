#include <iostream>

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode() : val{0}, next{nullptr} {};
    ListNode(int data) : val{data}, next{nullptr} {};
    ListNode(int data, ListNode *next) : val{data}, next{next} {};
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0); // Dummy head to simplify logic
        ListNode *temp = dummy;            // Pointer to build the result list
        int carry = 0;                     // Variable to store carry

        while (l1 || l2 || carry)
        {
            int sum = carry; // Start with carry from the previous addition
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;                    // Update carry
            temp->next = new ListNode(sum % 10); // Create a new node with the digit
            temp = temp->next;                   // Move to the next node
        }

        return dummy->next; // Return the actual head of the result list
    }
};

int main()
{
    // Create the first linked list: 2 -> 4 -> 3
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Create the second linked list: 5 -> 6 -> 4
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // Add the two numbers
    Solution s1;
    ListNode *result = s1.addTwoNumbers(l1, l2);

    // Print the result list
    std::cout << "Result: ";
    while (result)
    {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;

    // Clean up memory
    delete l1->next->next;
    delete l1->next;
    delete l1;

    delete l2->next->next;
    delete l2->next;
    delete l2;

    return 0;
}
