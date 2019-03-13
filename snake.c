#include <ncurses.h>
#include <stdio.h>

bool gameOver;
const int W = 40;
const int H = 20;
int x,y,fruitX,fruitY;
long snake;


void Snake(){

for (int i=0;i<W;i++){
for (int j=0;j<H;j++) {
     if((i == W/2) && (j == H/2)){
        printw("*");
        refresh();
     }
     
     }
     
     
}



}


void Draw(){
   
   for (int i=0;i<W+1;i++) {
       printw("#");
       
}
   printw("\n");
   

for (int i=0;i<H;i++){
for (int j=0;j<W;j++) {
     if(j == 0 || j == W-1){
        printw("#");
     }
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






int main(){
  initscr();
  
  Draw();
  Snake();
  endwin();
}
