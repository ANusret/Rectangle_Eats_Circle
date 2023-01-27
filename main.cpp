#include "raylib.h"

void oneplayer()
{
    // window dimension
    int width{600};
    int height{400};
    InitWindow(width, height, "R_eat_C");

    // circle coordinates
    int circle_x{300};
    int circle_y{200};
    int circle_radius{30};

    // circle edges
    int circle_left_x{circle_x - circle_radius};
    int circle_right_x{circle_x + circle_radius};
    int circle_up_y{circle_y - circle_radius};
    int circle_bottom_y{circle_y + circle_radius};

    // rectangle coordinates and dimension
    int rectangle_x{400};
    int rectangle_y{250};
    int rectangle_length{20};

    // rectangle edges
    int rectangle_left_x{rectangle_x};
    int rectangle_right_x{rectangle_x + rectangle_length};
    int rectangle_up_y{rectangle_y};
    int rectangle_bottom_y{rectangle_y + rectangle_length};

    // target direction
    int direction{15};

    bool collision_hitting{false};

    SetTargetFPS(30);

    while (WindowShouldClose() == false)
    {

        BeginDrawing();
        ClearBackground(RED);

        // Game logic begin
        DrawCircle(circle_x, circle_y, circle_radius, BLUE);
        DrawRectangle(rectangle_x, rectangle_y, rectangle_length, rectangle_length, WHITE);

        rectangle_y += direction;

        if ((circle_right_x >= rectangle_left_x) && (circle_up_y <= rectangle_bottom_y) && (circle_left_x <= rectangle_right_x) && (circle_bottom_y >= rectangle_up_y))
        {
            collision_hitting = true;
        }

        if (collision_hitting)
        {
            ClearBackground(WHITE);
            DrawText("Game Over.!", 220, 190, 22, RED);
        }
        else
        {

            // update rectangle and circle edges
            rectangle_left_x = rectangle_x;
            rectangle_right_x = rectangle_x + rectangle_length;
            rectangle_up_y = rectangle_y;
            rectangle_bottom_y = rectangle_y + rectangle_length;
            circle_left_x = circle_x - circle_radius;
            circle_right_x = circle_x + circle_radius;
            circle_up_y = circle_y - circle_radius;
            circle_bottom_y = circle_y + circle_radius;

            if (rectangle_y >= height || rectangle_y <= 0)
            {
                direction = -direction;
            }

            // circle movement controller

            if (IsKeyDown(KEY_D) && circle_x < width)
            {
                circle_x += 10;
            }

            if (IsKeyDown(KEY_A) && circle_x > 0)
            {
                circle_x -= 10;
            }

            if (IsKeyDown(KEY_S) && circle_y < height)
            {
                circle_y += 10;
            }

            if (IsKeyDown(KEY_W) && circle_y > 0)
            {
                circle_y -= 10;
            }
        }

        // Game logic end
        EndDrawing();

    }

}

void twoplayer()
{
    // window dimension
    int width{600};
    int height{400};
    InitWindow(width, height, "R_eat_C");

    // circle coordinates
    int circle_x{300};
    int circle_y{200};
    int circle_radius{30};

    // circle edges
    int circle_left_x{circle_x - circle_radius};
    int circle_right_x{circle_x + circle_radius};
    int circle_up_y{circle_y - circle_radius};
    int circle_bottom_y{circle_y + circle_radius};

    // rectangle coordinates and dimension
    int rectangle_x{400};
    int rectangle_y{250};
    int rectangle_length{20};

    // rectangle edges
    int rectangle_left_x{rectangle_x};
    int rectangle_right_x{rectangle_x + rectangle_length};
    int rectangle_up_y{rectangle_y};
    int rectangle_bottom_y{rectangle_y + rectangle_length};

    bool collision_hitting{false};

    SetTargetFPS(30);

    while (WindowShouldClose() == false)
    {

        BeginDrawing();
        ClearBackground(RED);

        // Game logic begin
        DrawCircle(circle_x, circle_y, circle_radius, BLUE);
        DrawRectangle(rectangle_x, rectangle_y, rectangle_length, rectangle_length, WHITE);

        //rectangle_y += direction;

        if ((circle_right_x >= rectangle_left_x) && (circle_up_y <= rectangle_bottom_y) && (circle_left_x <= rectangle_right_x) && (circle_bottom_y >= rectangle_up_y))
        {
            collision_hitting = true;
        }

        if (collision_hitting)
        {
            ClearBackground(WHITE);
            DrawText("Game Over.!", 220, 190, 22, RED);
        }
        else
        {

            // update rectangle and circle edges
            rectangle_left_x = rectangle_x;
            rectangle_right_x = rectangle_x + rectangle_length;
            rectangle_up_y = rectangle_y;
            rectangle_bottom_y = rectangle_y + rectangle_length;
            circle_left_x = circle_x - circle_radius;
            circle_right_x = circle_x + circle_radius;
            circle_up_y = circle_y - circle_radius;
            circle_bottom_y = circle_y + circle_radius;

            // circle movement controller
            if (IsKeyDown(KEY_D) && circle_x < width)
            {
                circle_x += 10;
            }

            if (IsKeyDown(KEY_A) && circle_x > 0)
            {
                circle_x -= 10;
            }

            if (IsKeyDown(KEY_S) && circle_y < height)
            {
                circle_y += 10;
            }

            if (IsKeyDown(KEY_W) && circle_y > 0)
            {
                circle_y -= 10;
            }

            // rectangle movement controller
            if (IsKeyDown(KEY_RIGHT) && rectangle_x < 600)
            {
                rectangle_x += 10;
            }

            if (IsKeyDown(KEY_LEFT) && rectangle_x > 0)
            {
                rectangle_x -= 10;
            }

            if (IsKeyDown(KEY_DOWN) && rectangle_y < 400)
            {
                rectangle_y += 10;
            }

            if (IsKeyDown(KEY_UP) && rectangle_y > 0)
            {
                rectangle_y -= 10;
            }
        }

        // Game logic end
        EndDrawing();

    }

}

int main()
{
    int width{600};
    int height{400};
    InitWindow(width, height, "R_eat_C");

    SetTargetFPS(30);

    while (WindowShouldClose() == false)
    {

        BeginDrawing();
        ClearBackground(WHITE);

        DrawText("Press q for 1 player mode \nPress e for 2 player mode", 220, 190, 22, BLACK);

        if (IsKeyDown(KEY_Q))
        {
            oneplayer();
        }
        if (IsKeyDown(KEY_E))
        {
            twoplayer();
        }

        EndDrawing();
    }

    return 0;
}