#include "llrec.h"
//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
	if(head == NULL)
	{
		smaller = NULL;
		larger = NULL;
		return;
	}
	else if(head->next == NULL)
	{
		if(head->val > pivot)
		{
			larger = head;
			larger->next = NULL;
			smaller = NULL;
			head = NULL;
		}
		else
		{
			smaller = head;
			smaller->next = NULL;
			larger = NULL;
			head = NULL;
		}
	}
	else
	{
		llpivot(head->next, smaller, larger, pivot);
		if(head->val > pivot)
		{
			Node* temp = larger;
			larger = head;
			larger->next = temp;
		}
		else
		{
			Node* temp = smaller;
			smaller = head;
			smaller->next = temp;
		}
		head = NULL;
	}


}