#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 15

const char HORZ = 196;
const char VERT = 179;
const char TL   = 218;
const char TM   = 194;
const char TR   = 191;
const char BL   = 192;
const char BM   = 193;
const char BR   = 217;
const int numW  = 3;             // size for writing out an integer
const int charW = 1;             // size for writing out a character
const int numPerLine = 15;
const char VERT_START = 195;
const char VERT_END = 180;
const char VERT_MID = 197;
const char* inputCommand = "Previous move/Next move/Stop [p/n/s]: ";
const char* endOfHistory = "This is the end of the match.\nPrevious move/Next move/Stop [p/n/s]: ";
const char* startOfGame = "This is the start of the match.\nPrevious move/Next move/Stop [p/n/s]: ";
const char* invalidInput = "Illegal input, please try again: ";

enum Stone {NA, X, O};

struct Move {
    int row;
    int col;
    enum Stone stone;
};

static char* lineString( char left, char mid, char right, char horz, int wcell, int ncell ) {
    static char result[100];
    strcpy(result, "");
    char cell[10];
    for(int i = 0; i < wcell; i++){
        cell[i] = horz;
    }
    cell[wcell] = '\0';
    strncat(result,&left,1);
    char cellMid[20];
    strcpy(cellMid, cell);
    strncat(cellMid, &mid,1);
    for ( int i = 0; i < ncell - 1; i++ )
        strcat(result, cellMid);
    char cellRight[20];
    strcpy(cellRight, cell);
    strncat(cellRight, &right,1);
    strcat(result, cellRight);
    return result;
}

void displayBoard(enum Stone arr[][15], int size) {
    //UPPERLINE
    printf("   ");
    for(int i = 0; i < size; i++) {
        printf("  %c ", (char)(i + 'a'));
    }
    printf("\n");
    printf("   %s\n", lineString( TL, TM, TR, HORZ, 3, numPerLine ));

    //MIDDLE
    for(int i = 0; i < size; i++) {
        printf("%2d %c", size - i, VERT);
        for(int j = 0; j < size; j++) {
            if(arr[i][j] == NA) printf("   %c", VERT);
            if(arr[i][j] == X) printf(" X %c", VERT);
            if(arr[i][j] == O) printf(" O %c", VERT);
        }
        printf("\n");
        if(i != size - 1) printf("   %s\n", lineString( VERT_START, VERT_MID, VERT_END, HORZ, 3, numPerLine ));
    }

    //UNDERLINE
    printf("   %s\n", lineString( BL, BM, BR, HORZ, 3, numPerLine ));
}

void displayBoardSimple(enum Stone arr[][15], int size) {
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++) {
            printf("%d", arr[i][j]);
        }
    }
    printf("\n");
}

bool makeMove(enum Stone board[][15], int size, char* playerMove, bool isFirstPlayerTurn){
   int n = 0, i;
   if(strlen(playerMove) > 3 || strlen(playerMove) <= 1) // nếu độ dài chuỗi <= 1 hoặc lớn hơn 3 thì sai vì 1 nước đi cần 1 số và 1 chữ cái nên tối thiểu độ dài 2 tối đa là 3
    return false;
   for(i=0; i<strlen(playerMove); i++) // duyệt từ đầu đến cuối xâu
        if(playerMove[i] >= '0' && playerMove[i] <= '9') // nếu là kí tự số thực hiện tách số 
            n = n*10 + playerMove[i] - 48; // VD: 15 => n = 0 + '1' - 48 = 1, n = 1*10 + '5' - 48 = 15 việc trừ 48 là để chuyển từ kí tự về số tương ứng
        else
            break; // nếu gặp kí tự khác số thì thoát
    if(n > 15 || playerMove[i] < 'a' || playerMove[i] > 'o') // kiểm tra số vừa tách được nếu > 15 hoặc kí tự còn lại không thuộc [a, o] thì trả về false
        return false;
    if(isFirstPlayerTurn){
        if(board[15 - n][playerMove[i] - 'a'] == NA) // kiểm tra có phải ô trống không
            board[15 - n][playerMove[i] - 'a'] = X; // đánh X
        else
            return false; // trả về sai vì đã đánh rồi
    }else
        if(board[15 - n][playerMove[i] - 'a'] == NA)
            board[15 - n][playerMove[i] - 'a'] = O;
        else
            return false;
    return true;
}

