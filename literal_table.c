#include "literal_table.h"

// Return the size (in words/entries) in the literal table
unsigned int literal_table_size()
{
	bail_with_error("TODO: no implementation of literal_table_size yet!");
	return 0;
}

// is the literal_table empty?
bool literal_table_empty()
{
	bail_with_error("TODO: no implementation of literal_table_empty yet!");
	return false;
}

// is the literal_table full?
bool literal_table_full()
{
	bail_with_error("TODO: no implementation of literal_table_full yet!");
	return false;
}

// initialize the literal_table
void literal_table_initialize()
{
	bail_with_error("TODO: no implementation of literal_table_initialize yet!");
}

// Return the offset of sought if it is in the table,
// otherwise return -1.
int literal_table_find_offset(const char *sought, word_type value)
{
	bail_with_error("TODO: no implementation of literal_table_find_offset yet!");
	return 0;
}

// Return true just when sought is in the table
bool literal_table_present(const char *sought, word_type value)
{
	bail_with_error("TODO: no implementation of literal_table_present yet!");
	return false;
}

// Return the word offset for val_string/value
// entering it in the table if it's not already present
unsigned int literal_table_lookup(const char *val_string, word_type value)
{
	bail_with_error("TODO: no implementation of literal_table_lookup yet!");
	return 0;
}

// === iteration helpers ===

// Start an iteration over the literal table
// which can extract the elements
void literal_table_start_iteration()
{
	bail_with_error("TODO: no implementation of literal_table_start_iteration yet!");
}

// End the current iteration over the literal table.
void literal_table_end_iteration()
{
	bail_with_error("TODO: no implementation of literal_table_end_iteration yet!");
}

// Is there another literal in the literal table?
bool literal_table_iteration_has_next()
{
	bail_with_error("TODO: no implementation of literal_table_has_next yet!");
	return false;
}

// Return the next word_type in the literal table
// and advance the iteration
word_type literal_table_iteration_next()
{
	bail_with_error("TODO: no implementation of literal_table_iteration_next yet!");
	return NULL;
}
