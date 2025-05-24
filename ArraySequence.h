#pragma once
#include "DinamicArray.h"
#include "Sequence.h"
#include "exeption.h"
template <class T>
class ArraySequence : public Sequence<T>, public DinamicArray<T>
{
private:
    DinamicArray<T>* array; 
public:
    ArraySequence(T* items, int count) : array(new DinamicArray<T>(items, count)) {}

    ArraySequence() : array(new DinamicArray<T>()) {}

    ArraySequence(int count) : array(new DinamicArray<T>(count)) {}

    ArraySequence(const ArraySequence<T>& other) : array(new DinamicArray<T>(*other.array)) {}


    ~ArraySequence()  { delete array; }

    virtual T GetFirst() const override {
        return array->Get(0);
    }

    virtual T GetLast() const override {
        return array->Get(array->GetSize()-1);
    }

    virtual T Get(int index) const override {
        return array->Get(index);
    }

    virtual int GetSize() const override {
        return array->GetSize();
    }
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) override {
        int subSize = endIndex - startIndex + 1;
        T* tempArray = new T[subSize];  // временный массив
        for (int i = 0; i < subSize; i++) {
            tempArray[i] = array->Get(startIndex + i);
        }
        ArraySequence<T>* result = new ArraySequence<T>(tempArray, subSize);
        delete[] tempArray;  // освобождаем временный массив
        return result;
    }

    virtual Sequence<T>* Append(const T& item) override{
        array->Resize(array->GetSize() + 1);
        array->Set(array->GetSize() - 1, item);
        return this;
    }
    virtual Sequence<T>* Prepend(const T& item) override {
        array->Resize(array->GetSize() + 1);
        for (int i = 0; i < array->GetSize() - 1; i++)
            array->Set(i + 1, array->Get(i));
        array->Set(0, item);
        return this;
    }
    virtual Sequence<T>* InsertAt(const T& item, int index) override {
        array->Resize(array->GetSize() + 1);
        for (int i = array->GetSize(); i > index; i--) {
            array->Set(i, array->Get(i - 1));
        }
        array->Set(index, item);
        return this;
    }

    virtual Sequence<T>* Concat(const Sequence<T>* other)const override {
        ArraySequence<T>* newSeq = new ArraySequence<T>(*this);
        for (int i = 0; i < other->GetSize(); i++) {
            newSeq->Append(other->Get(i));
        }
        return newSeq;
    }

    virtual Sequence<T>* RemoveAt(int index)  override{
        if (index < 0 || index >= array->GetSize()) {
            throw IndexOutOfRange();
        }
        for (int i = index; i < array->GetSize() - 1; i++) {
            array->Set(i, array->Get(i + 1));
        }
        array->Resize(array->GetSize() - 1); 
    }
    
};