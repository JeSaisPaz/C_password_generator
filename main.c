#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void menu_choice_checker(bool *CHOICE);

void generation(int LP, bool LL, bool UL, bool N, bool SC, char *PTR_ADR);

void send_password_to_file(char *table);

int main() {

        srand(time(NULL));

        char password[17];
        char *ptr_password = password;

        bool LOWERCASE_LETTERS, UPPERCASE_LETTERS, NUMBERS, SPECIAL_CHARACTERS, PRINTING;
        int LENGHT_PASSWORD, i;

        printf("\tGenerateur de mot-de-passe\n");

        printf("\nEntre 8 - 16, de quelle longeur voulez-vous votre mot-de-passe ?\n >");
        do {

                scanf("%d", &LENGHT_PASSWORD);

        }while(LENGHT_PASSWORD > 16 || LENGHT_PASSWORD < 8);

        printf("\nVoulez-vous des lettres minuscules dans votre mot-de-passe ? [o/N]\n");
        menu_choice_checker(&LOWERCASE_LETTERS);

        printf("\nVoulez-vous des lettres majuscules dans votre mot-de-passe ? [o/N]\n");
        menu_choice_checker(&UPPERCASE_LETTERS);

        printf("\nVoulez-vous des nombres dans votre mot-de-passe ? [o/N]\n");
        menu_choice_checker(&NUMBERS);

        printf("\nVoulez-vous des characteres speciaux dans votre mot-de-passe ? [o/N]\n");
        menu_choice_checker(&SPECIAL_CHARACTERS);

        generation(LENGHT_PASSWORD, LOWERCASE_LETTERS, UPPERCASE_LETTERS, NUMBERS, SPECIAL_CHARACTERS, ptr_password);

        printf("\nLe mot-de-passe est: %s", password);

        printf("Voulez-vous un ficher .txt contenant le mot-de-passe ? [o/N]");
        menu_choice_checker(&PRINTING);
        if(PRINTING == true) {
                send_password_to_file(password);
        }

        return 0;
}

void menu_choice_checker(bool *CHOICE) {
        char CHOICE_STATE;
        do{

                CHOICE_STATE = getchar();


        }while(CHOICE_STATE != 'o' && CHOICE_STATE != 'N');

        if(CHOICE_STATE == 'o') {
                *CHOICE = true;
        }
        else {
                *CHOICE = false;
        }
}

void generation(int LP, bool LL, bool UL, bool N, bool SC, char *PTR_ADR) {

        char wanted_chars[1024*sizeof(char)];
        int wanted_chars_index=0, i;

        if(UL == true) {
                for(i=65;i<90;i++) {
                        wanted_chars[wanted_chars_index] = (char)i;
                        wanted_chars_index++;
                }
        }
        if(LL == true) {

                for(i=97;i<122;i++) {
                        wanted_chars[wanted_chars_index] = (char)i;
                        wanted_chars_index++;
                }
        }
        if(N == true) {

                for(i=48;i<57;i++) {
                        wanted_chars[wanted_chars_index] = (char)i;
                        wanted_chars_index++;
                }
        }
        if(SC == true) {

                for(i=33;i<46;i++) {
                        wanted_chars[wanted_chars_index] = (char)i;
                        wanted_chars_index++;
                }
        }

        for(i=0;i<LP;i++) {
                *(PTR_ADR+i) = wanted_chars[rand() % wanted_chars_index];
        }
        PTR_ADR[LP] = '\0';
}

void send_password_to_file(char *table) {
        FILE* PTR_FILE;
        PTR_FILE =  fopen("password.txt", "w");
        fputs(table, PTR_FILE);
        fclose(PTR_FILE);

}