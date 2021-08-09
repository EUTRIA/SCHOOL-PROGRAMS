#include "Sequence.h"
#include <iostream>
using namespace std;

template <class T>
Sequence<T>::Sequence()
{
    head = NULL;
    temp = NULL;
    size = 0;
}// Sequence

template <class T>
Sequence<T>::~Sequence()
{
     //reclaimAllNodes(head);

}    // ~Sequence


template <class T>
void Sequence<T>::clear(void)
{
    size = 0;
    reclaimAllNodes(head);
    head = NULL;
    tail = NULL;
    temp = NULL;
    current = NULL;

} // clear

template <class T>
void Sequence<T>::reclaimAllNodes(NodeRecord*& initialP)
// requires: Null(initialP)  or  Alive(initialP)
//  ensures: all nodes in linked list
//           beginning with initialP are reclaimed
{
    if (initialP != NULL) {
        reclaimAllNodes(initialP->next);
        delete (initialP);

    } // end if
} // reclaimAllNodes


template <class T>
void Sequence<T>::addFirst(T& t) {
    //! updates self
    //! restores t
    //! ensures: self = <t> * #self

    NodeRecord* node = new NodeRecord;
    node->value = t;
    node->next = head;
    head = node;
    if (head->next == NULL) {
        tail = head;
    }
    size++;
}

template <class T>
void Sequence<T>::addLast(T& t, int pos) {
    //! updates self 
    //! restores pos and t
    //! requires: pos <= |self|+1
    //! ensures: self = #self * <t>

    NodeRecord* node = new NodeRecord;
    node->value = t;
    node->next = NULL; // Problem causing error with clear was due to a lack of NULL at the end of list 
    if (tail == NULL) {

        head = tail = node;
        size++;
    }
    else if (pos <= size + 1) 
    {
        tail->next = node;
        tail = tail->next;
        size++;
    }
}

// You are required to implement add, remove, entry, length, and outputSequence functions here.
template <class T>
void Sequence<T>::add(T& t, int pos) {
    //! updates self
    //! restores pos
    //! clears t
    //! requires: 0 = pos = |self|
    //! ensures: self = #self[0, pos) * <#x> * #self[pos, |#self|)

    NodeRecord* node = new NodeRecord;
    node->value = t;
    if (pos == 0) {//1st case adding to a empty linkedlist
        addFirst(t);
    }
    else if (pos >= size) {//2nd case adding to the end of the Llist
        addLast(t, pos);
    }
    else {              //third case node is added in the same position of a existing node 
        current = head;
        for (int i = 1; i < pos; i++)
        {
            current = current->next;
        }

        temp = current->next; //pointer is pointing to the next address of current
        current->next = node; //next address of current is now equal to node which is Alive memory

        node->next = temp;  /*  nodes->next is pointing to the next address of the current->next node
                            this node is what connects the new node to the rest of the list */
        size++;
      //  t = 0;
    }

}

template <class T>
void Sequence<T>::removeFirst(T& t) {
    //! updates self
    //! replaces t
    //! ensures: self = #self[1,|#self|) and
    //! <t> = #self[0,1)


    if (head == NULL) {
        tail == NULL;
    }
    else
    {
        temp = head;
        head = head->next;
        size--;
        t = temp->value;
    }
}

template <class T>
void Sequence<T>::removeLast(T& t) {
    //! updates self
    //! replaces t
    //! ensures: self = #self[0,|#self|-1) and
    //! <t> = #self[|#self-1|,|#self|)


    tail = tail->next;
    size--;
    if (size == 1) {
        temp = head;
        head = tail = NULL;
        size = 0;
        t = temp->value;
    }
    else
    {
        current = head;
        for (int i = 1; i < size - 1; i++) {//pointing to node before the last node 
            current = current->next;
        }
        temp = tail;
        tail = current;
        tail->next = NULL;
        t = temp->value;

        size--;
    }
}

template <class T>
void Sequence<T>::remove(T& t, int pos) {
    //! updates self
    //! restores pos
    //! replaces t
    //! requires: 0 = pos < |self|
    //! ensures: <t> = #self[pos, pos+1) and
    //! self = #self[0, pos) * #self[pos+1, |#self|)

    if (pos == 0) {
        removeFirst(t);
    }
    else if (pos == size)
    {
        removeLast(t);
    }
    else if (pos <= size) { //remove nodes in the middle of linked list 
        NodeRecord* previous = head;
        for (int i = 1; i < pos; i++) {
            previous = previous->next;
        }
        current = previous->next; //assigns current to previous->next node address
        previous->next = current->next; //assigns previous->next pointer to current next pointer removing current node
        size--;
        t = current->value;

    }
}


template <class T>
T& Sequence<T>::entry(int pos) {
    //! restores self, pos
    //! requires: 0 = pos < |self|
    //! ensures: <entry> = self[pos, pos+1)

    current = head;
    T pos_err;
    if ((pos < 0) || (pos > size) || (pos == size)) {
        return pos_err;
    }
    for (int i = 0; i != pos; i++) {
        current = current->next;
    }

    return current->value;
}
template <class T>
int Sequence<T>::length(void) {
    //! restores self
    //! ensures: length = |self|

    return size;
}


template <class T>
void Sequence<T>::outputSequence(void) {
    //! restores self
    //! ensures: self = #self

    int i = 1;
    temp = head;

    cout << "<";
    while (i <= size) {
        if (temp == tail) {
            cout << temp->value;
        }
        else
        {
            cout << temp->value << ", ";
            temp = temp->next;
        }
        i++;
    }
    cout << ">";
}


template <class T>
void Sequence<T>::transferFrom(Sequence& source) {
     //! replaces self
    //! clears source
    //! ensures: self = #source
    
    T temp;
    clear(); //clears self
    for (int i = 0; i < source.length(); i++)//traverses source
    {
        temp = source.entry(i);
        add(temp, length());//adds source elements to self
    }
    source.clear();//clears source
}

template <class T>
Sequence<T>& Sequence<T>::operator=(Sequence& rhs) {
    //! replaces self
    //! restores rhs
    //! ensures: self = rhs 
    
    
    clear();//clears self
    for (int i = 0; i < rhs.length(); i++)//traverses rhs
    {
        add(rhs.entry(i), length());//adds elements from rhs to self
    }
    return (*this);//returns self = rhs
}
