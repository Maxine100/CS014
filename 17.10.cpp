#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>

using namespace std;

vector<char> createVector() {
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for (int i = 0; i < vecSize; i++) {
        vals.push_back(c);
        c++;
    }
    return vals;
}

template<typename T>
unsigned min_index(const vector<T>& vals, unsigned index) {
    T min = vals.at(index);
    unsigned minIndex = index;
    for (int i = index; i < vals.size(); ++i) {
        if (vals.at(i) < min) {
            minIndex = i;
        }
    }
    return minIndex;
}

template<typename T>
void selection_sort(vector<T>& vals) {
    for (unsigned i = 0; i < vals.size(); ++i) {
        for (unsigned j = i + 1; j < vals.size(); ++j) {
            if (vals.at(i) > vals.at(j)) {
                T x = vals.at(i);
                vals.at(i) = vals.at(j);
                vals.at(j) = x;
            }
        }
    }
}

template<typename T>
T getElement(vector<T> vals, int index) {
    if (index > int(vals.size()) || index < 0) {
        throw runtime_error("Invalid index.");
    }
    return vals.at(index);
}

int main() {
    
    srand(time(0));
    vector<char> vals = createVector();
    char curChar;
    int index;
    int numOfRuns = 10;
    while(--numOfRuns >= 0) {
        cout << "Enter a number: " << endl;
        cin >> index;
        try {
            getElement(vals, index);
        }
        catch (runtime_error& excpt) {
            cout << excpt.what() << endl;
        }
        curChar = getElement(vals, index);
        cout << "Element located at " << index << ": is " << curChar << endl;
    }
    
    return 0;
}