bool hasWon(enum Stone board[][15], int size, bool isFirstPlayerTurn) {
    /*
    1: ngang
    2: dọc
    3: chéo xuống
    4: chéo lên
    chỉ cần kiểm tra 4 hướng vì các hướng còn lại ứng với 1 trong 4 hướng trên của 1 điểm khác trong bàn cờ
            4
          4
        4
      4
    0 1 1 1 1 
    2 3
    2   3
    2     3
    2       3
    
    */
    if(isFirstPlayerTurn){
        for(int i=0; i<15; i++)
            for(int j=0; j<15; j++)
                if(board[i][j] == X){
                    // Duyet ngang
                    if(j + 5 < size)// điều kiện để từ ô đang xét có 5 ô ngang
                        if(board[i][j] == board[i][j+1] && board[i][j] == board[i][j+2] // nếu 5 ô ngang liên tiếp bằng nhau thì trả về true
                            && board[i][j] == board[i][j+3] && board[i][j] == board[i][j+4]
                            && !(j > 0 && O == board[i][j-1] && O == board[i][j-5]) // không Bi chan 2 dau
                            && !(j > 0 && (X == board[i][j-1] || X == board[i][j-5])))  // khong phải nước 6
                                return true;
                    // Duyet doc
                    if(i + 5 < size) // để đủ 5 ô dọc thì i + 5 < size
                            if(board[i][j] == board[i+1][j] && board[i][j] == board[i+2][j]
                            && board[i][j] == board[i+3][j] && board[i][j] == board[i+4][j]
                            && !(i > 0 && O == board[i+5][j] && O == board[i-1][j]) // không bị chặn 2 đầu
                            && (i > 0 && (X == board[i+5][j] || X == board[i-1][j])))   // không phải nước 6
                                    return true;
                    // Duyet cheo xuong
                    if(i + 5 < size && j + 5 <size) // để có đủ 5 ô chéo xuống => mất 5 dòng và 5 ô cột 
                            if(board[i][j] == board[i+1][j+1] && board[i][j] == board[i+2][j+2]
                            && board[i][j] == board[i+3][j+3] && board[i][j] == board[i+4][j+4]
                            && !(i > 0 && j > 0 && O == board[i+5][j+5] && O == board[i-1][j-1]) // không bị chặn 2 đầu
                            && (i > 0 && j > 0 && (X == board[i+5][j+5] || X == board[i-1][j-1])))  // không phải nước 6
                                    return true;
                    // Duyet cheo len
                    if(i - 5 >= 0 && j + 5 <= size) // chéo lên 
                            if(board[i][j] == board[i-1][j+1] && board[i][j] == board[i-2][j+2]
                            && board[i][j] == board[i-3][j+3] && board[i][j] == board[i-4][j+4]
                            && !(j > 0 &&  i + 1 < size && O == board[i-5][j+5] && O== board[i+1][j-1]) // không bị chặn 2 đầu
                            && (j > 0 &&  i + 1 < size && (X == board[i-5][j+5] && X== board[i+1][j-1]))) // không phải nước 6
                                    return true;
                }
    }else
        for(int i=0; i<15; i++)
            for(int j=0; j<15; j++)
                if(board[i][j] == O){
                    // Duyet ngang
                    // Duyet ngang
                    if(j + 5 < size)// điều kiện để từ ô đang xét có 5 ô ngang
                        if(board[i][j] == board[i][j+1] && board[i][j] == board[i][j+2] // nếu 5 ô ngang liên tiếp bằng nhau thì trả về true
                            && board[i][j] == board[i][j+3] && board[i][j] == board[i][j+4]
                            && !(j > 0 && X == board[i][j-1] && X == board[i][j-5]) // không Bi chan 2 dau
                            && !(j > 0 && (O == board[i][j-1] || O == board[i][j-5])))  // khong phải nước 6
                                return true;
                    // Duyet doc
                    if(i + 5 < size) // để đủ 5 ô dọc thì i + 5 < size
                            if(board[i][j] == board[i+1][j] && board[i][j] == board[i+2][j]
                            && board[i][j] == board[i+3][j] && board[i][j] == board[i+4][j]
                            && !(i > 0 && X == board[i+5][j] && X == board[i-1][j]) // không bị chặn 2 đầu
                            && (i > 0 && (O == board[i+5][j] || O == board[i-1][j])))   // không phải nước 6
                                    return true;
                    // Duyet cheo xuong
                    if(i + 5 < size && j + 5 <size) // để có đủ 5 ô chéo xuống => mất 5 dòng và 5 ô cột 
                            if(board[i][j] == board[i+1][j+1] && board[i][j] == board[i+2][j+2]
                            && board[i][j] == board[i+3][j+3] && board[i][j] == board[i+4][j+4]
                            && !(i > 0 && j > 0 && X == board[i+5][j+5] && X == board[i-1][j-1]) // không bị chặn 2 đầu
                            && (i > 0 && j > 0 && (O == board[i+5][j+5] || O == board[i-1][j-1])))  // không phải nước 6
                                    return true;
                    // Duyet cheo len
                    if(i - 5 >= 0 && j + 5 <= size) // chéo lên 
                            if(board[i][j] == board[i-1][j+1] && board[i][j] == board[i-2][j+2]
                            && board[i][j] == board[i-3][j+3] && board[i][j] == board[i-4][j+4]
                            && !(j > 0 &&  i + 1 < size && X == board[i-5][j+5] && X== board[i+1][j-1]) // không bị chặn 2 đầu
                            && (j > 0 &&  i + 1 < size && (O == board[i-5][j+5] && O== board[i+1][j-1]))) // không phải nước 6
                                    return true;
                }
    return false;
}

