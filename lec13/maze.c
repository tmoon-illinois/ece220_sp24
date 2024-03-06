#include <stdio.h>

// maze 1
#define MAZE_H 4
#define MAZE_W 4

/*
// maze 2
#define MAZE_H 4
#define MAZE_W 6
*/
void print_maze(char maze[][MAZE_W], int height, int width);
int solve(char maze[][MAZE_W], int xpos, int ypos);

int main(){
    char maze[MAZE_H][MAZE_W] = {{' ', 'X', 'X', ' '}, 
                                 {'X', ' ', ' ', 'X'}, 
                                 {' ', ' ', 'X', ' '}, 
                                 {'E', 'X', ' ', ' '}};
    /* 
    char maze[MAZE_H][MAZE_W] = {{' ', 'X', 'X', 'X', ' ', 'X'}, 
                                 {' ', ' ', ' ', ' ', ' ', 'X'}, 
                                 {' ', 'X', 'X', 'X', ' ', ' '}, 
                                 {'E', 'X', ' ', 'X', ' ', ' '}};
                                 */
    /* 
    char maze[MAZE_H][MAZE_W] = {{' ', 'X', 'X', 'X', ' ', 'X'}, 
                                 {'X', ' ', ' ', ' ', ' ', 'X'}, 
                                 {' ', 'X', 'X', 'X', ' ', ' '}, 
                                 {'E', 'X', ' ', ' ', ' ', ' '}};
                                 */
    int x_start = 1, y_start = 2;
    printf("Starting point: (%d, %d)\n", x_start, y_start);
    print_maze(maze, MAZE_H, MAZE_W);
    int res = solve(maze, x_start, y_start);
    
   
    if(res)
        printf("\n\nFound a solution.\n");
    else
        printf("\n\nNo solution exists.\n");
    print_maze(maze, MAZE_H, MAZE_W);


}
void print_maze(char maze[][MAZE_W], int height, int width){
    int i,j;
    printf(" ");
    for(j=0;j<width;j++)
        printf("%d", j);
    printf("\n");
    for(i=0;i<height;i++){
        printf("%d", i);
        for(j=0;j<width;j++){
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// if no path exists, return 0
// if a path exists, return 1
int solve(char maze[][MAZE_W], int xpos, int ypos){
    // current xy position is one of the following cases
    // 1. (B) out of bound
    if(xpos < 0 || xpos >= MAZE_H || ypos < 0 || ypos >= MAZE_W)
        return 0;
    // 2. (B) found exist!
    if(maze[xpos][ypos] == 'E')
        return 1;
    // 3. (B) hit a wall or visited path
    if(maze[xpos][ypos] == 'V' || maze[xpos][ypos] == 'X')
        return 0;

    // 4. (R) a new empty space (let's mark as visted)
    maze[xpos][ypos] = 'V';
    // move down 
    if( solve(maze, xpos + 1, ypos) == 1 ){
        maze[xpos][ypos] = '*';
        return 1;
    }
    // move right
    if( solve(maze, xpos, ypos + 1) == 1 ){
        maze[xpos][ypos] = '*';
        return 1;
    }
    // move up 
    if( solve(maze, xpos - 1, ypos) == 1 ){
        maze[xpos][ypos] = '*';
        return 1;
    }
    // move left 
    if( solve(maze, xpos, ypos - 1) == 1 ){
        maze[xpos][ypos] = '*';
        return 1;
    }

    return 0;
}


