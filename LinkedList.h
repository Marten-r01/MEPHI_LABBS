#pragma once
#include"exeption.h"
#include <gtest/gtest.h>
using namespace std;

template<typename T>
class LinkedList {
    struct Node {
        Node(const T& value) : data(value), next(nullptr), past(nullptr) {
        }

        Node() : data(0), next(nullptr), past(nullptr) {
        }

        Node* next;
        Node* past;
        T data;
    };

    Node* start_el;
    Node* end_el;
    size_t size;

public:
    LinkedList() : start_el(nullptr), end_el(nullptr), size(0) {
    }

    LinkedList(const LinkedList<T>& list) {
        Node* cur = list.start_el;
        while (cur) {
            Append(cur->data);
            cur = cur->next;
        }
    }

    LinkedList(T* items, int count) {
        size = count;
        start_el = new Node{items[0]};
        Node* curr = start_el;

        for (int i = 1; i < count; i++) {
            Node* add_el = new Node{items[i]};
            curr->next = add_el;
            curr = add_el;
        }
    }


    void Append(const T& item) {
        Node* newNode = new Node(item);
        if (size == 0) {
            start_el = end_el = newNode;
        } else {
            end_el->next = newNode;
            newNode->past = end_el;
            end_el = newNode;
        }
        size++;
    }

    T GetFirst() {
        if (size == 0) throw InvalidArgument();
        return start_el->data;
    }

    T GetLast() {
        if (size == 0) throw InvalidArgument();
        return end_el->data;
    }

    T Get(int index) {
        if (index < 0 || index > size - 1)
            throw IndexOutOfRange();
        Node* cur = start_el;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        return cur->data;
    }

    LinkedList<T>* GetSubList(int startIndex, int endIndex) {
        if (startIndex < 0 || endIndex < 0)
            throw IndexOutOfRange();
        if (startIndex >= size || endIndex >= size || startIndex > endIndex)
            throw IndexOutOfRange();
        LinkedList<T>* cut = new LinkedList<T>;
        Node* cur = start_el;
        for (int i = 0; i < startIndex; i++)
            cur = cur->next;
        for (int i = startIndex; i < endIndex; i++) {
            cut->Append(cur->data);
            cur = cur->next;
        }
        return cut;
    }

    int GetSize() {
        return size;
    }

    void Prepend(const T& item) {
        Node* head = new Node(item);
        if (size == 0) {
            head->next = head->past = head;
        } else {
            head->next = start_el;
            start_el->past = head;
            start_el = head;
        }
        size++;
    }

    void InsertAt(const T& item, int index) {
        if (index < 0 || index > size)
            throw IndexOutOfRange();
        Node* add_el = new Node(item);
        Node* current = start_el;
        // ��������� � ���� ����� ������ ��������
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }

        // ������������� ����� ������ ����
        add_el->next = current->next;
        add_el->past = current;

        // ��������� ����� �������� �����
        if (current->next != nullptr) {
            current->next->past = add_el;
        }
        current->next = add_el;


        size++;
        /*Node* cur = start_el;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        add_el->past = &cur;
        if (cur->next != nullptr) {
            Node* after = cur->next;
            after->past = &add_el;
        }
        add_el->next = cur->next;
        cur->next = &add_el;
        size++;*/
    }

    LinkedList<T>* Concat(LinkedList<T>* Node) {
        if (Node->size == 0)
            return this;
        else if (this->size == 0) {
            this->start_el = Node->start_el;
            this->end_el = Node->end_el;
            this->size = Node->size;
        } else {
            this->end_el->next = Node->start_el;
            Node->start_el->past = this->end_el;
            this->size += Node->size;
            Node->end_el = nullptr;
            Node->start_el = nullptr;
            Node->size = 0;
        }
        return this;
    }

    void RemoveAt(int index) {
        if (index < 0 || index >= size) throw IndexOutOfRange();
        else if (index == 0) {
            Node* temp = start_el;
            start_el = start_el->next;
            delete(temp);
            size--;
        } else {
            Node* cur = start_el;
            for (int i = 0; i < index - 1; i++) {
                cur = cur->next;
            }
            Node* del_el = cur->next;
            cur->next = del_el->next;
            delete(del_el);
            size--;
            if (index == size) end_el = cur;
        }
        return;
    }
};
