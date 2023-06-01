//
// Created by wallj on 12/1/2020.
//

#ifndef MAIN_LAB_8__PLAYLISTS_PLAYLIST_H
#define MAIN_LAB_8__PLAYLISTS_PLAYLIST_H
#include "Song.h"
#include <string>
#include <vector>

class Playlist {
   private:
   std::string name = "not initialized";
   std::vector<Song*> songs;
   public:
   Playlist(std::string newName);
   std::string GetName();
   void AddSong(Song* song);
   void RemoveSong(int songIndex);
   void RemoveSong(Song* song);
   void ListSongs();
   void Play();
};


#endif //MAIN_LAB_8__PLAYLISTS_PLAYLIST_H
