/********************************** METADATA **********************************/

/*
 * Contributors: roadelou
 * Contacts:
 * Creation Date: 2021-03-06
 * Language: C Source
 */

/********************************** INCLUDES **********************************/

// Used to access the ABRO automaton.
#include <abro.h>

// Used to interact with the user.
#include <stdio.h>

/********************************* PROTOYPES **********************************/

/* The prototypes of your functions go here. */

/************************************ MAIN ************************************/

int main(int argc, const char **argv) {
    // We declare the input signals for the ABRO module.
    int A, B, R, O;

    // Used to hold the user input.
    int user_char = 0;

    // We start the event loop. We use this loop to interact with the user.
    // Here, because the only interaction with the outside is done throught the
    // user, we will only do a cycle when the user sends an input.
    do {
        // Resetting all signals.
        A = 0;
        B = 0;
        R = 0;
	O = 0;

        // If the user sent a known signal, we register its value.
        switch (user_char) {
        case 'A':
            A = 1;
            break;
        case 'B':
            B = 1;
            break;
        case 'R':
            R = 1;
            break;
	case '\n':
	    // This is the newline after each input character, we should skip it entirely.
	    continue;
	    break;
        case 0:
            // That is the initial value, not set by the user, and not a valid
            // keystroke, so we skip it.
            break;
        // The user cannot set O, it is an output signal.
        default:
            // Error feedback.
            fprintf(stderr, "Unknown signal %c\n", user_char);
            break;
        }

        // We perform one cycle in the ABRO state machine.
        abro(&A, &B, &R, &O);

        // We print all the signals back to the user.
        printf("Current signals: (A, %d), (B, %d), (R, %d), (O, %d)\n", A, B, R,
               O);

	// Small message to invite the user input.
	putchar('>');
	putchar('>');
	putchar(' ');

    } while ((user_char = getchar()) != EOF);
}

/********************************* FUNCTIONS **********************************/

/* The functions for your code go here. */

/************************************ EOF *************************************/
