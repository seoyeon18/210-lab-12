// COMSC-210 | Lab 11 | Seoyeon An

#include <iostream>
#include <fstream>
#include <array>
using namespace std;

const int DAYS = 30;

bool loadData(const string& filename, array<int, DAYS>& visits);

int main() {
    array<int, DAYS> visits;

    cout << "empty()? "
         << (visits.empty() ? "True" : "False") << endl;

    if (!loadData("visit.txt", visits)) {
        cout << "File error";
        return 0;
    }

    cout << "size(): " << visits.size() << endl;
    cout << "front(): " << visits.front() << endl;
    cout << "back(): " << visits.back() << endl;

    cout << " visitor data:";
    for (int i = 0; i < DAYS; i++)
        cout << visits[i] << endl;

    return 0;
}

bool loadData(const string& filename, array<int, DAYS>& visits) {
    ifstream fin;
    fin.open(filename);

    if (!fin.good())
        return false;

    for (int i = 0; i < DAYS; i++)
        fin >> visits[i];

    fin.close();
    return true;
}