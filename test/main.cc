#include <iostream>
#include <stdexcept>
#include "../tester.hh"

void f() {
    std::cout << "TEST 1" << std::endl;
}
tester t(f);

tester t2([](){
    std::cout << "TEST 2" << std::endl;
});

tester t3([](){
    std::cout << "TEST 3" << std::endl;
    throw std::runtime_error("BOOM!");
});

tester t4([](){
    std::cout << "TEST 4" << std::endl;
    throw 1;
});
