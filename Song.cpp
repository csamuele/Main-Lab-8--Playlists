//
// Created by wallj on 12/1/2020.
//

#include "Song.h"
#include <string>
#include <iostream>
Song::Song(std::string newName, std::string newFirstLine) {
   name = newName;
   firstLine = newFirstLine;
}

std::string Song::ToString() {

   return name + ": \"" + firstLine + "\", " + std::to_string(timesPlayed) + " play(s).";
}

void Song::Play() {
   std::cout << firstLine << std::endl;
   timesPlayed++;
}

std::string Song::GetName() {
   return name;
}

void Song::AddPlaylist(Playlist *playlist) {
   playlists.push_back(playlist);
}

std::vector<Playlist *> Song::GetPlaylists() {
   return playlists;
}

void Song::RemovePlaylist(Playlist *playlist) {
   for (unsigned int i = 0; i < playlists.size(); i++) {
      if(playlists.at(i) == playlist) {
         playlists.erase(playlists.begin() + i);
      }
   }
}





