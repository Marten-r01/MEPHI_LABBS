#pragma once
#include "ListSequence.h"
template <class T>
class ImmutableListSequence :ListSequence<T> {
	ImmutableListSequence() :ListSequence<T>(){}
	ImmutableListSequence(T* item, int count) : ListSequence<T>(item, count) {}
	ImmutableListSequence(const ListSequence<T>& arr) : ListSequence<T>(arr) {}
	~ImmutableListSequence() {}
	virtual ListSequence<T> Append(const T& item)  override {
		ImmutableListSequence<T>* new_list = new ImmutableListSequence<T>(*this);
		new_list->Append(item);
		return new_list;
	}
	virtual ListSequence<T> Prepend(const T& item)  override {
		ImmutableListSequence<T>* new_list = new ImmutableListSequence<T>(*this);
		new_list->Prepend(item);
		return new_list;
	}
	virtual ListSequence<T> RemoveAt(int index)  override {
		ImmutableListSequence<T>* new_list = new ImmutableListSequence<T>(*this);
		new_list->RemoveAt(index);
		return new_list;
	}
	virtual ListSequence<T> InsertAt(const T& item, int index)  override {
		ImmutableListSequence<T>* new_list = new ImmutableListSequence<T>(*this);
		new_list->InsertAt(item, index);
		return new_list;
	}
};