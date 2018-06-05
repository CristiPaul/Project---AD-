typedef struct _list{

  int key;
  struct _list* next;

}list;

typedef struct _degree{

  int id;
  int entry;

}degree;

void topological_sorting(list* adjacent_list, degree* degree_array, int vertices);
