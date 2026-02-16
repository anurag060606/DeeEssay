#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;

	Node(int data1, Node* next1){
		data=data1;
		next=next1;
	}

	Node(int data1){
		data=data1;
		next=nullptr;
	}
};

class Solution{
public:
	void insertAtHead(Node* &head, int val){
		Node* newNode=new Node(val, head);
		head=newNode;
	}
	void printList(Node* &head) {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
	Node* head=new Node(2);
	head->next=new Node(210);
	cout<<"Original list: "<<endl;
	Solution sol;
	sol.printList(head);
	sol.insertAtHead(head,12);

	cout<<"\nAltered array: \n";
	sol.printList(head);
}