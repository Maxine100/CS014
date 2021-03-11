#include "WordLadder.h"

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <stdexcept>
#include <stack>
#include <queue>

using namespace std;

WordLadder::WordLadder(const string& filename) {
    ifstream inFS;
    string word;
    
    inFS.open(filename.c_str());
    
    try {
        while (!inFS.eof()) {
            inFS >> word;
            if (word.size() != 5) {
                throw runtime_error("Word must have exactly 5 characters.");
            }
            else {
                dict.push_back(word);
            }
        }
    }
    
    catch(runtime_error& excpt) {
        cout << excpt.what() << endl;
    }
}

void WordLadder::outputLadder(const string& start, const string& end, const string& outputFile) {
    
    try {
        bool isInList = false;
        list<string>::iterator it;
        for (it = dict.begin(); it != dict.end(); ++it) {
            if (start == *it) {
                isInList = true;
            }
        }
        if (!isInList) {
            throw runtime_error("Words not in dict.");
        }
        isInList = false;
        for (it = dict.begin(); it != dict.end(); ++it) {
            if (end == *it) {
                isInList = true;
            }
        }
        if (!isInList) {
            throw runtime_error("Words not in dict.");
        }
        
        queue<stack<string> > stackQueue;
        stack<string> stack1;
        stack1.push(start);
        stackQueue.push(stack1);
        
        ofstream outFS;
        stack<string> stack4;
        
        bool hasWordLadder = false;
        
        if (start == end) {
            stackQueue.pop();
            hasWordLadder = true;
            stack4.push(start);
        }
        while (!stackQueue.empty()) {
            stack<string> stack3 = stackQueue.front();
            string startOfLadder = stack3.top();
            for (it = dict.begin(); it != dict.end(); ++it) {
                int numOfMatches = 0;
                string dictWord = *it;
                for (int i = 0; i < 5; ++i) {
                    if (dictWord.at(i) == startOfLadder.at(i)) {
                        ++numOfMatches;
                    }
                }
                
                if (numOfMatches == 4) {
                    stack<string> stack2 = stackQueue.front();
                    stack2.push(dictWord);
                    if (numOfMatches == 4 || numOfMatches == 5) {
                        string rid = *it;
                        --it;
                        dict.remove(rid);
                    }
                    if (dictWord == end) {
                        hasWordLadder = true;
                        while (!stack2.empty()) {
                            stack4.push(stack2.top());
                            stack2.pop();
                        }
                    }
                    else {
                        stackQueue.push(stack2);
                    }
                }
            }
            stackQueue.pop();
        }
        
        if (hasWordLadder) {
            outFS.open(outputFile.c_str());
            string word;
            while (!stack4.empty()) {
                word = stack4.top();
                outFS << word << " ";
                stack4.pop();
            }
        }
        
        else {
            outFS.open(outputFile.c_str());
            outFS << "No Word Ladder Found.";
            cout << "No word ladder found." << endl;
        }
    }
    catch (runtime_error& excpt) {
        cout << excpt.what() << endl;
    }
    
    
}