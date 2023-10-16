struct EduLinkedListNode {
	int data;
	EduLinkedListNode * next;
	EduLinkedListNode * arbitrary_pointer;
	EduLinkedListNode(int d) {
		data = d;
		next = nullptr;
		arbitrary_pointer = nullptr;
	}
};