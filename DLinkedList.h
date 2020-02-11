#pragma once

#ifndef DLINKLIST_H
#define DLINKLIST_H

#include <iostream>

using namespace std;

template <class T>
class DLinkedList
{

	//PROVIDED
	friend ostream& operator<<(ostream& out, const DLinkedList<T>& rhs)
	{
		DNode* curr = rhs.header->next;
		while (curr != rhs.header)
		{
			out << curr->data << " ";
			curr = curr->next;
		}
		return out;
	}

public:

	//inner class DNode PROVIDED
	class DNode
	{
	public:
		DNode* next;
		DNode* prev;
		T data;

		DNode(T val = T())
		{
			data = val;
			next = prev = this;
		}

	};

	//create an empty list:  PROVIDED
	DLinkedList()
	{
		//create the header
		header = new DNode();
	}

	//add method  PROVIDED
	DNode* add(T item)
	{
		//add a new node and return a 
		//pointer to this node
		DNode* newNode = new DNode(item);
		newNode->prev = header;
		newNode->next = header->next;
		header->next->prev = newNode;
		header->next = newNode;
		return newNode;
	}

	/**
	* ASSIGNED
	* remove val from the list
	*
	* @param val
	* @return true if successful, false otherwise
	*/
	bool remove(T val)
	{

		DNode* curr = header->next;

		while (curr != header && curr->data != val)
		{
			curr = curr->next;
		}



		if (curr != header)
		{
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			delete curr;
			return true;

		}
		return false;
	}


	/**
	* ASSIGNED
	*
	* @param item
	*/
	void insertOrder(T item)
	{
		//cout << "in insert order..." << endl;
		cout << item << endl;

		DNode* curr = header->next;

		while (curr != header && curr->data < item)
		{
			curr = curr->next;

		}
		DNode* nn = new DNode(item);
		nn->next = curr;
		nn->prev = curr->prev;
		curr->prev->next = nn;
		curr->prev = nn;
	}

	/**
	* ASSIGNED
	*
	* @param item
	*/
	bool insertOrderUnique(T item)
	{
		if (contains(item) == false)
		{
			insertOrder(item);
		}

		return true;

	}

	/**
	* ASSIGNED
	* PRE:  this and rhs are sorted lists
	* @param rhs
	* @return list that contains this and rhs merged into a sorted list
	* POST:  returned list will not contain duplicates, both rhs and this
	* will have no elements
	*/
	DLinkedList merge(DLinkedList rhs) {
		DLinkedList result;
		DNode* Aptr, * Bptr;
		Aptr = header->next;
		Bptr = rhs.header->next;



		while (Aptr != header && Bptr != rhs.header) // updating relevant point
		{
			if (Aptr->data < (Bptr->data))
			{
				Aptr->prev->next = Aptr->next;
				Aptr->next->prev = Aptr->prev;
				Aptr->prev = result.header->prev;
				Aptr->next = result.header;
				result.header->prev->next = Aptr;
				result.header->prev = Aptr;
				Aptr = header->next;
			}
			else
			{
				Bptr->prev->next = Bptr->next;
				Bptr->next->prev = Bptr->prev;
				Bptr->prev = result.header->prev;
				Bptr->next = result.header;
				result.header->prev->next = Bptr;
				result.header->prev = Bptr;
				Bptr = rhs.header->next;

			}
		}

		cout << "outside while" << endl;

		return result;
	}


private:
	//DLinkedList fields:  PROVIDED
	DNode* header;

	bool contains(T v)
	{

		DNode* curr = header->next;
		while (curr != header)
		{
			if (curr->data == v)
				return true;
			curr = curr->next;
		}
		return false;

	}

};     //183


#endif