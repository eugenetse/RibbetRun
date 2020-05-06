# RibbetRun<br/>
Made by:<br/>
TSE I Ching Eugene, UID: 3035608215, Subclass G<br/>

## Game Description<br/>
RibbetRun is an infinite obstacle dodging game. The single player controls Ribbet the Frog. Press the spacebar or up key (↑) to start the game and to jump. Players must avoid all the trees (obstacles) on the path by jumping. If the player hits a tree, they lose and the game ends. The aim is to last in the game as long as possible. Players’ score is based on time elapsed and bonuses obtained. Players can also hit coins on the path, which will grant them bonus points.

## Features and Functions:<br/>
* main()

  * Main function of game

  * If current.status = 'S', the game will first ask for the player to input a username (all of the user's progress will be stored under this name in an external file). Then, if the user inputs ' ' or up key, then start game.

  * Else if current.status = 'P', then if user inputs ' ' or up key, then execute jump function.

  * Else if current.status = 'O', display the Game Over text. Then, if user inputs ' ' or up key, then start game.

* **Structure:** game_status

  * This represents the current status/mode of the game. The first member of this structure is a character type variable named "status", which can have three values: 'S' for starting screen, 'P' for playing, 'O' for game over.

  * Description of statuses: starting screen (only displayed upon initialization), playing, and game over (once Ribbet hits obstacle).

  * At start of game, initalize game_status current = { 'O' }

* Function: set_obstacle

  * Obstacles (trees) will start appearing from the right, at random frequencies.

  * The separation between obstacles will take a **random number of spaces** (tree_space). tree_space will be a **randomly generated number between the range of 10 and 20** (i.e. distance between obstacles will randomly range from 10 to 20 spaces).

* Function: set_coin

  * Coins will start appearing from the right regularly and much less frequently than trees.

  * The space separation between coins (coin_space) will constantly be equal to 100 (i.e. distance between obstacles will always be 100 spaces).

* Function: moveleft()

  * This is the action that "moves" a tree/coin leftwards towards Ribbet.

  * The action copies and stores a tree/coin into a temporary storage, then erases the tree/coin from their current position, and finally copies the tree/coin from the temporary storage into the neighboring space on its left.

* **Structure:** obstacle_type

  * Represents the characteristics of tree obstacles. Obstacles can be a single tree, group of two trees, or group of three trees. Obstacles' height can be short, medium and tall.

  * Hence, there are two members in this structure: width (integer type) and height (integer type)

  * Value of width can be 1, 2, or 3 (representing number of "trees" that comprise the obstacle), and value of height can be 2, 3, or 4 (representing number of spaces).

* Void function: jump

  * Instructs Ribbet to jump.

  * Ribbet will move upwards by a constant number of spaces, and fall downwards by the same number of spaces.

* Bool: hit_tree

  * Reports status of whether Ribbet has touched a tree.

  * By default from initialization, hit_tree = False. During the game (when current.status = 'P'), if Ribbet's location is in immediate vicinity of (i.e. immediately neighboring) a tree/obstacle, value of hit_tree will become True. This will change current.status to 'O'. After this has happened, hit_tree will revert back to False.

  * Output: return True, False

* Bool: hit_coin

  * Reports status of whether Ribbet has touched a coin.

  * By default from initialization, hit_coin = False. During the game (when current.status = 'P'), if Ribbet's location is in immediate vicinity of (i.e. immediately neighboring) a coin, value of hit_coin will become True. This will trigger bonus_score += 500 (add 500 bonus points). After this has happened, hit_coin will revert back to False.

  * Output: return True, False

* **Structure:** score

  * Members: stored_score (**dynamic variable**, integer type), real_time_score (integer type), time_score (integer type) and bonus_score (integer type). pt_score (integer type) is a pointer that will point to the stored_score dynamic variable.

  * The unit that member variables are based on is tenth of a second.

  * Two structure variables used: score current_score and score highscore.

  * current_score structure:

    * While current.status = 'P', time_score will be constantly updated every tenth of a second to show the number of tenths of seconds that have elapsed (e.g. after 10 seconds runtime, time_score will be 100).

    * bonus_score += 500 when hit_coin = True.

    * real_time_score will be time_score + bonus_score, constantly updated every tenth of a second for every change. real_time_score will also be printed after each update, to accurately reflect real-time score. When current.status = 'O', real_time_score will stop updating, and its value will be copied over (updated) to the stored_score dynamic variable using current_score structure's *pt_score.

    * Prior to updating stored_score, *pt_score = new int must be executed, and if stored_score's value already exists, pt_score's memory must be freed and reset first (delete pt_score; pt_score = 0;).

  * For highscore structure, only stored_score **dynamic variable** will be used (real_time_score set to 0). If the player is new (external file belonging to username is newly created) then the default highscore.stored_score is 0. Otherwise, the player's existing highscore will be retrieved from [username].txt using read_user_file function. When current.status = 'O', current_score.stored_score will be compared to highscore.stored_score. If current_score.stored_score > highscore.stored_score, highscore.stored_score will be updated to equal current_score.stored_score, using highscore structure's *pt_score, and the new value will be copied to the user's external file using write_user_file function. Otherwise, there will be no change in highscore. highscore.stored_score will also be printed after each update (initially it will be printed as 0).

    * Prior to updating stored_score, *pt_score = new int must be executed, and if stored_score's value already exists, pt_score's memory must be freed and reset first (delete pt_score; pt_score = 0;).

* Function: read_user_file **(file input)**

  * Given a username as input argument, this function opens the username's corresponding file and retrieves their highscore.

  * First, check if [username].txt exists. If not, then print a notification message and then set highscore.stored_score to 0 (file will be created in write_user_file function). If the file exists, read the highscore from the file and copy it into highscore.stored_score. The file will finally be closed.

* Function: write_user_file **(file output)**

  * Create/write to the user's designated external file, copying/updating the new highscore value.

  * If the file cannot be created due to error, an error message will be printed. Otherwise, any previous user highscore data in the file should be erased and replaced with the new highscore data. The file will finally be closed.
