#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 30

typedef char String[50];

typedef struct {
    String bookName;
    String authorName;
    String genre;
    String publishingHouse;
    int publishingYear;
    int totalPageNum;
} Book;

typedef struct node {
    Book elem;
    struct node *next;
} BookNode, *BookType;

typedef struct {
    BookType books[10];
} BookShelf;

int Hash(String genre);

void initHash(BookShelf *D);

void insert(BookShelf *D, Book toInsert);

void displayHash(BookShelf D);

int Hash(String genre){

    String genres[10] = {
        "Design",
        "Manga",
        "Fantasy",
        "Romance",
        "Horror",
        "YoungAdult",
        "SciFi",
        "NonFiction",
        "Thriller",
        "Comics"
    };

    for(int i = 0;i < 10;i++){
        if(strcmp(genre,genres[i])==0){
            return i;
        }
    }

        return -1;
}

void initHash(BookShelf *D){

    for(int i = 0;i < MAX;i++){
        D->books[i] = NULL;
    }
}

void insert(BookShelf *D, Book toInsert){

    int index = Hash(toInsert.genre);

    BookType trav = malloc(sizeof(struct node));

    if(trav != NULL){
        trav->elem = toInsert;
        trav->next = D->books[index];
        D->books[index] = trav;
    }
}

void displayHash(BookShelf D){

    int i;
    BookType trav;

    String genres[10] = {
        "Design",
        "Manga",
        "Fantasy",
        "Romance",
        "Horror",
        "YoungAdult",
        "SciFi",
        "NonFiction",
        "Thriller",
        "Comics"
    };

    printf("\n========== BOOK HASH TABLE ==========\n");

    for (i = 0; i < 10; i++) {

        printf("\n[%d] %s\n", i, genres[i]);

        trav = D.books[i];

        if (trav == NULL) {
            printf("    NULL");
        }

        while (trav != NULL) {

            printf("    -> %s\n", trav->elem.bookName);

            trav = trav->next;
        }

        printf("\n");
    }
}

int main(void) {

    BookShelf shelf;

    Book books[15] = {

        {
            "The Design of Everyday Things",
            "Don Norman",
            "Design",
            "Basic Books",
            2013,
            368
        },

        {
            "One Piece",
            "Eiichiro Oda",
            "Manga",
            "Shueisha",
            1997,
            200
        },

        {
            "The Hobbit",
            "J.R.R. Tolkien",
            "Fantasy",
            "George Allen",
            1937,
            310
        },

        {
            "The Name of the Wind",
            "Patrick Rothfuss",
            "Fantasy",
            "DAW Books",
            2007,
            662
        },

        {
            "Pride and Prejudice",
            "Jane Austen",
            "Romance",
            "T. Egerton",
            1813,
            432
        },

        {
            "The Shining",
            "Stephen King",
            "Horror",
            "Doubleday",
            1977,
            447
        },

        {
            "It",
            "Stephen King",
            "Horror",
            "Viking Press",
            1986,
            1138
        },

        {
            "The Hunger Games",
            "Suzanne Collins",
            "YoungAdult",
            "Scholastic",
            2008,
            374
        },

        {
            "Dune",
            "Frank Herbert",
            "SciFi",
            "Chilton Books",
            1965,
            412
        },

        {
            "Ender's Game",
            "Orson Scott Card",
            "SciFi",
            "Tor Books",
            1985,
            324
        },

        {
            "Sapiens",
            "Yuval Noah Harari",
            "NonFiction",
            "Harper",
            2015,
            443
        },

        {
            "Gone Girl",
            "Gillian Flynn",
            "Thriller",
            "Crown Publishing",
            2012,
            419
        },

        {
            "The Silent Patient",
            "Alex Michaelides",
            "Thriller",
            "Celadon Books",
            2019,
            336
        },

        {
            "The Girl with the Dragon Tattoo",
            "Stieg Larsson",
            "Thriller",
            "Norstedts",
            2005,
            465
        },

        {
            "Batman: Year One",
            "Frank Miller",
            "Comics",
            "DC Comics",
            1987,
            144
        }
    };


    /* Initialize hash table */
    initHash(&shelf);


    /* Insert all 15 books */
    for (int i = 0; i < 15; i++) {
        insert(&shelf, books[i]);
    }


    /* Display the resulting hash table */
    displayHash(shelf);


    return 0;
}
