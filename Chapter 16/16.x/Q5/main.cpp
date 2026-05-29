#include "Random.h"
#include <iostream>
#include <string>
#include <string_view>

namespace WordList
{
std::vector<std::string> words{"myserty", "broccoli", "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage"};

std::string_view generateWord(std::vector<std::string> &words)
{
    return words[Random::get(0, words.size()-1)];
}
} // namespace WordList

int main()
{
    std::cout << "Welcome to C++man (a variant of Hangman)" << '\n';
    std::cout << "To win: guess the word. To lose: run out of pluses.\n\n";
    std::cout << "The word is: " << WordList::generateWord(WordList::words) << '\n';

    return 0;
}