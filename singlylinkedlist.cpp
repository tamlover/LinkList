#include "singlylinkedlist.h"

template<class T>
void LinkList<T>::insertOnHead(T val)
{
	Node *newNode = new Node;
	newNode->data = val;
	newNode->next = head->next;
	head->next = newNode;

	if (!size)
		tail->next = newNode; // ��βָ��ָ���һ���ڵ�
	++size;
}
template<class T>
void LinkList<T>::insertOnTail(T val)
{
	Node *newNode = new Node;
	newNode->data = val;
	newNode->next = nullptr;
	tail->next->next = newNode;
	tail->next = newNode;
	++size;
}
template<class T>
bool LinkList<T>::insert(int i,T val)
{
	if (i <= 0|| i > size)
		return false;

	Node *newNode = new Node;
	Node *temp = head;

	if (i == size)
		tail->next = newNode; // ����������룬����βָ��

	for (int j = 0; j <= size; ++j)
	{
		if (i != 0)
		{
			temp = temp->next;
			--i;
		}
		else
		{
			newNode->data = val;
			newNode->next = temp->next;
			temp->next = newNode;
			break;
		}
			
	}

	++size;
	return true;
	
	
}

template<class T>
bool LinkList<T>::getData(int i, T &val)
{
	if (i <= size && i > 0)
	{
		Node *temp = head;
		for (int j = 0; j < i; ++j)
		{
			temp = temp->next;
		}
		val = temp->data;
		return true;
	}
	else
	{
		return false;
	}
}
template<class T>
bool LinkList<T>::isEmpty()
{
	return size ? false : true;
}
template<class T>
void LinkList<T>::clear()
{
	Node *tempFront = head->next;  // ָ����һ����ɾ��
	Node *tempBack = head->next;   // ָ���ɾ����Ԫ��
	for (int i = 0; i < size; ++i)
	{
		tempBack = tempFront;
		tempFront = tempFront->next;
		delete tempBack;
	}
	size = 0;
}
template<class T>
void LinkList<T>::printList()
{
	if (!size)
	{
		cout << "empty link" << endl;
		return;
	}

	Node * temp = head->next;
	for (int i = 0; i < size; ++i)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}
