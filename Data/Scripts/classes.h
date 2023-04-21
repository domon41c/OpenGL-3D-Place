#ifndef MAIN_H_INCLUDED
#define MAIN_HINCLUDED

typedef struct{
    float x,y,z;
}TCell;

typedef struct{
    float r,g,b;
}TColor;

typedef struct{
    float u,v;
}TUV;

typedef struct{
    float x,y,z;
    int type;
    float scale;
}TObject;

#define mapW 100
#define mapH 100
TCell map[mapW][mapH];
TCell mapNormal[mapW][mapH];
TUV mapUV[mapW][mapH];

GLuint mapInd[mapW-1][mapH-1][6];
int mapIndCnt = sizeof(mapInd) / sizeof(GLuint);

    float plant[] = {-0.5,0,0, 0.5,0,0, 0.5,0,1, -0.5,0,1,
                     0,-0.5,0, 0,0.5,0, 0,0.5,1, 0,-0.5,1};
    float plantUV[] = {0,1, 1,1, 1,0, 0,0, 0,1, 1,1, 1,0, 0,0};
    GLuint plantInd[] = {0,1,2, 2,3,0, 4,5,6, 6,7,4};
    int plantIndCnt = sizeof(plantInd) / sizeof(GLuint);

    int texture_grass, texture_grass_obj_00, texture_flower_00, texture_tree_00, texture_grass_obj_01, texture_flower_01, texture_tree_01;

    TObject *plantMas = NULL;
    int plantCnt = 0;

    float sun[] = {-1,-1,0, 1,-1,0, 1,1,0, -1,1,0};

BOOL selectMode = FALSE;

#define ObjListCnt 255
typedef struct{
    int plantMas_Index;
    int colorIndex;
}TSelectObj;
TSelectObj selectMas[ObjListCnt];
int selectMasCnt = 0;

typedef struct{
    TObject *obj;
    float dx,dy,dz;
    int cnt;
}TAnim;

TAnim animation = {0,0,0,0,0};

POINT scrSize;
float scrKoef;

typedef struct{
    int type;
}TSlot;
#define bagSize 16
TSlot bag[bagSize];

float bagRect[] = {0,0, 1,0, 1,1, 0,1};
float bagRectUV[] = {0,0, 1,0, 1,1, 0,1};

int health = 15;
int healthMax = 20;

float heart[] = {0.5,0.25, 0.25,0, 0,0.25, 0.5,1, 1,0.25, 0.75,0};

BOOL mouseBind = TRUE;

float Map_GetHeight(float x, float y);

#endif // MAIN_H_INCLUDED