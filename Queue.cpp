struct My_queue{
    struct Node{
        int data;
        Node* next = nullptr;
    };

    Node* Head = nullptr;
    Node* Tail = nullptr;

    bool Empty() {
        return Head == nullptr;
    }

    void Push(int _data) {
        Node* n = new Node;
        n->data = _data;
        if (Empty()) {
            Tail = n;
            Head = n;
            Head->next = Tail;
        } else {
            Tail->next = n;
            Tail = n;
        }
    }

    int Pop() {
        if (Empty()) return 0;
        int data = Head->data;
        Head = Head->next;
        return data;
    }
};