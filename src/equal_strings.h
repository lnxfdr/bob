#ifndef BOB_SRC_EQUAL_STRINGS_H
#define BOB_SRC_EQUAL_STRINGS_H

int equal_strings(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0'){
		if (*s1 != *s2) return 0;
		s1++;
		s2++;
	}
	if (*s1 != '\0' || *s2 != '\0') return 0;
	return 1;
}

#endif
