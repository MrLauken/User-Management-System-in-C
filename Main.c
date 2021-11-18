#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>

    void RegisterUser ();
    void UserDelete ();    
    void UserEdit ();
    int applicationQuit(); 
    void Timeget();
    void Companylogo();
    



int main() {
    int k, path;
    int a = 1;
    Timeget();
    printf("Welcome to GreenhatAI ");
    Companylogo();
    Sleep(4500);
    jump:
    system("cls");
    Timeget();
    printf("Choose your course of action \n");
    printf("Press 1 for new user \n");
    printf("Press 2 to edit already existing user \n");
    printf("Press 3 to delete your account \n");
    printf("Press 9 to quit application \n");
    Sleep(200);
    while (a==1){ 
        scanf("%d",&k);
        switch (k) {
            case 1: 
                Timeget();
                RegisterUser();
                system("cls");
                Timeget();
                printf("\n New user successfully registered \n");
                Sleep(2500);
                system("cls");
                goto jump;
                break;
            case 2:
                system("cls");
                Timeget();
                UserEdit ();
                system("cls");
                goto jump;
                break;
            case 3:
                system("cls");
                Timeget();
                UserDelete();
                system("cls");
                goto jump;
                break;
            case 9:
            Top:
                system("cls");
                Timeget();
                path = applicationQuit();
                system("cls");
                if (path == 1){
                    Timeget();
                    goto Exit;
                }
                else if (path == 2) {
                    Timeget();
                    goto jump; 
                }
                else {
                    Timeget();
                    printf("\n Invalid input, try again");
                    Sleep(2500);
                    goto Top;
                }
                
            default:
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
    system("cls");
    Timeget();
    printf("\n Email: %s \n \n Please select a password: \n", Email);
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
    int count = 0;
    int line = 0;
    char fill3 [50];
    printf("Enter your Email: \n");
    scanf("%s", Email);
    printf("\n Enter your Password \n");
    scanf("%s", Password);
    FILE *Database = fopen("Fortrolig Database", "r+");
    FILE *Database2 = fopen("Midlertidig Database", "w");
    while ((fscanf(Database,"%s", fill) == 1) && (fscanf(Database,"%s", fill2) == 1)) {
        count++;
        if((strstr(fill, Email)!=0) && (strstr(fill2, Password)!=0)){
            rewind(Database);
            count=count*2-1;
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
        system("cls");
        Timeget();
        printf("Your user has been succesfully deleted");
        Sleep(2500);
    }
    else {
        fclose(Database2);
        fclose(Database);
        remove("Midlertidig Database");
        system("cls");
        Timeget();
        printf("Wrong email or password");
        Sleep(2500);
    }
    system("cls");
} 

int applicationQuit() {   
    int p;
    system("cls");
    printf("Are you sure you want to quit? \n");
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
    int count = 0;
    int line = 0;
    char fill3 [50];
    int p;
    time_t rawtime;
    Timeget();
    printf("\n \n \n \n \n Enter your Email: \n");
    scanf("%s", Email);
    printf("\n Enter your Password \n");
    scanf("%s", Password);
    FILE *Database = fopen("Fortrolig Database", "r+");
    FILE *Database2 = fopen("Midlertidig Database", "w");
    while ((fscanf(Database,"%s", fill) == 1) && (fscanf(Database,"%s", fill2) == 1)) {
        count ++;
        if((strstr(fill, Email)!=0) && (strstr(fill2, Password)!=0)){
            count=count*2-1;
            VanHalen:
                system("cls");
                Timeget();
                printf("What personal information do you want to edit? \n");
                printf("Enter 1 for email, enter 2 for password \n");
                scanf("%i",&p);
                if (p==1){
                    system("cls");
                    Timeget();
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
                    system("cls");
                    Timeget();
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
                    system("cls");
                    Timeget();
                    printf("Invalid input \n");
                    Sleep(2500);
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
        system("cls");
        printf("Wrong email or password, please try again");
        Sleep(2500);
    }


}


void Timeget(){
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    system("cls");
    printf("                                               %s", asctime(timeinfo) );
}

void Companylogo(){
    printf("\n  ____________________ ");
    Sleep(100);
    printf("\n  |                  |");
    Sleep(100);
    printf("\n  |                  |");
    Sleep(100);
    printf("\n  |                  |");
    Sleep(100);
    printf("\n  |__________________|");
    Sleep(100);
    printf("\n  |    GreenhatAI    |");
    Sleep(100);
    printf("\n ----------------------");
    Sleep(100);
    printf("\n     ___       ___             ");
    Sleep(100);
    printf("\n    | I |     | I |           ");
    Sleep(100);
    printf("\n     ---       ---         ");
    Sleep(100);
    printf("\n                          "); 
    Sleep(100);
    printf("\n      ==========                  "); 
    Sleep(100);
    printf("\n      ||||||||||            ");
    Sleep(100);
    printf("\n      ==========           ");
}

