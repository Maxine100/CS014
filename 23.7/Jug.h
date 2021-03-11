#ifndef JUG_H
#define JUG_H

#include <string>
#include <list>

class Jug {
    public:
        Jug(int,int,int,int,int,int,int,int,int);
        // ~Jug();

        //solve is used to check input and find the solution if one exists
        //returns -1 if invalid inputs. solution set to empty string.
        //returns 0 if inputs are valid but a solution does not exist. solution set to empty string.
        //returns 1 if solution is found and stores solution steps in solution string.
        int solve(std::string &solution);
        
        bool allPositive(int, int, int, int, int, int, int, int, int);
    private:
        //anything else you need
        int Ca;
        int Cb;
        int N;
        int cfA;
        int cfB;
        int ceA;
        int ceB;
        int cpAB;
        int cpBA;
        std::list<std::pair<int, int> > possiblities;
        
};
#endif