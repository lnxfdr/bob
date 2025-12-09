#ifndef BOB_SRC_COMPILE_OBJECTS_H
#define BOB_SRC_COMPILE_OBJECTS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 250
#define MAX_COMPILE_TO_OBJECTS_LENGTH 25000
#define MAX_COMPILE_EXECUTABLE_LENGTH 30000

int compile_objects()
{
	FILE *comp = fopen(".bob/to_change", "r");
	if (!comp) fprintf(stderr, ".bob/to_change failed to open in compile_objects()\n");

	char f[MAX_LINE_LENGTH];
	while (fgets(f, MAX_LINE_LENGTH, comp)){
		
		int pos = 0, len = 0;
		while (f[len] != '\0'){
			if (f[len] >= '0' && f[len] <= '9') pos++;
			len++;
		}

		char cmd[MAX_COMPILE_TO_OBJECTS_LENGTH] = {"gcc -c "};
		int cmd_pos = 7;
		for (int i = pos + 2; i < len; i++){
			cmd[cmd_pos++] = f[i];
		}
		cmd[cmd_pos] = '\0';
		system(cmd);

		system("mv *.o .bob/object_files/");
	}
	fclose(comp);

	FILE *fl = fopen(".bob/compiler_flags", "r");
	if (!fl) fprintf(stderr, ".bob/compiler_flags failed to open in compile_objects()\n");

	char compile[MAX_COMPILE_EXECUTABLE_LENGTH];
	fgets(compile, MAX_COMPILE_EXECUTABLE_LENGTH, fl);

	int pos = 0;
	while (compile[pos] != '\0'){
		pos++;
	}
	pos--;
	compile[pos++] = ' ';

	char obj_files[23] = ".bob/object_files/*.o";
	int of_pos = 0;
	while (obj_files[of_pos] != '\0'){
		compile[pos++] = obj_files[of_pos++];
	}
	system(compile);

	fclose(fl);
	return 0;
}

#endif
