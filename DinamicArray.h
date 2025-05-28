#pragma once
#include "exeption.h"
#include <gtest/gtest.h>
template <class T>
class DynamicArray {
private:
    T* data;
    int size;

public:
    DynamicArray(const T* items, int count) {
        if (count < 0) {
            throw InvalidArgument();
        }
        size = count;
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = items[i];
        }
    }

    DynamicArray(int size) {

        if (size < 0) {
            throw InvalidArgument();
        }
        this->size = size;
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = T();
        }
    }

    DynamicArray(const DynamicArray<T>& other) {
        size = other.size;
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    ~DynamicArray() {
        delete[] data;
    }

    int GetSize() const {
        return size;
    }

    int Size() const {
        return size;
    }

    T Get(int index) const {
        if (index < 0) {
            throw IndexOutOfRange(); // code=0 => "index < 0?"
        }
        if (index >= size) {
            throw IndexOutOfRange(); // code=1 => "index >= size"
        }
        return data[index];
    }

    void Set(int index, const T& value) {
        if (index < 0) {
            throw IndexOutOfRange();
        }
        if (index >= size) {
            throw IndexOutOfRange();
        }
        data[index] = value;
    }

    void Resize(int newSize) {
        if (newSize < 0) {
            throw InvalidArgument();
        }
        T* newData = new T[newSize];
        int minSize = (newSize < size) ? newSize : size;
        for (int i = 0; i < minSize; i++) {
            newData[i] = data[i];
        }
        for (int i = minSize; i < newSize; i++) {
            newData[i] = T();
        }
        delete[] data;
        data = newData;
        size = newSize;
    }

};