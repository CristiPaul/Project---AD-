#include <stdio.h>
#include "topological_sort.h"

void topological_sorting(list* adjacent_list, degree* degree_array, int vertices){
    int i, j, k, u;
    int index;
    int ordered[vertices];
    int keep_zeros[vertices];
    int counter = 0;
    list* pt_list;
    pt_list = (list*)malloc(sizeof(list));

    if(!pt_list){

        puts("Allocation error in memory.");
        exit(0);
    }

    for(i = 0; i < vertices; i++){

        degree_array[i].id = adjacent_list[i].key;
    }

    for(u = 0; u < vertices; u++){

        keep_zeros[u] = 0;
    }


    for(i = 0; i < vertices; i++){

        pt_list = &adjacent_list[i];
        pt_list = pt_list->next;

        while(pt_list != NULL){

            index = pt_list->key;

            for(j = 0; j < vertices; j++){

                if(degree_array[j].id == index){
                    degree_array[j].entry = degree_array[j].entry + 1;
                }
            }
            pt_list = pt_list->next;
        }
    }

    index = 0;


    for(i = 0; i < vertices; i++){
        ordered[i] = (int)NULL;
    }

    while(counter < vertices){

        for(i = 0; i < vertices; i++){
            if(degree_array[i].entry == 0){
                degree_array[i].entry = -1;
                counter = counter + 1;
                keep_zeros[index] = degree_array[i].id;
                index++;
                for(j = 0; j < vertices; j++){
                    if(ordered[j] == 0){
                        ordered[j] = degree_array[i].id;
                        break;
                    }
                }
            }
        }

        for(i = 0; i < vertices; i++){
        if(keep_zeros[i] != 0){
            for(j = 0; j < vertices; j++){
            if(adjacent_list[j].key == keep_zeros[i]){
                pt_list = &adjacent_list[j];
                pt_list = pt_list->next;
                while(pt_list != NULL){
                for(k = 0; k < vertices; k++){
                    if (degree_array[k].id == pt_list->key){
                    degree_array[k].entry = degree_array[k].entry - 1;
                    }
                }
                pt_list = pt_list->next;
                }
            }
            }
        }
        }

        for(i = 0; i < vertices; i++){
        keep_zeros[i] = 0;
        }
    }

    puts("");
    for(i = 0; i < vertices; i++){
        printf("%d ", ordered[i]);
    }

    }
