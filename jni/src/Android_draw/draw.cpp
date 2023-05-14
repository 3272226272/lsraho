#include <draw.h>
#include "include.h"


void *handle;// 动态库方案
EGLDisplay display = EGL_NO_DISPLAY;
EGLConfig config;
EGLSurface surface = EGL_NO_SURFACE;
ANativeWindow *native_window;
ANativeWindow *(*createNativeWindow)(const char *surface_name, uint32_t screen_width, uint32_t screen_height, bool author);
EGLContext context = EGL_NO_CONTEXT;
int minedisetence;
Screen full_screen;
int Orientation = 0;
int screen_x = 0, screen_y = 0;
int init_screen_x = 0, init_screen_y = 0;
bool g_Initialized = false;

long 数量地址;
string exec(string command) {
    char buffer[128];
    string result = "";
    // Open pipe to file
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        return "popen failed!";
    }
    // read till end of process:
    while (!feof(pipe)) {
        // use buffer to read and add to result
        if (fgets(buffer, 128, pipe) != nullptr){
            result += buffer;
        }
    }
    pclose(pipe);
    return result;
}

int init_egl(int _screen_x, int _screen_y, bool log){
    void* sy = get_createNativeWindow(); // 适配9-13安卓版本
    createNativeWindow = (ANativeWindow *(*)(const char *, uint32_t, uint32_t, bool))(sy);
    native_window = createNativeWindow("Ssage", _screen_x, _screen_y, false);
    ANativeWindow_acquire(native_window);
    display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    if (display == EGL_NO_DISPLAY) {
        printf("eglGetDisplay error=%u\n", glGetError());
        return -1;
    }
    if(log){
        printf("eglGetDisplay ok\n");
    }
    if (eglInitialize(display, 0, 0) != EGL_TRUE) {
        printf("eglInitialize error=%u\n", glGetError());
        return -1;
    }
    if(log){
        printf("eglInitialize ok\n");
    }
    EGLint num_config = 0;
    const EGLint attribList[] = {
            EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
            EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
            EGL_BLUE_SIZE, 5,   //-->delete
            EGL_GREEN_SIZE, 6,  //-->delete
            EGL_RED_SIZE, 5,    //-->delete
            EGL_BUFFER_SIZE, 32,  //-->new field
            EGL_DEPTH_SIZE, 16,
            EGL_STENCIL_SIZE, 8,
            EGL_NONE
    };
    if (eglChooseConfig(display, attribList, nullptr, 0, &num_config) != EGL_TRUE) {
        printf("eglChooseConfig  error=%u\n", glGetError());
        return -1;
    }
    if(log){
        printf("num_config=%d\n", num_config);
    }
    if (!eglChooseConfig(display, attribList, &config, 1, &num_config)) {
        printf("eglChooseConfig  error=%u\n", glGetError());
        return -1;
    }
    if(log){
        printf("eglChooseConfig ok\n");
    }
    EGLint egl_format;
    eglGetConfigAttrib(display, config, EGL_NATIVE_VISUAL_ID, &egl_format);
    ANativeWindow_setBuffersGeometry(native_window, 0, 0, egl_format);
    const EGLint attrib_list[] = {EGL_CONTEXT_CLIENT_VERSION, 3, EGL_NONE};
    context = eglCreateContext(display, config, EGL_NO_CONTEXT, attrib_list);
    if (context == EGL_NO_CONTEXT) {
        printf("eglCreateContext  error = %u\n", glGetError());
        return -1;
    }
    if(log){
        printf("eglCreateContext ok\n");
    }
    surface = eglCreateWindowSurface(display, config, native_window, nullptr);
    if (surface == EGL_NO_SURFACE) {
        printf("eglCreateWindowSurface  error = %u\n", glGetError());
        return -1;
    }
    if(log){
        printf("eglCreateWindowSurface ok\n");
    }
    if (!eglMakeCurrent(display, surface, surface, context)) {
        printf("eglMakeCurrent  error = %u\n", glGetError());
        return -1;
    }
    if(log){
        printf("eglMakeCurrent ok\n");
    }
    return 1;
}

void screen_config(){
    std::string window_size = exec("wm size");
    sscanf(window_size.c_str(),"Physical size: %dx%d",&screen_x, &screen_y);
    full_screen.ScreenX = screen_x;
    full_screen.ScreenY = screen_y;
    std::thread *orithread = new std::thread([&] {
        while(true){
            Orientation = Orientation = atoi(exec("dumpsys display | grep 'mCurrentOrientation' | cut -d'=' -f2").c_str());
            //atoi(exec("dumpsys input | grep SurfaceOrientation | awk '{print $2}' | head -n 1").c_str());
            if(Orientation == 0 || Orientation == 2){
                screen_x = full_screen.ScreenX;
                screen_y = full_screen.ScreenY;
            }
            if(Orientation == 1 || Orientation == 3){
                screen_x = full_screen.ScreenY;
                screen_y = full_screen.ScreenX;
            }
            std::this_thread::sleep_for(0.5s);
        }
    });
    orithread->detach();
}


void ImGuiMenuStyle()
{
	NumIo[1] = 300.0f;                                                  
    NumIo[2] = 400.0f;
 	NumIo[3] = 10.0f;//范围
    NumIo[4] = 20.0f;
    NumIo[6] = 1400.0f;
    NumIo[5] = 650.0f;
    NumIo[7] = 300.0f;  
    NumIo[8] = 2.0f;  
    NumIo[9] = 10.0f; 
	NumIo[11] = 1000.0f;
	NumIo[13] = 0.0f;
    NumIo[14] = 20.0f;
}


void ImGui_init(){
    if (g_Initialized){
        return;
    }
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.IniFilename = NULL;
    //ImGui::StyleColorsClassic();//黑紫色主题
    ImGui_ImplAndroid_Init(native_window);
    ImGui_ImplOpenGL3_Init("#version 300 es");
    ImFontConfig font_cfg;
    font_cfg.SizePixels = 22.0f;
    io.Fonts->AddFontFromMemoryTTF((void *) font_v, font_v_size, 28.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());
    io.Fonts->AddFontDefault(&font_cfg);
    ImGui::GetStyle().ScaleAllSizes(3.0f);
    g_Initialized = true;
}
static ImVec4 Colbox15 = ImVec4(100.0f, 255.0f, 0.0f, 255.0f);

