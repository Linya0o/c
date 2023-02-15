#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct Address {
    int id;
    char name[10];
    char email[20];
    struct Address *next;
};

struct Database {
    struct Address *data;
};

struct Connection {
    FILE *file;
    struct Database *db;
};

void menu(void);
void terminate(const char *message);
void address_show(struct Address *addr);
struct Connection* database_connect(const char *filename);
void database_load(struct Connection* conn);
void database_write(struct Connection *conn);
void database_close(struct Connection *conn);
void database_list(struct Connection *conn);
void database_create(struct Connection *conn, int id,
        const char *name, const char *email);
void database_delete(struct Connection *conn, struct Address *target);
struct Address* database_get(struct Connection *conn, int id);
void database_set(struct Connection *conn, int id,
        const char *name, const char *email);

int main(int argc, char *argv[]) {
    if (argc < 2)
        terminate("Usage: main <dbfile>");
    const char *filename = argv[1];
    struct Connection *conn = database_connect(filename);
    menu();
    while (1) {
        char action;
        printf("Input your action: ");
        scanf(" %c", &action);
        switch (action) {
            case 'l':
                database_list(conn); break;
            case 's': {
                int id;
                char name[256] = { 0 }, email[256] = { 0 };
                printf("Please input the id, name, email: ");
                scanf("%d %s %s", &id, name, email);
                database_set(conn, id, name, email);
                break;
            }
            case 'g': {
                int id;
                printf("Please input the id: ");
                scanf("%d", &id);
                address_show(database_get(conn, id));
                break;
            }
            case 'd': {
                int id;
                printf("Please input the id: ");
                scanf("%d", &id);
                database_delete(conn, database_get(conn, id));
                break;
            }
            case 'h':
                menu(); break;
            case 'q':
                database_close(conn);
                exit(0);
            default: printf("no that action.\n"); break;
        }
    }

    return EXIT_SUCCESS;
}

void menu(void) {
    const char menu_string[] = {
        "#################################\n"
        "#       available actions       #\n"
        "#- q: quit                      #\n"
        "#- h: show action menu          #\n"
        "#- g: get one data entry        #\n"
        "#- s: set one data entry        #\n"
        "#- d: delete one data entry     #\n"
        "#- l: list the whole database   #\n"
        "#################################\n"
    };
    printf(menu_string);
}

void terminate(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void address_show(struct Address *addr) {
    if (addr == NULL) {
        printf("No data.\n");
        return;
    }
    printf("Id: %-6d, Name: %-10s, Email: %-20s\n",
            addr->id, addr->name, addr->email);
}

void database_list(struct Connection *conn) {
    assert(conn != NULL);

    struct Database *db = conn->db;
    struct Address *p = db->data;
    while (p) {
        address_show(p);
        p = p->next;
    }
    printf("No more data.\n");
}

struct Connection* database_connect(const char *filename) {
    struct Connection *conn = malloc(sizeof(*conn));
    if (!conn) terminate("Memory allocation failed.");

    *conn = (struct Connection) { 0 };

    conn->file = fopen(filename, "rb+");
    if (!conn->file) terminate("file cannot open.");

    conn->db = malloc(sizeof(struct Database));
    if (!conn->db) terminate("Memory allocation failed.");

    database_load(conn);
    return conn;
}

void database_load(struct Connection* conn) {
    assert(conn != NULL);

    char check = fgetc(conn->file);
    rewind(conn->file);
    if (check == EOF) {
        conn->db->data = NULL;
        return;
    }

    struct Address **tail = &conn->db->data;
    while (!feof(conn->file)) {
        struct Address *node = malloc(sizeof(*node));
        if (!node) terminate("Memory allocation failed.");

        int rc = fread(node, sizeof(struct Address), 1, conn->file);
        if (rc != 1) {
            free(node);
            break;
        }
        *tail = node;
        tail = &(*tail)->next;
    }
    *tail = NULL;
}

void database_write(struct Connection *conn) {
    assert(conn != NULL);

    rewind(conn->file);
    struct Address *p = conn->db->data;
    while (p) {
        int rc = fwrite(p, sizeof(struct Address), 1, conn->file);
        if (rc != 1) terminate("Failed to write database.");

        p = p->next;
    }
    int rc = fflush(conn->file);
    if (rc == EOF) terminate("Cannot flush database.");
}

void database_close(struct Connection *conn) {
    assert(conn != NULL);

    if (conn->file) {
        database_write(conn);
        fclose(conn->file);
        conn->file = NULL;
    }

    if (conn->db) {
        struct Address *p = conn->db->data, *tmp;
        while (p) {
            tmp = p;
            p = p->next;
            free(tmp);
        }
        free(conn->db);
        conn->db = NULL;
    }
    free(conn);
}

// create one address entry in database.
void database_create(struct Connection *conn, int id,
        const char *name, const char *email) {
    assert(conn != NULL);

    // walk on the list
    struct Address **tail = &conn->db->data;
    while (*tail)
        tail = &(*tail)->next;

    struct Address *node = malloc(sizeof(*node));
    if (!node) terminate("Memory allocation failed.");

    int name_bsize = sizeof(char) * (strlen(name) + 1);
    int email_bsize = sizeof(char) * (strlen(email) + 1);
    *node = (struct Address) { .id = id, .next = NULL };
    memcpy(node->name, name, name_bsize);
    memcpy(node->email, email, email_bsize);
    *tail = node;
}

// delete one address entry in database.
void database_delete(struct Connection *conn, struct Address *target) {
    assert(conn != NULL);

    if (target == NULL) {
        printf("The id is not found.\n");
        return;
    }

    struct Address **indirect = &conn->db->data;
    while (*indirect != target) {
        indirect = &(*indirect)->next;
    }
    *indirect = target->next;

    printf("deleted.\n");
    free(target);
}

// get one address entry in database.
struct Address* database_get(struct Connection *conn, int id) {
    assert(conn != NULL);

    struct Address *p = conn->db->data;
    while (p && p->id != id)
        p = p->next;

    return p;
}

// if the id is exist, modify that address entry in database.
// if not, create one address entry in database.
void database_set(struct Connection *conn, int id,
        const char *name, const char *email) {
    assert(conn != NULL);

    struct Address *target = database_get(conn, id);
    if (target) {
        int name_bsize = sizeof(char) * (strlen(name) + 1);
        int email_bsize = sizeof(char) * (strlen(name) + 1);
        memcpy(target->name, name, name_bsize);
        memcpy(target->email, email, email_bsize);
    } else {
        database_create(conn, id, name, email);
    }
}
