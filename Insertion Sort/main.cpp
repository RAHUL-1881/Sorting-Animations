#include<iostream>
#include<raylib.h>
#include"bars.hpp"

using namespace std;

int main(){
    // Variables
    int screenwidth = 1600;
    int screenheight = 500;
    Color background = {238, 238, 238, 255};
    int fps = 10;

    // Class Objects
    layout buildings;
    buildings.back_buildings();

    //Game Window
    InitWindow(screenwidth,screenheight,"Insertion Sort");
    SetTargetFPS(fps);

    //GameLoop
    while(!WindowShouldClose()){

        //Variables

        //Event Handling
        buildings.click_button();

        //Update
        buildings.reset();
        buildings.heights();
        //buildings.check_sort();

        //Draw
        BeginDrawing();

        buildings.Draw();
        ClearBackground(background);

        EndDrawing();
    }

    return 0;
}