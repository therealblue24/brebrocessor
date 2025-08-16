// Copyright (C) 2025 therealblue24 under the MIT license
// Enterprise-grade code here
#include <stdio.h>
#include <wchar.h>
#include <ctype.h>

static inline int replace(wchar_t c)
{
	if(!isascii(c)) {
		return 0;
	}
	int l = tolower(c);
	return l == 'b' || l == 'p';
}

static inline void preprocess_one(wchar_t c)
{
	if(replace(c)) {
		fprintf(stdout, "🅱️");
	} else {
		fputwc(c, stdout);
	}
	return;
}

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	wchar_t c = WEOF;
	while((c = fgetwc(stdin)) != WEOF) {
		preprocess_one(c);
	}
	return 0;
}
