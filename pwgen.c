#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pwgen.h"
#include "color_shell/src/color_shell.h"

int main(int argc, char *argv[])
{
	char o = 0;
	int pw_len = 0;

	OPTIONS = O_NONE;

	if (argc < 2)
		usage(argv[0]);

	while ((o = getopt(argc, argv, "l:ans")) != -1)
	{
		switch(o)
		{
			case 'l':
				pw_len = atoi(optarg);
				break;
			case 'a':
				O_OPTIONS |= O_ALPHA;
				break;
			case 'n':
				O_OPTIONS |= O_NUM;
				break;
			case 's':
				O_OPTIONS |= O_SPECIAL;
				break;
			default:
				break;
		}
	}

	if (pw_len > MAX_LEN || pw_len < 1)
	{
		w_byellow("[!] # 0<length<256\n");
		exit(-1);
	}

	exit(0);
}

void usage(const char *self)
{
	w_bwhite("Usage: %s [OPTIONS]\n\n", self);
	w_white("  -l<n>	Specify password length\n");
	w_white("  -a		Use alpha charset\n");
	w_white("  -n		Use num charset\n");
	w_white("  -s		Use special charset\n");

	exit(0);
}

/*
 * Generate and return a password according to options.
 *
 */
char *pw_gen(int pw_len, int opt)
{
}
