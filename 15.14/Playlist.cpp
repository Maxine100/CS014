#include <iostream>

using namespace std;

#include "Playlist.h"

PlaylistNode::PlaylistNode() {
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = 0;
}

PlaylistNode::PlaylistNode(string uniqueID, string songName, string artistName, int songLength) {
    this->uniqueID = uniqueID;
    this->songName = songName;
    this->artistName = artistName;
    this->songLength = songLength;
    nextNodePtr = 0;
}

void PlaylistNode::InsertAfter(PlaylistNode* newNode) {
    PlaylistNode* temp = 0;
    temp = this->nextNodePtr;
    this->nextNodePtr = newNode;
    newNode->nextNodePtr = temp;
}

void PlaylistNode::SetNext(PlaylistNode* newNode) {
    // receive playlist node
    // adding next pointer
    this->nextNodePtr = newNode;
}

string PlaylistNode::GetID() {
    return uniqueID;
}

string PlaylistNode::GetSongName() {
    return songName;
}

string PlaylistNode::GetArtistName() {
    return artistName;
}

int PlaylistNode::GetSongLength() {
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext() {
    return this->nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode() {
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds): " << songLength << endl;
}