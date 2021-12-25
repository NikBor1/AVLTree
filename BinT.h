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
    void balace(Node* beg);

    Node* BinT::locate(int k, Node* beg);
    void BinT::locateDel(int k, Node* beg);

    Node* BinT::getmin();
    void BinT::delmin();

    void print(Node* beg);
};


#endif // BINT_H_INCLUDED
