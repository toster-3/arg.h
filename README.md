# arg.h
suckless arg.h extended with long option functionality

look through examples to learn how to use it
```c
#include <stdio.h>
#include "arg.h"

int main()
{
	ARGSTRUCT {
		{"verbose", 'v'},
		{0, 0},
	}
	
	LONG_ARGBEGIN {
	case 'v':
		printf("verbose\n");
	} ARGEND

	return 0;
}
```

## install

to use it just copy `arg.h` into your project
