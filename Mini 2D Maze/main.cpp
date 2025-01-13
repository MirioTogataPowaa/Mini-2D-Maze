#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int MAZE_HEIGHT = 15;
const int MAZE_WIDTH = 30;

string maze[MAZE_HEIGHT] = {
    "+############################+",
    "|            |               |",
    "|+XXXXXX+    |   +XXXXXX+    |",
    "|        |   |   |            ",
    "|+XXXXXX+        +   +XXXXXX+|",
    "|            |   |   |        ",
    "+XXXXXX+    |   |   |    +XXX+",
    "|        |   |   |   |        ",
    "|+XXXXXX+   +   +   +   +XXXX+",
    "|            |   |            ",
    "|+XXXXXX+    |   |   +XXXXXX+|",
    "|        |   |   |        |   ",
    "|+XXXXXX+   +XXX+   +XXXX+   |",
    "|        |   |   |        |   ",
    "+############################+",
};
void gotoXY(int x, int y) {
    cout << "\x1b[" << y << ";" << x << "H";
}

int keypress() {
    system("/bin/stty raw");
    int c = getc(stdin);
    system("/bin/stty cooked");
    return c;
}

int main() {
    int row = 1; 
    int col = 1;
    maze[row][col] = 'O';

    for (int i = 0; i < MAZE_HEIGHT; i++) {
        gotoXY(1, i+1);
        cout << maze[i] << endl;
    }
    while (true) {
        int key = keypress();

        if (key == 'd' && maze[row][col+1] != 'X') {
           maze[row][col] = ' '; 
            col++;
            maze[row][col] = 'O'; 
        } else if (key == 'a' && maze[row][col-1] != 'X') {
            maze[row][col] = ' '; 
            col--;
            maze[row][col] = 'O';
        } else if (key == 'w' && maze[row-1][col] != 'X') {
            maze[row][col] = ' '; 
            row--;
            maze[row][col] = 'O';
        } else if (key == 's' && maze[row+1][col] != 'X') {
         maze[row][col] = ' '; 
            row++;
            maze[row][col] = 'O';
        }

      system("clear"); 
        for (int i = 0; i < MAZE_HEIGHT; i++) {
            gotoXY(1, i+1);
            cout << maze[i] << endl;
        }
    }

    return 0;
}