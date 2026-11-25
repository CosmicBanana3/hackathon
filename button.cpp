#include "button.h"

Button::Button(float x_pos, float y_pos, float H_size, float V_size, string Message, Color Standard, Color Over)
{

    Text = Message;
    Size.x = x_pos;
    Size.y = y_pos;
    Size.width = H_size;
    Size.height = V_size;
    Normal = Standard;
    Hovering = Over;
    HasImage = false;
    Unlocked = true;

}

void Button::Update()
{
    bool inside = CheckCollisionPointRec(GetMousePosition(), Size); 

    Color present = Normal;
    if(inside){
        present = Hovering;
    }

    DrawRectangleRec(Size, present);
    DrawRectangleLinesEx(Size, 3.0f, BLACK);

    
    int fontSize = 20;
    //Gemini helped mon on knowing why text coulding be passed, it wasnt a accepted c type
    int Text_width = MeasureText(Text.c_str(), fontSize);
    int Text_x = (Size.x + (Size.width - Text_width) / 2);
    int Text_y = (Size.y + (Size.height - fontSize) / 2);

    
    DrawText(Text.c_str(), Text_x, Text_y, fontSize, BLACK);
    
}

void Button::Update(bool clickable)
{
    Unlocked = clickable;
    bool inside = CheckCollisionPointRec(GetMousePosition(), Size); 

    Color present = Normal;
    if(!Unlocked){
        present = {72, 72, 72, 255};
    }
    else if(inside){
        present = Hovering;
    }

    DrawRectangleRec(Size, present);
    DrawRectangleLinesEx(Size, 3.0f, BLACK);

    
    int fontSize = 20;
    int Text_width = MeasureText(Text.c_str(), fontSize);
    int Text_x = (Size.x + (Size.width - Text_width) / 2);
    int Text_y = (Size.y + (Size.height - fontSize) / 2);

    
    DrawText(Text.c_str(), Text_x, Text_y, fontSize, BLACK);
}

bool Button::Clicked()
{

    bool inside = CheckCollisionPointRec(GetMousePosition(), Size);
    if (inside && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        return true;
    }

return false;
}

bool Button::Clicked(bool clickable)
{
    Unlocked = clickable;
    if (!Unlocked){
        return false;
    }

    bool inside = CheckCollisionPointRec(GetMousePosition(), Size);
    if (inside && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            return true;
        }
    
    return false;
}
