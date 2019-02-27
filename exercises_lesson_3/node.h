#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node(int data, Node* next = nullptr);

    void set_next(Node* next);

    Node* next();

    int get_data();

private:
    int data_;
    Node* next_;
};

#endif