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

// Тесты для Sequence
TEST(ArraySequenceTest, ImmutableAppend) {
    int data[] = { 1, 2, 3 };
    ArraySequence<int> new_arr(data, 3);
    auto newSeq = new_arr.Append(4);
    EXPECT_EQ(ArraySequence<int>*->GetLength(), 4);
}
