#include "hash_tables.h"

/**
 * set_pair - Allocates memory for a new key/value pair in the hash table.
 * @key: The key (a non-empty string).
 * @value: The value associated with the key (can be an empty string).
 *
 * Return: Pointer to the new node.
 */
hash_node_t *set_pair(const char *key, const char *value)
{
	hash_node_t *node = malloc(sizeof(hash_node_t));

	if (node == NULL)
		return (NULL);

	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(node);
		return (NULL);
	}

	node->value = strdup(value);
	if (node->value == NULL)
	{
		free(node->key);
		free(node);
		return (NULL);
	}

	return (node);
}

/**
 * set_pair_only - Adds a key/value pair to the first element of the array.
 * @ht: Pointer to the hash table.
 * @key: The key (a non-empty string).
 * @value: The value associated with the key (can be an empty string).
 * @index: The index of the key.
 *
 * Return: 1 on success, 0 on failure.
 */
int set_pair_only(hash_table_t *ht, const char *key,
		  const char *value, unsigned long int index)
{
	hash_node_t *node = set_pair(key, value);

	if (node == NULL)
		return (0);

	node->next = NULL;
	ht->array[index] = node;
	return (1);
}

/**
 * hash_table_set - Adds an element to the hash table.
 * @ht: Pointer to the hash table.
 * @key: The key (a non-empty string).
 * @value: The value associated with the key (can be an empty string).
 *
 * Return: 1 on success, 0 on failure.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *node;

	if (key == NULL || ht == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	if (node == NULL)
		return (set_pair_only(ht, key, value, index));

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
		{
			if (strcmp(node->value, value) == 0)
				return (1);

			free(node->value);
			node->value = strdup(value);

			if (node->value == NULL)
				return (0);

			return (1);
		}
		node = node->next;
	}

	if (node == NULL)
	{
		node = set_pair(key, value);

		if (node == NULL)
			return (0);

		node->next = ht->array[index];
		ht->array[index] = node;
		return (1);
	}

	return (0);
}
