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

// 文字转码
#ifndef __UTF_H__
#define __UTF_H__
#define FALSE 0
#define TRUE 1
#define halfShift 10
#define UNI_SUR_HIGH_START (UTF32)0xD800
#define UNI_SUR_HIGH_END (UTF32)0xDBFF
#define UNI_SUR_LOW_START (UTF32)0xDC00
#define UNI_SUR_LOW_END (UTF32)0xDFFF
	// Some fundamental constants
#define UNI_REPLACEMENT_CHAR (UTF32)0x0000FFFD
#define UNI_MAX_BMP (UTF32)0x0000FFFF
#define UNI_MAX_UTF16 (UTF32)0x0010FFFF
#define UNI_MAX_UTF32 (UTF32)0x7FFFFFFF
#define UNI_MAX_LEGAL_UTF32 (UTF32)0x0010FFFF
typedef unsigned char boolean;
typedef unsigned int CharType;
typedef char UTF8;
typedef unsigned short UTF16;
typedef unsigned int UTF32;

static const UTF32 halfMask = 0x3FFUL;
static const UTF32 halfBase = 0x0010000UL;
static const UTF8 firstByteMark[7] = { 0x00, 0x00, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC };
static const UTF32 offsetsFromUTF8[6] =
	{ 0x00000000UL, 0x00003080UL, 0x000E2080UL, 0x03C82080UL, 0xFA082080UL, 0x82082080UL };
static const char trailingBytesForUTF8[256] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5
};

typedef enum
{
	strictConversion = 0,
	lenientConversion
}
ConversionFlags;
typedef enum
{
	conversionOK,				// conversion successful
	sourceExhausted,			// partial character in source,but hit end
	targetExhausted,			// insuff. room in target for conversion
	sourceIllegal,				// source sequence is illegal/malformed
	conversionFailed
}
ConversionResult;
#endif


ImU32 艳青 = IM_COL32(0, 255, 255, 255);
ImU32 红色 = IM_COL32(255, 0, 0, 255);
ImU32 黄色 = IM_COL32(255, 255, 0, 255);
ImU32 蓝色 = IM_COL32(0, 0, 255, 255);
ImU32 橙色 = IM_COL32(255, 165, 0, 255);
ImU32 粉红 = IM_COL32(255, 192, 203, 255);
ImU32 白色 = IM_COL32(255, 255, 255, 255);
ImU32 绿色 = IM_COL32(0, 255, 0, 255);
ImU32 紫色 = IM_COL32(128, 0, 128, 255);
ImU32 天蓝 = IM_COL32(135, 206, 235, 255);
ImU32 深天蓝 = IM_COL32(0, 191, 255, 255);

int Utf16_To_Utf8(const UTF16 * sourceStart, UTF8 * targetStart, size_t outLen,
				  ConversionFlags flags)
{
	int result = 0;
	const UTF16 *source = sourceStart;
	UTF8 *target = targetStart;
	UTF8 *targetEnd = targetStart + outLen;
	if ((NULL == source) || (NULL == targetStart))
	{
		// printf("ERR,Utf16_To_Utf8:source=%p,targetStart=%p\n",source,targetStart);
		return conversionFailed;
	}

	while (*source)
	{
		UTF32 ch;
		unsigned short bytesToWrite = 0;
		const UTF32 byteMask = 0xBF;
		const UTF32 byteMark = 0x80;
		const UTF16 *oldSource = source;	// In case we have to back up
		// because of target overflow.
		ch = *source++;
		// If we have a surrogate pair,convert to UTF32 first.
		if (ch >= UNI_SUR_HIGH_START && ch <= UNI_SUR_HIGH_END)
		{
			// If the 16 bits following the high surrogate are in the source
			// buffer...
			if (*source)
			{
				UTF32 ch2 = *source;
				// If it's a low surrogate,convert to UTF32.
				if (ch2 >= UNI_SUR_LOW_START && ch2 <= UNI_SUR_LOW_END)
				{
					ch = ((ch - UNI_SUR_HIGH_START) << halfShift) + (ch2 - UNI_SUR_LOW_START) +
						halfBase;
					++source;
				}
				else if (flags == strictConversion)
				{				// it's an unpaired high surrogate
					--source;	// return to the illegal value itself
					result = sourceIllegal;
					break;
				}
			}
			else
			{					// We don't have the 16 bits following the
				// high surrogate.
				--source;		// return to the high surrogate
				result = sourceExhausted;
				break;
			}
		}
		else if (flags == strictConversion)
		{
			// UTF-16 surrogate values are illegal in UTF-32
			if (ch >= UNI_SUR_LOW_START && ch <= UNI_SUR_LOW_END)
			{
				--source;		// return to the illegal value itself
				result = sourceIllegal;
				break;
			}
		}
		// Figure out how many bytes the result will require
		if (ch < (UTF32) 0x80)
		{
			bytesToWrite = 1;
		}
		else if (ch < (UTF32) 0x800)
		{
			bytesToWrite = 2;
		}
		else if (ch < (UTF32) 0x10000)
		{
			bytesToWrite = 3;
		}
		else if (ch < (UTF32) 0x110000)
		{
			bytesToWrite = 4;
		}
		else
		{
			bytesToWrite = 3;
			ch = UNI_REPLACEMENT_CHAR;
		}
		target += bytesToWrite;
		if (target > targetEnd)
		{
			source = oldSource;	// Back up source pointer!
			target -= bytesToWrite;
			result = targetExhausted;
			break;
		}
		switch (bytesToWrite)
		{						// note: everything falls through.
		case 4:
			*--target = (UTF8) ((ch | byteMark) & byteMask);
			ch >>= 6;
		case 3:
			*--target = (UTF8) ((ch | byteMark) & byteMask);
			ch >>= 6;
		case 2:
			*--target = (UTF8) ((ch | byteMark) & byteMask);
			ch >>= 6;
		case 1:
			*--target = (UTF8) (ch | firstByteMark[bytesToWrite]);
		}
		target += bytesToWrite;
	}
	return result;
}


int rs;
long int jgt,sjx,sjy,gjx,gjy;
float yaw,pitch,zxjl,cha1,cha2,cha3,xgyaw,xgpitch,wzz,wzzz,tz,fww,fwww;


	// 定义圆周率
#define PI 3.141592653589793238
double sf = 180 / PI;
typedef unsigned int ADDRESS;
typedef char PACKAGENAME;
typedef unsigned short UTF16;
typedef char UTF8;
#define UNI_SUR_HIGH_START (UTF32)0xD800
#define UNI_SUR_HIGH_END (UTF32)0xDBFF
#define UNI_SUR_LOW_START (UTF32)0xDC00
#define UNI_SUR_LOW_END (UTF32)0xDFFF
	// Some fundamental constants
#define UNI_REPLACEMENT_CHAR (UTF32)0x0000FFFD
#define UNI_MAX_BMP (UTF32)0x0000FFFF
#define UNI_MAX_UTF16 (UTF32)0x0010FFFF
#define UNI_MAX_UTF32 (UTF32)0x7FFFFFFF
#define UNI_MAX_LEGAL_UTF32 (UTF32)0x0010FFFF


int pid, fd, count, ipid, oid, scwz, location;
float angle, camera, r_x, r_y, r_w;

