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

char * readable_permissions(mode_t mode, char * output){
    char ans[10] = "000000000";
    if (mode & S_IRUSR) ans[0] = 'r';
    else ans[0] = '-';
    if (mode & S_IWUSR) ans[1] = 'w';
    else ans[1] = '-';
    if (mode & S_IXUSR) ans[2] = 'x';
    else ans[2] = '-';
    if (mode & S_IRGRP) ans[3] = 'r';
    else ans[3] = '-';
    if (mode & S_IWGRP) ans[4] = 'w';
    else ans[4] = '-';
    if (mode & S_IXGRP) ans[5] = 'x';
    else ans[5] = '-';
    if (mode & S_IROTH) ans[6] = 'r';
    else ans[6] = '-';
    if (mode & S_IWOTH) ans[7] = 'w';
    else ans[7] = '-';
    if (mode & S_IXOTH) ans[8] = 'x';
    else ans[8] = '-';
    strcpy(output, ans);
    return output;
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
    char output[] = "";
    printf("\nReadable File Permissions: %s\n", readable_permissions(permissions, output));
    
    printf("\n Getting Time of Last Access \n");
    time_t atime = buffer.st_atime;
    printf("\nTime Last accessed: %s\n", ctime(&atime));
    
}
