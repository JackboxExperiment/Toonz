//Jackie Li
//Project 0: MyTunez
//Systems pd05
//2018-10-19

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cllist.h"

void print_list(struct song_node * list) {
  struct song_node * curr = list;
  while (list) { //while current node is not NULL
    printf("|%s by %s| \n", list->name, list->artist);
    printf("===========================\n");
    list = list->next;
  }
}

void print_song(struct song_node * list) {
  if(list) {
    printf("%s by %s\n", list->name, list->artist);
  }
  else {
    printf("Nothing\n");
  }
}

int length(struct song_node * song) {
  int len = 0;
  while (song) {
    song = song->next;
    len++;
  }
  return len;
}

struct song_node * insert_front(struct song_node * song, char * name, char * artist) {
  struct song_node * new = malloc( sizeof( struct song_node ) ); //allocate a temp node

  //assign each value of node
  strcpy(new->name, name);
  strcpy(new->artist, artist);
  new->next = song;

  return new;
}

struct song_node * free_list(struct song_node * list) {
  //as long as not NULL
  while (list) {
    struct song_node * curr = list->next;
    free(list);

    list = curr;
  }

  return NULL;
}

int cmp_lower(char * f, char * s) {
  while( *f && *s && tolower(*f) == tolower(*s)) {
    f++;
    s++;
  }
  return tolower(*f) - tolower(*s);
}
int compare_songs(char * name1, char * artist1, char * name2, char * artist2) {
  if (cmp_lower(artist1, artist2) < 0) {
    return 1;
  }
  else if (cmp_lower(artist1, artist2) > 0) {
    return -1;
  }
  else {
    return -1 * cmp_lower(name1, name2);
  }
}

struct song_node * find_song( struct song_node * song, char * name, char * artist) {
  if (!song) {
    return 0;
  }
  while (cmp_lower(name, song->name) != 0 || cmp_lower(artist, song->artist) != 0) {
    song = song->next;
    if (!song) {
      return song;
    }
  }
  return song;
}

struct song_node * find_song_artist(struct song_node * song, char * artist) {
  if (!song) {
    return 0;
  }
  while(cmp_lower(artist, song->artist) != 0) {
    song = song->next;
    if (!song) {
      return song;
    }
  }
  return song;
}

struct song_node * rand_song(struct song_node * song) {
  int num = rand() % length(song);
  int curr = 0;
  while(curr < num) {
    song = song->next;
    curr++;
  }
  return song;
}

//Credit to Jared and Colin for help
struct song_node * remove_node(struct song_node * song, char name[], char artist[]) {
  return remove_node_help(song, name, artist, song);
}
struct song_node * remove_node_help(struct song_node * temp, char name[], char artist[], struct song_node * song) {
  if (! temp) {
    return song;
  }
  if (!temp->next) {
    return song;
  }
  if (!cmp_lower(name, temp->next->name) && !cmp_lower(name, temp->next->name)) {
    struct song_node * hold = temp->next;
    temp->next = temp->next->next;
    free(hold);
    return song;
  }
  return remove_node_help(temp->next, name, artist, song);
}


struct song_node * insert_alpha(struct song_node * song, char name[100], char artist[100]) {
  if (!song || compare_songs(name, artist, song->name, song->artist) > 0) {
    return insert_front(song, name, artist);
  }
  else {
    struct song_node * temp = song;
    while (song->next != 0 && compare_songs(name, artist, song->next->name, song->next->artist) < 0) {
      song = song->next;
    }
    song->next = insert_front(song->next, name, artist);
    return temp;
  }
}