float px;
float py;
unsigned long libbase, Gname, oneself, ye, xu, Object, weapon,
	handheld, Mesh, human, Bone;

// syscall内存读写
#if defined(__arm__)
int process_vm_readv_syscall = 376;
int process_vm_writev_syscall = 377;
#elif defined(__aarch64__)
int process_vm_readv_syscall = 270;
int process_vm_writev_syscall = 271;
#elif defined(__i386__)
int process_vm_readv_syscall = 347;
int process_vm_writev_syscall = 348;
#else
int process_vm_readv_syscall = 310;
int process_vm_writev_syscall = 311;
#endif

ssize_t process_v(pid_t __pid, const struct iovec *__local_iov, unsigned long __local_iov_count,
				  const struct iovec *__remote_iov, unsigned long __remote_iov_count,
				  unsigned long __flags, bool iswrite)
{
	return syscall((iswrite ? process_vm_writev_syscall : process_vm_readv_syscall), __pid,
				   __local_iov, __local_iov_count, __remote_iov, __remote_iov_count, __flags);
}


//获取进程



uintptr_t GetModuleBase(char *name, int index)
    {
        int f = 0, ii = 0, iii = 0;
        long start = 0, end = 0;
        char line[1024] = {0};
        char fname[128];
        char dname[128];
        if (strstr(name, "bss") != NULL) {
            sscanf(name, "%[^:]", dname);
            f++;
        } else {
            sprintf(dname, "%s", name);
        }
        sprintf(fname, "/proc/%d/maps", pid);
        FILE *p = fopen(fname, "r");
        if (p)
        {
            while (fgets(line, sizeof(line), p))
            {
                if (strstr(line, dname) != NULL)
                {
                    iii++;
                    if (f == 0)
                    {
                        if (iii == index)
                        {
                            if (sizeof(long) == 8) {
                                sscanf(line, "%lx-%lx", &start, &end);
                            } else {
                                sscanf(line, "%x-%x", &start, &end);
                            }
                            break;
                        }
                    } else {
                        ii++;
                    }
                }
                if (ii > 0) {
                    if (strstr(line, "[anon:.bss]") != NULL) {
                        if (sizeof(long) == 8) {
                            sscanf(line, "%lx-%lx", &start, &end);
                        } else {
                            sscanf(line, "%x-%x", &start, &end);
                        }
                        break;
                    }
                }
            }
            fclose(p);
        }
        return start;
    }

int getPID(const char *packageName)
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
				if (strcmp(packageName, cmdline) == 0)
				{
					return id;
				}
			}
		}
	}
	closedir(dir);
	return -1;
}

//获取结束


int WriteAddress_FLOAT(long int addr, float value)
{
    char lj[64];
    int handle;
    sprintf(lj, "/proc/%d/mem", pid);
    handle = open(lj, O_RDWR);
    pwrite64(handle, &value, 4, addr);
    return 0;
}
int WriteAddress_DWORD(long int addr, int value)
{
    char lj[64];
    int handle;
    sprintf(lj, "/proc/%d/mem", pid);
    handle = open(lj, O_RDWR);
    pwrite64(handle, &value, 4, addr);
    return 0;
}



bool pvm(void *address, void *buffer, size_t size, bool iswrite)
{
	struct iovec local[1];
	struct iovec remote[1];
	local[0].iov_base = buffer;
	local[0].iov_len = size;
	remote[0].iov_base = address;
	remote[0].iov_len = size;
	if (pid < 0)
	{
		return false;
	}
	ssize_t bytes = process_v(pid, local, 1, remote, 1, 0, iswrite);
	return bytes == size;
}
bool vm_readv(unsigned long address, void *buffer, size_t size)
{
	return pvm(reinterpret_cast < void *>(address), buffer, size, false);
}
bool vm_writev(unsigned long address, void *buffer, size_t size)
{
	return pvm(reinterpret_cast < void *>(address), buffer, size, true);
}



// 获取F类内存
float getFloat(unsigned long addr)
{
	float var = 0;
	vm_readv(addr, &var, 4);
	return (var);
}

// 获取D类内存
int getDword(unsigned long addr)
{
	int var = 0;
	vm_readv(addr, &var, 4);
	return (var);
}
unsigned long getZZ(unsigned long addr)
{
	unsigned long var = 0;
	vm_readv(addr, &var, 4);
	return (var);
}

unsigned long lsp64(unsigned long addr)
{
	unsigned long var = 0;
	vm_readv(addr, &var, 8);
	return (var);
}

// 获取基址
unsigned long get_module_base(int pid, const char *name)
{
	FILE *fp;
	int cnt = 0;
	long start;
	char tmp[256];
	fp = NULL;
	char line[1024];
	char fname[128];
	sprintf(fname, "/proc/%d/maps", pid);
	fp = fopen(fname, "r");
	while (!feof(fp))
	{
		fgets(tmp, 256, fp);
		if (cnt == 1)
		{
			if (strstr(tmp, "[anon:.bss]") != NULL)
			{
				sscanf(tmp, "%lx-%*lx", &start);
				break;
			}
			else
			{
				cnt = 0;
			}
		}
		if (strstr(tmp, name) != NULL)
		{
			cnt = 1;
		}
	}
	return start;
}

int readb(int &c, int num) {
  ++c;
  return num;
}


//获取bss基址
unsigned long get_module_bss(int pid, const char *module_name)
{
	FILE *fp;
	unsigned long addr = 0;
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
					sscanf(line, "%lX", &addr);
					break;
				}
			}
		}
		fclose(fp);
	}
	return addr;
}




// 获取进程是否运行
int isapkrunning(PACKAGENAME * bm)
{
	DIR *dir = NULL;
	struct dirent *ptr = NULL;
	FILE *fp = NULL;
	char filepath[64];
	char filetext[64];
	dir = opendir("/proc/");
	if (dir != NULL)
	{
		while ((ptr = readdir(dir)) != NULL)
		{
			if ((strcmp(ptr->d_name, ".") == 0) || (strcmp(ptr->d_name, "..") == 0))
				continue;
			if (ptr->d_type != DT_DIR)
				continue;
			sprintf(filepath, "/proc/%s/cmdline", ptr->d_name);
			fp = fopen(filepath, "r");
			if (NULL != fp)
			{
				fgets(filetext, sizeof(filetext), fp);
				if (strcmp(filetext, bm) == 0)
				{
					closedir(dir);
					return 1;
				}
				fclose(fp);
			}
		}
	}
	closedir(dir);
	return 0;
}

// 读取字符信息
void getUTF8(UTF8 * buf, unsigned long namepy)
{
	UTF16 buf16[16] = { 0 };
	vm_readv(namepy, buf16, 28);
	UTF16 *pTempUTF16 = buf16;
	UTF8 *pTempUTF8 = buf;
	UTF8 *pUTF8End = pTempUTF8 + 32;
	while (pTempUTF16 < pTempUTF16 + 28)
	{
		if (*pTempUTF16 <= 0x007F && pTempUTF8 + 1 < pUTF8End)
		{
			*pTempUTF8++ = (UTF8) * pTempUTF16;
		}
		else if (*pTempUTF16 >= 0x0080 && *pTempUTF16 <= 0x07FF && pTempUTF8 + 2 < pUTF8End)
		{
			*pTempUTF8++ = (*pTempUTF16 >> 6) | 0xC0;
			*pTempUTF8++ = (*pTempUTF16 & 0x3F) | 0x80;
		}
		else if (*pTempUTF16 >= 0x0800 && *pTempUTF16 <= 0xFFFF && pTempUTF8 + 3 < pUTF8End)
		{
			*pTempUTF8++ = (*pTempUTF16 >> 12) | 0xE0;
			*pTempUTF8++ = ((*pTempUTF16 >> 6) & 0x3F) | 0x80;
			*pTempUTF8++ = (*pTempUTF16 & 0x3F) | 0x80;
		}
		else
		{
			break;
		}
		pTempUTF16++;
	}
}



