#include <stdio.h>

// The style struct will contain the ANSI color codes
typedef struct Style_struct
{
    const char black[15],
        red[15],
        green[15],
        yellow[15],
        blue[15],
        magenta[15],
        cyan[15],
        white[15],
        underline[15],
        reset[15],
        clear[15];
} Style;

// Static Initialization outside of main()
Style colorStyle = {"\033[30m",       // black
                    "\033[31m",       // red
                    "\033[32m",       // green
                    "\033[33m",       // yellow
                    "\033[34m",       // blue
                    "\033[35m",       // magenta
                    "\033[36m",       // cyan
                    "\033[37m",       // white
                    "\033[4m",        // underline
                    "\033[0m",        // reset
                    "\033[H\033[2J"}; // clear

/*
  You Must Declare the struct and Initialize it on the same line.  You cannot initialize the struct variables outside of declaration if it is a static struct
*/
