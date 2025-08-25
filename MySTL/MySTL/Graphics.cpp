
#include <iostream>
using namespace std;


class Graphics
{
    //Breseham画线算法
    //1.交换x、y,确保从长的那一边开始画，避免点不连续。交换需要打个符号
    //2.交换大小，确保从小的那一边开始画起
    //3.逐帧绘制x，记录插值系数t，再根据此绘制y。
    void line(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color) {
        bool steep = false;
        if (std::abs(x0 - x1) < std::abs(y0 - y1)) {
            std::swap(x0, y0);
            std::swap(x1, y1);
            steep = true;
        }
        if (x0 > x1) {
            std::swap(x0, x1);
            std::swap(y0, y1);
        }

        for (int x = x0; x <= x1; x++) {
            float t = (x - x0) / (float)(x1 - x0);
            int y = y0 * (1. - t) + y1 * t;
            if (steep) {
                image.set(y, x, color);
            }
            else {
                image.set(x, y, color);
            }
        }
    }
}