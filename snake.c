#include <ncursesw/ncurses.h>
#include <stdio.h>
#include <stdlib.h>



bool gameOver;
const int W = 40;
const int H = 20;
int x,y,fruitX,fruitY;
int hvostX[100],hvostY[100],NEWhwost;
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
     else{

        bool print = false;
        
        for(int k = 0;k < NEWhwost;k++){

            if (hvostX[k] == j && hvostY[k] == i){
                print = true;
                printw("+");
}
}
        if (!print)   
           printw(" "); 
}    
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
    nodelay(stdscr, TRUE);//от залипания
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


void pravila(){
     int prevX = hvostX[0];   
     int prevY = hvostY[0]; 
     int prev2X, prev2Y;
     hvostX[0] = x;
     hvostY[0] = y;
     //перемещение тела за головой
     for (int i=1;i < NEWhwost;i++){

     prev2X = hvostX[i]; 
     prev2Y = hvostY[i];
     hvostX[i] = prevX;
     hvostY[i] = prevY;
     prevX = prev2X;
     prevY = prev2Y;
}

     control();
     
     if (x >= W-1){
        x = 0;   
}else if (x < 0){
        x = W-2;
}

    if (y >= H){
        y = 0;   
}else if (y < 0){
        y = H -1;
}

     //если съел хвост
     for(int i=0;i<NEWhwost;i++){
         if(hvostX[i] == x && hvostY[i] == y){
            gameOver = true;
}
}

     if (x == fruitX && y == fruitY){
     
     fruitX = rand() % W;
     fruitY = rand() % H;
     NEWhwost++;
}
}

int main(){

  char c;

  initscr();
  Setup();
  while (gameOver != true){
  
  Draw();
    
  timeout(110);
  c = getch();
  setDirection(c);
  clear();
  
  
  pravila(); 
  
  refresh();
}
  endwin();
}
