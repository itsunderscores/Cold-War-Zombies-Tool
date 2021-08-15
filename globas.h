

typedef struct _Offsets
{

} Offsets;

typedef struct _Visuals
{
    bool DoBoxESP = false;

} Visuals;

typedef struct _Aim
{
    int aimkey = 0x5;
    int MaxFOV = 100.f;
    bool DoAimbot = false;
} Aim;

typedef struct _Misc
{

} Misc;

typedef struct _Settings
{
    Visuals visuals;
    Misc misc;
    Aim aim;
    int maxfps;
} Settings;

typedef struct _GlobalVars
{
    bool activated;
    bool shouldExit;
    bool ready;

 
    Offsets offsets;

    int width;
    int height;

    Settings settings;
} GlobalVars;

GlobalVars* g_Vars;