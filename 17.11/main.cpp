#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>

using namespace std;

#inlcude "WordLadder.cpp"

int main() {

    WordLadder w1("words.txt");
    w1.outputLadder("dream", "sorry", "outc.txt");

    return 0;
}