void displayHistory(char* history, int numOfMoves) {
    enum Stone game[15][15];
    for(int i = 0; i < MAX_SIZE; i++) {
        for(int j = 0; j < MAX_SIZE; j++) {
            game[i][j] = NA;
        }
    }
    displayBoard(game, MAX_SIZE);
     //displayBoardSimple(game, MAX_SIZE);
    char playerMove[50];
    bool player1Turn = true;
    // ta tạo 1 mảng chuỗi để lưu từng bước đi
    char history2[255][4];
    for(int i=0; i<numOfMoves; i++){
        for(int j=0; j<strlen(history); j++)
            if(history[j] >= 'a' && history[j] <= 'o'){  // 
                strncpy(history2[i], history, j + 1); // copy nước đi 
                // vd: 13n10a => j = 2 => copy từ vị trí đầu đi 3 kí tự tức 13n vào  
                strcpy(history, history + j + 1); // xóa đi j + 1 kí tự đầu của chuỗi lịch sử
                break;
            }
    } 
    int i = 0;
    char c;
    do{
        printf("\nPrevious move/Next move/Stop[p/n/s]: "); fflush(stdin); // xóa bộ nhớ thừa trong bộ nhớ
        scanf("%c", &c);
        switch(c){
            case 'p':{ // nếu nhập p
                if(i == 0){ // nếu đang ở đầu
                    printf("startOfGame.\n");
                    break; // quay lại B4
                }
                // 
                i--; // quay trở lại bước trước
                // tính vị trí bước trước đánh
                int n = 0, j; 
                for(j=0; j<strlen(history2[i]); j++) // duyệt từ đầu đến cuối xâu
                    if(history2[i][j] >= '0' && history2[i][j] <= '9') // nếu là kí tự số thực hiện tách số 
                        n = n*10 + history2[i][j] - 48; // VD: 15 => n = 0 + '1' - 48 = 1, n = 1*10 + '5' - 48 = 15 việc trừ 48 là để chuyển từ kí tự về số tương ứng
                    else
                        break; // nếu gặp kí tự khác số thì thoát
                //printf("%d %c\n", n, history2[i][j]);
                game[15 - n][history2[i][j] - 'a'] = NA; // xóa kí tự đã đánh
                player1Turn = !player1Turn; // đổi lại người đánh
                displayBoard(game, MAX_SIZE); // in ra bàn cờ
                //displayBoardSimple(game, MAX_SIZE);
                break;
            }
            case 'n':{ // nếu nhập n
                if(i == numOfMoves){ // nếu đang ở cuối
                    printf("endOfHistory.\n");
                    break; // kết thúc
                }
                // tương tự bên trên
                int n = 0, j;
                for(j=0; j<strlen(history2[i]); j++) // duyệt từ đầu đến cuối xâu
                    if(history2[i][j] >= '0' && history2[i][j] <= '9') // nếu là kí tự số thực hiện tách số 
                        n = n*10 + history2[i][j] - 48; // VD: 15 => n = 0 + '1' - 48 = 1, n = 1*10 + '5' - 48 = 15 việc trừ 48 là để chuyển từ kí tự về số tương ứng
                    else
                        break; // nếu gặp kí tự khác số thì thoát
                //printf("%d %c", n, )
                // kiểm tra xem đang là X đánh hay O đánh
                if(player1Turn)
                    game[15 - n][history2[i][j] - 'a'] = X;
                else
                    game[15 - n][history2[i][j] - 'a'] = O;
                // tăng lượt
                i++;
                player1Turn = !player1Turn; // đổi người đánh
                displayBoard(game, MAX_SIZE); // in ra bàn mới
                //displayBoardSimple(game, MAX_SIZE);
                break;
            }
            case 's':{ // kết thúc
                return;
            }
            default:{ // các trường hợp còn lại
                printf("invalidInput.\n");
            }
        }
    }while(1);
}

