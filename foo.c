#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  int fd;
  fd = open("foo.ppm", O_WRONLY | O_CREAT, 0644);

  char heading[] = "P3 500 500 255";
  write(fd, heading, sizeof(heading));

  int row, col;
  char pixel[50];
  
  FILE *fp;
  fp = fopen("pic.txt", "r");
  if(fp){
    int r, b, g;
    for(row = 0; row < 500; row ++){
      for (col = 0; col < 500; col ++){
	if((r = fgetc(fp)) != EOF && (b = fgetc(fp)) != EOF && (g = fgetc(fp)) != EOF){
	  sprintf(pixel, "%d %d %d ", r, b, g);
	}
	write(fd, pixel, strlen(pixel));
      }
      write(fd, "\n", sizeof("\n"));
    }
    fclose(fp);
  }
  else{
    for(row = 0; row < 500; row ++){
      for (col = 0; col < 500; col ++){
	sprintf(pixel, "%d %d %d ", 255, 255, 255);
	write(fd, pixel, strlen(pixel));
      }
      write(fd, "\n", sizeof("\n"));
    }
  }
  
  close(fd);
  return 0;
}

