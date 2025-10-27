#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MAX_ROWS 30
#define MAX_COLS 30

// Board state
static bool mines[MAX_ROWS][MAX_COLS];
static bool revealed[MAX_ROWS][MAX_COLS];
static bool flagged[MAX_ROWS][MAX_COLS];
static int adj[MAX_ROWS][MAX_COLS];

static int R = 9, C = 9, M = 10; // defaults
static bool first_move = true;    // delay mine placement until first reveal so it's always safe

static inline bool in_bounds(int r, int c) {
    return r >= 0 && r < R && c >= 0 && c < C;
}

static void clear_board(void) {
    for (int r = 0; r < MAX_ROWS; ++r) {
        for (int c = 0; c < MAX_COLS; ++c) {
            mines[r][c] = false;
            revealed[r][c] = false;
            flagged[r][c] = false;
            adj[r][c] = 0;
        }
    }
    first_move = true;
}

static void place_mines_avoiding(int sr, int sc) {
    // Place M mines randomly, avoiding (sr, sc) and its 8 neighbors so first click is always safe
    int safe[9][2];
    int safe_count = 0;
    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            int rr = sr + dr, cc = sc + dc;
            if (in_bounds(rr, cc)) {
                safe[safe_count][0] = rr; safe[safe_count][1] = cc; safe_count++;
            }
        }
    }

    int placed = 0;
    while (placed < M) {
        int r = rand() % R;
        int c = rand() % C;
        bool is_safe = false;
        for (int i = 0; i < safe_count; ++i) {
            if (safe[i][0] == r && safe[i][1] == c) { is_safe = true; break; }
        }
        if (is_safe || mines[r][c]) continue;
        mines[r][c] = true;
        placed++;
    }
}

static void compute_adjacent_counts(void) {
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (mines[r][c]) { adj[r][c] = -1; continue; }
            int count = 0;
            for (int dr = -1; dr <= 1; ++dr) {
                for (int dc = -1; dc <= 1; ++dc) {
                    if (dr == 0 && dc == 0) continue;
                    int rr = r + dr, cc = c + dc;
                    if (in_bounds(rr, cc) && mines[rr][cc]) count++;
                }
            }
            adj[r][c] = count;
        }
    }
}

static void print_board(bool reveal_all) {
    // Column header
    printf("    ");
    for (int c = 0; c < C; ++c) printf("%2d ", c + 1);
    printf("\n");
    printf("   +");
    for (int c = 0; c < C; ++c) printf("--+");
    printf("\n");

    for (int r = 0; r < R; ++r) {
        printf("%2d |", r + 1);
        for (int c = 0; c < C; ++c) {
            char ch = ' ';
            bool show = reveal_all || revealed[r][c];
            if (show) {
                if (mines[r][c]) ch = '*';
                else if (adj[r][c] == 0) ch = ' ';
                else ch = '0' + adj[r][c];
            }
            else if (flagged[r][c]) {
                ch = 'F';
            }
            else {
                ch = '#';
            }
            printf("%2c ", ch);
        }
        printf("|\n");
        printf("   +");
        for (int c = 0; c < C; ++c) printf("--+");
        printf("\n");
    }
}

static void flood_reveal(int sr, int sc) {
    // BFS flood to reveal empty areas (adj == 0)
    typedef struct { int r, c; } Node;
    Node* q = (Node*)malloc(R * C * sizeof(Node));
    int head = 0, tail = 0;
    q[tail++] = (Node){ sr, sc };
    revealed[sr][sc] = true;

    while (head < tail) {
        Node cur = q[head++];
        if (adj[cur.r][cur.c] != 0) continue; // only expand from zeros
        for (int dr = -1; dr <= 1; ++dr) {
            for (int dc = -1; dc <= 1; ++dc) {
                int rr = cur.r + dr, cc = cur.c + dc;
                if (!in_bounds(rr, cc)) continue;
                if (revealed[rr][cc] || flagged[rr][cc]) continue;
                revealed[rr][cc] = true;
                if (adj[rr][cc] == 0) q[tail++] = (Node){ rr, cc };
            }
        }
    }
    free(q);
}

