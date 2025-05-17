#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdio.h>

int enableHeader = 1;

int isNumber(const char *s) {
	while (*s) {
		if (!isdigit(*s++)) return 0;
	}
	return 1;
}

char* getProcInfo(const char *pid) {
	static char proc_info[256];
	char path[64];
	FILE *f;
	char line[256];
	char name[64] = "";
	char mem[32] = "0";
	snprintf(path, sizeof(path), "/proc/%s/status", pid);
	f = fopen(path, "r");
	if (!f) return NULL;
	while (fgets(line, sizeof(line), f)) {
		if (!name[0] && strncmp(line, "Name:", 5) == 0) {
			sscanf(line + 5, "%63s", name);
		}
		else if (strncmp(line, "VmRSS:", 6) == 0) {
			sscanf(line + 6, "%31s", mem);
			break;
		}
	}
	fclose(f);
	snprintf(proc_info, sizeof(proc_info), "%s\t%s\t%s\n", pid, name, mem);
	return proc_info;
}

void checkForHeader(int argc, char* argv[]) {
	int i;
	for (i = 0; i < argc; i++) {
		if (strcmp(argv[i], "--no-header")) enableHeader = 0;
	}
}

int main(int argc, char* argv[]) {
	struct dirent *entry;
	DIR *proc = opendir("/proc");
	char* info;
	if (!proc) {
		perror("Cannot open dir /proc");
		return 1;
	}
	if (argc > 1) {
		checkForHeader(argc, argv);
	}
	if (enableHeader == 1)
		printf("PID\tNAME\tMEM_kB\n");
	while ((entry = readdir(proc))) {
		if (isNumber(entry->d_name) == 1) {
			info = getProcInfo(entry->d_name);
			if (info) {
				printf(info);
			}
		}
	}
	closedir(proc);
	return 0;
}
