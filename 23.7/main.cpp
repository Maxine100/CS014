#include "Jug.h"

#include <iostream>

using namespace std;

int main() {
    
    string solution = "";
    Jug round1(3, 5, 4, 1, 2, 3, 4, 5, 6);
    if (round1.solve(solution) != 1) {
        cout << "Error 3" << endl;
    }
    cout << solution << endl << endl;
    
    Jug round2( 3, 5, 4, 1, 1, 1, 1, 1, 2);
    if (round2.solve(solution) != 1) {
        cout << "Error 3" << endl;
    }
    cout << solution << endl << endl;
    
    return 0;
}