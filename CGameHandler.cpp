#include "CGameHandler.h"

CKopter kopter;
CMap map(20,20);
CMission mission(0);
int counter, _id, _howMuch = 0;
char _howMuchStr [3], _howFuleStr[10];
bool _underTheBuilding, _iAmFull, _underTheHospital, _toHos, _onMission, _noTime, _startScreen, _ins, _underFuleStation, _isFuleing;
clock_t _startTime, _countMyTime;
unsigned int totaltime=0,time_left=0, _milliseconds=0,_seconds=0;
double _howFule=1200;
char timeLeft [5];
CRoad road;
CCube cube, person;
CFuleStation fule;
extern void renderBitmapString(float x, float y, void *font, char *string);
extern void renderVerticalBitmapString(float x, float y, int bitmapHeight, void *font, char *string);

void CGameHandler::StartOfGame()
{
	_startScreen = true;
	font = def_font = (int)GLUT_BITMAP_HELVETICA_18;
	ChangeBackgroundColors(0.5, 0.75, 0.25);
	_isR, _isL, _isU, _isD, _underTheBuilding, _isPicking, _underTheHospital, _iAmFull, _toHos, _onMission, _noTime, _ins, _underFuleStation = false;
	kopter.MoveModel(0, 0, 0);
	kopter.ScaleSelfModel(0.5,0.5,0.5);
	map.MakeMap();
	map.MoveMapCenter(0,-3,0);
	_startTime=clock();//אתחול השעון
	road.MoveModelCenter(0,-4.5,0);
	road.SetModelColor(0.5,0.5,0.5);
	cube.MoveModelCenter(0,0,0);
	cube.ScaleSelfModel(-1,-1,-1);
	cube.ScaleSelfModel(100,100,100);
	cube.SetModelColor(0,0,0.8);
	person.SetModelColor(0,0,1);
	person.ScaleSelfModel(0.05,0.2,0.05);
	road.ScaleSelfModel((map.GetModel(map.GetNumberOfModels()-1).GetModelCenter().GetCoordinate(X_AXIS)-(map.GetModel(0).GetModelCenter().GetCoordinate(X_AXIS)))*1.5,1,(map.GetModel(map.GetNumberOfModels()-1).GetModelCenter().GetCoordinate(Z_AXIS)-(map.GetModel(0).GetModelCenter().GetCoordinate(Z_AXIS)))*1.5);
	fule.MoveMyCenter(map.GetModel(0).GetModelCenter().GetCoordinate(X_AXIS)-4,-3,map.GetModel(0).GetModelCenter().GetCoordinate(Z_AXIS)+5);
}

void CGameHandler::DrawScene()
{
		kopter.DrawModel();
		fule.DrawFuleStation();
		map.DrawMap();
		road.DrawModel();
		cube.DrawModel();
		person.DrawModel();
}

