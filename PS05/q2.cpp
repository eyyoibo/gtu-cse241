#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int numClasses;
    string* classList;

public:
    Student() {
        name = "";
        numClasses = 0;
        classList = nullptr;
    }

    ~Student() {
        delete[] classList;
        classList = nullptr;
    }

    Student& operator=(const Student& other) {
        if (this != &other) {
            delete[] classList;

            name = other.name;
            numClasses = other.numClasses;

            if (numClasses > 0) {
                classList = new string[numClasses];
                for (int i = 0; i < numClasses; i++) {
                    classList[i] = other.classList[i];
                }
            } else {
                classList = nullptr;
            }
        }
        return *this;
    }

    string getName() const { return name; }
    int getNumClasses() const { return numClasses; }
    string getClass(int index) const { return classList[index]; }

    void setName(const string& n) { name = n; }

    void InputData() {
        cout << "Enter student name: ";
        getline(cin, name);

        cout << "Enter number of classes: ";
        cin >> numClasses;
        cin.ignore();

        delete[] classList;
        if (numClasses > 0) {
            classList = new string[numClasses];
            for (int i = 0; i < numClasses; i++) {
                cout << "Enter class " << (i + 1) << " name: ";
                getline(cin, classList[i]);
            }
        } else {
            classList = nullptr;
        }
    }

    void OutputData() const {
        cout << "Name: " << name << endl;
        cout << "Number of classes: " << numClasses << endl;
        for (int i = 0; i < numClasses; i++) {
            cout << "  Class " << (i + 1) << ": " << classList[i] << endl;
        }
    }

    void ResetClasses() {
        delete[] classList;
        classList = nullptr;
        numClasses = 0;
    }
};

int main()
{
    Student s1, s2;

    s1.InputData();
    cout << "Student 1's data:" << endl;
    s1.OutputData();

    cout << endl;

    s2 = s1;
    cout << "Student 2's data after assignment from student 1:" << endl;
    s2.OutputData();

    s1.ResetClasses();
    cout << "Student 1's data after reset:" << endl;
    s1.OutputData();

    cout << "Student 2's data, should still have original classes:" << endl;
    s2.OutputData();

    cout << endl;
    return 0;
}
