// COMSC-210 | Lab 11 | Seoyeon An

#include <iostream>
#include <fstream>
#include <array>

#include <algorithm>
#include <numeric>
using namespace std;

const int DAYS = 30;

bool loadData(const string& filename, array<int, DAYS>& visits);
void printData(const array<int, DAYS>& visits, const string& title);
int main() {
    array<int, DAYS> visits;

    cout << "empty()? "
         << (visits.empty() ? "True" : "False") << endl;

    if (!loadData("visit.txt", visits)) {
        cout << "File error visit.txt not found";
        return 0;
    }

    cout << "size(): " << visits.size() << "\n";
    cout << "front(): " << visits.front() << "\n";
    cout << "back(): " << visits.back() << "\n";
    cout << "at(2): " << visits.at(2) << "\n";



    int sum = accumulate(visits.begin(), visits.end(), 0);
    cout << "\nSum: " << sum << endl;



    array<int, DAYS> zeros;
    sort(sorted.begin(), sorted.end());
    printData(sorted, "\nSorted data:");

    // member functions: fill(), swap()
    array<int, DAYS> baseline;
    baseline.fill(0);
    printData(baseline, "\nBaseline (fill(0)):");

    baseline.swap(sorted);
    printData(baseline, "After swap:");
    printData(sorted, "After swap:");

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