#pragma once
#include "exeption.h"
using namespace std;
template<typename T>
class DinamicArray {
	T* m_arr;
	int m_size;
	int m_capacity;
public:
	DinamicArray() : m_arr(nullptr), m_size(0), m_capacity(0) {}

	DinamicArray(T* items, int count) {
		m_arr = new T[count];
		for (int i = 0; i < count; i++)
			m_arr[i] = items[i];
		m_size = m_capacity = count;
	}
	DinamicArray(int size) {
		if (size > 0) {
			m_capacity = size;
			m_size = 0;
			m_arr = new T[size];
		}
		else {
			m_arr = nullptr;
			m_size = m_capacity = 0;
		}
	}
	DinamicArray(const DinamicArray<T> & other ) {
		this->m_size = other.m_size;
		this->m_capacity = other.m_capacity;
		this->m_arr = new T[m_capacity];
		for (int i = 0; i < m_size; i++) {
			this->m_arr[i] = m_arr[i];
		}
	}
	T Get(int index) {
		if (index < 0 || index >= m_size)
			throw IndexOutOfRange();
		return m_arr[index];
	}
	int GetSize() {
		return m_size;
	}
	void Set(int index, T value) {
		if (index<0 || index > m_size || index>=m_capacity)
			throw IndexOutOfRange();
		m_arr[index] = value;
	}
	void Resize(int newSize) {
		if (newSize < 0) throw MemoryAllocationError();
		if (newSize < m_capacity) return;

		T* new_m_arr = new T[newSize];
		for (int i = 0; i < m_size; i++) {
			new_m_arr[i] = m_arr[i];
		}
		m_capacity = newSize;
		delete[] m_arr;
		m_arr = new_m_arr;
		return;
	}
	~DinamicArray() {
		delete[] m_arr;
	}

};
/*template <typename T>
bool operator=(const DinamicArray<T>& a, const DinamicArray<T>& b) {
	if (a->m_capacity == b->m_capacity) {
		for (int i = 0;i<)
	}
	return false;
}*/