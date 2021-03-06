#include <iostream>
using namespace std;

/* VARIABLES ====================================================================== */

const int BOARD_SIZE = 10; /* dimensions for board */
const int MAX_MINES = 10; /* maximum number of mines that can be on the board */
const char UNSEEN = '-';
const char BOMB = 'X';
const char FLAG = '+';
char map[BOARD_SIZE][BOARD_SIZE]; /* contains bomb locations */
char board[BOARD_SIZE][BOARD_SIZE]; /* the current board as the user sees it */

/* FUNCTIONS ====================================================================== */

/* fills the user's board with "unseens" */
void populate(char arr[BOARD_SIZE][BOARD_SIZE]) /* fills with "unseens" */
{
        for (int r = 0; r < BOARD_SIZE; r++) {
                for (int c=0; c<BOARD_SIZE; c++) 
                        arr[r][c] = UNSEEN; 
        }
}

/* fills the map with random bombs */
void populateMap()
{
        populate(map);
        int i = 0;
        int temp;
        srand(time(0));
        while (i < MAX_MINES) {
                for (int r = 0; r < BOARD_SIZE; r++) {
                        for(int c = 0; c < BOARD_SIZE; c++){
                                if (i == MAX_MINES) 
                                        return;

                                temp = rand() % (BOARD_SIZE * BOARD_SIZE);

                                if ((temp < MAX_MINES) && 
                                    (i<MAX_MINES) && 
                                    (map[r][c] == UNSEEN)) {
                                        map[r][c] = BOMB;
                                        i++;
                                }
                        }
                }
        }
}

/* prints the given array to console, including coordinate labels */
void printArray(char arr[BOARD_SIZE][BOARD_SIZE])
{
        cout << " ";
        for(int i = 0; i < BOARD_SIZE; i++)  /* top label */
                cout << " " << i;

        for(int r = 0; r < BOARD_SIZE; r++) { /* rows */
                cout << "\n" << r; 
                for(int c = 0; c < BOARD_SIZE; c++)
                        cout << " " << arr[r][c]; 
        }
        cout << "\n";
}

/* helper method to playGame, counts neighboring bombs to cell (r, c) */
char count(int r, int c) 
{ 
        char count = '0';
        int top, bottom, left, right; /* neighboring rows or columns */

        /* row above and below selected cell */
        (r == 0) ? (top = r) : (top = r - 1);
        (r == BOARD_SIZE - 1) ? bottom = r : (bottom = r + 1);

        /* columns to left and right of selected position */
        (c == 0) ? (left = c) : (left = c - 1);
        (c == BOARD_SIZE - 1) ? (right = c) : (right = c + 1);

        for(int x = top; x <= bottom; x++) {
                for(int y = left; y <= right; y++) {
                        if(map[x][y] == BOMB) 
                                count++;
                }
        }
        return count;
}

void playGame()
{
        char state;
        int r, c;
        int remaining = BOARD_SIZE * BOARD_SIZE - MAX_MINES;
        cout << "START GAME\n";

        while(remaining != 0){
                cout << "Enter row and column number,\n";
                cin >> r;
                cin >> c;
                
                cout << "Enter G to guess or F to flag/remove flag.\n";
                cin >> state;

                if (r >= BOARD_SIZE || c >= BOARD_SIZE) {
                        cout << "Out of range. Try again.\n";

                } else if (board[r][c] != UNSEEN && state != 'F') {
                        cout << "Already guessed. Try again.\n";

                } else if (board[r][c] == FLAG && state == 'F') { 
                        board[r][c] = UNSEEN; /* remove flag */

                } else if (board[r][c] != FLAG && state == 'F') { 
                        board[r][c] = FLAG; /* add flag */

                } else if (map[r][c] == UNSEEN) {
                        board[r][c] = count(r, c);
                        remaining--;

                } else if (map[r][c] == BOMB) { /* hit a mine */
                        board[r][c] = BOMB;
                        printArray(board);
                        cout << "YOU HIT A MINE! GAME OVER!\n\n";
                        return;
                }
                printArray(board);
        }
        cout << "YOU WON!!!"; /* this only gets called if the player wins */
}

/* MAIN =========================================================================== */
int main()
{
        populate(board); /* fills up the user's board */
        populateMap(); /* creates map */
        printArray(board); /* shows the board before game begins */
        playGame();
        return 0;
}
