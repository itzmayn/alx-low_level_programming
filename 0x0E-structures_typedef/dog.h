#ifndef DOG_H
#define DOG_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct dog - a new type of data representing a dog
 * @name: name of dog
 * @age: age of dog
 * @owner: owner's name
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/**
 * dog_t - Typedef for struct dog
 */
typedef struct dog dog_t;

/**
 * init_dog - Initializes a struct dog with given values
 * @d: Pointer to struct dog
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Owner's name
 */
void init_dog(struct dog *d, char *name, float age, char *owner);

/**
 * print_dog - Prints the details of a struct dog
 * @d: Pointer to struct dog
 */
void print_dog(struct dog *d);

/**
 * new_dog - Creates a new struct dog with given values
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Owner's name
 * Return: Pointer to the new struct dog
 */
dog_t *new_dog(char *name, float age, char *owner);

/**
 * free_dog - Frees the memory allocated for a struct dog
 * @d: Pointer to struct dog
 */
void free_dog(dog_t *d);

/**
 * _strlen - Computes the length of a string
 * @str: Pointer to string
 * Return: Length of the string
 */
int _strlen(char *str);

/**
 * _strcopy - Copies a string to a destination buffer
 * @dest: Destination buffer
 * @src: Source string
 * Return: Pointer to the destination buffer
 */
char *_strcopy(char *dest, char *src);

#endif
