// #include "LinkedListNode.cpp"

// Revert the second half of the linked_list to 
// compare it with the first half
// EduLinkedListNode* ReversedList(EduLinkedListNode* slowPtr){
//   EduLinkedListNode* prev = nullptr;
//   EduLinkedListNode* next = nullptr;
//   EduLinkedListNode* curr = slowPtr;
//   while(curr != nullptr){
//     next = curr->next;
//     curr->next = prev;
//     prev = curr;
//     curr = next;
//   }
//   return prev;
// }