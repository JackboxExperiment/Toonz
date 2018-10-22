//Jackie Li
//Project 0: MyTunez
//Systems pd05
//2018-10-19

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cllist.h"
#include "library.h"

int main() {
  srand(time(NULL));

  printf("===============Testing linked list==============\n");

  struct song_node * songs = 0;
  songs = insert_front(songs, "Yellow Submarine", "Beetles");
  songs = insert_alpha(songs, "Billie Jean", "Michael Jackson");
  songs = insert_alpha(songs, "Shakedown", "The Score");
  songs = insert_alpha(songs, "Smells Like Teen Spirit", "Nirvana");
  print_list(songs);

  printf("\n=============Testing Find Song=============\n");
  printf("Searching for Billie Jean by Michael Jackson:\n");
  print_song(find_song(songs, "Billie Jean", "Michael Jackson"));
  printf("\nSearching for Country Roads by John Denver: (Not in list)\n");
  print_song(find_song(songs, "Country Roads", "John Denver"));

  printf("\n===========Testing Find Song by Artist===========\n");
  printf("Finding Michael Jackson:\n");
  print_song(find_song_artist(songs, "Michael Jackson"));
  printf("\nFinding Nirvana:\n");
  print_song(find_song_artist(songs, "Nirvana"));
  printf("\nFinding Luis Fonzi: (Not in list)\n");
  print_song(find_song_artist(songs, "Luis Fonzi"));

  printf("\n==================Testing Random song==================\n");
  print_song(rand_song(songs));
  print_song(rand_song(songs));
  print_song(rand_song(songs));
  print_song(rand_song(songs));
  print_song(rand_song(songs));
  print_song(rand_song(songs));

  printf("\n=================Removing Songs===================\n");
  printf("\nRemoving Billie Jean by Michael Jackson\n");
  songs = remove_node(songs, "Billie Jean", "Michael Jackson");
  printf("\nRemoving Smells Like Teen Spirit by Nirvana\n");
  songs = remove_node(songs, "Smells Like Teen Spirit", "Nirvana");
  printf("\nRemoving Country Roads by John Denver (Not in list)\n");
  songs = remove_node(songs, "Country Roads", "John Denver");
  printf("\nThe song list is now: \n");
  print_list(songs);

  printf("\n===============Freeing List===================\n");
  songs = free_list(songs);
  printf("Songs are now: \n");
  print_list(songs);

  printf("\n===============Testing Library==============\n");
  struct library *lib = calloc(1, sizeof(struct library));  

  add_song(lib, "Billie Jean", "Michael Jackson");
  add_song(lib, "Shakedown", "The Score");
  add_song(lib, "Thriller", "Michael Jackson");
  add_song(lib, "Smells Like Teen Spirit", "Nirvana");
  add_song(lib, "Purple Rain", "Prince");
  add_song(lib, "DNA", "Kendrick Lamar");
  add_song(lib, "Uptown Funk", "Bruno Mars");
  add_song(lib, "Despacito", "Luis Fonzi");
  print_lib(lib);

  printf("\n===============Testing Adding Songs==============\n");
  add_song(lib, "Beat It", "Michael Jackson");
  add_song(lib, "Human", "Rag'n'Bone Man");
  print_lib(lib);

  printf("\n===============Testing Library Search==============\n");
  printf("Searching for Billie Jean by Michael Jackson\n");
  print_song(get_song(lib, "Billie Jean", "Michael Jackson"));
  printf("Searching for Thunderstruck by ACDC (Not in library)\n");
  print_song(get_song(lib, "Thunderstruck", "ACDC"));

  printf("\nSearching for Michael Jackson\n");
  print_song(get_song_artist(lib, "Michael Jackson"));
  printf("\nSearching for Bach (not in list) \n");
  print_song(get_song_artist(lib, "Bach"));

  printf("\n===============Testing Prints==============\n");
  printf("Printing songs from artists starting with J\n");
  print_letter(lib, 'J');
  printf("Printing songs from artists starting with X\n");
  print_letter(lib, 'X');

  printf("Printing songs from Michael Jackson\n");
  print_artist(lib, "Michael Jackson");
  printf("Printing songs from ACDC\n");
  print_artist(lib, "ACDC");

  printf("\n===============Testing Shuffle==============\n");
  shuffle(lib, 4);
  shuffle(lib, 2);

  printf("\n===============Testing Delete==============\n");
  printf("Removing Thriller by Michael Jackson\n");
  remove_song(lib, "Thriller", "Michael Jackson");
  printf("Removing Thunderstruck by ACDC (Not in list)\n");
  remove_song(lib, "Thunderstruck", "ACDC");
  print_lib(lib);

  printf("\n===============Testing Free==============\n");
  free_library(lib);
  printf("Freed library: \n");
  print_lib(lib);

  return 0;
}
