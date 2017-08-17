#ifndef _STATE_MACHINE__H
#define _STATE_MACHINE__H

#include <stdint.h>
#include <stdbool.h>
#include "badgerloop.h" /* don't know how to not need this */

typedef void state_transition_t(STATE_NAME to_or_from, uint32_t flags);
typedef void state_handler_t(uint32_t flags);

typedef struct state {
	STATE_NAME curr_state;
	STATE_NAME prev_state;
	STATE_NAME next_state;
	volatile bool change_state;
	volatile uint32_t flags;
	state_transition_t * const *to_state_table;
	state_handler_t * const *in_state_table;
	state_transition_t * const *from_state_table;
} state_t;

extern const char *state_strings[];

/* State handling */
extern state_t state_handle;
extern state_transition_t * const to_handlers[];
extern state_handler_t * const in_handlers[];
extern state_transition_t * const from_handlers[];

void initialize_state_machine(state_t *handle, STATE_NAME initial_state,
							state_transition_t * const *to_states,
							state_handler_t * const *in_states,
							state_transition_t * const *from_states);
void state_machine_handler(state_t *handle);

#endif

