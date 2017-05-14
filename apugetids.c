#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(void) {
	printf("User Id :%d\n Group Id :%d \n", getuid(), getgid());
	return 0;
}