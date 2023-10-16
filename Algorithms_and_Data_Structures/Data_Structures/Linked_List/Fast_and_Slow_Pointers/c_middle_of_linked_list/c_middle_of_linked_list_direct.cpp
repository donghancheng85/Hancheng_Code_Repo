#include "LinkedList.cpp"	

// function for finding the middle node
EduLinkedListNode* GetMiddleNode(EduLinkedListNode* head){

    EduLinkedListNode* slow = head;
    EduLinkedListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

int main()
{
    EduLinkedList mylist;
    mylist.CreateLinkedList({3,2,1});

    auto result = GetMiddleNode(mylist.head);

    std::cout << result->data << "\n\n";
}