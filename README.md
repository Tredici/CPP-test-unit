# Description
Basic C++ testing framework.

# Usage
Import "tester.hh" header and create global objects to supply test objects to testing framework.

"main()" **MUST NOT** be included in source file because it is supply by framework.

A testcase is considered successfull if it completes without throwing anything. Failing testcases do not block subsequent tests.

```cpp
#include <iostream>
#include <stdexcept>
#include "../tester.hh"

// successful
void f() {
    std::cout << "TEST 1" << std::endl;
}
tester t(f);

// successful
tester t2([](){
    std::cout << "TEST 2" << std::endl;
});

// fails
tester t3([](){
    std::cout << "TEST 3" << std::endl;
    throw std::runtime_error("BOOM!");
});

// fails
tester t4([](){
    std::cout << "TEST 4" << std::endl;
    throw 1;
});

```

