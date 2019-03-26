#include <ncursesw/ncurses.h>
#include <stdio.h>
#include <stdlib.h>



bool gameOver;
const int W = 40;
const int H = 20;
int x,y,fruitX,fruitY;
enum eDirection {STOP = 0,LEFT,RIGHT,UP,DOWN} dir;


void Setup(){
     gameOver = false;
     dir = STOP;
     x = W/2 - 1;
     y = H/2 - 1;
     fruitX = rand() % W;
     fruitY = rand() % H;



}


void Draw(){
   system ("clear");
   for (int i=0;i<W+1;i++) {
       printw("#");
       
}
   printw("\n");
   

for (int i=0;i<H;i++){
for (int j=0;j<W;j++) {
     if(j == 0 || j == W-1){
        printw("#");
     }
     if (i == y && j == x) //вывод змейки
        printw("o");
     else if (j == fruitX && i == fruitY) //вывод фруктов
        printw("*");
     else
     printw(" "); 
     }
     printw("\n");
     
}

for (int i=0;i<W+1;i++) {
       printw("#");
}
   printw("\n");
refresh();
getch();
}

void setDirection (char c){
    //nodelay(stdscr, TRUE);
    switch (c){
    
    case 'a':
    dir = LEFT;
    break;
 
    case 'd':
    dir = RIGHT;
    break;

    case 'w':
    dir = UP;
    break;

    case 's':
    dir = DOWN;
    break;

    case 'x':
    gameOver = true;
    break;
    refresh();


}

}

void control(){
     switch(dir){
     
     case LEFT:
          x--;
     break;
     case RIGHT:
          x++;
     break;
     case UP:
          y--;
     break;
     case DOWN:
          y++;
     break;
     refresh();
}
}










int main(){

  char c;

  initscr();
  Setup();
  while (gameOver != true){
  Draw();
  
  control();
  
  timeout(110);
  c = getch();
  setDirection(c);
  clear();
  
  
  
  
  refresh();
}
  endwin();
}
