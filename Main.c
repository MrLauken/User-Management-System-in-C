#include <stdio.h>
#include <string.h>
#include <stdlib.h>

    void RegisterUser ();
   // int Crypto(char Password[50]);
    void UserDelete ();
    /* void UserEdit ();
    void applicationQuit(); */


int main() {
    int k;
    printf("Welcome to GreenhatAI \n \n \n \n \n \n \n");
    printf("Choose your course of action \n");
    printf("Press 1 for new user \n");
    printf("Press 2 to edit already existing user \n");
    printf("Press 3 to delete your account \n");
    printf("Press 9 to quit application \n");
    jump: 
        scanf("%d",&k);
        switch (k) {
            case 1: 
                RegisterUser();
                break;
            case 2:
                //UserEdit ();
                printf("Error, Path not yet coded \n");
                goto jump;
                break;
            case 3:
                UserDelete();
                goto jump;
                break;
            case 9:
               // applicationQuit();
                printf("Error, Path not yet coded \n");
                goto jump;
                break; 
            default:
                printf("\n Invalid input \n");
                printf("Press 1 for new user \n");
                printf("Press 2 to edit already existing user \n");
                printf("Press 3 to delete your account \n");
                printf("Press 9 to quit application \n");
                goto jump;
                break;
    }
    return 0;

}


void RegisterUser () {
    FILE *Database;
    char Email [50];
    char Password [50]; 
    printf("User registration: \n \n Hello ... and welcome to GreenhatAI \n");
    printf("\n \n Start your registration by typing your Email: \n");
    scanf("%s", Email);
    printf("\n \n \n \n \n \n \n \n \n \n Email: %s \n \n Please select a password: \n", Email);
    scanf("%s", Password);
    Database = fopen("Fortrolig Database", "a+");
    fprintf(Database,"\n \n %s", Email);
    fprintf(Database,"\n %s", Password);
    fclose(Database);
    /* char CribbedPassword = Crypto(Password);
     StorinUnit(Email, CribbedPassword); */
}
/*
int Crypto(char Password[50]) {
    for (int i=0; i<=50; i++) {
        Password[i]= Password[i]*2;
    }
    return Password[50];
}
*/

void UserDelete () {
    char Email[50];
    char Password[50];
    char fill [50];
    printf("Enter your Email: \n");
    scanf("%s", Email);
    printf("\n Enter your Password \n");
    scanf("%s", Password);
    FILE *Database = fopen("Fortrolig Database", "r+");
    while (fscanf(Database,"%s", fill) == 1){
        if(strstr(fill, Email)!=0){
           printf("Email found");
        }


    }


}