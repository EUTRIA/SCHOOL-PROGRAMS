using namespace std;
template <class T>
class Sequence
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

    void transferFrom(Sequence& source);
    Sequence& operator=(Sequence& rhs);

private: // Internal operations
    void reclaimAllNodes(NodeRecord*& p);
};

