#include <stdlib.h>
#include<gl/glut.h>
#include<math.h>
#include<windows.h>
#include <cstdlib>

#define PI 3.14159265
#define VK_W 0x57
#define VK_S 0x53
#define VK_K 0x4B
float red_x = 10;
float red_y = 300;
float blue_x = 790;
float blue_y = 300;
float ball_x = 400;
float ball_y = 300;
float ball_speed_y = -0.5;
float ball_speed_x = -2;
float red_speed_y = 0;
float blue_speed_y = 0;
int start_flag = 0;
int collider_cooldown;
float player1_collider_center_x;
float player1_collider_center_y;
float player2_collider_center_x;
float player2_collider_center_y;
int Player1_Score = 0, Player2_Score = 0;


void Render();  //Declaration of Draw function

//Points for display score of red player
int red_p1[] = { 319 , 499 };
int red_p2[] = { 319 , 539 };
int red_p3[] = { 319 , 579 };
int red_p4[] = { 359 , 579 };
int red_p5[] = { 359 , 539 };
int red_p6[] = { 359 , 499 };
int red_p7[] = { 299 , 579 };
int red_p8[] = { 299 , 499 };

//Points for display win for red player
int w_red_p1[] = { 150 , 399 };
int w_red_p2[] = { 175 , 199 };
int w_red_p3[] = { 250 , 399 };
int w_red_p4[] = { 275 , 199 };
int w_red_p5[] = { 350 , 399 };
int l_red_p6[] = { 150 , 199 };
int l_red_p7[] = { 200 , 199 };

//Points for display score of blue player
int blue_p1[] = { 439 , 499 };
int blue_p2[] = { 439 , 539 };
int blue_p3[] = { 439 , 579 };
int blue_p4[] = { 479 , 579 };
int blue_p5[] = { 479 , 539 };
int blue_p6[] = { 479 , 499 };
int blue_p7[] = { 419 , 579 };
int blue_p8[] = { 419 , 499 };

//Point for display win for blue player
int w_blue_p1[] = { 550 , 399 };
int w_blue_p2[] = { 575 , 199 };
int w_blue_p3[] = { 650 , 399 };
int w_blue_p4[] = { 675 , 199 };
int w_blue_p5[] = { 750 , 399 };
int l_blue_p6[] = { 550 , 199 };
int l_blue_p7[] = { 600 , 199 };

