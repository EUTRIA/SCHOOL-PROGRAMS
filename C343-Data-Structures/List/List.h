#pragma once
#include "Sequence.hpp"

template<class T>
class List1
	//! is modeled by (
	//! left: string of T//!
	//! right: string of T//!)
	//! exemplar self
{
public:
	// Standard Operations 5
	List1();
	~List1();

	void clear(void);
	void transferFrom(List1& source);
	List1& operator= (List1& rhs);

	// List1 Specific Operations 10
	void moveToStart(void);
	void moveToFinish(void);

	void advance(void);

	void addRightFront(T& x);
	void removeRightFront(T& x);
	T& rightFront(void);

	void replaceRightFront(T& x);
	void swapRights(List1& otherS);

	int leftLength(void);
	int rightLength(void);

	void outputList(void);
private: // representation
	
	Sequence<T> seqleft;
	Sequence<T> seqright;

};