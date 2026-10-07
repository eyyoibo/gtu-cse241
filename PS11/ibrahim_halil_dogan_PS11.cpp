#include <iostream>
#include <stdexcept>

using namespace std;

void callFunction(int currentDepth, int throwDepth)
{
    cout << "Depth " << currentDepth << " reached." << endl;

    if (currentDepth == throwDepth)
    {
        throw currentDepth;
    }

    if (currentDepth < 10)
    {
        callFunction(currentDepth + 1, throwDepth);
    }
}

int main()
{
    int throwDepth = -1;

    cout << "Enter the calling depth where the exception will be thrown (0-10): ";
    if (!(cin >> throwDepth))
    {
        cout << "Invalid input: Please enter an integer." << endl;
        return 1;
    }

    try
    {
        if (throwDepth < 0 || throwDepth > 10)
        {
            throw invalid_argument("Depth must be between 0 and 10.");
        }

        if (throwDepth == 0)
        {
            cout << "Depth 0 reached in main." << endl;
            throw 0;
        }

        callFunction(1, throwDepth);
    }
    catch (int depth)
    {
        cout << "Exception thrown and caught at depth " << depth << "." << endl;
    }
    catch (const invalid_argument& error)
    {
        cout << "Invalid input: " << error.what() << endl;
    }

    return 0;
}
