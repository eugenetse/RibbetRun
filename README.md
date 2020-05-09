# RibbetRun<br/>
Made by:<br/>
TSE I Ching Eugene, UID: 3035608215, Subclass G<br/>

## Game Description<br/>
RibbetRun is an obstacle dodging game. The single player controls Ribbet the Frog. Press the return key to start the game. Press spacebar to jump. Players must avoid all the trees (obstacles) on the path by jumping. If the player hits a tree, they lose and the game ends. The aim is to last in the game as long as possible. Players’ progress is based on time elapsed and steps moved.

## Features and Functions:<br/>

ribbetrun.cpp contains the following:<br/>

* tree(int x,int y, int h)
  * Function to draw first tree at x from left, y from top

* untree(int x,int y, int h)
  * Function to erase first tree at x, y
  
* tree2(int x,int y, int h)
  * Function to draw second tree at x from left, y from top
  * Creates illusion that trees are sequentially coming. Actually using two trees.
  
* untree2(int x,int y, int h)
  * Function to erase second tree at x, y
  
* wait(int t)
  * Delay function for controlling speed, t = 2000 to 5000 reasonable

* movetree(int t)
  * Function to move first tree one step to left at delay t (speed)
  
* movetree2(int t)
  * Function to move second tree one step to left at delay t (speed)
  
* thefrog(int y)
  * Draw green frog (Ribbet) at y from top
  
* upfrog(int h)
  * Frog jumps while trees keep moving
  
* collision(int jump)
  * Test collision condition

* random_range()
  * Function to set random_distance of second tree from first tree

* main()

  * Main function of game

  * Declare functions such as detect_space(void) and random_range(void)
  
  * Set max cycles to 5000
  
  * Draw the welcoming screen
  
  * Wait for user to hit RETURN
  
  * Starts game
  
  * Randomly set the tree heights to 2, 3 or 4
  
  * Draw the frog and the tree initial positions
  
  * Starts the loop. Detects keystroke, or keep trees moving regardless of keystroke
  
  * Check collision while not jumping
  
  * Stops after MAX_CYCLE, display final message.
  
tree_height and random_range both use **randomization** to generate values.<br/>

Program codes are in **multiple files**.<br/>

Data structures: kbhit.cpp uses the static **struct** termios old, current.<br/>

Used in kbhit.cpp:<br/>

* initTermios(int echo)

* resetTermios()

* enable_raw_mode()

* disable_raw_mode()

* kbhit()

* detect_space()
