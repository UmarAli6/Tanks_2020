#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include <SDL_net.h>
#include <SDL_image.h>
#include <SDL_timer.h>

#define WINDOW_WIDTH (640)
#define WINDOW_HEIGHT (480)

// speed in pixels/second
#define SPEED (300)

int main(void)
{
	UDPsocket sd;
	IPaddress srvadd;
	UDPpacket *p;
	UDPpacket *p2;
	UDPpacket *p3;
	UDPpacket *p4;

	if (SDLNet_Init() < 0)
	{
		fprintf(stderr, "SDLNet_Init: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}

	if (!(sd = SDLNet_UDP_Open(0)))
	{
		fprintf(stderr, "SDLNet_UDP_Open: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}

	/* Resolve server name  */
	if (SDLNet_ResolveHost(&srvadd, "127.0.0.1", 2000) == -1)
	{
		fprintf(stderr, "SDLNet_ResolveHost(192.0.0.1 2000): %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}

	if (!((p = SDLNet_AllocPacket(512)) && (p2 = SDLNet_AllocPacket(512))))
	{
		fprintf(stderr, "SDLNet_AllocPacket: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
	if (!((p2 = SDLNet_AllocPacket(512)) && (p3 = SDLNet_AllocPacket(512))))
	{
		fprintf(stderr, "SDLNet_AllocPacket: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
	if (!((p3 = SDLNet_AllocPacket(512)) && (p4 = SDLNet_AllocPacket(512))))
	{
		fprintf(stderr, "SDLNet_AllocPacket: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}

	// attempt to initialize graphics and timer system
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
	{
		printf("error initializing SDL: %s\n", SDL_GetError());
		return 1;
	}

	SDL_Window* win = SDL_CreateWindow("Hello World!",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH, WINDOW_HEIGHT, 0);
	if (!win)
	{
		printf("error creating window: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	// create a renderer, which sets up the graphics hardware
	Uint32 render_flags = SDL_RENDERER_ACCELERATED;
	SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
	if (!rend)
	{
		printf("error creating renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(win);
		SDL_Quit();
		return 1;
	}

	// load the image into memory using SDL_image library function
	SDL_Surface* surface = IMG_Load("resources/drawing.png");
	if (!surface)
	{
		printf("error creating surface\n");
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return 1;
	}

	// load the image data into the graphics hardware's memory
	SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_Texture* tex2 = SDL_CreateTextureFromSurface(rend, surface);
	SDL_Texture* tex3 = SDL_CreateTextureFromSurface(rend, surface);
	SDL_Texture* tex4 = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	if (!tex || !tex)
	{
		printf("error creating texture: %s\n", SDL_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return 1;
	}

	// struct to hold the position and size of the sprite
	SDL_Rect dest;
	SDL_Rect secondDest;
	SDL_Rect thirdDest;
	SDL_Rect fourthDest;

	// get and scale the dimensions of texture
	SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);
	dest.w /= 4;
	dest.h /= 4;

	secondDest.h = dest.h;
	secondDest.w = dest.w;
	thirdDest.h = dest.h;
	thirdDest.w = dest.w;
	fourthDest.h = dest.h;
	fourthDest.w = dest.w;


	// start sprite in center of screen
	float x_pos = (WINDOW_WIDTH - dest.w) / 2;
	float y_pos = (WINDOW_HEIGHT - dest.h) / 2;
	float x_posOld = x_pos;
	float y_posOld = y_pos;
	float x_vel = 0;
	float y_vel = 0;
	secondDest.y = (int)y_pos;
	secondDest.x = (int)x_pos;
	thirdDest.y = (int)y_pos;
	thirdDest.x = (int)x_pos;
	fourthDest.y = (int)y_pos;
	fourthDest.x = (int)x_pos;
	int a, b;

	// keep track of which inputs are given
	int up = 0;
	int down = 0;
	int left = 0;
	int right = 0;

	// set to 1 when window close button is pressed
	int close_requested = 0;
	printf("Client");
	// animation loop
	while (!close_requested)
	{
		// process events
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				close_requested = 1;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.scancode)
				{
				case SDL_SCANCODE_W:
				case SDL_SCANCODE_UP:
					up = 1;
					break;
				case SDL_SCANCODE_A:
				case SDL_SCANCODE_LEFT:
					left = 1;
					break;
				case SDL_SCANCODE_S:
				case SDL_SCANCODE_DOWN:
					down = 1;
					break;
				case SDL_SCANCODE_D:
				case SDL_SCANCODE_RIGHT:
					right = 1;
					break;
				default:
					break;
				}
				break;
			case SDL_KEYUP:
				switch (event.key.keysym.scancode)
				{
				case SDL_SCANCODE_W:
				case SDL_SCANCODE_UP:
					up = 0;
					break;
				case SDL_SCANCODE_A:
				case SDL_SCANCODE_LEFT:
					left = 0;
					break;
				case SDL_SCANCODE_S:
				case SDL_SCANCODE_DOWN:
					down = 0;
					break;
				case SDL_SCANCODE_D:
				case SDL_SCANCODE_RIGHT:
					right = 0;
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
		}

		// determine velocity
		x_vel = y_vel = 0;
		if (up && !down) y_vel = -SPEED;
		if (down && !up) y_vel = SPEED;
		if (left && !right) x_vel = -SPEED;
		if (right && !left) x_vel = SPEED;

		// update positions
		x_pos += x_vel / 60;
		y_pos += y_vel / 60;

		// send and retrive positions  
		if (x_posOld != x_pos || y_posOld != y_pos) {
			printf("%d %d\n", (int)x_pos, (int)y_pos);
			sprintf((char *)p->data, "%d %d\n", (int)x_pos, (int)y_pos);
			p->address.host = srvadd.host;	/* Set the destination host */
			p->address.port = srvadd.port;	/* And destination port */
			p->len = strlen((char *)p->data) + 1;
			SDLNet_UDP_Send(sd, -1, p);
			x_posOld = x_pos;
			y_posOld = y_pos;
		}


		if (SDLNet_UDP_Recv(sd, p2)) {
			int a, b;
			sscanf((char *)p2->data, "%d %d\n", &a, &b);
			secondDest.x = a;
			secondDest.y = b;
			printf("UDP Packet incoming %d %d\n", secondDest.x, secondDest.y);
		}
		if (SDLNet_UDP_Recv(sd, p3)) {
			int a, b;
			sscanf((char *)p3->data, "%d %d\n", &a, &b);
			thirdDest.x = a;
			thirdDest.y = b;
			printf("UDP Packet incoming %d %d\n", thirdDest.x, thirdDest.y);
		}
		if (SDLNet_UDP_Recv(sd, p4)) {
			int a, b;
			sscanf((char *)p4->data, "%d %d\n", &a, &b);
			thirdDest.x = a;
			thirdDest.y = b;
			printf("UDP Packet incoming %d %d\n", thirdDest.x, thirdDest.y);
		}

		// collision detection with bounds
		if (x_pos <= 0) x_pos = 0;
		if (y_pos <= 0) y_pos = 0;
		if (x_pos >= WINDOW_WIDTH - dest.w) x_pos = WINDOW_WIDTH - dest.w;
		if (y_pos >= WINDOW_HEIGHT - dest.h) y_pos = WINDOW_HEIGHT - dest.h;

		// set the positions in the struct
		dest.y = (int)y_pos;
		dest.x = (int)x_pos;

		// clear the window
		SDL_RenderClear(rend);
		//printf("1-%d:%d 2-%d:%d\n",dest.x, dest.y, secondDest.x, secondDest.y);
		// draw the image to the window
		SDL_RenderCopy(rend, tex, NULL, &dest);
		SDL_RenderCopy(rend, tex2, NULL, &secondDest);
		SDL_RenderCopy(rend, tex3, NULL, &thirdDest);
		SDL_RenderCopy(rend, tex4, NULL, &fourthDest);
		SDL_RenderPresent(rend);

		// wait 1/60th of a second
		SDL_Delay(10000 / 60);
	}

	// clean up resources before exiting
	SDL_DestroyTexture(tex);
	SDL_DestroyTexture(tex2);
	SDL_DestroyTexture(tex3);
	SDL_DestroyTexture(tex4);
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	SDL_Quit();
}