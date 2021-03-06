/********************************** METADATA **********************************/

/*
 * Contributors: roadelou
 * Contacts:
 * Creation Date: 2021-03-06
 * Language: C Source
 */

/********************************** INCLUDES **********************************/

// The header we are trying to implement.
#include <abro.h>

/********************************* PROTOYPES **********************************/

// We declare here the states of the machine, since they have to persist between
// calls.
//
// This is the global state of the machine. It corresponds to the implicit
// "Sequential" execution of the module. In ABBRO there is only one part to this
// implicit sequence (the "loop ... each ...") but there could be several
// statements.
static int sequential_module = 0;
// This is the state created by the sequence (i.e. the ";" inside of the main
// loop).
static int sequential_in_loop = 0;
// This is the state created by the "Parallel" in ABRO, which waits until all
static int parallel_joined = 0;
// the threads are joined. This is the state created by "await A".
static int awaited_A = 0;
// This is the state created by "await B.
static int awaited_B = 0;

/************************************ MAIN ************************************/

/* The main function of your code goes here. */

/********************************* FUNCTIONS **********************************/

int abro(const int *A, const int *B, const int *R, int *C) {
    // First we check the state of the module. There is only 1 state, we always
    // are inside of the "loop ... each ...".
    switch (sequential_module) {
    case 0:
        // We are now inside of the loop, we have to check the reset first.
        if (*R) {
            // We reset all the states owned by the for loop, i.e. below in the
            // AST.
            sequential_in_loop = 0;
            awaited_A = 0;
            awaited_B = 0;
        } else {
            // The loop was not reset this cycle, we may go into the
            // "Sequential" block.
            switch (sequential_in_loop) {
            case 0:
                // We are at the beginning of the sequence, in the awaits.
                //
                // We are now in "await A", which updates the state awaited_A,
                // unless the state is already set. This leads to the boolean
                // equation:
                awaited_A = awaited_A || *A;
                // We are now in "await B", which is similar to "await A".
                awaited_B = awaited_B || *B;
                // We are back in the "Parallel", which binds to the "||" in
                // Esterel. We may only move to the next state if all the states
                // below us are passed.
                parallel_joined = awaited_A && awaited_B;
                // We are now back in the "Sequential", and we move to the next
                // step if all the states of the statefull children were passed.
                // There is only a single statefull child (the "Parallel"), so
                // the consition to move to the next state is.
                sequential_in_loop = parallel_joined;
                // End of first "Sequential" sub-block.
                break;
            case 1:
                // We are at the end of the sequence, in "emit C".
                //
                // We enter the emission. There isn't much to do ere, we just
                // emit C.
                *C = 1;
                // We are back in the "Sequential", we move on to the next state
                // once all our stateful children are done. But we have no
                // stateful children here, so we are stuck, there is no
                // condition for going to the next state.
                //
                // End of second "Sequential" sub-block.
                break;
            }
        }
        // We are back in the implicit "Sequential" of the module. We move on to
        // the next state once all our stateful children are done. The loop
        // isn't statefull, hence we have no condition for moving to the next
        // state, and we are stuck.
        //
        // End of first implicit "Sequential" sub-block.
    }
    // End of function, returning flow to the main.
    return 0;
}

/************************************ EOF *************************************/
