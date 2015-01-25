/*
 * In The Name Of God
 * ========================================
 * [] File Name : users.c
 *
 * [] Creation Date : 25-01-2015
 *
 * [] Last Modified : Sun 25 Jan 2015 07:14:54 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <glib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "message.h"
#include "users.h"

static GHashTable *users = NULL;

int main()
{
	printf("start\n");

	init_user();
	struct message *m1 = malloc(sizeof(struct message));
	strcpy(m1->dest_id, "12345");
	add_user(m1, 1);
	free(m1);

	struct message m2;
	strcpy(m2.dest_id, "12345");
	snd_user(&m2, 2);
}

/*
 * @ typedef const void *gconstpointer
 * An untyped pointer to constant data. The data pointed to should not be changed.
 * This is typically used in function prototypes to indicate that the data pointed
 * to will not be altered by the function.
 *
 * @ typedef gint gboolean
 * A standard boolean type.
 * Variables of this type should only contain the value TRUE or FALSE.
 *
 * @ typedef void* gpointer
 * An untyped pointer. gpointer looks better and is easier to use than void*.
*/

static void destroy_key(gpointer data)
{
	g_free(data);
}

static void destroy_value(gpointer data)
{
	g_free(data);
}

void init_user(void)
{
	users = g_hash_table_new_full(NULL, g_str_equal, destroy_key, destroy_value);
}

void add_user(const struct message *message, int socket)
{
	int *fd;

	fd = g_hash_table_lookup(users, message->dest_id);
	if (fd) {
		printf("%d\n", *fd);
	} else {
		g_hash_table_insert(users,
				g_strdup(message->dest_id), g_memdup(&socket, sizeof(socket)));
	}
}

void del_user(const struct message *message, int socket)
{
}

void snd_user(const struct message *message, int socket)
{
	int *fd;
	
	fd = g_hash_table_lookup(users, message->dest_id);
	if (fd)
		printf("%d\n", *fd);
	else
		printf("Not Found\n");

