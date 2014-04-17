//***********************************************************************//
//																		 //
//		- "Talk to me like I'm a 3 year old!" Programming Lessons -		 //
//                                                                       //
//		$Author:		Ben Humphrey	digiben@gametutorials.com		 //
//																		 //
//		$Program:		Arrays										 	 //
//																		 //
//		$Description:	Print out random numbers with arrays and macro's.//
//																		 //
//		$Date:			6/5/00											 //
//																		 //
//***********************************************************************//

#include <iostream>							// This line of code is necessary to include all the C++ standard functions\classes definitions
#include <windows.h>						// This allows us to use the function Sleep() which is a delay
#include <time.h>							// We need to include this to call the time() function.  This is our first .h.  It's an old standard C header file.
using namespace std;						// Set our namespace to standard

#define MAX_NUMBERS 15						// This is called a define.  Usually the #defines go after the includes.
											// Typically, with defines.. they are ALL_CAPS and use underscores between words.
											// This lets the coder know that this is a define.  You might be asking.. why use define?
											// How are they difference from variables?  Well, variables allocate memory.
											// The line "int i;" asks the operating system (OS) for some memory so that it could hold a number.
											// Defines on the other hand, don't take any memory, but instead REPLACE where ever it's typed with it's definition.
											// In this case, you notice we use MAX_NUMBERS in our for loop.  Before the compiler compiles the code, it "secretly"
											// Goes and replaces the MAX_NUMBERS with 15.  Does that make sense?  It's literally as if we typed it our self.
											// In games and most any other coding, these are used a lot.  They are useful because ...
											// What if you use MAX_NUMBERS, a 100 times in your code?  What if want to change the number later?
											// All you have to do is go to the top of this file and change the 15 to what ever number you want.
											// If you had just typed 15, 100 times throughout your code, you would have to change them one by one.
											// Even though there is a find and replace in most applications, trust me... it doesn't always work out
											// Like you think it does.  If you have 50 different files for your project.. are you going to go and
											// Find and replace in ALL 50 files?  It's SOoOoOooO time consuming and tedious.  I learned the hard way :)
											
											// You can also use defines like this:
											// "#define PRINT_SCORE(score) cin << "Your score is " << score << "." << endl
											// If I type PRINT_SCORE(<a variable>) anywhere, it will substitute the cout statement and print the value of the variable passed in.
											// Like this: PRINT_SCORE(<a integer>) cout << "Your score is " << <a integer> << "." << endl
											// Do you get it?  It's like your own personalized cout!  
											// The bad thing with defines are.. if you have a syntax error (you didn't follow the compiler's rules)
											// They are HARD to trace.  Also, don't put a semicolon after the #define statement, since it is a literal replace where you use it.
											// In Fact, let's do a #define of PRINT_NUM()

#define PRINT_NUM(num) cout << num << endl	// See what I mean?  All this does is print the number passed into as "num" (num isn't the name, just the word to replace in the cout statement).
											// And go to the next line.  Simple huh?  You notice there isn't an "=" sign,...
											// Because #defines are just replacing text, not assigning values.  #define are also called MACROS.
											// We have successfully made our first macro.
											// Don't put a ; after the macro, you will do that when you call (in other words, use) the macro
									

void main()									// The beginning of our program
{											// This starts the main function
	int list[MAX_NUMBERS]={0}, i=0;			// Initialize the array of integers (numbers) and a counter "i".
											// This line says that we now have storage for MAX_NUMBERS (which is 15) integers.
											// If we didn't have arrays, we would have to do things like:
											// int i, i2, i3, i4, i5, i6, i7, i8, i9, etc... and who wants to do that?? (besides the freak who just raised his hand :) )
											// The = {0} sets all the slots\numbers in the array to 0.
	cout << "\nThe not so random list:\n\n"; // Display a word about the not random list.  notice the '\n' ...
											// We can insert this into a string and it does the same thing as endl;
											// We can put it anywhere in a string.  We must have the backslash in front of the n though.
											// This is a bit cleaner than << endl << endl;  As you will see, it won't print out: \n it will just go to a new line where it was in the string.  Try it.

	for(i=0; i < MAX_NUMBERS; i++)			// We call our for loop that will continue to print out MAX_NUMBERS (15) random numbers
	{										// Start the cycle if the expression in the middle is true.
		list[i] = rand();					// list[i] means, the slot "i" (which will start out as 0) in list gets a random number.
											// Say, the random number came out to be 2200.  In the beginning, since i = 0;  list[0] would equal 2200;
		PRINT_NUM(list[i]);					// If list[i] was 2200 , then PRINT_NUM() would print out 2200 to the screen.	
	}										// End of the cycle and check at the top if we need to continue.
		
											// The for loop will continue to go until i == 15.  Then it will stop.
											// Run this program again and you will notice that the numbers are the same every time.
	cout << "\nThe TRULY random list:\n\n";	// They are different from each other, but the same every time.
											// We need to "seed" the random number generator. To do this, we use time.
											// The computers internal clock will always be changing, so we start the random number on our systems time.
	srand( time ( NULL ) );					// srand() stands for "seed randomizer"  ... or something like that :)
											// We pass the function time() in with a NULL parameter.  We pass in NULL to time() because we don't care what format is returned.
											// We just passed a function into another function.  Time will return a number to the function srand() to seed rand().
											// Kinda complicated huh?  Well, not really but at first.

	Sleep(3000);							// This functions causes a delay for about 3 seconds.  1000 is ~ 1 second.  ~ means approximately.

											// Let's see that again...
	for(i=0; i < MAX_NUMBERS; i++)			// Now you'll notice the differences in numbers EVERYTIME .. or at least when the clock changes :)
	{											
		list[i] = rand();					// Randomize the new list
											
		PRINT_NUM(list[i]);					// Print out the randomized number.									
	}
											// Now we will restrict the random numbers so that we don't get numbers in the 10's of thousands.
											// Print the new title of numbers
	cout << "\nThe *restricted* TRULY random list:\n\n";

	Sleep(3000);							// Sleep for 3 seconds

	for(i=0; i < MAX_NUMBERS; i++)			// Now you'll notice the differences in numbers EVERYTIME .. or at least when the clock changes :)
	{											
		list[i] = rand() % 100;				// Randomize the new list with numbers less than 100.
											// using the modulus operator "%" we can restrict the random numbers to being less than 100;
											// Here is an example on how modulus works.  It's kinda like divide, except it returns the remainder of the divide instead
											// "  15 % 5 = 0,      15 % 7 = 1,    15 % 26 = 15 "
											// Can you see why?  it's the remainder.  15 / 5 = 3 with NO remainder, so 15 % 5 = 0
											// 15 / 7 has a remainder of 1.  15 % 26 returns 15 because anything being moded by a higher number, just returns that number that is being moded.
											
		PRINT_NUM(list[i]);					// Print out the randomized number.									
	}

}											// The end of the program

// *FUNCTIONS EXPLANATION*
//
// So far, in the C++ tutorials, we haven't really used or called a function.
// Sleep() is a function that does a delay.  A function always have parenthesis.
// Inside the parenthesis, you can pass in information to the function.
// In the case of Sleep(), you want to tell it how long to delay...
// So, we "pass in" the number 3000 like so:  Sleep(3000);
// Some functions don't take parameters inside the parenthesis.
// Like variables, functions are case sensitive, you need to use a capital S in this case.
// We will learn how to create our own functions later.

// � 2000-2003 GameTutorials