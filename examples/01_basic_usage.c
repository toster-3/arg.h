#include <stdio.h>  /* for printf and putchar */
#include <stdlib.h> /* for exit */
#include "../arg.h"

/*
 * This variable is required to use arg.h
 * It will be argv[0] (the program name)
 * It doesn't have to be global, however
 * this way allows you to easily get
 * the program name, see usage()
 */
char *argv0;

void usage(void)
{
	printf("Usage: %s [-abc] VALUE [-v]\n", argv0);
	exit(1);
}

/*
 * Use this main function signature or
 * int main(int argc, char **argv)
 */
int main(int argc, char *argv[])
{
	char *f;
	/*
	 * ARGBEGIN assumes argc and argv are in scope
	 * After ARGBEGIN put the body of a switch statement
	 * and after that put ARGEND as shown
	 */
	ARGBEGIN {
	case 'v':
		/*
		 * ARGC() returns the character of the current option
		 */
		printf("-%c specified\n", ARGC());
		break;
	case 'a':
		/*
		 * ARGF() returns the argument of the current option
		 * and null if there is no argument.
		 * Supports the following:
		 * -avalue, -a value, -a=value
		 */
		printf("-a specified with argument: %s\n", (f=ARGF()) ? f : "(no arg)");
		break;
	case 'b':
		/*
		 * EARGF() is ARGF() but executes a function on failure
		 * EARGF() expects a function as an argument i.e. EARGF(usage())
		 * If the function returns, abort() is run
		 * If this is undesirable modify arg.h
		 */
		printf("-b specified with argument: %s\n", EARGF(usage()));
		break;
	default:
		usage();
	} ARGEND
	/*
	 * If your syntax highlighting is acting weird you can add a semicolon to ARGEND i.e. "ARGEND;"
	 */

	/*
	 * After ARGEND argc and argv are changed
	 * to represent the non-option arguments
	 */
	printf("%d arguments:", argc);
	while (*argv)
		printf(" '%s'", *argv++);
	putchar('\n');
	return 0;
}
