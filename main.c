#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "libsort.h"



int main()
{
    struct carte *test=malloc(sizeof(struct carte));
    test->next=NULL;
    int no_carti_random=100;
    clock_t start, end;
    double cpu_time_used;
    start=clock();
    for(int i=0; i<no_carti_random; i++)
    {
        push_random_carte_end(test);
    }
    end=clock();
    printf("Generare finalizata cu succes \n");
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Timp de generare: %f secunde \n", cpu_time_used);
    int opt;
    printf("Bun venit! \n");
    printf("\n");
    printf("1. Adaugati o carte la biblioteca \n");
    printf("2. Afisati lista cartilor pentru un anumit autor \n");
    printf("3. Afisati lista autorilor pentru o anumita carte \n");
    printf("4. Afisati toate cartile din biblioteca \n");
    printf("5. Carte rand \n");
    printf("0. Inchideti programul \n");
    printf("\n");
    printf("Tastati numarul corespunzator optiunii dvs:");
    scanf("%d", &opt);
    while(opt!=0)
    {

        if(opt==1)
        {
            start = clock();
            push_carte_end(test);
            end = clock();
        }
        else
        if(opt==2)
        {
            start=clock();
            int n;
            printf("De cate litere ai nevoie? ");
            scanf("%d", &n);
            printf("\n");
            char *nume=malloc(sizeof(char)*n);
            char *prenume=malloc(sizeof(char)*n);
            printf("Ce autor doresti sa cauti in biblioteca? ");
            scanf("%s", nume);
            scanf("%s", prenume);
            book_list(test, nume, prenume);
            end=clock();
        }
        else
        if(opt==3)
        {
            start=clock();
            int n;
            printf("De cate litere ai nevoie? ");
            scanf("%d", &n);
            printf("\n");
            char *title=malloc(sizeof(char)*n);
            printf("Pentru ce carte doresti sa afli autorii? ");
            scanf("%s", title);
            auth_list(test, title);
            end=clock();
        }
        else
        if(opt==4)
        {
            start=clock();
            print_carte(test);
            end=clock();
        }
        else
        if(opt==5)
        {
            start=clock();
            push_random_carte_end(test);
            end=clock();
        }
        if(opt==0)
        {
            printf("La revedere!");
            return 0;
        }

        printf("\n");
        printf("Tastati numarul corespunzator optiunii dvs:");
        scanf("%d", &opt);

    }

    return 0;
}
