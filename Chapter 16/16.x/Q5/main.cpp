#include "Random.h"
#include <iostream>
#include <string>
#include <string_view>

namespace WordList
{
std::vector<std::string> words{"myserty", "broccoli",  "account",  "almost", "spaghetti",
                               "opinion", "beautiful", "distance", "luggage"};

std::string_view generateWord(std::vector<std::string> &words)
{
    return words[Random::get(0, words.size() - 1)];
}
} // namespace WordList

class Session
{
  private:
    std::string m_word{WordList::generateWord(WordList::words)};

  public:
    std::string_view getWord()
    {
        return m_word;
    }

    void display()
    {
        std::cout << "The word: ";

        for (std::size_t i; i <= m_word.size(); i++)
        {
            std::cout << "_";
        }
    }

    char userInput()
    {
        while (true)
        {
            char letter;

            std::cout << "Enter your next letter: ";
            std::cin >> letter;

            if (!std::cin)
            {
                std::cin.clear();
                std::cout << "That wasn't a valid input. Try again\n";
                continue;
            }

            if (letter < 'a' || letter > 'z')
            {
                std::cout << "That wasn't a valid input. Try again.\n";
                continue;
            }

            return letter;
        }
    }
};

int main()
{
    Session session;
    char letter;

    std::cout << "Welcome to C++man (a variant of Hangman)" << '\n';
    std::cout << "To win: guess the word. To lose: run out of pluses.\n\n";
    // std::cout << "The word is: " << session.getWord() << '\n';

    session.display();
    std::cout << '\n';

    session.userInput();

    return 0;
}