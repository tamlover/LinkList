#pragma once

#include <iostream>
using namespace std;


template<class T>
struct Node // �ڵ�����ݽṹ
{
	T data;
	Node *next;

	Node() :next(nullptr){}  // �޲ι���
	Node(T t) :data(t), next(nullptr){} // ����������
};

template<class T>
class LinkList  //������
{
private:
	Node<T> *head; // ͷָ�� ���սڵ㣩
	Node<T> *tail; // βָ�� ���սڵ㣩
	int size;
public:
	LinkList()
	{
		head = new Node<T>;
		tail = new Node<T>;

		size = 0;
	}
	~LinkList()
	{

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
