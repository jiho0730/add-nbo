#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32")
#include <netinet/in.h>

int read(char* file) {
    uint32_t result;
    FILE* fp;
    fp = fopen(file, "rb"); 
    fread(&result, sizeof(uint32_t), 1, fp); 
    fclose(fp); 

    return htonl(result);
}

int main(int argc, char** argv) {

    uint32_t num1 = read(argv[1]); 
    uint32_t num2 = read(argv[2]);
    uint32_t num3 = num1 + num2;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, num3, num3);

}
