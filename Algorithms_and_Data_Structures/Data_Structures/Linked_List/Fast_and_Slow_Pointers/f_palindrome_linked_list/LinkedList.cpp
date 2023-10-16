#include <iostream>
#include <string>
#include <vector>
#include "LinkedListNode.cpp"

class EduLinkedList {
public:
	EduLinkedListNode* head;

	EduLinkedList() { head = nullptr; }
	EduLinkedList(EduLinkedListNode* h) {
		 head = h; 
	}

	void InsertAtHead(int data) {
		if (head == nullptr) {
			head = new EduLinkedListNode(data);
		} else {
			EduLinkedListNode* new_node = new EduLinkedListNode(data);
			new_node->next = head;
			head = new_node;
		}
	}

	void InsertAtTail(int data) {
		if (head == nullptr) {
			head = new EduLinkedListNode(data);
		} else {
			EduLinkedListNode* new_node = new EduLinkedListNode(data);
			EduLinkedListNode* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = new_node;
		}
	}

	void CreateLinkedList(const std::vector<int>& vec) {
		for (int i = vec.size() - 1; i >= 0; i--) {
			InsertAtHead(vec[i]);
		}
	}
	
};