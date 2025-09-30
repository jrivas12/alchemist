#include <iostream>
#include <fstream>
using namespace std;

struct ListNode
{
	double value;
	ListNode *next;

	ListNode(double value1, ListNode *next1 = NULL)
	{
		value = value1;
		next = next1;
	}
};

int main()
{
	ifstream inFile;
	inFile.open("Grades.txt");
	ListNode *head= NULL;
	double value;
	for (int x=0; x<10; x++)
	{
		inFile>>value;
		head = new ListNode(value,head);
	}
	ListNode *ptr1;
	double temp;
	for (int x=0; x<10; x++)
	{
		ptr1=head;
		for (int y=0; y<10-1-x; y++)
		{
			if (ptr1->value > ptr1->next->value)
			{
				temp = ptr1->value;
				ptr1->value = ptr1->next->value;
				ptr1->next->value = temp;
			}
			ptr1=ptr1->next;
		}
	}


	ListNode *ptr = head;
	for (int x=0; x<10; x++)
	{
		cout<<ptr->value<<endl;
		ptr=ptr->next;
	}

	return 0;
}