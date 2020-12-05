//Brandon Mohamed   
//12-5-20
//Exceptions 15a
//CIS 1202.502

#include <iostream>
#include <string>
#include <cctype>

using namespace std;


char character(char start, int offset);

int main()
{
    char endProgram, charStart, charEnd;

    int offset;

    cout << "Character offset calculator" << endl;

    do
    {
        cout << "Enter a letter to start with: "; cin >> charStart;

        cout << "Enter the offset: "; cin >> offset;

        charEnd = character(charStart, offset);
        if (charEnd != 0)
        {
            cout << "The new character is: " << charEnd << endl;
        }

        cout << "Another? Y/N: "; cin >> endProgram;

        cout << endl;
    } while (endProgram == 'Y' || endProgram == 'y');

    return 0;
}

char character(char start, int offset)
{


    char newChar = start + offset;


    try
    {
        if (!isalpha(start))
        {

            throw string("invalidCharacterException");
        }
        else if (!isalpha(newChar))
        {

            throw string("invalidRangeException");
        }
        else if (islower(start) && isupper(newChar) || islower(newChar) && isupper(start))
        {
            throw string("caseTransitionException");
        }
        else
        {
            return newChar;
        }
    }
    catch (string x)
    {
        cout << x << endl;
        return 0;
    }
}