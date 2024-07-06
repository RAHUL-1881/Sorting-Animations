#pragma once

#include<iostream>
#include<vector>
#include<raylib.h>

class layout{
public:
    // Variables
    int i = 1;
    static const int Max_bars = 64;
    Rectangle bars[Max_bars] = { 0 };
    Rectangle button;
    Vector2 Tri_left; //= { 5, 435 };
    Vector2 Tri_down; //= { 0, 445 };
    Vector2 Tri_right; //= {10, 445 };
    //Vector2 mouse = { };
    //vector<Rectangle>bars = {};
    Color bar_color[Max_bars] = { 0 };
    //vector<Color>bar_color = {};

    //Functions
    void Draw();
    void back_buildings();
    void Update_sort();
    void reset();
    void click_button();
    void check_sort();
    void heights();
    //bool reset();

};

// To Draw objects to screen
void layout::Draw()
{
    for(int i = 0; i < Max_bars; i++){
        DrawRectangleRec(bars[i], bar_color[i]); 
    }
        DrawRectangle(0,450,1600,50,Color{246, 220, 172, 255});
        DrawRectangle(0,450,1600,5,Color{ 255, 255, 255, 255 });

        //Text - (insertion Sort)
        DrawText("Insertion Sort", 700, 470, 20, Color{2, 131, 145, 255});

        //Button
        button = {1100, 50, 100, 40};
        DrawRectangleRounded(button, 1, 80, Color{220, 95, 0, 255});
        DrawText("Sort", 1127, 60, 20, WHITE);

        //Instructions
        DrawRectangleLines(0,0,350,100,GRAY);
        DrawText(" --> Press and Hold the Button to Sort", 20, 35, 12, GRAY);
        DrawText(" --> Pressing the 'R' Button Resets the Bars", 20, 55, 12, GRAY);

        //Triangle (pointer to the current bar that is beign sorted)
        DrawTriangle(
            Tri_left,
            Tri_down,
            Tri_right,
            RED
        );
}       

 inline void layout::Update_sort()
 {
    if ( i <= Max_bars ) {
         int key = bars[i].height;
         int j = i -1 ;

         while(j >= 0 && bars[j].height > key){
             bars[j + 1].height = bars[j].height;
             Tri_left = { bars[j].x + 3 , 435 };
             Tri_down = { bars[j].x - 2 , 445 };
             Tri_right = { bars[j].x + 8, 445 };
             j--;
             
        }

         bars[j + 1].height = key;
         i++;
    }
    
    for (int k = 0; k < Max_bars; k++){
         bars[k].y = float(430 - bars[k].height);
    }   

    if (i == Max_bars){

        Vector2 Tri_left = { 0, 435 };
        Vector2 Tri_down = { 5, 445 };
        Vector2 Tri_right = {10, 435 };

     }
    
 }
     
inline void layout::back_buildings()
{
    float spacing = 2;
    for (int i = 0; i < Max_bars; i++){
        bars[i].width = 6;
        bars[i].height = GetRandomValue(10, 250);
        bars[i].x = spacing;
        bars[i].y = float(430 - bars[i].height);
        bar_color[i] = {
            (unsigned char)(GetRandomValue(150, 250)),
            (unsigned char)(GetRandomValue(150, 250)),
            (unsigned char)(GetRandomValue(150, 250)),
            255
        };

         spacing = spacing + 25;
    }
}

inline void layout::heights()
{
    int bar_height;
    for(int k = 0; k < Max_bars; k++){
        bar_height = bars[k].height;
    if ( k % 2 == 0 || k == 0 ){
        DrawText(TextFormat("%d",bar_height), bars[k].x + 2, 130, 3, BLACK);
    }
    if ( k % 2 != 0 ){
        DrawText(TextFormat("%d",bar_height), bars[k].x + 2, 130, 3, RED);
    }

    }
}

 inline void layout::check_sort()
 {
     if (i == Max_bars){

        Vector2 Tri_left = { 0, 435 };
        Vector2 Tri_down = { 5, 445 };
        Vector2 Tri_right = {10, 435 };

     }
 }

inline void layout::reset()
{
    if (IsKeyPressed(KEY_R)){

        back_buildings();
        i = 1;

    }
}

inline void layout::click_button()
{
    //mouse = GetMousePosition(); 
    if (CheckCollisionPointRec(GetMousePosition(), button) && IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
        Update_sort();
    }
}