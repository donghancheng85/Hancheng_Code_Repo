#include "LinkedList.cpp"	
#include <forward_list>

// function for finding the middle node
EduLinkedListNode* GetMiddleNode(EduLinkedListNode* head){

    // transfer data in the EduLinkedList to STL forward_list
    std::forward_list<int> temp_list;
    EduLinkedListNode* buffer_head = head;
    while(head)
    {
        temp_list.push_front(head->data);
        head = head->next;
    }
    temp_list.reverse(); // need to reverse, or the order of the list is reversed

    auto slow = temp_list.begin();
    auto fast = temp_list.begin();

    while (fast != temp_list.end() && std::distance(fast, temp_list.end()) != 1)
    {
        std::advance(slow, 1);
        std::advance(fast, 2);
    }

    int midpos = std::distance(temp_list.begin(), slow);

    for (int i=0; i<midpos; i++)
        buffer_head = buffer_head->next;
    
    return buffer_head;
}

int main()
{
    EduLinkedList mylist;
    mylist.CreateLinkedList({3,2,1});

    auto result = GetMiddleNode(mylist.head);

    std::cout << result->data << "\n\n";
}