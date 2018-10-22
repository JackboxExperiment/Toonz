//Jackie Li
//Project 0: MyTunez
//Systems pd05
//2018-10-19

#ifndef CLLIST_H
#define CLLIST_H

struct song_node {
  char name[100];
  char artist[100];
  struct song_node * next;
};

void print_list(struct song_node *);

void print_song(struct song_node *);

int cmp_lower(char *, char *);

int compare_songs(char *, char *, char *, char *);

int length(struct song_node *);

struct song_node * insert_front(struct song_node *, char *, char *);

struct song_node * insert_alpha(struct song_node *, char[], char[]);

struct song_node * free_list(struct song_node *);

struct song_node * find_song(struct song_node *, char *, char *);

struct song_node * find_song_artist(struct song_node *, char *);

struct song_node * rand_song(struct song_node *);

struct song_node * remove_node(struct song_node *, char[], char[]);

struct song_node * remove_node_help(struct song_node *, char[], char[], struct song_node *);

#endif