static bool check_win(void) {
    int unrevealed = 0;
    for (int r = 0; r < R; ++r)
        for (int c = 0; c < C; ++c)
            if (!revealed[r][c]) unrevealed++;
    return unrevealed == M; // all non-mine cells revealed
}

static void print_help(void) {
    printf("\nCommands:\n");
    printf("  r row col   - reveal cell at (row,col)\n");
    printf("  f row col   - toggle flag at (row,col)\n");
    printf("  h           - help\n");
    printf("  q           - quit\n\n");
    printf("Rows/cols are 1-based indexes. First reveal is always safe.\n\n");
}

int main(void) {
    srand((unsigned)time(NULL));
    clear_board();

    printf("==== Console Minesweeper (C) ====\n");
    printf("Enter board size and mines (e.g., 9 9 10). Max %d x %d.\n", MAX_ROWS, MAX_COLS);
    printf("Rows Cols Mines: ");

    int rr, cc, mm;
    if (scanf("%d %d %d", &rr, &cc, &mm) != 3) {
        printf("Invalid input. Using defaults 9 9 10.\n");
        rr = 9; cc = 9; mm = 10;
    }
    if (rr < 1) rr = 1; if (rr > MAX_ROWS) rr = MAX_ROWS;
    if (cc < 1) cc = 1; if (cc > MAX_COLS) cc = MAX_COLS;
    int max_m = rr * cc - 1; // keep at least one safe cell
    if (mm < 1) mm = (rr * cc) / 8 + 1;
    if (mm > max_m) mm = max_m;
    R = rr; C = cc; M = mm;

    // consume leftover line break from scanf
    int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}

    print_help();
    print_board(false);

    char line[128];
    bool game_over = false;

    while (!game_over) {
        printf("> ");
        if (!fgets(line, sizeof(line), stdin)) break;
        // trim leading spaces
        int i = 0; while (line[i] && isspace((unsigned char)line[i])) ++i;
        if (line[i] == '\0') continue;

        char cmd;
        int r, c;
        if (sscanf(line + i, "%c %d %d", &cmd, &r, &c) >= 1) {
            cmd = tolower((unsigned char)cmd);
            if (cmd == 'q') {
                printf("Bye!\n");
                break;
            }
            else if (cmd == 'h') {
                print_help();
                print_board(false);
                continue;
            }
            else if (cmd == 'f' || cmd == 'r') {
                if (sscanf(line + i + 1, "%*s %d %d", &r, &c) != 2) {
                    printf("Usage: %c row col\n", cmd);
                    continue;
                }
                r -= 1; c -= 1; // to 0-based
                if (!in_bounds(r, c)) {
                    printf("Out of bounds. Rows 1..%d, Cols 1..%d\n", R, C);
                    continue;
                }
                if (cmd == 'f') {
                    if (revealed[r][c]) { printf("Already revealed.\n"); continue; }
                    flagged[r][c] = !flagged[r][c];
                }
                else { // reveal
                    if (flagged[r][c]) { printf("Cell is flagged. Unflag first.\n"); continue; }
                    if (!revealed[r][c]) {
                        if (first_move) {
                            place_mines_avoiding(r, c);
                            compute_adjacent_counts();
                            first_move = false;
                        }
                        if (mines[r][c]) {
                            printf("BOOM! You hit a mine at (%d,%d).\n", r + 1, c + 1);
                            print_board(true);
                            game_over = true;
                            continue;
                        }
                        flood_reveal(r, c);
                        if (check_win()) {
                            printf("Congratulations! You cleared the board!\n");
                            print_board(true);
                            game_over = true;
                            continue;
                        }
                    }
                }
                print_board(false);
            }
            else {
                printf("Unknown command. Type 'h' for help.\n");
            }
        }
    }
    return 0;
}
