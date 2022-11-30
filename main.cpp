// Jason Whitlow (0593858)
// Programming Assignment 4: Lexographic Permutation

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> getUserInput();                     // returns user input as a vector
void genLexPerm(vector<int> const &inputVec);   // generates all lexographic permutations of an ordered vector                               
void printVec(vector<int> const &inputVec);     // prints a vector
void removeDup(vector<int> &inputVec);          // removes duplicate values from an ordered vector
void bubbleSort(vector<int> &inputVec);         // sorts a vector
void reverse(vector<int> &inputVec);            // reverse the order of a vector
void nextPerm(vector<int> &inputVec);           // finds the next permutation and stores it in inputVec


int main()
{
    vector<int> inputVec;
    bool exit;
    string s;

    cout << "User will enter a list of integers separated by spaces." << endl
         << "For example '5 4 2 99 54' is a valid entry." << endl
         << "  1. The list of integers must contain only positive integers." << endl
         << "  2. The list must contain only digits and spaces." << endl
         << "  3. Any repeated integers will be removed from the list." << endl
         << endl;

    exit = false;
    while (!exit)
    {
        inputVec = getUserInput();
        
        nextPerm(inputVec);
        printVec(inputVec);
        
        /*
        bubbleSort(inputVec);
        removeDup(inputVec);
        printVec(inputVec);
        genLexPerm(inputVec);
        printVec(inputVec);
        */

        cout << "Exit? type 'e' to exit, enter to continue: ";
        getline(cin, s);

        if (s == "e" || s == "E")
            exit = true;
    }

    return 0;
}

// accepts user input as string and returns as vector
// string should be in the form "16 72 599 4"
vector<int> getUserInput()
{
    bool validInput;
    string input;
    vector<int> inputVec;

    // input validation
    validInput = false;
    while (!validInput)
    {
        cout << "Enter a list of integers: ";
        getline(cin, input);

        // remove leading spaces
        int counter = 0;
        while (input[counter] == ' ')
        {
            counter++;
        }
        input = input.substr(counter, input.length()-counter);

        // remove trailing spaces
        counter = input.length()-1;
        while (input[counter] == ' ')
        {
            counter--;
        }
        input = input.substr(0, counter + 1);

        // special case for empty string
        if (input == "")
        {
            cout << "Input cannot be blank!" << endl;
            continue;
        }

        // check for correct formatting
        // string format: "5 4 99 100"
        validInput = true;
        inputVec.clear();
        for (size_t i = 0; i < input.length(); i++)
        {
            // fail if not digit
            if (input[i] != ' ' && !isdigit(input[i]))
            {
                // cout << "fail if not digit" << endl;
                validInput = false;
                break;
            }

            // remove space
            while (input[i] == ' ')
                i++;

            // get and store integer
            string buffer = "";
            while (isdigit(input[i]))
            {;
                buffer.push_back(input[i]);
                i++;
            }
            inputVec.push_back(stoi(buffer));
        }
    }
    return inputVec;
}

// print vector
void printVec(vector<int> const &inputVec)
{
    for (int i = 0; i < inputVec.size(); i++)
    {
        cout << inputVec.at(i) << ' ';
    }
    cout << endl;
}

// removes duplicate values from a vector
void removeDup(vector<int> &inputVec)
{
    for (size_t i = 0; i < inputVec.size()-1; i++)
        {
            if (inputVec[i] == inputVec[i+1])
            {
                auto it = inputVec.begin() + i;
                inputVec.erase(it);
                i--;
            }
        }
}

// sorts a vector in ascending order using bubble sort
void bubbleSort(vector<int> &inputVec)
{
    int temp;
    bool swap = true;
    while(swap)
    {
        swap = false;
        for (size_t i = 0; i < inputVec.size()-1; i++)
        {
            if (inputVec[i]>inputVec[i+1])
            {
                temp = inputVec[i];
                inputVec[i]= inputVec[i+1];
                inputVec[i+1]=temp;
                swap = true;
            }
        }
    }
}

