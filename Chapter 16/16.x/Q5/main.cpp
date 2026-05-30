#include "Random.h"
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

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
    std::vector<char> m_letters_guessed{};
    std::vector<char> m_game_state{};
    std::vector<char> m_wrong_guesses{};

  public:
    // constructor
    Session() : m_game_state(m_word.size(), '_'), m_wrong_guesses(6, '+')
    {
    }

    // get word
    std::string_view getWord()
    {
        return m_word;
    }

    void intro()
    {
        std::cout << "Welcome to C++man (a variant of Hangman)" << '\n';
        std::cout << "To win: guess the word. To lose: run out of pluses.\n\n";
    }

    void display()
    {
        std::cout << "The word: ";
        for (char e : m_game_state)
        {
            std::cout << e;
        }

        std::cout << "    Wrong guesses ";
        for (char e : m_wrong_guesses)
        {
            std::cout << e;
        }

        std::cout << '\n';
    }

    void updateGameState(char letter, std::size_t index)
    {
        m_game_state[index] = letter;
    }

    char userInput()
    {
        bool guess_flag = false;

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

            for (char e : m_letters_guessed)
            {
                if (e == letter)
                {
                    std::cout << "You already guessed that. Try again.\n";
                    guess_flag = true;
                    continue;
                }
            }

            if (guess_flag == false)
            {
                m_letters_guessed.push_back(letter);
            }

            std::cout << '\n';

            return letter;
        }
    }

    void letterInWord(char letter)
    {
        int found{0}; // 0 = not found, 1 = found

        for (std::size_t i{0}; i < m_word.size(); i++)
        {
            if (letter == m_word[i])
            {
                found = 1;
                std::cout << "Yes, '" << letter << "' is in the word!\n";
                updateGameState(letter, i);
            }
        }

        if (found == 0)
        {
            wrongGuesses(letter);
        }
    }

    bool foundAllLetters()
    {
        // convert vector to a string
        std::string m_game_state_str(m_game_state.begin(), m_game_state.end());

        if (m_game_state_str == m_word)
        {
            return true;
        }

        return false;
    }

    void wrongGuesses(char letter)
    {
        static std::size_t index{m_wrong_guesses.size() - 1};
        static int count_wrong_guesses{0};

        if (count_wrong_guesses == 5)
        {
            youLose();
            return;
        }

        std::cout << "No, '" << letter << "' is not in the word!\n";

        m_wrong_guesses[index] = letter;
        index--;
        count_wrong_guesses++;
    }

    void youWin()
    {
        std::cout << "You win!\n";
    }

    void youLose()
    {
        std::cout << "You lost! The word was: " << m_word << '\n';
        exit(1);
    }
};

int main()
{
    Session session;
    char letter;

    session.intro();
    std::cout << "The word is: " << session.getWord() << '\n';
    session.display();

    while (session.foundAllLetters() == false)
    {
        letter = session.userInput();
        session.letterInWord(letter);
        session.display();
    }

    if (session.foundAllLetters() == true)
    {
        session.youWin();
    }
    else
    {
        session.youLose();
    }

    return 0;
}
