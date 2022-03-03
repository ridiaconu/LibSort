#ifndef LIBSORT_H_INCLUDED
#define LIBSORT_H_INCLUDED

struct author{

    char *nume;
    char *prenume;
    struct author *next;

};



struct carte {
    char *titlu;
    struct author *head;
    struct carte *next;

};

int find_book_in_lib(struct carte *head ,char *titlu);
int find_auth_in_lib(struct author *head, char *nume, char *prenume);
void push_carte_end(struct carte *head);
void print_carte(struct carte *head);

#endif // LIBSORT_H_INCLUDED
