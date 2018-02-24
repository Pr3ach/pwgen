#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pwgen.h"
#include "color_shell/src/color_shell.h"

int main(int argc, char *argv[])
{
	char o = 0;
	int pw_len = 0;
	int use_alpha = 0;
	int use_num = 0;
	int use_spec = 0;

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
				use_alpha = 1;
				break;
			case 'n':
				use_num = 1;
				break;
			case 's':
				use_spec = 1;
				break;
			default:
				break;
		}
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
