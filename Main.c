#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>

    int RememberUsername(char *Email);
    const char* Login();
    int Logout();
    void RegisterUser ();
    void UserDelete ();    
    void UserEdit ();
    char applicationQuit(); 
    void Timeget();
    void Companylogo();
    void invalidInput();
    void Creditscreen();
    



int main() {
    const char *shit;
    int k, path, p;
    int a = 1;
    int L = 0; 
    char Email[255];
    Timeget();
    printf("Welcome to GreenhatAI ");
    Companylogo();
    Sleep(4500);
    jump:
    system("cls");
    Timeget();
    if (L==1){
        printf("User: %s", Email);
    }

    printf("\nChoose your course of action \n");
    printf("Press 1 for new user \n");
    printf("Press 2 to edit already existing user \n");
    printf("Press 3 to delete your account \n");
    printf("Press 4 to view the creditscreen \n");
    if (L==1){
    printf("Press 5 to logout \n");
    }
    else{
    printf("Press 5 to login \n");
    }
    printf("Press 9 to quit application \n");
    Sleep(200);
    a=1;
    while (a==1){ 
        scanf("%i",&k);
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
            case 4:
                system("cls");
                Timeget();
                Creditscreen();
                goto jump;
                break;
            case 5:
                if (L==0){
                    system("cls");
                    Timeget();
                    shit = Login();
                    if (shit!=0){
                        strncpy(Email, shit, 200);
                        L=1;
                    }
                    goto jump;
                }
                else if (L==1){
                    char z;
                    system("cls");
                    Timeget();
                    printf("Are you sure you want to log out?\n");
                    printf("Press 1 for yes\n");
                    printf("Press 2 for no\n");
                    scanf("%", &z);
                    if (z==1){
                    L=0;
                    }
                    else if ((z!=1) && (z!=2)){
                        invalidInput();
                    }
                    goto jump;
                }
                break;
            case 9:
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
                else if ((path != 1) || (path != 2)) {
                    invalidInput();
                    goto jump;
                }
                
            default:
                invalidInput();
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
        perror("Wrong email or password");
        Sleep(2500);
    }
    system("cls");
} 

char applicationQuit() {   
    char p;
    system("cls");
    printf("Are you sure you want to quit? \n");
    printf("Press 1 for yes, and 2 for no \n");
    scanf("%d", &p);
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
    Timeget();
    printf("\nEnter your Email: \n");
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
                    invalidInput();
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
    printf(" .");
    Sleep(20);
    printf(" .");
    Sleep(250);
    printf(" .");
    Sleep(313);
    printf(" .");
    Sleep(350);
    printf(" .");
    Sleep(100);
}

void invalidInput () {
    Timeget();
    perror(" \n Input not defined");
    Sleep(3000);
    system("cls");
}

void Creditscreen() {
    Companylogo();
    for (int i = 0; i<5; i++){
    printf("\n");
    Sleep(500);
    }
    printf("\nHenrik Alexander Sortaasloekken");
    Sleep(1500);
    printf("\nElias Maarvad Oevstegaard");
    Sleep(1500);
    printf("\nCredible partners: stackoverflow.com");
    Sleep(1500);
    printf("\n                   tutorialspoint.com");
    Sleep(1500);
    printf("\n                   geeksforgeeks.org");
    Sleep(1500);
    for (int i = 0; i<5; i++){
    printf("\n");
    Sleep(1500);
    }
    printf("\nSupport future projects by donating to +47 47340041 with vipps");
    Sleep(1500);
    printf("\nThank You!");
    Sleep(2000);
    Sleep(5000);
    Timeget();
    Companylogo();
}

const char* Login () {
    int p=0;
    char Email[255];
    char Password[255];
    char fill[255];
    char fill2[255];
    printf("Login: \n");
    printf("Please enter your email below: \n");
    scanf("%s", Email);
    printf("\n Enter your Password \n");
    scanf("%s", Password);
    FILE *Database = fopen("Fortrolig Database", "r+");
    while ((fscanf(Database,"%s", fill) != 0) && (fscanf(Database,"%s", fill2) != 0)) {
        if((strstr(fill, Email)!=0) && (strstr(fill2, Password)!=0)){
            p=2;
            system("cls");
            printf("\n Welcome back %s!", Email);
            Sleep(3000);
            char *papa = Email;
            return papa;
    
        }
    }
    if (p==0){
        printf("\nFeil Passord retard!");
        Sleep(2500);
        return 0;  }  

        
}
