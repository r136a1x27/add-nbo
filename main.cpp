#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf

#define MAX_BUF_SIZE 128

uint32_t my_ntol(uint32_t a){
	uint32_t a1 = (a & 0xFF000000) >> 24;
	uint32_t a2 = (a & 0x00FF0000) >> 8;
	uint32_t a3 = (a & 0x0000FF00) << 8;
	uint32_t a4 = (a & 0x000000FF) << 24;

	return (a1 | a2 | a3 | a4);
}

int main(){
	FILE *fp1 = fopen("thousand.bin", "rb");
	FILE *fp2 = fopen("five-hundred.bin", "rb");

	uint32_t buffer1[] = {0x00,0x00,0x00,0x00};
	uint32_t buffer2[] = {0x00,0x00,0x00,0x00};

	fread(buffer1, 1, MAX_BUF_SIZE, fp1);
	fread(buffer2, 1, MAX_BUF_SIZE, fp2);

	uint32_t* p1 = reinterpret_cast<uint32_t*>(buffer1);
	uint32_t* p2 = reinterpret_cast<uint32_t*>(buffer2);
	
	uint32_t n1 = my_ntol(*p1);
	uint32_t n2 = my_ntol(*p2);

	// printf("16bit number1 = 0x%x / %d\n", n1,n1);
	// printf("16bit number2 = 0x%x / %d\n", n2,n2);
	
	uint32_t sum = n1+n2;

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",n1,n1,n2,n2,sum,sum);

	fclose(fp1);
	fclose(fp2);
}
