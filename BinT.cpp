BinT::BinT(Node* ro)
{
    root = ro;
}

BinT::BinT()
{
    root = nullptr;
}


void BinT::right_turn(Node* base)
{
    Node* newBase = base->get_leftSon();
    newBase = base->get_leftSon();

    newBase->set_parent(base->get_parent());
    base->set_parent(newBase);

    if(base  == (newBase->get_parent())->get_leftSon())
        (newBase->get_parent())->set_leftSon(newBase);
    else
        (newBase->get_parent())->set_rightSon(newBase);

    base->set_leftSon(newBase->get_rightSon());
    newBase->set_rightSon(base);

    (base->get_leftSon())->set_parent(base);
}

void BinT::left_turn(Node* base)
{
    Node* newBase = base->get_rightSon();
    newBase = base->get_rightSon();

    newBase->set_parent(base->get_parent());
    base->set_parent(newBase);

    if(base  == (newBase->get_parent())->get_rightSon())
        (newBase->get_parent())->set_rightSon(newBase);
    else
        (newBase->get_parent())->set_leftSon(newBase);

    base->set_rightSon(newBase->get_leftSon());
    newBase->set_leftSon(base);

    (base->get_rightSon())->set_parent(base);
}


void BinT::balance(Node* beg)
{
    if(beg->underBalanced() == 1 || beg->underBalanced() == 3)
        this->balance(beg->get_leftSon());

    if(beg->underBalanced() == 2)
        this->balance(beg->get_rightSon());

    if(beg->underBalanced() == 0)
    {
        if(beg->disbalance() > 1)
        {
            if((beg->get_rightSon())->disbalance() <= 0)
                this->left_turn(beg);
            else
            {
                this->right_turn(beg->get_rightSon());
                this->left_turn(beg);
            }
        }

        if(beg->disbalance() < -1)
        {
            if((beg->get_leftSon())->disbalance() <= 0)
                this->right_turn(beg);
            else
            {
                this->left_turn(beg->get_leftSon());
                this->right_turn(beg);
            }
        }

    }

    if(beg->get_parent() != 0 )
        this->balance(beg->get_parent());
}

void BinT::add(int newElem)
{
    Node* newLeaf = new Node (nullptr, newElem);

    if(this->get_root() == 0)
        this->set_root(newLeaf);
    else
    {
        bool breaker = true;
        Node* nowAt = this->get_root();


        while(breaker)
        {
            if(newElem == nowAt->get_key())
                break;

            if(newElem > nowAt->get_key())
            {
                if(nowAt->get_rightSon() == 0)
                {
                    newLeaf->set_parent(nowAt);
                    nowAt->set_rightSon(newLeaf);
                    break;
                }
                else
                {
                    nowAt = nowAt->get_rightSon();
                    continue;
                }
            }

            if(newElem < nowAt->get_key())
            {
                if(nowAt->get_leftSon() == 0)
                {
                    newLeaf->set_parent(nowAt);
                    nowAt->set_leftSon(newLeaf);
                    break;
                }
                else
                {
                    nowAt = nowAt->get_leftSon();
                    continue;
                }
            }
        }
        while(nowAt != 0)
        {

            if(nowAt->get_leftSon() == 0 && nowAt->get_rightSon() == 0)
                nowAt->set_underHeight(0);

            if(nowAt->get_leftSon() == 0 && nowAt->get_rightSon() != 0)
                nowAt->set_underHeight((nowAt->get_rightSon())->get_underHeight() + 1);

            if(nowAt->get_leftSon() != 0 && nowAt->get_rightSon() == 0)
                nowAt->set_underHeight((nowAt->get_leftSon())->get_underHeight() + 1);

            if(nowAt->get_leftSon() != 0 && nowAt->get_rightSon() != 0)
                nowAt->set_underHeight(std::max((nowAt->get_leftSon())->get_underHeight() + 1, (nowAt->get_rightSon())->get_underHeight() + 1));

            if(nowAt->get_parent() !=0)
                nowAt = nowAt->get_parent();
            else
                break;
        }

        this->balance(this->root);
    }


}


Node* BinT::locate(int k, Node* beg)
{
    if(beg->get_key() == k)
        return beg;

    if(beg->get_key() < k)
    {
        if(beg->get_rightSon() == 0)
            return 0;
        return this->locate(k, beg->get_rightSon());
    }


    if(beg->get_key() > k)
    {
        if(beg->get_leftSon() == 0)
            return 0;
        return this->locate(k, beg->get_leftSon());
    }

}

