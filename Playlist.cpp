//
// Created by wallj on 12/1/2020.
//
#include <iostream>
#include "Playlist.h"

Playlist::Playlist(std::string newName) {
   name = newName;
}

std::string Playlist::GetName() {
   return name;
}

void Playlist::AddSong(Song *song) {
   song->AddPlaylist(this);
   songs.push_back(song);
}

void Playlist::Play() {
   std::cout << "Playing songs from playlist: " << name << std::endl;
   for (unsigned int i = 0; i < songs.size(); i++) {
      songs.at(i)->Play();
   }
}

void Playlist::RemoveSong(int songIndex) {
   songs.at(songIndex)->RemovePlaylist(this);
   songs.erase(songs.begin()+songIndex);
}

void Playlist::ListSongs() {
   for (unsigned int i = 0; i < songs.size(); i++) {
      std::cout << "  " << i << ": " << songs.at(i)->GetName() << std::endl;
   }
}

void Playlist::RemoveSong(Song *song) {
   for (unsigned int i = 0; i < songs.size(); i++) {
      if (songs.at(i) == song){
         RemoveSong(i);
      }
   }

}
