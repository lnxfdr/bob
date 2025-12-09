## Bob the C build system for linux.

## Commands:

    bob init 
    bob set <gccflags>
    bob build
    bob run

## Structure:

    init - creates a new build and ./.bob inside the current directory;
    set - tells bob what flags to use;
    build - builds the files in the init directory recursively;
    run - runs the program;

## Yet to be implemented:

    bob does not compile or link dependencies outside the working directory;
