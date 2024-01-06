#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <algorithm>
#include <stdexcept>

template <size_t N>
class Mask {

    std::vector<bool> mask;

public:

    template<typename ... Args>
    requires(std::is_convertible_v<Args, bool>&&...)
    Mask(Args ... arg) {
        (mask.push_back(arg), ...);
        if (mask.size() != N)
            throw std::invalid_argument("Size of initializer list does not match the size of the mask.");
    }

    size_t size() const { return N; }

    bool at(size_t index) const {
        if (index >= N)
            throw std::out_of_range("Index is out of range.");
        return mask[index];
    }

    template <typename Container>
    requires std::ranges::range<Container> &&
    requires(Container container) { { container.erase(std::declval<typename Container::iterator>()) }; }
    void slice(Container& container) const {
        size_t index = 0;
        for (auto it = container.begin(); it != container.end(); ++it) {
            if (!mask[index]) {
                it = container.erase(it);
                --it;
            }
            index = (index + 1) % N;
        }
    }

    template <typename Container, typename TransformFunc>
    requires (std::derived_from<Container, std::vector<typename Container::value_type>> ||
              std::derived_from<Container, std::list<typename Container::value_type>>) &&
              std::invocable<TransformFunc, typename Container::value_type>
    auto transform(const Container& container, TransformFunc func) {
        Container result;
        size_t index = 0;
        for (auto it = container.begin(); it != container.end(); ++it) {
            if (mask[index])
                result.push_back(func(*it));
            else
                result.push_back(*it);
            index = (index + 1) % N;
        }
        return result;
    }

    template <typename Container, typename TransformFunc>
    requires (std::derived_from<Container, std::vector<typename Container::value_type>> ||
              std::derived_from<Container, std::list<typename Container::value_type>>) &&
              std::invocable<TransformFunc, typename Container::value_type> &&
                      requires(Container container) { { container.erase(std::declval<typename Container::iterator>()) }; }
    auto slice_and_transfrom(const Container& container, TransformFunc func) {
        Container result(container);
        slice(result);
        std::transform(result.begin(), result.end(), result.begin(), func);
        return result;
    }

};

template <typename Container>
requires std::ranges::range<Container>
std::ostream& operator<<(std::ostream & out, Container container) {
    for (const auto& el : container)
        out << el << " ";
    return out;
}

int main() {

    std::set s = {"kjh", "kcjj", "cdcdsv"};
    Mask<2> mask1 = {0, 1};
    mask1.slice(s);
    std::cout << s << std::endl;

    std::vector v {1, 2, 3, 4, 5, 6, 7};
    Mask<3> mask2 = {1, 0, 1};
    v = mask2.transform(v, [](int x){ return x % 2; });
    std::cout << v << std::endl;

    v = {1, 2, 3, 4, 5, 6, 7};
    v = mask1.slice_and_transfrom(v, [](int x){ return x % 2; });
    std::cout << v << std::endl;

    return 0;
}
