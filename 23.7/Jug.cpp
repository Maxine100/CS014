#include "Jug.h"

#include <string>
#include <sstream>
#include <iostream>
#include <list>

using namespace std;

Jug::Jug(int Ca, int Cb, int N, int cfA, int cfB, int ceA, int ceB, int cpAB, int cpBA) {
    this->Ca = Ca;
    this->Cb = Cb;
    this->N = N;
    this->cfA = cfA;
    this->cfB = cfB;
    this->ceA = ceA;
    this->ceB = ceB;
    this->cpAB = cpAB;
    this->cpBA = cpBA;
    
}

int Jug::solve(string &solution) {
    
    ostringstream fullSolution;
    
    if (allPositive(Ca, Cb, N, cfA, cfB, ceA, ceB, cpAB, cpBA) && Ca > 0 && Cb >= Ca && Cb >= N && Cb <= 1000) {
        // int totalCost = 0;
        
        // int jugA = 0;
        // int jugB = 0;
        
        for (int i = 0; i < Ca; ++i) {
            for (int j = 0; j < Cb; ++j) {
                pair<int, int> pairP;
                pairP = make_pair(i, j);
                possiblities.push_back(pairP);
            }
        }
        
        list<pair<int, int> >::iterator it;
        for (it = possiblities.begin(); it != possiblities.end(); ++it) {
            
        }
        
        return 1;
    }
    else {
        solution = "";
        return -1;
    }
}

bool Jug::allPositive(int capA, int capB, int goal, int costFillA, int costFillB, int costEmptyA, int costEmptyB, int costPourAtoB, int costPourBtoA) {
    
    if (capA >= 0 && capB >= 0 && goal >=0 && costFillA >= 0 && costFillB >= 0 && costEmptyA >= 0 && costEmptyB >= 0 && costPourAtoB >= 0 && costPourBtoA>= 0) {
        return true;
    }
    return false;
}