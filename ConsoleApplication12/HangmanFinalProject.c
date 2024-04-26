#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


#define MAX_WRONG_GUESSES 6
#define MAX_WORD_LENGTH 20

// Function to randomly select a word from the list
const char* chooseWord(const char* wordList[], int wordCount) {
    srand(time(NULL));
    return wordList[rand() % wordCount];
}


// Function to display the hangman based on the number of wrong guesses
void drawHangman(int wrongGuesses) {

    switch (wrongGuesses) {

    case 0:
        printf("  ____\n");
        printf(" |    |\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
        printf("   ------\n");
        break;
    case 1:
        printf("  ____\n");
        printf(" |    |\n");
        printf(" O    |\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
        printf("   ------\n");
        break;
    case 2:
        printf("  ____\n");
        printf(" |    |\n");
        printf(" O    |\n");
        printf(" |    |\n");
        printf("      |\n");
        printf("      |\n");
        printf("   ------\n");
        break;
    case 3:
        printf("  ____\n");
        printf(" |    |\n");
        printf(" O    |\n");
        printf(" |\\   |\n");
        printf("      |\n");
        printf("      |\n");
        printf("   ------\n");
        break;
    case 4:
        printf("  ____\n");
        printf(" |    |\n");
        printf(" O    |\n");
        printf("/|\\   |\n");
        printf("      |\n");
        printf("      |\n");
        printf("   ------\n");
        break;
    case 5:
        printf("  ____\n");
        printf(" |    |\n");
        printf(" O    |\n");
        printf("/|\\   |\n");
        printf("/     |\n");
        printf("      |\n");
        printf("   ------\n");
        break;
    case 6:
        printf("  ____\n");
        printf(" |    |\n");
        printf(" O    |\n");
        printf("/|\\   |\n");
        printf("/ \\   |\n");
        printf("      |\n");
        printf("    ----\n");
        break;
    }
}

// Function to display the word with correctly guessed letters
void displayWord(const char* word, const char* guessedLetters) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (strchr(guessedLetters, word[i]) != NULL) {
            printf("%c ", word[i]);
        }
        else {
            printf("_ ");
        }
    }
    printf("\n");
}

void easyGame() {
    const char* wordList[] = { "fry", "ice", "rad", "flag", "drag", "sink", "door", "paint", "grass", "rug", "cat", "water," "apple", "juice" };
    const int wordCount = sizeof(wordList) / sizeof(wordList[0]);
    const char* word = chooseWord(wordList, wordCount);
    char guessedLetters[MAX_WORD_LENGTH];
    int wrongGuesses = 0;

    memset(guessedLetters, 0, sizeof(guessedLetters));

    printf("Welcome to the easy game of Hangman! GOOD LUCK!\n");
    printf("Try to guess the word.\n");


    // -------------------------------
    while (1) {
        printf("\n");
        drawHangman(wrongGuesses);
        displayWord(word, guessedLetters);

        if (wrongGuesses == MAX_WRONG_GUESSES) {
            printf("\nYou lost! The word was: %s\n", word);
            break;
        }

        int allLettersGuessed = 1;
        for (int i = 0; i < strlen(word); i++) {
            if (strchr(guessedLetters, word[i]) == NULL) {
                allLettersGuessed = 0;
                break;
            }
        }
        if (allLettersGuessed) {
            printf("\nCongratulations! You won!\n");
            break;
        }

        printf("\nEnter a letter: ");
        char guess;
        scanf_s(" %c", &guess);
        guess = tolower(guess);

        if (strchr(guessedLetters, guess) != NULL) {
            printf("You already guessed that letter.\n");
            continue;
        }

        guessedLetters[strlen(guessedLetters)] = guess;

        if (strchr(word, guess) == NULL) {
            printf("Wrong guess!\n");
            wrongGuesses++;
        }
    }

    return 0;
    //-----------------------
}

