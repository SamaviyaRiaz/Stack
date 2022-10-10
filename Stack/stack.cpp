#include <iostream>
using namespace std;
class Node
{
	private:
		int data;
		Node *next;
	public:
		Node(int data,Node *next=NULL)
		{
			setData(data);
			setNext(next);
		}
		void setData(int data)
		{
			this->data=data;
		}
		void setNext(Node *next)
		{
			this->next=next;
		}
		int getData()
		{
			return this->data;
		}
		Node* getNext()
		{
			return this->next;
		}
};

class LinkedList
{
	private:
		Node *head;
	public:
		LinkedList()
		{
			head=NULL;
		}
		LinkedList(Node *head)
		{
			this->head=head;
		}
		bool isEmpty()
		{
			return (head=NULL);
		}
         void insertAtBeginning(int value){
        Node * newNode = new Node(value);
        newNode -> setNext(head);
        head = newNode;
         }
        void removeFromBeginning(){
        if (!isEmpty()){
            if (head->getNext() == NULL){
                delete head;
                head = NULL;
            }
            else {
                Node * temp = head;
                temp = head -> getNext();
                delete head;
                head = temp;
                }
            }
        }
        int getLength(){
        if (!isEmpty()){
            int count = 0;
            Node * temp = head;
            while (temp != NULL){
                temp = temp -> getNext();
                count++;
                }
                return count;
            }
            return 0;
        }
        int getFirstElement(){
        if (!isEmpty()){
            return head->getData();
            }
			return -1;
        }
        void print(){
        Node * temp = head;
        while (temp != NULL){
            cout << temp -> getData()<< "->";
            temp = temp -> getNext();
        }
        cout << "NULL\n";
    }
};

class Stack
{
	private:
		LinkedList l1;
		int size;
	public:
		void setSize(int size)
	{
		this->size = size;
	}
	int getSize()
	{
		return size;
	}
	Stack(int size)
	{
		setSize(size);
	}
	bool push(int val)
	{
		if (!(isFull()))
		{
			l1.insertAtBeginning(val);
			return true;
		}
		else
		{
			cout << "\nStack is Full";
			return false;
		}
	}
	int pop()
	{
		if (!(isEmpty()))
		{
			int data = l1.getFirstElement();
			l1.removeFromBeginning();
			return data;
		}
		else
		{
			cout << "\nStack is Empty.";
		}
	}
	bool isEmpty()
	{
		return (l1.isEmpty()) ? true : false;
	}
	bool isFull()
	{
		int length = l1.getLength();
		return (length == size) ? true : false;
	}
	int getTop()
	{
		if (!(l1.isEmpty()))
		{
			return l1.getFirstElement();
		}
		else
		{
			cout << "\nStack is Empty.";
		}
	}
	void printStack()
	{
		l1.print();
	}
};

int main()
{
	Stack s1(10);
	s1.push(5);
	s1.setSize(15);
	s1.getSize();
	s1.getTop();
	s1.isEmpty();
	s1.isFull();
	s1.pop();
	s1.printStack();
	return 0;
}
