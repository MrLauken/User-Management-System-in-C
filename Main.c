#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

    void RegisterUser ();
    void UserDelete ();
    void UserEdit ();
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
                UserEdit ();
                goto jump;
                break;
            case 3:
                UserDelete();
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                goto jump;
                break;
            case 9:
            Top:
                path = applicationQuit();
                if (path == 1){
                    goto Exit;
                }
                else if (path == 2) {
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
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
}


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
            while (fgets(fill3, 50, Database)!= NULL){     
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

int applicationQuit() {   
    int p;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n Are you sure you want to quit? \n");
    printf("Press 1 for yes, and 2 for no \n");
    scanf("%i", &p);
    return p;
    }

void UserEdit() {
    char Email[50];
    char Password[50];
    char Email2[50];
    char Password2[50];
    char fill [50];
    char fill2 [50];
    int count = 1;
    int line = 0;
    char fill3 [50];
    int p;
    printf("Enter your Email: \n");
    scanf("%s", Email);
    printf("\n Enter your Password \n");
    scanf("%s", Password);
    FILE *Database = fopen("Fortrolig Database", "r+");
    FILE *Database2 = fopen("Midlertidig Database", "w");
    while ((fscanf(Database,"%s", fill) == 1) && (fscanf(Database,"%s", fill2) == 1)) {
        count ++;
        if((strstr(fill, Email)!=0) && (strstr(fill2, Password)!=0)){
            VanHalen:
                printf("What personal information do you want to edit? \n");
                printf("Enter 1 for email, enter 2 for password \n");
                scanf("%i",&p);
                if (p==1){
                    printf("Select your new email below: \n");
                    scanf("%s", Email2);
                    rewind(Database);
                    while (fgets(fill3, 50, Database)!= NULL){      
                        line ++;
                        if (count != line) {
                            fprintf(Database2, fill3);
                         } 
                        else if (count == line-1){
                            fprintf(Database2, "\n");
                        }
                        else if (count == line) {
                            fprintf(Database2, "%s\n", Email2);
                        }
                        }
                }
                else if (p==2){
                    printf("Select your new password below: \n");
                    scanf("%s", Password2);
                    rewind(Database);
                    while (fgets(fill3, 50, Database)!= NULL){      
                        line ++;
                        if (count != line-1) {
                            fprintf(Database2, fill3);
                         } 
                        else if (count == line-2){
                            fprintf(Database2, "\n");
                        }
                        else if (count == line-1) {
                            fprintf(Database2, "%s\n", Password2);
                        }
                    }
                }
                else {
                    printf("Invalid input \n");
                    goto VanHalen;
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
    