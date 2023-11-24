// Gael Adames, Kensley Cadet, Carlos Gonzalez

#include <stdlib.h>
#include <string.h>

#include "literal_table.h"
#include "symtab.h"
#include "utilities.h"

#define MAX_TABLE_SIZE 32

typedef struct Node
{
	char *data;
	struct Node *next;
} Node;

typedef struct LitTab
{
	// where the values are stored
	Node **arr;
	unsigned int size;
} LitTab;

// literal table is in the form of an array
LitTab *table;

// functions for linked list manipulation
Node *table_create_node(Node *curr, const char *data, word_type value);
void table_add(const char *data, word_type value);
bool table_search_key(const char *key);
bool table_search_word(word_type value);
Node *table_destroy();

Node *table_create_node(Node *curr, const char *data, word_type value)
{
	curr = malloc(sizeof(Node));
	curr->data = malloc(sizeof(char) * (sizeof(data) + 1));
	strcpy(curr->data, data);
	curr->value = value;

	return curr;
}

void table_add(const char *data, word_type value)
{
	table->arr[table->size] = table_create_node(table->arr[table->size], data, value);

	table->size++;
}

bool table_search_key(const char *key)
{
	if (literal_table_empty()) return false;
	
	int i;
	for (i = 0; i < literal_table_size(); i++)
		if (!strcmp(key, table->arr[i])) 
			return true;

	return false;
}

bool table_search_word(word_type value)
{
	if (literal_table_empty()) return false;
	
	int i;
	for (i = 0; i < literal_table_size(); i++)
		if (table->arr[i] == value)
			return true;

	return false;
}

Node *table_destroy(Node *head)
{
	int i;
	for (i = 0; i < literal_table_size(); i++)
	{
		free(table->arr[i]->data);
		free(table->arr[i]);
	}

	free(table->arr);
	free(table);
	return NULL;
}

// ========== BEGINNING OF LITERAL TABLE FUNCTIONS ==========

// Return the size (in words/entries) in the literal table
unsigned int literal_table_size()
{
	return table->size;
}

// is the literal_table empty?
bool literal_table_empty()
{
	return (table->size == 0) ? true : false;
}

// is the literal_table full?
bool literal_table_full()
{
	return (table->size >= MAX_TABLE_SIZE) ? true : false;
}

// initialize the literal_table
void literal_table_initialize()
{
	table = calloc(1, sizeof(List));
	table->arr = malloc(sizeof(Node*) * MAX_TABLE_SIZE);

	// initialize from BOF's data section
}

// Return the offset of sought if it is in the table,
// otherwise return -1.
int literal_table_find_offset(const char *sought, word_type value)
{
	// sought not in table, return -1
	if (!table_search_key(sought)) return -1;
	
	id_use *ret = symtab_lookup(sought);

	return ret->attrs->offset_count;
}

// Return true just when sought is in the table
bool literal_table_present(const char *sought, word_type value)
{
	return table_search_key(sought) || table_search_word(value);
}

// Return the word offset for val_string/value
// entering it in the table if it's not already present
unsigned int literal_table_lookup(const char *val_string, word_type value)
{
	// if not in table, add it
	if (!literal_table_present(val_string, value))
	{
		table_add(val_string, value);
	}

	return literal_table_find_offset(val_string, value);
}

/*
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
*/
