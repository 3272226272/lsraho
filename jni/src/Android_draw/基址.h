// 动态基址CPP
#include <stdio.h>
//#include <conio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <pthread.h>
#include <sys/socket.h>
#include <malloc.h>
#include <math.h>
#include <thread>
#include <iostream>
#include <sys/stat.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>
#include <locale>
#include <string>
#include <codecvt>
//--/////////////////////////////////////////////
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/syscall.h>
#include <sys/mman.h>
#include <sys/uio.h>
#include <malloc.h>
#include <math.h>
#include <thread>
#include <iostream>
#include <sys/stat.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>
#include <locale>
#include <string>
#include <codecvt>
#include <dlfcn.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <pthread.h>
#include <sys/socket.h>
#include <malloc.h>
#include <math.h>
#include <thread>
#include <iostream>
#include <sys/stat.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>
#include <locale>
#include <string>
#include <codecvt>
typedef char PACKAGENAMEjz;
int jz_getPID(const char *packageNamejz)
{
	int id = -1;
	DIR *dir;
	FILE *fp;
	char filename[64];
	char cmdline[64];
	struct dirent *entry;
	dir = opendir("/proc");
	while ((entry = readdir(dir)) != NULL)
	{
		id = atoi(entry->d_name);
		if (id != 0)
		{
			sprintf(filename, "/proc/%d/cmdline", id);
			fp = fopen(filename, "r");
			if (fp)
			{
				fgets(cmdline, sizeof(cmdline), fp);
				fclose(fp);
				if (strcmp(packageNamejz, cmdline) == 0)
				{
					return id;
				}
			}
		}
	}
	closedir(dir);
	return -1;
}

long int jz_get_Xa(int pid, const char *module_name)
{
	FILE *fp;
	long addr = 0;
	char *pch;
	char filename[64];
	char line[1024];
	snprintf(filename, sizeof(filename), "/proc/%d/maps", pid);
	fp = fopen(filename, "r");
	if (fp != NULL)
	{
		while (fgets(line, sizeof(line), fp))
		{
			if (strstr(line, module_name))
			{
				pch = strtok(line, "-");
				addr = strtoul(pch, NULL, 16);
				if (addr == 0x8000)
					addr = 0;
				break;
			}
		}
		fclose(fp);
	}
	return addr;
}

long jz_get_bss(int pid, const char *module_name)
{
	FILE *fp;
	long addr = 0;
	char *pch;
	char filename[64];
	char line[1024];
	snprintf(filename, sizeof(filename), "/proc/%d/maps", pid);
	fp = fopen(filename, "r");
	bool is = false;
	if (fp != NULL)
	{
		while (fgets(line, sizeof(line), fp))
		{
			if (strstr(line, module_name ))
			{
				is = true;
			}
			if (is)
			{
				if (strstr(line, "[anon:.bss]"))
				{
					sscanf(line, "%X", &addr);
					break;
				}
			}
		}
		fclose(fp);
	}
	return addr;
}

long jz_get_Cd(int pid, const char *module_name)
{
	FILE *fp;
	long addr = 0;
	char *pch;
	char filename[64];
	char line[1024];
	snprintf(filename, sizeof(filename), "/proc/%d/maps", pid);
	fp = fopen(filename, "r");
	char str[100];
	sprintf(str, "-%x", jz_get_bss((pid, module_name));
	if (fp != NULL)
	{
		while (fgets(line, sizeof(line), fp))
		{
			if (strstr(line, str ))
			{
				sscanf(line, "%X", &addr);
				break;
			}
		}
		fclose(fp);
	}
	return addr;
}



long int handles;
float jz_gainF(long int addr)
{
	float var = 0;
	pread64(handles, &var, 4, addr);
	return var;
}

int jz_gainD(long int addr)
{
	int var = 0;
	pread64(handles, &var, 4, addr);
	return var;
}
//32位指针
long int lsp32jz(long int addr)
{
	long int var = 0;
	pread64(handles, &var, 4, addr);
	return var;
}

//64位指针
long int lsp64jz(long int addr)
{
	long int var = 0;
	//pread64(handles, &var, 8, addr);
	return var;
}
//D类型
int WriteAddress_DWORDjz(long int addr,int value) {
	pwrite64(handles, &value, 4, addr);
	return 0;
}
//F类型
float WriteAddress_FLOATjz(long int addr, float value) {
	pwrite64(handles, &value, 4, addr);
	return 0;
}
//B类型
int8_t WriteAddress_BYTEjz(long int addr,int value) {
	pwrite64(handles, &value, 1, addr);
	return 0;
}
//W类型
int16_t WriteAddress_WORDjz(long int addr,int value) {
	pwrite64(handles, &value, 2, addr);
	return 0;
}
//Q类型
int64_t WriteAddress_QWORDjz(long int addr,int value) {
	pwrite64(handles, &value, 32, addr);
	return 0;
}
//E类型
double WriteAddress_DOUBLEjz(long int addr, double value) {
	pwrite64(handles, &value, 64, addr);
	return 0;
}

int Range()
{
	// 读取游戏进程
	int ipid = getPID("com.sofunny.Sausage");
    char lj[64];
	sprintf(lj, "/proc/%d/mem", ipid);
	handles = open(lj, O_RDWR);
	if (handles == 0)
	{
		puts("获取mem失败!");
		exit(1);
	}
	// 读取基址
	puts("\n开始基址搜索");
	char mname[] = "libil2cpp.so";	// 基址入口模块
	//Xa用getXa,Cb用getbss,Cd用getCd
	
	long int fool = jz_get_bss(ipid, mname);
    //64位游戏把lsp32jz换成lsp64jz即可0xBD098, 0x5C, 0x68, 0x100, 0x4C}
	long int a1 = lsp32jz(lsp32jz(lsp32jz(lsp32jz(fool + 0xBD098) + 0x5C)+0x68)+0x100)+0x4C;
	printf("基址搜索完成\n");
    printf("\n阳光地址=%lx\n", a1);
	WriteAddress_DWORDjz(a1, 40);
	//修改支持所有类型
	puts("\n修改成功\n");
	}
	
	