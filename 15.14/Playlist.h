#ifndef PLAYLIST_H
#define PLAYLIST_H

class PlaylistNode {
    public:
        PlaylistNode();
        PlaylistNode(string uniqueID, string songName, string artistName, int songLength);
        void InsertAfter(PlaylistNode* newNode);
        void SetNext(PlaylistNode* newNode);
        string GetID();
        string GetSongName();
        string GetArtistName();
        int GetSongLength();
        PlaylistNode* GetNext();
        void PrintPlaylistNode();
    
    private:
        string uniqueID;
        string songName;
        string artistName;
        int songLength;
        PlaylistNode* nextNodePtr;
    
};

#endif