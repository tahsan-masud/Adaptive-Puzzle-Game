#include <stdio.h>
#include <string.h>
#include <windows.h>


#define USERS_FILE "users.txt"

#define EASY_COUNT 10
#define MED_COUNT 10
#define HARD_COUNT 10



typedef struct
    {
        char username[50];
        char password[50];
        int score;
    } Player;


typedef struct
    {
        char question[200];
        char answer[50];
        int difficulty; // 1 = easy, 2 = medium, 3 = hard
    } Puzzle;



void typeText(const char *text) {
    for (int i = 0; text[i] != '\0'; i++)
    {
        printf("%c", text[i]);
        fflush(stdout);
        Sleep(25);
    }
}

void showRightScoreboard(int score, int room, int total) {
    printf("\n");
    printf("                                                                                                                    ================================\n");
    printf("                                                                                                                    =        SCORE BOARD           =\n");
    printf("                                                                                                                    ================================\n");
    printf("                                                                                                                    =  Room:    %2d / %2d            =\n", room, total);
    printf("                                                                                                                    =  Score:   %4d               =\n", score);
    printf("                                                                                                                    ================================\n");
}

void showIntroStory()
{
    typeText("\033[1;3m               \nIt was an old winter evening, the kind where the world feels slow and quiet.                \033[0m\n \n\n");
    typeText("\033[1;3m              You were walking alone through forgotten ruins, snow crunching beneath your boots.             \033[0m\n   \n");
    typeText("\033[1;3m                 The path was unclear, but a pale light glowed ahead, steady and inviting.                   \033[0m\n \n\n");
    typeText("\033[1;3m                                             You followed it.                                                \033[0m\n \n\n");
    typeText("\033[1;3m                                   The stone beneath you cracked and gave way.                               \033[0m\n \n\n");
    typeText("\033[1;3m                                      You awaken on a cold stone floor.                                      \033[0m\n \n\n");

    printf("\033[1;3m        \nPress Enter to continue...                                                                           \033[0m\n      ");
    //getchar();   // consume leftover newline
    getchar();   // wait for Enter
}


void showRoomStory(int room)
{
    system("cls");
    printf("\n");

    switch(room)
    {
        case 1: typeText("\033[1;3m            You awaken on a cold stone floor, darkness surrounds you.                  \033[0m\n \n"); break;
        case 2: typeText("\033[1;3m        Torches ignite along the walls, casting shadows that seem alive.               \033[0m\n \n"); break;
        case 3: typeText("\033[1;3m        A stone statue blocks your path, mouth open as if asking something.            \033[0m\n \n"); break;
        case 4: typeText("\033[1;3m           The hall seems empty, yet unseen eyes follow your every step.               \033[0m\n \n"); break;
        case 5: typeText("\033[1;3m              An iron door looms, covered in strange carvings.                         \033[0m\n \n"); break;
        case 6: typeText("\033[1;3m           The chamber grows colder, breath fogs the air, and a puzzle awaits.         \033[0m\n \n"); break;
        case 7: typeText("\033[1;3m                Water drips into a shallow pool, echoing endlessly.                    \033[0m\n \n"); break;
        case 8: typeText("\033[1;3m              Broken weapons litter the floor; a logic puzzle challenges your mind.    \033[0m\n \n"); break;
        case 9: typeText("\033[1;3m              A narrow path stretches forward, one misstep could be fatal.             \033[0m\n \n"); break;
        case 10: typeText("\033[1;3m              A golden door stands before you; the final test awaits.                 \033[0m\n \n"); break;
    }

    Sleep(600);
}

