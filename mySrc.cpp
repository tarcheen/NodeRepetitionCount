#include "node.h"

int main()
{
	/* Create Linear Link List including the following data  1 , 4 , 2, 2, 1, 3, 2, 2, 1 */
	node* head = new node;
	node* temp = head;
	temp->data = 1;

	temp->next = new node;
	temp = temp->next;
	temp->data = 4;
	
	temp->next = new node;
	temp = temp->next;
	temp->data = 2;

	temp->next = new node;
	temp = temp->next;
	temp->data = 2;

	temp->next = new node;
	temp = temp->next;
	temp->data = 1;

	temp->next = new node;
	temp = temp->next;
	temp->data = 3;

	temp->next = new node;
	temp = temp->next;
	temp->data = 2;

	temp->next = new node;
	temp = temp->next;
	temp->data = 2;

	temp->next = new node;
	temp = temp->next;
	temp->data = 1;
	
	/* display all nodes */
	display_node_data(head);		

	/* print result */
	node* result = most_repeat_node(head);
	cout << "Node: "<<result<< " which contains: "<<result->data << " has the most repeats"<<endl;

}