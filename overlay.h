#ifndef OVERLAY_H
#define OVERLAY_H

#include "maintwo.h"

namespace Overlay
{
    void Loop(void* blank);
}

namespace Render
{
    void Start();
    void End();

    void Text(ImVec2 pos, float fontsize, ImColor color, const char* text_begin, const char* text_end, float wrap_width,
        const ImVec4* cpu_fine_clip_rect);
    void EasyText(ImVec2 pos, ImColor color, const char* text);
    void HotBarText(ImVec2 pos, ImColor color, const char* text);
    void RectFilled(int x0, int y0, int x1, int y1, ImColor color, float rounding, int rounding_corners_flags);
    void Line(ImVec2 a, ImVec2 b, ImColor color, float thickness);
    void DrawBox(ImColor color, int x, int y, int w, int h);
    void HealthBar(int x, int y, int w, int h, int phealth);
    void ShieldBar(int x, int y, int w, int h, int pshield);
    void Circle(ImColor color);
}

namespace Helper
{
    void RenderStatic();
    void RenderMenu();
    void RenderFeatures();
}

#endif