struct Vector2A {
	float X;
	float Y;

	Vector2A() {
		this->X = 0;
		this->Y = 0;
	}

	Vector2A(float x, float y) {
		this->X = x;
		this->Y = y;
	}
};


struct Vector3A 
{
    #if 0
	float X;
	float Y;
	float Z;

	Vector3A() {
		this->X = 0;
		this->Y = 0;
		this->Z = 0;
	}

	Vector3A(float x, float y, float z) {
		this->X = x;
		this->Y = y;
		this->Z = z;
	}
    #else
    float X;
	float Z;
	float Y;
	Vector3A() 
	{
		this->X = 0;
		this->Z = 0;
		this->Y = 0;
	}

	Vector3A(float x, float z, float y) 
	{
		this->X = x;
		this->Z = z;
		this->Y = y;
	}
    #endif
};

struct Vector4A {
	float x;
	float y;
	float h;
	float w;

	Vector4A() {
		this->x = 0;
		this->y = 0;
		this->h = 0;
		this->w = 0;
	}


	Vector4A (float x, float y, float h, float w) {
		this->x = x;
		this->y = y;
		this->h = h;
		this->w = w;
	}
};


struct Vector3
   {
	float X;
	float Z;
	float Y;

	Vector3() {
		this->X = 0;
		this->Z = 0;
		this->Y = 0;
	}

	Vector3(float x, float z, float y) {
		this->X = x;
		this->Z = z;
		this->Y = y;
	}

};


struct FMatrix {
	float M[4][4];
};

struct Quat {
	float X;
	float Y;
	float Z;
	float W;
};



struct MAPS {
	long int addr;
	long int taddr;
	int type;
	struct MAPS *next;
};

typedef struct MAPS *PMAPS;

#define LEN sizeof(struct MAPS)

/* ------ 相关数据计算 ------ */

Vector2A rotateCoord(float angle, float objRadar_x, float objRadar_y)
{
	Vector2A radarCoordinate;
	float s = sin(angle * PI / 180);
	float c = cos(angle * PI / 180);
	radarCoordinate.X = objRadar_x * c + objRadar_y * s;
	radarCoordinate.Y = -objRadar_x * s + objRadar_y * c;
	return radarCoordinate;
}

Vector2A WorldToScreen(Vector3 obj, float matrix[16], float ViewW)
{
	float x =
		px + (matrix[0] * obj.X + matrix[4] * obj.Y + matrix[8] * obj.Z + matrix[12]) / ViewW * px;
	float y =
		py - (matrix[1] * obj.X + matrix[5] * obj.Y + matrix[9] * obj.Z + matrix[13]) / ViewW * py;

	return Vector2A(x, y);
}

Vector2A WorldToScreen2(Vector3A obj , float matrix[16]) {
	float ViewW = matrix[3] * obj.X + matrix[7] * obj.Y + matrix[11] * obj.Z + matrix[15];
	if (ViewW < 0.01) {
		return Vector2A(3100, 3100);
	}
	float x = px + (matrix[0] * obj.X + matrix[4] * obj.Y + matrix[8] * obj.Z + matrix[12]) / ViewW * px;
	float y = py - (matrix[1] * obj.X + matrix[5] * obj.Y + matrix[9] * obj.Z + matrix[13]) / ViewW * py;
	return Vector2A(x,y);
}

Vector3A MarixToVector(FMatrix matrix) {
	return Vector3A(matrix.M[3][0], matrix.M[3][1], matrix.M[3][2]);
}

FMatrix MatrixMulti(FMatrix m1, FMatrix m2) {
	FMatrix matrix = FMatrix();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				matrix.M[i][j] += m1.M[i][k] * m2.M[k][j];
			}
		}
	}
	return matrix;
}

//骨骼
float matrix[16] = { 0 };

struct D3DXVECTOR4
{
	float X;
	float Y;
	float Z;
	float W;
};
struct FTransform
{
	D3DXVECTOR4 Rotation;
	Vector3A Translation;
	Vector3A Scale3D;
};

struct D3DXMATRIX
{
	float _11;
	float _12;
	float _13;
	float _14;
	float _21;
	float _22;
	float _23;
	float _24;
	float _31;
	float _32;
	float _33;
	float _34;
	float _41;
	float _42;
	float _43;
	float _44;
};

FTransform ReadFTransform(long location);
FTransform ReadFTransform2(long location);
D3DXMATRIX ToMatrixWithScale(Vector4A Rotation, Vector3A Translation, Vector3A Scale3D);
D3DXMATRIX D3DXMatrixMultiply(D3DXMATRIX Pm1, D3DXMATRIX Pm2);
Vector2A rotateCoogetDword(float angle, float objectRadar_x, float objectRadar_y);
Vector3A D3dMatrixMultiply(D3DXMATRIX bonematrix, D3DXMATRIX actormatrix);
Vector3A getBoneXYZ(long humanAddr, long boneAddr, int Part);
Vector2A getBoneCoordinate(long humanAddr, long boneAddr, int Part);
Vector3A getBoneXYZ2(long humanAddr, long boneAddr, int Part);
Vector2A getBoneCoordinate2(long humanAddr, long boneAddr, int Part);

// 获取骨骼3d坐标
Vector3A D3dMatrixMultiply(D3DXMATRIX bonematrix, D3DXMATRIX actormatrix)
{
	Vector3A result;
	result.X =
		bonematrix._41 * actormatrix._11 + bonematrix._42 * actormatrix._21 +
		bonematrix._43 * actormatrix._31 + bonematrix._44 * actormatrix._41;
	result.Y =
		bonematrix._41 * actormatrix._12 + bonematrix._42 * actormatrix._22 +
		bonematrix._43 * actormatrix._32 + bonematrix._44 * actormatrix._42;
	result.Z =
		bonematrix._41 * actormatrix._13 + bonematrix._42 * actormatrix._23 +
		bonematrix._43 * actormatrix._33 + bonematrix._44 * actormatrix._43;
	return result;
}


		// 计算旋转坐标
Vector2A rotateCoogetDword(float angle, float objectRadar_x, float objectRadar_y)
{
	Vector2A radarCoogetDwordinate;
	float s = sin(angle * PI / 180);
	float c = cos(angle * PI / 180);
	radarCoogetDwordinate.X = objectRadar_x * c + objectRadar_y * s;
	radarCoogetDwordinate.Y = -objectRadar_x * s + objectRadar_y * c;
	return radarCoogetDwordinate;
}


