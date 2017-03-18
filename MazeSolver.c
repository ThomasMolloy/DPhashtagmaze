//
//  main.c
//  C Practice
//
//  Created by Thomas Molloy on 3/3/17.
//  Copyright © 2017 Thomas Molloy. All rights reserved.
//
# define EOF -1
# define YES 1
# define NO 0
#include <stdio.h>
#include <stdlib.h>

int height, width;
char array[10000], maze[100][100];

void UpdateXRight(int* x){
    *x = *x + 1;
}

void UpdateXLeft(int* x){
    *x = *x - 1;
}

void UpdateYUp(int* y){
    *y = *y - 1;
}

void UpdateYDown(int* y){
    *y = *y + 1;
}

int CheckWall(char* cursor){
    if(*cursor == ' '){
        return NO;
    }
    else return YES;
}

char CheckSym(char* cursor){
    if(*cursor == '#'){
        return '#';
    }
    else if(*cursor == 'D'){
        return 'D';
    }
    else if(*cursor == 'o'){
        return 'o';
    }
    else return ' ';
}


int main(int argc, char **argv){
    int inc, x, y, startX = 0, startY = 0, deadEnd = YES, finish = NO;
    
    //reading input into 2d array maze
    inc = 0;
//    while(getchar() != EOF){
//        array[inc] = getchar();
///    }
    char c;
    FILE * fpointer;
    fpointer = fopen("maze.txt", "r");
    while((c = fgetc(fpointer)) != EOF){
        array[inc] = c;
        inc++;
    }

    height = atoi(argv[1]);
    width = atoi(argv[2]);

    inc = 0;
    for(int i = 0; i < height; i++){
        for(int k = 0; k <= width; k++){
            maze[i][k] = array[inc];
            if(maze[i][k] == 'S'){
                startX = k;
                startY = i;
            }
            inc++;
        }
    }
    //Goes through the maze
    y = startY; x = startX;
    while(finish == NO){
        if(maze[y][x] == 'X'){
            finish = YES;
            break;
        }
        if(CheckWall(&maze[y - 1][x]) == NO){
            maze[y][x] = 'o';
            UpdateYUp(&y);
        }
        else if(CheckWall(&maze[y + 1][x]) == NO){
            maze[y][x] = 'o';
            UpdateYDown(&y);
        }
        else if(CheckWall(&maze[y][x - 1]) == NO){
            maze[y][x] = 'o';
            UpdateXLeft(&x);
        }
        else if(CheckWall(&maze[y][x + 1]) == NO){
            maze[y][x] = 'o';
            UpdateXRight(&x);
        }
        else{
            //dead end : back track to available space
            deadEnd = YES;
            while(deadEnd == YES){
                if(CheckSym(&maze[y - 1][x]) == ' '){
                    deadEnd = NO;
                    UpdateYUp(&y);
                }
                else if(CheckSym(&maze[y + 1][x]) == ' '){
                    deadEnd = NO;
                    UpdateYDown(&y);
                }
                else if(CheckSym(&maze[y][x - 1]) == ' '){
                    deadEnd = NO;
                    UpdateXLeft(&x);
                }
                else if(CheckSym(&maze[y][x + 1]) == ' '){
                    deadEnd = NO;
                    UpdateXRight(&x);
                }
                else if(CheckSym(&maze[y - 1][x]) == 'o'){
                    maze[y][x] = 'D';
                    UpdateYUp(&y);
                }
                else if(CheckSym(&maze[y + 1][x]) == 'o'){
                    maze[y][x] = 'D';
                    UpdateYDown(&y);
                }
                else if(CheckSym(&maze[y][x - 1]) == 'o'){
                    maze[y][x] = 'D';
                    UpdateXLeft(&x);
                }
                else if(CheckSym(&maze[y][x + 1]) == 'o'){
                    maze[y][x] = 'D';
                    UpdateXRight(&x);
                }
            }
        }
    }

    //prints final result maze
    maze[startY][startX] = 'S';
    for(int i = 0; i <= height; i++){
        for(int k = 0; k <= width; k++){
            if(maze[i][k] == 'D'){
                maze[i][k] = ' ';
            }
            printf("%c", maze[i][k]);
        }
    }
    
}
