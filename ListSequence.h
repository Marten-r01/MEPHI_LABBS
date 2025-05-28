#pragma once
#pragma once
#include "Sequence.h"
#include "LinkedList.h"
#include "exeption.h"
#include <gtest/gtest.h>

template <class T>
class ListSequence : public Sequence<T> {
private:
    LinkedList<T>* list;
public:
    ListSequence(T* items, int count) : list(new LinkedList<T>(items, count)) {}
    ListSequence() : list(new LinkedList<T>()) {}  
    ListSequence(const ListSequence<T>& other) : list(new LinkedList<T>(*other.list)) {}
    ~ListSequence() override { delete list; }

    ListSequence(const LinkedList<T>& inputList) : list(new LinkedList<T>(inputList)) {}

    virtual T GetFirst() const override { return list->GetFirst(); }

    virtual T GetLast() const override { return list->GetLast(); }

    virtual T Get(int index) const override { return list->Get(index); }

    virtual int GetSize() const override { return list->GetSize(); }

    virtual ListSequence<T>* GetSubsequence(int Startindex, int Endindex) const override {
        if (Startindex < 0 || Endindex >= list->GetSize() || Endindex < Startindex) throw IndexOutOfRange();
        LinkedList<T>* sublist = list->GetSubList(Startindex, Endindex);
        ListSequence<T>* result = new ListSequence<T>(*sublist);
        delete sublist;
        return result;
    }

    virtual ListSequence<T>* Append(const T& item) override {
        list->Append(item);
        return this;
    }

    virtual ListSequence<T>* Prepend(const T& item) override {
        list->Prepend(item);
        return this;
    }

    virtual ListSequence<T>* InsertAt(const T& item, int index) override {
        list->InsertAt(item, index);
        return this;
    }

    virtual ListSequence<T>* RemoveAt(int index) override {
        list->RemoveAt(index);
        return this;
    }
    virtual Sequence<T>* Concat(const Sequence<T>* other) override {
        ListSequence<T>* newSeq = new ListSequence<T>(*this);
        for (int i = 0; i < other->GetSize(); i++) {
            newSeq->Append(other->Get(i));
        }
        return newSeq;
    }
};
