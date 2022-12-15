struct My_stack{
    struct Node{
        int data = 0;
        Node* next = nullptr;
    };

    Node* Head = nullptr;

    bool Empty() {
        return Head == nullptr;
    }

    void Push(int _data) {
        Node* n = new Node;
        n->data = _data;
        n->next = Head;
        Head = n;
    }

    int Pop() {
        if (!Empty()) {
            int data = Head->data;
            Head = Head->next;
            return data;
        }
        return 0;
    }
};