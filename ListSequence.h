#pragma once
#include "Sequence.h"
#include"LinkedList.h"
#include"exeption.h"
template <class T>
class ListSequence :public Sequence<T>, public LinkedList<T> {
private:
	LinkedList<T>* list;
public:
    ListSequence(T* items, int count) : list(new LinkedList<T>(items, count)) {}
    ListSequence() : list(new LinkedList<T>()) {}
    ListSequence(const ListSequence<T>& other) : list(new LinkedList<T>(*other.list)) {}
    ~ListSequence() override { delete list; }
    
    T GetFirst() const override { return list->GetFirst(); }
    T GetLast() const override { return list->GetLast(); }
    T Get(int index) const override { return list->Get(index); }

    virtual Sequence<T>* GetSubsequence(int Startindex, int Endindex)  override {
        if(Startindex<0||Endindex>=list->GetSize()||Endindex<Startindex) throw IndexOutOfRange();
        LinkedList<T> sublist = list->GetSubList(Startindex, Endindex);
        return new ListSequence<T>(* sublist);
    }
    virtual Sequence<T>* Append(T item)  override{
        list->Append(item);
        return this;
    }
    virtual Sequence<T>* Prepend(T item) override {
        list->Prepend(item);
        return this;
    }
    virtual Sequence<T>* InsertAt(T item, int index) override {
        list->InsertAt(item, index);
        return this;
    }
    virtual Sequence<T>*  RemoveAt(int index)  override{
        list->RemoveAt(index);
        return this;
    }
};