#include "读写.h"
#include <touch.h>


int style_idx2 = 2;
int aimCount = 0;
float NumIo[50];
bool DrawIo[50];
string SaveDir;
FILE *numSave = nullptr;
float inttouchx = 300;
float inttouchy = 500;


void 绘制加粗文本(float size, float x, float y, ImColor color, ImColor color1, const char* str)
{
    ImGui::GetBackgroundDrawList()->AddText(NULL, size, ImVec2(x-0.1, y-0.1), color1, str);
    ImGui::GetBackgroundDrawList()->AddText(NULL, size, ImVec2(x+0.1, y+0.1), color1, str);
    ImGui::GetBackgroundDrawList()->AddText(NULL, size, ImVec2(x, y), color, str);
}
void 绘制字体描边(float size,int x, int y, ImVec4 color, const char* str)
{
    ImGui::GetBackgroundDrawList()->AddText(NULL, size,ImVec2(x + 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(0.0f, 0.0f, 0.0f, 1.0f)), str);
    ImGui::GetBackgroundDrawList()->AddText(NULL, size,ImVec2(x - 0.1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(0.0f, 0.0f, 0.0f, 1.0f)), str);
    ImGui::GetBackgroundDrawList()->AddText(NULL, size,ImVec2(x, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0.0f, 0.0f, 0.0f, 1.0f)), str);
    ImGui::GetBackgroundDrawList()->AddText(NULL, size,ImVec2(x, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0.0f, 0.0f, 0.0f, 1.0f)), str);
    ImGui::GetBackgroundDrawList()->AddText(NULL, size,ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(color), str);
}


