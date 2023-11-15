#include "literal_table.h"

// Return the size (in words/entries) in the literal table
unsigned int literal_table_size()
{
	return 0;
}

// is the literal_table empty?
bool literal_table_empty()
{
	return false;
}

// is the literal_table full?
bool literal_table_full()
{
	return false;
}

// initialize the literal_table
void literal_table_initialize()
{

}

// Return the offset of sought if it is in the table,
// otherwise return -1.
int literal_table_find_offset(const char *sought, word_type value)
{
	return 0;
}

// Return true just when sought is in the table
bool literal_table_present(const char *sought, word_type value)
{
	return false;
}

// Return the word offset for val_string/value
// entering it in the table if it's not already present
unsigned int literal_table_lookup(const char *val_string, word_type value)
{
	return 0;
}

// === iteration helpers ===

// Start an iteration over the literal table
// which can extract the elements
void literal_table_start_iteration()
{

}

// End the current iteration over the literal table.
void literal_table_end_iteration()
{

}

// Is there another literal in the literal table?
bool literal_table_iteration_has_next()
{
	return false;
}

// Return the next word_type in the literal table
// and advance the iteration
word_type literal_table_iteration_next()
{
	return NULL;
}