void Getwuz()
{
         
               const ImU32 namecolor = ImColor(Colbox15);//名字          
               int 数量1=getDword(getZZ(getZZ(getZZ(getZZ(getZZ(libil2cpp+0x621E1F0)+0x5C)+0x124)+0x98)+0x14)+0xC+0x4);
               物资数组= getZZ(getZZ(getZZ(getZZ(getZZ(getZZ(libil2cpp+0x621E1F0)+0x5C)+0x124)+0x98)+0x14)+0xC)+0x20;             
          
               for (int i = 0; i <数量1; i++)
    
                  {                        
               Objaddr = getZZ(物资数组+ 0x18 * i);
               Vector3 Z;
               vm_readv(MySelf + 0x120, &Z, sizeof(Z));
               Vector3 D; 
               vm_readv(Objaddr + 0x28, &D, sizeof(D)); 
               // 计算人物矩阵
               camera = matrix[3] * D.X + matrix[7] * D.Z + matrix[11] * D.Y + matrix[15];
               r_x = px + (matrix[0] * D.X + matrix[4] * (D.Z) + matrix[8] * D.Y + matrix[12]) / camera * px;  // 视角高
               r_y = py - (matrix[1] * D.X + matrix[5] * (D.Z- 0.5) + matrix[9] * D.Y + matrix[13]) / camera * py;    // ;视角宽
               r_w = py - (matrix[1] * D.X + matrix[5] * (D.Z + 1.8) + matrix[9] * D.Y + matrix[13]) / camera * py;                              
               X = r_x - (r_y - r_w) / 4;
               XLX = r_x - (r_y - r_w) / 85;
               Y = r_y;
               W = (r_y - r_w) / 2;
               float Distance = sqrt(pow(D.X - Z.X, 2) + pow(D.Z - Z.Z, 2) + pow(D.Y - Z.Y, 2));
               float MIDDLE = X + W / 2;
               float BOTTOM = Y + W;
               float TOP = Y - W;
               float left = (X + W / 2) - W / 2.6f;
               float right = X + W / 1.12f;  
               getUTF8(GUNname, getZZ(Objaddr + 0xC)+0xC);      
               char* name;
               int  sz= getMaterial(GUNname, &name);   
                  
               if(W>0)
                {         
               std::string s;
               s += name;
               auto textSize = ImGui::CalcTextSize(s.c_str(), 0, 28.f);
               ImGui::GetForegroundDrawList()->AddText(NULL, 18.f, {MIDDLE - 60, TOP},namecolor, s.c_str());                          
                       
                      }
                    }    
                 
              
             
             
    
    
}



void DrawInit()
{
pid = getPID("com.sofunny.Sausage");
FILE *fpp = fopen("/sdcard/x", "r");
FILE *fp1 = fopen("/sdcard/y", "r");
if (fpp == NULL || fp1 == NULL)	// 如果没有读取到分辨率文件,则设置以下分辨
{
py = 1080 / 2;  
px = 2400 / 2; 
}
else
{
fscanf(fpp, "%f", &px);
fscanf(fp1, "%f", &py);
if (py > px)
{
 float t = px;
 px = py;
 py = t;
}
py = py / 2;
px = px / 2;
fclose(fpp);
fclose(fp1);
}
libil2cpp = GetModuleBase("libil2cpp.so",1);
libunity=GetModuleBase("libunity.so",1);

    ImGuiMenuStyle();
}

struct AimStruct
{
    Vector3 ObjAim;  
	Vector3 MyObjAim;
    float ScreenDistance = 0;
    float WodDistance = 0; 
}Aim[100];