void Draw3DBox(Vector3 D, ImColor bone_color, float camera, float bonesWidth)
{
	// unity3d立体框算法
   //定义分辨率
   float gWidth=(2248/2);
   float gHeight=(1080/2);
   
   //开始定义射线位置
   
    float fkx1 = gWidth + (matrix[0] * (D.X + 0.4) + matrix[4] * (D.Z + 0.75) + matrix[8] * (D.Y + 0.4) + matrix[12]) / camera * gWidth;
    // 上左上 
    float fkx2 = gWidth + (matrix[0] * (D.X - 0.4) + matrix[4] * (D.Z + 0.75) + matrix[8] * (D.Y + 0.4) + matrix[12]) / camera * gWidth;
    // 上右下
   float fkx3 = gWidth + (matrix[0] * (D.X + 0.4) + matrix[4] * (D.Z - 0.75) + matrix[8] * (D.Y + 0.4) + matrix[12]) / camera * gWidth;
   // 上左下
   float fkx4 = gWidth + (matrix[0] * (D.X - 0.4) + matrix[4] * (D.Z - 0.75) + matrix[8] * (D.Y + 0.4) + matrix[12]) / camera * gWidth;
   // 上右上
   float fky1 = gHeight - (matrix[1] * (D.X + 0.4) + matrix[5] * (D.Z + 0.75) + matrix[9] * (D.Y + 0.4) + matrix[13]) / camera * gHeight;
   // 上左上
   float fky2 = gHeight - (matrix[1] * (D.X - 0.4) + matrix[5] * (D.Z + 0.75) + matrix[9] * (D.Y + 0.4) + matrix[13]) / camera * gHeight;
   // 上右下
   float fky3 = gHeight - (matrix[1] * (D.X + 0.4) + matrix[5] * (D.Z - 0.75) + matrix[9] * (D.Y + 0.4) + matrix[13]) / camera * gHeight;
   // 上左下
   float fky4 = gHeight - (matrix[1] * (D.X - 0.4) + matrix[5] * (D.Z - 0.75) + matrix[9] * (D.Y + 0.4) + matrix[13]) / camera * gHeight;
   // 下右上
   float fkx5 = gWidth + (matrix[0] * (D.X + 0.4) + matrix[4] * (D.Z + 0.75) + matrix[8] * (D.Y - 0.4) + matrix[12]) / camera * gWidth;
   // 下左上
   float fkx6 = gWidth + (matrix[0] * (D.X - 0.4) + matrix[4] * (D.Z + 0.75) + matrix[8] * (D.Y - 0.4) + matrix[12]) / camera * gWidth;
   // 下右下
   float fkx7 = gWidth + (matrix[0] * (D.X + 0.4) + matrix[4] * (D.Z - 0.75) + matrix[8] * (D.Y - 0.4) + matrix[12]) / camera * gWidth;
   // 下左下
   float fkx8 = gWidth + (matrix[0] * (D.X - 0.4) + matrix[4] * (D.Z - 0.75) + matrix[8] * (D.Y - 0.4) + matrix[12]) / camera * gWidth;
   // 下右上
   float fky5 = gHeight - (matrix[1] * (D.X + 0.4) + matrix[5] * (D.Z + 0.75) + matrix[9] * (D.Y - 0.4) + matrix[13]) / camera * gHeight;
   // 下左下
   float fky6 = gHeight - (matrix[1] * (D.X - 0.4) + matrix[5] * (D.Z + 0.75) + matrix[9] * (D.Y - 0.4) + matrix[13]) / camera * gHeight;
   // 下右下
   float fky7 = gHeight - (matrix[1] * (D.X + 0.4) + matrix[5] * (D.Z - 0.75) + matrix[9] * (D.Y - 0.4) + matrix[13]) / camera * gHeight;
   // 下左下
   float fky8 = gHeight - (matrix[1] * (D.X - 0.4) + matrix[5] * (D.Z - 0.75) + matrix[9] * (D.Y - 0.4) + matrix[13]) / camera * gHeight;
   
   //连线开始
   
   
   ImGui::GetBackgroundDrawList()->AddLine({fkx1,fky1},{fkx2,fky2},bone_color, bonesWidth);
   ImGui::GetBackgroundDrawList()->AddLine({fkx3,fky3},{fkx4,fky4},bone_color, bonesWidth);
   ImGui::GetBackgroundDrawList()->AddLine({fkx1,fky1},{fkx3,fky3},bone_color, bonesWidth);
   ImGui::GetBackgroundDrawList()->AddLine({fkx2,fky2},{fkx4,fky4},bone_color, bonesWidth);
      
   ImGui::GetBackgroundDrawList()->AddLine({fkx5,fky5},{fkx6,fky6},bone_color, bonesWidth);
   ImGui::GetBackgroundDrawList()->AddLine({fkx7,fky7},{fkx8,fky8},bone_color, bonesWidth);
   ImGui::GetBackgroundDrawList()->AddLine({fkx5,fky5},{fkx7,fky7},bone_color, bonesWidth);
   ImGui::GetBackgroundDrawList()->AddLine({fkx6,fky6},{fkx8,fky8},bone_color, bonesWidth);
            
   ImGui::GetBackgroundDrawList()->AddLine({fkx1,fky1},{fkx2,fky2},bone_color, bonesWidth);
   ImGui::GetBackgroundDrawList()->AddLine({fkx3,fky3},{fkx4,fky4},bone_color, bonesWidth);
   ImGui::GetBackgroundDrawList()->AddLine({fkx1,fky1},{fkx3,fky3},bone_color, bonesWidth);
   ImGui::GetBackgroundDrawList()->AddLine({fkx2,fky2},{fkx4,fky4},bone_color, bonesWidth);
   
   ImGui::GetBackgroundDrawList()->AddLine({fkx1,fky1},{fkx5,fky5},bone_color, bonesWidth);
   ImGui::GetBackgroundDrawList()->AddLine({fkx2,fky2},{fkx6,fky6},bone_color, bonesWidth);
   ImGui::GetBackgroundDrawList()->AddLine({fkx3,fky3},{fkx7,fky7},bone_color, bonesWidth);
   ImGui::GetBackgroundDrawList()->AddLine({fkx4,fky4},{fkx8,fky8},bone_color, bonesWidth);
  
   //连线结束
}

void DrawXt(float x,float y, float w,float hp,ImU32 color) {
    ImGui::GetForegroundDrawList()->AddRectFilled({x + (w / 2) + 4, y+w-((y+w)-(y-w))*hp/100},{x+w/2 + 10, y + w},color,{1.5});
}


float right1;
float x1;
float top;
float bottom;
float left;
float right;
float X,Y,W;
float pmjl;


long int libunity,onesefaddr,onself,libil2cpp,数量, Uworld,fwdx,物资数组,Arrayaddr, Uleve5,Matrix, MySelf, Objaddr, Uleve, Uleves, Uleve2, Uleve3, Uleve4,bullet;
//long int ;
int Myteam;
int isBeta, nByte;
char PlayerName[100]; 
char GUNname[100]; 
char extra[32];
int Count;
float XLX;
int PlayerCount;
float zm_x,zm_y;
int AimObjCount = 0;
int WorldDistance;
int AimCount = 0;
int MaxPlayerCount = 0;
int ToReticleDistance;
int Gmin= -1;
int wz;
