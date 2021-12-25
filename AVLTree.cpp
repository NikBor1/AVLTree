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
        std::cout << "If you want to find an element by the key, enter 3:\n";
        std::cout << "If you want to find the smallest element, enter 4:\n";
        std::cout << "If you want to delete a an element by the key, enter 5:\n";
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
                break;
            }
            case 3:
            {
                int k;
                std::cout << "Enter the key: \n";
                std::cin >> k;

                if(mainTree.locate(k, mainTree.get_root()) == 0)
                    std::cout << "There is no element with this key. Please, try again.\n";
                else
                    std::cout << "Element address is " << mainTree.locate(k, mainTree.get_root()) << std::endl;
                break;
            }
            case 4:
            {
                if(mainTree.getmin() == 0)
                    std::cout << "There is no elements in tree. Please, try again.\n";
                else
                    std::cout << "Element address is " << mainTree.getmin() << std::endl;
                break;
            }
            case 5:
            {
                int k;
                std::cout << "Enter the key: \n";
                std::cin >> k;
                mainTree.locateDel(k, mainTree.get_root());
                break;
            }
            case 6:
            {
                mainTree.delmin();
                break;

            }
            case 7:
            {
                mainTree.print(mainTree.get_root());
                break;
            }
            default:
            {
                break;
            }
        }
    }




    return 0;
}
