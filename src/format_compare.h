#ifndef BOB_SRC_FORMAT_COMPARE_H
#define BOB_SRC_FORMAT_COMPARE_H

#include "equal_strings.h"

int format_compare()
{
	FILE *time = fopen(".bob/temp_time", "r");
	char l[250][250];
	int start[250], end[250];
	int line = 0;
	while (fgets(l[line], 250, time) != NULL){
		if (l[line][0] != '-') continue;
		int len = 0;
		while (l[line][len] != '\0'){
			len++;
		}
		int pos = len - 1;
		char sep = ' ';
		if (l[line][pos] == '\''){
			sep = '\'';
			pos--;
		}
		while (l[line][pos] != sep){
			pos--;
		}
		pos--;
		while (l[line][pos] >= '0' && l[line][pos] <= '9'){
			pos--;
		}
		start[line] = pos;
		end[line] = len - 1;
		line++;
	}
	fclose(time);
	time = fopen(".bob/last_edits", "r");
	int new_lines[250];
	int pos = 0;
	for (int i = 0; i < line; i++){
		char last_edit[250];
		int ok = 0;
		while (fgets(last_edit, 250, time) != NULL){
			if (equal_strings(last_edit, l[i] + start[i])){
				ok = 1;
				break;
			}
		}
		fseek(time, 0, SEEK_SET);
		if (ok == 0 &&
		    l[i][end[i] - 1] == 'c' &&
		    l[i][end[i] - 2] == '.') new_lines[pos++] = i;
	}
	fclose(time);
	time = fopen(".bob/last_edits", "w");
	for (int i = 0; i < line; i++){
		fputs(l[i] + start[i], time);
	}
	fclose(time);
	time = fopen(".bob/to_change", "w");
	for (int i = 0; i < pos; i++){
		fputs(l[new_lines[i]] + start[i], time);
	}
	fclose(time);
	return 0;
}

#endif
