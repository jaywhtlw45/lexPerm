// Jason Whitlow (0593858)
// Programming Assignment 4: Lexographic Permutation
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//int genLexPerm(n);
int nextPerm();
bool validInput();
string getUserInput(); // returns an ordered vector

// test case 2, 5 5, 6,

int main()
{
    string userInput;

    cout << "User will enter a list of integers separated by commas." << endl
         << "For example '5, 4, 2, 99, 54' is a valid entry." << endl
         << "  1. The list of integers must contain only positive integers." << endl
         << "  2. The list must start and end with an integer." << endl
         << "  3. Every integer must be separated by a comma and then a space." << endl
         << "  4. Any repeated integers will be removed from the list." << endl;

    userInput = getUserInput();

    //genLexPermutations();
    return 0;
}

// accepts user input as string
// string should be in the form "16, 72, 599, 4"
string getUserInput()
{
    bool validInput;
    string input;

    // input validation
    validInput = false;
    while (!validInput)
    {
        cout << "Enter a list of integers: ";
        getline(cin, input);

        // special case for empty string
        if (input == "")
        {
            cout << "Input cannot be blank!" << endl;
            continue;
        }

        // check for correct formatting
        // string format: "5, 4, 99, 100"
        validInput = true;
        for (size_t i = 0; i < input.length(); i++)         // test ', '
        {

            // special case: last digit
            if (i == (input.length() - 1))
            {
                if(isdigit(input[i]))
                    break;
                else
                {
                    validInput = false;
                    break;
                }
                
            }

            while (isdigit(input[i]))
            {
                i++;
            }

            // next char: ','
            if (input[i] != ',')
            {
                validInput = false;
                break;
            }

            // next char; ' '
            i++;
            if (input[i] != ' ')
            {
                validInput = false;
                break;
            }

            // next char
            i++;

            // special case: string ends in ', '
            if(i == input.length())
            {
                validInput = false;
                break
            }
        }

        // clear input stream
        while (getchar() != '\n')
            ;
        cin.clear();
    }

    return input;
}
