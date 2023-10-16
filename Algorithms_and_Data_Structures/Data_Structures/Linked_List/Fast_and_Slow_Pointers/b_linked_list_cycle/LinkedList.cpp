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

	void CreateLinkedList(std::vector<int>& vec) {
		for (int i = vec.size() - 1; i >= 0; i--) {
			InsertAtHead(vec[i]);
		}
	}

	// returns the number of nodes in the linked list
    int GetLength(EduLinkedListNode* h){
        EduLinkedListNode *temp = h;
        int length = 0;
        while(temp!=nullptr){
            length+=1;
            temp = temp->next;
		}	
        return length;
    }

    // returns the node at the specified position(index) of the linked list
    EduLinkedListNode* GetNode(EduLinkedListNode* h, int pos){
        if (pos != -1){
            int p = 0;
            EduLinkedListNode* ptr = h;
            while (p < pos){
                ptr = ptr->next;
                p += 1;
            }
            return ptr;
        }
        return h;
    }

	
};