#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

class Node
{
    int value;
    Node* parent;
    Node* leftSon;
    Node* rightSon;
    int underHeight;
    bool was;

public:
    Node();
    Node(Node* par, int val);

    int get_value(){return value;}
    Node* get_parent(){return parent;}
    Node* get_leftSon(){return leftSon;}
    Node* get_rightSon(){return rightSon;}
    int get_underHeight(){return underHeight;}
    bool get_was(){return was;}

    void set_value(int val){value = val;}
    void set_parent(Node* par){parent = par;}
    void set_leftSon(Node* ls){leftSon = ls;}
    void set_rightSon(Node* rs){rightSon = rs;}
    void set_underHeight(int h){underHeight = h;}
    void set_was(bool w){was = w;}

    int disbalance();
    bool underBalanced();
    int type();

    void print();
};



#endif // NODE_H_INCLUDED
