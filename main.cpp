#include "vector.h"

int main()
{
    Vector<int> a(7);

    a[0] = 11;
    a[1] = 21;
    a[2] = 31;
    a[3] = 41;
    a[4] = 20;
    a[5] = 32;
    a[6] = 11;

    a.reserve(18);
    std::cout<<a.capacity()<<std::endl;
    a.print();
	    
    


    return 0;
}
