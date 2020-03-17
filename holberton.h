#ifndef HOLBERTON_H
#define HOLBERTON_H

int _printf(const char *format, ...);
void _itos(long int num, char *string, int cont, int sign);
void rev_string(char *s);
int _strlen(char *s);
int plus(const char *format, int i);
int case_d(long int p);
int case_s(char *f);
int switche_int(char c, int args);
int switche_string(char c, char *args);
int escape(const char *format, int i);
int is_neg(long int num);
int dec_to_bin(long int n);
int case_b(long int p);

#endif