int findminat()
{
    float min = NumIo[3];
    int minAt = 999;
    for (int i = 0; i < MaxPlayerCount; i++)
    {
         if (Aim[i].ScreenDistance < min && Aim[i].ScreenDistance != 0)
        {
            min = Aim[i].ScreenDistance;
           // printf("%f\n",min);
            minAt = i;
        }
    }
    if (minAt == 999)
    {
        Gmin = -1;
        return -1;
    }
    Gmin = minAt;   
    WorldDistance = Aim[minAt].WodDistance;
    return minAt;
}
void AimBotAuto()
{   
    bool isDown = false;
    // 是否按下触摸
    double leenx = 0.0f;
    // x轴速度
    double leeny = 0.0f;
    // y轴速度     
    double de = 1.5f;
    // 顶部不可触摸区域
   
    double tx = NumIo[5], ty = NumIo[6];
    // 触摸点位置

    float SpeedMin = 2.0f;
    // 临时触摸速度

    double w = 0.0f, h = 0.0f, cmp = 0.0f;
    // 宽度 高度 正切

    double ScreenX = screen_x, ScreenY = screen_y;
    // 分辨率(竖屏)PS:滑屏用的坐标是竖屏状态下的

    double ScrXH = ScreenX / 2.0f;
    // 一半屏幕X

    double ScrYH = ScreenY / 2.0f;
    // 一半屏幕X

    static float TargetX = 0;
    static float TargetY = 0;
    // 触摸目标位置
    
    Vector3 obj;   
   
	Touch_Init(&screen_x,&screen_y);	
	
    while (true)
    {        
        if (!DrawIo[20])
        {           
            if (isDown == true)
            {
                tx = NumIo[5], ty = NumIo[6];
                // 恢复变量 
                Touch_Up(8);
                // 抬起
                isDown = false;
            }
            usleep(NumIo[9] * 1000);
            continue;
        }
        

        findminat();
        int Firing = getDword(getZZ(getZZ(MySelf + 0x7C)+0x12C)+0x48);
		//开镜
        int Aiming = getDword(MySelf + 0x2D4);	
		//敌人离准星距离
		float ToReticleDistance = Aim[Gmin].ScreenDistance;              
		//printf("%f\n",ToReticleDistance);
        if (Gmin == -1)
        {          
            if (isDown == true)
            {
                tx = NumIo[5], ty = NumIo[6];
                // printf("%d %d",tx,ty);
                // 恢复变量 
                Touch_Up(8);
                // 抬起
                isDown = false;
            }
            usleep(NumIo[9] * 1000);
            continue;
        }
		
        obj.X = Aim[Gmin].ObjAim.X;
		if(wz == 0)
		{
        obj.Y = Aim[Gmin].ObjAim.Z + 0.50;
		}
		if(wz == 1)
		{
		obj.Y = Aim[Gmin].ObjAim.Z + 0.15;
		}
		if(wz == 2)
		{
        obj.Y = Aim[Gmin].ObjAim.Z - 0.15;
		}
        obj.Z = Aim[Gmin].ObjAim.Y;
        float cameras = matrix[3] * obj.X + matrix[7] * obj.Y + matrix[11] * obj.Z + matrix[15];
        Vector2A vpvp = WorldToScreen(obj,matrix,cameras);      
		float AimDs = sqrt(pow(px - vpvp.X, 2) + pow(py - vpvp.Y, 2));
        zm_y = vpvp.X;     
        zm_x = ScreenX - vpvp.Y;        
			
		if (zm_x == 0 && zm_y == 0)
		{
			if (isDown == true)
            {
                tx = NumIo[5], ty = NumIo[6];
                // 恢复变量 
                Touch_Up(8);
                // 抬起
                isDown = false;
            }
            usleep(NumIo[9] * 1000);
            continue;
		}
		
		if (ToReticleDistance > NumIo[3])
		{
			if (isDown == true)
            {
                tx = NumIo[5], ty = NumIo[6];
                // 恢复变量 
                Touch_Up(8);
                // 抬起
                isDown = false;
            }
            usleep(NumIo[9] * 1000);
            continue;
		}
		
		if (W <= 0)
		{
			if (isDown == true)
            {
                tx = NumIo[5], ty = NumIo[6];
                // 恢复变量 
                Touch_Up(8);
                // 抬起
                isDown = false;
            }
            usleep(NumIo[9] * 1000);
            continue;
		}
		
        if (zm_x <= 0 || zm_x >= ScreenX || zm_y <= 0 || zm_y >= ScreenY)
        {          
            if (isDown == true)
            {
                tx = NumIo[5], ty = NumIo[6];
                // 恢复变量 
                Touch_Up(8);
                // 抬起
                isDown = false;
            }
            usleep(NumIo[9] * 1000);
            continue;
        }
                         
        if ((Firing != 0 || Aiming != 0) && AimCount > 0)
        {                                
            if (isDown == false)
            {
                Touch_Down(8,(int)tx, (int)ty);
                
                isDown = true;
            }
			
			float Aimspeace = NumIo[4];

            if (zm_x > ScrXH)
            {
                TargetX = -(ScrXH - zm_x);
                TargetX /= Aimspeace;                                       
                if (TargetX + ScrXH > ScrXH * 2)
                    TargetX = 0;
            }
            if (zm_x < ScrXH)
            {
                TargetX = zm_x - ScrXH;
                TargetX /= Aimspeace;             
                if (TargetX + ScrXH < 0)
                    TargetX = 0;
            }
            if (zm_y > ScrYH)
            {
                TargetY = -(ScrYH - zm_y);
                TargetY /= Aimspeace;              
                if (TargetY + ScrYH > ScrYH * 2)
                    TargetY = 0;
            }
            if (zm_y < ScrYH)
            {
                TargetY = zm_y - ScrYH;
                TargetY /= Aimspeace;              
                if (TargetY + ScrYH < 0)
                  TargetY = 0;
            }
            
            if (TargetY >= 35 || TargetX >= 35 || TargetY <= -35 || TargetX <= -35)
            {
                if (isDown == true)
                {
                    tx = NumIo[5], ty = NumIo[6];
                    // 恢复变量
                    Touch_Up(8);
                    isDown = false;
                }
                usleep(NumIo[9] * 1000);
                continue;
            }           		
            tx += TargetX;
            ty += TargetY;		
			
            if (tx >= NumIo[5] + NumIo[7] || tx <= NumIo[5] - NumIo[7] || ty >= NumIo[6] + NumIo[7] || ty <= NumIo[6] - NumIo[7])
            {
                // 只要滑屏达到了边界，直接还原至中心
                tx = NumIo[5], ty = NumIo[6];
                // 恢复变量
                Touch_Up(8);
                // 抬起
                Touch_Down(8,(int)tx, (int)ty);
                // printf("%f %d\n",tx,ty);
            } 
			
           	Touch_Move(8,(int)tx, (int)ty);
         }
		else
		{
			if (isDown == true)
            {
                tx = NumIo[5], ty = NumIo[6];
                // 恢复变量 
                Touch_Up(8);
                // 抬起
                isDown = false;
            }
            usleep(NumIo[9] * 1000);
            continue;
		}
		
        usleep(NumIo[9] * 1000);
    }
}

static ImVec4 Colbox1 = ImVec4(100.0f, 255.0f, 0.0f, 255.0f);
static ImVec4 Colbox2 = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
static ImVec4 Colbox3 = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
static ImVec4 Colbox5 = ImVec4(0.0f, 255.0f, 76.0f, 255.0f);
static ImVec4 Colbox6 = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
static ImVec4 Colbox7 = ImVec4(1.0f, 0.0f, 0.0f,1.0f);
static ImVec4 Colbox8 = ImVec4(1.0f, 0.0f, 0.0f,1.0f);

