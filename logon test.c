#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct login {
    char fname[30];
    char lname[30];
    char username[30];
    char password[20];
};

void login(void);
void registration(void);

int main(void) {
    char C;
    int option;

    printf("Press '1' to Register\nPress '2' to Login\n\n");
    scanf_s("%d", &option);

    while ((C = getchar()) != '\n' && C != EOF); // Clearing input buffer

    if (option == 1) {
        system("CLS");
        registration();
    }
    else if (option == 2) {
        system("CLS");
        login();
    }
}

void login(void) {
    char username[30], password[20];
    FILE* log = fopen("login.txt", "r");
    if (log == NULL) {
        fputs("Error at opening File!", stderr);
        exit(1);
    }

    struct login l;

    printf("\nPlease Enter your login credentials below\n\n");
    printf("Username:  ");
    fgets(username, 30, stdin);
    printf("\nPassword: ");
    fgets(password, 20, stdin);

    fseek(log, 0, SEEK_SET); // Reset file pointer to beginning

    int loggedIn = 0; // Flag to indicate successful login

    while (fread(&l, sizeof(l), 1, log)) {
        if (strcmp(username, l.username) == 0 && strcmp(password, l.password) == 0) {
            printf("\nSuccessful Login\n");
            loggedIn = 1; // Set flag to indicate successful login
            break; // Exit the loop once login is successful
        }
    }

    if (!loggedIn) {
        printf("\nIncorrect Login Details\nPlease enter the correct credentials\n");
    }

    fclose(log);
}

void registration(void) {
    FILE* log = fopen("login.txt", "a+");
    if (log == NULL) {
        fputs("Error at opening File!", stderr);
        exit(1);
    }

    char* fname;
    char* lname;
    char* username;
    char* password;

    printf("\nWelcome to Hangman follow steps for registration.\n\n");
    printf("\nEnter First Name:\n");
    scanf_s("%s", &fname); // Use %s for strings without spaces
    printf("\nEnter Last Name:\n");
    scanf_s("%s", &lname);

    printf("Thank you.\nNow please choose a username and password as credentials for system login.\nEnsure the username is no more than 30 characters long.\nEnsure your password is at least 8 characters long and contains lowercase, uppercase, numerical and special character values.\n");

    printf("\nEnter Username:\n");
    scanf_s("%s", &username);
    printf("\nEnter Password:\n");
    scanf_s("%s", &password);

    fwrite(&fname, sizeof(fname), 1, log);
    fwrite(&lname, sizeof(lname), 1, log);
    fwrite(&username, sizeof(username), 1, log);
    fwrite(&password, sizeof(password), 1, log);

    fclose(log);

    printf("\nRegistration Successful!\n");
}