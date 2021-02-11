#include "builtins.h"
#include <fcntl.h>

extern char **make_builtin_argv ();
extern int setns ();

int setns_main(int argc, char **argv) {
    if (argc != 2) {
        write(2, "Usage: setns <namspace>\n", 24);
        return 2;
    }
    int fd, r;
    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        write(2, "Can't open namespace\n", 21);
        return 1;
    }
    r = setns(fd, 0);
    if (r != 0) {
        write(2, "Failed\n", 7);
    }
    close(fd);
    return r;
}

int setns_builtin(WORD_LIST *list) {
    char **v;
    int c, r;

    v = make_builtin_argv(list, &c);
    r = setns_main(c, v);
    free(v);

    return r;
}

char *setns_doc[] = {
    "Set Linux namespaces.",
    "",
    "Change the current bash process's namesapces.",
    "Example: setns /proc/12345/ns/mnt",
    (char)0
};

struct builtin setns_struct = {
    "setns",
    setns_builtin,
    BUILTIN_ENABLED,
    setns_doc,
    "setns <namespace>",
    0
};
