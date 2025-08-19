#include <stdio.h>
#include <stdint.h>
#include <fstream>



uint32_t  my_ntohl(uint32_t n){
        uint32_t f = (n & 0xFF000000) >> 24;
        uint32_t s = (n & 0x00FF0000) >> 8;
        uint32_t t = (n & 0x0000FF00) << 8;
        uint32_t fth = (n & 0x000000FF) << 24;
        return f | s | t | fth;

}


int main(int argc, char *argv[]){
	uint32_t sum = 0;

	for(int i = 1; i < argc; i++){
		FILE* fp;
		fp = fopen(argv[i],"rb");
		
		uint32_t str[8];
		int size = fread(str, sizeof(uint32_t), 8, fp);
		//if (size < 8){
			//printf("your file size is not big enough!");
		//}	
		uint32_t result = my_ntohl(*str);
		sum += result;
		printf("%d(0x%08X) " , result, result);
		if (i < argc-1){
			printf("+ ");
		}
		else{
		printf("= ");
		}
		fclose(fp);
	}	
	printf("%d(0x%08X)", sum,sum);

		
	}


