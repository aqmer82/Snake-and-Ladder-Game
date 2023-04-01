#include<iostream>
#include<stdio.h>
#include<vector>
#include<SFML/graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<SFML/window.hpp>
#include<SFML/Network.hpp>
using namespace sf;
class playerCo {
public:
	float plx[10];
	float ply[10];
	playerCo() {
		for (int i = 0; i < 10; i++) {
			plx[i] = 0;
			ply[i] = 0;
		}
	}
	void playerCoSet(float a, float j, float d, float e) {
		ply[0] = a;
		float k = 0;
		for (int i = 0; i < 10; i++) {
			plx[i] += j;
			j += d;
		}
		for (int i = 1; i < 10; i++) {
			k += e;
			ply[i] += (ply[0] - k);
		}
	}
};
class player :public playerCo, public Texture, public CircleShape {
public:
	int no;
	player() :playerCo() {

	}
};
class dice : public Sprite, public Texture {
public:

};
void main() {
	//Video resolution
	VideoMode videoMode;
	videoMode.height = 1080;
	videoMode.width = 1920;

	//event variable
	Event ev;

	// Mouse positions
	Vector2i mousePosWindow;
	Vector2f mousePosView;

	//player
	player pl1;
	player pl2;
	player pl3;
	player pl4;

	//player coordinates
	pl1.playerCoSet(1019, 20, 158, 105);
	pl2.playerCoSet(965, 20, 158, 105);
	pl3.playerCoSet(1020, 110, 155, 105);
	pl4.playerCoSet(970, 111, 155, 106);

	//player details
	player player1;
	player player2;
	player player3;
	player player4;

	pl1.no = 1;
	player pl1tex;
	pl1tex.loadFromFile("1.png");
	player1.setRadius(24);
	player1.setTexture(&pl1tex);
	player1.setPosition(Vector2f(pl1.plx[0], pl1.ply[0]));

	pl2.no = 1;
	player pl2tex;
	pl2tex.loadFromFile("2.png");
	player2.setRadius(24);
	player2.setTexture(&pl2tex);
	player2.setPosition(Vector2f(pl2.plx[0], (pl2.ply[0])));

	pl3.no = 1;
	player pl3tex;
	pl3tex.loadFromFile("3.png");
	player3.setRadius(24);
	player3.setTexture(&pl3tex);
	player3.setPosition(Vector2f((pl3.plx[0]), (pl3.ply[0])));

	pl4.no = 1;
	player pl4tex;
	pl4tex.loadFromFile("4.png");
	player4.setRadius(24);
	player4.setTexture(&pl4tex);
	player4.setPosition(Vector2f((pl4.plx[0]), (pl4.ply[0])));

	//image variable
	Image image;
	if (!image.loadFromFile("board2.jpg")) {
		std::cout << "Error";
	}
	Texture texture;
	texture.loadFromImage(image);

	Sprite sprite;
	sprite.setTexture(texture);
	RenderWindow window(videoMode, "Snake and Ladder");
	window.setFramerateLimit(60);

	//Dice
	dice dice1;
	dice dice2;
	dice dice3;
	dice dice4;
	dice dice5;
	dice dice6;

	dice dice1t;
	dice1t.loadFromFile("dice-1.png");
	dice1.setTexture(dice1t);
	dice1.setPosition(Vector2f(1650, 750));

	dice dice2t;
	dice2t.loadFromFile("dice-2.png");
	dice2.setTexture(dice2t);
	dice2.setPosition(Vector2f(1650, 750));

	dice dice3t;
	dice3t.loadFromFile("dice-3.png");
	dice3.setTexture(dice3t);
	dice3.setPosition(Vector2f(1650, 750));

	dice dice4t;
	dice4t.loadFromFile("dice-4.png");
	dice4.setTexture(dice4t);
	dice4.setPosition(Vector2f(1650, 750));

	dice dice5t;
	dice5t.loadFromFile("dice-5.png");
	dice5.setTexture(dice5t);
	dice5.setPosition(Vector2f(1650, 750));

	dice dice6t;
	dice6t.loadFromFile("dice-6.png");
	dice6.setTexture(dice6t);
	dice6.setPosition(Vector2f(1650, 750));

	//Sound
	SoundBuffer bufferr;
	bufferr.loadFromFile("roll.wav");
	Sound soundr;
	soundr.setBuffer(bufferr);

	SoundBuffer buffers;
	buffers.loadFromFile("snake.ogg");
	Sound sounds;
	sounds.setBuffer(buffers);

	SoundBuffer bufferl;
	bufferl.loadFromFile("ladder.wav");
	Sound soundl;
	soundl.setBuffer(bufferl);

	SoundBuffer bufferv;
	bufferv.loadFromFile("victory.wav");
	Sound soundv;
	soundv.setBuffer(bufferv);

	//Text
	Font font;
	font.loadFromFile("arial.ttf");
	Text text;
	text.setFont(font);
	text.setString("Player 1\n\nPress\nSpace\nto\nroll");
	text.setFillColor(Color::White);
	text.setOutlineColor(Color(190, 190, 190));
	text.setOutlineThickness(3);
	text.setStyle(Text::Bold);
	text.setPosition(Vector2f(1620, 50));
	text.setCharacterSize(75);

	Text nopt;
	nopt.setFont(font);
	nopt.setString("Enter no of players:");
	nopt.setFillColor(Color::White);
	nopt.setOutlineColor(Color::Black);
	nopt.setOutlineThickness(7);
	nopt.setStyle(Text::Bold);
	nopt.setPosition(Vector2f(100, 300));
	nopt.setCharacterSize(150);

	Text vict;
	vict.setFont(font);
	vict.setString("Player 1 Victory");
	vict.setFillColor(Color::White);
	vict.setOutlineColor(Color::Black);
	vict.setOutlineThickness(7);
	vict.setStyle(Text::Bold);
	vict.setPosition(Vector2f(2000, 2000));
	vict.setCharacterSize(200);

	// extras
	//no of players
	bool vicb = true;
	bool nopb = false;
	int nop;
	nop = 1;
	int ch2 = 1;

	//game loop
	while (window.isOpen()) {
		window.clear();
		mousePosWindow = Mouse::getPosition(window);
		mousePosView = window.mapPixelToCoords(mousePosWindow);
		if (nopb == false) {
			text.setPosition(Vector2f(2000, 2000));
			dice1.setPosition(Vector2f(2000, 2000));
			dice2.setPosition(Vector2f(2000, 2000));
			dice3.setPosition(Vector2f(2000, 2000));
			dice4.setPosition(Vector2f(2000, 2000));
			dice5.setPosition(Vector2f(2000, 2000));
			dice6.setPosition(Vector2f(2000, 2000));
			player1.setPosition(Vector2f(2000, 2000));
			player2.setPosition(Vector2f(2000, 2000));
			player3.setPosition(Vector2f(2000, 2000));
			player4.setPosition(Vector2f(2000, 2000));
		}
		//event polling
		while (window.pollEvent(ev)) {
			switch (ev.type) {
			case Event::Closed:
				window.close();
				break;
			case Event::KeyPressed:
				if (ev.key.code == Keyboard::Escape) {
					window.close();
				}
				if (ev.key.code == Keyboard::C) {
					printf("%f   %f\n", mousePosView.x, mousePosView.y);
				}
				//player movements
				if (ev.key.code == Keyboard::Num1 || ev.key.code == Keyboard::Numpad1) {
					nopt.setPosition(Vector2f(2000, 2000));
					text.setPosition(Vector2f(1620, 50));
					dice6.setPosition(Vector2f(1650, 750));
					player1.setPosition(Vector2f(pl1.plx[0], pl1.ply[0]));
					nopb = true;
					nop = 1;
				}
				else if (ev.key.code == Keyboard::Num2 || ev.key.code == Keyboard::Numpad2) {
					nopt.setPosition(Vector2f(2000, 2000));
					text.setPosition(Vector2f(1620, 50));
					dice6.setPosition(Vector2f(1650, 750));
					player1.setPosition(Vector2f(pl1.plx[0], pl1.ply[0]));
					player2.setPosition(Vector2f(pl2.plx[0], pl2.ply[0]));
					nopb = true;
					nop = 2;
				}
				else if (ev.key.code == Keyboard::Num3 || ev.key.code == Keyboard::Numpad3) {
					nopt.setPosition(Vector2f(2000, 2000));
					text.setPosition(Vector2f(1620, 50));
					dice6.setPosition(Vector2f(1650, 750));
					player1.setPosition(Vector2f(pl1.plx[0], pl1.ply[0]));
					player2.setPosition(Vector2f(pl2.plx[0], pl2.ply[0]));
					player3.setPosition(Vector2f(pl3.plx[0], pl3.ply[0]));
					nopb = true;
					nop = 3;
				}
				else if (ev.key.code == Keyboard::Num4 || ev.key.code == Keyboard::Numpad4) {
					nopt.setPosition(Vector2f(2000, 2000));
					text.setPosition(Vector2f(1620, 50));
					dice6.setPosition(Vector2f(1650, 750));
					player1.setPosition(Vector2f(pl1.plx[0], pl1.ply[0]));
					player2.setPosition(Vector2f(pl2.plx[0], pl2.ply[0]));
					player3.setPosition(Vector2f(pl3.plx[0], pl3.ply[0]));
					player4.setPosition(Vector2f(pl4.plx[0], pl4.ply[0]));
					nopb = true;
					nop = 4;
				}
				if (nop == 1 && nopb == true && (vicb == true)) {
					if (ev.key.code == Keyboard::Space && (vicb == true)) {
						text.setString("Player 1\n\nPress\nSpace\nto\nroll");
						soundr.play();
						int i;
						srand(time(NULL));
						i = rand() % 6 + 1;
						printf("%d", i);
						if (i == 1) {
							dice1.setPosition(Vector2f(1650, 750));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (i == 2) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(1650, 750));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (i == 3) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(1650, 750));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (i == 4) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(1650, 750));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (i == 5) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(1650, 750));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (i == 6) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(1650, 750));
						}
						pl1.no += i;
						if (pl1.no > 100) {
							pl1.no -= i;
						}

						//player 1 movements

						//Snakes
						if (pl1.no == 44) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[2], pl1.ply[1]));
							pl1.no = 22;
						}
						else if (pl1.no == 46) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[4], pl1.ply[0]));
							pl1.no = 5;
						}
						else if (pl1.no == 48) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[8], pl1.ply[0]));
							pl1.no = 9;
						}
						else if (pl1.no == 52) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[9], pl1.ply[1]));
							pl1.no = 11;
						}
						else if (pl1.no == 55) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[6], pl1.ply[0]));
							pl1.no = 7;
						}
						else if (pl1.no == 59) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[3], pl1.ply[1]));
							pl1.no = 17;
						}
						else if (pl1.no == 64) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[4], pl1.ply[3]));
							pl1.no = 36;
						}
						else if (pl1.no == 69) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[7], pl1.ply[3]));
							pl1.no = 33;
						}
						else if (pl1.no == 73) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[0], pl1.ply[0]));
							pl1.no = 1;
						}
						else if (pl1.no == 83) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[1], pl1.ply[1]));
							pl1.no = 19;
						}
						else if (pl1.no == 92) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[9], pl1.ply[5]));
							pl1.no = 51;
						}
						else if (pl1.no == 95) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[3], pl1.ply[2]));
							pl1.no = 24;
						}
						else if (pl1.no == 98) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[7], pl1.ply[2]));
							pl1.no = 28;
						}

						//Ladder
						else if (pl1.no == 8) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[5], pl1.ply[2]));
							pl1.no = 26;
						}
						else if (pl1.no == 21) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[1], pl1.ply[8]));
							pl1.no = 82;
						}
						else if (pl1.no == 43) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[3], pl1.ply[7]));
							pl1.no = 77;
						}
						else if (pl1.no == 50) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[9], pl1.ply[9]));
							pl1.no = 91;
						}
						else if (pl1.no == 54) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[7], pl1.ply[9]));
							pl1.no = 93;
						}
						else if (pl1.no == 62) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[4], pl1.ply[9]));
							pl1.no = 96;
						}
						else if (pl1.no == 66) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[6], pl1.ply[8]));
							pl1.no = 87;
						}
						else if (pl1.no == 80) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[0], pl1.ply[9]));
							pl1.no = 100;
						}

						//boxes
						if (pl1.no > 0 && pl1.no < 11) {
							player1.setPosition(Vector2f(pl1.plx[pl1.no - 1], pl1.ply[0]));
						}
						else if (pl1.no > 10 && pl1.no < 21) {
							player1.setPosition(Vector2f(pl1.plx[20 - pl1.no], pl1.ply[1]));
						}
						else if (pl1.no > 20 && pl1.no < 31) {
							player1.setPosition(Vector2f(pl1.plx[pl1.no - 21], pl1.ply[2]));
						}
						else if (pl1.no > 30 && pl1.no < 41) {
							player1.setPosition(Vector2f(pl1.plx[40 - pl1.no], pl1.ply[3]));
						}
						else if (pl1.no > 40 && pl1.no < 51) {
							player1.setPosition(Vector2f(pl1.plx[pl1.no - 41], pl1.ply[4]));
						}
						else if (pl1.no > 50 && pl1.no < 61) {
							player1.setPosition(Vector2f(pl1.plx[60 - pl1.no], pl1.ply[5]));
						}
						else if (pl1.no > 60 && pl1.no < 71) {
							player1.setPosition(Vector2f(pl1.plx[pl1.no - 61], pl1.ply[6]));
						}
						else if (pl1.no > 70 && pl1.no < 81) {
							player1.setPosition(Vector2f(pl1.plx[80 - pl1.no], pl1.ply[7]));
						}
						else if (pl1.no > 80 && pl1.no < 91) {
							player1.setPosition(Vector2f(pl1.plx[pl1.no - 81], pl1.ply[8]));
						}
						else if (pl1.no > 90 && pl1.no < 101) {
							player1.setPosition(Vector2f(pl1.plx[100 - pl1.no], pl1.ply[9]));
						}
						if (pl1.no == 100) {
							soundv.play();
							vicb = false;
							vict.setString("Player 1 Victory");
							vict.setPosition(Vector2f(100, 300));
						}
					}
				}
				if (nop == 2 && (nopb == true) && (vicb == true)) {
					text.setString("Player 1\n\nPress\nSpace\nto\nroll");
					if ((ev.key.code == Keyboard::Space) && (ch2 == 1) && (vicb == true)) {
						text.setString("Player 2\n\nPress\nSpace\nto\nroll");
						soundr.play();
						int i;
						srand(time(NULL));
						i = rand() % 6 + 1;
						if (i == 1) {
							dice1.setPosition(Vector2f(1650, 750));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (i == 2) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(1650, 750));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (i == 3) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(1650, 750));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (i == 4) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(1650, 750));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (i == 5) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(1650, 750));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (i == 6) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(1650, 750));
						}
						pl1.no += i;
						if (pl1.no > 100) {
							pl1.no -= i;
						}

						//player 1 movements

						//Snakes
						if (pl1.no == 44) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[2], pl1.ply[1]));
							pl1.no = 22;
						}
						else if (pl1.no == 46) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[4], pl1.ply[0]));
							pl1.no = 5;
						}
						else if (pl1.no == 48) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[8], pl1.ply[0]));
							pl1.no = 9;
						}
						else if (pl1.no == 52) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[9], pl1.ply[1]));
							pl1.no = 11;
						}
						else if (pl1.no == 55) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[6], pl1.ply[0]));
							pl1.no = 7;
						}
						else if (pl1.no == 59) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[3], pl1.ply[1]));
							pl1.no = 17;
						}
						else if (pl1.no == 64) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[4], pl1.ply[3]));
							pl1.no = 36;
						}
						else if (pl1.no == 69) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[7], pl1.ply[3]));
							pl1.no = 33;
						}
						else if (pl1.no == 73) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[0], pl1.ply[0]));
							pl1.no = 1;
						}
						else if (pl1.no == 83) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[1], pl1.ply[1]));
							pl1.no = 19;
						}
						else if (pl1.no == 92) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[9], pl1.ply[5]));
							pl1.no = 51;
						}
						else if (pl1.no == 95) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[3], pl1.ply[2]));
							pl1.no = 24;
						}
						else if (pl1.no == 98) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[7], pl1.ply[2]));
							pl1.no = 28;
						}

						//Ladder
						else if (pl1.no == 8) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[5], pl1.ply[2]));
							pl1.no = 26;
						}
						else if (pl1.no == 21) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[1], pl1.ply[8]));
							pl1.no = 82;
						}
						else if (pl1.no == 43) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[3], pl1.ply[7]));
							pl1.no = 77;
						}
						else if (pl1.no == 50) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[9], pl1.ply[9]));
							pl1.no = 91;
						}
						else if (pl1.no == 54) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[7], pl1.ply[9]));
							pl1.no = 93;
						}
						else if (pl1.no == 62) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[4], pl1.ply[9]));
							pl1.no = 96;
						}
						else if (pl1.no == 66) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[6], pl1.ply[8]));
							pl1.no = 87;
						}
						else if (pl1.no == 80) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[0], pl1.ply[9]));
							pl1.no = 100;
						}

						//boxes
						if (pl1.no > 0 && pl1.no < 11) {
							player1.setPosition(Vector2f(pl1.plx[pl1.no - 1], pl1.ply[0]));
						}
						else if (pl1.no > 10 && pl1.no < 21) {
							player1.setPosition(Vector2f(pl1.plx[20 - pl1.no], pl1.ply[1]));
						}
						else if (pl1.no > 20 && pl1.no < 31) {
							player1.setPosition(Vector2f(pl1.plx[pl1.no - 21], pl1.ply[2]));
						}
						else if (pl1.no > 30 && pl1.no < 41) {
							player1.setPosition(Vector2f(pl1.plx[40 - pl1.no], pl1.ply[3]));
						}
						else if (pl1.no > 40 && pl1.no < 51) {
							player1.setPosition(Vector2f(pl1.plx[pl1.no - 41], pl1.ply[4]));
						}
						else if (pl1.no > 50 && pl1.no < 61) {
							player1.setPosition(Vector2f(pl1.plx[60 - pl1.no], pl1.ply[5]));
						}
						else if (pl1.no > 60 && pl1.no < 71) {
							player1.setPosition(Vector2f(pl1.plx[pl1.no - 61], pl1.ply[6]));
						}
						else if (pl1.no > 70 && pl1.no < 81) {
							player1.setPosition(Vector2f(pl1.plx[80 - pl1.no], pl1.ply[7]));
						}
						else if (pl1.no > 80 && pl1.no < 91) {
							player1.setPosition(Vector2f(pl1.plx[pl1.no - 81], pl1.ply[8]));
						}
						else if (pl1.no > 90 && pl1.no < 101) {
							player1.setPosition(Vector2f(pl1.plx[100 - pl1.no], pl1.ply[9]));
						}
						ch2 = 2;
						if (pl1.no == 100) {
							soundv.play();
							vicb = false;
							vict.setString("Player 1 Victory");
							vict.setPosition(Vector2f(100, 300));
						}
					}
					else if ((ev.key.code == Keyboard::Space) && (ch2 == 2) && (vicb == true)) {
						text.setString("Player 1\n\nPress\nSpace\nto\nroll");
						soundr.play();
						int j;
						srand(time(NULL));
						j = rand() % 6 + 1;
						if (j == 1) {
							dice1.setPosition(Vector2f(1650, 750));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (j == 2) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(1650, 750));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (j == 3) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(1650, 750));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (j == 4) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(1650, 750));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (j == 5) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(1650, 750));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (j == 6) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(1650, 750));
						}
						pl2.no += j;
						if (pl2.no > 100) {
							pl2.no -= j;
						}

						//player 2 movements

						//Snakes
						if (pl2.no == 44) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[2], pl2.ply[1]));
							pl2.no = 22;
						}
						else if (pl2.no == 46) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[4], pl2.ply[0]));
							pl2.no = 5;
						}
						else if (pl2.no == 48) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[8], pl2.ply[0]));
							pl2.no = 9;
						}
						else if (pl2.no == 52) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[9], pl2.ply[1]));
							pl2.no = 11;
						}
						else if (pl2.no == 55) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[6], pl2.ply[0]));
							pl2.no = 7;
						}
						else if (pl2.no == 59) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[3], pl2.ply[1]));
							pl2.no = 17;
						}
						else if (pl2.no == 64) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[4], pl2.ply[3]));
							pl2.no = 36;
						}
						else if (pl2.no == 69) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[7], pl2.ply[3]));
							pl2.no = 33;
						}
						else if (pl2.no == 73) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[0], pl2.ply[0]));
							pl2.no = 1;
						}
						else if (pl2.no == 83) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[1], pl2.ply[1]));
							pl2.no = 19;
						}
						else if (pl2.no == 92) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[9], pl2.ply[5]));
							pl2.no = 51;
						}
						else if (pl2.no == 95) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[3], pl2.ply[2]));
							pl2.no = 24;
						}
						else if (pl2.no == 98) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[7], pl2.ply[2]));
							pl2.no = 28;
						}

						//Ladder
						else if (pl2.no == 8) {
							soundl.play();
							player2.setPosition(Vector2f(pl2.plx[5], pl2.ply[2]));
							pl2.no = 26;
						}
						else if (pl2.no == 21) {
							soundl.play();
							player2.setPosition(Vector2f(pl2.plx[1], pl2.ply[8]));
							pl2.no = 82;
						}
						else if (pl2.no == 43) {
							soundl.play();
							player2.setPosition(Vector2f(pl2.plx[3], pl2.ply[7]));
							pl2.no = 77;
						}
						else if (pl2.no == 50) {
							soundl.play();
							player2.setPosition(Vector2f(pl2.plx[9], pl2.ply[9]));
							pl2.no = 91;
						}
						else if (pl2.no == 54) {
							soundl.play();
							player2.setPosition(Vector2f(pl2.plx[7], pl2.ply[9]));
							pl2.no = 93;
						}
						else if (pl2.no == 62) {
							soundl.play();
							player2.setPosition(Vector2f(pl2.plx[4], pl2.ply[9]));
							pl2.no = 96;
						}
						else if (pl2.no == 66) {
							soundl.play();
							player2.setPosition(Vector2f(pl2.plx[6], pl2.ply[8]));
							pl2.no = 87;
						}
						else if (pl2.no == 80) {
							soundl.play();
							player2.setPosition(Vector2f(pl2.plx[0], pl2.ply[9]));
							pl2.no = 100;
						}

						//boxes
						if (pl2.no > 0 && pl2.no < 11) {
							player2.setPosition(Vector2f(pl2.plx[pl2.no - 1], pl2.ply[0]));
						}
						else if (pl2.no > 10 && pl2.no < 21) {
							player2.setPosition(Vector2f(pl2.plx[20 - pl2.no], pl2.ply[1]));
						}
						else if (pl2.no > 20 && pl2.no < 31) {
							player2.setPosition(Vector2f(pl2.plx[pl2.no - 21], pl2.ply[2]));
						}
						else if (pl2.no > 30 && pl2.no < 41) {
							player2.setPosition(Vector2f(pl2.plx[40 - pl2.no], pl2.ply[3]));
						}
						else if (pl2.no > 40 && pl2.no < 51) {
							player2.setPosition(Vector2f(pl2.plx[pl2.no - 41], pl2.ply[4]));
						}
						else if (pl2.no > 50 && pl2.no < 61) {
							player2.setPosition(Vector2f(pl2.plx[60 - pl2.no], pl2.ply[5]));
						}
						else if (pl2.no > 60 && pl2.no < 71) {
							player2.setPosition(Vector2f(pl2.plx[pl2.no - 61], pl2.ply[6]));
						}
						else if (pl2.no > 70 && pl2.no < 81) {
							player2.setPosition(Vector2f(pl2.plx[80 - pl2.no], pl2.ply[7]));
						}
						else if (pl2.no > 80 && pl2.no < 91) {
							player2.setPosition(Vector2f(pl2.plx[pl2.no - 81], pl2.ply[8]));
						}
						else if (pl2.no > 90 && pl2.no < 101) {
							player2.setPosition(Vector2f(pl2.plx[100 - pl2.no], pl2.ply[9]));
						}
						ch2 = 1;
						if (pl2.no == 100) {
							soundv.play();
							vicb = false;
							vict.setString("Player 2 Victory");
							vict.setPosition(Vector2f(100, 300));
						}
					}
				}
				if (nop == 3 && (nopb == true) && (vicb == true)) {
					text.setString("Player 1\n\nPress\nSpace\nto\nroll");
					if ((ev.key.code == Keyboard::Space) && (ch2 == 1) && (vicb == true)) {
						text.setString("Player 2\n\nPress\nSpace\nto\nroll");
						soundr.play();
						int i;
						srand(time(NULL));
						i = rand() % 6 + 1;
						if (i == 1) {
							dice1.setPosition(Vector2f(1650, 750));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (i == 2) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(1650, 750));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (i == 3) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(1650, 750));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (i == 4) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(1650, 750));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (i == 5) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(1650, 750));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (i == 6) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(1650, 750));
						}
						pl1.no += i;
						if (pl1.no > 100) {
							pl1.no -= i;
						}

						//player 1 movements

						//Snakes
						if (pl1.no == 44) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[2], pl1.ply[1]));
							pl1.no = 22;
						}
						else if (pl1.no == 46) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[4], pl1.ply[0]));
							pl1.no = 5;
						}
						else if (pl1.no == 48) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[8], pl1.ply[0]));
							pl1.no = 9;
						}
						else if (pl1.no == 52) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[9], pl1.ply[1]));
							pl1.no = 11;
						}
						else if (pl1.no == 55) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[6], pl1.ply[0]));
							pl1.no = 7;
						}
						else if (pl1.no == 59) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[3], pl1.ply[1]));
							pl1.no = 17;
						}
						else if (pl1.no == 64) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[4], pl1.ply[3]));
							pl1.no = 36;
						}
						else if (pl1.no == 69) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[7], pl1.ply[3]));
							pl1.no = 33;
						}
						else if (pl1.no == 73) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[0], pl1.ply[0]));
							pl1.no = 1;
						}
						else if (pl1.no == 83) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[1], pl1.ply[1]));
							pl1.no = 19;
						}
						else if (pl1.no == 92) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[9], pl1.ply[5]));
							pl1.no = 51;
						}
						else if (pl1.no == 95) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[3], pl1.ply[2]));
							pl1.no = 24;
						}
						else if (pl1.no == 98) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[7], pl1.ply[2]));
							pl1.no = 28;
						}

						//Ladder
						else if (pl1.no == 8) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[5], pl1.ply[2]));
							pl1.no = 26;
						}
						else if (pl1.no == 21) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[1], pl1.ply[8]));
							pl1.no = 82;
						}
						else if (pl1.no == 43) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[3], pl1.ply[7]));
							pl1.no = 77;
						}
						else if (pl1.no == 50) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[9], pl1.ply[9]));
							pl1.no = 91;
						}
						else if (pl1.no == 54) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[7], pl1.ply[9]));
							pl1.no = 93;
						}
						else if (pl1.no == 62) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[4], pl1.ply[9]));
							pl1.no = 96;
						}
						else if (pl1.no == 66) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[6], pl1.ply[8]));
							pl1.no = 87;
						}
						else if (pl1.no == 80) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[0], pl1.ply[9]));
							pl1.no = 100;
						}

						//boxes
						if (pl1.no > 0 && pl1.no < 11) {
							player1.setPosition(Vector2f(pl1.plx[pl1.no - 1], pl1.ply[0]));
						}
						else if (pl1.no > 10 && pl1.no < 21) {
							player1.setPosition(Vector2f(pl1.plx[20 - pl1.no], pl1.ply[1]));
						}
						else if (pl1.no > 20 && pl1.no < 31) {
							player1.setPosition(Vector2f(pl1.plx[pl1.no - 21], pl1.ply[2]));
						}
						else if (pl1.no > 30 && pl1.no < 41) {
							player1.setPosition(Vector2f(pl1.plx[40 - pl1.no], pl1.ply[3]));
						}
						else if (pl1.no > 40 && pl1.no < 51) {
							player1.setPosition(Vector2f(pl1.plx[pl1.no - 41], pl1.ply[4]));
						}
						else if (pl1.no > 50 && pl1.no < 61) {
							player1.setPosition(Vector2f(pl1.plx[60 - pl1.no], pl1.ply[5]));
						}
						else if (pl1.no > 60 && pl1.no < 71) {
							player1.setPosition(Vector2f(pl1.plx[pl1.no - 61], pl1.ply[6]));
						}
						else if (pl1.no > 70 && pl1.no < 81) {
							player1.setPosition(Vector2f(pl1.plx[80 - pl1.no], pl1.ply[7]));
						}
						else if (pl1.no > 80 && pl1.no < 91) {
							player1.setPosition(Vector2f(pl1.plx[pl1.no - 81], pl1.ply[8]));
						}
						else if (pl1.no > 90 && pl1.no < 101) {
							player1.setPosition(Vector2f(pl1.plx[100 - pl1.no], pl1.ply[9]));
						}
						ch2 = 2;
						if (pl1.no == 100) {
							soundv.play();
							vicb = false;
							vict.setString("Player 1 Victory");
							vict.setPosition(Vector2f(100, 300));
						}
					}
					else if ((ev.key.code == Keyboard::Space) && (ch2 == 2) && (vicb == true)) {
						text.setString("Player 3\n\nPress\nSpace\nto\nroll");
						soundr.play();
						int j;
						srand(time(NULL));
						j = rand() % 6 + 1;
						if (j == 1) {
							dice1.setPosition(Vector2f(1650, 750));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (j == 2) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(1650, 750));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (j == 3) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(1650, 750));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (j == 4) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(1650, 750));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (j == 5) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(1650, 750));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (j == 6) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(1650, 750));
						}
						pl2.no += j;
						if (pl2.no > 100) {
							pl2.no -= j;
						}

						//player 2 movements

						//Snakes
						if (pl2.no == 44) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[2], pl2.ply[1]));
							pl2.no = 22;
						}
						else if (pl2.no == 46) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[4], pl2.ply[0]));
							pl2.no = 5;
						}
						else if (pl2.no == 48) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[8], pl2.ply[0]));
							pl2.no = 9;
						}
						else if (pl2.no == 52) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[9], pl2.ply[1]));
							pl2.no = 11;
						}
						else if (pl2.no == 55) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[6], pl2.ply[0]));
							pl2.no = 7;
						}
						else if (pl2.no == 59) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[3], pl2.ply[1]));
							pl2.no = 17;
						}
						else if (pl2.no == 64) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[4], pl2.ply[3]));
							pl2.no = 36;
						}
						else if (pl2.no == 69) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[7], pl2.ply[3]));
							pl2.no = 33;
						}
						else if (pl2.no == 73) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[0], pl2.ply[0]));
							pl2.no = 1;
						}
						else if (pl2.no == 83) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[1], pl2.ply[1]));
							pl2.no = 19;
						}
						else if (pl2.no == 92) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[9], pl2.ply[5]));
							pl2.no = 51;
						}
						else if (pl2.no == 95) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[3], pl2.ply[2]));
							pl2.no = 24;
						}
						else if (pl2.no == 98) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[7], pl2.ply[2]));
							pl2.no = 28;
						}

						//Ladder
						else if (pl2.no == 8) {
							soundl.play();
							player2.setPosition(Vector2f(pl2.plx[5], pl2.ply[2]));
							pl2.no = 26;
						}
						else if (pl2.no == 21) {
							soundl.play();
							player2.setPosition(Vector2f(pl2.plx[1], pl2.ply[8]));
							pl2.no = 82;
						}
						else if (pl2.no == 43) {
							soundl.play();
							player2.setPosition(Vector2f(pl2.plx[3], pl2.ply[7]));
							pl2.no = 77;
						}
						else if (pl2.no == 50) {
							soundl.play();
							player2.setPosition(Vector2f(pl2.plx[9], pl2.ply[9]));
							pl2.no = 91;
						}
						else if (pl2.no == 54) {
							soundl.play();
							player2.setPosition(Vector2f(pl2.plx[7], pl2.ply[9]));
							pl2.no = 93;
						}
						else if (pl2.no == 62) {
							soundl.play();
							player2.setPosition(Vector2f(pl2.plx[4], pl2.ply[9]));
							pl2.no = 96;
						}
						else if (pl2.no == 66) {
							soundl.play();
							player2.setPosition(Vector2f(pl2.plx[6], pl2.ply[8]));
							pl2.no = 87;
						}
						else if (pl2.no == 80) {
							soundl.play();
							player2.setPosition(Vector2f(pl2.plx[0], pl2.ply[9]));
							pl2.no = 100;
						}

						//boxes
						if (pl2.no > 0 && pl2.no < 11) {
							player2.setPosition(Vector2f(pl2.plx[pl2.no - 1], pl2.ply[0]));
						}
						else if (pl2.no > 10 && pl2.no < 21) {
							player2.setPosition(Vector2f(pl2.plx[20 - pl2.no], pl2.ply[1]));
						}
						else if (pl2.no > 20 && pl2.no < 31) {
							player2.setPosition(Vector2f(pl2.plx[pl2.no - 21], pl2.ply[2]));
						}
						else if (pl2.no > 30 && pl2.no < 41) {
							player2.setPosition(Vector2f(pl2.plx[40 - pl2.no], pl2.ply[3]));
						}
						else if (pl2.no > 40 && pl2.no < 51) {
							player2.setPosition(Vector2f(pl2.plx[pl2.no - 41], pl2.ply[4]));
						}
						else if (pl2.no > 50 && pl2.no < 61) {
							player2.setPosition(Vector2f(pl2.plx[60 - pl2.no], pl2.ply[5]));
						}
						else if (pl2.no > 60 && pl2.no < 71) {
							player2.setPosition(Vector2f(pl2.plx[pl2.no - 61], pl2.ply[6]));
						}
						else if (pl2.no > 70 && pl2.no < 81) {
							player2.setPosition(Vector2f(pl2.plx[80 - pl2.no], pl2.ply[7]));
						}
						else if (pl2.no > 80 && pl2.no < 91) {
							player2.setPosition(Vector2f(pl2.plx[pl2.no - 81], pl2.ply[8]));
						}
						else if (pl2.no > 90 && pl2.no < 101) {
							player2.setPosition(Vector2f(pl2.plx[100 - pl2.no], pl2.ply[9]));
						}
						ch2 = 3;
						if (pl2.no == 100) {
							soundv.play();
							vicb = false;
							vict.setString("Player 2 Victory");
							vict.setPosition(Vector2f(100, 300));
						}
					}
					else if ((ev.key.code == Keyboard::Space) && (ch2 == 3) && (vicb == true)) {
						text.setString("Player 1\n\nPress\nSpace\nto\nroll");
						soundr.play();
						int k;
						srand(time(NULL));
						k = rand() % 6 + 1;
						if (k == 1) {
							dice1.setPosition(Vector2f(1650, 750));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (k == 2) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(1650, 750));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (k == 3) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(1650, 750));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (k == 4) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(1650, 750));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (k == 5) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(1650, 750));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (k == 6) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(1650, 750));
						}
						pl3.no += k;
						if (pl3.no > 100) {
							pl3.no -= k;
						}

						//player 3 movements

						//Snakes
						if (pl3.no == 44) {
							sounds.play();
							player3.setPosition(Vector2f(pl3.plx[2], pl3.ply[1]));
							pl3.no = 22;
						}
						else if (pl3.no == 46) {
							sounds.play();
							player3.setPosition(Vector2f(pl3.plx[4], pl3.ply[0]));
							pl3.no = 5;
						}
						else if (pl3.no == 48) {
							sounds.play();
							player3.setPosition(Vector2f(pl3.plx[8], pl3.ply[0]));
							pl3.no = 9;
						}
						else if (pl3.no == 52) {
							sounds.play();
							player3.setPosition(Vector2f(pl3.plx[9], pl3.ply[1]));
							pl3.no = 11;
						}
						else if (pl3.no == 55) {
							sounds.play();
							player3.setPosition(Vector2f(pl3.plx[6], pl3.ply[0]));
							pl3.no = 7;
						}
						else if (pl3.no == 59) {
							sounds.play();
							player3.setPosition(Vector2f(pl3.plx[3], pl3.ply[1]));
							pl3.no = 17;
						}
						else if (pl3.no == 64) {
							sounds.play();
							player3.setPosition(Vector2f(pl3.plx[4], pl3.ply[3]));
							pl3.no = 36;
						}
						else if (pl3.no == 69) {
							sounds.play();
							player3.setPosition(Vector2f(pl3.plx[7], pl3.ply[3]));
							pl3.no = 33;
						}
						else if (pl3.no == 73) {
							sounds.play();
							player3.setPosition(Vector2f(pl3.plx[0], pl3.ply[0]));
							pl3.no = 1;
						}
						else if (pl3.no == 83) {
							sounds.play();
							player3.setPosition(Vector2f(pl3.plx[1], pl3.ply[1]));
							pl3.no = 19;
						}
						else if (pl3.no == 92) {
							sounds.play();
							player3.setPosition(Vector2f(pl3.plx[9], pl3.ply[5]));
							pl3.no = 51;
						}
						else if (pl3.no == 95) {
							sounds.play();
							player3.setPosition(Vector2f(pl3.plx[3], pl3.ply[2]));
							pl3.no = 24;
						}
						else if (pl3.no == 98) {
							sounds.play();
							player3.setPosition(Vector2f(pl3.plx[7], pl3.ply[2]));
							pl3.no = 28;
						}

						//Ladder
						else if (pl3.no == 8) {
							soundl.play();
							player3.setPosition(Vector2f(pl3.plx[5], pl3.ply[2]));
							pl3.no = 26;
						}
						else if (pl2.no == 21) {
							soundl.play();
							player3.setPosition(Vector2f(pl3.plx[1], pl3.ply[8]));
							pl3.no = 82;
						}
						else if (pl3.no == 43) {
							soundl.play();
							player3.setPosition(Vector2f(pl3.plx[3], pl3.ply[7]));
							pl3.no = 77;
						}
						else if (pl3.no == 50) {
							soundl.play();
							player3.setPosition(Vector2f(pl3.plx[9], pl3.ply[9]));
							pl3.no = 91;
						}
						else if (pl3.no == 54) {
							soundl.play();
							player3.setPosition(Vector2f(pl3.plx[7], pl3.ply[9]));
							pl3.no = 93;
						}
						else if (pl3.no == 62) {
							soundl.play();
							player3.setPosition(Vector2f(pl3.plx[4], pl3.ply[9]));
							pl3.no = 96;
						}
						else if (pl3.no == 66) {
							soundl.play();
							player3.setPosition(Vector2f(pl3.plx[6], pl3.ply[8]));
							pl3.no = 87;
						}
						else if (pl3.no == 80) {
							soundl.play();
							player3.setPosition(Vector2f(pl3.plx[0], pl3.ply[9]));
							pl3.no = 100;
						}

						//boxes
						if (pl3.no > 0 && pl3.no < 11) {
							player3.setPosition(Vector2f(pl3.plx[pl3.no - 1], pl3.ply[0]));
						}
						else if (pl3.no > 10 && pl3.no < 21) {
							player3.setPosition(Vector2f(pl3.plx[20 - pl3.no], pl3.ply[1]));
						}
						else if (pl3.no > 20 && pl3.no < 31) {
							player3.setPosition(Vector2f(pl3.plx[pl3.no - 21], pl3.ply[2]));
						}
						else if (pl3.no > 30 && pl3.no < 41) {
							player3.setPosition(Vector2f(pl3.plx[40 - pl3.no], pl3.ply[3]));
						}
						else if (pl3.no > 40 && pl3.no < 51) {
							player3.setPosition(Vector2f(pl3.plx[pl3.no - 41], pl3.ply[4]));
						}
						else if (pl3.no > 50 && pl3.no < 61) {
							player3.setPosition(Vector2f(pl3.plx[60 - pl3.no], pl3.ply[5]));
						}
						else if (pl3.no > 60 && pl3.no < 71) {
							player3.setPosition(Vector2f(pl3.plx[pl3.no - 61], pl3.ply[6]));
						}
						else if (pl3.no > 70 && pl3.no < 81) {
							player3.setPosition(Vector2f(pl3.plx[80 - pl3.no], pl3.ply[7]));
						}
						else if (pl3.no > 80 && pl3.no < 91) {
							player3.setPosition(Vector2f(pl3.plx[pl3.no - 81], pl3.ply[8]));
						}
						else if (pl3.no > 90 && pl3.no < 101) {
							player3.setPosition(Vector2f(pl3.plx[100 - pl3.no], pl3.ply[9]));
						}
						ch2 = 1;
						if (pl3.no == 100) {
							soundv.play();
							vicb = false;
							vict.setString("Player 3 Victory");
							vict.setPosition(Vector2f(100, 300));
						}
					}
				}
				if (nop == 4 && (nopb == true) && (vicb == true)) {
					text.setString("Player 1\n\nPress\nSpace\nto\nroll");
					if ((ev.key.code == Keyboard::Space) && (ch2 == 1) && (vicb == true)) {
						text.setString("Player 2\n\nPress\nSpace\nto\nroll");
						soundr.play();
						int i;
						srand(time(NULL));
						i = rand() % 6 + 1;
						if (i == 1) {
							dice1.setPosition(Vector2f(1650, 750));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (i == 2) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(1650, 750));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (i == 3) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(1650, 750));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (i == 4) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(1650, 750));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (i == 5) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(1650, 750));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (i == 6) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(1650, 750));
						}
						pl1.no += i;
						if (pl1.no > 100) {
							pl1.no -= i;
						}

						//player 1 movements

						//Snakes
						if (pl1.no == 44) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[2], pl1.ply[1]));
							pl1.no = 22;
						}
						else if (pl1.no == 46) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[4], pl1.ply[0]));
							pl1.no = 5;
						}
						else if (pl1.no == 48) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[8], pl1.ply[0]));
							pl1.no = 9;
						}
						else if (pl1.no == 52) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[9], pl1.ply[1]));
							pl1.no = 11;
						}
						else if (pl1.no == 55) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[6], pl1.ply[0]));
							pl1.no = 7;
						}
						else if (pl1.no == 59) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[3], pl1.ply[1]));
							pl1.no = 17;
						}
						else if (pl1.no == 64) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[4], pl1.ply[3]));
							pl1.no = 36;
						}
						else if (pl1.no == 69) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[7], pl1.ply[3]));
							pl1.no = 33;
						}
						else if (pl1.no == 73) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[0], pl1.ply[0]));
							pl1.no = 1;
						}
						else if (pl1.no == 83) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[1], pl1.ply[1]));
							pl1.no = 19;
						}
						else if (pl1.no == 92) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[9], pl1.ply[5]));
							pl1.no = 51;
						}
						else if (pl1.no == 95) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[3], pl1.ply[2]));
							pl1.no = 24;
						}
						else if (pl1.no == 98) {
							sounds.play();
							player1.setPosition(Vector2f(pl1.plx[7], pl1.ply[2]));
							pl1.no = 28;
						}

						//Ladder
						else if (pl1.no == 8) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[5], pl1.ply[2]));
							pl1.no = 26;
						}
						else if (pl1.no == 21) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[1], pl1.ply[8]));
							pl1.no = 82;
						}
						else if (pl1.no == 43) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[3], pl1.ply[7]));
							pl1.no = 77;
						}
						else if (pl1.no == 50) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[9], pl1.ply[9]));
							pl1.no = 91;
						}
						else if (pl1.no == 54) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[7], pl1.ply[9]));
							pl1.no = 93;
						}
						else if (pl1.no == 62) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[4], pl1.ply[9]));
							pl1.no = 96;
						}
						else if (pl1.no == 66) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[6], pl1.ply[8]));
							pl1.no = 87;
						}
						else if (pl1.no == 80) {
							soundl.play();
							player1.setPosition(Vector2f(pl1.plx[0], pl1.ply[9]));
							pl1.no = 100;
						}

						//boxes
						if (pl1.no > 0 && pl1.no < 11) {
							player1.setPosition(Vector2f(pl1.plx[pl1.no - 1], pl1.ply[0]));
						}
						else if (pl1.no > 10 && pl1.no < 21) {
							player1.setPosition(Vector2f(pl1.plx[20 - pl1.no], pl1.ply[1]));
						}
						else if (pl1.no > 20 && pl1.no < 31) {
							player1.setPosition(Vector2f(pl1.plx[pl1.no - 21], pl1.ply[2]));
						}
						else if (pl1.no > 30 && pl1.no < 41) {
							player1.setPosition(Vector2f(pl1.plx[40 - pl1.no], pl1.ply[3]));
						}
						else if (pl1.no > 40 && pl1.no < 51) {
							player1.setPosition(Vector2f(pl1.plx[pl1.no - 41], pl1.ply[4]));
						}
						else if (pl1.no > 50 && pl1.no < 61) {
							player1.setPosition(Vector2f(pl1.plx[60 - pl1.no], pl1.ply[5]));
						}
						else if (pl1.no > 60 && pl1.no < 71) {
							player1.setPosition(Vector2f(pl1.plx[pl1.no - 61], pl1.ply[6]));
						}
						else if (pl1.no > 70 && pl1.no < 81) {
							player1.setPosition(Vector2f(pl1.plx[80 - pl1.no], pl1.ply[7]));
						}
						else if (pl1.no > 80 && pl1.no < 91) {
							player1.setPosition(Vector2f(pl1.plx[pl1.no - 81], pl1.ply[8]));
						}
						else if (pl1.no > 90 && pl1.no < 101) {
							player1.setPosition(Vector2f(pl1.plx[100 - pl1.no], pl1.ply[9]));
						}
						ch2 = 2;
						if (pl1.no == 100) {
							soundv.play();
							vicb = false;
							vict.setString("Player 1 Victory");
							vict.setPosition(Vector2f(100, 300));
						}
					}
					else if ((ev.key.code == Keyboard::Space) && (ch2 == 2) && (vicb == true)) {
						text.setString("Player 3\n\nPress\nSpace\nto\nroll");
						soundr.play();
						int j;
						srand(time(NULL));
						j = rand() % 6 + 1;
						if (j == 1) {
							dice1.setPosition(Vector2f(1650, 750));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (j == 2) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(1650, 750));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (j == 3) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(1650, 750));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (j == 4) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(1650, 750));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (j == 5) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(1650, 750));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (j == 6) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(1650, 750));
						}
						pl2.no += j;
						if (pl2.no > 100) {
							pl2.no -= j;
						}

						//player 2 movements

						//Snakes
						if (pl2.no == 44) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[2], pl2.ply[1]));
							pl2.no = 22;
						}
						else if (pl2.no == 46) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[4], pl2.ply[0]));
							pl2.no = 5;
						}
						else if (pl2.no == 48) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[8], pl2.ply[0]));
							pl2.no = 9;
						}
						else if (pl2.no == 52) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[9], pl2.ply[1]));
							pl2.no = 11;
						}
						else if (pl2.no == 55) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[6], pl2.ply[0]));
							pl2.no = 7;
						}
						else if (pl2.no == 59) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[3], pl2.ply[1]));
							pl2.no = 17;
						}
						else if (pl2.no == 64) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[4], pl2.ply[3]));
							pl2.no = 36;
						}
						else if (pl2.no == 69) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[7], pl2.ply[3]));
							pl2.no = 33;
						}
						else if (pl2.no == 73) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[0], pl2.ply[0]));
							pl2.no = 1;
						}
						else if (pl2.no == 83) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[1], pl2.ply[1]));
							pl2.no = 19;
						}
						else if (pl2.no == 92) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[9], pl2.ply[5]));
							pl2.no = 51;
						}
						else if (pl2.no == 95) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[3], pl2.ply[2]));
							pl2.no = 24;
						}
						else if (pl2.no == 98) {
							sounds.play();
							player2.setPosition(Vector2f(pl2.plx[7], pl2.ply[2]));
							pl2.no = 28;
						}

						//Ladder
						else if (pl2.no == 8) {
							soundl.play();
							player2.setPosition(Vector2f(pl2.plx[5], pl2.ply[2]));
							pl2.no = 26;
						}
						else if (pl2.no == 21) {
							soundl.play();
							player2.setPosition(Vector2f(pl2.plx[1], pl2.ply[8]));
							pl2.no = 82;
						}
						else if (pl2.no == 43) {
							soundl.play();
							player2.setPosition(Vector2f(pl2.plx[3], pl2.ply[7]));
							pl2.no = 77;
						}
						else if (pl2.no == 50) {
							soundl.play();
							player2.setPosition(Vector2f(pl2.plx[9], pl2.ply[9]));
							pl2.no = 91;
						}
						else if (pl2.no == 54) {
							soundl.play();
							player2.setPosition(Vector2f(pl2.plx[7], pl2.ply[9]));
							pl2.no = 93;
						}
						else if (pl2.no == 62) {
							soundl.play();
							player2.setPosition(Vector2f(pl2.plx[4], pl2.ply[9]));
							pl2.no = 96;
						}
						else if (pl2.no == 66) {
							soundl.play();
							player2.setPosition(Vector2f(pl2.plx[6], pl2.ply[8]));
							pl2.no = 87;
						}
						else if (pl2.no == 80) {
							soundl.play();
							player2.setPosition(Vector2f(pl2.plx[0], pl2.ply[9]));
							pl2.no = 100;
						}

						//boxes
						if (pl2.no > 0 && pl2.no < 11) {
							player2.setPosition(Vector2f(pl2.plx[pl2.no - 1], pl2.ply[0]));
						}
						else if (pl2.no > 10 && pl2.no < 21) {
							player2.setPosition(Vector2f(pl2.plx[20 - pl2.no], pl2.ply[1]));
						}
						else if (pl2.no > 20 && pl2.no < 31) {
							player2.setPosition(Vector2f(pl2.plx[pl2.no - 21], pl2.ply[2]));
						}
						else if (pl2.no > 30 && pl2.no < 41) {
							player2.setPosition(Vector2f(pl2.plx[40 - pl2.no], pl2.ply[3]));
						}
						else if (pl2.no > 40 && pl2.no < 51) {
							player2.setPosition(Vector2f(pl2.plx[pl2.no - 41], pl2.ply[4]));
						}
						else if (pl2.no > 50 && pl2.no < 61) {
							player2.setPosition(Vector2f(pl2.plx[60 - pl2.no], pl2.ply[5]));
						}
						else if (pl2.no > 60 && pl2.no < 71) {
							player2.setPosition(Vector2f(pl2.plx[pl2.no - 61], pl2.ply[6]));
						}
						else if (pl2.no > 70 && pl2.no < 81) {
							player2.setPosition(Vector2f(pl2.plx[80 - pl2.no], pl2.ply[7]));
						}
						else if (pl2.no > 80 && pl2.no < 91) {
							player2.setPosition(Vector2f(pl2.plx[pl2.no - 81], pl2.ply[8]));
						}
						else if (pl2.no > 90 && pl2.no < 101) {
							player2.setPosition(Vector2f(pl2.plx[100 - pl2.no], pl2.ply[9]));
						}
						ch2 = 3;
						if (pl2.no == 100) {
							soundv.play();
							vicb = false;
							vict.setString("Player 2 Victory");
							vict.setPosition(Vector2f(100, 300));
						}
					}
					else if ((ev.key.code == Keyboard::Space) && (ch2 == 3) && (vicb == true)) {
						text.setString("Player 4\n\nPress\nSpace\nto\nroll");
						soundr.play();
						int k;
						srand(time(NULL));
						k = rand() % 6 + 1;
						if (k == 1) {
							dice1.setPosition(Vector2f(1650, 750));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (k == 2) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(1650, 750));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (k == 3) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(1650, 750));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (k == 4) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(1650, 750));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (k == 5) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(1650, 750));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (k == 6) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(1650, 750));
						}
						pl3.no += k;
						if (pl3.no > 100) {
							pl3.no -= k;
						}

						//player 3 movements

						//Snakes
						if (pl3.no == 44) {
							sounds.play();
							player3.setPosition(Vector2f(pl3.plx[2], pl3.ply[1]));
							pl3.no = 22;
						}
						else if (pl3.no == 46) {
							sounds.play();
							player3.setPosition(Vector2f(pl3.plx[4], pl3.ply[0]));
							pl3.no = 5;
						}
						else if (pl3.no == 48) {
							sounds.play();
							player3.setPosition(Vector2f(pl3.plx[8], pl3.ply[0]));
							pl3.no = 9;
						}
						else if (pl3.no == 52) {
							sounds.play();
							player3.setPosition(Vector2f(pl3.plx[9], pl3.ply[1]));
							pl3.no = 11;
						}
						else if (pl3.no == 55) {
							sounds.play();
							player3.setPosition(Vector2f(pl3.plx[6], pl3.ply[0]));
							pl3.no = 7;
						}
						else if (pl3.no == 59) {
							sounds.play();
							player3.setPosition(Vector2f(pl3.plx[3], pl3.ply[1]));
							pl3.no = 17;
						}
						else if (pl3.no == 64) {
							sounds.play();
							player3.setPosition(Vector2f(pl3.plx[4], pl3.ply[3]));
							pl3.no = 36;
						}
						else if (pl3.no == 69) {
							sounds.play();
							player3.setPosition(Vector2f(pl3.plx[7], pl3.ply[3]));
							pl3.no = 33;
						}
						else if (pl3.no == 73) {
							sounds.play();
							player3.setPosition(Vector2f(pl3.plx[0], pl3.ply[0]));
							pl3.no = 1;
						}
						else if (pl3.no == 83) {
							sounds.play();
							player3.setPosition(Vector2f(pl3.plx[1], pl3.ply[1]));
							pl3.no = 19;
						}
						else if (pl3.no == 92) {
							sounds.play();
							player3.setPosition(Vector2f(pl3.plx[9], pl3.ply[5]));
							pl3.no = 51;
						}
						else if (pl3.no == 95) {
							sounds.play();
							player3.setPosition(Vector2f(pl3.plx[3], pl3.ply[2]));
							pl3.no = 24;
						}
						else if (pl3.no == 98) {
							sounds.play();
							player3.setPosition(Vector2f(pl3.plx[7], pl3.ply[2]));
							pl3.no = 28;
						}

						//Ladder
						else if (pl3.no == 8) {
							soundl.play();
							player3.setPosition(Vector2f(pl3.plx[5], pl3.ply[2]));
							pl3.no = 26;
						}
						else if (pl2.no == 21) {
							soundl.play();
							player3.setPosition(Vector2f(pl3.plx[1], pl3.ply[8]));
							pl3.no = 82;
						}
						else if (pl3.no == 43) {
							soundl.play();
							player3.setPosition(Vector2f(pl3.plx[3], pl3.ply[7]));
							pl3.no = 77;
						}
						else if (pl3.no == 50) {
							soundl.play();
							player3.setPosition(Vector2f(pl3.plx[9], pl3.ply[9]));
							pl3.no = 91;
						}
						else if (pl3.no == 54) {
							soundl.play();
							player3.setPosition(Vector2f(pl3.plx[7], pl3.ply[9]));
							pl3.no = 93;
						}
						else if (pl3.no == 62) {
							soundl.play();
							player3.setPosition(Vector2f(pl3.plx[4], pl3.ply[9]));
							pl3.no = 96;
						}
						else if (pl3.no == 66) {
							soundl.play();
							player3.setPosition(Vector2f(pl3.plx[6], pl3.ply[8]));
							pl3.no = 87;
						}
						else if (pl3.no == 80) {
							soundl.play();
							player3.setPosition(Vector2f(pl3.plx[0], pl3.ply[9]));
							pl3.no = 100;
						}

						//boxes
						if (pl3.no > 0 && pl3.no < 11) {
							player3.setPosition(Vector2f(pl3.plx[pl3.no - 1], pl3.ply[0]));
						}
						else if (pl3.no > 10 && pl3.no < 21) {
							player3.setPosition(Vector2f(pl3.plx[20 - pl3.no], pl3.ply[1]));
						}
						else if (pl3.no > 20 && pl3.no < 31) {
							player3.setPosition(Vector2f(pl3.plx[pl3.no - 21], pl3.ply[2]));
						}
						else if (pl3.no > 30 && pl3.no < 41) {
							player3.setPosition(Vector2f(pl3.plx[40 - pl3.no], pl3.ply[3]));
						}
						else if (pl3.no > 40 && pl3.no < 51) {
							player3.setPosition(Vector2f(pl3.plx[pl3.no - 41], pl3.ply[4]));
						}
						else if (pl3.no > 50 && pl3.no < 61) {
							player3.setPosition(Vector2f(pl3.plx[60 - pl3.no], pl3.ply[5]));
						}
						else if (pl3.no > 60 && pl3.no < 71) {
							player3.setPosition(Vector2f(pl3.plx[pl3.no - 61], pl3.ply[6]));
						}
						else if (pl3.no > 70 && pl3.no < 81) {
							player3.setPosition(Vector2f(pl3.plx[80 - pl3.no], pl3.ply[7]));
						}
						else if (pl3.no > 80 && pl3.no < 91) {
							player3.setPosition(Vector2f(pl3.plx[pl3.no - 81], pl3.ply[8]));
						}
						else if (pl3.no > 90 && pl3.no < 101) {
							player3.setPosition(Vector2f(pl3.plx[100 - pl3.no], pl3.ply[9]));
						}
						ch2 = 4;
						if (pl3.no == 100) {
							soundv.play();
							vicb = false;
							vict.setString("Player 3 Victory");
							vict.setPosition(Vector2f(100, 300));
						}
					}
					else if ((ev.key.code == Keyboard::Space) && (ch2 == 4) && (vicb == true)) {
						text.setString("Player 1\n\nPress\nSpace\nto\nroll");
						soundr.play();
						int l;
						srand(time(NULL));
						l = rand() % 6 + 1;
						if (l == 1) {
							dice1.setPosition(Vector2f(1650, 750));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (l == 2) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(1650, 750));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (l == 3) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(1650, 750));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (l == 4) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(1650, 750));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (l == 5) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(1650, 750));
							dice6.setPosition(Vector2f(2000, 2000));
						}
						else if (l == 6) {
							dice1.setPosition(Vector2f(2000, 2000));
							dice2.setPosition(Vector2f(2000, 2000));
							dice3.setPosition(Vector2f(2000, 2000));
							dice4.setPosition(Vector2f(2000, 2000));
							dice5.setPosition(Vector2f(2000, 2000));
							dice6.setPosition(Vector2f(1650, 750));
						}
						pl4.no += l;
						if (pl4.no > 100) {
							pl4.no -= l;
						}

						//player 4 movements

						//Snakes
						if (pl4.no == 44) {
							sounds.play();
							player4.setPosition(Vector2f(pl4.plx[2], pl4.ply[1]));
							pl4.no = 22;
						}
						else if (pl4.no == 46) {
							sounds.play();
							player4.setPosition(Vector2f(pl4.plx[4], pl4.ply[0]));
							pl4.no = 5;
						}
						else if (pl4.no == 48) {
							sounds.play();
							player4.setPosition(Vector2f(pl4.plx[8], pl4.ply[0]));
							pl4.no = 9;
						}
						else if (pl4.no == 52) {
							sounds.play();
							player4.setPosition(Vector2f(pl4.plx[9], pl4.ply[1]));
							pl4.no = 11;
						}
						else if (pl4.no == 55) {
							sounds.play();
							player4.setPosition(Vector2f(pl4.plx[6], pl4.ply[0]));
							pl4.no = 7;
						}
						else if (pl4.no == 59) {
							sounds.play();
							player4.setPosition(Vector2f(pl4.plx[3], pl4.ply[1]));
							pl4.no = 17;
						}
						else if (pl4.no == 64) {
							sounds.play();
							player4.setPosition(Vector2f(pl4.plx[4], pl4.ply[3]));
							pl4.no = 36;
						}
						else if (pl4.no == 69) {
							sounds.play();
							player4.setPosition(Vector2f(pl4.plx[7], pl4.ply[3]));
							pl4.no = 33;
						}
						else if (pl4.no == 73) {
							sounds.play();
							player4.setPosition(Vector2f(pl4.plx[0], pl4.ply[0]));
							pl4.no = 1;
						}
						else if (pl4.no == 83) {
							sounds.play();
							player4.setPosition(Vector2f(pl4.plx[1], pl4.ply[1]));
							pl4.no = 19;
						}
						else if (pl4.no == 92) {
							sounds.play();
							player4.setPosition(Vector2f(pl4.plx[9], pl4.ply[5]));
							pl4.no = 51;
						}
						else if (pl4.no == 95) {
							sounds.play();
							player4.setPosition(Vector2f(pl4.plx[3], pl4.ply[2]));
							pl4.no = 24;
						}
						else if (pl4.no == 98) {
							sounds.play();
							player4.setPosition(Vector2f(pl4.plx[7], pl4.ply[2]));
							pl4.no = 28;
						}

						//Ladder
						else if (pl4.no == 8) {
							soundl.play();
							player4.setPosition(Vector2f(pl4.plx[5], pl4.ply[2]));
							pl4.no = 26;
						}
						else if (pl4.no == 21) {
							soundl.play();
							player4.setPosition(Vector2f(pl4.plx[1], pl4.ply[8]));
							pl4.no = 82;
						}
						else if (pl4.no == 43) {
							soundl.play();
							player4.setPosition(Vector2f(pl4.plx[3], pl4.ply[7]));
							pl4.no = 77;
						}
						else if (pl4.no == 50) {
							soundl.play();
							player4.setPosition(Vector2f(pl4.plx[9], pl4.ply[9]));
							pl4.no = 91;
						}
						else if (pl4.no == 54) {
							soundl.play();
							player4.setPosition(Vector2f(pl4.plx[7], pl4.ply[9]));
							pl4.no = 93;
						}
						else if (pl4.no == 62) {
							soundl.play();
							player4.setPosition(Vector2f(pl4.plx[4], pl4.ply[9]));
							pl4.no = 96;
						}
						else if (pl4.no == 66) {
							soundl.play();
							player4.setPosition(Vector2f(pl4.plx[6], pl4.ply[8]));
							pl4.no = 87;
						}
						else if (pl4.no == 80) {
							soundl.play();
							player4.setPosition(Vector2f(pl4.plx[0], pl4.ply[9]));
							pl4.no = 100;
						}

						//boxes
						if (pl4.no > 0 && pl4.no < 11) {
							player4.setPosition(Vector2f(pl4.plx[pl4.no - 1], pl4.ply[0]));
						}
						else if (pl4.no > 10 && pl4.no < 21) {
							player4.setPosition(Vector2f(pl4.plx[20 - pl4.no], pl4.ply[1]));
						}
						else if (pl4.no > 20 && pl4.no < 31) {
							player4.setPosition(Vector2f(pl3.plx[pl4.no - 21], pl4.ply[2]));
						}
						else if (pl4.no > 30 && pl4.no < 41) {
							player4.setPosition(Vector2f(pl4.plx[40 - pl4.no], pl4.ply[3]));
						}
						else if (pl4.no > 40 && pl4.no < 51) {
							player4.setPosition(Vector2f(pl4.plx[pl4.no - 41], pl4.ply[4]));
						}
						else if (pl4.no > 50 && pl4.no < 61) {
							player4.setPosition(Vector2f(pl3.plx[60 - pl4.no], pl4.ply[5]));
						}
						else if (pl4.no > 60 && pl4.no < 71) {
							player4.setPosition(Vector2f(pl4.plx[pl4.no - 61], pl4.ply[6]));
						}
						else if (pl4.no > 70 && pl4.no < 81) {
							player4.setPosition(Vector2f(pl4.plx[80 - pl4.no], pl4.ply[7]));
						}
						else if (pl4.no > 80 && pl4.no < 91) {
							player4.setPosition(Vector2f(pl4.plx[pl4.no - 81], pl4.ply[8]));
						}
						else if (pl4.no > 90 && pl4.no < 101) {
							player4.setPosition(Vector2f(pl4.plx[100 - pl4.no], pl4.ply[9]));
						}
						ch2 = 1;
						if (pl4.no == 100) {
							soundv.play();
							vicb = false;
							vict.setString("Player 4 Victory");
							vict.setPosition(Vector2f(100, 300));
						}
					}
				}
				break;
			}
		}
		window.draw(sprite);
		window.draw(nopt);
		window.draw(text);
		window.draw(dice1);
		window.draw(dice2);
		window.draw(dice3);
		window.draw(dice4);
		window.draw(dice5);
		window.draw(dice6);
		window.draw(player1);
		window.draw(player2);
		window.draw(player3);
		window.draw(player4);
		window.draw(vict);
		window.display();
	}
}