void CGameHandler::LogicPart()
{
	TimerHendler(360);
	itoa(_howMuch,_howMuchStr,10);
	map.SetHospitalBack();
	kopter.RotatePropelor(50);
	kopter.MoveForward();
	if((kopter.GetModelCenter().GetCoordinate(X_AXIS) < map.GetModel(_id).GetModelCenter().GetCoordinate(X_AXIS)+0.5)&&(kopter.GetModelCenter().GetCoordinate(X_AXIS) > map.GetModel(_id).GetModelCenter().GetCoordinate(X_AXIS)-0.5)&&(kopter.GetModelCenter().GetCoordinate(Z_AXIS) < map.GetModel(_id).GetModelCenter().GetCoordinate(Z_AXIS)+0.5)&&(kopter.GetModelCenter().GetCoordinate(Z_AXIS) > map.GetModel(_id).GetModelCenter().GetCoordinate(Z_AXIS)-0.5)&&!_iAmFull)
		_underTheBuilding = true;
	else _underTheBuilding = false;
	if(!_onMission)
	{
		//map.RepaintBuildings();
		mission.SetNewMission(map.GetNumberOfModels());
		_id = abs(mission.GetMissionId());
		printf("%d  ",_id);
		person.MoveModelCenter(map.GetModel(_id).GetModelCenter().GetCoordinate(X_AXIS), -2, map.GetModel(_id).GetModelCenter().GetCoordinate(Z_AXIS));
		_toHos = false;
		_onMission = true;
	}
	if(_iAmFull)
	{
		map.RepaintBuildings();
		person.MoveModelCenter(map.GetModel(_id).GetModelCenter().GetCoordinate(X_AXIS), -6, map.GetModel(_id).GetModelCenter().GetCoordinate(Z_AXIS));
		_toHos = true;
		_iAmFull = false;
	}
	if((kopter.GetModelCenter().GetCoordinate(X_AXIS) < fule.GetMyCenter().GetCoordinate(X_AXIS)+1)&&(kopter.GetModelCenter().GetCoordinate(X_AXIS) > fule.GetMyCenter().GetCoordinate(X_AXIS)-1)&&(kopter.GetModelCenter().GetCoordinate(Z_AXIS) < fule.GetMyCenter().GetCoordinate(Z_AXIS)+1)&&(kopter.GetModelCenter().GetCoordinate(Z_AXIS) > fule.GetMyCenter().GetCoordinate(Z_AXIS)-1))
	{
		_underFuleStation = true;
	}
	else
	{
		_underFuleStation = false;
	}
	if((kopter.GetModelCenter().GetCoordinate(X_AXIS) < map.GetModel(0).GetModelCenter().GetCoordinate(X_AXIS)+0.5)&&(kopter.GetModelCenter().GetCoordinate(X_AXIS) > map.GetModel(0).GetModelCenter().GetCoordinate(X_AXIS)-0.5)&&(kopter.GetModelCenter().GetCoordinate(Z_AXIS) < map.GetModel(0).GetModelCenter().GetCoordinate(Z_AXIS)+0.5)&&(kopter.GetModelCenter().GetCoordinate(Z_AXIS) > map.GetModel(0).GetModelCenter().GetCoordinate(Z_AXIS)-0.5)&& _toHos)
	{
		_underTheHospital = true;
	}
	else _underTheHospital = false;
	if(_isR)
	{
		kopter.RotateKopterY(1);
		_isR = false;
	}
	if(_isL)
	{
		kopter.RotateKopterY(-1);
		_isL = false;
	}
	if(_isU)
	{
		kopter.Accelerate(-0.01);
		_isU = false;
	}
	if(_isD)
	{
		kopter.Accelerate(0.01);
		_isD = false;
	}
	if (_isPicking) 
	{
		if (counter<=250 && counter>125) {
			kopter.MoveModel(Y_AXIS,-0.01);
			counter--;
		} else if  (counter<=125 && counter>0) {
			kopter.MoveModel(Y_AXIS,0.01);
			counter--;
		} else if (counter==0){
			kopter.MoveModel(Y_AXIS,0);
			_isPicking=0;
		}
	}
	if(_isFuleing)
	{
		if(counter<=250 && counter>100)
		{
			kopter.MoveModel(Y_AXIS,-0.01);
			counter--;
		}
		else 
		{
			if(counter<=100 && counter>-25)
			{
				kopter.MoveModel(Y_AXIS,0);
				counter--;
			} 
			else 
			{
				if(counter<=-25 && counter>-150);
				{
					_howFule=1200;
					kopter.MoveModel(Y_AXIS,0.01);
					counter--;
				}
				if (counter==-150)
				{
					kopter.MoveModel(Y_AXIS,0);
					_isFuleing=0;
				}
			}
		}
	}
	if(_howFule==1)
		_noTime = true;
}