void showDungeonStory(int room)
{
    system("cls");
    printf("\n");

    switch (room)
    {
        case 2:
            typeText(
                "\033[1;3m             Long ago, an adventurer lived at the edge of this forest.      \033[0m\n \n"
                "\033[1;3m                 He loved her deeply, but she did not love him back.        \033[0m\n \n"
                "\033[1;3m             One warm summer night, he tried to summon her with a spell.    \033[0m\n \n"
                "\033[1;3m                      The magic failed and the dungeon was born.            \033[0m\n \n"
            );
            break;

        case 4:
            typeText(
                "\033[1;3m                       Scratches and faded symbols cover the walls.           \033[0m\n \n"
                "\033[1;3m                          They tell of waiting. Of hoping.                    \033[0m\n \n"
                "\033[1;3m           A brittle letter rests in stone: 'Come back or let me follow you.' \033[0m\n \n"
                "\033[1;3m                          The curse grew from longing, not anger.             \033[0m\n \n"
            );
            break;

        case 6:
            typeText(
                "\033[1;3m                   Torches flicker, casting shadows that reach like hands.    \033[0m\n \n"
                "\033[1;3m                                     Love cannot be forced.                   \033[0m\n \n"
                "\033[1;3m                 Each failed spell left sorrow behind, carved into stone.     \033[0m\n \n"
                "\033[1;3m                               The dungeon remembers everything.              \033[0m\n \n"
            );
            break;

        case 8:
            typeText(
                "\033[1;3m                         Broken charms and old trinkets lie scattered.        \033[0m\n \n"
                "\033[1;3m                      They speak of patience, disappointment, and regret.     \033[0m\n \n"
                "\033[1;3m                          The magic trapped his heartbreak here.              \033[0m\n \n"
                "\033[1;3m                       The dungeon mourns what cannot be undone.              \033[0m\n \n"
            );
            break;

        case 10:
            typeText(
                "\033[1;3m                              The final hall is silent and still.                          \033[0m\n \n"
                "\033[1;3m                    Now you understand this place exists because of failed love.           \033[0m\n \n"
                "\033[1;3m                               He tried to bring her back.                                 \033[0m\n \n"
                "\033[1;3m                             All he created was a prison of memory.                        \033[0m\n \n"
                "\033[1;3m                  Only by understanding the past and moving on can the curse be broken.    \033[0m\n \n"
            );
            break;
    }

    typeText("\033[1;3m                     \n\nPress Enter to continue...   \033[0m\n");
    getchar(); // clear leftover newline
    getchar(); // wait for Enter
}

void storyLock(int room)
{
    char input[50];

    system("cls");
    printf("\n");

    /* ---------- ROOM 5 LOCK ---------- */
    if (room == 5)
    {
        typeText("\033[1;3m        A stone door blocks your path.         \033[0m\n \n\n");
        typeText("\033[1;3m            I am written with love,            \033[0m\n \n");
        typeText("\033[1;3m             and spoken after loss.            \033[0m\n \n\n");

        typeText("\033[1;3m Enter your answer: \033[0m\n");
        scanf("%s", input);

        if (strcmp(input, "letter") == 0)
        {
            typeText("\033[1;3m \nThe lock clicks softly. \033[0m\n \n");
            Sleep(500);
        }
        else
        {
            typeText("\033[1;3m \nThe door remains sealed. \033[0m\n \n");
            Sleep(700);
            storyLock(5);   // retry safely
        }
    }

    /* ---------- ROOM 10 LOCK ---------- */
    else if (room == 10)
    {
        typeText("\033[1;3m             The final door stands before you.                 \033[0m\n \n\n");
        typeText("\033[1;3m           This place exists because he could not let go.      \033[0m\n \n");
        typeText("\033[1;3m           To leave, you must do what he never did.            \033[0m\n \n\n");

        typeText("\033[1;3m Enter your answer: \033[0m\n");

        fflush(stdin);
        fgets(input, sizeof(input), stdin);   // allow spaces
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "move on") == 0)
        {
            typeText("\033[1;3m \nThe dungeon begins to collapse.   \033[0m\n \n");
            Sleep(600);
            typeText("\033[1;3m The curse is finally broken.   \033[0m\n \n");
            Sleep(600);
        }
        else
        {
            typeText("\033[1;3m \nThe door does not respond.   \033[0m\n \n");
            Sleep(700);
            storyLock(10);   // retry safely
        }
    }
}



