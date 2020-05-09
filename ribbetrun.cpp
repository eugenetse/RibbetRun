#include <iostream>
#include <limits>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <sys/ioctl.h>
#include <termios.h>
#include <ctime>

using namespace std;
#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

int tree_xpos=80;	//Tree position
int tree_height=3;	//Tree height (to be randomly changed
int tree2_xpos=80;
int tree2_height=4;
int speed=3000;
int g=0;

//Function to draw first tree at x from left, y from top
void tree(int x,int y, int h) {
  gotoxy(x, y);
  printf("\033[1mH\033[0m");
  for (int i=0; i<h; i++) {
    gotoxy(x, y-(i+1));
    printf("\033[1mH\033[0m");
  }
  gotoxy(x, y-h);
  printf("\033[1m^\033[0m");
  return;
}

//Function to erase first tree at x, y
void untree(int x,int y, int h) {
  gotoxy(x, y);
  printf(" ");
  for (int i=0; i<h; i++) {
    gotoxy(x, y-(i+1));
    printf(" ");
  }
  gotoxy(x, y-h);
  printf(" ");
  return;
}

//Function to draw second tree at x from left, y from top
void tree2(int x,int y, int h) {
  gotoxy(x, y);
  printf("\033[1mH\033[0m");
  for (int i=0; i<h; i++) {
  	gotoxy(x, y-(i+1));
  	printf("\033[1mH\033[0m");
  }
  gotoxy(x, y-h);
  printf("\033[1m^\033[0m");
  return;
}

//Function to erase second tree at x, y
void untree2(int x,int y, int h) {
  gotoxy(x, y);
  printf(" ");
  for (int i=0; i<h; i++) {
  	gotoxy(x, y-(i+1));
    	printf(" ");
  }
  gotoxy(x, y-h);
  printf(" ");
  return;
}

//Delay function for controlling speed, t = 2000 to 5000 reasonable
void wait(int t) {
       for (int i=0; i<10*t; i++) {
           gotoxy(1,1);
           printf(" ");
       } 
       return;
}

//Function to move first tree one step to left at delay t (speed)
void movetree(int t) {
  if (tree_xpos == 0) {
	untree(0, 20, 4);
	tree_xpos=80;
	tree_height=(rand()%3)+2;
	tree(80, 20, tree_height);
	wait(t);
	}
  if (tree_xpos>0) {
	untree(tree_xpos, 20, 4);
	tree_xpos--;
  	tree(tree_xpos, 20, tree_height);
	wait(t);
	}
  gotoxy(1,1);
  return;
} 

//Function to move second tree one step to left at delay t (speed)
void movetree2(int t) {
  if (tree2_xpos == 0) {
	untree2(0, 20, 4);
	tree2_xpos=80;
	tree2_height=(rand()%3)+2;
	tree2(80, 20, tree2_height);
	wait(t);
	}
  if (tree2_xpos>0) {
	untree2(tree2_xpos, 20, 4);
	tree2_xpos--;
  	tree2(tree2_xpos, 20, tree2_height);
	wait(t);
	}
  gotoxy(1,1);
  return;
} 

//Draw green frog at y from top
void thefrog(int y) {
	gotoxy(19, y);
	printf("\033[0;32m8 8\033[0m");
	gotoxy(19, y-1);
  	printf("\033[0;32m( )\033[0m");
	gotoxy(19, y-2);
	printf("\033[0;32m OO\033[0m");
	return;
}

// Frog jumps while trees keep moving
void upfrog(int h) {
	bool random_range(void);
	for(int i=0; i<h; i++) {
		thefrog(20-i);
		wait(speed);	
		gotoxy(19,20-i);
		printf("   ");
		movetree(speed);			//First tree moves
		if (random_range()) movetree2(speed);	//Second tree moves
	}
	for(int i=0; i<h; i++) {
		thefrog(21-h+i);
		wait(speed);
		gotoxy(19,21-h+i-3);
		printf("   ");
		movetree(speed);			//First tree moves
		if (random_range()) movetree2(speed);	//Second tree moves
	}
}

