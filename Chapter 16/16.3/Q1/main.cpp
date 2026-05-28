#include <vector>
#include <iostream>

int main()
{
    std::vector arr{'h', 'e', 'l', 'l', 'o'};

    std::cout << "The array has " << arr.size() << " elements\n";
    std::cout << arr[1] << arr.at(1) << '\n';

    return 0;
}