/* ----------------- File Handling ----------------- */

int loadUser(char *username, Player *p) {

    FILE *fp = fopen(USERS_FILE, "r");
    if (!fp) return 0;

    while (fscanf(fp, "%s %s %d", p->username, p->password, &p->score) == 3)
        {
            if (strcmp(username, p->username) == 0)
            {
                fclose(fp);
                return 1;
            }
        }

    fclose(fp);
    return 0;
}

void saveNewUser(Player p) {

    FILE *fp = fopen(USERS_FILE, "a");

    fprintf(fp, "%s %s %d\n", p.username, p.password, p.score);

    fclose(fp);
}

void updateUser(Player p) {

    FILE *fp = fopen(USERS_FILE, "r");
    FILE *temp = fopen("temp.txt", "w");

    Player x;

    while (fscanf(fp, "%s %s %d", x.username, x.password, &x.score) == 3)
    {

        if (strcmp(x.username, p.username) == 0)
        {
            int finalScore = x.score;

            if (p.score > x.score) finalScore = p.score;

            fprintf(temp, "%s %s %d\n", p.username, p.password, finalScore);
        }

        else    { fprintf(temp, "%s %s %d\n", x.username, x.password, x.score); }
    }

    fclose(fp);
    fclose(temp);

    remove(USERS_FILE);
    rename("temp.txt", USERS_FILE);
}

/* ----------------- Authentication ----------------- */

int signup() {
    Player p;

    printf("Choose username: ");
    scanf("%s", p.username);

    Player temp;

    if (loadUser(p.username, &temp))
    {
        printf("User already exists!\n");
        return 0;
    }

    printf("Choose password: ");
    scanf("%s", p.password);

    p.score = 0;

    saveNewUser(p);
    printf("Signup successful!\n");
    return 1;
}

int login(Player *p) {
    char uname[50], pass[50];

    printf("Username: ");
    scanf("%s", uname);

    if (!loadUser(uname, p) )
    {
        printf("User not found.\n");
        return 0;
    }

    printf("Password: ");
    scanf("%s", pass);

    if (strcmp(pass, p->password) != 0)
    {
        printf("Wrong password!\n");
        return 0;
    }

    printf("\nLogin successful!\n");
    printf("Welcome back, %s!\n", p->username);
    printf("Your current score: %d\n", p->score);

    printf("\nPress Enter to continue...");
    while (getchar() != '\n');  // clear any leftover newline
    getchar();                  // wait for Enter

    return 1;
}

/* ----------------- Game Logic ----------------- */

