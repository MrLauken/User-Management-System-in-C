#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

    void RegisterUser ();
   // int Crypto(char Password[50]);
    void UserDelete ();
    // void UserEdit ();
    int applicationQuit(); 


int main() {
    int k, path;
    int a = 1;
    printf("Welcome to GreenhatAI \n \n \n \n \n \n \n");
    jump:
    printf("Choose your course of action \n");
    printf("Press 1 for new user \n");
    printf("Press 2 to edit already existing user \n");
    printf("Press 3 to delete your account \n");
    printf("Press 9 to quit application \n");
    while (a==1){ 
        scanf("%d",&k);
        switch (k) {
            case 1: 
                RegisterUser();
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n New user successfully registered \n");
                goto jump;
                break;
            case 2:
                //UserEdit ();
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n Error, Path not yet coded \n");
                goto jump;
                break;
            case 3:
                UserDelete();
                goto jump;
                break;
            case 9:
                Top:
                    if (applicationQuit() == 1){
                        goto Exit;
                    }
                    else if (applicationQuit() == 2) {
                        goto jump; 
                    }
                    else {
                        printf("\n Invalid input, try again");
                        goto Top;
                    }
            default:
                printf("\n Invalid input \n");
                printf("Press 1 for new user \n");
                printf("Press 2 to edit already existing user \n");
                printf("Press 3 to delete your account \n");
                printf("Press 9 to quit application \n");
                goto jump;
                break;
    }
    }
    Exit:
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
    fprintf(Database,"\n%s", Email);
    fprintf(Database,"\n%s", Password);
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
    char fill2 [50];
    int count = 1;
    int line = 0;
    char fill3 [50];
    printf("Enter your Email: \n");
    scanf("%s", Email);
    printf("\n Enter your Password \n");
    scanf("%s", Password);
    FILE *Database = fopen("Fortrolig Database", "r+");
    FILE *Database2 = fopen("Midlertidig Database", "w");
    while ((fscanf(Database,"%s", fill) == 1) && (fscanf(Database,"%s", fill2) == 1)) {
        count ++;
        if((strstr(fill, Email)!=0) && (strstr(fill2, Password)!=0)){
            rewind(Database);
            while (fgets(fill3, 50, Database)!= NULL){      //while loop doesnt start at top, but at found value
               line ++;
               if ((count != line) &&  (count+1 != line)) {
                    printf("%s", fill3);
                    fprintf(Database2, fill3);
               } 

           }
        
           }
    }
    if (line>0){
        fclose(Database2);
        fclose(Database);
        remove("Fortrolig Database");
        rename("Midlertidig Database", "Fortrolig Database");
    }
    else {
        fclose(Database2);
        fclose(Database);
        remove("Midlertidig Database");
    }
} 

int applicationQuit() {   //Denne funksjonen krasjer på input 4 some unknown reason
    int answer;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n Are you sure you want to quit? \n");
    printf("Press 1 for yes, and 2 for no \n");
    scanf("%i", answer);
    printf("\n%i",answer);
    return answer;
    }

    

    