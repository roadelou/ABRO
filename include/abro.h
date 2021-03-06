/* Include once header guard */
#ifndef YOUR_HEADER_GUARD
#define YOUR_HEADER_GUARD

/********************************** METADATA **********************************/

/*
* Contributors: roadelou
* Contacts: 
* Creation Date: 2021-03-06
* Language: C Header
*/

/********************************** INCLUDES **********************************/

/* The includes for your header go here */

/*********************************** MACROS ***********************************/

/* The macros definitions for your header go here */

/********************************** STRUCTS ***********************************/

/* The enums of your header go here */

/* The structs of your header go here */

/* The unions of your header go here */

/* The typedefs of your header go here */

/********************************* PROTOTYPES *********************************/

// Performs one "tick" of the ABRO state machine.
// Should be called in a "while (1)" loop by the main.
int abro(const int *A, const int *B, const int *R, int *C);

/* End of include once header guard */
#endif

/************************************ EOF *************************************/
