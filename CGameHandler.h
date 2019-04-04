#pragma once
#include "CModel.h"
#include "CCube.h"
#include "CPolygon.h"
#include "CKopter.h"
#include "CMission.h"
#include "CFuleStation.h"
#include <stddef.h>
#include <string>
#include <time.h>
#include <math.h>
#include "glut.h"

class CGameHandler
{
public:
	
	//the beginning
	CGameHandler(){};
	void StartOfGame();
	
	//on each frame:
	void DrawScene();
	void LogicPart();
	void WriteText();
	void KeyPressed(char key);
	void SpecialKeyPressed(char key);
	void CameraHendler();
	void TimerHendler(unsigned int _timeForMission);
	bool IsGameOver();
	bool IsGameStart();
	void GameOverScreen();
	void GameStartScreen();
	void GameOverKeyHandle(char key);
	void GameStartKeyHandler(char key);
	void Instructions();
	bool IsInst();
	void InstKeyHandler(char key);
	int Prec();
	
	//getting backgroundColor
	float GetBeckgroundColorR();
	float GetBeckgroundColorG();
	float GetBeckgroundColorB();

private:
	//other procedures
	void ChangeBackgroundColors(float R, float G, float B);

	//internal variables:
	float BGColor_R,BGColor_G,BGColor_B; //BackGround colors.
	int font,def_font; //determine the font to the text written.
	char* WrongKeyText;

	bool _isR,_isL,_isU, _isD, _isPicking;
};