void loadPuzzles(Puzzle easy[], Puzzle med[], Puzzle hard[]) {
    // easy
    strcpy(easy[0].question, "\033[32m You step into a damp stone chamber. A rusted door blocks your path. Three scratches are carved on the stone… then five more beneath them. A whisper echoes: 'Count what the stone remembers.' \033[0m\n");
    strcpy(easy[0].answer, "8");
    easy[0].difficulty = 1;

    strcpy(easy[1].question, "\033[32mThe hallway is dark. You light two torches, each burning long enough to guide you for 4 hours. A voice murmurs: 'How long many hours will the light protect you?' \033[0m\n");
    strcpy(easy[1].answer, "8");
    easy[1].difficulty = 1;

    strcpy(easy[2].question, "\033[32mA statue of a forgotten king extends its hand. You place 3 coins, then find another 3 coins hidden beneath the pedestal. The inscription reads: 'How many  coins does he hold?' \033[0m\n");
    strcpy(easy[2].answer, "6");
    easy[2].difficulty = 1;

    strcpy(easy[3].question, "\033[32mA mechanical gate requires 10 units of power. It shows to be holding 6 units. The gate groans: 'How many units of power missing?' \033[0m\n");
    strcpy(easy[3].answer, "4");
    easy[3].difficulty = 1;

    strcpy(easy[4].question, "\033[32mFootprints circle the room. You notice paw-prints of a certain animal, small in size. What could this animal be? \033[0m\n");
    strcpy(easy[4].answer, "cat");
    easy[4].difficulty = 1;

    strcpy(easy[5].question, "\033[32mA polished wall reflects you perfectly. The carving asks: 'What shows your face but is not alive?' \033[0m\n");
    strcpy(easy[5].answer, "mirror");
    easy[5].difficulty = 1;

    strcpy(easy[6].question, "\033[32mA torch burns without sound or smoke. The inscription reads: I consume but never eat. What am I? \033[0m\n");
    strcpy(easy[6].answer, "fire");
    easy[6].difficulty = 1;

    strcpy(easy[7].question, "\033[32mA circular seal glows faintly. It shows the numbers 2, 4, and 6 etched into the stone. The circle demands: 'Reveal the sum.' \033[0m\n");
    strcpy(easy[7].answer, "12");
    easy[7].difficulty = 1;

    strcpy(easy[8].question, "\033[32mAn iron plate reads DOOR. The voice says: 'Reveal the first letter.' \033[0m\n");
    strcpy(easy[8].answer, "D");
    easy[8].difficulty = 1;

    strcpy(easy[9].question, "\033[32mA door engraving states: 'Let the count of angles borne by an octagon be halved. What's the resulting count?' \033[0m\n");
    strcpy(easy[9].answer, "4");
    easy[9].difficulty = 1;




    // medium
    strcpy(med[0].question, "\033[33mA shattered clock still ticks. The inscription reads: 'What is always coming, but never arrives?' \033[0m\n");
    strcpy(med[0].answer, "tomorrow");
    med[0].difficulty = 2;

    strcpy(med[1].question, "\033[33mA vault whispers: Count the syllables in ‘OBSIDIAN’ and raise it to the power of two. \033[0m\n");
    strcpy(med[1].answer, "16");
    med[1].difficulty = 2;

    strcpy(med[2].question, "\033[33mA mechanism hums: 'Take the predecessor of ten and double it.' \033[0m\n");
    strcpy(med[2].answer, "18");
    med[2].difficulty = 2;

    strcpy(med[3].question, "\033[33mA statue blocks the way. It asks: 'What has keys but cannot open locks?' \033[0m\n");
    strcpy(med[3].answer, "piano");
    med[3].difficulty = 2;

    strcpy(med[4].question, "\033[33mThe path stretches forever. The slab reads: 'I have no beginning, no end, yet I am always around you.' \033[0m\n");
    strcpy(med[4].answer, "circle");
    med[4].difficulty = 2;

    strcpy(med[5].question, "\033[33mA magic door shows the numbers: 2 > 4 > 8 > ? What number appears next? \033[0m\n");
    strcpy(med[5].answer, "16");
    med[5].difficulty = 2;

    strcpy(med[6].question, "\033[33mA pressure plate declares: 'Multiply the number of chambers by the number of letters in KEY.' There are 4 chambers. \033[0m\n");
    strcpy(med[6].answer, "12");
    med[6].difficulty = 2;

    strcpy(med[7].question, "\033[33mYou feel pain, yet see nothing. The riddle states: 'What can cut you without touching you?'\033[0m\n");
    strcpy(med[7].answer, "words");
    med[7].difficulty = 2;

    strcpy(med[8].question, "\033[33mYou hear a fainting voice- 'Complete the ancient catchphrase' It continues- 'All that glitters is not ____.'\033[0m\n");
    strcpy(med[8].answer, "gold");
    med[8].difficulty = 2;

    strcpy(med[9].question, "\033[33mA sigil shows the letter C. The gate asks: 'Reveal its index in the alphabets'\033[0m\n");
    strcpy(med[9].answer, "3");
    med[9].difficulty = 2;

    // hard
    strcpy(hard[0].question, "\033[31mA seal bears the word LEVEL. The glyph asks: 'Count distinct letters.' \033[0m\n");
    strcpy(hard[0].answer, "3");
    hard[0].difficulty = 3;

    strcpy(hard[1].question, "\033[31mNames are carved everywhere. The whisper asks: 'What belongs to you, but others use it more?' \033[0m\n");
    strcpy(hard[1].answer, "name");
    hard[1].difficulty = 3;

    strcpy(hard[2].question, "\033[31mThe walls display a rural of the outline of a ferocious mammal. An inscription displays the letters 'niol'. Reorganize the words. \033[0m\n ");
    strcpy(hard[2].answer, "lion");
    hard[2].difficulty = 3;

    strcpy(hard[3].question, "\033[31mA vault inscription states: 'Reverse the digits of the smallest two-digit prime, and double it.' \033[0m\n ");
    strcpy(hard[3].answer, "22");
    hard[3].difficulty = 3;

    strcpy(hard[4].question, "\033[31mYou feel watched. The glyph asks: 'What is always in front of you, but cannot be seen?' \033[0m\n ");
    strcpy(hard[4].answer, "future");
    hard[4].difficulty = 3;

    strcpy(hard[5].question, "\033[31mA voice fades as it speaks: 'What can be broken without being held?' \033[0m\n ");
    strcpy(hard[5].answer, "promise");
    hard[5].difficulty = 3;

    strcpy(hard[6].question, "\033[31mA throne carved from bone speaks: 'The more you take, the more you leave behind. What is it?' \033[0m\n ");
    strcpy(hard[6].answer, "footsteps");
    hard[6].difficulty = 3;

    strcpy(hard[7].question, "\033[31m'You enter and notice a grave, supposedly of a pharaoh. The inscription states: reassemble the word 'grave' in alphabetic order.' \033[0m\n ");
    strcpy(hard[7].answer, "aegrv");
    hard[7].difficulty = 3;

    strcpy(hard[8].question, "\033[31mA door opens only when watched. The rune asks: 'What disappears the moment you say its name?' \033[0m\n ");
    strcpy(hard[8].answer, "silence");
    hard[8].difficulty = 3;

    strcpy(hard[9].question, "\033[31mA chest opens - nothing inside. The whisper laughs: 'What is full when spoken, but empty when done?' \033[0m\n ");
    strcpy(hard[9].answer, "mouth");
    hard[9].difficulty = 3;

}

