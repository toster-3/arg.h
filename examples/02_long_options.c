#include <stdio.h>  /* for printf */
#include <stdlib.h> /* for exit */
#include "../arg.h"

/* Don't forget this! */
char *argv0;

void usage(void)
{
	printf("Usage: %s [-v | --verbose] [-f | --file FILE] [--long-option]\n", argv0);
	exit(1);
}

int main(int argc, char *argv[])
{
	/*
	 * LONG_ARGSTRUCT creates an array of the long options struct
	 * this is required for the use of LONG_ARGBEGIN
	 * the first entry is the name of the long option
	 * and the second is the name of the short option
	 * If you want only a long option you can set the short option
	 * to a control character as shown.
	 * REMEMBER TO NULL TERMINATE THE ARRAY!
	 */
	LONG_ARGSTRUCT {
		{"verbose", 'v'},
		{"file", 'f'},
		{"long-option", '\r'},
		{0, 0},
	};

	/*
	 * LONG_ARGBEGIN is like ARGBEGIN except it supports long options
	 * It requires LONG_ARGSTRUCT to be created
	 * It is dependant on the strcmp function, for more information
	 * see 03_miscellaneous.c
	 */
	LONG_ARGBEGIN {
	case 'v':
		printf("-v/--verbose specified\n");
		break;
	case 'f':
		/*
		 * ARGC(), ARGF() and EARGF() work as expected
		 * Although if the character is a control character
		 * you might want to rethink using ARGC()
		 */
		printf("-%c/--file specified with argument: %s\n", ARGC(), EARGF(usage()));
		break;
	case '\r':
		printf("--long-option specified\n");
		break;
	default:
		usage();
	} LONG_ARGEND
	/*
	 * LONG_ARGEND is the same as ARGEND,
	 * use whichever one you'd like
	 */

	printf("%d arguments:", argc);
	while (*argv)
		printf(" '%s'", *argv++);
	putchar('\n');
	return 0;
}
