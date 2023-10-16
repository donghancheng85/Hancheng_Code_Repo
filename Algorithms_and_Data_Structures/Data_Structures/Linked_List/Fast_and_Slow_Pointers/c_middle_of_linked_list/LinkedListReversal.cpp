// Template for reversing a linked list

EduLinkedListNode* ReverseLinkedList(EduLinkedListNode* head){
	EduLinkedListNode* current = head; 
	EduLinkedListNode* prev = nullptr; 
    EduLinkedListNode* nxt = nullptr; 
	while (current != nullptr){
      nxt = current->next;
	  current->next = prev;
	  prev = current;
	  current = nxt;
	}
	return prev;
}