void Score_Draw(int Score, int Selected_Player) //bool variable if true --> red player .. if false -->blue player
{
	switch (Score)
	{
	case 0:
		if (Selected_Player == 1) //Red player selected
		{
			glLineWidth(10);
			glBegin(GL_LINE_LOOP);
			glVertex2iv(red_p1);
			glVertex2iv(red_p2);
			glVertex2iv(red_p3);
			glVertex2iv(red_p4);
			glVertex2iv(red_p5);
			glVertex2iv(red_p6);
			glEnd();
			//glFlush();
		}
		else if (Selected_Player == 2) //Blue player selected
		{
			glLineWidth(10);
			glBegin(GL_LINE_LOOP);
			glVertex2iv(blue_p1);
			glVertex2iv(blue_p2);
			glVertex2iv(blue_p3);
			glVertex2iv(blue_p4);
			glVertex2iv(blue_p5);
			glVertex2iv(blue_p6);
			glEnd();
			//glFlush();
		}

		break;
	case 1:

		if (Selected_Player == 1) //Red player selected
		{
			glLineWidth(10);
			glBegin(GL_LINE_STRIP);
			glVertex2iv(red_p4);
			glVertex2iv(red_p5);
			glVertex2iv(red_p6);
			glEnd();
			//glFlush();
		}
		else if (Selected_Player == 2)  //Blue player selected
		{
			glLineWidth(10);
			glBegin(GL_LINE_STRIP);
			glVertex2iv(blue_p4);
			glVertex2iv(blue_p5);
			glVertex2iv(blue_p6);
			glEnd();
			//glFlush();
		}

		break;
	case 2:

		if (Selected_Player == 1) //Red player selected
		{
			glLineWidth(10);
			glBegin(GL_LINE_STRIP);
			glVertex2iv(red_p6);
			glVertex2iv(red_p1);
			glVertex2iv(red_p2);
			glVertex2iv(red_p5);
			glVertex2iv(red_p4);
			glVertex2iv(red_p3);
			glEnd();
			//glFlush();
		}
		else if (Selected_Player == 2)  //Blue player selected
		{
			glLineWidth(10);
			glBegin(GL_LINE_STRIP);
			glVertex2iv(blue_p6);
			glVertex2iv(blue_p1);
			glVertex2iv(blue_p2);
			glVertex2iv(blue_p5);
			glVertex2iv(blue_p4);
			glVertex2iv(blue_p3);
			glEnd();
			//glFlush();
		}

		break;
	case 3:

		if (Selected_Player == 1) //Red player selected
		{
			glLineWidth(10);
			glBegin(GL_LINE_STRIP);
			glVertex2iv(red_p1);
			glVertex2iv(red_p6);
			glVertex2iv(red_p5);
			glVertex2iv(red_p2);
			glVertex2iv(red_p5);
			glVertex2iv(red_p4);
			glVertex2iv(red_p3);
			glEnd();
			//glFlush();
		}
		else if (Selected_Player == 2)  //Blue player selected
		{
			glLineWidth(10);
			glBegin(GL_LINE_STRIP);
			glVertex2iv(blue_p1);
			glVertex2iv(blue_p6);
			glVertex2iv(blue_p5);
			glVertex2iv(blue_p2);
			glVertex2iv(blue_p5);
			glVertex2iv(blue_p4);
			glVertex2iv(blue_p3);
			glEnd();
			//glFlush();
		}

		break;
	case 4:

		if (Selected_Player == 1) //Red player selected
		{
			glLineWidth(10);
			glBegin(GL_LINE_STRIP);
			glVertex2iv(red_p3);
			glVertex2iv(red_p2);
			glVertex2iv(red_p5);
			glVertex2iv(red_p4);
			glVertex2iv(red_p5);
			glVertex2iv(red_p6);
			glEnd();
			//glFlush();
		}
		else if (Selected_Player == 2)  //Blue player selected
		{
			glLineWidth(10);
			glBegin(GL_LINE_STRIP);
			glVertex2iv(blue_p3);
			glVertex2iv(blue_p2);
			glVertex2iv(blue_p5);
			glVertex2iv(blue_p4);
			glVertex2iv(blue_p5);
			glVertex2iv(blue_p6);
			glEnd();
			//glFlush();
		}


		break;
	case 5:

		if (Selected_Player == 1) //Red player selected
		{
			glLineWidth(10);
			glBegin(GL_LINE_STRIP);
			glVertex2iv(red_p1);
			glVertex2iv(red_p6);
			glVertex2iv(red_p5);
			glVertex2iv(red_p2);
			glVertex2iv(red_p3);
			glVertex2iv(red_p4);
			glEnd();
			//glFlush();
		}
		else if (Selected_Player == 2)  //Blue player selected
		{
			glLineWidth(10);
			glBegin(GL_LINE_STRIP);
			glVertex2iv(blue_p1);
			glVertex2iv(blue_p6);
			glVertex2iv(blue_p5);
			glVertex2iv(blue_p2);
			glVertex2iv(blue_p3);
			glVertex2iv(blue_p4);
			glEnd();
			//glFlush();
		}

		break;
	case 6:

		if (Selected_Player == 1) //Red player selected
		{
			glLineWidth(10);
			glBegin(GL_LINE_STRIP);
			glVertex2iv(red_p4);
			glVertex2iv(red_p3);
			glVertex2iv(red_p2);
			glVertex2iv(red_p1);
			glVertex2iv(red_p6);
			glVertex2iv(red_p5);
			glVertex2iv(red_p2);
			glEnd();
			//glFlush();
		}
		else if (Selected_Player == 2)  //Blue player selected
		{
			glLineWidth(10);
			glBegin(GL_LINE_STRIP);
			glVertex2iv(blue_p4);
			glVertex2iv(blue_p3);
			glVertex2iv(blue_p2);
			glVertex2iv(blue_p1);
			glVertex2iv(blue_p6);
			glVertex2iv(blue_p5);
			glVertex2iv(blue_p2);
			glEnd();
			//glFlush();
		}


		break;
	case 7:

		if (Selected_Player == 1) //Red player selected
		{
			glLineWidth(10);
			glBegin(GL_LINE_STRIP);
			glVertex2iv(red_p3);
			glVertex2iv(red_p4);
			glVertex2iv(red_p5);
			glVertex2iv(red_p6);
			glEnd();
			//glFlush();
		}
		else if (Selected_Player == 2)  //Blue player selected
		{
			glLineWidth(10);
			glBegin(GL_LINE_STRIP);
			glVertex2iv(blue_p3);
			glVertex2iv(blue_p4);
			glVertex2iv(blue_p5);
			glVertex2iv(blue_p6);
			glEnd();
			//glFlush();
		}


		break;
	case 8:

		if (Selected_Player == 1) //Red player selected
		{
			glLineWidth(10);
			glBegin(GL_LINE_STRIP);
			glVertex2iv(red_p1);
			glVertex2iv(red_p6);
			glVertex2iv(red_p5);
			glVertex2iv(red_p2);
			glVertex2iv(red_p5);
			glVertex2iv(red_p4);
			glVertex2iv(red_p3);
			glVertex2iv(red_p2);
			glVertex2iv(red_p1);
			glEnd();
			//glFlush();
		}
		else if (Selected_Player == 2)  //Blue player selected
		{
			glLineWidth(10);
			glBegin(GL_LINE_STRIP);
			glVertex2iv(blue_p1);
			glVertex2iv(blue_p6);
			glVertex2iv(blue_p5);
			glVertex2iv(blue_p2);
			glVertex2iv(blue_p5);
			glVertex2iv(blue_p4);
			glVertex2iv(blue_p3);
			glVertex2iv(blue_p2);
			glVertex2iv(blue_p1);
			glEnd();
			//glFlush();
		}

		break;
	case 9:

		if (Selected_Player == 1) //Red player selected
		{
			glLineWidth(10);
			glBegin(GL_LINE_STRIP);
			glVertex2iv(red_p1);
			glVertex2iv(red_p6);
			glVertex2iv(red_p5);
			glVertex2iv(red_p2);
			glVertex2iv(red_p5);
			glVertex2iv(red_p4);
			glVertex2iv(red_p3);
			glVertex2iv(red_p2);
			glEnd();
			//glFlush();
		}
		else if (Selected_Player == 2)  //Blue player selected
		{
			glLineWidth(10);
			glBegin(GL_LINE_STRIP);
			glVertex2iv(blue_p1);
			glVertex2iv(blue_p6);
			glVertex2iv(blue_p5);
			glVertex2iv(blue_p2);
			glVertex2iv(blue_p5);
			glVertex2iv(blue_p4);
			glVertex2iv(blue_p3);
			glVertex2iv(blue_p2);
			glEnd();
			//glFlush();
		}

		break;
	default:
		if (Selected_Player == 1) //Red player selected
		{
			glLineWidth(10);
			glBegin(GL_LINE_STRIP);
			glVertex2iv(w_red_p1);
			glVertex2iv(w_red_p2);
			glVertex2iv(w_red_p3);
			glVertex2iv(w_red_p4);
			glVertex2iv(w_red_p5);
			glEnd();
			//glLineWidth(10);
			glBegin(GL_LINE_STRIP);
			glVertex2iv(w_blue_p1);
			glVertex2iv(l_blue_p6);
			glVertex2iv(l_blue_p7);
			glEnd();
			//glLineWidth(10);
			glBegin(GL_LINE_LOOP);
			glVertex2iv(red_p1);
			glVertex2iv(red_p2);
			glVertex2iv(red_p3);
			glVertex2iv(red_p4);
			glVertex2iv(red_p5);
			glVertex2iv(red_p6);
			glEnd();
			glBegin(GL_LINE_STRIP);
			glVertex2iv(red_p7);
			glVertex2iv(red_p8);
			glEnd();
			start_flag = 1;  // Start Game button
		//ball_speed_x=-1;
		//ball_speed_y=0;
			ball_x = 400;
			ball_y = 300;
			collider_cooldown = 1;
			//glFlush();
		}
		else if (Selected_Player == 2)  //Blue player selected
		{
			glLineWidth(10);
			glBegin(GL_LINE_STRIP);
			glVertex2iv(w_blue_p1);
			glVertex2iv(w_blue_p2);
			glVertex2iv(w_blue_p3);
			glVertex2iv(w_blue_p4);
			glVertex2iv(w_blue_p5);
			glEnd();
			glLineWidth(10);
			glBegin(GL_LINE_STRIP);
			glVertex2iv(w_red_p1);
			glVertex2iv(l_red_p6);
			glVertex2iv(l_red_p7);
			glEnd();
			glLineWidth(10);
			glBegin(GL_LINE_LOOP);
			glVertex2iv(blue_p1);
			glVertex2iv(blue_p2);
			glVertex2iv(blue_p3);
			glVertex2iv(blue_p4);
			glVertex2iv(blue_p5);
			glVertex2iv(blue_p6);
			glEnd();
			glBegin(GL_LINE_STRIP);
			glVertex2iv(blue_p7);
			glVertex2iv(blue_p8);
			glEnd();

			start_flag = 1;  // Start Game button
		//ball_speed_x=-1;
		//ball_speed_y=0;
			ball_x = 400;
			ball_y = 300;
			collider_cooldown = 1;
			//glFlush();
		}
		break;
	}
	glPointSize(4);
	glColor3f(0.0, 1.0, 0.0);
}