void DrawPlayer(ImDrawList *Draw)
{
   const ImU32 namecolor = ImColor(Colbox1);//名字
   const ImU32 jlcolor = ImColor(Colbox5);//距离
   const ImU32 fkcolor = ImColor(Colbox2);//方框
   const ImU32 sxcolor = ImColor(Colbox3);//射线
   const ImU32 zmcolor = ImColor(Colbox6);//自瞄圈
   const ImU32 zmyxjcolor = ImColor(Colbox7);//自瞄圈
   const ImU32 zxcolor = ImColor(Colbox8);
   float top,right,left,bottom,x1,top1;
    

     
    
    if (DrawIo[20])       
    {         
    ImGui::GetForegroundDrawList()->AddCircle({px, py}, NumIo[3],zmcolor,0,2.5f);     
    }
       
	
    if (DrawIo[21])
    {	
        ImGui::GetForegroundDrawList()->AddRectFilled({0,0}, {px*2, py*2},ImColor(0,0,0,110));
        std::string ssf;  
        ssf += "勿放控件，长按拖动";
        auto textSize = ImGui::CalcTextSize(ssf.c_str(), 0, 25);
        ImGui::GetForegroundDrawList()->AddRectFilled({NumIo[6] - NumIo[7]/2, py*2 - NumIo[5] + NumIo[7]/2}, {NumIo[6] + NumIo[7]/2, py*2 - NumIo[5] - NumIo[7]/2},ImColor(255,0,0,120)); 
		ImGui::GetForegroundDrawList()->AddText(NULL,32,{NumIo[6] - (textSize.x / 2),py*2 - NumIo[5]},ImColor(255,255,255),ssf.c_str());                                                   
    }   
    Matrix = getZZ(getZZ(getZZ(getZZ(getZZ(libunity + 0xFDB3A8) + 0x5C) + 0x4) + 0x1C) + 0x8) + 0xC4;
  //
    Uworld = getZZ(libunity + 0xFDDA94);
    Uleve = getZZ(Uworld + 0x4);
    Uleve2 = getZZ(Uleve + 0x4);
    Uleve3 = getZZ(Uleve2 + 0x8);
    Uleve4 = getZZ(Uleve3 + 0x18);
    Uleve5 = getZZ(Uleve4 + 0x2C);
    Arrayaddr = getZZ(Uleve5 + 0x8);
    数量地址 = 	 Uleve5 + 0x0c; 
    数量 = getDword(Uleve5 + 0xC);
           
    oneself = getZZ(getZZ(getZZ(getZZ(getZZ(getZZ(getZZ(Uworld + 0x4) + 0x4) + 0x8) + 0x18) + 0x2C) + 0x8) + 0x10); // 自身对象        
    long int team = getDword(oneself + 0xF0);    
    MySelf = getZZ(getZZ(getZZ(getZZ(libil2cpp + 0x60F271C) + 0xC4) + 0x5C) + 0xF8);
    memset(matrix, 0, 16);
    vm_readv(Matrix, matrix, 16 * 4);         

    PlayerCount = 0; 
    AimCount = 0;
    AimObjCount = 0;
    float min_distance = 300;
    long Temporary = 0;
    for (int i = 0; i < 数量; i++)
    {
        Objaddr = getZZ(Arrayaddr+0x10 + 4 * i);  // 遍历数量次数
	    int TeamID = getDword(Objaddr + 0xF0);	
	    if (team == TeamID)     
        {
           continue;
	    }
         long int object = getZZ(getZZ(getZZ(getZZ(getZZ(getZZ(getZZ(getZZ(Objaddr + 0xC8) + 0x10) + 0x8) + 0x1C) + 0x1C) + 0x14) + 0x28) + 0x14);        		
         onesefaddr = getZZ(getZZ(getZZ(getZZ(getZZ(getZZ(getZZ(getZZ(oneself + 0xC8) + 0x10) + 0x8) + 0x1C) + 0x1C) + 0x14) + 0x28) + 0x14);     
           // 自身坐标 
        Vector3 Z;
        vm_readv(onesefaddr + 0x60, &Z, sizeof(Z)); // 自己坐标
        // 敌人和物资坐标
        Vector3 D;
        vm_readv(object + 0x60, &D, sizeof(D)); // 对象坐标
        D.Z =D.Z+0.3;
        // 计算人物矩阵
        camera = matrix[3] * D.X + matrix[7] * D.Z+ matrix[11] * D.Y + matrix[15];
	    r_x = px + (matrix[0] * D.X + matrix[4] * (D.Z) + matrix[8] * D.Y + matrix[12]) / camera * px;	// 视角高
	    r_y = py - (matrix[1] * D.X + matrix[5] * (D.Z - 0.4) + matrix[9] * D.Y + matrix[13]) / camera * py;	// ;视角宽
	    r_w = py - (matrix[1] * D.X + matrix[5] * (D.Z + 1.8) + matrix[9] * D.Y + matrix[13]) / camera * py;							  
	    
        //printf("[%f %f %f] (%f %f %f)\n",D.X,D.Y,D.Z,r_x,r_y,r_w);
            X = r_x - (r_y - r_w) / 4;
			XLX = r_x - (r_y - r_w) / 85;
            Y = r_y;
            W = (r_y - r_w) / 2;
			float MIDDLE = X + W / 2;
         	float BOTTOM = Y + W;
		 	float TOP = Y - W;
            float pmjl = sqrt(pow(r_x - px, 2) + pow(r_y - py, 2));
			float Distance = sqrt(pow(D.X - Z.X, 2) + pow(D.Z - Z.Z, 2) + pow(D.Y - Z.Y, 2));
            left = (X + W / 2) - W / 2.6f;
            right = X + W / 1.12f;

            float Health = getFloat(Objaddr + 0x220);
			if(Health <= 0)
			{
			continue;
			}			
   
            getUTF8(PlayerName, getZZ(Objaddr + 0xB8)+0xC);
	
            if(DrawIo[20])
            {
			Aim[AimCount].ObjAim = D;                            
            Aim[AimCount].ScreenDistance = sqrt(pow(r_x-px, 2) + pow(r_y - py, 2));
			AimCount++;
			}        

           if(DrawIo[22])
               {
            ImGui::GetForegroundDrawList()->AddLine({px-NumIo[14],py},{px+NumIo[14],py},zxcolor,{1.5});
            ImGui::GetForegroundDrawList()->AddLine({px,py-NumIo[14]},{px,py+NumIo[14]},zxcolor,{1.5});
               }
            // 开始绘制           
            if(W > 0)
            {    			
       
                
                if (DrawIo[1])
                {
				//方框
				Draw->AddLine({X, TOP}, {X+(W/3), TOP}, fkcolor, 1.3f);
                Draw->AddLine({X+W, TOP}, {X+W-(W/3), TOP},fkcolor, 1.3f);
                Draw->AddLine({X, TOP}, {X, TOP+(W/3)},fkcolor, 1.3f);
                Draw->AddLine({X+W, TOP}, {X+W, TOP+(W/3)},fkcolor, 1.3f);
                Draw->AddLine({X, BOTTOM}, {X+(W/3), BOTTOM},fkcolor, 1.3f);
                Draw->AddLine({X+W, BOTTOM}, {X+W-(W/3), BOTTOM},fkcolor, 1.3f);
                Draw->AddLine({X, BOTTOM}, {X, BOTTOM-(W/3)},fkcolor, 1.3f);
                Draw->AddLine({X+W, BOTTOM}, {X+W, BOTTOM-(W/3)},fkcolor, 1.3f);
				}
         
            
                if (DrawIo[2])
                {
                // 射线
				ImGui::GetForegroundDrawList()->AddLine({2248 / 2, 0}, {MIDDLE , TOP - 25},sxcolor, {1.5});
				}
                
				if (DrawIo[3])
				{
	  
                if (Health >= 75)
                DrawXt(XLX,Y,W,Health,绿色);
                if (Health >= 45 && Health < 75)
                DrawXt(XLX,Y,W,Health,黄色);
                if (Health >= 25 && Health < 45)
                DrawXt(XLX,Y,W,Health,蓝色);
                if (Health > 0 && Health < 25)
                DrawXt(XLX,Y,W,Health,红色);
				}
	           
               if (DrawIo[20])
                {
                if(pmjl < NumIo[3])   
                    {
                int mindisetence = findminat(); 
                camera = matrix[3] * Aim[mindisetence].ObjAim.X + matrix[7] * Aim[mindisetence].ObjAim.Z+ matrix[11] * Aim[mindisetence].ObjAim.Y + matrix[15];
                r_x = px + (matrix[0] * Aim[mindisetence].ObjAim.X + matrix[4] * (Aim[mindisetence].ObjAim.Z) + matrix[8] * Aim[mindisetence].ObjAim.Y + matrix[12]) / camera * px; // 视角高
                r_y = py - (matrix[1] * Aim[mindisetence].ObjAim.X + matrix[5] * (Aim[mindisetence].ObjAim.Z - 0.4) + matrix[9] * Aim[mindisetence].ObjAim.Y + matrix[13]) / camera * py;   // ;视角宽
                r_w = py - (matrix[1] * Aim[mindisetence].ObjAim.X + matrix[5] * (Aim[mindisetence].ObjAim.Z + 1.8) + matrix[9] * Aim[mindisetence].ObjAim.Y + matrix[13]) / camera * py;                                  
                X = r_x - (r_y - r_w) / 4;
                XLX = r_x - (r_y - r_w) / 85;
                Y = r_y;
                W = (r_y - r_w) / 2;
                float MIDDLE = X + W / 2;
                float TOP = Y - W;   
                if (mindisetence >= 0)ImGui::GetForegroundDrawList()->AddLine({px, py},{ MIDDLE , TOP - 25},zxcolor,{1.5});                   
                     }
                  }             

	      


             if(DrawIo[6])
             {
                 
                 Getwuz();
             }
                if (DrawIo[4])
				{
				//距离
				std::string s;
                s += std::to_string((int)Distance);
                s += "m";
                auto textSize = ImGui::CalcTextSize(s.c_str(), 0, 28.f);
				ImGui::GetForegroundDrawList()->AddText(NULL, 25.f, {MIDDLE - 25, TOP - 45},jlcolor, s.c_str());
				}
	
				if (DrawIo[5])
				{
				//信息
				std::string s;
				s += "队伍";
           		s += std::to_string(TeamID);
				s += " － ";
				s += PlayerName;
				auto textSize = ImGui::CalcTextSize(s.c_str(), 0, 28.f);
           		ImGui::GetForegroundDrawList()->AddText(NULL, 25.f, {MIDDLE - 60, TOP - 25},namecolor, s.c_str());
				}

            }  
			MaxPlayerCount = AimCount;
			PlayerCount++;
        }
    sprintf(extra,"Nunber: %", 数量);
    绘制字体描边(35.0f, 280.0f, 70.0f,ImColor(250,0,0), extra);


//内存/////////////////内存////////////////////内存//////////////////内存//////////////////////////////////
//内存/////////////////内存////////////////////内存//////////////////内存///////////////////////////////////
//内存/////////////////内存////////////////////内存//////////////////内存////////////////////////////////////
/*  local t = {"libil2cpp.so", "Cd"}
    local tt = {0x3A5A34, 0x5C, 0xE0, 0x100, 0x4C}*/

   // bullet = getZZ(getZZ(getZZ(getZZ(getZZ(libil2cpp+0x3A5A34)+0x5C)+0xE0)+0x100)+0x4C);//子弹addr
int gf;
    if (DrawIo[23])
    {
        for (int i = 0; i < 1; ++i) {
            WriteAddress_FLOAT(libunity + 0x95F818, NumIo[3]);
        }
    }else{
        for (int i = 0; i < 1; ++i) {
            WriteAddress_FLOAT(libunity+0x95F818,2);
        }

    }
    if (DrawIo[24])
    {//子弹
        int id = jz_getPID("com.sofunny.Sausage");
        char ljs[64];
        sprintf(ljs, "/proc/%d/mem", id);
        handles = open(ljs, O_RDWR);
        if (handles == 0)
        {
            puts("获取mem失败!");
            exit(1);
        }
        // 读取基址
        puts("\n开始基址搜索");
        //char mnames[] = ;	// 基址入口模块

        //Xa用getXa,Cb用getbss,Cd用getCd
        long int fool = jz_get_bss(id,"libil2cpp.so");
        //64位游戏把lsp32jz换成lsp64jz即可0xBD098, 0x5C, 0x68, 0x100, 0x4C}
        long int a1 = lsp32jz(lsp32jz(lsp32jz(lsp32jz(fool + 0xBD098) + 0x5C)+0x68)+0x100)+0x4C;
        printf("基址搜索完成\n");
        printf("\n阳光地址=%lx\n", a1);
        WriteAddress_DWORDjz(a1, 40);
        //修改支持所有类型
        puts("\n修改成功\n");

    }

      
          
       }

