#include <stdexcept>

class MyLinkedList {
    struct Node {
        int val;
        Node* prev;
        Node* next;

        Node(int n) : val(n), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    MyLinkedList() {
        head = new Node(0); // Dummy head
        tail = new Node(0); // Dummy tail
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    int get(int index) {
        if (!isElementIndex(index)) {
            return -1;
        }
        Node* p = head->next;
        for (int i = 0; i < index; i++) {
            p = p->next;
        }
        return p->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;

        Node* p = head;
        for (int i = 0; i < index; i++) {
            p = p->next;
        }
        Node* x = new Node(val);
        Node* temp = p->next;
        p->next = x;
        x->prev = p;
        x->next = temp;
        temp->prev = x;
        size++;
    }

    void deleteAtIndex(int index) {
        if (!isElementIndex(index)) return;

        Node* p = head->next;
        for (int i = 0; i < index; i++) {
            p = p->next;
        }
        Node* prev = p->prev;
        Node* next = p->next;
        prev->next = next;
        next->prev = prev;
        delete p;
        size--;
    }

private:
    bool isElementIndex(int index) {
        return index >= 0 && index < size;
    }
};