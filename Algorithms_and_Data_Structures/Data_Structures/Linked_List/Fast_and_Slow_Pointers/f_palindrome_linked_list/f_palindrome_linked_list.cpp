#include "LinkedList.cpp"	
#include "LinkedListReverse.cpp"
#include <list>

// Tip: You may use some of the code templates provided
// in the support files

// Check palindrome in linkedList  
bool Palindrome(EduLinkedListNode* head)
{
    if (head->next == nullptr)
        return true;

    auto slow = head;
    auto fast = head;
    std::list<int> second_half;

    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // now slow is in the center of the linked list
    // store the second half of linked list to second_half
    auto mid = slow;
    while(slow)
    {
        second_half.push_front(slow->data);
        slow = slow->next;
    }

    auto it = second_half.begin();
    while (head != mid)
    {
        if (head->data != *it)
            return false;
        head = head->next;
        it++;
    }

    return true;
}

int main()
{
    EduLinkedList mylist;
    mylist.CreateLinkedList({3,6,9,8,4,8,9,6,3});

    std::cout << std::boolalpha << Palindrome(mylist.head) << "\n\n";
}