void startGame() {
    enum Stone game[15][15];
    for(int i = 0; i < MAX_SIZE; i++) {
        for(int j = 0; j < MAX_SIZE; j++) {
            game[i][j] = NA;
        }
    }
    displayBoard(game, MAX_SIZE);
     //displayBoardSimple(game, MAX_SIZE);
    char playerMove[50];
    bool player1Turn = true;
    printf("Player 1 turn: ");
    while(true) {
        scanf("%s", playerMove);
        if(strcmp(playerMove,"ff") == 0) {
            printf("%s", ((player1Turn) ? "Player 2 won " : "Player 1 won "));
            break;
        }
        else if(makeMove(game, MAX_SIZE, playerMove, player1Turn)){
            if(hasWon(game, MAX_SIZE, player1Turn)) {
                displayBoard(game, MAX_SIZE);
                 //displayBoardSimple(game, MAX_SIZE);
                printf("%s", ((player1Turn) ? "Player 1 won " : "Player 2 won "));
                return;
            }
            player1Turn = !player1Turn;
            displayBoard(game, MAX_SIZE);
             //displayBoardSimple(game, MAX_SIZE);
            printf("%s", ((player1Turn) ? "Player 1 turn: " : "Player 2 turn: "));
        } else {
            printf("Illegal move, please try again: ");
        }
    }
}

int main()
{
    printf("Welcome to Gomoku!\n");
    printf("1. Play game\n");
    printf("2. History\n");
    printf("3. Exit\n");
    printf("Please select mode [1/2/3]: ");
    int mode;
    while(true){
        scanf("%d", &mode);
        if(mode == 1) {
            startGame();
            return 0;
        } else if (mode == 2) {
            int numOfMoves;
            printf("Please enter number of moves: ");
            scanf("%d", &numOfMoves);
            char history[700];
            printf("Please enter history: ");
            scanf("%s", history);
            displayHistory(history, numOfMoves);
            return 0;
        } else if (mode == 3) {
            return 0;
        } else {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Invalid mode, please try again: ");
        }
    }

    return 0;
}