#include "vector.h"

int main()
{
    Vector<int> b(4);

    b[0] = 1;
    b[1] = 2;
    b[2] = 3;
    b[3] = 4;

    b.print();
    b.push_back(5);
    std::cout<<std::endl;
    b.print();
    
    std::cout<<std::endl;

    b.pop_back();
    b.print();

    std::cout<<std::endl;

    Vector<int> a(7);

    a[0] = 11;
    a[1] = 21;
    a[2] = 31;
    a[3] = 41;
    a[4] = 20;
    a[5] = 32;
    a[6] = 11;

    b.swap(a);
    
    b.print();
    std::cout<<std::endl;
    a.print();
    


    return 0;
}