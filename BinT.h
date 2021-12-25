#ifndef BINT_H_INCLUDED
#define BINT_H_INCLUDED

class BinT
{
    Node* root;

public:

    BinT(Node* ro);
    BinT();

    Node* get_root(){return root;}
    void set_root(Node* ro){root = ro;}


    void add(int newElem);
    void sorting(Node* beg, bool* res);

    void right_turn(Node* base);
    void left_turn(Node* base);
    void balance(Node* beg);

    Node* locate(int k, Node* beg);
    void locateDel(int k, Node* beg);

    Node* getmin();
    void delmin();

    void print(Node* beg);
};


#endif // BINT_H_INCLUDED