int mediumGame() {
    const char* wordList[] = { "remember", "library", "baseball", "interested", "partner", "laptop", "pressure", "programming", "brawler", "reinforced", "rushing", "beginner" };
    const int wordCount = sizeof(wordList) / sizeof(wordList[0]);
    const char* word = chooseWord(wordList, wordCount);
    char guessedLetters[MAX_WORD_LENGTH];
    int wrongGuesses = 0;

    memset(guessedLetters, 0, sizeof(guessedLetters));

    printf("Welcome to the medium game of Hangman! GOOD LUCK!\n");
    printf("Try to guess the word.\n");

    while (1) {
        printf("\n");
        drawHangman(wrongGuesses);
        displayWord(word, guessedLetters);

        if (wrongGuesses == MAX_WRONG_GUESSES) {
            printf("\nYou lost! The word was: %s\n", word);
            break;
        }

        int allLettersGuessed = 1;
        for (int i = 0; i < strlen(word); i++) {
            if (strchr(guessedLetters, word[i]) == NULL) {
                allLettersGuessed = 0;
                break;
            }
        }
        if (allLettersGuessed) {
            printf("\nCongratulations! You won!\n");
            break;
        }

        printf("\nEnter a letter: ");
        char guess;
        scanf_s(" %c", &guess);
        guess = tolower(guess);

        if (strchr(guessedLetters, guess) != NULL) {
            printf("You already guessed that letter.\n");
            continue;
        }

        guessedLetters[strlen(guessedLetters)] = guess;

        if (strchr(word, guess) == NULL) {
            printf("Wrong guess!\n");
            wrongGuesses++;
        }
    }

    return 0;
}

int hardGame() {
    const char* wordList[] = { "recording", "evangelion", "encouraged", "sporangium", "integumentary", "endometrium", "blandisment", "camaraderie", "circumlocution", "commensurate" };
    const int wordCount = sizeof(wordList) / sizeof(wordList[0]);
    const char* word = chooseWord(wordList, wordCount);
    char guessedLetters[MAX_WORD_LENGTH];
    int wrongGuesses = 0;

    memset(guessedLetters, 0, sizeof(guessedLetters));

    printf("Welcome to the hard game of Hangman! GOOD LUCK!\n");
    printf("Try to guess the word.\n");

    while (1) {
        printf("\n");
        drawHangman(wrongGuesses);
        displayWord(word, guessedLetters);

        if (wrongGuesses == MAX_WRONG_GUESSES) {
            printf("\nYou lost! The word was: %s\n", word);
            break;
        }

        int allLettersGuessed = 1;
        for (int i = 0; i < strlen(word); i++) {
            if (strchr(guessedLetters, word[i]) == NULL) {
                allLettersGuessed = 0;
                break;
            }
        }
        if (allLettersGuessed) {
            printf("\nCongratulations! You won!\n");
            break;
        }

        printf("\nEnter a letter: ");
        char guess;
        scanf_s(" %c", &guess);
        guess = tolower(guess);

        if (strchr(guessedLetters, guess) != NULL) {
            printf("You already guessed that letter.\n");
            continue;
        }

        guessedLetters[strlen(guessedLetters)] = guess;

        if (strchr(word, guess) == NULL) {
            printf("Wrong guess!\n");
            wrongGuesses++;
        }
    }

    return 0;
}

int menu()
{            //desplaying the Main menu
    char m[10];
    system("cls");
    printf("     Menu     \n");
    printf("=========================================\n\n");
    printf("  - Welcome to Hangman\n- Select Difficulty -\n-- Easy Medium Hard --  \n");
    printf("    exit to exit   \n\n");
    printf("=========================================\n");
    scanf_s("%s", &m, 10);


    //check the users input and proceed accorcdingly
    if (strcmp(m, "Easy") == 0)
    {
        system("cls");
        easyGame();
    }
    if (strcmp(m, "easy") == 0)
    {
        system("cls");
        easyGame();

    }
    else if (strcmp(m, "Medium") == 0)
    {
        system("cls");
        mediumGame();

    }
    else if (strcmp(m, "medium") == 0)
    {
        system("cls");
        mediumGame();
    }
    else if (strcmp(m, "Hard") == 0)
    {
        system("cls");
        hardGame();
    }
    else if (strcmp(m, "hard") == 0)
    {
        system("cls");
        hardGame();
    }
    else if (strcmp(m, "Exit") == 0)
    {
        printf("Exiting game");
    }
    else if (strcmp(m, "exit") == 0)
    {
        printf("Exiting game");
    }
    else
    {
        printf("Incorrect entry, please try again."); //prompt for a correct input
        Sleep(2000);
        menu();
    }
}

char entry()
{              //function for full name entry
    char fname[1024];
    char lname[1024];
    system("cls");
    printf("Signin with your full name: ");
    scanf_s("%s %s", &fname, 1024, &lname, 1024);


    //credentials check for access
    if (strcmp(fname, "Benjamin") == 0)
    {
        if (strcmp(lname, "Walters") == 0)
        {
            menu(); //display menu on successful 
        }

        else
        {
            printf("Last name not correct, please try again");
            Sleep(2000);
            entry();
        }
    }

    else
    {
        printf("First name not correct, please try again");
        Sleep(2000);
        entry();
    }
}

int main() {
    entry();
}