D3DXMATRIX ToMatrixWithScale(D3DXVECTOR4 Rotation, Vector3A Translation, Vector3A Scale3D)
{
	D3DXMATRIX M;
	float X2, Y2, Z2, xX2, Yy2, Zz2, Zy2, Wx2, Xy2, Wz2, Zx2, Wy2;
	M._41 = Translation.X;
	M._42 = Translation.Y;
	M._43 = Translation.Z;
	X2 = Rotation.X + Rotation.X;
	Y2 = Rotation.Y + Rotation.Y;
	Z2 = Rotation.Z + Rotation.Z;
	xX2 = Rotation.X * X2;
	Yy2 = Rotation.Y * Y2;
	Zz2 = Rotation.Z * Z2;
	M._11 = (1 - (Yy2 + Zz2)) * Scale3D.X;
	M._22 = (1 - (xX2 + Zz2)) * Scale3D.Y;
	M._33 = (1 - (xX2 + Yy2)) * Scale3D.Z;
	Zy2 = Rotation.Y * Z2;
	Wx2 = Rotation.W * X2;
	M._32 = (Zy2 - Wx2) * Scale3D.Z;
	M._23 = (Zy2 + Wx2) * Scale3D.Y;
	Xy2 = Rotation.X * Y2;
	Wz2 = Rotation.W * Z2;
	M._21 = (Xy2 - Wz2) * Scale3D.Y;
	M._12 = (Xy2 + Wz2) * Scale3D.X;
	Zx2 = Rotation.X * Z2;
	Wy2 = Rotation.W * Y2;
	M._31 = (Zx2 + Wy2) * Scale3D.Z;
	M._13 = (Zx2 - Wy2) * Scale3D.X;
	M._14 = 0;
	M._24 = 0;
	M._34 = 0;
	M._44 = 1;
	return M;
}

FMatrix TransformToMatrix(FTransform transform)
{
	FMatrix matrix;
	matrix.M[3][0] = transform.Translation.X;
	matrix.M[3][1] = transform.Translation.Y;
	matrix.M[3][2] = transform.Translation.Z;
	float x2 = transform.Rotation.X + transform.Rotation.X;
	float y2 = transform.Rotation.Y + transform.Rotation.Y;
	float z2 = transform.Rotation.Z + transform.Rotation.Z;
	float xx2 = transform.Rotation.X * x2;
	float yy2 = transform.Rotation.Y * y2;
	float zz2 = transform.Rotation.Z * z2;
	matrix.M[0][0] = (1 - (yy2 + zz2)) * transform.Scale3D.X;
	matrix.M[1][1] = (1 - (xx2 + zz2)) * transform.Scale3D.Y;
	matrix.M[2][2] = (1 - (xx2 + yy2)) * transform.Scale3D.Z;
	float yz2 = transform.Rotation.Y * z2;
	float wx2 = transform.Rotation.W * x2;
	matrix.M[2][1] = (yz2 - wx2) * transform.Scale3D.Z;
	matrix.M[1][2] = (yz2 + wx2) * transform.Scale3D.Y;
	float xy2 = transform.Rotation.X * y2;
	float wz2 = transform.Rotation.W * z2;
	matrix.M[1][0] = (xy2 - wz2) * transform.Scale3D.Y;
	matrix.M[0][1] = (xy2 + wz2) * transform.Scale3D.X;
	float xz2 = transform.Rotation.X * z2;
	float wy2 = transform.Rotation.W * y2;
	matrix.M[2][0] = (xz2 + wy2) * transform.Scale3D.Z;
	matrix.M[0][2] = (xz2 - wy2) * transform.Scale3D.X;
	matrix.M[0][3] = 0;
	matrix.M[1][3] = 0;
	matrix.M[2][3] = 0;
	matrix.M[3][3] = 1;
	return matrix;
}

FTransform getBone(unsigned long addr)
{
	FTransform transform;
	vm_readv(addr, &transform, 4 * 11);
	return transform;
}

D3DXMATRIX D3DXMatrixMultiply(D3DXMATRIX Pm1, D3DXMATRIX Pm2)
{
	D3DXMATRIX Pout;
	Pout._11 = Pm1._11 * Pm2._11 + Pm1._12 * Pm2._21 + Pm1._13 * Pm2._31 + Pm1._14 * Pm2._41;
	Pout._12 = Pm1._11 * Pm2._12 + Pm1._12 * Pm2._22 + Pm1._13 * Pm2._32 + Pm1._14 * Pm2._42;
	Pout._13 = Pm1._11 * Pm2._13 + Pm1._12 * Pm2._23 + Pm1._13 * Pm2._33 + Pm1._14 * Pm2._43;
	Pout._14 = Pm1._11 * Pm2._14 + Pm1._12 * Pm2._24 + Pm1._13 * Pm2._34 + Pm1._14 * Pm2._44;
	Pout._21 = Pm1._21 * Pm2._11 + Pm1._22 * Pm2._21 + Pm1._23 * Pm2._31 + Pm1._24 * Pm2._41;
	Pout._22 = Pm1._21 * Pm2._12 + Pm1._22 * Pm2._22 + Pm1._23 * Pm2._32 + Pm1._24 * Pm2._42;
	Pout._23 = Pm1._21 * Pm2._13 + Pm1._22 * Pm2._23 + Pm1._23 * Pm2._33 + Pm1._24 * Pm2._43;
	Pout._24 = Pm1._21 * Pm2._14 + Pm1._22 * Pm2._24 + Pm1._23 * Pm2._34 + Pm1._24 * Pm2._44;
	Pout._31 = Pm1._31 * Pm2._11 + Pm1._32 * Pm2._21 + Pm1._33 * Pm2._31 + Pm1._34 * Pm2._41;
	Pout._32 = Pm1._31 * Pm2._12 + Pm1._32 * Pm2._22 + Pm1._33 * Pm2._32 + Pm1._34 * Pm2._42;
	Pout._33 = Pm1._31 * Pm2._13 + Pm1._32 * Pm2._23 + Pm1._33 * Pm2._33 + Pm1._34 * Pm2._43;
	Pout._34 = Pm1._31 * Pm2._14 + Pm1._32 * Pm2._24 + Pm1._33 * Pm2._34 + Pm1._34 * Pm2._44;
	Pout._41 = Pm1._41 * Pm2._11 + Pm1._42 * Pm2._21 + Pm1._43 * Pm2._31 + Pm1._44 * Pm2._41;
	Pout._42 = Pm1._41 * Pm2._12 + Pm1._42 * Pm2._22 + Pm1._43 * Pm2._32 + Pm1._44 * Pm2._42;
	Pout._43 = Pm1._41 * Pm2._13 + Pm1._42 * Pm2._23 + Pm1._43 * Pm2._33 + Pm1._44 * Pm2._43;
	Pout._44 = Pm1._41 * Pm2._14 + Pm1._42 * Pm2._24 + Pm1._43 * Pm2._34 + Pm1._44 * Pm2._44;
	return Pout;
}
//骨骼🤔

FTransform ReadFTransform(long address)
{
	FTransform Result;
	Result.Rotation.X = getFloat(address);	// Rotation_X 
	Result.Rotation.Y = getFloat(address + 4);	// Rotation_y
	Result.Rotation.Z = getFloat(address + 8);	// Rotation_z
	Result.Rotation.W = getFloat(address + 12);	// Rotation_w
	Result.Translation.X = getFloat(address + 16);	// /Translation_X
	Result.Translation.Y = getFloat(address + 20);	// Translation_y
	Result.Translation.Z = getFloat(address + 24);	// Translation_z
	Result.Scale3D.X = getFloat(address + 28);	// Scale_X
	Result.Scale3D.Y = getFloat(address + 32);	// Scale_y
	Result.Scale3D.Z = getFloat(address + 36);	// Scale_z
	return Result;
}

