# ifndef FLAG
# define FLAG

#include <iostream>
#include <set>

using std::cout;
using std::endl;


struct node
{
	int data;
	node* next = nullptr;
};

/* display all nodes value */
void display_node_data(node* n)
{
	while (n->next != nullptr)
	{
		cout << "node: "<<n<< " includes data: " << n->data << endl;
		n = n->next;
	}
	cout << "node: " << n << " includes data: " << n->data << endl;
	cout << ">>-----------------------------------------<<" << endl;
}

/* method that counts the number of nodes in a Linear Link List */
int count_nodes(node* head)
{
	int count = 1;
	while (head->next != nullptr)
	{
		++count;
		head = head->next;
	}

	return count;
}


/* code that counts repetition of the node */
int count_repeats(node* n)
{
	int count = 1;
	int value = n->data;
	while (n->next != nullptr)
	{
		n = n->next;
		if (n->data == value)
			++count;
	}
	return count;
}

bool check_duplicate_nodes(node* forward, std::set<int>* nodeSet)
{
	return nodeSet->find(forward->data) != nodeSet->end();
}

node* most_repeat_node(node* n)
{

	node* result = n;							// points to the final answer
	node* forward = n->next;					// temporary node pointer which traverses throught the LLL

	if (count_nodes(n) <= 2)					// if size of the link list is 1 or 2, return the first node
		return result;

	int to_beat = count_repeats(result);		// count the first node repeation
	int temp_result;
	std::set<int> numbers;						// store data anytime we go through a node

	while (forward->next != nullptr)
	{
		
		if (check_duplicate_nodes(forward, &numbers))			// check whether we already check the node with that data ( if forward use to point to data 2, we dont want to check for data 2 again for future
		{
			forward = forward->next;
			continue;
		}

		temp_result = count_repeats(forward);	// count second node repetition 
		if (temp_result > to_beat)				// if future nodes beat the current count
		{
			to_beat = temp_result;				// update the to beat count
			result = forward;					// point the final answer to the current node the forward is pointing
		}

		numbers.insert(forward->data);
		forward = forward->next;				// lets check next node
	}

	return result;
}


#endif
