#include <stdio.h>
#include <assert.h>
#include <string.h>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
        }
    }
    return i * j;
}

int main() {
    
    char buffer[1024];
    setvbuf(stdout,buffer,_IOFBF,sizeof(buffer));
    const char *expected_colors = "1 | White | Orange\n";

    int result = printColorMap();
    fflush(stdout);
    
    assert(result == 25);
    char *color_found = strstr(buffer,expected_colors);
    assert(color_found != NULL);
    printf("All is well (maybe!)\n");
    
    return 0;
}
