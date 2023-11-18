#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#define no_argument        0
#define required_argument  1
#define optional_argument  2

int main(int argc, char **argv) {
    int c;
    int digit_optind = 0;

    while (1) {
        int this_option_optind;
        if (optind) {
            this_option_optind = optind;
        } else {
            this_option_optind = 1;
        }
        int option_index = 0;
        static struct option long_options[] = {
            {"number-nonblank", no_argument, 0, 'b'},
            {"number", no_argument, 0, 'n'},
            {"squeeze-blank", no_argument, 0, 's'},
            {0, 0, 0, 0}
        };

        c = getopt_long(argc, argv, "+abc:d:012", long_options, &option_index);
        if (c == -1)
            break;

        switch (c) {
        case 0:
            printf("Parameter %s", long_options[option_index].name);
           if (optarg)
                printf(" with argument %s", optarg);
           // printf("\n");
           // break;

        case '0':
        case '1':
        case '2':
            if (digit_optind != 0 && digit_optind != this_option_optind)
                printf("Digits used in different elements of argv.\n");
            digit_optind = this_option_optind;
            printf("Parameter %c\n", c);
            break;

        case 'a':
            printf("Parameter a\n");
            break;

        case 'b':
            printf("Parameter b\n");
            break;

        case 'c':
            printf("Parameter c with value `%s'\n", optarg);
            break;

        case 'd':
            printf("Parameter d with value `%s'\n", optarg);
            break;

        case '?':
            break;

        default:
            printf("?? Getopt returned character code 0%o ??\n", c);
        }
    }

    if (optind < argc) {
        printf("Non-parameter elements in ARGV: ");
        while (optind < argc)
            printf("%s ", argv[optind++]);
        printf("\n");
    }

    exit(0);
}