// select which player has new score draw
void Score_Select(void)
{
	if (Player1_Score >= 1)
	{
		Score_Draw(Player1_Score, 1);
	}
	if (Player2_Score >= 1)
	{
		Score_Draw(Player2_Score, 2);
	}
}

void Draw_Play_Ground()
{
	glClear(GL_COLOR_BUFFER_BIT); //Clean the screen 

		//Middel Line
	glColor3f(0.0, 0.9, 0.0);
	glRecti(399, 0, 404, 599);
	//glFlush();

		//Red Player
	glColor3f(1.0, 0.0, 0.0);
	glRecti(789, 0, 799, 599);
	//glFlush();

		//Blue Player
	glColor3f(0.0, 0.0, 1.0);
	glRecti(0, 0, 9, 599);
	//glFlush();


	//downBorder
	glColor3f(0.0, 1.0, 0.0);
	glRecti(10, 0, 788, 9);
	//glFlush();

	//uperBorder
	glColor3f(0.0, 1.0, 0.0);
	glRecti(10, 589, 788, 599);
	//glFlush();
}

void draw_circle(int first_point_angle, int last_point_angle, int radius, int x, int y) //Drawing General Circle Function
{
	glBegin(GL_POLYGON);
	float theta;
	for (int i = first_point_angle; i < last_point_angle; i++)
	{
		theta = i * 3.142 / 180;
		glVertex2f(x + radius * cos(theta), y + radius * sin(theta));
	}
	glEnd();
}