bool drawimguitick = false;
void GetTouch2()
{
	for(;;)
	{
		usleep(2000);	
		ImGuiIO& iooi = ImGui::GetIO();
		if (iooi.MouseDown[0] && point2.x <= inttouchx + 80 && point2.y <= inttouchy + 80 && point2.x >= inttouchx - 80 && point2.y >= inttouchy - 80)
		{			
			usleep(55000);		
			if (iooi.MouseDown[0] && point2.x <= inttouchx + 80 && point2.y <= inttouchy + 80 && point2.x >= inttouchx - 80 && point2.y >= inttouchy - 80)
			{
				while (iooi.MouseDown[0])
				{
					inttouchx = point2.x;
					inttouchy = point2.y;
					usleep(500);		
				}
			}
			if (drawimguitick)
			{
				drawimguitick = false;
			}else{
				drawimguitick = true;		
			}
		}
	}
}

void GetTouch()
{
	for(;;)
	{
		usleep(2000);	
		ImGuiIO& ioooi = ImGui::GetIO();
		if (DrawIo[21] && ioooi.MouseDown[0] && point2.x <= NumIo[6] + NumIo[7] && point2.y <= py*2 - NumIo[5] + NumIo[7] && point2.x >= NumIo[6] - NumIo[7] && point2.y >= py*2 - NumIo[5] - NumIo[7])
		{			
			usleep(55000);		
			if (ioooi.MouseDown[0] && point2.x <= NumIo[6] + NumIo[7] && point2.y <= py*2 - NumIo[5] + NumIo[7] && point2.x >= NumIo[6] - NumIo[7] && point2.y >= py*2 - NumIo[5] - NumIo[7])
			{
				while (ioooi.MouseDown[0])
				{
					NumIo[6] = point2.x;
					NumIo[5] = py*2 - point2.y;
					usleep(500);		
				}
			}		
		}
	}
}
        


static struct Ui
{
float 圆角 = 10.0f;
float 描边 = 1.0f;
float 框架描边 = 1.0f;
float 控件圆角 = 10.0f;

}TheUi;
int Style_idx = 0;


