#ifndef WORDLADDER_H
#define WORDLADDER_H

#include <string>
#include <list>

class WordLadder {
    private:
        std::list<std::string> dict;

    public:
        WordLadder(const std::string& filename);
        void outputLadder(const std::string& start, const std::string& end, const std::string& outputFile);
};

#endif