#include "state_machine.h"
#include "config.h"

#define DEBUG_STATE		0

void initialize_state_machine(state_t *handle, STATE_NAME initial_state,
							state_transition_t * const *to_states,
							state_handler_t * const *in_states,
							state_transition_t * const *from_states,
							unsigned int *timestamp_table,
							const unsigned int *interval_table) {

	/* Set initial state */
	handle->prev_state = initial_state;
	handle->curr_state = initial_state;
	handle->next_state = initial_state;

	/* Setup table pointers */
	handle->to_state_table = to_states;
	handle->in_state_table = in_states;
	handle->from_state_table = from_states;

	/* Timestamp table for control over event frequency */
	handle->state_timestamp_table = timestamp_table;
	handle->event_interval_table = interval_table;

	/* No flags, no state change assertion */
	handle->change_state = false;
	handle->flags = POWER_ON;
}

void state_machine_handler(state_t *handle) {

	/* Enter state handler */
	if(check_interval(handle->curr_state)) {
#if DEBUG_STATE
		print_time();
		printf("%s (message: %s)\r\n", state_strings[handle->curr_state], (handle->curr_state == FAULT) ? fault_message : "none");
#endif
		handle->in_state_table[handle->curr_state](handle->flags);
	}

	/* Check if we are transitioning */
	if (handle->change_state) {

		handle->change_state = false;

		/* see if any action is necessary */
		if (handle->curr_state == handle->next_state)
			return;

#if DEBUG_STATE
		printf("%s -> %s\r\n",
			state_strings[handle->next_state],
			state_strings[handle->curr_state]);
#endif

		/* call state exit function */
		handle->from_state_table[handle->curr_state](handle->next_state, handle->flags);

		/* call state entrance function */
		handle->to_state_table[handle->next_state](handle->curr_state, handle->flags);

		/* update state information */
		handle->prev_state = handle->curr_state;
		handle->curr_state = handle->next_state;
	}
}

int check_interval(STATE_NAME state) {
	if (!(ticks % GET_INTERVAL(state)) && ticks != GET_TIMESTAMP(state)) {
		SET_TIMESTAMP(state);
		return 1;
	}
	return 0;
}

const char *state_strings[] = {
	"FAULT", "IDLE", "READY", "PUSHING", "COAST", "BRAKING"
};

