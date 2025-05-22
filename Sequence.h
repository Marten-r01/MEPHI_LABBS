#pragma once
template<class T>
class Sequence {
public:
	virtual ~Sequence() = default;
	virtual int GetSize() const=0;
	virtual T Get(int index) const = 0;
	virtual T GetFirst() const = 0;
	virtual T GetLast() const = 0;

	virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) ;
	virtual Sequence<T>* Append(const T& item) ;
	virtual Sequence<T>* Prepend(const T& item) ;
	virtual Sequence<T>* InsertAt(const T& item, int index) ;
	virtual Sequence <T>* Concat(const Sequence <T>* list) const =0;
	virtual Sequence<T>* RemoveAt(int index) ;
};
template<class T>
bool operator==(const Sequence<T>& a, const Sequence<T>& b) {
	if (a.GetSize() != b.GetSize()) return false;
	for (int i = 0; i < a.GetSize(); ++i)
		if (!(a.Get(i) == b.Get(i))) return false;
	return true;
}