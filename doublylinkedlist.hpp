#pragma once

/*
	��δ����
*/

template<class T>
class LinkList  //������
{
protected:
	struct Node // �ڵ�����ݽṹ
	{
		T data;
		Node *next;
		Node *pre;

		Node() :next(nullptr), pre(nullptr){}  // �޲ι���
		Node(T t) :data(t), next(nullptr), pre(nullptr){} // ����������
	};

private:
	Node *head; // ͷָ�� ���սڵ㣩
	Node *tail; // βָ�� ���սڵ㣩
	int size;
public:
	LinkList()
	{
		head = new Node;
		tail = new Node;

		size = 0;
	}
	~LinkList()
	{
		clear();
		delete head;
		delete tail;
	}
public:
   /**
    *	�������ͷ�������½ڵ�
    *		@param val�������½ڵ��ֵ
	*/
	void insertOnHead(T val);

   /**
	*	�������β�������½ڵ�
	*		@param val�������½ڵ��ֵ
	*/
	void insertOnTail(T val); 

   /**
	*	�������ĳһλ�ò����½ڵ㣬����ɹ�����true�����򷵻�false
	*		@param i��ָ����λ��
	*		@param val�������½ڵ��ֵ
	*/
	bool insert(int i,T val); 

   /**
	*	��ȡĳ�ڵ��ֵ����ȡ�ɹ�����true�����򷵻�false
	*		@param i��ָ����λ��
	*		@param val�������½ڵ��ֵ	
	*/
	bool getData(int i,T &val); 

   /**
	*	�жϿգ��յĻ�����true�����򷵻�false
	*/
	bool isEmpty(); 

   /**
	*	�������
	*/
	void clear(); 

   /**
	*	��ӡ����
	*/
	void printList();
};

template<class T>
void LinkList<T>::insertOnHead(T val)
{
	Node *newNode = new Node;
	newNode->data = val;
	newNode->pre = head;
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
	newNode->pre = tail->next;
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
			newNode->pre = temp;
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


