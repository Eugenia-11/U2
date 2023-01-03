#include <stdio.h>
#include <string.h>

char saved_password[] = "stack smashing";
int check_password() {
    char buffer[20];
    int flag = 0;

    printf("password:");
    gets(buffer);
    if(strcmp(buffer, saved_password)== 0)
        flag = 1;

    return flag;
}

int main(int argc, char*argv[]){
    if(check_password()) {
        printf("\n*-=-=-=-=-=-=-=-=-=-=-=-=*");
        printf("\n*|   ACCESS ALLOWED   |*");
        printf("\n*-=-=-=-=-=-=-=-=-=-=-=-=*");
    }
    else{
        printf("\n******ACCESS DENIED******");
    }
    return 0;
}
