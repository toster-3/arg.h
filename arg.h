/*
 * Copy me if you can.
 * by 20h
 * extended by toster-3
 */

#ifndef ARG_H__
#define ARG_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef ARGH_STRCMP
#define ARGH_STRCMP strcmp
#include <string.h>
#endif

extern char *argv0;

struct Lopts_ {
	char *lopt;
	char opt;
};

/* use main(int argc, char *argv[]) */
#define ARGBEGIN	for (argv0 = *argv, argv++, argc--;\
					argv[0] && argv[0][0] == '-'\
					&& argv[0][1];\
					argc--, argv++) {\
				char argc_;\
				char **argv_;\
				int brk_;\
				if (argv[0][1] == '-' && argv[0][2] == '\0') {\
					argv++;\
					argc--;\
					break;\
				}\
				for (brk_ = 0, argv[0]++, argv_ = argv;\
						argv[0][0] && !brk_;\
						argv[0]++) {\
					if (argv_ != argv)\
						break;\
					argc_ = argv[0][0];\
					switch (argc_)

#define ARGEND			}\
			}

#define ARGC()		argc_

#define EARGF(x)	((argv[0][1] == '\0' && argv[1] == NULL)?\
				((x), abort(), (char *)0) :\
				(brk_ = 1, (argv[0][1] != '\0')?\
					((argv[0][1] == '=' &&\
					  argv[0][2] != '\0') ?\
						(&argv[0][2]) :\
						(&argv[0][1])) :\
					(argc--, argv++, argv[0])))

#define ARGF()		((argv[0][1] == '\0' && argv[1] == NULL)?\
				(char *)0 :\
				(brk_ = 1, (argv[0][1] != '\0')?\
					((argv[0][1] == '=' &&\
					  argv[0][2] != '\0') ?\
						(&argv[0][2]) :\
						(&argv[0][1])) :\
					(argc--, argv++, argv[0])))

#define LONG_ARGSTRUCT	struct Lopts_ lopts_[] =

#define ARGSTRUCT	LONG_ARGSTRUCT

#define LONG_ARGBEGIN	for (argv0 = *argv, argv++, argc--;\
					argv[0] && argv[0][0] == '-'\
					&& argv[0][1];\
					argc--, argv++) {\
				char argc_;\
				char tmpc_;\
				char **argv_;\
				char *lopt_argv0_;\
				int lopt_i_;\
				int brk_;\
				if (argv[0][1] == '-' && argv[0][2] == '\0') {\
					argv++;\
					argc--;\
					break;\
				}\
				if (argv[0][1] == '-' && argv[0][2] != '\0') {\
					lopt_argv0_ = &argv[0][2];\
					while (argv[0][0] != '\0' &&\
							argv[0][0] != '=')\
						argv[0]++;\
					tmpc_ = argv[0][0];\
					argv[0][0] = '\0';\
					for (lopt_i_ = 0; lopts_[lopt_i_].opt != 0\
						&& ARGH_STRCMP(lopts_[lopt_i_].lopt,\
						lopt_argv0_); lopt_i_++);\
					if (lopts_[lopt_i_].opt == 0)\
						continue;\
					argv[0][0] = tmpc_;\
					*(--argv[0]) = lopts_[lopt_i_].opt;\
					*(--argv[0]) = '-';\
				}\
				for (brk_ = 0, argv[0]++, argv_ = argv;\
						argv[0][0] && !brk_;\
						argv[0]++) {\
					if (argv_ != argv)\
						break;\
					argc_ = argv[0][0];\
					switch (argc_)

#define ELONG_ARGBEGIN(x) for (argv0 = *argv, argv++, argc--;\
					argv[0] && argv[0][0] == '-'\
					&& argv[0][1];\
					argc--, argv++) {\
				char argc_;\
				char tmpc_;\
				char **argv_;\
				char *lopt_argv0_;\
				int lopt_i_;\
				int brk_;\
				if (argv[0][1] == '-' && argv[0][2] == '\0') {\
					argv++;\
					argc--;\
					break;\
				}\
				if (argv[0][1] == '-' && argv[0][2] != '\0') {\
					lopt_argv0_ = &argv[0][2];\
					while (argv[0][0] != '\0' &&\
							argv[0][0] != '=')\
						argv[0]++;\
					tmpc_ = argv[0][0];\
					argv[0][0] = '\0';\
					for (lopt_i_ = 0; lopts_[lopt_i_].opt != 0\
						&& ARGH_STRCMP(lopts_[lopt_i_].lopt,\
						lopt_argv0_); lopt_i_++);\
					if (lopts_[lopt_i_].opt == 0) {\
						(x);\
						continue;\
					}\
					argv[0][0] = tmpc_;\
					*(--argv[0]) = lopts_[lopt_i_].opt;\
					*(--argv[0]) = '-';\
				}\
				for (brk_ = 0, argv[0]++, argv_ = argv;\
						argv[0][0] && !brk_;\
						argv[0]++) {\
					if (argv_ != argv)\
						break;\
					argc_ = argv[0][0];\
					switch (argc_)

#define LONG_ARGEND		}\
			}

#ifdef __cplusplus
}
#endif

#endif
