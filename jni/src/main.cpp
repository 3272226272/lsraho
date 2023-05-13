#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <pthread.h>
#include <fstream>
#include <string.h>
#include <time.h>
#include <malloc.h>
#include <iostream>
#include <fstream>
#include <sys/system_properties.h>
#include <ctime>
#include <main.h>
#include <stdlib.h>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

int main()
{	  
    screen_config();
    init_screen_x = screen_x + screen_y;
    init_screen_y = screen_y + screen_x;
	if(!init_egl(init_screen_x,init_screen_y)) 
	{
     exit(0);
    }
    ImGui_init(); 
	
	new std::thread(Getwuz);
    new std::thread(GetTouch2);
    new std::thread(GetTouch);
    new std::thread(AimBotAuto);
	
    while (1)
    {     
	  tick();  
    }
    shutdown();
    return 0;
}
