//
// Created by wallj on 12/1/2020.
//

#ifndef MAIN_LAB_8__PLAYLISTS_SONG_H
#define MAIN_LAB_8__PLAYLISTS_SONG_H
#include <string>
#include <vector>
class Playlist;
class Song {
   private:
      std::string name = "not initialized";
      std::string firstLine = "not initialized";
      int timesPlayed = 0;
      std::vector<Playlist*> playlists;
   public:
      Song(std::string newName, std::string newFirstLine);
      std::string ToString();
      void Play();
      std::string GetName();
      std::vector<Playlist*> GetPlaylists();
      void AddPlaylist(Playlist* playlist);
      void RemovePlaylist(Playlist* playlist);
};


#endif //MAIN_LAB_8__PLAYLISTS_SONG_H
