#include <iostream>
#include <utility>

// struct
template <typename T=int, typename U=int, typename K=int>
struct Triad
{
    T first{};
    U second{};
    K third{};
};

// deduction guide
template <typename T=int, typename U=int, typename K=int>
Triad(T, U, K) -> Triad<T, U, K>;

template <typename T>
void print(T t)
{
    std::cout << "[" << t.first << ", " << t.second << ", " << t.third << "]";
}

int main()
{
    Triad t1{1, 2, 3}; // note: uses CTAD to deduce template arguments
    print(t1);

    Triad t2{1.2, 3.4, 5.6}; // note: uses CTAD to deduce template arguments
    print(t2);

    return 0;
}