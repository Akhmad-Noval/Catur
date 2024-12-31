#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

// Struktur untuk mewakili papan catur
char board[BOARD_SIZE][BOARD_SIZE];

// Fungsi untuk menampilkan papan catur
void print_board() {
    printf("  a b c d e f g h\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%d ", BOARD_SIZE - row); // Menampilkan nomor baris catur
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("%c ", board[row][col]); // Menampilkan posisi bidak
        }
        printf("\n");
    }
}

// Fungsi untuk menginisialisasi papan catur
void setup_board() {
    char initial_setup[BOARD_SIZE][BOARD_SIZE] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}, // baris 1
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'}, // baris 2
        {'.', '.', '.', '.', '.', '.', '.', '.'}, // baris 3
        {'.', '.', '.', '.', '.', '.', '.', '.'}, // baris 4
        {'.', '.', '.', '.', '.', '.', '.', '.'}, // baris 5
        {'.', '.', '.', '.', '.', '.', '.', '.'}, // baris 6
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, // baris 7
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}  // baris 8
    };
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = initial_setup[i][j];
        }
    }
}

// Fungsi untuk mengonversi koordinat kolom (a-h) menjadi indeks array
int col_to_index(char col) {
    return col - 'a';
}

// Fungsi untuk mengonversi koordinat baris (1-8) menjadi indeks array
int row_to_index(int row) {
    return BOARD_SIZE - row;
}

// Fungsi untuk memindahkan bidak
void move_piece(char from_col, int from_row, char to_col, int to_row) {
    int from_col_index = col_to_index(from_col);
    int from_row_index = row_to_index(from_row);
    int to_col_index = col_to_index(to_col);
    int to_row_index = row_to_index(to_row);
    
    // Memindahkan bidak
    char piece = board[from_row_index][from_col_index];
    board[to_row_index][to_col_index] = piece;
    board[from_row_index][from_col_index] = '.';
}

// Fungsi untuk meminta input gerakan dari pemain catur
void get_move() {
    char from_col, to_col;
    int from_row, to_row;
    
    printf("Masukkan gerakan (misal: e2 e4): ");
    scanf(" %c%d %c%d", &from_col, &from_row, &to_col, &to_row);
    
    // Memindahkan bidak
    move_piece(from_col, from_row, to_col, to_row);
}

int main() {
    setup_board();
    
    while (1) {
        print_board(); // Menampilkan papan catur
        get_move();    // Meminta input gerakan catur
    }
    
    return 0;
}
Enter