Vector2A getBoneCoordinate(long humanAddr, long boneAddr, int Part)
{
	Vector2A result;
	// 获取Bone数据
	FTransform Bone = ReadFTransform(boneAddr + Part * 48);
	// 获取Actor数据
	FTransform Actor = ReadFTransform(humanAddr);
	D3DXMATRIX Bone_Matrix = ToMatrixWithScale(Bone.Rotation, Bone.Translation, Bone.Scale3D);
	D3DXMATRIX Component_ToWorld_Matrix =
		ToMatrixWithScale(Actor.Rotation, Actor.Translation, Actor.Scale3D);
	D3DXMATRIX New_Matrix = D3DXMatrixMultiply(Bone_Matrix, Component_ToWorld_Matrix);
	float ViewW =
		matrix[3] * New_Matrix._41 + matrix[7] * New_Matrix._42 + matrix[11] * New_Matrix._43 + matrix[15];
		result.X =
			px + (matrix[0] * New_Matrix._41 + matrix[4] * New_Matrix._42 +
				  matrix[8] * New_Matrix._43 + matrix[12]) / ViewW * px;
		result.Y =
			py - (matrix[1] * New_Matrix._41 + matrix[5] * New_Matrix._42 +
				  matrix[9] * New_Matrix._43 + matrix[13]) / ViewW * py;
	
	return result;
}


