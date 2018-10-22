//Jackie Li
//Project 0: MyTunez
//Systems pd05
//2018-10-19

#ifndef LIBRARY_H
#define LIBRARY_H

#include "cllist.h"

struct library {
  struct song_node * table[27];
  int size;
};

struct library * add_song(struct library *, char *, char *);

void remove_song(struct library *, char *, char *);

struct song_node * get_song(struct library *, char *, char *);

struct song_node * get_song_artist(struct library *, char *);

struct song_node * random_song(struct library *);

void print_lib(struct library *);

void print_artist(struct library *, char *);

void print_letter(struct library *, char);

void shuffle(struct library *, int);

void free_library(struct library * table[]);

int table_index(char);

#endif
