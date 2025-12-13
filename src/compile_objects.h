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

		int pos = 0, len = 1, ok = 0;
		while (f[len] != '\0'){
			if (f[len] >= '0' && f[len] <= '9' && ok == 0){
				pos++;
			} else{
				ok = 1;
			}
			len++;
		}

		char find_path_compile[MAX_COMPILE_TO_OBJECTS_LENGTH] = {"find . -name "};

		int path_pos = 13;
		find_path_compile[path_pos++] = '"';
		for (int i = pos + 2; i < len - 1; i++){
			find_path_compile[path_pos++] = f[i];
		}
		find_path_compile[path_pos++] = '"';
		find_path_compile[path_pos++] = ' ';

		char cmd[20] = {"-exec gcc {} -c \\;"};

		for (int i = 0; i < 20; i++){
			find_path_compile[path_pos++] = cmd[i];
		}

		system(find_path_compile);
		
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
