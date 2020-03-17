// error.h
// Řešení IJC-DU1, příklad b), 17.3.2020
// Autor: Peter Urgoš - xurgos00, FIT VUT v Brne

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void warning_msg(const char *fmt, ...);
void error_exit(const char *fmt, ...);
