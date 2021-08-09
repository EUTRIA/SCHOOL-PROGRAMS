#include "Queue.h"
#include <string>
using namespace std;


template <class T>
Queue1<T>::Queue1() {
	//! replaces self
	//! ensures: self = <>
	//Sequence<T> Queue1;
}//Queue1


template <class T>
Queue1<T>::~Queue1() {

	seq.~Sequence();
}//~Queue1


template <class T>
void Queue1<T>::clear(void) {
	//! clears self
	seq.clear();
}//clear


template <class T>
void Queue1<T>::transferFrom(Queue1& source) {
	//! replaces self
	//! clears source
	//! ensures: self = #source

	 seq.transferFrom(source.seq);//ask dr.h
}//transferFrom


template <class T>
Queue1<T>& Queue1<T>::operator= (Queue1& rhs) {
	//! replaces self
	//! restores rhs
	//! ensures: self = rhs

	 seq.operator=(rhs.seq);

	return (*this);//returns self = rhs
	
}//operator=


template <class T>
void Queue1<T>::enqueue(T& x) {
	//! updates self
	//! clears x
	//! ensures: self = #self * <#x>

	seq.addLast(x,length());
	static T y; //local static variables intialize themselves 
	x = y;

}//enqueue


template <class T>
void Queue1<T>::dequeue(T& x) {
	//! updates self
	//! replaces x
	//! requires: self /= <>
	//! ensures: <x> is prefix of #self  and  self = #self[1, |#self|)
	seq.removeFirst(x);

}//dequeue


template <class T>
void Queue1<T>::replaceFront(T& x) {
	//! updates self, x
	//! requires: self /= <>
	//! ensures: <x> is prefix of #self  and  self = <#x> * #self[1, |#self|)
	T temp;
	seq.removeFirst(temp);
	seq.addFirst(x);
	x = temp;
}//replaceFront


template <class T>
T& Queue1<T>::front(void) {
	//! restores self
	//! requires: self /= <>
	//! ensures: <front> is prefix of self
	return seq.entry(0);
}//front


template <class T>
int Queue1<T>::length(void) {
	//! restores self
	//! ensures: length = |self|

	return seq.length();
}//length


template <class T>
void Queue1<T>::outputQueue(void) {
	//! restores self
	//! ensures: self = #self
	seq.outputSequence();
}//outputQueue