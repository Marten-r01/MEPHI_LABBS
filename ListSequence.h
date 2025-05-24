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

    virtual T GetFirst() const override { return list->GetFirst(); }

    virtual T GetLast() const override { return list->GetLast(); }

    virtual T Get(int index) const override { return list->Get(index); }

    virtual int GetSize() const override { return list->GetSize(); }

    virtual ListSequence<T>* GetSubsequence(int Startindex, int Endindex) const override {
        if (Startindex < 0 || Endindex >= list->GetSize() || Endindex < Startindex) throw IndexOutOfRange();
        LinkedList<T>* sublist = list->GetSubList(Startindex, Endindex);
        ListSequence<T>* result = new ListSequence<T>();
        delete result->list;
        result->GetSubList = sublist;
        return sublist;
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
};
TEST(ListSequenceTest, DefaultConstructor) {
    ListSequence<int> seq;
    EXPECT_EQ(seq.GetSize(), 0);
}

TEST(ListSequenceTest, ArrayConstructor) {
    int arr[] = { 1, 2, 3, 4, 5 };
    ListSequence<int> seq(arr, 5);

    EXPECT_EQ(seq.GetSize(), 5);
    EXPECT_EQ(seq.GetFirst(), 1);
    EXPECT_EQ(seq.GetLast(), 5);
}

TEST(ListSequenceTest, Get) {
    int arr[] = { 10, 20, 30 };
    ListSequence<int> seq(arr, 3);

    EXPECT_EQ(seq.Get(0), 10);
    EXPECT_EQ(seq.Get(1), 20);
    EXPECT_EQ(seq.Get(2), 30);
    EXPECT_THROW(seq.Get(3), std::out_of_range);
}

TEST(ListSequenceTest, Append) {
    ListSequence<int> seq;
    seq.Append(100);
    seq.Append(200);

    EXPECT_EQ(seq.GetSize(), 2);
    EXPECT_EQ(seq.GetFirst(), 100);
    EXPECT_EQ(seq.GetLast(), 200);
}

TEST(ListSequenceTest, Prepend) {
    ListSequence<int> seq;
    seq.Prepend(300);
    seq.Prepend(400);

    EXPECT_EQ(seq.GetSize(), 2);
    EXPECT_EQ(seq.GetFirst(), 400);
    EXPECT_EQ(seq.GetLast(), 300);
}

TEST(ListSequenceTest, InsertAt) {
    int arr[] = { 1, 2, 4, 5 };
    ListSequence<int> seq(arr, 4);

    seq.InsertAt(3, 2);
    EXPECT_EQ(seq.GetSize(), 5);
    EXPECT_EQ(seq.Get(2), 3);
    EXPECT_THROW(seq.InsertAt(0, 10), std::out_of_range);
}

TEST(ListSequenceTest, RemoveAt) {
    int arr[] = { 1, 2, 3, 4, 5 };
    ListSequence<int> seq(arr, 5);

    seq.RemoveAt(2);
    EXPECT_EQ(seq.GetSize(), 4);
    EXPECT_EQ(seq.Get(2), 4);
    EXPECT_THROW(seq.RemoveAt(10), std::out_of_range);
}

TEST(ListSequenceTest, GetSubsequence) {
    int arr[] = { 1, 2, 3, 4, 5 };
    ListSequence<int> seq(arr, 5);

    ListSequence<int>* sub = seq.GetSubsequence(1, 3);
    EXPECT_EQ(sub->GetSize(), 3);
    EXPECT_EQ(sub->Get(0), 2);
    EXPECT_EQ(sub->Get(2), 4);
    delete sub;

    EXPECT_THROW(seq.GetSubsequence(-1, 3), std::out_of_range);
    EXPECT_THROW(seq.GetSubsequence(2, 1), std::out_of_range);
}