// accepts a vector assorted in ascending order
// prints all permutations of the vector
void genLexPerm(vector<int> const &inputVec)
{
    vector<int> next = inputVec;
    vector<int> final = inputVec;
    reverse(final);
    int count =0;

    int i = 0;
   while (next != final)
   {
    //for (size_t i = 0; i < 10; i++)
    //{
        /* code */
        i++;
        cout << "-----------------------------------i: " << i << endl;
        printVec(next);
        nextPerm(next);
   //}
    }
    printVec(next);
   //}
   
}

// reverses the order of a vector
void reverse(vector<int> &inputVec)
{
    int temp;
    for (size_t i = 0; i < inputVec.size()/2; i++)
    {
        temp = inputVec[i];
        inputVec[i] = inputVec[inputVec.size()-i-1];
        inputVec[inputVec.size()-i-1] = temp;
    }
}

// size 1
// accepts a vector as input and modifies the vector to be the next permutation
void nextPerm(vector<int> &inputVec)
{
    // special case, size less than 2
    if (inputVec.size()<2) return;

    // moving from right to left, find the first decreasing value
    int leftIndex = inputVec.size()-1; 
    int temp = inputVec.size()-1;     
    while (leftIndex > 0 && inputVec[leftIndex] < inputVec[leftIndex -1])
    {
        cout << "204" << endl;
        if (inputVec[leftIndex-1] > inputVec[temp]) temp = leftIndex-1;
        leftIndex --;
    }
    leftIndex --;

    cout << "test1" << endl;
    cout << "temp = " << temp << endl;
    cout << "leftIndex = " << leftIndex << endl;
    //cout << "rightIndex = " << rightIndex<< endl;
     printVec(inputVec);
  

    // special case
    // if leftIndex equals 0 and inputVec[0] > inputVec[1]
    // then the vector is already in decreasing order
    if (leftIndex == 0 && inputVec[0] > inputVec[1]) return;

    // find the smallest value after leftIndex that is larger than leftIndex
    // in other words... if we have the vector 1 2 4 9 8 7 6 5 3
    // leftIndex will be set to 4 and temp will be set to 5 (the smallest value that is larger than 4)
    int rightIndex = inputVec.size()-1;
    while (leftIndex < rightIndex)
    {
        
        //cout << "rightIndex" << rightIndex << endl;
        //cout << "leftIndex" << leftIndex << endl;
        if (inputVec[rightIndex]>inputVec[leftIndex] && inputVec[rightIndex] < inputVec[temp]) 
        {
            temp = rightIndex;
        }
        rightIndex = rightIndex -1;
    }

    cout << "test2" << endl;
    cout << "temp = " << temp << endl;
    cout << "leftIndex = " << leftIndex << endl;
    cout << "rightIndex = " << rightIndex<< endl;
     printVec(inputVec);

    // swap the values of leftIndex and temp
    int tempValue = inputVec[temp];
    inputVec[temp] = inputVec[leftIndex];
    inputVec[leftIndex] = tempValue;

    cout << "test2b" << endl;
    cout << "temp = " << temp << endl;
    cout << "leftIndex = " << leftIndex << endl;
    cout << "rightIndex = " << rightIndex<< endl;
     printVec(inputVec);

    // reorder everything to the right of leftIndex in increasing order
    vector<int> tempVec(inputVec.begin()+leftIndex+1, inputVec.end());
    bubbleSort(tempVec);
    leftIndex++;
    for (size_t i = 0; i < tempVec.size(); i++)
    {
        inputVec[leftIndex + i] = tempVec[i];
    }

        cout << "test3" << endl;
    cout << "temp = " << temp << endl;
    cout << "leftIndex = " << leftIndex << endl;
    cout << "rightIndex = " << rightIndex<< endl;
     printVec(inputVec);

    return;
}