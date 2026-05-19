#include <iostream>
#include <raylib.h>

using namespace std;

int player_score = 0;
int cpu_score = 0;

class Ball{
public:
    float x,y;
    int radius;
    Color colour;
    int speed_x;
    int speed_y;

    void Draw(){
        DrawCircle(x, y, radius, colour);
    }

    void ResetBall(){
        x = GetScreenWidth()/2;
        y = GetScreenHeight()/2;
        
        int speed_choices[2] = {-1,1};
        speed_x *= speed_choices[GetRandomValue(0,1)];
        speed_y *= speed_choices[GetRandomValue(0,1)];
    }

    void Update(){
        x += speed_x;
        y += speed_y;

        if(y <= 0 || y >= GetScreenHeight()){
            speed_y *= -1;
        }
         if(x <= 0){
            cpu_score++;
            ResetBall();
         }
         if(x >= GetScreenWidth()){
            player_score++;
            ResetBall();
        }

    }
};

class Paddle{
protected:
    void LimitMovement(){
        if(y <= 0){
            y = 0;
        }
        if(y + height >= GetScreenHeight()){
            y  = GetScreenHeight() - height;
        }
    }

public:
    float x,y;
    float width, height;
    Color colour;
    int speed;

    void Draw(){
        DrawRectangleRounded(Rectangle{x, y, width, height}, 0.8, 0, WHITE);
    }

    void Update(){
        if(IsKeyDown(KEY_UP)){
            y -= speed;
        }
        if(IsKeyDown(KEY_DOWN)){
            y += speed;
        }
        LimitMovement();
    }

};

struct CpuPaddle: public Paddle{
    void Update(int ball_y){
        if(y + height / 2 > ball_y){
            y -= speed;
        }
        if(y + height/2 <= ball_y){
            y += speed;
        }
        LimitMovement();
    }
};

int main() {
    //initialization
    const int screenWidth = 1280;
    const int screenHeight = 800;

    Color col1 = Color{126, 175, 52};
    Color col2 = Color{178, 207, 133};

    Ball ball{screenWidth/2, screenHeight/2, 20, GOLD, -5, -5};

    Paddle paddle1{10, screenHeight/2 - 115/2, 25, 125, WHITE, 7};

    CpuPaddle cpu{screenWidth-10-25, screenHeight/2 - 115/2, 25, 125, WHITE, 7};

    InitWindow(screenWidth, screenHeight, "Ping Pong");
    
    SetTargetFPS(60);


    //Main game loop
    while(!WindowShouldClose()){
        // Drawing
        BeginDrawing();

        ClearBackground(col1);
        DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, WHITE);

        //Goal line
        DrawLine(0, screenHeight/2-200, 150, screenHeight/2-200, WHITE);
        DrawLine(0, screenHeight/2+200, 150, screenHeight/2+200, WHITE);
        DrawLine(150, screenHeight/2-200, 150, screenHeight/2+200, WHITE);

        DrawLine(screenWidth-150, screenHeight/2-200, screenWidth, screenHeight/2-200, WHITE);
        DrawLine(screenWidth-150, screenHeight/2+200, screenWidth, screenHeight/2+200, WHITE);
        DrawLine(screenWidth-150, screenHeight/2-200, screenWidth-150, screenHeight/2+200, WHITE);

        //middle circle
        DrawCircleLines(screenWidth/2, screenHeight/2, 150, WHITE);
        

        ball.Draw();
        ball.Update();
        
        paddle1.Draw();
        paddle1.Update();

        cpu.Draw();
        cpu.Update(ball.y);

        
        if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{paddle1.x, paddle1.y, paddle1.width, paddle1.height})){
            ball.speed_x *= -1;
        }
        if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{cpu.x, cpu.y, cpu.width, cpu.height})){
            ball.speed_x *= -1;
        }

        DrawText(TextFormat("%i",player_score), screenWidth/4, 20, 80, WHITE);
        DrawText(TextFormat("%i",cpu_score), screenWidth*3/4, 20, 80, WHITE);


        EndDrawing();

    }

    CloseWindow();


    return 0;
}