void CGameHandler::WriteText()
{
	font = (int) GLUT_BITMAP_TIMES_ROMAN_24;
	glColor3f(1,1,0);
	int x_pos = glutGet(GLUT_SCREEN_WIDTH)/2-100;
	int y_pos = 30;
	if(_underTheBuilding&&!_toHos)
		renderBitmapString(x_pos, y_pos, (void *)font, "!!UNDER YOU!!");
	if(_underTheHospital&&_toHos)
		renderBitmapString(x_pos, y_pos, (void *)font, "!!LEAVE HIM HERE!!");
	if(_underFuleStation)
	{
		renderBitmapString(x_pos, y_pos, (void *)font, "You Can Fule Here");
	}
	if(_noTime)
		renderBitmapString(x_pos, y_pos+60, (void *)font, "GAME OVER");
	else
	{
		char a[30] = "You Have: ";
		strcat_s(a, timeLeft);
		char b[9] = " Seconds";
		strcat_s(a, b);
		renderBitmapString(x_pos, y_pos+60, (void *)font, a);
	}
	char a[30] = "You Saved: ";
	strcat(a, _howMuchStr);
	char b[7] = " Lives";
	strcat(a, b);
	renderBitmapString(x_pos, 60, (void *)font, a);
	char c[11] = "Fuel: ";
	itoa(Prec(), _howFuleStr, 10);
	strcat(c, _howFuleStr);
	char d[3] = "%";
	strcat(c, d);
	renderBitmapString(x_pos-200, y_pos+60, (void *)font, c);
	renderBitmapString(1, 5*(GLUT_WINDOW_HEIGHT+GLUT_WINDOW_HEIGHT), (void *)font, "KopperChopper");
	glColor3f(0,1,0);
}


void CGameHandler::KeyPressed(char key)
{
	switch (key)
	{
	case ' ':
		if (_isPicking==0)
		{
			kopter.Accelerate(0);
			_isPicking=!_isPicking;
			counter=250;
			if(_underTheBuilding)
				_iAmFull = true;
			if(_toHos == true && _underTheHospital == true){
				_toHos = false;_howMuch++;_onMission=false;}
		}
		if (_underFuleStation == true)
		{
			_isPicking = false;
			_isFuleing=true;
		}
		break;
	case 's':
		kopter.Accelerate(0);
		break;
	default:
		break;
	}
}

void CGameHandler::SpecialKeyPressed(char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		_isR = true;
		break;
	case GLUT_KEY_RIGHT:
		_isL = true;
		break;
	case GLUT_KEY_UP:
		_isU = true;
		break;
	case GLUT_KEY_DOWN:
		_isD = true;
		break;
	default:
		break;
	}
}
float CGameHandler::GetBeckgroundColorR()
{return BGColor_R;}
float CGameHandler::GetBeckgroundColorG()
{return BGColor_G;}
float CGameHandler::GetBeckgroundColorB()
{return BGColor_B;}
void CGameHandler::ChangeBackgroundColors(float R, float G, float B)
{BGColor_R = R;BGColor_G = G;BGColor_B = B;}
void CGameHandler::CameraHendler()
{
	gluLookAt(kopter.GetModelCenter().GetCoordinate(X_AXIS), kopter.GetModelCenter().GetCoordinate(Y_AXIS)+3, kopter.GetModelCenter().GetCoordinate(Z_AXIS)+7, //איפה המצלמה נמצאת
			kopter.GetModelCenter().GetCoordinate(X_AXIS), kopter.GetModelCenter().GetCoordinate(Y_AXIS), kopter.GetModelCenter().GetCoordinate(Z_AXIS), //לאן המצלמה מסתכלת
			0.0, 1.0, 0.0 ); //מה הזווית של המצלמה
}
void CGameHandler::TimerHendler(unsigned int _timeForMission)
{
	_countMyTime=clock();//אתחול מחודש של השעון כדי לקצר את הזמן
	_milliseconds=_countMyTime-_startTime;//כמות המילישניות שנותרו
	_seconds=(_milliseconds/(CLOCKS_PER_SEC));//כמות השניות שנותרו
	time_left=_timeForMission-_seconds; //חיסור כדי לקבל הפרשי זמן
	if(time_left==0)
		_noTime=true;
	itoa(time_left,timeLeft,10);
}
int CGameHandler::Prec()
{

	if(time_left%5==0&&_milliseconds%5==0)
	{
	_howFule--;
	}
	
	return _howFule/12;

}
bool CGameHandler::IsGameOver()
{
	return _noTime;
}

