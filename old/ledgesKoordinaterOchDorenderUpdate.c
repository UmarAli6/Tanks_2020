//set the drawing color to blue
	SDL_SetRenderDrawColor(renderer, 192, 192, 192, 0);

	//Clear the screen (to blue)
	SDL_RenderClear(renderer);

	//set the drawing color to white
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

	for (int i = 0; i<MAX_LEDGES; i++)
	{
		SDL_Rect ledgeRect = { game->ledges[i].x,game->ledges[i].y,game->ledges[i].w,game->ledges[i].h };
		SDL_RenderFillRect(renderer, &ledgeRect);
	}
  
  
  
  
  
  game->ledges[0].w = WIDTH;
	game->ledges[0].h = 5;
	game->ledges[0].x = 0;
	game->ledges[0].y = 0;

	game->ledges[1].w = 5;
	game->ledges[1].h = HEIGHT;
	game->ledges[1].x = 0;
	game->ledges[1].y = 0;

	game->ledges[2].w = WIDTH;
	game->ledges[2].h = 5;
	game->ledges[2].x = 0;
	game->ledges[2].y = HEIGHT-5;

	game->ledges[3].w = 5;
	game->ledges[3].h = HEIGHT;
	game->ledges[3].x = WIDTH -5;
	game->ledges[3].y = 0;

	game->ledges[4].w = 5;
	game->ledges[4].h = 120;
	game->ledges[4].x = 480;
	game->ledges[4].y = 0;

	game->ledges[5].w = 120;
	game->ledges[5].h = 5;
	game->ledges[5].x = 480;
	game->ledges[5].y = 120;

	game->ledges[6].w = 240;
	game->ledges[6].h = 5;
	game->ledges[6].x = 120;
	game->ledges[6].y = 120;

	game->ledges[7].w = 5;
	game->ledges[7].h = 120;
	game->ledges[7].x = 360;
	game->ledges[7].y = 120;

	game->ledges[8].w = 5;
	game->ledges[8].h = 120;
	game->ledges[8].x = 120;
	game->ledges[8].y = 240;

	game->ledges[9].w = 240;
	game->ledges[9].h = 5;
	game->ledges[9].x = 120;
	game->ledges[9].y = 360;

	game->ledges[10].w = 5;
	game->ledges[10].h = 240;
	game->ledges[10].x = 360;
	game->ledges[10].y = 360;

	game->ledges[11].w = 240;
	game->ledges[11].h = 5;
	game->ledges[11].x = 0;
	game->ledges[11].y = 480;

	game->ledges[12].w = 5;
	game->ledges[12].h = 120;
	game->ledges[12].x = 840;
	game->ledges[12].y = 600;

	game->ledges[13].w = 5;
	game->ledges[13].h = 120;
	game->ledges[13].x = 600;
	game->ledges[13].y = 600;

	game->ledges[14].w = 120;
	game->ledges[14].h = 5;
	game->ledges[14].x = 120;
	game->ledges[14].y = 600;

	game->ledges[15].w = 5;
	game->ledges[15].h = 120;
	game->ledges[15].x = 480;
	game->ledges[15].y = 240;

	game->ledges[16].w = 120;
	game->ledges[16].h = 5;
	game->ledges[16].x = 600;
	game->ledges[16].y = 240;

	game->ledges[17].w = 120;
	game->ledges[17].h = 5;
	game->ledges[17].x = 720;
	game->ledges[17].y = 120;

	game->ledges[18].w = 5;
	game->ledges[18].h = 240;
	game->ledges[18].x = 720;
	game->ledges[18].y = 120;

	game->ledges[19].w = 120;
	game->ledges[19].h = 5;
	game->ledges[19].x = 840;
	game->ledges[19].y = 240;

	game->ledges[20].w = 120;
	game->ledges[20].h = 5;
	game->ledges[20].x = 720;
	game->ledges[20].y = 360;

	game->ledges[21].w = 240;
	game->ledges[21].h = 5;
	game->ledges[21].x = 480;
	game->ledges[21].y = 480;

	game->ledges[22].w = 5;
	game->ledges[22].h = 120;
	game->ledges[22].x = 840;
	game->ledges[22].y = 360;

	game->ledges[23].w = 5;
	game->ledges[23].h = 120;
	game->ledges[23].x = 720;
	game->ledges[23].y = 480;
  
  
  
  
  1. Define max_ledges 50
  ev. tabort load image för fence long och side allt som har med brick bilderna att göra 
  
  
  //Ser till så att man håller sig innanför fönstret
	if (getTankPositionX(game->t1) <= 0)
	{
		setTankX(game->t1, 0);
	}
	if (getTankPositionY(game->t1) <= 0)
	{
		setTankY(game->t1, 0);
	}
	if (getTankPositionX(game->t1) >= WIDTH - 48)
	{
		setTankX(game->t1, WIDTH - 48);
	}
	if (getTankPositionY(game->t1) >= HEIGHT - 48)
	{
		setTankY(game->t1, HEIGHT - 48);
	}
