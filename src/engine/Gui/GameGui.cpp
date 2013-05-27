#include "GameGui.h"

GameGui::GameGui()
{
    Button* button = new Button(Vec2f(0.5f, 0.5f), Vec2f(0.4f, 0.6f));
    
    button->color_idle = Color3f(0.0f, 1.0f, 0.0f);
    button->color_pressed = Color3f(0.0f, 0.5f, 0.0f);
    
    widgets.push_back(button);
}

void GameGui::draw_gui()
{
    for(size_t i = 0; i < widgets.size(); i++)
    {
        widgets[i]->Draw();
    }
}

Widget* GameGui::get_first_widget()
{
    widget_iter = widgets.begin();
    return *widget_iter;
}

/*Widget* GameGui::get_next_widget()
{
    //-------MaaaaaaaaaGIC!------------------
    static bool is_end = widgets.empty();    
    Widget* result = (is_end) ? *widget_iter : NULL;
    is_end = (widget_iter == widgets.end());
    widget_iter++;
    return result;
}

void GameGui::reset_widget_iterator()
{
    widget_iter = widgets.begin();
}*/

Widget* GameGui::on_touch(float x, float y)
{    
    for(size_t i = 0; i < widgets.size(); i++)
    {
        if(widgets[i]->is_touched(x, y))
            return widgets[i];        
    }
}