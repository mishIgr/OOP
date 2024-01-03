#include <string>
#include <vector>
#include <iostream>
#include <sstream>

template<typename T>
concept ObjStream = requires(T obj, std::ostream& out) { {out << obj}; };

class FormatException : public std::exception {
public:
    FormatException(std::string format, int arg_number)
            : message("Invalid number of arguments for format: \"" + format + "\". Required: " + std::to_string(arg_number)) {}

    const char* what() const noexcept {
        return message.c_str();
    }

private:
    std::string message;
};

class FormatString {
public:
    FormatString(const std::string& format) : format(format) {}

    template<ObjStream ... T>
    std::string operator()(T ... args) const {
        std::vector<std::string> args_str;
        (add_arg(args_str, args), ...);
        if (args_str.size() != arg_number())
            throw FormatException(format, arg_number());

        std::stringstream output;
        std::string tmp(format);
        while (tmp.size()) {
            auto p = tmp.find('%');
            if (p == std::string::npos) {
                output << tmp;
                tmp = "";
            }
            else {
                output << tmp.substr(0, p);
                tmp = tmp.substr(p + 1);
                if (std::isdigit(tmp[0])) {
                    output << args_str[std::stoi(tmp.substr(0, 1)) - 1];
                    tmp = tmp.substr(1);
                }
                else if (tmp[0] == '%') {
                    output << "%";
                    tmp = tmp.substr(1);
                }
            }
        }

        return output.str();

    }

    int arg_number() const {
        int counter = 0;
        for (int i = 0; i < format.size() - 1; ++i) {
            if (format[i] == '%' && std::isdigit(format[i + 1]))
                counter = std::max(counter, std::stoi(format.substr(i + 1, i + 2)));
        }
        return counter;
    }

private:

    template<ObjStream T>
    void add_arg(std::vector<std::string>& args, T arg) const {
        std::stringstream strstream;
        strstream << arg;
        args.push_back(strstream.str());
    }

    std::string format;
};

FormatString operator""_fstr(const char* str, std::size_t len) {
    return FormatString(std::string(str, len));
}

int main() {
    auto format_str = "Hello, %2. I am %1! Buy, %2"_fstr;
    std::string str = format_str(3.14, 'F');
    std::string another_str = format_str('Q', 333);
    std::cout << str << std::endl;
    std::cout << another_str << std::endl;

    format_str = "% %1 -- %2 --- %%%"_fstr;
    str = format_str(3.14, 'F');
    another_str = format_str('Q', 333);
    std::cout << str << std::endl;
    std::cout << another_str << std::endl;


    return 0;
}