void BinT::locateDel(int k, Node* beg)
{
    bool lSon;

    if(beg->get_key() == k)
    {
        if(beg->get_parent() == 0)
        {
            if(beg->type() == 0)
                this->set_root(0);

            if(beg->type() == 1)
            {
                this->set_root(beg->get_leftSon());
                beg->get_leftSon()->set_parent(0);
            }

            if(beg->type() == 2)
            {
                this->set_root(beg->get_rightSon());
                beg->get_rightSon()->set_parent(0);
            }

            if(beg->type() == 3)
            {
                this->set_root(beg->get_leftSon());
                beg->get_leftSon()->set_parent(0);
                beg->get_rightSon()->set_parent(0);
            }
        }
        else
        {
            if(k < (beg->get_parent())->get_key())
                lSon = true;
            else
                lSon = false;


            if(beg->type() == 0)
            {
                if(lSon)
                    beg->get_parent()->set_leftSon(0);
                else
                    beg->get_parent()->set_rightSon(0);
            }
            if(beg->type() == 1)
            {
                if(lSon)
                    beg->get_parent()->set_leftSon(beg->get_leftSon());
                else
                    beg->get_parent()->set_rightSon(beg->get_leftSon());

                beg->get_leftSon()->set_parent(beg->get_parent());
            }

            if(beg->type() == 2)
            {
                if(lSon)
                    beg->get_parent()->set_leftSon(beg->get_rightSon());
                else
                    beg->get_parent()->set_rightSon(beg->get_rightSon());

                beg->get_rightSon()->set_parent(beg->get_parent());
            }

            if(beg->type() == 3)
            {
                if(lSon)
                    beg->get_parent()->set_leftSon(beg->get_leftSon());
                else
                    beg->get_parent()->set_rightSon(beg->get_leftSon());

                beg->get_leftSon()->set_parent(beg->get_parent());
                beg->get_rightSon()->set_parent(beg->get_parent());
            }
        }

        delete beg;
    }


    if(beg->get_key() < k)
    {
        if(beg->get_rightSon() != 0)
            this->locateDel(k, beg->get_rightSon());
    }


    if(beg->get_key() > k)
    {
        if(beg->get_leftSon() != 0)
            this->locateDel(k, beg->get_leftSon());
    }

}

Node* BinT::getmin()
{
    Node* nowAt;
    nowAt = this->get_root();

    while(nowAt->get_leftSon() != 0)
        nowAt = nowAt->get_leftSon();
    return nowAt;
}

void BinT::delmin()
{
    Node* nowAt = this->get_root();

    while(nowAt->get_leftSon() != 0)
        nowAt = nowAt->get_leftSon();

    if(nowAt->get_parent() == 0)
    {
        if(nowAt->type() == 0)
            this->set_root(0);

        if(nowAt->type() == 2)
        {
            this->set_root(nowAt->get_rightSon());
            nowAt->get_rightSon()->set_parent(0);
        }

    }
    else
    {
        if(nowAt->type() == 0)
            nowAt->get_parent()->set_leftSon(0);

        if(nowAt->type() == 2)
        {
            nowAt->get_parent()->set_leftSon(nowAt->get_rightSon());
            nowAt->get_rightSon()->set_parent(nowAt->get_parent());
        }
    }

    delete nowAt;


}

void BinT::print(Node* beg)
{
    beg->print();

    if(beg->get_leftSon() != 0)
        this->print(beg->get_leftSon());

    if(beg->get_rightSon() != 0)
        this->print(beg->get_rightSon());

}

void BinT::sorting(Node* beg, bool* res)
{
    Node* nowAt = beg;

    if(nowAt->get_leftSon() != 0 && !(nowAt->get_leftSon())->get_was())
        this->sorting(nowAt->get_leftSon(), res);
    else
    {
        if(nowAt->get_leftSon() != 0 && nowAt->get_rightSon() != 0 && ((nowAt->get_leftSon())->get_underHeight() - (nowAt->get_rightSon())->get_underHeight() < -1 || (nowAt->get_leftSon())->get_underHeight() - (nowAt->get_rightSon())->get_underHeight() > 1))
            *res = false;
        if(nowAt->get_leftSon() == 0 && nowAt->get_rightSon() != 0 && (nowAt->get_rightSon())->get_underHeight() > 0)
            *res = false;
        if(nowAt->get_rightSon() == 0 && nowAt->get_leftSon() != 0 && (nowAt->get_leftSon())->get_underHeight() > 0)
            *res = false;


        nowAt->set_was(true);

        if(nowAt->get_rightSon() != 0 && !(nowAt->get_rightSon())->get_was())
            this->sorting(nowAt->get_rightSon(), res);

        if(nowAt->get_parent() != 0)
            this->sorting(nowAt->get_parent(), res);

    }


}


