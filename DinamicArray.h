#pragma once
#include "exeption.h"
using namespace std;
template<typename T>
class DinamicArray {
	T* m_arr;
	size_t m_size;
	size_t m_capacity;
public:
	DinamicArray(T* items, int count) {
		m_arr = new T[count];
		for (int i = 0; i < count; i++)
			m_arr[i] = items[i];
		m_size = m_capacity = (size_t)count;
	}
	DinamicArray(int size) {
		if (size > 0) {
			m_capacity = (size_t)size;
			m_size = 0;
			m_arr = new T[size];
		}
		else {
			m_arr = nullptr;
			m_size = m_capacity = 0;
		}
	}
	DinamicArray(const DinamicArray<T> & DinamicArray ) {
		this->m_size = m_size;
		this->m_capacity = m_capacity;
		this->m_arr = new T[m_capacity];
		for (int i = 0; i < m_size; i++) {
			this->m_arr[i] = m_arr[i];
		}
	}
	T Get(int index) {
		if (index < 0 || index >= (int)m_size)
			throw IndexOutOfRange();
		return m_arr[index];
	}
	int GetSize() {
		return (int)m_size;
	}
	void Set(int index, T value) {
		if (index<0 || index >= (int)m_size || index>(int)m_capacity)
			throw IndexOutOfRange();
		m_arr[index] = value;
	}
	void Resize(int newSize) {
		if (newSize < 0)
			throw MemoryAllocationError();
		if (newSize < m_capacity)
			return;
		T* new_m_arr = new T[newSize];
		for (int i = 0; i < m_size; i++) {
			new_m_arr[i] = m_arr[i];
		}
		size = newSize;
		m_arr = new_m_arr;
		delete[] new_m_arr;
		return;
	}
	~DinamicArray() {
		delete[] m_arr;
	}
};