#include "bob_tools.h"

int main(int argc, char **argv)
{
	if (argc < 2){
		printf("Specify call type.\n");
		return 1;
	}
	int command_id = determine_command(argv[1]);
	handle_command(command_id, argc, argv);
	return 0;
}
