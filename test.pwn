/*
    test.inc

    It's just a testing include
    nothing special here!

    Always run as administrator because
    Symlink doesn't work on normal user!
    
*/

#include <a_samp>
#include <sscanf2>

#include "random-names.inc"

main() {
    printf("Random name by Kirima");
    printf("Random Name: %s", GetRandomName());
}