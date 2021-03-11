#include "HashTable.h"
#include "WordEntry.h"

#include <list>
#include <string>
using namespace std;

/* HashTable constructor
*  input s is the size of the array
*  set s to be size
*  initialize array of lists of WordEntry
*/
HashTable::HashTable(int s) {
	size = s;
	hashTable = new list<WordEntry>[s];
}


/* computeHash
*  return an integer based on the input string
*  used for index into the array in hash table
*  be sure to use the size of the array to 
*  ensure array index doesn't go out of bounds
*/
int HashTable::computeHash(const string &s) {
	char first = s[0];
	int hash = int(first);
	int bucket = hash % size;
	return bucket;
}


/* put
*  input: string word and int score to be inserted
*  First, look to see if word already exists in hash table
*   if so, addNewAppearence with the score to the WordEntry
*   if not, create a new Entry and push it on the list at the
*   appropriate array index
*/
void HashTable::put(const string &s, int score) {
	int hash = computeHash(s);
	if (contains(s)) {
		list<WordEntry>::iterator it;
		for (it = hashTable[hash].begin(); it != hashTable[hash].end(); ++it) {
			if (s == it->getWord()) {
	    		it->addNewAppearance(score);
			}
		}
	}
	else {
	    WordEntry entry(s, score);
	    hashTable[hash].push_back(entry);
	}
}

/* getAverage
*  input: string word 
*  output: the result of a call to getAverage()
*          from the WordEntry
*  Must first find the WordEntry in the hash table
*  then return the average
*  If not found, return the value 2.0 (neutral result)
*/

double HashTable::getAverage(const string &s) {
	double avg = 2.0;
	int hash = computeHash(s);
	list<WordEntry>::iterator it;
	for (it = hashTable[hash].begin(); it != hashTable[hash].end(); ++it) {
		if (s == it->getWord()) {
			avg = it->getAverage();
			return avg;
		}
	}
	return avg;
}

/* contains
* input: string word
* output: true if word is in the hash table
*         false if word is not in the hash table
*/
bool HashTable::contains(const string &s) {
    list<WordEntry>::iterator it;
    int hash = computeHash(s);
    for (it = hashTable[hash].begin(); it != hashTable[hash].end(); ++it) {
    	if (s == it->getWord()) {
    		return true;
    	}
    }
    return false;
}