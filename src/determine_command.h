#ifndef BOB_SRC_DETERMINE_COMMAND_H
#define BOB_SRC_DETERMINE_COMMAND_H

int is_equal(char *arg, char *s)
{
	while (*s != '\0' && *arg != '\0' && *s == *arg){
		s++;
		arg++;
	}
	if (*s == '\0' && *arg == '\0') return 1;
	return 0;
}

int determine_command(char *arg)
{
	if (is_equal(arg, "init")) return 1;
	if (is_equal(arg, "set")) return 2;
	if (is_equal(arg, "build")) return 3;
	if (is_equal(arg, "run")) return 4;
	return 0;
}

#endif
