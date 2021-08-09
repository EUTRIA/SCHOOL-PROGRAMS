#pragma once
#include "List.h"
#include <iostream>;
using namespace std;

template <class T>
List1<T>::List1()
{
	//!replaces self
	//!ensures: self = (<>,<>) 
	

}//List1

template<class T>
 List1<T>::~List1()
{

}//~List1

template<class T>
 void List1<T>::clear(void)
{
	 //!clears self
	 
	 seqleft.clear();
	 seqright.clear();

}//clear

template<class T>
void List1<T>::transferFrom(List1& source)
{
	//!replaces self
	//!clears source
	//!ensures: self = #source
	
	seqleft.transferFrom(source.seqleft);
	seqright.transferFrom(source.seqright);

}//transferFrom

template<class T>
List1<T>& List1<T>::operator=(List1& rhs)
{
	//!replaces self
    //!restores rhs
	//!ensures: self = rhs
	seqleft = rhs.seqleft;
	seqright = rhs.seqright;
	return *this;
}//operator=

template<class T>
void List1<T>::moveToStart(void)
{
	//!updates self
	//!ensures: self = (<>,#self.left * #self.right)
	Sequence<T> temp;
	temp.transferFrom(seqright);
	seqright.transferFrom(seqleft);

	for (int i = 0; i < temp.length();i++) {

		seqright.addLast(temp.entry(i),i);
	}
	
}//moveToStart 

template<class T>
void List1<T>::moveToFinish(void)
{
	//!updates self
	//!ensures: self = (#self.left * #self.right,<>)
	
	for (int i = 0; i < rightLength(); i++) {

		seqleft.addLast(seqright.entry(i),i);
	}
	
	seqright.clear();

}//moveToFinish 

template<class T>
void List1<T>::advance(void)
{
	//!updates self
	//!requires: self.right /= <>
	//!ensures: self.left * self.right = #self.left *
	//!#self.right and|self.left| = |#self.left| + 1
	T y;
	seqright.removeFirst(y);
	seqleft.addLast(y,leftLength());
}//advance 

template<class T>
 void List1<T>::addRightFront(T& x)
{
	 //!updates self.right
	 //!clears x
	 //!ensures: self = (#self.left,<#x> * #self.right)
	 
	 seqright.addFirst(x);
	 
}//addRightFront 

 template<class T>
 void List1<T>::removeRightFront(T& x)
 {
	 //!updates self.right
	 //!replaces x
	 //!requires: self.right /= <>//!ensures: <x> is prefix of #self.right  and
	 //!self = (#self.left,#self.right[1,|#self.right|))
	 
	 seqright.removeFirst(x);
 }//removeRightFront

 template<class T>
  T& List1<T>::rightFront(void)
 {
	  //!restores self 
	  //!requires: self.right /= <>//!ensures: <rightFront> is prefix of self.right
	  
	  return seqright.entry(0);
 }//rightFront 

 template<class T>
 void List1<T>::replaceRightFront(T& x)
 {
	 //!updates self.right, x
	 //!requires: self.right /= <>
	 //!ensures: <x> is prefix of #self.right  and
	 //!self = (#self.left,<#x> * #self.right[1,|#self.right|))
	 
	 T temp;
	 seqright.removeFirst(temp);
	 addRightFront(x);
	 x = temp;
 }//replacrRightFront 

 template<class T>
void List1<T>::swapRights(List1& otherS)
 {
	//!updates self.right, otherS.right
	//!ensures: self = (#self.left,#otherS.right)  and
	//!otherS = (#otherS.left,#self.right)
	
	Sequence<T> temp;
	temp.transferFrom(otherS.seqright); //temp = incoming seqright

	otherS.seqright.transferFrom(this->seqright); //otherS seqright = self seqright

	seqright.transferFrom(temp);
 }//swapRights

template<class T>
 int List1<T>::leftLength(void)
{
	 //!restores self
	 //!ensures: leftLength = |self.left|
	 
	 return seqleft.length();
}//leftLength

template<class T>
int List1<T>::rightLength(void)
{
	//!restores self
	//!ensures: rightLength = |self.right|
	
	return seqright.length();
}//rightLength 

template<class T>
void List1<T>::outputList(void)
{
   //! restores self
   //! ensures: self = #self.left* #self.right
   
	///*
	int total;
	total = leftLength() + rightLength();
	cout << "<";

	for (int i = 0; i < total; i++) {
		if (i <leftLength() ) {
			if (i == total - 1){
			cout << seqleft.entry(i);
			}//if
			  else {
				cout << seqleft.entry(i)<<", ";
			}//else
		}//if

		else if (i == total-1) {
			cout << seqright.entry(i - leftLength());
		}//elseif

		else
		{
			cout << seqright.entry(i - leftLength())<<", ";
		}//else
	}//for
	
	cout << ">";
	// */
		
	//seqleft.outputSequence();
	//seqright.outputSequence();
}//outputList
