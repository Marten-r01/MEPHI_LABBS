#pragma once
#include "DinamicArray.h"
#include "Sequence.h"
#include "exeption.h"
#include <gtest/gtest.h>
template <class T>
class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T>* items;
    int count;
public:
    ArraySequence() {
        items = new DynamicArray<T>(4);
        count = 0;
    }

    ArraySequence(const T* arr, int length) {
        items = new DynamicArray<T>(length);
        for (int i = 0; i < length; i++) {
            items->Set(i, arr[i]);
        }
        count = length;
    }

    ArraySequence(const ArraySequence<T>& other) {
        count = other.count;
        items = new DynamicArray<T>(*other.items);
    }

    virtual ~ArraySequence() {
        delete items;
    }

    virtual T GetFirst() const override {
        return items->Get(0);
    }

    virtual T GetLast() const override {
        return items->Get(count - 1);
    }

    virtual T Get(int index) const override {
        return items->Get(index);
    }

    virtual int GetSize() const override {
        return count;
    }

    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const override {
        int newLen = endIndex - startIndex + 1;
        T* temp = new T[newLen];
        for (int i = 0; i < newLen; i++) {
            temp[i] = items->Get(startIndex + i);
        }
        ArraySequence<T>* result = new ArraySequence<T>(temp, newLen);
        delete[] temp;
        return result;
    }

    virtual Sequence<T>* Append(const T& item) override {
        if (count == items->Size()) {
            items->Resize(items->Size() * 2);
        }
        items->Set(count, item);
        count++;
        return this;
    }

    virtual Sequence<T>* RemoveAt(int index) override {
        for (int i = index; i < count - 1; i++) {
            items->Set(i, items->Get(i + 1));
        }
        count--;
        return this;
    }

    virtual Sequence<T>* Prepend(const T& item) override {
        if (count == items->Size()) {
            items->Resize(items->Size() * 2);
        }
        for (int i = count; i > 0; i--) {
            items->Set(i, items->Get(i - 1));
        }
        items->Set(0, item);
        count++;
        return this;
    }

    virtual Sequence<T>* InsertAt(const T& item, int index) override {
        if (count == items->Size()) {
            items->Resize(items->Size() * 2);
        }
        for (int i = count; i > index; i--) {
            items->Set(i, items->Get(i - 1));
        }
        items->Set(index, item);
        count++;
        return this;
    }

    virtual Sequence<T>* Concat(const Sequence<T>* seq) const override {
        ArraySequence<T>* newSeq = new ArraySequence<T>(*this);
        for (int i = 0; i < seq->GetSize(); i++) {
            newSeq->Append(seq->Get(i));
        }
        return newSeq;
    }
};