//Test collision condition
bool collision(int jump) {
        bool collide = false;
	int lower_x, upper_x;
	//Define boundaries of collision
	if (jump==1) {  	//while jumping
		lower_x = 14;
		upper_x = 23;
	}
	else {			//not jumping
		lower_x = 17;
		upper_x = 23;
	}
	if (tree_xpos<upper_x && tree_xpos>lower_x) collide=true;
	if (tree2_xpos<upper_x && tree2_xpos>lower_x) collide=true;
	return(collide); 
}

//Function to set random_distance of second tree from first tree
bool random_range() {
  int random_dist[5];
  int k=0;
  bool in_range=false;
  //Set 5 random distances between trees, either 30, 35, 40, 45, 50
  for(int i=0; i<5; i++) {
	random_dist[i] = 30 + 5*(rand()%5);
    	k = (g/80) % 5;
  }
  if (g%80 > random_dist[k]) in_range=true; //start at random distance
  if (tree2_xpos == 0) in_range=false; 	//stop when reached leftend
  if ((g/80)%3 == 1) in_range=true;  	//make sure trees not too far/close
  return(in_range);
}

//MAIN GAME PROGRAM
int main()
{
  bool detect_space(void);
  bool random_range(void);
  void disable_raw_mode(void);
  void resetTermios(void);
  long start_time;
  char c;
  int MAX_CYCLE=5000; 		//Set max cycles to 5000

  //Draw the welcoming screen:
  clear();
  gotoxy(20,10);
  printf("\033[0;31mW E L C O M E    T O    R I B B E T R U N !");
  gotoxy(20,12);
  printf("\033[0mP R E S S  [ R E T U R N ]  T O   S T A R T");
  c = getchar();  //Wait for user to hit RETURN
  if (c=='q') return 0;

  //NOW START THE GAME:
  game_starting_point:
  tree_xpos=80;
  tree2_xpos=80;
  clear();
  gotoxy(20,22);
  printf("\033[0;34m          Press [SPACE] to jump\033[0m");
  gotoxy(1,21);
  printf("-------------------------------------------------------------------------------");

  //Randomly set the tree heights to 2, 3 or 4
  tree_height = rand()%3 + 2;
  tree2_height = rand()%3 + 2;

  //Draw the frog and the tree initial positionsn
  //Frog at x=20 from left, y=20 from top
  //Tree at x=80 from left (rightmost), y=20 from top
  thefrog(20);
  tree(tree_xpos, 20, tree_height);
  start_time = time(NULL);		//set clock

  //START the loop, g is the step counter of the tree movement
  for(g=0; g<MAX_CYCLE; g++) {
	gotoxy(50,4);
	printf("Time elapsed: \033[1m%ld sec\033[0m", time(NULL)-start_time);
	gotoxy(50,5);
	printf("Steps moved: \033[1m%d steps\033[0m", g);

	//Start the loop to detect keystroke [space]
  	while (detect_space()) {
	 	upfrog(10); 	//Jump the frog
		gotoxy(1,1); 	//Hide the cursor
		// Check collision while jumping
		if (collision(1)) {
			gotoxy(35,11);
                	printf("\033[1mGame Over!\033[0m");
                	gotoxy(1,1);
                	gotoxy(17,12);
			printf("Press \033[1m[Return]\033[0m to restart or \033[1m[Control-C]\033[0m to quit.");
			disable_raw_mode();
			c = getchar();
			goto game_starting_point;
			}	
  		}
	//Keep trees moving regardless of keystroke
	movetree(speed*2);
	if (random_range()) movetree2(speed*2); 	//Second tree 
  	thefrog(20);			//Redraw the frog
  	gotoxy(1,1);			//Hide the cursor

	//Check collision while not jumping 
	if (collision(0)) {
		gotoxy(35,11);
		printf("\033[1mGame Over!\033[0m");
		gotoxy(1,1);
                gotoxy(17,12);
		printf("Press \033[1m[Return]\033[0m to restart or \033[1m[Control-C]\033[0m to quit.");
  		disable_raw_mode();
		c = getchar();
		goto game_starting_point;
	}
  }

  //Promote healthy playing, stop after MAX_CYCLE 
  gotoxy(20,12);
  printf("You've played too long. Go back to work!");
  gotoxy(1,1); 		//Hide the cursor
  disable_raw_mode();
  return 0;
}
