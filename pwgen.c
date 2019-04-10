#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <getopt.h>
#include <string.h>
#include "pwgen.h"
#include "color_shell/src/color_shell.h"

int main(int argc, char *argv[])
{
	char o = 0;
	int pw_len = 0;

	OPTIONS = O_NONE;

	if (argc < 2)
		usage(argv[0]);

	while ((o = getopt(argc, argv, "l:anshv")) != -1)
	{
		switch(o)
		{
			case 'l':
				pw_len = atoi(optarg);
				break;
			case 'a':
				OPTIONS |= O_ALPHA;
				break;
			case 'n':
				OPTIONS |= O_NUM;
				break;
			case 's':
				OPTIONS |= O_SPECIAL;
				break;
			case 'h':
				usage(argv[0]);
				break;
			case 'v':
				version();
				break;
			default:
				break;
		}
	}

	if (pw_len > MAX_LEN || pw_len < MIN_LEN)
	{
		w_byellow("[!] # %d<length<%d\n", MIN_LEN-1, MAX_LEN+1);
		exit(-1);
	}

	if (OPTIONS == O_NONE)
		usage(argv[0]);

	srand(time(NULL));
	pw_gen(pw_len);
	w_bgreen("[*] %s\n", PASSWD);

	exit(0);
}

void usage(const char *self)
{
	w_bwhite("Usage: %s [OPTIONS]\n\n", self);
	w_white("   -h		Diplay this help\n");
	w_white("   -v		Show version information\n");
	w_white("   -l<n>	Specify password length\n");
	w_white("   -a		Use alpha charset\n");
	w_white("   -n		Use num charset\n");
	w_white("   -s		Use special charset\n");

	exit(0);
}

void version(void)
{
	w_bwhite("pwgen-%.2f/%s by %s - built on %s\n", VERSION, PLATFORM, AUTHOR, __DATE__);
	exit(0);
}

/*
 * Generate a password according to the specified options.
 *
 * */
void pw_gen(int pw_len)
{
	char charset_alpha[64] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char charset_num[64] = "0123456789";
	char charset_spec[64] = "!?%=\\-_:+~|@#/;><&$*";
	char charset[128] = {0};
	char len = 0;
	int i = 0;

	/* Build the charset. */
	if (OPTIONS & O_ALPHA)
		strcat(charset, charset_alpha);
	if (OPTIONS & O_NUM)
		strcat(charset, charset_num);
	if (OPTIONS & O_SPECIAL)
		strcat(charset, charset_spec);

	if (!charset[0])
		return;

	shuffle_charset(charset);

	len = strlen(charset);

	for (i = 0; i < pw_len; i++)
		PASSWD[i] = charset[rand()%len];

	PASSWD[i] = (char) 0;
}

/*
 * Shuffle the charset.
 *
 * */
void shuffle_charset(char charset[])
{
	int len = 0;
	int passes = 0;
	int i = 0;

	len = strlen(charset);
	passes = len/2;

	for (i = 0; i < passes; i++)
		swap(charset, rand() % len, rand() % len);
}

/*
 * Swap s[i1] and s[i2].
 *
 * */
void swap(char s[], int i1, int i2)
{
	char tmp = s[i1];

	s[i1] = s[i2];
	s[i2] = tmp;
}
