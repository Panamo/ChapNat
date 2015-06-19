/*
 * In The Name Of God
 * ========================================
 * [] File Name : users.c
 *
 * [] Creation Date : 18-05-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#include <glib.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "message.h"
#include "net.h"
#include "users.h"
#include "chobj.h"
#include "common.h"

static GHashTable *users;

/*
 * @ typedef const void *gconstpointer
 * An untyped pointer to constant data.
 * The data pointed to should not be changed.
 * This is typically used in function prototypes to indicate
 * that the data pointed to will not be altered by the function.
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
	chobj_del(data);
}

void init_user(void)
{
	users = g_hash_table_new_full(g_str_hash, g_str_equal, destroy_key,
		destroy_value);
}

void add_user(const struct message *message, int socket)
{
	struct chobj *new;
	struct sockaddr_in client_addr;
	socklen_t len = 0;

	getsockname(socket, (struct sockaddr *) &client_addr, &len);
	new = g_hash_table_lookup(users, message->dest_id);
	if (new) {
		ulog("Found\n");
	} else {
		ulog("%s is added\n", message->dest_id);
		new = chobj_new(message->dest_id, socket, client_addr);
		g_hash_table_insert(users, g_strdup(message->dest_id), new);
	}
}

void del_user(const char *id)
{
	g_hash_table_remove(users, id);
}

void snd_user(const struct message *message, int socket)
{
	struct chobj *new;

	new = g_hash_table_lookup(users, message->dest_id);
	if (new) {
		ulog("sned to %s\n", new->id);
		send_message(message, new->fd);
	} else {
		ulog("Not Found\n");
	}
}
