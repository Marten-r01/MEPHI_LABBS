#include <iostream>
#include <gtest/gtest.h>
#include "DinamicArray.h"  
#include "LinkedList.h"
#include "ArraySequence.h"
#include "ListSequence.h"

TEST(DinamicArrayTest, ConstructorAndGet) {
    int data[] = { 1, 2, 3 };
    DinamicArray<int> arr(data, 3);
    EXPECT_EQ(arr.GetSize(), 3);
    EXPECT_EQ(arr.Get(0), 1);
}

TEST(DinamicArrayTest, Resize) {
    DinamicArray<int> arr(3);
    arr.Resize(5);
    EXPECT_EQ(arr.GetSize(), 5);
}

// Тесты для LinkedList
TEST(LinkedListTest, Append) {
    LinkedList<int> list;
    list.Append(1);
    EXPECT_EQ(list.GetSize(), 1);
}

TEST(ArraySequenceTest, AppendAndGet) {
    ArraySequence<int> seq;
    seq.Append(1);
    seq.Append(2);

    EXPECT_EQ(seq.GetSize(), 2);
    EXPECT_EQ(seq.Get(0), 1);
    EXPECT_EQ(seq.Get(1), 2);
}

TEST(ArraySequenceTest, SetAndResize) {
    ArraySequence<int> seq(3);
    seq.Set(0, 10);
    seq.Resize(5);

    EXPECT_EQ(seq.Get(0), 10);
    EXPECT_EQ(seq.GetSize(), 5);
}

// Тесты для ImmutableArraySequence
TEST(ImmutableArraySequenceTest, AppendCreatesNewInstance) {
    int data[] = { 1, 2, 3 };
    ImmutableArraySequence<int> seq(data, 3);
    auto newSeq = seq.Append(4);

    EXPECT_EQ(seq.GetSize(), 3);  // Исходный объект не изменился
    EXPECT_EQ(newSeq->GetLength(), 4);
    EXPECT_EQ(newSeq->Get(3), 4);
}

TEST(ImmutableArraySequenceTest, SetDoesNotModifyOriginal) {
    int data[] = { 1, 2, 3 };
    ImmutableArraySequence<int> seq(data, 3);
    auto newSeq = seq.Set(0, 10);

    EXPECT_EQ(seq.Get(0), 1);  // Исходный объект не изменился
    EXPECT_EQ(newSeq->Get(0), 10);
}
