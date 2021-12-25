Node::Node()
{
    value = 0;
    parent = nullptr;
    leftSon = nullptr;
    rightSon = nullptr;
    underHeight = 0;
    was = false;
}


Node::Node(Node* par, int val)
{
    value = val;
    parent = par;
    leftSon = nullptr;
    rightSon = nullptr;
    underHeight = 0;
    was = false;
}

int disbalance()
{
    int l, r;

    if(this->get_leftSon() == 0)
        l = 0;
    else
        l = (this->get_leftSon())->get_underHeight() + 1;

     if(this->get_rightSon() == 0)
        r = 0;
    else
        r = (this->get_rightSon())->get_underHeight() + 1;

    return l - r;

}

int underBalanced()
{
    bool l, r;

    if(this->get_rightSon() == 0)
        r = true;
    else
    {
        if((this->get_rightSon())->disbalance() > 1 || (this->get_rightSon())->disbalance() < -1)
            r = false;
        else
            r = true;
    }

    if(this->get_leftSon() == 0)
        l = true;
    else
    {
        if((this->get_leftSon())->disbalance() > 1 || (this->left_rightSon())->disbalance() < -1)
            l = false;
        else
            l = true;
    }

    if(r && !l)
        return 1;
    if(l && !r)
        return 2;
    if(r && l)
        return 0;
    if(!r && !l)
        return 3;
}

int type()
{
    if(this->get_leftSon() == 0 && this->get_rightSon() == 0)
        return 0;

    if(this->get_leftSon() != 0 && this->get_rightSon() == 0)
        return 1;

    if(this->get_leftSon() == 0 && this->get_rightSon() != 0)
        return 2;

    if(this->get_leftSon() != 0 && this->get_rightSon() != 0)
        return 3;

}

void print()
{
    std::cout << "Element " this << " is " << this->get_key() << ". Height is " << this->get_underHeight + 1 << ". Left son is  " << this->get_leftSon << ". Right son is "  << this->get_rightSon() << std::endl;
}
