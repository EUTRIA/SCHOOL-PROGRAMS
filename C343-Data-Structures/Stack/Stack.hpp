#include "Stack.h"
#include <iostream>

using namespace std;

template <class T>
Stack1<T>::Stack1()
{
  //! alters self
  //! ensures: self = < >
 
}//Stack1

template<class T>
Stack1<T>::~Stack1()
{

}//~Stack1

template<class T>
void Stack1<T>::clear(void)
{
	//! alters self
	//! ensures: self = < >
	
	que1.clear();
	que2.clear();
}//clear

template<class T>
void Stack1<T>::transferFrom(Stack1& source)
{
	//! alters self, source
	//! ensures self = #source  and  source = < >
	
	que1.transferFrom(source.que1);
}//transferFrom

template<class T>
Stack1<T>& Stack1<T>::operator=(Stack1& rhs)
{
	//! alters self
   //! preserves rhs
   //! ensures: self = rhs

	que1.operator=(rhs.que1);
	return *this;
}//operator=

template<class T>
void Stack1<T>::push(T& x)
{
	//! alters self
	//! consumes x
	//! ensures: self = <#x> * self
	T sizTemp = que1.length();
	que2.enqueue(x);

	int i = 0;
	while (i < sizTemp) {
		T x = que1.front();
		que2.enqueue(x);
		que1.dequeue(x);
		i++;
	}
	Queue1<T> temp = que1;
	que1 = que2;
	que2 = temp;
}//push

template<class T>
 void Stack1<T>::pop(T& x)
{
   //! alters self
   //! produces x
   //! requires: self /= < >
   //! ensures: <x> is prefix of #self  and  self = #self[1, |#self|)
	 T sizTemp = que1.length();
	 T z;
	 if (sizTemp != 0) {
		 que1.dequeue(z);
	 }
	 x = z;

}//pop

template<class T>
void Stack1<T>::replaceTop(T& x)
{
	//! alters self, x
	//! requires: self /= < >
	//! ensures: <x> is prefix of #self  and  self = <#x> * #self[1, |#self|)
	
	T sizTemp = que1.length()-1;

	T y;
	que1.dequeue(y);
	que2.enqueue(x);

	int i = 0;
	while (i < sizTemp) {
		T x = que1.front();
		que2.enqueue(x);
		que1.dequeue(x);
		i++;
	}
	Queue1<T> temp = que1;
	que1 = que2;
	que2 = temp;
	

}//replaceTop

template<class T>
 T& Stack1<T>::top(void)
{
   //! preserves self
   //! requires: self /= < >
   //! ensures: <top> is prefix of self
	return que1.front();

}//top

template<class T>
 int Stack1<T>::length(void)
{
	//! preserves self
	//! ensures: length = |self|
	
	return que1.length();
}//length

 template<class T>
 void Stack1<T>::outputStack(void) {
	 //! restores self
	//! ensures: self = #self
	
	 que1.outputQueue();
	
 }