bool CGameHandler::IsGameStart()
{
	return _startScreen;
}
void CGameHandler::GameOverScreen()
{
	glClearColor(1, 0, 0, 0);
	glColor3f(1,1,1);
	int x_pos = glutGet(GLUT_SCREEN_WIDTH)/2-100;
	int y_pos = glutGet(GLUT_SCREEN_HEIGHT)/2-100;
	font = (int) GLUT_BITMAP_TIMES_ROMAN_24;
	renderBitmapString(x_pos, y_pos, (void *)font, "!!GAME OVER!!");
	renderBitmapString(x_pos, y_pos+60, (void *)font, "r - Play Again");
	renderBitmapString(x_pos, y_pos+120, (void *)font, "esc - Exit");
}
void CGameHandler::GameStartScreen()
{
	glClearColor(1, 1, 1, 0);
	glColor3f(0,0,0);
	int x_pos = glutGet(GLUT_SCREEN_WIDTH)/2-100;
	int y_pos = glutGet(GLUT_SCREEN_HEIGHT)/2-100;
	font = (int) GLUT_BITMAP_TIMES_ROMAN_24;
	renderBitmapString(x_pos, GLUT_SCREEN_HEIGHT, (void *)font, "KopterChopper");
	renderBitmapString(x_pos, y_pos+60, (void *)font, "s - Start");
	renderBitmapString(x_pos, y_pos+120, (void *)font, "i - Instructions");
	renderBitmapString(x_pos, y_pos+180, (void *)font, "esc - Exit");
}
void CGameHandler::Instructions()
{
	_startScreen = false;
	glClearColor(1, 1, 1, 0);
	glColor3f(0,0,0);
	int x_pos = glutGet(GLUT_SCREEN_WIDTH)/2-100;
	int y_pos = glutGet(GLUT_SCREEN_HEIGHT)/2-100;
	font = (int) GLUT_BITMAP_TIMES_ROMAN_24;
	renderBitmapString(x_pos, 80, (void *)font, "KopterChopper");
	renderBitmapString(10, 125, (void *)font, "The goal is to save as many patients.");
	renderBitmapString(10, 150, (void *)font, "Injured patients are in blue clouts.");
	renderBitmapString(10, 175, (void *)font, "You should land on the roof and collect the the wounded and then pass it to hospital care.");
	renderBitmapString(10, 200, (void *)font, "Hospital dyed red because of the difficulties in identifying from helicopter due to the thick fog.");
	renderBitmapString(10, 225, (void *)font, "You only have three minutes to the end of reception in the hospital.");
	renderBitmapString(10, 250, (void *)font, "There is fuel station, if you out of fuel the game is over.");

	renderBitmapString(10, 300, (void *)font, "Movement - arrow keys.");
	renderBitmapString(10, 325, (void *)font, "Landing - spacebar.");

	renderBitmapString(10, 400, (void *)font, "s - Start");
	renderBitmapString(10, 425, (void *)font, "esc - Exit");

}
bool CGameHandler::IsInst()
{
	return _ins;
}
void CGameHandler::GameStartKeyHandler(char key)
{
	switch (key)
	{
		case 's':
			_startTime=clock();
			_noTime, _startScreen = false;
			_isR, _isL, _isU, _isD, _underTheBuilding, _isFuleing, _isPicking, _underTheHospital, _iAmFull, _toHos, _onMission, _noTime, _ins = false;
			counter, _id, _howMuch = 0;
			kopter.MoveModelCenter(0, 0, 0);
			kopter.Accelerate(0);
			break;
		case 'i':
			_ins = true;
			break;
		case 27:
			exit(1);
			break;
	}
}
void CGameHandler::GameOverKeyHandle(char key)
{
	switch (key)
	{
		case 'r':
			_startTime=clock();
			_noTime = false;
			_isR, _isL, _isU, _isD, _underTheBuilding, _isFuleing, _isPicking, _underTheHospital, _iAmFull, _toHos, _onMission, _noTime = false;
			counter, _id, _howMuch = 0;
			_howFule = 1200;
			kopter.MoveModelCenter(0, 0, 0);
			kopter.Accelerate(0);
			break;
		case 27:
			exit(1);
			break;
	}
}