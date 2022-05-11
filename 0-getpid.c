#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t ourpid;
	ourpid = getpid();

	printf("%d is the pid for the parent\n", ourpid);
	return (0);
}
