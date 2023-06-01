//A Note regarding 'using namespace std':
// The author of this code prefers to not have the line 'using namespace std;'
// Instead, you will see 'std::' in front of string, cout, and other identifiers
// You could put 'using namespace std;' at the top of your code and not need 'std::' in front of these words,
// but many people consider it better practice to not have 'using namespace std;'


#include <iostream>
#include <string>
#include <vector>


//TODO: Include your class files here
#include "Song.h"
#include "Playlist.h"

// TODO: clean up memory when it is no longer used
//  (you need to find the appropriate places in the code to do this)

std::string GetUserString(const std::string& prompt);

void AddSongsMenuOption(std::vector<Song*>& songs);
void ListSongsMenuOption(std::vector<Song *> songs);
void AddPlaylistMenuOption(std::vector<Playlist *>& playlists);
void AddSongToPlaylistMenuOption(std::vector<Playlist *> playlists, std::vector<Song *> songs);
void ListPlaylistsMenuOption(std::vector<Playlist *> playlists);
void PlayPlaylistMenuOption(std::vector<Playlist *> playlists);
void RemovePlaylistMenuOption(std::vector<Playlist *>& playlists);
void RemoveSongFromPlaylistMenuOption(std::vector<Playlist *> playlists);
void RemoveSongFromLibraryMenuOption(std::vector<Song *>& songs);
void OptionsMenuOption(/*TODO: list any parameters here*/);
void QuitMenuOption(std::vector<Song *>& songs, std::vector<Playlist *>& playlists);
void ListSongs(std::vector<Song*> songs);

int main() {
   std::cout << "Welcome to the Firstline Player!  Enter options to see menu options." << std::endl << std::endl;

   //TODO: Create vectors to hold the songs and playlists
   std::vector<Song*> AllSongs;
   std::vector<Playlist *> AllPlaylists;
   std::string userMenuChoice = "none";
   bool continueMenuLoop = true;

   while (continueMenuLoop) {
      userMenuChoice = GetUserString("Enter your selection now: ");

      if (userMenuChoice == "add") {
         AddSongsMenuOption(AllSongs);
      }
      else if (userMenuChoice == "list") {
         ListSongsMenuOption(AllSongs);
      }
      else if (userMenuChoice == "addp") {
         AddPlaylistMenuOption(AllPlaylists);
      }
      else if (userMenuChoice == "addsp") {
         AddSongToPlaylistMenuOption(AllPlaylists, AllSongs);
      }
      else if (userMenuChoice == "listp") {
         ListPlaylistsMenuOption(AllPlaylists);
      }
      else if (userMenuChoice == "play") {
         PlayPlaylistMenuOption(AllPlaylists);
      }
      else if (userMenuChoice == "remp") {
         RemovePlaylistMenuOption(AllPlaylists);
      }
      else if (userMenuChoice == "remsp") {
         RemoveSongFromPlaylistMenuOption(AllPlaylists);
      }
      else if (userMenuChoice == "remsl") {
         RemoveSongFromLibraryMenuOption(AllSongs);
      }
      else if (userMenuChoice == "options") {
         OptionsMenuOption(/*TODO: list any arguments here*/);
      }
      else if (userMenuChoice == "quit") {
         QuitMenuOption(AllSongs, AllPlaylists);
         continueMenuLoop = false;
      }
      else {
         OptionsMenuOption(/*TODO: list any arguments here*/);
      }
   }

   return 0;
}


std::string GetUserString(const std::string& prompt) {
   std::string userAnswer = "none";

   std::cout << prompt;
   std::getline(std::cin, userAnswer);
   std::cout << std::endl;
   return userAnswer;
}
int GetUserInt(const std::string& prompt) {
   int userAnswer = 0;

   std::cout << prompt;
   std::cin >> userAnswer;
   std::cin.ignore();
   std::cout << std::endl;
   return userAnswer;
}

void AddSongsMenuOption(std::vector<Song*>& songs) {
   const std::string DONE_KEYWORD = "DONE";
   std::cout << "Enter songs' names and first lines"
             << " (type \"" << DONE_KEYWORD << "\" when done):" << std::endl;

   std::string songName = "none";
   std::string firstLine = "none";

   songName = GetUserString("Song Name: ");
   while (songName != DONE_KEYWORD) {
      firstLine = GetUserString("Song's first line: ");

      //TODO: Create a Song using `songName` and `firstLine` and add it to allSongs,
      // .
      // This should be just 1-2 lines of code to create the song and add it to the list
      Song* newSong = new Song(songName, firstLine);
      songs.push_back(newSong);
      songName = GetUserString("Song Name: ");
   }
}

