/*#include "LinkedList.h"
#include "DinamicArray.h"
#include "ArraySequence.h"
#include "ListSequence.h"


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


TEST(LinkedListTest, DefaultConstructor) {
    LinkedList<int> list;
    EXPECT_EQ(list.GetSize(), 0);
}

TEST(LinkedListTest, ArrayConstructor) {
    int init[] = { 1, 2, 3 };
    LinkedList<int> list(init, 3);
    EXPECT_EQ(list.GetSize(), 3);
    EXPECT_EQ(list.GetFirst(), 1);
    EXPECT_EQ(list.GetLast(), 3);
}

TEST(LinkedListTest, Get) {
    int arr[] = { 10, 20, 30 };
    LinkedList<int> list(arr, 3);
    EXPECT_EQ(list.Get(0), 10);
    EXPECT_EQ(list.Get(1), 20);
    EXPECT_EQ(list.Get(2), 30);
    EXPECT_THROW(list.Get(3), std::out_of_range);
}

TEST(LinkedListTest, Append) {
    LinkedList<int> list;
    list.Append(100);
    list.Append(200);
    EXPECT_EQ(list.GetSize(), 2);
    EXPECT_EQ(list.GetFirst(), 100);
    EXPECT_EQ(list.GetLast(), 200);
}

TEST(LinkedListTest, Prepend) {
    LinkedList<int> list;
    list.Prepend(300);
    list.Prepend(400);
    EXPECT_EQ(list.GetSize(), 2);
    EXPECT_EQ(list.GetFirst(), 400);
    EXPECT_EQ(list.GetLast(), 300);
}

TEST(LinkedListTest, InsertAt) {
    int arr[] = { 1, 2, 4, 5 };
    LinkedList<int> list(arr, 4);
    list.InsertAt(3, 2);
    EXPECT_EQ(list.GetSize(), 5);
    EXPECT_EQ(list.Get(2), 3);
    EXPECT_THROW(list.InsertAt(0, 10), std::out_of_range);
}

TEST(LinkedListTest, RemoveAt) {
    int arr[] = { 1, 2, 3, 4, 5 };
    LinkedList<int> list(arr, 5);
    list.RemoveAt(2);
    EXPECT_EQ(list.GetSize(), 4);
    EXPECT_EQ(list.Get(2), 4);
    EXPECT_THROW(list.RemoveAt(10), std::out_of_range);
}

TEST(LinkedListTest, GetSubList) {
    int arr[] = { 1, 2, 3, 4, 5 };
    LinkedList<int> list(arr, 5);
    LinkedList<int>* sub = list.GetSubList(1, 3);
    EXPECT_EQ(sub->GetSize(), 3);
    EXPECT_EQ(sub->Get(0), 2);
    EXPECT_EQ(sub->Get(2), 4);
    delete sub;
    EXPECT_THROW(list.GetSubList(-1, 3), std::out_of_range);
    EXPECT_THROW(list.GetSubList(2, 1), std::out_of_range);
}

TEST(LinkedListTest, Concat) {
    int arr1[] = { 1, 2, 3 };
    int arr2[] = { 4, 5, 6 };
    LinkedList<int> list1(arr1, 3);
    LinkedList<int> list2(arr2, 3);
    LinkedList<int>* result = list1.Concat(&list2);

    EXPECT_EQ(result->GetSize(), 6);
    EXPECT_EQ(result->Get(0), 1);
    EXPECT_EQ(result->Get(3), 4);
    EXPECT_EQ(result->Get(5), 6);
    delete result;
}
*/