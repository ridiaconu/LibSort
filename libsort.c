#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libsort.h"


int find_book_in_lib(struct carte *head ,char *titlu){
    int position = -1; //list is empty
    struct carte *iterator = head;
    int element_found = 0;

    while (iterator->next != NULL) {
        position++;
        if (strcmp(iterator->next->titlu, titlu)==0){
            element_found = 1;
            break;
        }
        iterator = iterator->next;
    }

    if (element_found == 1){
        return position;
    }else{
        return -2; // not found in list
    }

}

/*int find_auth_in_lib(struct carte *head, char *nume, char *prenume){
    int position = -1; //list is empty
    struct carte *iterator = head;
    int element_found = 0;

    while (iterator->next != NULL) {
        position++;
        if (strcmp(iterator->next->head->nume, nume)==0){
            if(strcmp(iterator->next->head->prenume, prenume)==0)
            {
                element_found = 1;
                break;
            }
        }
        iterator = iterator->next;
    }



    if (element_found == 1){
        return position;
    }else{
        return -2; // not found in list
    }

}
*/
void push_carte_end(struct carte *head){

    struct carte *new_element = malloc(sizeof(struct carte));
    struct carte *iterator = head;
    struct carte *last_element;

    while (iterator->next != NULL) {
        iterator = iterator->next;
    }
    last_element = iterator;

    int n;
    printf("De cate litere ai nevoie: ");
    scanf("%d", &n);
    printf("\n");
    printf("Introduceti numele cartii:");
    char *book=malloc(sizeof(char)*n);
    scanf("%s", book);
    while (find_book_in_lib(head, book)>=0)
    {
        printf("Carte deja introdusa! Introduceti alta carte! \n");
        printf("Introduceti numele cartii:");
        scanf("%s", book);
    }
    new_element->titlu=malloc(sizeof(char)*strlen(book));
    strcpy(new_element->titlu, book);
    int no_autori;
    printf("Introduceti nr autori:");
    scanf("%d", &no_autori);
    new_element->head=malloc(sizeof(struct author));
    new_element->head->next=NULL;
    for(int i=0; i<no_autori; i++)
    {
        struct author *tmp=malloc(sizeof(struct author));
        tmp->next=NULL;

        char *nume=malloc(sizeof(char)*n);
        char *prenume=malloc(sizeof(char)*n);
        printf("Introduceti nume si prenume autor:");
        scanf("%s", nume);
        scanf("%s", prenume);
        tmp->nume=malloc(sizeof(char)*strlen(nume));
        tmp->prenume=malloc(sizeof(char)*strlen(prenume));
        strcpy(tmp->nume, nume);
        strcpy(tmp->prenume, prenume);
        struct author *cursor=new_element->head;
        for(cursor=new_element->head; cursor->next!=NULL; cursor=cursor->next);
        cursor->next=tmp;
    }

    last_element->next = new_element;
    new_element->next = NULL;
}

void print_carte(struct carte *head){
    struct carte *iterator = head;

    printf("Cartile din biblioteca sunt: \n");
    while (iterator->next != NULL) {
        printf("%s ", iterator->next->titlu);
        printf("de ");
        struct author *cursor = iterator->next->head;
        while(cursor -> next != NULL)
        {
            printf("%s ", cursor->next->nume);
            printf("%s ,", cursor->next->prenume);
            cursor=cursor->next;
        }
        printf("\n");
        iterator = iterator->next;
    }
}

void book_list(struct carte *head, char *nume, char *prenume)
{
    struct carte *iterator = head;
    printf("Cartile din biblioteca scrise de %s %s: \n", nume, prenume);
    while (iterator->next != NULL) {

        struct author *cursor=iterator->next->head;
        while (cursor->next!=NULL)
        {
            if(strcmp(cursor->next->nume, nume)==0)
            {

                if(strcmp(cursor->next->prenume, prenume)==0)
                {
                    printf("%s ", iterator->next->titlu);
                    printf(",");
                }
            }
            cursor=cursor->next;
        }

        ///printf("\n");
        iterator = iterator->next;
    }
}

void auth_list(struct carte *head, char *titlu)
{
    struct carte *iterator = head;
    printf("Cartea %s a fost scrisa de: \n", titlu);
    while(iterator -> next != NULL)
    {
        if(strcmp(iterator->next->titlu, titlu)==0)
        {
        struct author *cursor = iterator->next->head;
        while(cursor -> next != NULL)
        {
            printf("%s ", cursor->next->nume);
            printf("%s ,", cursor->next->prenume);
            cursor = cursor->next;
        }
        }
        iterator = iterator->next;
    }


}

char *randstring(int length) {
    static int mySeed = 25011984;
    char *string = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";
    size_t stringLen = strlen(string);
    char *randomString = NULL;

    srand(time(NULL) * length + ++mySeed);

    if (length < 1) {
        length = 1;
    }

    randomString = malloc(sizeof(char) * (length +1));

    if (randomString) {
        short key = 0;

        for (int n = 0;n < length;n++) {
            key = rand() % stringLen;
            randomString[n] = string[key];
        }

        randomString[length] = '\0';

        return randomString;
    }
    else {
        printf("No memory");
        exit(1);
    }
}

void push_random_carte_end(struct carte *head){

    struct carte *new_element = malloc(sizeof(struct carte));
    struct carte *iterator = head;
    struct carte *last_element;

    while (iterator->next != NULL) {
        iterator = iterator->next;
    }
    last_element = iterator;

    int n=rand()%10+1;
    char *book=malloc(sizeof(char)*n);
    strcpy(book, randstring(n));
    while (find_book_in_lib(head, book)>=0)
    {
        n=rand()%10+1;
        book=malloc(sizeof(char)*n);
        strcpy(book, randstring(n));

    }
    new_element->titlu=malloc(sizeof(char)*strlen(book));
    strcpy(new_element->titlu, book);
    int no_autori=rand()%5+1;
    new_element->head=malloc(sizeof(struct author));
    new_element->head->next=NULL;
    for(int i=0; i<no_autori; i++)
    {
        struct author *tmp=malloc(sizeof(struct author));
        tmp->next=NULL;

        char *nume=malloc(sizeof(char)*n);
        char *prenume=malloc(sizeof(char)*n);
        strcpy(nume, randstring(n));
        strcpy(prenume, randstring(n));
        tmp->nume=malloc(sizeof(char)*strlen(nume));
        tmp->prenume=malloc(sizeof(char)*strlen(prenume));
        strcpy(tmp->nume, nume);
        strcpy(tmp->prenume, prenume);
        struct author *cursor=new_element->head;
        for(cursor=new_element->head; cursor->next!=NULL; cursor=cursor->next);
        cursor->next=tmp;
    }

    last_element->next = new_element;
    new_element->next = NULL;
}
