#include "LinkedList.cpp"
#include <iostream>

bool DetectCycle(EduLinkedListNode* head)
{
    // init 2 pointers, slow and fast
    auto slow = head;
    auto fast = head->next;

    // traverse the linked list, slow move 1 and fast move 2 ahead
    while( slow != fast && fast != nullptr )
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != nullptr)
            fast = fast->next;
    }
  
    if(fast == slow)
        return true;
    
    return false;
}

int main()
{
    // EduLinkedListNode* head = new EduLinkedListNode{9};
    std::vector<int> myvec {1,3,5,7,9};
    EduLinkedList ll;

    ll.CreateLinkedList(myvec);

    auto result = DetectCycle(ll.head);

    std::cout << std::boolalpha << result << "\n\n";
}