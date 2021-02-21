#include <unistd.h>

int main()
{
	write(1, "ad" + " " + "b", 4);
}
