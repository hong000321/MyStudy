
#include "virtual_class_test.h"
#include "virtual_class_test2.h"


int main()
{
    Base* base = new Derived();
    PrintTest<Base> print_test;
    print_test.print_all(base);
    delete base;
    return 0;
}
