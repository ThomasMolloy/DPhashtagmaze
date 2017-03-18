# define EOF -1
#include <stdio.h>
#include <stdlib.h>

int height, width;
char maze[100][100], array[10000];

int main(int argc, char **argv){
  int inc;
  inc = 0;
  while((array[inc] = getchar()) != EOF){
    inc++;
  }
  //int gr = 0;
  //while(gr < inc){
  //printf("%c", array[gr]);
  //gr++;
  //}

  height = atoi(argv[1]);
  width = atoi(argv[2]);

  inc = 0;
  for(int i = 0; i <= height; i++){
    for(int k = 0; k <= width; k++){
      maze[i][k] = array[inc];
      inc++;
    }
  }

  for(int i = 0; i <= height; i++){
    for(int k = 0; k <= width; k++){
      printf("%c", maze[i][k]);
    }
  }
  /*for(int i = 0; i < height; i++){
    for(int k = 0; k < width; k++){
      printf("%c", maze[i][k]);
    }
    printf("\n");
    }*/
}
