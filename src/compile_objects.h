#ifndef BOB_SRC_COMPILE_OBJECTS_H
#define BOB_SRC_COMPILE_OBJECTS_H

#include <stdio.h>
#include <stdlib.h>

int compile_objects()
{
	FILE *comp = fopen(".bob/to_change", "r");
	char f[250];
	while (fgets(f, 250, comp) != NULL){
		int pos = 0, len = 0;
		while (f[len] != '\0'){
			if (f[len] >= '0' && f[len] <= '9') pos++;
			len++;
		}
		char cmd[500] = {"gcc -c "};
		int cmd_pos = 0;
		for (int i = pos + 2; i < len; i++){
			cmd[cmd_pos + 7] = f[i];
			cmd_pos++;
		}
		cmd[cmd_pos + 7] = '\0';
		system(cmd);
		system("mv *.o .bob/object_files/");
	}
	fclose(comp);
	FILE *fl = fopen(".bob/compiler_flags", "r");
	char compile[500];
	fgets(compile, 500, fl);
	int pos = 0;
	while (compile[pos] != '\0'){
		pos++;
	}
	pos--;
	compile[pos++] = ' ';
	char dir[50] = ".bob/object_files/";
	int dir_pos = 0;
	while (dir[dir_pos] != '\0'){
		compile[pos++] = dir[dir_pos];
		dir_pos++;
	}
	compile[pos++] = '*';
	compile[pos++] = '.';
	compile[pos++] = 'o';
	compile[pos] = '\0';
	system(compile);
	fclose(fl);
	return 0;
}

#endif
