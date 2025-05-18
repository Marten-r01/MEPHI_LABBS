#pragma once
#include <stdexcept>
using namespace std;

class IndexOutOfRange : public out_of_range{
public:
    IndexOutOfRange() : out_of_range("Index out of range") {}
};

class InvalidArgument : public invalid_argument {
public:
    InvalidArgument() : invalid_argument("Invalid argument") {}
};

class MemoryAllocationError : public runtime_error {
public:
    MemoryAllocationError() : runtime_error("Memory allocation failed") {}
};