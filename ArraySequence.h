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
    ArraySequence(const ArraySequence<T>& other) : array(new DinamicArray<T>(*other.array)) {}
    ~ArraySequence() override { delete array; }

    virtual T GetFirst() const override {
        if (array->GetSize() == 0)throw InvalidArgument();
        return array->Get(0);
    }
    virtual T GetFirst() const override {
        if (array->GetSize() == 0)throw InvalidArgument();
        return array->Get(array->GetSize()-1);
    }
    virtual T Get(int index) const override {
        if (index < 0 || index >= array->GetSize())throw IndexOutOfRange();
        return array->Get(index);
    }
    virtual int GetSize() const override {
        return arrqy->GetSize();
    }
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const override {
        if (startIndex<0) throw InvalidArgument();
        if(endIndex>=array->GetSize()||endIndex<startIndex) throw IndexOutOfRange();
        DinamicArray<T>* subArray = new DinamicArray<T>(endIndex - startIndex + 1);
        for (int i = startIndex; i <= endIndex; i++) {
            subArray->Set(i - startIndex, array->Get(i));
        }
        return new ArraySequence<T>(*subArray);
    }
    virtual Sequence<T>* Append(T item) const override{
        array->Resize(array->GetSize() + 1);
        array->Set(array->GetSize() - 1, item);
        return this;
    }
    virtual Sequence<T>* Prepend(T item) const override {
        array->Resize(array->GetSize() + 1);
        for (int i = 0; i < array->GetSize() - 1; i++)
            array->Set(i + 1, array->Get(i));
        array->Set(0, item);
        return this;
    }
    virtual Sequence<T>* InsertAt(int index, T item) const override {
        if (index<0||index>=array->GetSize) throw IndexOutOfRange();
        array->Resize(array->GetSize() + 1);
        for (int i = array->GetSize(); i > index; i--) {
            array->Set(i, array->Get(i - 1));
        }
        array->Set(index, item);
        return this;
    }
    virtual Sequence<T>* Concat(Sequence<T>* other) const override {
        int oldSize = array->GetSize();
        int otherSize = other->GetLength();
        array->Resize(oldSize + otherSize);
        // Копируем элементы из other
        for (int i = 0; i < otherSize; i++) {
            array->Set(oldSize + i, other->Get(i));
        }
        return this;
    }
    virtual Sequence<T>* RemoveAt(int index) const override{
        if (index < 0 || index >= array->GetSize()) {
            throw IndexOutOfRange();
        }
        for (int i = index; i < array->GetSize() - 1; i++) {
            array->Set(i, array->Get(i + 1));
        }
        array->Resize(array->GetSize() - 1); 
    }
};