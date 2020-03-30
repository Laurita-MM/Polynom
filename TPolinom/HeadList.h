#pragma once
#include "List.h"
template <class T>
class THeadList : public TList<T> {
protected:
	TNode<T>* pHead;
public:

	THeadList() : TList<T>() {
		pHead = new TNode<T>;
		this->pStop = pHead;
		pHead->pNext = pHead;
		this->pFirst = pHead;
	}

	~THeadList() {
		TList<T> ::DelList();
		delete pHead;
	}

	void InsFirst(T el) {
		TList<T>::InsFirst(el);
		this->pHead->pNext = this->pFirst;
	}

	void InsLast(T el) {
		TList<T>::InsLast(el);
	}

	void InsCurr(T el) {
		TList<T>::InsCurr(el);
	}

	void DelFirst() {
		TList::DelFirst();
		this->pHead->pNext = this->pFirst;
	}
};