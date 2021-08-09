
#include <iostream>
#include <cstdio>
using namespace std;
template <class T>
class Sequence //linkedlist
{
private: // Internal Representation
      

    class NodeRecord {
    public:
        T value;
        NodeRecord* next;
    };

    NodeRecord* head;
    NodeRecord* tail;
    NodeRecord* current;
    NodeRecord* temp;
    int size;

public:
    Sequence();
    ~Sequence();
    void clear(void);

    void add(T& t, int pos);
    void addFirst(T& t);
    void addLast(T& t, int pos);

    void remove(T& t, int pos);
    void removeFirst(T& t);
    void removeLast(T& t);

    T& entry(int pos);
    int length(void);
    void outputSequence(void);
    void subtractX(int x);
    void reverse(Sequence& s);
    void transferFrom(Sequence& source);
    Sequence& operator=(Sequence& rhs);

private: // Internal operations
    void reclaimAllNodes(NodeRecord*& p);
};

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
    // reclaimAllNodes(head);
}    // ~Sequence


template <class T>
void Sequence<T>::clear(void)
{
    size = 0;
    reclaimAllNodes(head);
    head = NULL;

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
void Sequence<T>::addLast(T& t,int pos) {
    NodeRecord* node = new NodeRecord;
    node->value = t;
    node->next = NULL; // Problem causing error with clear was a lack of NULL at the end of list 
    if (tail == NULL) {

        head = tail = node;
    }
    else if (pos <= size+1)
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
    //! clears x
    //! requires: 0 ≤ pos ≤ |self|
    //! ensures: self = #self[0, pos) * <#x> * #self[pos, |#self|)
 
    NodeRecord* node = new NodeRecord;
    node->value = t;
    if (pos == 0) {//1st case adding to a empty linkedlist
        addFirst(t);
    }
    else if (pos >= size) {//2nd case adding to the end of the Llist
        addLast(t,pos);
    }
    else {              //third case node is added in the same position of a existing node 
        current = head;
        for (int i = 1; i < pos; i++) {
            current = current->next;
        }

        temp = current->next; //pointer is pointing to the next address of current
        current->next = node; //next address of current is now equal to node which is Alive memory

        node->next = temp;  /*  nodes->next is pointing to the next address of the current->next node
                            this node is what connects the new node to the rest of the list */
        size++;
        t = 0;
    }

}

template <class T>
void Sequence<T>::removeFirst(T& t) {
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
    //! restores pos //! replaces x
    //! requires: 0 ≤ pos < |self|
    //! ensures: <x> = #self[pos, pos+1) and
    //! self = #self[0, pos) * #self[pos+1, |#self|)

    if (pos == 0) {
        removeFirst(t);
    }
    else if (pos == size)
    {
        removeLast(t);
    }
    else if (pos<=size) { //remove nodes in the middle of linked list 
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
    //! requires: 0 ≤ pos < |self|
    //! ensures: <entry> = self[pos, pos+1)

    current = head;
    T pos_err = NULL;
    if ((pos < 0) || (pos > size)||(pos==size)) {
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

    cout << "< ";
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

template <class T>
void Sequence<T>:: reverse(Sequence& s)
//! updates s 
//! ensures: s = rev(#s) 
{

    if(s.length() != 0) {
        T x;
        s.remove(x, 0);
        reverse(s);
        s.add(x, s.length());
    }
} // reverse

int main()
{
    Sequence<int> s1;
    Sequence<int> s2;
    Sequence<int> s3;
    int xi = 0;
    cout << "SEQUENCE ONE\nS1: ";
    s1.outputSequence();

    cout << "\n\nTESTING ADD, OUTPUTSEQUENCE, LENGTH\nFilled S1 with <23, 14, 18, 31, 11>";
    xi = 23;
    s1.add(xi, 0);
    xi = 14;
    s1.add(xi, 1);
    xi = 18;
    s1.add(xi, 2);
    xi = 31;
    s1.add(xi, 3);
    xi = 11;
    s1.add(xi, 4);
    cout << "\nS1: ";
    s1.outputSequence();
    s1.reverse(s1);
    cout << "\n";
    s1.outputSequence();

  
   //Output
  
   /* cout << "\n\nADD, OUTPUTSEQUENCE, LENGTH\nAdded 17 to position 0";
    xi = 17;
    s1.add(xi, 0);
    cout << "\nS1: ";
    s1.outputSequence();
    cout << "\nS1 size: " << s1.length();

    cout << "\n\nTESTING REMOVE\n+ OUTPUTSEQUENCE, LENGTH\nRemoved entry at position 3";
    s1.remove(xi, 3);
    cout << "\nElement removed: " << xi;
    cout << "\nS1: ";
    s1.outputSequence();
    cout << "\nS1 size: " << s1.length();

    cout << "\n\nTESTING ENTRY\nS1[1]: " << s1.entry(1);
    cout << "\nS1[0]: " << s1.entry(0);

    cout << "\n\nTESTING CLEAR\n+ OUTPUTSEQUENCE\nClearing Sequence One\nS1:";
    s1.clear();
    s1.outputSequence();



  //  /* TESTING SEQUENCE TWO
        TESTED:
            ADD
            OUTPUTSEQUENCE
            LENGTH
            ENTRY
            REMOVE
            CLEAR
    // */

   


   /* cout << "\n\n\nSEQUENCE TWO\nS2: ";
    s2.outputSequence();

    cout << "\n\nADD, OUTPUTSEQUENCE, LENGTH\nFilled S2 with <1>";
    xi = 1;
    s2.add(xi, 0);
    cout << "\nS2: ";
    s2.outputSequence();
    cout << "\nS2 size: " << s2.length();

    cout << "\n\nADD, OUTPUTSEQUENCE, LENGTH\nAdded 3 to position 3";
    xi = 3;
    s2.add(xi, 3); //error because 3 > size
    cout << "\nS2: ";
    s2.outputSequence();
    cout << "\nS2 size: " << s2.length();

    cout << "\n\nENTRY\nS2[3]: ";
    cout << s2.entry(3); //error because 3 > size


    cout << "\n\nREMOVE, OUTPUTSEQUENCE\nRemoved entry at position 2";
    s2.remove(xi, 2);
    cout << "Element removed: " << xi;
    cout << "\nS2: ";
    s2.outputSequence();



    cout << "\n\nENTRY";
    cout << "\nS2[0]: ";
    cout << s2.entry(0);
    cout << "\nS2[1]: ";
    cout << s2.entry(1); //error because 1 = size
    cout << "\nS2[2]: ";
    cout << s2.entry(2); //error because 2 > size
    cout << "\nS2[3]: ";
    cout << s2.entry(3); //          ||

    cout << "\n\nCLEAR, OUTPUTSEQUENCE, LENGTH\nClearing Sequence Two";
    s2.clear();
    cout << "\nS2: ";
    s2.outputSequence();
    cout << "\nS2 size: " << s2.length();



    /* TESTING SEQUENCE THREE
       TESTED:
           ADD
           OUTPUTSEQUENCE
           LENGTH
           ENTRY
           REMOVE
           CLEAR
    */




/*    cout << "\n\n\nSEQUENCE THREE\nS3: ";
    s3.outputSequence();

    cout << "\n\nADD, OUTPUTSEQUENCE, LENGTH\nFilled S3 with <8, 23, 2000>";
    xi = 8; //08 => invalid octal digit ??
    s3.add(xi, 0);
    xi = 23;
    s3.add(xi, 1);
    xi = 2000;
    s3.add(xi, 2);
    cout << "\nS3: ";
    s3.outputSequence();
    cout << "\nS3 size: " << s3.length();


    cout << "\n\nADD, OUTPUTSEQUENCE, LENGTH\nAdded 1 to position 0 + 6 to position 1 + 2002 to position 3>";
    xi = 1;
    s3.add(xi, 0);
    xi = 6;
    s3.add(xi, 1);
    xi = 2002;
    s3.add(xi, 2);
    cout << "\nS3: ";
    s3.outputSequence();
    cout << "\nS3 size: " << s3.length();


    cout << "\n\nENTRY, REMOVE";
    cout << "\nS3[2]: " << s3.entry(2);
    cout << "\nRemoved entry at position 2";
    s3.remove(xi, 2);
    cout << "Element removed: " << xi;
    cout << "\nS3[2]: " << s3.entry(2);
    cout << "\nRemoved entry at position 2";
    s3.remove(xi, 2);
    cout << "Element removed: " << xi;
    cout << "\nS3[3]: " << s3.entry(2);


    cout << "\n\nOUTPUTSEQUENCE, LENGTH\nS3: ";
    s3.outputSequence();
    cout << "\nS3 size: " << s3.length();


    cout << "\n\nCLEAR, OUTPUTSEQUENCE, LENGTH\nClearing Sequence Three";
    s3.clear();
    cout << "\nS3: ";
    s3.outputSequence();
    cout << "\nS3 size: " << s3.length();


    cout << "\n\nADD, OUTPUTSEQUENCE, LENGTH\nAdded 6 to position 0, 2019 to position 1, and 25 to position 1";
    xi = 6;
    s3.add(xi, 0);
    xi = 2019;
    s3.add(xi, 1);
    xi = 25;
    s3.add(xi, 1);
    cout << "\nS3: ";
    s3.outputSequence();
    cout << "\nS3 size: " << s3.length();

    return 0;
    */

};//main

/*          Output
* 
* SEQUENCE ONE
S1: < >

TESTING ADD, OUTPUTSEQUENCE, LENGTH
Filled S1 with <23, 14, 18, 31, 11>
S1: < 23, 14, 18, 31, 11>
S1 size: 5

ADD, OUTPUTSEQUENCE, LENGTH
Added 17 to position 0
S1: < 17, 23, 14, 18, 31, 11>
S1 size: 6

TESTING REMOVE
+ OUTPUTSEQUENCE, LENGTH
Removed entry at position 3
Element removed: 18
S1: < 17, 23, 14, 31, 11>
S1 size: 5

TESTING ENTRY
S1[1]: 23
S1[0]: 17

TESTING CLEAR
+ OUTPUTSEQUENCE
Clearing Sequence One
S1:< >


SEQUENCE TWO
S2: < >

ADD, OUTPUTSEQUENCE, LENGTH
Filled S2 with <1>
S2: < 1>
S2 size: 1

ADD, OUTPUTSEQUENCE, LENGTH
Added 3 to position 3
S2: < 1>
S2 size: 1

ENTRY
S2[3]: 0

REMOVE, OUTPUTSEQUENCE
Removed entry at position 2Element removed: 3
S2: < 1>

ENTRY
S2[0]: 1
S2[1]: 0
S2[2]: 0
S2[3]: 0

CLEAR, OUTPUTSEQUENCE, LENGTH
Clearing Sequence Two
S2: < >
S2 size: 0


SEQUENCE THREE
S3: < >

ADD, OUTPUTSEQUENCE, LENGTH
Filled S3 with <8, 23, 2000>
S3: < 8, 23, 2000>
S3 size: 3

ADD, OUTPUTSEQUENCE, LENGTH
Added 1 to position 0 + 6 to position 1 + 2002 to position 3>
S3: < 1, 6, 2002, 8, 23, 2000>
S3 size: 6

ENTRY, REMOVE
S3[2]: 2002
Removed entry at position 2Element removed: 2002
S3[2]: 8
Removed entry at position 2Element removed: 8
S3[3]: 23

OUTPUTSEQUENCE, LENGTH
S3: < 1, 6, 23, 2000>
S3 size: 4

CLEAR, OUTPUTSEQUENCE, LENGTH
Clearing Sequence Three
S3: < >
S3 size: 0

ADD, OUTPUTSEQUENCE, LENGTH
Added 6 to position 0, 2019 to position 1, and 25 to position 1
S3: < 6, 25, 2019>
S3 size: 3
*/
