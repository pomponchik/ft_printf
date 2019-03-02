#include <dirent.h>
#include <stdio.h>

int main()
{
	DIR *cat;
	struct dirent *ror;

	cat = opendir("../");
	while ((ror = readdir(cat)))
		printf("%s\t", ror->d_name);
	return 0;
}
