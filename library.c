//Jackie Li
//Project 0: MyTunez
//Systems pd05
//2018-10-19

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "cllist.h"
#include "library.h"

int table_index(char c) {
  if (isalpha(c)) {
    return (int) c - 'A';
  }
  return 26;
}

struct library * add_song(struct library * lib, char * name, char * artist) {
  int i = table_index(*artist);
  lib->table[i] = insert_alpha(lib->table[i], name, artist);
  lib->size++;
  return lib;
}

void remove_song(struct library * lib, char * name, char * artist) {
  int i = table_index(*artist);
  lib->table[i] = remove_node(lib->table[i], name, artist);
  lib->size--;
}

struct song_node * get_song(struct library * lib, char * name, char * artist) {
  int i = table_index(artist[0]);
    struct song_node * temp = find_song(lib->table[i], name, artist);
  return temp;
}

struct song_node * get_song_artist(struct library * lib, char * artist) {
  int i = table_index(artist[0]);
    struct song_node * temp = find_song_artist(lib->table[i], artist);
  return temp;
}

struct song_node * random_song(struct library *lib) {
  int i = rand() % lib->size;
  for (int x = 0; x < 27; x++) {
    for(struct song_node * song = lib->table[x]; song; song = song->next) {
      if (!i--) {
	return song;
      }
    }
  }
  return 0;
}

void shuffle(struct library * lib, int i) {
  while(i--) {
    print_song(random_song(lib));
  }
}

void print_lib(struct library * lib) {
  if (lib) {
    for (int i = 0; i < 27; i++) {
      print_list(lib->table[i]);
    }
  }
}

void print_artist(struct library * lib, char * artist) {
  int i = table_index(artist[0]);
  struct song_node * temp = lib->table[i];
  while (temp) {
    if (!strcmp(artist, temp->artist)) {
      print_song(temp);
      temp = temp->next;
    }
    else {
      break;
    }
  }
}

void print_letter(struct library * lib, char c) {
  int i = table_index(c);
  if (lib -> table[i]) {
    print_list(lib->table[i]);
    printf("\n");
  }
  else {
    printf("No artists found at %c\n", c);
  }
}

void free_library(struct library * lib[27]) {
  for (int i = 0; i < 27; i++) {
    free_list(lib[i]);
    lib[i] = NULL;
  }
}
