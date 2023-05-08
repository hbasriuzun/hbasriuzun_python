#include <stdio.h>
#include <stdlib.h>
// ==================== WRITE YOUR OPTIONAL DATA TYPES IF YOU NEED =============

typedef struct COORDINATE
{
    int x;
    int y;
}COORDINATE;


#define COORDINATE_NULL_PTR ((COORDINATE*)0)

#define NULL ((void *)0)
// ====== WRITE YOUR COMPULSORY (BUT SPECIFIC TO THE PROBLEM) DATA TYPES =======

enum ACTIONS // All possible actions
{
	GO_east, GO_west, GO_northeast, GO_northwest, GO_southeast, GO_southwest
};

typedef struct State  
{
    COORDINATE  coordinate; 
    int Map_Size;                    // update this part
    float h_n;   // Heuristic function
      
}State;

// ================== YOU DO NOT NEED TO CHANGE THIS PART ======================

enum METHODS  // This part must be updated if a new algorithm is added.
{
	BreastFirstSearch = 1,   UniformCostSearch = 2,        DepthFirstSearch = 3,    
	DepthLimitedSearch= 4,   IterativeDeepeningSearch = 5, GreedySearch = 6,
    AStarSearch = 7 
};

// This struct is used to determine a new state in transition model
typedef struct Transition_Model
{
    State new_state;
    float step_cost;
}Transition_Model;

typedef struct Node
{
    State state;
    float path_cost;
    enum ACTIONS action; //The action applied to the parent to generate this node
    struct Node *parent;
    int Number_of_Child; // required for depth-first search algorithms
}Node;

typedef struct Queue  // Used for frontier
{
    Node *node;
    struct Queue *next;
}Queue;

void Print_State(const State *const state, COORDINATE** map)
{ 
	int i,j;
	int map_size = state->Map_Size;
    for ( i = 0; i < map_size + 1; i++){
		for ( j = 0; j < map_size - i ; j++){
			printf("   ");
		}
		
		for ( j = map_size - i; j < map_size * 2 + 1; j++)
		{
			if(map[i][j].x == -1 || map[i][j].y == -1)
				printf("***   ");
			else
				printf("%d,%d   ", map[i][j].x, map[i][j].y);
		}
        printf("\n\n");
	}

	for ( i = map_size + 1; i < map_size *2+ 1; i++){
		for ( j = 0; j < i - map_size; j++){
			printf("   ");
		}
		
		for ( j = 0; j < map_size * 2 - i + map_size + 1; j++)
		{
			if(map[i][j].x == -1 || map[i][j].y == -1)
				printf("***   ");
			else
				printf("%d,%d   ", map[i][j].x, map[i][j].y);
			
		}
        printf("\n\n");
	}

}

void Print_State_with_size(int Map_Size, COORDINATE** map)
{ 
	int i,j;
	int map_size = Map_Size;
    for ( i = 0; i < map_size + 1; i++){
		for ( j = 0; j < map_size - i ; j++){
			printf("   ");
		}
		
		for ( j = map_size - i; j < map_size * 2 + 1; j++)
		{
			if(map[i][j].x == -1 || map[i][j].y == -1)
				printf("***");
			else
				printf("%d,%d   ", map[i][j].x, map[i][j].y);
		}
        printf("\n\n");
	}

	for ( i = map_size + 1; i < map_size *2+ 1; i++){
		for ( j = 0; j < i - map_size; j++){
			printf("   ");
		}
		
		for ( j = 0; j < map_size * 2 - i + map_size + 1; j++)
		{
			if(map[i][j].x == -1 || map[i][j].y == -1)
				printf("***");
			else
				printf("%d,%d   ", map[i][j].x, map[i][j].y);
			
		}
        printf("\n\n");
	}

}

State* Create_State(COORDINATE** map, int map_size)
{
	State *state = (State*)malloc(sizeof(State));
    if(state==NULL)
    	Warning_Memory_Allocation(); 

	state->Map_Size = map_size;
   	
    Print_State(state, map);
            
   
   	do{ 
    	printf("Enter the coordinate of the state x and y: ");
        scanf("%d,%d", &state->coordinate.x, &state->coordinate.y);
   	}while(state->coordinate.x <0 || state->coordinate.y < 0 ||  state->coordinate.x >= 7 || state->coordinate.y >= 7);
	       
    return state;    
}

COORDINATE** Create_Map(int map_size)
{	
	int i,j,k,l;

	COORDINATE **map = (COORDINATE **)malloc((map_size * 2 + 1) * sizeof(COORDINATE *));
	for (i = 0; i < map_size * 2 + 1; i++) {
		map[i] = (COORDINATE *)malloc((map_size * 2 + 1) * sizeof(COORDINATE));
	}

    for ( i = 0; i < map_size + 1; i++){
		for ( j = 0; j < map_size - i ; j++){
			map[i][j].x = -1;
			map[i][j].y = -1;
		}
		
		for ( j = map_size - i; j < map_size * 2 + 1; j++)
		{
			map[i][j].x = j;
			map[i][j].y = i;
		}
	}

	for ( i = map_size + 1,k = map_size * 2 - 1; i < map_size *2+ 1; i++,k--){
		for ( j = 6; j > k; j--){
			map[i][j].x = -1;
            map[i][j].y = -1;
		}
		
		for ( j = 0; j < map_size * 2 - i + map_size + 1; j++)
		{
			map[i][j].x = j;
            map[i][j].y = i;
		}
	}

    Print_State_with_size(map_size, map);

	printf("Enter of the number of barriers: ");
	scanf("%d", &l);

    printf("Enter the coordinates of the barrier or barriers: ");
    
	for ( i = 0; i < l; i++){
		scanf("%d,%d", &j, &k);
		map[k][j].x = -1;
		map[k][j].y = -1;
	}

	return map;
}

void Warning_Memory_Allocation()
{
    printf("The memory Error in alloacation process! Press a key to exit.\n");
    exit(-1);
}

int main()
{
    Node root, *goal;
    State *goal_state = NULL;
    enum METHODS method;
    int Max_Level, level;

    printf("============= ENTER OF THE MAP SİZE ================= \n");
    int map_size;
    scanf("%d", &map_size);
    
    COORDINATE** map = Create_Map(map_size);

    printf("========== SELECTION OF INITIAL STATE =============== \n");
    root.state     = *(Create_State(map, map_size));
    
}
