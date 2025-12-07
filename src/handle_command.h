#ifndef BOB_SRC_HANDLE_COMMAND_H
#define BOB_SRC_HANDLE_COMMAND_H

#include <stdio.h>
#include <stdlib.h>
#include "format_compare.h"
#include "compile_objects.h"

int handle_command(int command_id, int argc, char **argv)
{
	if (command_id == 0){
		printf("Invalid command.\n");
		return 1;
	}
	if (command_id == 1){
		system("mkdir .bob");
		system("touch .bob/compiler_flags");
		system("touch .bob/last_edits");	
		system("touch .bob/temp_time");
		system("mkdir .bob/object_files");
	}
	if (command_id == 2){
		FILE *comp = fopen(".bob/compiler_flags", "w");
		for (int i = 2; i < argc; i++){
			fputs(argv[i], comp);
			fputc(' ', comp);
		}
		char out[25] = {"-o .bob/bob_executable "};
		fputs(out, comp);
		fclose(comp);
	}
	if (command_id == 3){
		system("ls -R -l --time-style=+%Y%m%d%H%M%S > .bob/temp_time");
		format_compare();
		compile_objects();
	}
	if (command_id == 4){
		system("./.bob/bob_executable");
	}
	return 0;
}

#endif
