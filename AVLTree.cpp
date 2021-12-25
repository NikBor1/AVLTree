#include <iostream>
#include <vector>
#include "Node.h"
#include "BinT.h"
#include "Node.cpp"
#include "BinT.cpp"



int main()
{
    int st = 0;

    BinT mainTree;

    while(st != 1)
    {
        std::cout << "Hello! If you want to end the program, enter 1:\n";
        std::cout << "If you want to add a new element, enter 2:\n";
        std::cout << "If you want to find an element by key, enter 3:\n";
        std::cout << "If you want to find the smallest element, enter 4:\n";
        std::cout << "If you want to delete a an element by key, enter 5:\n";
        std::cout << "If you want to delete the smallest element, enter 6:\n";
        std::cout << "If you want to see the tree, enter 7:\n";
        std::cin >> st;

        switch(st)
        {
            case 1:
            {
                break;

            }
            case 2:
            {
                int k;

                std::cout << "Enter a new element: \n";
                std::cin >> k;
                mainTree.add(k);
            }
            case 3:
            {

            }
            case 4:
            {

            }
            case 5:
            {

            }
            case 6:
            {

            }
            case 7:
            {

            }
        }
    }




    return 0;
}
