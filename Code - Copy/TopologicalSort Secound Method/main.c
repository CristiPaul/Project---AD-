#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "topological_sort.h"

void init_adjacent_list(list* adjacent_list, int vertices){
    int i;

    for(i = 0; i < vertices; i++){

        adjacent_list[i].key= (int)NULL;
        adjacent_list[i].next = NULL;

    }
}


void init_list(list* lists){

    lists->key= (int)NULL;
    lists->next = NULL;

}

void init_degree(degree* degrees, int vertices){
    int i;

    for(i = 0; i < vertices; i++){

        degrees[i].id = 0;
        degrees[i].entry = 0;

    }
}


void entries_adjacent_list(list* adjacent_list, int vertices){
    char temp[100];
    char* ptr;
    int counter = 0, value;

    while(counter < vertices){

            puts("Insert the vertex and its respective edges, if the vertex has (Data must be typed with spaces).");
            if(counter == 0){

                puts("Examples of how to enter data:");
                puts("Example_1 (vertex 5 has edges 4 and 3): 5 4 3");
                puts("Example_2 (vertex 6 has no edges): 6");
            }


            fgets(temp, 100, stdin);

            if(temp[(int)(strlen(temp)-1)] == '\n'){

                temp[(int)(strlen(temp)-1)]= '\0';

            }

        adjacent_list[counter].key = (int)strtol(temp, &ptr, 10);

            while(strlen(ptr) != 0){

                value  = (int)strtol(ptr, &ptr, 0);
                creat_adjacent_list(adjacent_list, value, counter);

        }

        counter++;
    }
}


void creat_adjacent_list(list* adjacent_list, int value, int index){
    list* new_list;
    list* pt_list;

    new_list = (list*)malloc(sizeof(list));
    pt_list = (list*)malloc(sizeof(list));

    if(!pt_list || !new_list){

        puts("Allocation error in memory.");
        exit(0);
    }

    init_list(new_list);
    new_list->key = value;
    pt_list = &adjacent_list[index];

    if(pt_list->next == NULL)
        pt_list->next = new_list;

    else{
        while(pt_list->next != NULL){
            pt_list = pt_list->next;
        }

        pt_list->next = new_list;
    }
}

int main(int argc, char *argv[])
{

    list* adjacent_list;
    degree* degree_array;
    int vertices, edges;

    puts("Enter the number of vertices and edges.");
  //printf ("Vertices\n");
    scanf("%d %d", &vertices);
  //printf ("Edges\n");
    scanf ("%d", &edges);
    do{} while (getchar() != '\n');

    adjacent_list = (list*)malloc(sizeof(list)*vertices);
    degree_array = (degree*)malloc(sizeof(degree)*vertices);

    if(!adjacent_list || !degree_array){

        puts("Allocation error");
        exit(0);
    }

    init_adjacent_list(adjacent_list, vertices);
    init_degree(degree_array, vertices);
    entries_adjacent_list(adjacent_list, vertices);
    topological_sorting(adjacent_list, degree_array, vertices);

    free(adjacent_list);
    free(degree_array);

    return 0;
}