int getPoints(int difficulty) {
    if (difficulty == 1) return 5;
    if (difficulty == 2) return 10;
    else return 15;
}

int playGame(Player *p) {

    int difficulty = 1;
    Puzzle easy[EASY_COUNT], med[MED_COUNT], hard[HARD_COUNT];
    loadPuzzles(easy, med, hard);

    char ans[50];
    int room;
    int runScore = 0;   // score only for this run

    printf("\n--- Starting the dungeon ---\n");
    showIntroStory();

    for (room = 1; room <= 10;room++) {
        Puzzle q;

        showRoomStory(room);
        showRightScoreboard(runScore, room, 10);

        int index;
        int attempt = 0;
        int solved = 0;

        /* To randomize, first i used the formula
        index = (room + difficulty) % EASY_COUNT
        this worked for a few tries, but if the player constantly
        starts giving wrong answer, the game goes to the easy
        level and at some point index 1. when easy level and index 1
        is reached, for example for room 2, the formula gives
        (2+1)%3 = 1. after another attempt, it is again (2+1)%3 = 1.
        Hence, the game gets stuck in the same question.
        To alter this, a new "attempt" is introduced.
        the formula is updated to
        index = (room + difficulty + attempt) % EASY_COUNT;
        attempt is incremented each time the player gets wrong,
        which avoids the index being 1 continuously. */


        while (!solved)
        {

            if (difficulty == 1)
            {
                index = (room + difficulty + attempt) % EASY_COUNT;
                q = easy[index];
            }
            else if (difficulty == 2)
            {
                index = (room + difficulty + attempt) % MED_COUNT;
                q = med[index];
            }
            else
            {
                index = (room + difficulty + attempt) % HARD_COUNT;
                q = hard[index];
            }

            printf("\n\n");
            printf("                                                                       Room %d\n\n", room);
            printf("============================================================================================================================================================\n");
            printf("\n %s\n", q.question);
            printf("============================================================================================================================================================\n");
            printf("\nAnswer: ");

            scanf("%s", ans);

            if (strcmp(ans, q.answer) == 0)
            {
                printf("Correct!\n");
                runScore += getPoints(difficulty);   // add to run score only

                if (difficulty < 3)
                    difficulty++;


                   solved=1;

            }

            else
            {
                printf("\nIncorrect! Try again.\n");
                attempt++;

                if (difficulty > 1) difficulty--;
            }
        }

         if (room % 2 == 0)
        {
            showDungeonStory(room);
        }

        if (room == 5 || room == 10)
        {
            storyLock(room);
        }
    }

    printf("\033[36m \nYou have successfully broken the curse of the dungeon. Run complete!   \033[0m\n \n");
    printf("Run Score: %d", runScore);

    // Update high score:
    if (runScore > p->score) { p->score = runScore; }

    updateUser(*p);

    int choice;
    printf("\n                                                                   Press 1 to Play again               \n");
    printf("\n                                                                   Press 2 to Logout                   \n");
    scanf("%d", &choice);

    if (choice == 1) return 1;
    else return 0;
}

