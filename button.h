#include "raylib.h"
#include <iostream>
using namespace std;

class Button{
    public:

        Rectangle Size;
        string Text;
        Color Normal;
        Color Hovering;
        Texture2D Image;
        bool HasImage;
        bool Unlocked;
        bool clickable = true;

        Button(float x_pos, float y_pos, float H_size, float V_size, string Message, Color Standard, Color Over);

        Button(float x_pos, float y_pos, float H_size, float V_size, Texture2D Icon, Color Standard, Color Over);
        
        bool Clicked();
        bool Clicked(bool clickable);
        
        void Update();
        void Update(bool clickable);
};