Vector3A getBoneXYZ(long humanAddr, long boneAddr, int Part)
{
	// 获取Bone数据
	FTransform Bone = ReadFTransform(boneAddr + Part * 48);
	// 获取Actor数据
	FTransform Actor = ReadFTransform(humanAddr);
	D3DXMATRIX Bone_Matrix = ToMatrixWithScale(Bone.Rotation, Bone.Translation, Bone.Scale3D);
	D3DXMATRIX Component_ToWorld_Matrix =
		ToMatrixWithScale(Actor.Rotation, Actor.Translation, Actor.Scale3D);
	Vector3A result = D3dMatrixMultiply(Bone_Matrix, Component_ToWorld_Matrix);
	return result;
}

    
bool getMaterial(char* GUNname, char** name)
{
    if (strstr(GUNname, "12Gauge") != 0)
    {
        *name = "霰弹";
        return true;
    }else if (strstr(GUNname, "556mm") != 0)
    {
        *name = "5.56";
        return true;
    }else if (strstr(GUNname, "762mm") != 0)
    {
        *name = "7.62";
        return true;
    }else if (strstr(GUNname, "9mm") != 0)
    {
        *name = "9mm";
        return true;
    }else if (strstr(GUNname, "dot300Magnum") != 0)
    {
        *name = "AWM子弹";
        return true;
    }else if (strstr(GUNname, "dot45ACP") != 0)
    {
        *name = "白色冲锋枪子弹";
        return true;
    }else if (strstr(GUNname, "AngledForegrip") != 0)
    {
        *name = "直角握把";
        return true; 
    }else if (strstr(GUNname, "VerticalForegrip") != 0)
    {
        *name = "垂直握把";
        return true;    
    }else if (strstr(GUNname, "ExtendedMagAssaultRifles") != 0)
    {
        *name = "步枪扩容弹夹";
        return true;    
    }else if (strstr(GUNname, "ExtendedMagPistols") != 0)
    {
        *name = "手枪扩容弹夹";
        return true;   
    }else if (strstr(GUNname, "ExtendedMagSinperRifles") != 0)
    {
        *name = "狙击枪扩容弹夹";
        return true;   
    }else if (strstr(GUNname, "ExtendedMagSubmachine") != 0)
    {
        *name = "冲锋枪扩容弹夹";
        return true;  
    }else if (strstr(GUNname, "ExtendedQuickDrawMagAssaultRifles") != 0)
    {
        *name = "步枪快速扩容弹夹";
        return true;
    }else if (strstr(GUNname, "ExtendedQuickDrawMagPistols") != 0)
    {
        *name = "手枪快速扩容弹夹";
        return true;
    }else if (strstr(GUNname, "ExtendedQuickDrawMagSinperRifles") != 0)
    {
        *name = "狙击枪快速扩容弹夹";
        return true;
    }else if (strstr(GUNname, "ExtendedQuickDrawMagSubmachine") != 0)
    {
        *name = "冲锋枪快速扩容弹夹";
        return true;
    }else if (strstr(GUNname, "QuickDrawMagAssaultRifles") != 0)
    {
        *name = "步枪快速弹夹";
        return true;
    }else if (strstr(GUNname, "QuickDrawMagPistols") != 0)
    {
        *name = "手枪快速弹夹";
        return true;
    }else if (strstr(GUNname, "QuickDrawMagSinperRifles") != 0)
    {
        *name = "狙击枪快速弹夹";
        return true;
    }else if (strstr(GUNname, "QuickDrawMagSubmachine") != 0)
    {
        *name = "冲锋枪快速弹夹";
        return true;
    }else if (strstr(GUNname, "Choke") != 0)
    {
        *name = "霰弹枪收束";
        return true;
    }else if (strstr(GUNname, "CompensatorAssaultRifles") != 0)
    {
        *name = "步枪补偿";
        return true;
    }else if (strstr(GUNname, "CompensatorSniperRifles") != 0)
    {
        *name = "狙击枪补偿";
        return true;
      }else if (strstr(GUNname, "CompensatorSubmachine") != 0)
    {
        *name = "冲锋枪补偿";
        return true;
    }else if (strstr(GUNname, "FlashHiderAssaultRifles") != 0)
    {
        *name = "步枪消焰";
        return true;
    }else if (strstr(GUNname, "FlashHiderSniperRifles") != 0)
    {
        *name = "狙击枪消焰";
        return true;
    }else if (strstr(GUNname, "FlashHiderSubmachine") != 0)
    {
        *name = "冲锋枪消焰";
        return true;
    }else if (strstr(GUNname, "SuppressorAssaultRifles") != 0)
    {
        *name = "步枪消音";
        return true;
    }else if (strstr(GUNname, "SuppressorPistols") != 0)
    {
        *name = "手枪消音";
        return true;
    }else if (strstr(GUNname, "SuppressorSinperRifles") != 0)
    {
        *name = "狙击枪消音";
        return true;
    }else if (strstr(GUNname, "SuppressorSubmachine") != 0)
    {
        *name = "冲锋枪消音";
        return true;
    }else if (strstr(GUNname, "BulletLoops98k") != 0) 
    {
        *name = "98k子弹袋";
        return true;
    }else if (strstr(GUNname, "BulletLoopsS1897S686") != 0)
    {
        *name = "霰弹枪子弹袋";
        return true;
    }else if (strstr(GUNname, "CheekPad") != 0)
    {
        *name = "狙击枪托腮";
        return true;
    }else if (strstr(GUNname, "StockMicroUZI") != 0)
    {
        *name = "uzi枪托";
        return true;
    }else if (strstr(GUNname, "TactialStock") != 0)
    {
        *name = "战术枪托";
        return true;
    }else if (strstr(GUNname, "15x") != 0)
    {
        *name = "15倍镜";
        return true;
    }else if (strstr(GUNname, "2x") != 0)
    {
        *name = "2倍镜";
        return true;
    }else if (strstr(GUNname, "3x") != 0)
    {
        *name = "3倍镜";
        return true;  

    }else if (strstr(GUNname, "4x") != 0)
    {
        *name = "4倍镜";
        return true;
    }else if (strstr(GUNname, "6x") != 0)
    {
        *name = "6倍镜";
        return true;
    }else if (strstr(GUNname, "8x") != 0)
    {
        *name = "8倍镜";
        return true;
    }else if (strstr(GUNname, "QX") != 0)
    {
        *name = "全息";
        return true;
    }else if (strstr(GUNname, "Bandage") != 0)
    {
        *name = "绑带";
        return true;
    }else if (strstr(GUNname, "EnergyDrink") != 0)
    {
        *name = "能量饮料";
        return true;
    }else if (strstr(GUNname, "FirstAidKit") != 0)
    {
        *name = "急救包";
        return true;
    }else if (strstr(GUNname, "MedKit") != 0)
    {
        *name = "医疗箱";
        return true;
    }else if (strstr(GUNname, "Oilbucket") != 0)
    {
        *name = "彩虹能源";
        return true;
    }else if (strstr(GUNname, "Painkiller") != 0)
    {
        *name = "止痛药";
        return true;
    }else if (strstr(GUNname, "VestLeve1_1") != 0)
    {
        *name = "1级防弹衣";
        return true;
    }else if (strstr(GUNname, "VestLeve2_1") != 0)
    {
        *name = "2级防弹衣";
        return true;
    }else if (strstr(GUNname, "VestLeve3_1") != 0)
    {
        *name = "3级防弹衣";
        return true;
    }else if (strstr(GUNname, "BackpackLevel1") != 0)
    {
        *name = "1级背包";
        return true;
    }else if (strstr(GUNname, "BackpackLevel2") != 0)
    {
        *name = "2级背包";
        return true;
    }else if (strstr(GUNname, "BackpackLevel3") != 0)
    {
        *name = "3级背包";
        return true;
    }else if (strstr(GUNname, "GhillieShrubs") != 0)
    {
        *name = "吉利服";
        return true;
     }else if (strstr(GUNname, "SwimringDuck") != 0)
    {
        *name = "游泳圈";
        return true;
     }else if (strstr(GUNname, "HelmetLeve1_1") != 0)
    {
        *name = "1级头盔";
        return true;
        }else if (strstr(GUNname, "HelmetLeve2_1") != 0)
    {
        *name = "2级头盔";
        return true;
    }else if (strstr(GUNname, "HelmetLeve3_1") != 0)
    {
        *name = "3级头盔";
        return true;
    }else if (strstr(GUNname, "AKM") != 0)
    {
        *name = "AK步枪";
        return true;  
    }else if (strstr(GUNname, "AUG") != 0)
    {
        *name = "AUG步枪";
        return true;        
    }else if (strstr(GUNname, "Groza") != 0)
    {
        *name = "狗杂";
        return true;        
    }else if (strstr(GUNname, "M16A4") != 0)
    {
        *name = "M16A4";
        return true;        
    }else if (strstr(GUNname, "M416") != 0)
    {
        *name = "M416";
        return true;        
    }else if (strstr(GUNname, "SCARL") != 0)
    {
        *name = "死嘎步枪";
        return true;        
    }else if (strstr(GUNname, "DiscoBomb") != 0)
    {
        *name = "治疗弹";
        return true;        
    }else if (strstr(GUNname, "Grenade") != 0)
    {
        *name = "巴雷特子弹";
        return true;        
    }else if (strstr(GUNname, "dot50BMG") != 0)
    {
        *name = "手雷";
        return true;        
    }else if (strstr(GUNname, "InkOcclusion") != 0)
    {
        *name = "雪球";
        return true;        
    }else if (strstr(GUNname, "PinkSmokeShell") != 0)
    {
        *name = "爱心云雾弹";
        return true;        
    }else if (strstr(GUNname, "SmokeShell") != 0)
    {
        *name = "云雾弹";
        return true;        
    }else if (strstr(GUNname, "MK14") != 0)
    {
        *name = "妹控";
        return true;        
    }else if (strstr(GUNname, "Mini14") != 0)
    {
        *name = "Mini14";
        return true;        
    }else if (strstr(GUNname, "SKS") != 0)
    {
        *name = "SKS";
        return true;        
    }else if (strstr(GUNname, "SLR") != 0)
    {
        *name = "SLR";
        return true;        
    }else if (strstr(GUNname, "VSS") != 0)
    {
        *name = "VSS";
        return true;        
    }else if (strstr(GUNname, "DP28") != 0)
    {
        *name = "大盘鸡";
        return true;        
    }else if (strstr(GUNname, "M249") != 0)
    {
        *name = "大菠萝";
        return true;        
    }else if (strstr(GUNname, "Bat") != 0)
    {
        *name = "棒球棍";
        return true;                
    }else if (strstr(GUNname, "Fork") != 0)
    {
        *name = "小叉子";
        return true;                
    }else if (strstr(GUNname, "Pan") != 0)
    {
        *name = "平底锅";
        return true;                
    }else if (strstr(GUNname, "Plunger") != 0)
    {
        *name = "马桶塞";
        return true;        
    }else if (strstr(GUNname, "RainbowMagicWand") != 0)
    {
        *name = "魔法棒";
        return true;                
    }else if (strstr(GUNname, "P18C") != 0)
    {
        *name = "P18C";
        return true;                
    }else if (strstr(GUNname, "P1911") != 0)
    {
        *name = "P1911";
        return true;            
     }else if (strstr(GUNname, "P92") != 0)
    {
        *name = "P92";
        return true;               
     }else if (strstr(GUNname, "R1895") != 0)
    {
        *name = "R1895";
        return true;               
    }else if (strstr(GUNname, "S12K") != 0)
    {
        *name = "S12K";
        return true;                
    }else if (strstr(GUNname, "S1897") != 0)
    {
        *name = "S1897";
        return true;                
    }else if (strstr(GUNname, "S686") != 0)
    {
        *name = "S686";
        return true;                
    }else if (strstr(GUNname, "AWM") != 0)
    {
        *name = "AWM";
        return true;                
     }else if (strstr(GUNname, "Kar98") != 0)
    {
        *name = "98k";
        return true;               
     }else if (strstr(GUNname, "M24") != 0)
    {
        *name = "M24";
        return true;               
    }else if (strstr(GUNname, "MicroUZI") != 0)
    {
        *name = "uzi";
        return true;                
    }else if (strstr(GUNname, "TommyGun") != 0)
    {
        *name = "汤姆逊";
        return true;                
    }else if (strstr(GUNname, "UMP9") != 0)
    {
        *name = "UMP9";
        return true;                
    }else if (strstr(GUNname, "Vector") != 0)
    {
        *name = "维克托";
        return true;                
     }else if (strstr(GUNname, "TransportItem") != 0)
    {
        *name = "传送胶囊";
        return true;               
     }else if (strstr(GUNname, "TransportItem") != 0)
    {
        *name = "传送胶囊";
        return true;                  
     }else if (strstr(GUNname, "Jeep") != 0)
    {
        *name = "吉普车";
        return true;                  
     }else if (strstr(GUNname, "Buggy") != 0)
    {
        *name = "蹦蹦车";
        return true;                  
     }else if (strstr(GUNname, "Kayak") != 0)
    {
        *name = "快艇";
        return true;                  
     }else if (strstr(GUNname, "HelmetLeve4_1") != 0)
    {
        *name = "4级头盔";
        return true;                  
     }else if (strstr(GUNname, "VestLeve4_1") != 0)
    {
        *name = "4级防弹衣";
        return true;                          
     }else if (strstr(GUNname, "BackpackLevel4") != 0)
    {
        *name = "4级背包";
        return true;                  
     }else if (strstr(GUNname, "SuppressorAssaultRifles_Lv4") != 0)
    {
        *name = "高级步枪消音";
        return true;                  
     }else if (strstr(GUNname, "SuppressorSubmachine_Lv4") != 0)
    {
        *name = "高级冲锋枪消音";
        return true;                          
     }else if (strstr(GUNname, "SuppressorSinperRifles_Lv4") != 0)
    {
        *name = "高级狙击枪消音";
        return true;               
     }else if (strstr(GUNname, "VerticalForegrip_Lv4") != 0)
    {
        *name = "高级垂直握把";
        return true;                  
     }else if (strstr(GUNname, "CheekPad_Lv4") != 0)
    {
        *name = "高级狙击枪托腮";
        return true;                  
     }else if (strstr(GUNname, "ExtendedQuickDrawMagAssaultRifles_Lv4") != 0)
    {
        *name = "高级步枪快速扩容弹夹";
        return true;                  
     }else if (strstr(GUNname, "ExtendedQuickDrawMagSinperRifles_Lv4") != 0)
    {
        *name = "高级狙击枪快速扩容弹夹";
        return true;                  
     }else if (strstr(GUNname, "ExtendedQuickDrawMagSubmachine_Lv4") != 0)
    {
        *name = "高级冲锋枪快速扩容弹夹";
        return true;                  
     }else if (strstr(GUNname, "SG") != 0)
    {
        *name = "KSG";
        return true;                          
     }else if (strstr(GUNname, "SignalGun") != 0)
    {
        *name = "信号枪";
        return true;                  
     }else if (strstr(GUNname, "SignalFlare") != 0)
    {
        *name = "信号弹";
        return true;                  
     }else if (strstr(GUNname, "Minigun") != 0)
    {
        *name = "加特林";
        return true;                                  
     }else if (strstr(GUNname, "SandCastle") != 0)
    {
        *name = "战术掩体";
        return true;               
     }else if (strstr(GUNname, "Projectile") != 0)
    {
        *name = "火箭弹";
        return true;                  
     }else if (strstr(GUNname, "RPG") != 0)
    {
        *name = "火箭筒";
        return true;                  
     }else if (strstr(GUNname, "QBZ") != 0)
    {
        *name = "QBZ";
        return true;                  
     }else if (strstr(GUNname, "LaserSight") != 0)
    {
        *name = "激光瞄准器";
        return true;                  
     }else if (strstr(GUNname, "ShipAnchor") != 0)
    {
        *name = "拉钩钩";
        return true;                  
     }else if (strstr(GUNname, "SlimeBomb") != 0)
    {
        *name = "波波";
        return true;                          
     }else if (strstr(GUNname, "IDCard_Tiga") != 0)
    {
        *name = "泰迦身份卡";
        return true;                  
     }else if (strstr(GUNname, "TRexKing") != 0)
    {
        *name = "凶凶龙王";
        return true;                  
     }else if (strstr(GUNname, "Peterosaur") != 0)
    {
        *name = "飘飘龙";
        return true;                                  
     }else if (strstr(GUNname, "Triceratops") != 0)
    {
        *name = "憨憨龙";
        return true;               
     }else if (strstr(GUNname, "Raptors") != 0)
    {
        *name = "奔奔龙";
        return true;                  
     }else if (strstr(GUNname, "ActivityFoolBox1") != 0)
    {
        *name = "礼盒";
        return true;                  
     }else if (strstr(GUNname, "WaterBalloon2022") != 0)
    {
        *name = "水球";
        return true;                  
     }else if (strstr(GUNname, "PirateCannon") != 0)
    {
        *name = "传送大炮";
        return true;                  
     }else if (strstr(GUNname, "CircusBall") != 0)
    {
        *name = "皮皮球";
        return true;                  
     }else if (strstr(GUNname, "GrenadeMax") != 0)
    {
        *name = "MAX手雷";
        return true;                          
     }else if (strstr(GUNname, "IDCard_Zeta") != 0)
    {
        *name = "泽塔身份卡";
        return true;                  
     }else if (strstr(GUNname, "IDCard_Zero") != 0)
    {
        *name = "赛罗身份卡";
        return true;                  
     }else if (strstr(GUNname, "IDCard_Geed") != 0)
    {
        *name = "捷德身份卡";
        return true;                                  
     }else if (strstr(GUNname, "IDCard_Flyman") != 0)
    {
        *name = "飞翼身份卡";
        return true;               
     }else if (strstr(GUNname, "JetCar") != 0)
    {
        *name = "飞车";
        return true;                  
     }else if (strstr(GUNname, "IDCard_Rainbow") != 0)
    {
        *name = "彩虹王子身份卡";
        return true;                  
     }else if (strstr(GUNname, "HolySword") != 0)
    {
        *name = "圣剑";
        return true;                  
     }else if (strstr(GUNname, "SummonMachineArmorGun") != 0)
    {
        *name = "唤甲枪";
        return true;                  
     }else if (strstr(GUNname, "SummonMachineArmorGunBullet") != 0)
    {
        *name = "唤甲弹";
        return true;                  
     }else if (strstr(GUNname, "Lego") != 0)
    {
        *name = "积木";
        return true;                          
     }else if (strstr(GUNname, "IDCard_Zeus") != 0)
    {
        *name = "神王身份卡";
        return true;                  
     }else if (strstr(GUNname, "LightningBombBullet") != 0)
    {
        *name = "神王雷矛";
        return true;                  
     }else if (strstr(GUNname, "IDCard_Hades") != 0)
    {
        *name = "冥王身份卡";
        return true;                                  
     }else if (strstr(GUNname, "IDCard_Poseidon") != 0)
    {
        *name = "海王身份卡";
        return true;               
     }else if (strstr(GUNname, "IDCard_ZhuGeLiang") != 0)
    {
        *name = "军师身份卡";
        return true;                  
     }else if (strstr(GUNname, "ArrowTowerBullet") != 0)
    {
        *name = "箭塔箭矢";
        return true;                  
     }else if (strstr(GUNname, "IDCard_PaoKu") != 0)
    {
        *name = "球球身份卡";
        return true;                  
     }else if (strstr(GUNname, "AK12") != 0)
    {
        *name = "AK12";
        return true;                  
     }else if (strstr(GUNname, "SwordSpirit") != 0)
    {
        *name = "圣剑剑气";
        return true;                  
     }else if (strstr(GUNname, "DragonFire") != 0)
    {
        *name = "呆呆龙火球";
        return true;                          
     }else if (strstr(GUNname, "IDCard_AidMei") != 0)
    {
        *name = "甜心身份卡";
        return true;                  
     }else if (strstr(GUNname, "Barrett") != 0)
    {
        *name = "巴勒特";
        return true;                  
     }else if (strstr(GUNname, "dot50BMG") != 0)
    {
        *name = "巴勒特子弹";
        return true;                                  
   }else if (strstr(GUNname, "IDCard_ZhuGeLiang") != 0)
    {
        *name = "军师身份卡";
        return true;                  
     }else if (strstr(GUNname, "ArrowTowerBullet") != 0)
    {
        *name = "箭塔箭矢";
        return true;                  
     }else if (strstr(GUNname, "Machine_Carrier") != 0)
    {
        *name = "变形机甲";
        return true;                  
     }else if (strstr(GUNname, "ArmoredBus") != 0)
    {
        *name = "装甲巴士";
        return true;                  
     }else if (strstr(GUNname, "ZiZiBeng") != 0)
    {
        *name = "能量灸灸炮";
        return true;                  
     }else if (strstr(GUNname, "Dragon") != 0)
    {
        *name = "呆呆龙";
        return true;                          
     }else if (strstr(GUNname, "ARSuit") != 0)
    {
        *name = "全息装置";
        return true;                  
     }else if (strstr(GUNname, "UFO") != 0)
    {
        *name = "飞碟";
        return true;                  
     }else if (strstr(GUNname, "ActivityFoolBox") != 0)
    {
        *name = "礼盒";
        return true;                                   
   }else if (strstr(GUNname, "EnergySmg") != 0)
    {
        *name = "能量双枪";
        return true;                  
     }else if (strstr(GUNname, "ActivityFunnyBox") != 0)
    {
        *name = "有趣君";
        return true;                  
     }else if (strstr(GUNname, "Bigger") != 0)
    {
        *name = "变大大";
        return true;                  
     }else if (strstr(GUNname, "PonyVehicle") != 0)
    {
        *name = "小马";
        return true;                  
     }else if (strstr(GUNname, "ActivityRedPacket") != 0)
    {
        *name = "虎年红包";
        return true;                  
     }else if (strstr(GUNname, "ShiftDevice") != 0)
    {
        *name = "传送手雷";
        return true;                          
     }else if (strstr(GUNname, "PanBigger") != 0)
    {
        *name = "披萨平底锅";
        return true;                  
     }else if (strstr(GUNname, "PizzaPackage") != 0)
    {
        *name = "必胜客套餐";
        return true;                  
     }else if (strstr(GUNname, "ActivityPizza") != 0)
    {
        *name = "披萨";
        return true;                               
   }else if (strstr(GUNname, "IDCard_SnowGirl") != 0)
    {
        *name = "雪女身份卡";
        return true;                  
     }else if (strstr(GUNname, "FireBall") != 0)
    {
        *name = "火球";
        return true;                  
     }else if (strstr(GUNname, "SummonGun") != 0)
    {
        *name = "唤龙枪";
        return true;                  
     }else if (strstr(GUNname, "SummonBullet") != 0)
    {
        *name = "唤龙弹";
        return true;                  
     }else if (strstr(GUNname, "TransMagicWand") != 0)
    {
        *name = "魔法棒";
        return true;                  
     }else if (strstr(GUNname, "ExpressionInkOcclusion") != 0)
    {
        *name = "特制呜呜弹";
        return true;                          
     }else if (strstr(GUNname, "FocusGun") != 0)
    {
        *name = "能量加速机枪";
        return true;                  
     }else if (strstr(GUNname, "RailGun") != 0)
    {
        *name = "蓄能炮";
        return true;                  
     }else if (strstr(GUNname, "ChargeBullet") != 0)
    {
        *name = "能量子弹";
        return true;                                   
   }else if (strstr(GUNname, "CapacityChip") != 0)
    {
        *name = "扩容芯片";
        return true;                  
     }else if (strstr(GUNname, "PreciseChip") != 0)
    {
        *name = "精准芯片";
        return true;                  
     }else if (strstr(GUNname, "HolySwordFire") != 0)
    {
        *name = "猎魔剑";
        return true;                  
     }else if (strstr(GUNname, "ActivityFirecrackers") != 0)
    {
        *name = "鞭炮";
        return true;                  
     }else if (strstr(GUNname, "ActivityBell") != 0)
    {
        *name = "铃铛";
        return true;                  
     }else if (strstr(GUNname, "IDCard_WolfMan") != 0)
    {
        *name = "狼王身份卡";
        return true;                          
     }else if (strstr(GUNname, "DemonMachete") != 0)
    {
        *name = "魔刀";
        return true;                  
     }else if (strstr(GUNname, "IDCard_CaoCao") != 0)
    {
        *name = "枭雄身份卡";
        return true;                  
     }else if (strstr(GUNname, "HandCannon") != 0)
    {
        *name = "手炮";
        return true;                                   
   }else if (strstr(GUNname, "IDCard_Ninja") != 0)
    {
        *name = "影武者身份卡";
        return true;                  
     }else if (strstr(GUNname, "ParticleCannon") != 0)
    {
        *name = "能量粒子炮";
        return true;                  
     }else if (strstr(GUNname, "ActivityLamp") != 0)
    {
        *name = "神灯";
        return true;                  
     }else if (strstr(GUNname, "ActivityBelial") != 0)
    {
        *name = "恶魔碎片";
        return true;                  
     }else if (strstr(GUNname, "IDCard_GuanYu") != 0)
    {
        *name = "武圣身份卡";
        return true;                  
     }else if (strstr(GUNname, "P90") != 0)
    {
        *name = "P90";
        return true;                          
     }else if (strstr(GUNname, "VictoryPistol") != 0)
    {
        *name = "胜利海帕枪";
        return true;                  
     }else if (strstr(GUNname, "ActivityShovel") != 0)
    {
        *name = "小铲子";
        return true;                  
     }else if (strstr(GUNname, "QuickChip") != 0)
    {
        *name = "快速装填芯片";
        return true;                                   
   }else if (strstr(GUNname, "TurboChip") != 0)
    {
        *name = "高速预热芯片";
        return true;                  
     }else if (strstr(GUNname, "ExtendedChip") != 0)
    {
        *name = "能量扩容芯片";
        return true;                  
     }else if (strstr(GUNname, "LaserChip") != 0)
    {
        *name = "腰射精淮度特化芯片";
        return true;                  
     }else if (strstr(GUNname, "HorizontalChip") != 0)
    {
        *name = "水平后坐力特化芯片";
        return true;                  
     }else if (strstr(GUNname, "VerticalChip") != 0)
    {
        *name = "垂直后坐力特化芯片";
        return true;                  
     }else if (strstr(GUNname, "RpmBoostChip") != 0)
    {
        *name = "射速提升芯片";
        return true;                          
     }else if (strstr(GUNname, "DamageBoostChip") != 0)
    {
        *name = "伤害提升芯片";
        return true;                  
     }else if (strstr(GUNname, "Tavor") != 0)
    {
        *name = "Tavor";
        return true;                  
     }else if (strstr(GUNname, "IDCard_Taiga") != 0)
    {
        *name = "泰迦身份卡";
        return true;                                   
   }else if (strstr(GUNname, "Gutswing") != 0)
    {
        *name = "胜利飞燕号";
        return true;                              
     }
   }
