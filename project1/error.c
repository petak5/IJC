// error.c
// Řešení IJC-DU1, příklad b), 17.3.2020
// Autor: Peter Urgoš - xurgos00, FIT VUT v Brne

#include "error.h"

void warning_msg(const char *fmt, ...)
{
	fprintf(stderr, "CHYBA: ");

	va_list arg;
	va_start(arg, fmt);

	vfprintf(stderr, fmt, arg);

	va_end(arg);
}

void error_exit(const char *fmt, ...)
{
	fprintf(stderr, "CHYBA: ");

	va_list arg;
	va_start(arg, fmt);

	vfprintf(stderr, fmt, arg);

	va_end(arg);

	exit(1);
}