void draw_ball(float ball_position_x, float ball_position_y) // Draw the Ball
{
	glColor3f(0.0, 0.0, 0.0);
	draw_circle(0, 360, 5, ball_position_x, ball_position_y);
}
void draw_player_red(int x, int y)  // Draw Player 1
{
	glColor3f(1.0, 0.0, 0.0);
	glRecti(x, y, x + 10, y + 125);
	draw_circle(330, 391, 125, x - 98, (2 * y + 125) / 2);
	player1_collider_center_x = x - 98;
	player1_collider_center_y = (2 * y + 125) / 2;
}
void draw_player_blue(int x, int y)  //Draw player 2
{
	glColor3f(0.0, 0.0, 1.0);
	glRecti(x - 10, y, x, y + 125);
	draw_circle(150, 211, 125, x + 98, (2 * y + 125) / 2);
	player2_collider_center_x = x + 98;
	player2_collider_center_y = (2 * y + 125) / 2;
}

void update_ball_position(float speedx, float speedy)  //Update position of ball with respect to speed
{
	ball_x += speedx;
	ball_y += speedy;
}
void update_players_position(float speed_player_1, float speed_player_2) //Update positions of Players with respect to Speed
{
	red_y += speed_player_1;
	blue_y += speed_player_2;
	if (red_y + 125 >= 600)
	{
		red_y = 600 - 126;
		red_speed_y = 0;
	}
	else if (red_y <= 0)
	{
		red_y = 1;
		red_speed_y = 0;
	}
	if (blue_y + 125 >= 600)
	{
		blue_y = 600 - 126;
		blue_speed_y = 0;
	}
	else if (blue_y <= 0)
	{
		blue_y = 1;
		blue_speed_y = 0;
	}

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//COLLISIONS
float sine_inverse(float opposite, float hypotenuse)
{

	float radian;
	float degree;
	float sin_of_angle = opposite / hypotenuse;
	radian = asin(sin_of_angle);
	degree = radian * 180 / PI;
	return degree;
}
float tan_inverse(float speedx, float speedy)
{
	float radian;
	float degree;
	float tan_of_angle = speedy / speedx;
	radian = atan(tan_of_angle);
	degree = radian * 180 / PI;
	return degree;
}
void ball_red_collider()
{
	if (collider_cooldown == 1)//point for red player
	{
		float distance;
		float angle;
		float delta_x = ball_x - player1_collider_center_x;
		delta_x = delta_x * delta_x;
		float delta_y = ball_y - player1_collider_center_y;
		delta_y = delta_y * delta_y;
		distance = sqrtf(delta_y + delta_x);
		if ((ball_y + 5 > red_y) && (ball_y - 5 < red_y + 125))
		{
			if (distance <= 130)
			{
				angle = sine_inverse(ball_y - player1_collider_center_y, 125);
				//		ball_speed_y = cos(angle+(180-tan_inverse(ball_speed_x , ball_speed_y)));
					//	ball_speed_x = sin(angle+(180-tan_inverse(ball_speed_x , ball_speed_y)));
				ball_speed_x = (abs(ball_speed_x) + abs(red_speed_y + sin(angle)) - 1) * 0.7;
				ball_speed_y += (red_speed_y + cos(angle) - 0.7) * 0.7;
				collider_cooldown = 2;

			}
		}
	}
}

void ball_blue_collider()
{
	if (collider_cooldown == 2)// point for blue player
	{
		float distance;
		float angle;
		float delta_x = ball_x - player2_collider_center_x;
		delta_x = delta_x * delta_x;
		float delta_y = ball_y - player2_collider_center_y;
		delta_y = delta_y * delta_y;
		distance = sqrtf(delta_y + delta_x);
		if ((ball_y + 5 > blue_y) && (ball_y - 5 < blue_y + 125))
		{
			if (distance <= 130)
			{
				angle = sine_inverse(ball_y - player2_collider_center_y, 125);
				//		ball_speed_y = cos(angle+(180-tan_inverse(ball_speed_x , ball_speed_y)));
					//	ball_speed_x = sin(angle+(180-tan_inverse(ball_speed_x , ball_speed_y)));
				ball_speed_x = (-ball_speed_x - abs(blue_speed_y * sin(angle)) + 1) * 0.7;
				ball_speed_y += (blue_speed_y + cos(angle) - 0.7) * 0.7;
				collider_cooldown = 1;

			}
		}
	}
}

void ball_goal_collider()
{
	if (ball_x >= 800)
	{
		ball_speed_x = -2;
		ball_speed_y = 0;
		ball_x = 400;
		ball_y = 300;
		collider_cooldown = 1;
		Player1_Score++;
		//Score_Select(Player1_Score,1);
	}
	else if (ball_x <= 0)
	{
		ball_speed_x = 2;
		ball_speed_y = 0;
		ball_x = 400;
		ball_y = 300;
		collider_cooldown = 2;
		Player2_Score++;
	}
}

void ball_border_collider()
{
	if (ball_y <= 0)
	{
		ball_speed_y = abs(ball_speed_y);
	}
	else if (ball_y >= 600)
	{
		ball_speed_y = -abs(ball_speed_y);
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Keyboard()  //Check Keys pressed
{
	if (GetAsyncKeyState(VK_W)) red_speed_y += 0.4;//increase speed upwards player 1 (accelerate)
	if (GetAsyncKeyState(VK_S)) red_speed_y -= 0.4;//increase speed downwards player 1 (accelerate opposite direction)
	if ((!GetAsyncKeyState(VK_W) && !GetAsyncKeyState(VK_S)))  //if no key pressed for player 1
	{
		red_speed_y = 0;
		//		if (red_speed_y != 0){
		//			red_speed_y -= (red_speed_y / abs(red_speed_y))*(0.2); //decrease speed if nothing is pressed by 0.3 whether it was +ve or -ve
		//		}
	}

	// player 2
	if (GetAsyncKeyState(VK_UP)) blue_speed_y += 0.4;
	if (GetAsyncKeyState(VK_DOWN)) blue_speed_y -= 0.4;
	if ((!GetAsyncKeyState(VK_UP) && !GetAsyncKeyState(VK_DOWN)))
	{
		blue_speed_y = 0;
		//if (blue_speed_y != 0){
		//	blue_speed_y -= (blue_speed_y / abs(blue_speed_y))*(0.2); //decrease speed if nothing is pressed by 0.3 whether it was +ve or -ve
		//}
	}

	if (GetAsyncKeyState(VK_K))
	{
		start_flag = 1;  // Start Game button
		ball_speed_x = -1;
		ball_speed_y = 0;
		ball_x = 400;
		ball_y = 300;
		collider_cooldown = 1;
	}

}

void update(int value)  // Update Frame by frame
{
	Keyboard();
	update_players_position(red_speed_y, blue_speed_y);
	if (start_flag == 1)
	{
		ball_border_collider();
		ball_goal_collider();
		ball_red_collider();
		ball_blue_collider();
		update_ball_position(ball_speed_x, ball_speed_y);

	}
	glutTimerFunc(17, update, 0);// Call update every 17 milliseconds with 0 frame skips
	glutPostRedisplay();

}

void myInit()
{
	glClearColor(1.0, 1.0, 1.0, 0.0); //set the background color bright white 
	glColor3f(0.0f, 0.0f, 0.0f); //Set the drawing color to black
	glPointSize(4.0); //Set the point size to 4 by 4 pixels
	glMatrixMode(GL_PROJECTION); //To be explained ...
	glLoadIdentity(); //To be explained ...
	gluOrtho2D(0.0, 800.0, 0.0, 600.0); //To be explained ...
}




void main(int argc, char** argv)
{

	glutInit(&argc, argv); //Initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Set the display mode 
	glutInitWindowSize(800, 600); //Set the window size 
	glutInitWindowPosition(100, 150); //Set the window position on the screen 
	glutCreateWindow("Pong ++"); //Set title for the display window
	glutDisplayFunc(Render);
	glutTimerFunc(17, update, 0);
	myInit();
	glutMainLoop();
	//Go into a perpetual loop
}

void Render()
{
	glClear(GL_COLOR_BUFFER_BIT); //Clean the screen 

	Draw_Play_Ground();
	Score_Select();
	draw_ball(ball_x, ball_y);

	//Red Player
	draw_player_red(red_x, red_y);

	//Blue Player
	draw_player_blue(blue_x, blue_y);
	glFlush();
}