#pragma once
#include"exeption.h"
using namespace std;
template <typename T>
class LinkedList {
	struct List {
		List* next;
		List* past;
		T data;
		List(const T& value, List* n = nullptr, List* p = nullptr) {
			data = value;
			next = n;
			past = p;
		}
	};
	List* start_el;
	List* end_el;
	size_t size;
public:
	LinkedList() : start_el(nullptr), end_el(nullptr), size(0){}
	
	LinkedList(const LinkedList<T>& str) {
		List* cur = str.start_el;
		while (cur) {
			Append(cur->data);
			cur = cur->next;
		}

	}
	void Append(const T& item) {
		List* newlist = new List(item);
		if (size == 0) {
			start_el = end_el = newlist;
		}
		else {
			end_el->next = newlist;
			newlist->past = end_el;
			end_el = newlist;
		}
		size++;
	}
	T GetFirst() {
		if (size == 0)
			throw InvalidArgument();
		return start_el->data;
	}
	T GetLast() {
		if (size == 0)
			throw InvalidArgument();
		return end_el->data;
	}
	T Get(int index) {
		if (index < 0 || index >= size)
			throw IndexOutOfRange();
		List* cur = start_el;
		for (int i = 0; i <= index; i++) {
			cur = cur->next;
		}
		return cur->data;
	}
	LinkedList<T>* GetSubList(int startIndex, int endIndex) {
		if (startIndex < 0 || endIndex < 0)
			throw IndexOutOfRange();
		if (startIndex>=size || endIndex>= size || startIndex>endIndex)
			throw IndexOutOfRange();
		LinkedList<T>* cut = new LinkedList<T>;
		List* cur = start_el;
		for (int i = 0; i < startIndex; i++)
			cur = cur->next;
		for (int i = startIndex; i < endIndex; i++)
		{
			cut->Append(cur->data);
			cur = cur->next;
		}
		return cut;
	}
	int GetSize() {
		return size;
	}
	void Prepend(T item) {
		List head = new List(item);
		if (size == 0)
		{
			head->next = head->past = head;
		}
		else {
			head->next = start_el;
			start_el->past = head;
			start_el = head;
		}
		size++;
	}
	void InsertAt(T item, int index) {
		if (index<0 || index>size)
			throw IndexOutOfRange();
		List add_el = new List;
		add_el->data = item;
		List* cur = start_el;
		for (int i = 0; i < index; i++) {
			cur = cur->next;
		}
		add_el->past = &cur;
		if (cur->next != nullptr) {
			List* after = cur->next;
			after->past = &add_el;
		}
		add_el->next = cur->next;
		cur->next = &add_el;
		size++;
	}
	LinkedList<T>* Concat(LinkedList<T>* list) {
		if (list->size == 0)
			return this;
		else if (this->size == 0)
		{
			this->start_el = list->start_el;
			this->end_el = list->end_el;
			this->size = list->size;
		}
		else {
			this->end_el->next = list->start_el;
			list->start_el->past = this->end_el;
			this->size += list->size;
			list->end_el = nullptr;
			list->start_el = nullptr;
			list->size = 0;
		}
		return this;
	}
	void RemoveAt(int index) {
		if(index<0||index>=size) throw IndexOutOfRange();
		else if (index == 0) {
			List* temp = start_el;
			start_el = start_el->next;
			delete(temp);
			size--;
		}
		else {
			List* cur = start_el;
			for (int i = 0; i < index - 1; i++) {
				cur = cur->next;
			}
			List* del_el = cur->next;
			cur->next = del_el->next;
			delete(del_el);
			size--;
			if (index == size) end_el=cur;
		}
		return;
	}
};