void ListSongsMenuOption(std::vector<Song *> songs) {
   for (unsigned int i = 0;  i < songs.size(); i++) {
      Song* iteratorSong = songs.at(i);
      std::cout << iteratorSong->ToString() << std::endl;
   }
}

void AddPlaylistMenuOption(std::vector<Playlist *>& playlists) {
   std::string playlistName = GetUserString("Playlist name: ");
   Playlist* newPlaylist = new Playlist(playlistName);
   playlists.push_back(newPlaylist);
}

void AddSongToPlaylistMenuOption(std::vector<Playlist *> playlists, std::vector<Song *> songs) {
   ListPlaylistsMenuOption(playlists);
   int playlistIndex = GetUserInt("Pick a playlist index number: ");
   ListSongs(songs);
   int songIndex = GetUserInt("Pick a song index number: ");
   playlists.at(playlistIndex)->AddSong(songs.at(songIndex));
}

void ListPlaylistsMenuOption(std::vector<Playlist *> playlists) {
   for (unsigned int i = 0; i < playlists.size(); i++) {
      std::cout << "  " << i << ": " << playlists.at(i)->GetName() << std::endl;
   }
}

void PlayPlaylistMenuOption(std::vector<Playlist *> playlists) {
   ListPlaylistsMenuOption(playlists);
   int playlistIndex = GetUserInt("Pick a playlist index number: ");
   playlists.at(playlistIndex)->Play();
}

void RemovePlaylistMenuOption(std::vector<Playlist *>& playlists) {
   ListPlaylistsMenuOption(playlists);
   int playlistIndex = GetUserInt("Pick a playlist index number to remove: ");
   delete playlists.at(playlistIndex);
   playlists.erase(playlists.begin() + playlistIndex);
}

void RemoveSongFromPlaylistMenuOption(std::vector<Playlist *> playlists) {
   ListPlaylistsMenuOption(playlists);
   int playlistIndex = GetUserInt("Pick a playlist index number: ");
   playlists.at(playlistIndex)->ListSongs();
   int songIndex = GetUserInt("Pick a song index number to remove: ");
   playlists.at(playlistIndex)->RemoveSong(songIndex);
}

void RemoveSongFromLibraryMenuOption(std::vector<Song *>& songs) {
   ListSongs(songs);
   int songIndex = GetUserInt("Pick a song index number to remove: ");
   std::vector<Playlist*> playlists = songs.at(songIndex)->GetPlaylists();
   for (unsigned int i = 0; i < playlists.size(); i ++) {
      playlists.at(i)->RemoveSong(songs.at(songIndex));
   }
   delete songs.at(songIndex); //For clearing the memory allocated for songs
   songs.erase(songs.begin()+songIndex);

}

void OptionsMenuOption(/*TODO: list any parameters here*/) {
   std::cout << "add      Adds a list of songs to the library" << std::endl
             << "list     Lists all the songs in the library" << std::endl
             << "addp     Adds a new playlist" << std::endl
             << "addsp    Adds a song to a playlist" << std::endl
             << "listp    Lists all the playlists" << std::endl
             << "play     Plays a playlist" << std::endl
             << "remp     Removes a playlist" << std::endl
             << "remsp    Removes a song from a playlist" << std::endl
             << "remsl    Removes a song from the library (and all playlists)" << std::endl
             << "options  Prints this options menu" << std::endl
             << "quit     Quits the program" << std::endl << std::endl;
}

void QuitMenuOption(std::vector<Song *> &songs, std::vector<Playlist *> &playlists) {
   unsigned int i;
   for (i = 0; i < songs.size(); i++) {
      delete songs.at(i); //For clearing the memory allocated for songs
   }
   for (i = 0; i < playlists.size(); i++) {
      delete playlists.at(i); //For clearing the memory allocated for playlists
   }

   songs.clear();
   playlists.clear();
   std::cout << "Goodbye!" << std::endl;
}

void ListSongs(std::vector<Song *> songs) {
   for (unsigned int i = 0;  i < songs.size(); i++) {
      std::cout << "  " << i << ": " << songs.at(i)->GetName() << std::endl;
   }
}

