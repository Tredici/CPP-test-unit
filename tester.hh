#include <iostream>
#include <vector>
#include <functional>

class tester
{
public:
    using test = void(*)(void);
    using testable = std::function<void(void)>;

    tester(test t) {
        tester::add([=](){t();});
    }

    static void add(testable t) {
        tester::tests.push_back(t);
    }

    static const auto& get_all() {
        return tests;
    }

private:
    static std::vector<testable> tests;
};
std::vector<tester::testable> tester::tests;

int main(int argc, char const *argv[])
{
    constexpr auto separator = "****************************************************************";
    auto& out = std::cout;
    auto i{0LL}; auto success{0LL}; auto fails{0LL};
    for (auto f : tester::get_all()) {
        out << "RUNNING TESTCASES " << ++i << std::endl;
        try
        {
            f();
            out << "SUCCESS" << std::endl;
            ++success;
        }
        catch(const std::exception& e)
        {
            out << "FAILED: " << e.what() << '\n';
            ++fails;
        }
        catch(...)
        {
            out << "FAILED: unknown cause" << '\n';
            ++fails;
        }
        out << std::endl;
        out << separator << std::endl;
    }

    out << "RESULTS:" << std::endl;
    out << "\tTotal number of testcases: " << i << std::endl;
    out << "\tTestcases completed: " << success << std::endl;
    out << "\tTestcases failed:    " << fails << std::endl;
    return 0;
}
