#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <math.h>

char * readable_form(long size){
    int x = 0;
    char * end[] = { "B", "KB", "MB", "GB" };
    while (size / 1024 != 0){
        size = size / 1024;
        x++;
    }
    return end[x];
}


int main(){
    
    struct stat buffer;
    
    stat("main.c", &buffer);
    
    printf("\nMetadata of main.c :\n");
    
    printf("\nGetting the file size:\n");
    long file_size = buffer.st_size;
    printf("\nSize of the File: %ld\n", file_size);
    char * readable_size = readable_form(file_size);
    char human_form[100];
    long new_size = file_size;
    while (new_size > 1024){
        new_size = new_size / 1024;
    }
    sprintf(human_form, "%ld %s", new_size, readable_size);
    printf("\nReadable Size of File: %s\n", human_form);
    
    printf("\nGetting the file permissions:\n");
    mode_t permissions = buffer.st_mode;
    printf("\n File Permissions: %d\n", permissions);
    
    printf("\n Getting Time of Last Access \n");
    time_t atime = buffer.st_atime;
    printf("\nTime Last accessed: %s\n", ctime(&atime));
    
}
