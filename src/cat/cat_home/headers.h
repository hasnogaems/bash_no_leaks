#ifndef headers
#define headers
typedef struct Flags{
    int b;
    int s;
    int e;
}Flags;
Flags parse_flags(int argc, char *argv[]);
#endif