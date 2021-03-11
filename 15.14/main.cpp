#include <iostream>

using namespace std;

#include "Playlist.h"

void PrintMenu(string playlistTitle) {
    cout << playlistTitle << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    
    cout << "Choose an option:" << endl;
    char option;
    cin >> option;
    cin.ignore();
    
    PlaylistNode* headSong = 0;
    
    while (option != 'q') {
        if (option == 'a') {
            
            string uID;
            string sName;
            string aName;
            int sLength;
            
            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            getline(cin, uID);
            cout << "Enter song's name:" << endl;
            getline(cin, sName);
            cout << "Enter artist's name:" << endl;
            getline(cin, aName);
            cout << "Enter song's length (in seconds):" << endl;
            cin >> sLength;
            cout << endl;
            
            PlaylistNode* currSong = 0;
            PlaylistNode* newSong = new PlaylistNode(uID, sName, aName, sLength);
            if (headSong == 0) {
                headSong = newSong;
            }
            else {
                currSong = headSong;
                while (currSong->GetNext() != 0) {
                    currSong = currSong->GetNext();
                }
                currSong->InsertAfter(newSong);
            }
            
        }
        else if (option == 'd') {
            string uID;
            cout << "REMOVE SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin >> uID;
            
            PlaylistNode* currSong = headSong;
            
            while (currSong->GetID() != uID) {
                currSong = currSong->GetNext();
            }
            
            cout << "\"" << currSong->GetSongName() << "\" removed." << endl;
            cout << endl;
            
            currSong = headSong;
            if (headSong->GetID() == uID) {
                PlaylistNode* tmp = headSong;
                currSong = 0;
                headSong = headSong->GetNext();
                delete tmp;
            }
            else {
                while (currSong->GetNext() != 0) {
                    if ((currSong->GetNext())->GetID() == uID) {
                        PlaylistNode* tmp = currSong->GetNext();
                        currSong->SetNext((currSong->GetNext())->GetNext());
                        delete tmp;
                    }
                    currSong = currSong->GetNext();
                }
            }
            currSong = headSong;
        }
        else if (option == 'c') {
            PlaylistNode* currSong = headSong;
            int currentPos;
            int newPos;
            cout << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:" << endl;
            cin >> currentPos;
            cout << "Enter new position for song:" << endl;
            cin >> newPos;
            
            for (int i = 1; i < currentPos; ++i) {
                currSong = currSong->GetNext();
            }
            
            PlaylistNode* prevSong = headSong;
            if (currentPos == 1) {
                prevSong = 0;
            }
            else {
                for (int i = 1; i < currentPos - 1; ++i) {
                    prevSong = prevSong->GetNext();
                }
            }
            
            PlaylistNode* nextSong = currSong->GetNext();
            
            PlaylistNode* newSongPos = headSong;
            for (int i = 1; i < newPos; ++i) {
                newSongPos = newSongPos->GetNext();
            }
            
            PlaylistNode* beforeNewPos = headSong;
            for (int i = 1; i < newPos - 1; ++i) {
                beforeNewPos = beforeNewPos->GetNext();
            }
            
            PlaylistNode* afterNewPos = newSongPos->GetNext();
            
            PlaylistNode* newSong = new PlaylistNode(currSong->GetID(), currSong->GetSongName(), currSong->GetArtistName(), currSong->GetSongLength());
            
            if (currentPos > newPos) {
                if (newPos == 1) {
                    newSong->SetNext(headSong);
                    headSong = newSong;
                }
                else {
                    newSong->SetNext(newSongPos);
                    beforeNewPos->InsertAfter(newSong);
                }
                
                PlaylistNode* temp = currSong;
                prevSong->SetNext(nextSong);
                delete temp;
            }
            else {
                newSongPos->SetNext(newSong);
                
                if (afterNewPos == 0) {
                    newSong->SetNext(0);
                }
                else {
                    newSong->SetNext(afterNewPos);
                }
                
                PlaylistNode* temp = currSong;
                if (prevSong == 0) {
                    headSong = currSong->GetNext();
                }
                else {
                    prevSong->SetNext(nextSong);
                }
                delete temp;
            }
            
            cout << "\"" << currSong->GetSongName() << "\" moved to position " << newPos << endl << endl;
        }
        else if (option == 's') {
            string aName;
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:" << endl;
            getline(cin, aName);
            cout << endl;
            
            PlaylistNode* currSong = headSong;
            int num = 1;
            while (currSong != 0) {
                if (currSong->GetArtistName() == aName) {
                    cout << num << "." << endl;
                    currSong->PrintPlaylistNode();
                    cout << endl;
                }
                currSong = currSong->GetNext();
                ++num;
            }
        }
        else if (option == 't') {
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            PlaylistNode* currSong = headSong;
            int totalTime = 0;
            while (currSong != 0) {
                totalTime = totalTime + currSong->GetSongLength();
                currSong = currSong->GetNext();
            }
            cout << "Total time: " << totalTime << " seconds" << endl << endl;
        }
        else if (option == 'o') {
            cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
            PlaylistNode* currSong = headSong;
            if (headSong == 0) {
                cout << "Playlist is empty" << endl << endl;
            }
            else {
                int numSong = 1;
                while (currSong != 0) {
                    cout << numSong << "." << endl;
                    currSong->PrintPlaylistNode();
                    cout << endl;
                    currSong = currSong->GetNext();
                    ++numSong;
                }
            }
        }
        cout << playlistTitle << " PLAYLIST MENU" << endl;
        cout << "a - Add song" << endl;
        cout << "d - Remove song" << endl;
        cout << "c - Change position of song" << endl;
        cout << "s - Output songs by specific artist" << endl;
        cout << "t - Output total time of playlist (in seconds)" << endl;
        cout << "o - Output full playlist" << endl;
        cout << "q - Quit" << endl;
        cout << endl;
        cout << "Choose an option:" << endl;
        cin >> option;
        cin.ignore();
    }
}

int main() {
    
    string playlistTitle;
    
    cout << "Enter playlist's title:" << endl << endl;
    getline(cin, playlistTitle);
    PrintMenu(playlistTitle);
    
    return 0;
}