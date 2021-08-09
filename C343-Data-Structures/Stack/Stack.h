#include "Queue.hpp"
using namespace std;

template <class T>
class Stack1
    //! is modeled by string(T)
    //!   exemplar self
{
public: // standard Operations
    Stack1();
    ~Stack1();

    void clear(void);

    void transferFrom(Stack1& source);

    Stack1& operator =(Stack1& rhs);

   // Stack1 Specific Operations
    void push(T& x);
    void pop(T& x);

    void replaceTop(T& x);
    T& top(void);

    int length(void);
    void outputStack(void);

private: // Representation
    Queue1<T> que1,que2;

};