#include <iostream>
#include <unistd.h> // for sleeping or delay
int main()
{
    int length_circle = 5,x_axis = (-1*length_circle) + 1, y_axis = 1;
    int x_add = 1, y_add = 1, indicate_x_axis_limit = 1;
    bool turn_on_MultiplynegaOneX = false, turn_on_MultiplynegaOneY = false;
    while(true)
    {
        // limit of the y - axis should be 20
        for(int i = 1; i <= 20; i++)
        {
            // check if it should render the shape , if true then go and if not then dont to save time and memory
            if(i >= y_axis && i <= length_circle + y_axis) // in other words, it will check the y-axis position of the shape if it matches
            { 
                // limit of the x-axis should be 40
                for(int k = 1; k <= length_circle + x_axis; k++)
                {
                    if((k == length_circle + x_axis) && (i > y_axis && i < length_circle + y_axis))
                    {
                        // for the left side or left arm
                        std::cout << "*"; // left arm
                        // for the right side or right arm
                        for(int s = 1; s <= length_circle + 1; s++)
                            if((s == length_circle + 1))
                                std::cout << "*"; // right arm
                            else if((s < length_circle + 1))
                                std::cout << " "; // spaces inside body
                    }
                    else if((i == length_circle + y_axis || i == y_axis)) // spaces for top and bot or head and foot
                        std::cout << " ";
                    else if((i > y_axis  && i < length_circle + y_axis)) // spaces for the body
                        std::cout << " ";
                }
            }
            // check if it is in the top or bot
            if(i == length_circle + y_axis|| i == y_axis)
            {
                // for loop for printing top and bottom or head and foot
                for(int l = 1; l <= length_circle; l++)
                    // print top and buttom or head and foot
                    std::cout << "*";
            }
            std::cout<<std::endl;
            if(i == 20) // indicator
                std::cout << "y = " << y_axis << "," << "x = " << x_axis << ",Total: " << indicate_x_axis_limit + length_circle << std::endl;
        }
        indicate_x_axis_limit++;
        if(x_axis == (-1*length_circle)+2) // if it is greater than (-1*length_circle)+1 then activate
            turn_on_MultiplynegaOneX = true;
        if(y_axis == 2) // if it is greater than 1 then activate
            turn_on_MultiplynegaOneY = true;
        // check if it reaches the max or min limits, to decided the movement
        if(((indicate_x_axis_limit + length_circle == 40) || (x_axis == (-1 *length_circle) + 1)) && turn_on_MultiplynegaOneX)
        { // for right and left movement
            x_add *= -1;
            indicate_x_axis_limit = 1;
        }
        if((y_axis + length_circle  == 20) || (y_axis == 1) && turn_on_MultiplynegaOneY)
            y_add *= -1; // for up and down movement
        // increment to move
        x_axis += x_add; // for right and left movement
        y_axis += y_add; // for up and down movement
        usleep(250000); // 1 second for 1000000 , 0.5 for 500000
        system("clear");
    }
    return 0;
}
// Created By Shann