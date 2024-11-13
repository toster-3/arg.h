#include <stdio.h>  /* for printf */
#include <stdlib.h> /* for exit */

/*
 * ARGH_STRCMP can be set if you dont want to use the
 * standard library function strcmp
 * If it isnt set before including arg.h then
 * string.h will be included
 */
#define ARGH_STRCMP my_strcmp

#include "../arg.h"

/* Don't forget this! */
char *argv0;

/* This function is from musl libc */
int my_strcmp(const char *l, const char *r)
{
	for (; *l==*r && *l; l++, r++);
	return *(unsigned char *)l - *(unsigned char *)r;
}

void usage(void)
{
	printf("Usage: %s [-v | --verbose] [-f | --file FILE] [--long-option]\n", argv0);
	exit(1);
}


int main(int argc, char *argv[])
{
	/* ARGSTRUCT is an alias of LONG_ARGSTRUCT */
	ARGSTRUCT {
		{"verbose", 'v'},
		{"file", 'f'},
		{"long-option", '\r'},
		{0, 0},
	};

	/*
	 * When LONG_ARGBEGIN() encounters a long option that
	 * wasn't declared in LONG_ARGSTRUCT, it fails silently
	 * If that is undesirable you can use ELONG_ARGBEGIN()
	 * ELONG_ARGBEGIN() takes a function as an argument
	 * the same way as EARGF(), although ELONG_ARGBEGIN()
	 * doesn't abort if the function returns
	 */
	ELONG_ARGBEGIN(usage()) {
	case 'v':
		printf("-v/--verbose specified\n");
		break;
	case 'f':
		printf("-%c/--file specified with argument: %s\n", ARGC(), EARGF(usage()));
		break;
	case '\r':
		printf("--long-option specified\n");
		break;
	default:
		usage();
		break;
	} ARGEND
	/*
	 * ARGEND is the same as LONG_ARGEND,
	 * use whichever one you'd like
	 */

	printf("%d arguments:", argc);
	while (*argv)
		printf(" '%s'", *argv++);
	putchar('\n');
	return 0;
}
