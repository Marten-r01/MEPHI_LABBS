#pragma once
#include"ArraySequence.h"
template<class T>
class ImmutableArraySequence:public ArraySequence<T> {
public:
	ImmutableArraySequence(): ArraySequence<T>() {}

	ImmutableArraySequence(T* arr, int count) : ArraySequence<T>(arr, count) {}

	ImmutableArraySequence(const ImmutableArraySequence& other) : ArraySequence<T>(other) {}

	~ImmutableArraySequence() {}

	virtual Sequence<T>* Append(const T& item) override {
		ImmutableArraySequence<T>* new_arr = new ImmutableArraySequence<T>(*this);
		new_arr->Append(item);
		return new_arr;
	}

	virtual Sequence<T>* Prepend( const T& item)  override {
		ImmutableArraySequence<T>* new_arr = new ImmutableArraySequence<T>(*this);
		new_arr->Prepend(item);
		return new_arr;
	}

	virtual Sequence<T>* InsertAt(const T& item, int index)override {
		ImmutableArraySequence<T>* new_arr = new ImmutableArraySequence<T>(*this);
		new_arr->InsertAt(index, item);
		return new_arr;
	}

	virtual Sequence<T>* RemoveAt(int index) override {
		ImmutableArraySequence<T>* new_arr = new ImmutableArraySequence<T>(*this);
		new_arr->RemoveAt(index);
		return new_arr;
	}

	virtual Sequence<T>* Concat(const Sequence<T>* arr)const override {
		ImmutableArraySequence<T>* new_arr = new ImmutableArraySequence<T>(*this);
		new_arr->Concat(arr);
		return new_arr;
	}
};