#include "Sequence.hpp"
template <class T>
class Queue1
    //! is modeled by string of T
    //!   exemplar self
{
public: // Standard Operations
     Queue1();
    ~Queue1();

    void clear(void);

    void transferFrom(Queue1& source);

    Queue1& operator = (Queue1& rhs);

    void enqueue(T& x);

    void dequeue(T& x);

    void replaceFront(T& x);

    T& front(void);

   int length(void);

    void outputQueue(void);


private: // Representation
    Sequence<T> seq;
};