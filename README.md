# RibbetRun<br/>
Made by:<br/>
TSE I Ching Eugene, UID: 3035608215, Subclass G<br/>

## Game Description<br/>
RibbetRun is an obstacle dodging game. The single player controls Ribbet the Frog. Press the return key to start the game. Press spacebar to jump. Players must avoid all the trees (obstacles) on the path by jumping. If the player hits a tree, they lose and the game ends. The aim is to last in the game as long as possible. Players’ progress is based on time elapsed and steps moved.

## Compilation, Execution and Playing Instructions (also shown in video)<br/>
* Ensure you have all the files from this repository in your current directory/folder.<br/>
* Enter 'Make'.<br/>
* Enter './ribbetrun'.<br/>
* You will be greeted by a welcome screen. Press the return key to begin playing.<br/>
* Hit the spacebar to jump. Jump to avoid incoming trees<br/>
* If you hit a tree, you lose and the game is over. Press the return key to instantly restart the game.<br/>
* Or, you can press control+c to quit the game and return to shell.<br/>
* When Ribbet has reached 4999 steps (maximum progress), the game will end automatically and display an ending message.<br/>
* However it is possible for the game to lag significantly if played on a server (i.e. CS server) due to purely network-related speed issues. The screen and keyboard response time could possibly be slow. To solve this, I have made it possible to manually adjust the speed of the game - a lower "speed" value will mean a FASTER speed. **You may change/edit this in ribbetrun.cpp.**<br/>
* Recommended "speed" value for playing on a network is **500** (extra fast).<br/>
* Recommended value for playing locally on computer is **3000**.<br/>

## Features and Functions:<br/>

*Note: as discussed with TA Chun-Kiu, due to my original partner late-dropping the course recently and unexpectedly, and the fact that the workload was fully done by myself, I am required to satisfy half of the code requirements and implement half of the program features. To the best of my ability, I have managed to fulfil a majority of the original features, and have met code requirements 1, 2, 5, 6, and 7. (This is also written in my individual submission)*<br/>

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

Player's progress/"score" is quantified by time elapsed and steps moved. These are constantly updated in real-time during gameplay.<br/>

Program codes are in **multiple files**.<br/>

Data structures: kbhit.cpp uses the static **struct** termios old, current.<br/>

Used in kbhit.cpp:<br/>

* initTermios(int echo)

* resetTermios()

* enable_raw_mode()

* disable_raw_mode()

* kbhit()

* detect_space()
