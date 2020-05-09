#include <iostream>
#include <chrono>
#include <thread>
#include <sys/ioctl.h>
#include <termios.h>

static struct termios old, current;

/* Initialize new terminal i/o settings */
void initTermios(int echo)
{ 
	tcgetattr(0, &old); /* grab old terminal i/o settings */ 
 	current = old; /* make new settings same as old settings */
	current.c_lflag &= ~ICANON; /* disable buffered i/o */
  	if (echo) {
      		current.c_lflag |= ECHO; /* set echo mode */
  	}
	else {
      		current.c_lflag &= ~ECHO; /* set no echo mode */
  	}
  	tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
}

void resetTermios()
{ 
  	tcsetattr(0, TCSANOW, &old);
}

void enable_raw_mode()
{
    	termios term;
    	tcgetattr(0, &term);
    	term.c_lflag &= ~(ICANON | ECHO); // Disable echo as well
    	tcsetattr(0, TCSANOW, &term);
}

void disable_raw_mode()
{
    	termios term;
    	tcgetattr(0, &term);
    	term.c_lflag |= ICANON | ECHO;
   	tcsetattr(0, TCSANOW, &term);
}

int kbhit()
{
    	static const int STDIN = 0;
    	static bool initialized = false;

    	if (! initialized) {
        	// Use termios to turn off line buffering
        	termios term;
        	tcgetattr(STDIN, &term);
        	term.c_lflag &= ~ICANON;
        	tcsetattr(STDIN, TCSANOW, &term);
        	setbuf(stdin, NULL);
        	initialized = true;
    	}

    	int bytesWaiting;
    	ioctl(STDIN, FIONREAD, &bytesWaiting);
    	return bytesWaiting;
}

bool detect_space()
{
	char c='.';
	bool detect=false;
	enable_raw_mode();
	if (kbhit()) {
		initTermios(0); //No echo. Very important to mimic getch()
		c = getchar();
		resetTermios(); //Very important to mimic getch()
	}
	if (c==' ') detect=true;
	//resetTermios();
	return(detect);
}
