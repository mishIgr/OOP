#include <iostream>
#include <algorithm>
#include <any>
#include <stack>
#include <stdexcept>
#include <vector>
#include <tuple>

template<typename T>
class Function {

    template<typename Func, typename... Args>
    struct is_func_impl {
    private:
        typedef char(&yes)[1];
        typedef char(&no)[2];

        template<typename U>
        static yes test(U* u, decltype((*u)(std::declval<Args>()...))* = nullptr);
        static no test(...);

    public:
        enum { value = sizeof(test(static_cast<Func*>(nullptr))) == sizeof(yes) };
    };

    template<typename... Args, typename Func>
    bool is_func(Func func) {
        return is_func_impl<Func, Args...>::value;
    }

    T func;
    int count_args;

public:

    Function(T func, int count_args) : func(func), count_args(count_args) {}

    template<typename ... Args>
    bool substitute(Args ... args) { return is_func<Args ...>(func); }

    template<typename ... Args>
    auto operator()(Args ... args) { return func(args...); }

    int get_count_args() { return count_args; }

};

class Parser {

    std::vector<std::string> name_func;
    std::tuple<> functionals;

    bool removeSubstring(std::string& str, const std::string& substr) {
        auto pos = str.find(substr);
        if (pos != std::string::npos) {
            str.erase(pos, substr.length());
            return true;
        } else {
            return false;
        }
    }

    class Expression {

    };

public:

    template<typename Func>
    void setHandler(std::string name, Func func) {
        name.erase(std::remove_if(name.begin(), name.end(), [](unsigned char x){return std::isspace(x);}), name.end());
        int counter_args;
        auto p = name.find("_1");
        if (p == std::string::npos)
            throw std::runtime_error("Not found _1");
        p = name.find("_2");
        if (p == std::string::npos) {
            if (!removeSubstring(name, "(_1)"))
                removeSubstring(name, "_1");
            counter_args = 1;
        }
        else {
            if (!removeSubstring(name, "(_1, _2)")) {
                removeSubstring(name, "_1");
                removeSubstring(name, "_2");
            }
            counter_args = 2;
        }

        auto f = Function(func, counter_args);
        std::tuple tmp = { f };
        functionals = std::tuple_cat(functionals, tmp);
    }

    Expression handle(const std::string& input) {

    }
};

int main() {

    Parser parser;
    parser.setHandler("_1+_2", [](auto x, auto y){ return x + y; });

    return 0;
}
