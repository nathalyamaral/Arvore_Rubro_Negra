#ifndef _RBTREE_H_
#define _RBTREE_H_
#include <stdio.h>

#define RED 0
#define BLACK 1

class Node{

    public:
        Node* left;
        Node* right;
        Node* parent;
        int value;
        int color;

        Node(){
            left = right = parent = NULL;
            color = BLACK;
        }

        Node(int value){
            this->value = value;
        }
};

class RBTree{

    private:
        Node* nil;
        Node* root;
        int numberOfNodes;

        void leftRotation(Node*);
        void rightRotation(Node*);
        void RBTransplant(Node*, Node*);
        Node* sucessor(Node*);
        void print(Node*);
        void insertFixUp(Node*&);
        void removeFixUp(Node*&);
        void deleteTree(Node*);

    public:
        RBTree();
        ~RBTree();

        void insert(int);
        bool remove(int);
        bool contains(int);

        void print();
        int size() const;
        bool isEmpty() const;
};

#endif