void tick()
{
        ImGuiIO& io = ImGui::GetIO();
        if (display == EGL_NO_DISPLAY)
        return;	
        static ImVec4 clear_color = ImVec4(0, 0, 0, 0);
        ImGui_ImplOpenGL3_NewFrame();    	
        ImGui_ImplAndroid_NewFrame(init_screen_x, init_screen_y);
        ImGui::NewFrame();
		ImGuiStyle &Style = ImGui::GetStyle();
		Style.GrabRounding = 5;
		Style.GrabMinSize = 20;
    	Style.WindowRounding = TheUi.圆角;//设置边框圆角
    	Style.FrameBorderSize = TheUi.描边;//设置控件描边宽度
		Style.WindowBorderSize = TheUi.框架描边;//设置框架描边宽度
		Style.FrameRounding = TheUi.控件圆角;// 控件圆角	
    	Style.FramePadding = ImVec2(5, 5);
    	Style.WindowMinSize = ImVec2(750,550);
		static bool show_ChildMenu1 = true;
        static bool show_ChildMenu2 = false;
        static bool show_ChildMenu3 = false;	
    	Style.WindowTitleAlign = ImVec2(0.5, 0.5);// 设置标题居中
		ImGui::Begin("香肠派对"); 
		
		  if(ImGui::BeginChild("##mMenu",ImVec2(250,0),false,ImGuiWindowFlags_NoScrollbar|ImGuiWindowFlags_NoScrollbar|ImGuiWindowFlags_NavFlattened));
        {
			ImGui::BulletText("system");
            if(ImGui::Button("绘制",ImVec2(245,85)))
            {
                show_ChildMenu1 = true;
                show_ChildMenu2 = false;
                show_ChildMenu3 = false;
            }
            if(ImGui::Button("自瞄",ImVec2(245,85)))
            {
                show_ChildMenu1 = false;
                show_ChildMenu2 = true;
                show_ChildMenu3 = false;
            }
            if(ImGui::Button("设置",ImVec2(245,85)))
            {
                show_ChildMenu1 = false;
                show_ChildMenu2 = false;
                show_ChildMenu3 = true;
            }
            if(ImGui::Button("退出",ImVec2(245,85)))
            {
                exit(0);
            }
            ImGui::EndChild();// 需要和ImGui::BeginChild成对出现。
        }
		
		ImGui::SameLine();
        if(show_ChildMenu1){
        if(ImGui::BeginChild("##绘制",ImVec2(0,0),false,ImGuiWindowFlags_NavFlattened)){
		ImGui::Text("进游戏再开启本插件");
		ImGui::Text("绘制耗时 %.3f ms (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
		ImGui::Text(("进程: Pid %d"), pid);
		if (ImGui::Combo("", &Style_idx, "白色主题\0蓝色主题\0紫色主题\0红色主题\0蓝黑主题\0"))
        {
            switch (Style_idx)
            {
                case 0: ImGui::StyleColorsLight(); break;
                case 1: ImGui::StyleColorsDark(); break;
                case 2: ImGui::StyleColorsClassic(); break;
				case 3: break;
				case 4: break;
            }
        }
        if (Style_idx == 0){
            ImGui::StyleColorsLight();
        }
        if (Style_idx == 1){
            ImGui::StyleColorsDark();
        }
        if (Style_idx == 2){
            ImGui::StyleColorsClassic();
        }
        if (Style_idx == 3){
        Style.Colors[ImGuiCol_Text]                   = ImVec4(0.92f, 0.92f, 0.92f, 1.00f);
        Style.Colors[ImGuiCol_TextDisabled]           = ImVec4(0.44f, 0.44f, 0.44f, 1.00f);
        Style.Colors[ImGuiCol_WindowBg]               = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
        Style.Colors[ImGuiCol_ChildBg]                = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
        Style.Colors[ImGuiCol_PopupBg]                = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
        Style.Colors[ImGuiCol_Border]                 = ImVec4(0.80f, 0.00f, 0.00f, 1.00f);
        Style.Colors[ImGuiCol_BorderShadow]           = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
        Style.Colors[ImGuiCol_FrameBg]                = ImVec4(0.11f, 0.11f, 0.11f, 1.00f);
        Style.Colors[ImGuiCol_FrameBgHovered]         = ImVec4(0.80f, 0.00f, 0.00f, 1.00f);
        Style.Colors[ImGuiCol_FrameBgActive]          = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
        Style.Colors[ImGuiCol_TitleBg]                = ImVec4(0.80f, 0.00f, 0.00f, 1.00f);
        Style.Colors[ImGuiCol_TitleBgActive]          = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
        Style.Colors[ImGuiCol_TitleBgCollapsed]       = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
        Style.Colors[ImGuiCol_MenuBarBg]              = ImVec4(0.11f, 0.11f, 0.11f, 1.00f);
        Style.Colors[ImGuiCol_ScrollbarBg]            = ImVec4(0.06f, 0.06f, 0.06f, 0.53f);
        Style.Colors[ImGuiCol_ScrollbarGrab]          = ImVec4(0.21f, 0.21f, 0.21f, 1.00f);
        Style.Colors[ImGuiCol_ScrollbarGrabHovered]   = ImVec4(0.47f, 0.47f, 0.47f, 1.00f);
        Style.Colors[ImGuiCol_ScrollbarGrabActive]    = ImVec4(0.81f, 0.83f, 0.81f, 1.00f);
        Style.Colors[ImGuiCol_CheckMark]              = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
        Style.Colors[ImGuiCol_SliderGrab]             = ImVec4(0.80f, 0.00f, 0.00f, 1.00f);
        Style.Colors[ImGuiCol_SliderGrabActive]       = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
        Style.Colors[ImGuiCol_Button]                 = ImVec4(0.80f, 0.00f, 0.00f, 1.00f);
        Style.Colors[ImGuiCol_ButtonHovered]          = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
        Style.Colors[ImGuiCol_ButtonActive]           = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
        Style.Colors[ImGuiCol_Header]                 = ImVec4(0.80f, 0.00f, 0.00f, 1.00f);
        Style.Colors[ImGuiCol_HeaderHovered]          = ImVec4(0.60f, 0.00f, 0.00f, 1.00f);
        Style.Colors[ImGuiCol_HeaderActive]           = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
        Style.Colors[ImGuiCol_Separator]              = ImVec4(0.21f, 0.21f, 0.21f, 1.00f);
        Style.Colors[ImGuiCol_SeparatorHovered]       = ImVec4(0.60f, 0.00f, 0.00f, 1.00f);
        Style.Colors[ImGuiCol_SeparatorActive]        = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
        Style.Colors[ImGuiCol_ResizeGrip]             = ImVec4(0.21f, 0.21f, 0.21f, 1.00f);
        Style.Colors[ImGuiCol_ResizeGripHovered]      = ImVec4(0.60f, 0.00f, 0.00f, 1.00f);
        Style.Colors[ImGuiCol_ResizeGripActive]       = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
        Style.Colors[ImGuiCol_Tab]                    = ImVec4(0.80f, 0.00f, 0.00f, 1.00f);
        Style.Colors[ImGuiCol_TabHovered]             = ImVec4(0.60f, 0.00f, 0.00f, 1.00f);
        Style.Colors[ImGuiCol_TabActive]              = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
        Style.Colors[ImGuiCol_TabUnfocused]           = ImVec4(0.10f, 0.10f, 0.10f, 0.97f);
        Style.Colors[ImGuiCol_TabUnfocusedActive]     = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
        Style.Colors[ImGuiCol_PlotLines]              = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
        Style.Colors[ImGuiCol_PlotLinesHovered]       = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
        Style.Colors[ImGuiCol_PlotHistogram]          = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
        Style.Colors[ImGuiCol_PlotHistogramHovered]   = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
        Style.Colors[ImGuiCol_TextSelectedBg]         = ImVec4(1.00f, 0.00f, 0.00f, 0.35f);
        Style.Colors[ImGuiCol_DragDropTarget]         = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
        Style.Colors[ImGuiCol_NavHighlight]           = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
        Style.Colors[ImGuiCol_NavWindowingHighlight]  = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
        Style.Colors[ImGuiCol_NavWindowingDimBg]      = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);	
        }
        if (Style_idx == 4){
        Style.Colors[ImGuiCol_Text]                  = ImVec4(0.90f, 0.90f, 0.90f, 0.90f);
        Style.Colors[ImGuiCol_TextDisabled]          = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
        Style.Colors[ImGuiCol_WindowBg]              = ImColor(0.0f, 0.0f, 0.0f, 1.0f);
        Style.Colors[ImGuiCol_ChildBg]               = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
        Style.Colors[ImGuiCol_PopupBg]               = ImVec4(0.05f, 0.05f, 0.10f, 0.85f);
        Style.Colors[ImGuiCol_Border]                = ImVec4(0.0f, 0.45f, 1.0f, 1.0f);
        Style.Colors[ImGuiCol_BorderShadow]          = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);

        Style.Colors[ImGuiCol_FrameBg]               = ImColor(0.0f, 0.45f, 1.0f, 1.0f);
        Style.Colors[ImGuiCol_FrameBgActive]         = ImColor(0.0f, 0.45f, 1.0f, 1.0f);
        Style.Colors[ImGuiCol_FrameBgHovered]        = ImColor(0.0f, 0.45f, 1.0f, 1.0f);

        Style.Colors[ImGuiCol_TitleBg]               = ImColor(0.0f, 0.0f, 0.0f, 1.0f);
        Style.Colors[ImGuiCol_TitleBgActive]         = ImColor(0.0f, 0.0f, 0.0f, 1.0f);
        Style.Colors[ImGuiCol_TitleBgCollapsed]      = ImColor(0, 0, 0, 130);

        Style.Colors[ImGuiCol_MenuBarBg]             = ImVec4(0.01f, 0.01f, 0.02f, 0.80f);
        Style.Colors[ImGuiCol_ScrollbarBg]           = ImVec4(0.20f, 0.25f, 0.30f, 0.60f);
        Style.Colors[ImGuiCol_ScrollbarGrab]         = ImVec4(0.55f, 0.53f, 0.55f, 0.51f);
        Style.Colors[ImGuiCol_ScrollbarGrabHovered]  = ImVec4(0.56f, 0.56f, 0.56f, 1.00f);
        Style.Colors[ImGuiCol_ScrollbarGrabActive]   = ImVec4(0.56f, 0.56f, 0.56f, 0.91f);
        Style.Colors[ImGuiCol_CheckMark]             = ImVec4(0.90f, 0.90f, 0.90f, 1.0f);
        Style.Colors[ImGuiCol_SliderGrab]            = ImVec4(0.70f, 0.70f, 0.70f, 0.62f);
        Style.Colors[ImGuiCol_SliderGrabActive]      = ImVec4(0.30f, 0.30f, 0.30f, 0.84f);

        Style.Colors[ImGuiCol_Separator]             = ImColor(0.0f, 0.45f, 1.0f, 1.0f);
        Style.Colors[ImGuiCol_SeparatorActive]       = ImColor(0.0f, 0.45f, 1.0f, 1.0f);
        Style.Colors[ImGuiCol_SeparatorHovered]      = ImColor(0.0f, 0.45f, 1.0f, 1.0f);

        Style.Colors[ImGuiCol_Button]                = ImColor(0.0f, 0.45f, 1.0f, 1.0f);
        Style.Colors[ImGuiCol_ButtonActive]          = ImColor(0.0f, 0.58f, 1.0f, 1.0f);
        Style.Colors[ImGuiCol_ButtonHovered]         = ImColor(0.0f, 0.58f, 1.0f, 1.0f);

        Style.Colors[ImGuiCol_Header]                = ImColor(0, 0, 0, 0);
        Style.Colors[ImGuiCol_HeaderActive]          = ImColor(0, 0, 0, 0);
        Style.Colors[ImGuiCol_HeaderHovered]         = ImColor(46, 46, 46, 255);

        Style.Colors[ImGuiCol_ResizeGrip]            = ImVec4(1.00f, 1.00f, 1.00f, 0.0f);
        Style.Colors[ImGuiCol_ResizeGripHovered]     = ImVec4(1.00f, 1.00f, 1.00f, 0.00f);
        Style.Colors[ImGuiCol_ResizeGripActive]      = ImVec4(1.00f, 1.00f, 1.00f, 0.0f);
        Style.Colors[ImGuiCol_PlotLines]             = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
        Style.Colors[ImGuiCol_PlotLinesHovered]      = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
        Style.Colors[ImGuiCol_PlotHistogram]         = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
        Style.Colors[ImGuiCol_PlotHistogramHovered]  = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
        Style.Colors[ImGuiCol_TextSelectedBg]        = ImVec4(0.00f, 0.00f, 1.00f, 0.35f);
        }
       if(ImGui::Button("绘制初始画"))
       {
      DrawInit(); 
       }                



	    if (ImGui::CollapsingHeader("人物绘制功能")) {
        if (ImGui::Button("一键全开"))
        {   
            DrawIo[1] = true;
			DrawIo[2] = true;
			DrawIo[3] = true;
			DrawIo[4] = true;
			DrawIo[5] = true;
            DrawIo[22] = true;
            }
		ImGui::SameLine();
		if(ImGui::Button("一键全关"))
		{
			DrawIo[1] = false;
			DrawIo[2] = false;
			DrawIo[3] = false;
			DrawIo[4] = false;
			DrawIo[5] = false;
		    DrawIo[22] = false;
        }	
        ImGui::Checkbox("绘制方框", &DrawIo[1]);
		ImGui::SameLine();
        ImGui::Checkbox("绘制射线", &DrawIo[2]);
		ImGui::EndTabBar();  
        ImGui::Checkbox("绘制血量", &DrawIo[3]);
		ImGui::SameLine();
		ImGui::Checkbox("绘制距离", &DrawIo[4]);
		ImGui::EndTabBar();  
		ImGui::Checkbox("绘制信息", &DrawIo[5]);			  
        ImGui::SameLine();
		ImGui::Checkbox("绘制准星", &DrawIo[22]);			  
        ImGui::Text("准星大小");
        ImGui::SameLine();
        ImGui::SliderFloat("", &NumIo[14],20.0f,300.0f,"%.0f",1);         
		}
     if (ImGui::CollapsingHeader("物资绘制功能")) 
     {
	 ImGui::Text(("物资数组: %lX "),物资数组);
     ImGui::Checkbox("物资绘制开关", &DrawIo[6]);
     ImGui::Checkbox("绘制枪械", &DrawIo[7]);    
         
     }
     if (ImGui::CollapsingHeader("内存功能")) 
     {
        ImGui::Checkbox("范围", &DrawIo[23]);
		ImGui::SameLine();
        ImGui::Checkbox("子弹", &DrawIo[24]);
		ImGui::EndTabBar();  
        ImGui::Checkbox("绘制血量", &DrawIo[25]);
		ImGui::SameLine();
		ImGui::Checkbox("绘制距离", &DrawIo[26]);
		ImGui::EndTabBar();  
		ImGui::Checkbox("绘制信息", &DrawIo[27]);			  
        ImGui::SameLine();
            if(ImGui::Button("范围")){                       
          //  WriteAddress_FLOAT(libunity+0x95F818,NumIo[3]);
               }
            ImGui::Text("先调整范围大小再开范围");
            ImGui::Text("范围大小");
            ImGui::SameLine();
             ImGui::SliderFloat("大小", &NumIo[3],10.0f,30.0f,"%.0f",1);         
         
     }
      
         ImGui::Text(("游戏入口libil2cpp: %lX "), libil2cpp);
        ImGui::Text(("游戏入口libunity: %lX "),libunity);      
        ImGui::Text(("矩阵: %lX "),Matrix );
        ImGui::Text(("人物数量: %lX "),数量地址);
        ImGui::Text(("数组: %lX "),Arrayaddr);   
        ImGui::Text(("自己地址: %lX "),oneself);
        ImGui::Text("自身结构体=%f",getFloat(onesefaddr+0x64)); 
        ImGui::Text(("开镜判断: %d "),getDword(MySelf + 0x2D4));   
        ImGui::Text(("开火判断: %d "),getDword(getZZ(getZZ(MySelf + 0x7C)+0x12C)+0x48));
        ImGui::Text(("子弹: %lx "),bullet);




        }
 
    
    
    
    }
		
		if(show_ChildMenu2){
	    if(ImGui::BeginChild("##自瞄",ImVec2(0,0),false,ImGuiWindowFlags_NavFlattened)){
	    ImGui::Text("触摸自瞄");
		ImGui::Checkbox("触摸开关", &DrawIo[20]);
		ImGui::SameLine();
		ImGui::Checkbox("触摸位置", &DrawIo[21]);
		ImGui::RadioButton("头部",&wz,0);
        ImGui::SameLine();
        ImGui::RadioButton("胸部",&wz,1);
        ImGui::SameLine();
        ImGui::RadioButton("腿部",&wz,2);          
        ImGui::SliderFloat("自瞄范围", &NumIo[3],10.0f,500.0f,"%.0f",1);     
	    ImGui::SliderFloat("触摸范围", &NumIo[7],5.0f,600.0f,"%.0f",2); 
		ImGui::SliderFloat("自瞄速度", &NumIo[4],0.1f,90.0f,"%.2f",2);
        ImGui::SliderFloat("平滑力度", &NumIo[9],0.1f,90.0f,"%.1f",3);
		}
		}
		
		if(show_ChildMenu3){
	    if(ImGui::BeginChild("##设置",ImVec2(0,0),false,ImGuiWindowFlags_NavFlattened)){
	    ImGui::Text("UI界面设置");
		ImGui::SliderFloat("圆角圆度", &TheUi.圆角, 0, 50);
		ImGui::SliderFloat("描边宽度", &TheUi.描边, 0, 10);
		ImGui::SliderFloat("框架描边宽度", &TheUi.框架描边, 0, 10);
		ImGui::SliderFloat("控件圆角", &TheUi.控件圆角, 0, 50);
		ImGui::Text("颜色调节");
		{
        ImGui::ColorEdit4("名字颜色", (float*)&Colbox1);                
        ImGui::ColorEdit4("方框颜色", (float*)&Colbox2);                
        ImGui::ColorEdit4("射线颜色", (float*)&Colbox3);
        ImGui::ColorEdit4("距离颜色", (float*)&Colbox5);
		ImGui::ColorEdit4("圈圈颜色", (float*)&Colbox6); 
        ImGui::ColorEdit4("准星颜色", (float*)&Colbox8);
        }
		}
		}
		
		
	ImGui::End();
		
    DrawPlayer(ImGui::GetForegroundDrawList());
    ImGui::Render();  
    glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
    glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    eglSwapBuffers(display, surface);
}

void shutdown()
{
    if (!g_Initialized) {
        return;
    }
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplAndroid_Shutdown();
    ImGui::DestroyContext();
    if (display != EGL_NO_DISPLAY){
        eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
        if (context != EGL_NO_CONTEXT){
            eglDestroyContext(display, context);
        }
        if (surface != EGL_NO_SURFACE){
            eglDestroySurface(display, surface);
        }
        eglTerminate(display);
    }
    display = EGL_NO_DISPLAY;
    context = EGL_NO_CONTEXT;
    surface = EGL_NO_SURFACE;
    ANativeWindow_release(native_window);
}