/* ----------------- Main ----------------- */

int main() {
    int choice;
    Player current;

    printf("\n");
        printf("\n");
        printf("             \033[32m                                   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                    \033[0m\n");
        printf("             \033[32m                                  @                                                     @                    \033[0m\n");
        printf("             \033[32m                                 @            @@@@         @@@@@@@@     @@@@@@@@@@@      @            \033[0m\n");
        printf("             \033[32m                                @            @@  @@        @@     @@    @@                @               \033[0m\n");
        printf("             \033[92m                               @            @@    @@       @@     @@    @@                 @              \033[0m\n");
        printf("             \033[92m                              @            @@@@@@@@@@      @@@@@@@@@    @@   @@@@@@         @                \033[0m\n");
        printf("             \033[92m                               @          @@        @@     @@           @@       @@        @                    \033[0m\n");
        printf("             \033[92m                                @        @@          @@    @@           @@       @@       @               \033[0m\n");
        printf("             \033[33m                                 @      @@            @@   @@           @@       @@      @                \033[0m\n");
        printf("             \033[33m                                  @    @@              @@  @@           @@@@@@@@@@@     @               \033[0m\n");
        printf("             \033[33m                                   @                                                   @                    \033[0m\n");
        printf("             \033[33m                                    @        ADAPTIVE        PUZZLE       GAME        @                     \033[0m\n");
        printf("             \033[33m                                     @                                               @                    \033[0m\n");
        printf("             \033[33m                                      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                    \033[0m\n");
        printf(" \n");
        printf("             \033[31m                                  |----- A Dungeon Based Adaptive Gaming Experience -----|                                 \033[0m\n");
        printf(" \n");

    while (1)
    {
        printf("                                                                 Press 1 to Signup                                     \n");
        printf("                                                                 Press 2 to Login                                      \n");
        printf("                                                                 Press 3 to Exit                                       \n");

        scanf("%d", &choice);

        if (choice == 1) signup();

        else if (choice == 2)
        {
            if (login(&current))
            {
                int replay = 1;
                while (replay == 1) { replay = playGame(&current); }
            }
        }

        else if (choice == 3) break;

        else printf("Invalid choice.\n");
    }

    return 0;
}

