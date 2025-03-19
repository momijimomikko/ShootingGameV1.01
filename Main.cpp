#include <DxLib.h>
#include "Kansuu.h"
//--------------------------------------グローバル関数--------------------------------------------------------------------
int Haikei = 0;

int score = 0;


int MyHP = 1000;

int myX = 600;
int myY = 500;

int ballX;
int ballY;
int ballX2;
int ballY2;

int ct = 100000;

int MainTimer = 0;

int Kougekibosu1Y;

int KougekiBosu2ct = 0;

int KougekiBosu2Y1 = 0;
int KougekiBosu2Y2 = 0;
int KougekiBosu2Y3 = 0;
int KougekiBosu2Y4 = 0;
int KougekiBosu2X4 = 0;
int KougekiBosu2X5 = 0;

int bosu1HP = 3000;

int bosu2HP = 5000;

int Teki1;

int TekiHanteiX;

int TekiHanteiY;

int HanteiTime = 0;

int bosu1ct = 0;

//----------------------------------------グローバル関数ここまで-----------------------------------------------------------
//---------------------------------------WindowSetUP--------------------------------------------------------------------------------

class WindowSetup {
public:

    int Change = 0;

    int Windowsetup(void) {

        SetGraphMode(1200, 700, 32);

        if (CheckHitKey(KEY_INPUT_F11)) {

            if (Change == 0) {

                ChangeWindowMode(FALSE);

                Change += 1;

            }
            else {

                ChangeWindowMode(TRUE);

                Change = 0;

            }

        }

        return 0;
    }

};

//-----------------------------------WindowSetupここまで-----------------------------------------------------------------
//-----------------------------------ホーム画面ここから-----------------------------------------------------------------------------------------------
class Changewindow {
public:

    int Change1;

    int Change() {

        Change1 = LoadGraph("ShootingChange1.png");

        DrawGraph(0, 0, Change1, TRUE);


            if (CheckHitKey(KEY_INPUT_Y) == 1) {

                Haikei = 100;

            }
            if (CheckHitKey(KEY_INPUT_N) == 1) {

                Haikei = 0;
               
            }

        return 0;
    }
};

class Explanewindow {
public:

    int img1;
    int img2;
    int img3;
    int img4;

	int Page1 = 1;
    int Page2 = 0;
	int Page3 = 0;
	int Page4 = 0;

    int Explane(void){

        img1 = LoadGraph("ShootingGameExplane.png");
        img2 = LoadGraph("ShootingGameExplane2.png");
        img3 = LoadGraph("ShootingGameExplane3.png");
        img4 = LoadGraph("ShootingGameExplane4.png");

		if (CheckHitKey(KEY_INPUT_1) != 0) {

			Page1 = 1;
			Page2 = 0;
			Page3 = 0;
			Page4 = 0;

		}

        if (CheckHitKey(KEY_INPUT_2) != 0) {

			Page1 = 0;
			Page2 = 1;
			Page3 = 0;
			Page4 = 0;

        }

        if (CheckHitKey(KEY_INPUT_3) != 0) {

            Page1 = 0;
			Page2 = 0;
			Page3 = 1;
			Page4 = 0;

        }

        if (CheckHitKey(KEY_INPUT_4) != 0) {

            Page1 = 0;
			Page2 = 0;
			Page3 = 0;
			Page4 = 1;

        }

        if (Page1 == 1) {

            DrawGraph(0, 0, img1, TRUE);

        }

        if (Page2 == 1) {

            DrawGraph(0, 0, img2, TRUE);

        }

		if (Page3 == 1) {

			DrawGraph(0, 0, img3, TRUE);

		}

		if (Page4 == 1) {

			DrawGraph(0, 0, img4, TRUE);

		}

        if (CheckHitKey(KEY_INPUT_RETURN) != 0) {

            Haikei = 0;

            Page1 = 0;
			Page2 = 0;
			Page3 = 0;
			Page4 = 0;

        }

        DrawString(1000, 600, "エンターでタイトルに戻る\n\nスペースキーで次のページへ", GetColor(0, 0, 255));


        return 0;
    }
};

class HomeHome {
public:

    int imghome1;
    int imghome2;
    int imghome3;

    int Homehome(void) {
        if (Haikei == 0) {

            imghome1 = LoadGraph("ShootingHome1.png");
            imghome2 = LoadGraph("ShootingHome2.png");
            imghome3 = LoadGraph("ShootingHome3.png");

            SetDrawScreen(DX_SCREEN_BACK);

            ClearDrawScreen();

            DrawGraph(100, 50, imghome1, TRUE);
            DrawGraph(450, 400, imghome2, TRUE);
            DrawGraph(450, 525, imghome3, TRUE);

            DrawString(540, 400, "Aを入力してください", GetColor(0, 0, 255));
            DrawString(540, 525, "Bを入力してください", GetColor(255, 255, 255));

            DrawString(1000, 600, "エンターでタイトルに戻る\nスペースキーで次のページへ", GetColor(0, 0, 255));
            if (CheckHitKey(KEY_INPUT_A) != 0) {
                Haikei = 10;
            }

            if (CheckHitKey(KEY_INPUT_B) != 0) {
                Haikei = 1;
            }
        }
        return 0;
    }
};

class Homewindow {
public:

    Explanewindow Ew;
    Changewindow Cw;
    WindowSetup WS;
    HomeHome Hh;

    int Home(void) {

        while (1)
        {

            WS.Windowsetup();

            if (Haikei == 0) {

                Hh.Homehome();

            }

            if (Haikei == 10) {

                Cw.Change();

            }

            if (Haikei == 1) {

                Ew.Explane();

            }

            ScreenFlip();

            WaitTimer(50);

            if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {

                DxLib_End();

                break;
            }

            if (Haikei == 100) {
                break;
            }
        }
		return 0;
    }
};

//-----------------------------------------------------------ホーム画面ここまで-------------------------------------------------------------


//-------------------------------------------------------------------ゲームここから---------------------------------------------------------------------

class Mypolygon {
public:

    int img1;

    int imgTimer1;
    int imgTimer2;
    int imgTimer3;
    int imgTimer4;
    int imgTimer5;
    int imgTimer6;
    int imgTimer7;
    int imgTimer8;
    int imgTimer9;

    int imgHP1;
    int imgHP2;
    int imgHP3;
    int imgHP4;
    int imgHP5;
    int imgHP6;
    int imgHP7;
    int imgHP8;
    int imgHP9;
    int imgHP10;

    int LoadImg(void) {

        img1 = LoadGraph("MyPolygon.png");

        imgTimer1 = LoadGraph("ShootingTimer1.png");

        imgTimer2 = LoadGraph("ShootingTimer2.png");

        imgTimer3 = LoadGraph("ShootingTimer3.png");

        imgTimer4 = LoadGraph("ShootingTimer4.png");

        imgTimer5 = LoadGraph("ShootingTimer5.png");

        imgTimer6 = LoadGraph("ShootingTimer6.png");

        imgTimer7 = LoadGraph("ShootingTimer7.png");

        imgTimer8 = LoadGraph("ShootingTimer8.png");

        imgTimer9 = LoadGraph("ShootingTimer9.png");

        Teki1 = LoadGraph("ShootingKougeki1.png");

        imgHP1 = LoadGraph("ShootingHPbar1.png");

        imgHP2 = LoadGraph("ShootingHPbar2.png");

        imgHP3 = LoadGraph("ShootingHPbar3.png");

        imgHP4 = LoadGraph("ShootingHPbar4.png");

        imgHP5 = LoadGraph("ShootingHPbar5.png");

        imgHP6 = LoadGraph("ShootingHPbar6.png");

        imgHP7 = LoadGraph("ShootingHPbar7.png");

        imgHP8 = LoadGraph("ShootingHPbar8.png");

        imgHP9 = LoadGraph("ShootingHPbar9.png");

        imgHP10 = LoadGraph("ShootingHPbar10.png");

        return 0;
    }

    int me(void) {

        if (CheckHitKey(KEY_INPUT_LSHIFT) == 0) {

            if (CheckHitKey(KEY_INPUT_W) != 0) {

                myY -= 10;

                if (myY <= 0) {
                    myY = 0;
                }

            }

            if (CheckHitKey(KEY_INPUT_A) != 0) {

                myX -= 10;

                if (myX <= 0) {
                    myX = 0;
                }

            }

            if (CheckHitKey(KEY_INPUT_S) != 0) {

                myY += 10;

                if (myY >= 574) {
                    myY = 574;
                }

            }

            if (CheckHitKey(KEY_INPUT_D) != 0) {

                myX += 10;

                if (myX >= 1100) {
                    myX = 1100;
                }

            }

        }
        else {

            if (CheckHitKey(KEY_INPUT_W) != 0) {

                myY -= 5;

            }

            if (CheckHitKey(KEY_INPUT_A) != 0) {

                myX -= 5;

            }

            if (CheckHitKey(KEY_INPUT_S) != 0) {

                myY += 5;

            }

            if (CheckHitKey(KEY_INPUT_D) != 0) {

                myX += 5;

            }

        }
        
        DrawGraph(myX, myY, img1, FALSE);

        return 0;
        
    }

    int Ball(void) {

        ballY = myY;

        ballX = myX + 45;

        ballX2 = ballX + 10;

        ballY2 = myY - 10000;

        if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {




                       if (ct > 7) {

                           DrawBox(ballX, ballY, ballX2, ballY2, GetColor(0, 255, 0), TRUE);

                           if (CheckHitKey(KEY_INPUT_LSHIFT) == 0) {

                               ct -= 5;

                           }
                           else {

                               ct -= 7;

                           }

                       }

        }
        if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {

            if (ct > 15) {

                DrawBox(ballX, ballY, ballX2, ballY2, GetColor(0, 0, 255), TRUE);

                if (CheckHitKey(KEY_INPUT_LSHIFT) == 0) {

                    ct -= 10;

                }
                else {

                    ct -= 15;

                }

            }

        }
        return 0;
    }


    int Timer(void) {

        ct += 4;

        if (ct > 1500) {
            ct = 1500;
        }

        if (ct < 60) {

            DrawGraph(10, 10, imgTimer1, FALSE);

        }
        if ((ct < 120)&& (ct >= 60)) {

            DrawGraph(10, 10, imgTimer2, FALSE);

        }
        if ((ct >= 120)&& (ct < 180)) {

            DrawGraph(10, 10, imgTimer3, FALSE);

        }
        if ((ct >= 180)&& (ct < 240)) {

            DrawGraph(10, 10, imgTimer4, FALSE);

        }
        if ((ct >= 240)&& (ct < 300)) {

            DrawGraph(10, 10, imgTimer5, FALSE);

        }
        if ((ct >= 300)&& (ct < 360)) {

            DrawGraph(10, 10, imgTimer6, FALSE);

        }
        if ((ct >= 360)&& (ct < 420)) {

            DrawGraph(10, 10, imgTimer7, FALSE);

        }
        if ((ct >= 420)&& (ct < 480)) {

            DrawGraph(10, 10, imgTimer8, FALSE);

        }
        if (ct >= 480) {

            DrawGraph(10, 10, imgTimer9, FALSE);

        }
        if ((ct >= 540) && (ct < 600)) {

            DrawGraph(70, 10, imgTimer1, FALSE);

        }
        if ((ct >= 600) && (ct < 660)) {

            DrawGraph(70, 10, imgTimer2, FALSE);

        }
        if ((ct >= 660) && (ct < 720)) {

            DrawGraph(70, 10, imgTimer3, FALSE);

        }
        if ((ct >= 720) && (ct < 780)) {

            DrawGraph(70, 10, imgTimer4, FALSE);

        }
        if ((ct >= 780) && (ct < 840)) {

            DrawGraph(70, 10, imgTimer5, FALSE);

        }
        if ((ct >= 840) && (ct < 900)) {

            DrawGraph(70, 10, imgTimer6, FALSE);

        }
        if ((ct >= 900) && (ct < 960)) {

            DrawGraph(70, 10, imgTimer7, FALSE);

        }
        if ((ct >= 960) && (ct < 1020)) {

            DrawGraph(70, 10, imgTimer8, FALSE);

        }
        if (ct >= 1020) {

            DrawGraph(70, 10, imgTimer9, FALSE);

        }
        if ((ct >= 1020) && (ct < 1080)) {

            DrawGraph(130, 10, imgTimer1, FALSE);

        }
        if ((ct >= 1080) && (ct < 1140)) {

            DrawGraph(130, 10, imgTimer2, FALSE);

        }
        if ((ct >= 1140) && (ct < 1200)) {

            DrawGraph(130, 10, imgTimer3, FALSE);

        }
        if ((ct >= 1200) && (ct < 1260)) {

            DrawGraph(130, 10, imgTimer4, FALSE);

        }
        if ((ct >= 1260) && (ct < 1320)) {

            DrawGraph(130, 10, imgTimer5, FALSE);

        }
        if ((ct >= 1320) && (ct < 1380)) {

            DrawGraph(130, 10, imgTimer6, FALSE);

        }
        if ((ct >= 1380) && (ct < 1440)) {

            DrawGraph(130, 10, imgTimer7, FALSE);

        }
        if ((ct >= 1440) && (ct < 1500)) {

            DrawGraph(130, 10, imgTimer8, FALSE);

        }
        if (ct >= 1500) {

            DrawGraph(130, 10, imgTimer9, FALSE);

        }

        return 0;

    }

    int MyHantei(void) {

        if ((((myX < TekiHanteiX + 120)&&(myX + 100> TekiHanteiX)) && ((myY + 126 > TekiHanteiY) && (myY < TekiHanteiY + 79)))
           || (((myX + 100 > TekiHanteiX)&&(myX < TekiHanteiX + 120)) && ((myY < TekiHanteiY + 79) && (myY + 126 > TekiHanteiY)))) {

            MyHP -= 3;

        }


        if ((MainTimer >= 1660) && (MainTimer <= 3600)) {

            if (bosu1HP > 0) {

                if ((bosu1ct <= 80) && (bosu1ct >= 20)) {

                    if ((myY <= Kougekibosu1Y + 50) && (myY + 126 >= Kougekibosu1Y)) {

                        MyHP -= 4;

                    }
                }
            }
        }

        if ((MainTimer >= 5100)&&(MainTimer <= 7000)) {

			if ((KougekiBosu2ct <= 70) && (KougekiBosu2ct >= 0)) {

                if (bosu2HP > 0) {

                    if ((myY <= KougekiBosu2Y1 + 20) && (myY + 126 >= KougekiBosu2Y1)) {

                        MyHP -= 4;

                    }

                    if ((myY <= KougekiBosu2Y2 + 20) && (myY + 126 >= KougekiBosu2Y2)) {

                        MyHP -= 4;

                    }

                    if ((myY <= KougekiBosu2Y3 + 20) && (myY + 126 >= KougekiBosu2Y3)) {

                        MyHP -= 4;

                    }

                    if ((myX <= KougekiBosu2X4 + 20) && (myX + 100 >= KougekiBosu2X4)) {

                        MyHP -= 4;

                    }
                }
			}
        }

        return 0;

    }

    int HPbar(void) {

        if (MyHP == 1000) {

            DrawGraph(0, 80, imgHP1, TRUE);

        }

        if ((MyHP < 1000) && (MyHP >= 901)) {

            DrawGraph(0, 80, imgHP2, TRUE);

        }

        if ((MyHP < 901) && (MyHP >= 801)) {

            DrawGraph(0, 80, imgHP3, TRUE);

        }

        if ((MyHP < 801) && (MyHP >= 701)) {

            DrawGraph(0, 80, imgHP4, TRUE);

        }

        if ((MyHP < 701) && (MyHP >= 601)) {

            DrawGraph(0, 80, imgHP5, TRUE);

        }

        if ((MyHP < 601) && (MyHP >= 501)) {

            DrawGraph(0, 80, imgHP6, TRUE);

        }

        if ((MyHP < 501) && (MyHP >= 401)) {

            DrawGraph(0, 80, imgHP7, TRUE);

        }

        if ((MyHP < 401) && (MyHP >= 301)) {

            DrawGraph(0, 80, imgHP8, TRUE);

        }

        if ((MyHP < 301) && (MyHP >= 201)) {

            DrawGraph(0, 80, imgHP9, TRUE);

        }

        if (MyHP < 201){

            DrawGraph(0, 80, imgHP10, TRUE);

        }

        return 0;
    }

	int scoreDisplay(void) {

        DrawFormatString(1050, 20, GetColor(255, 255, 255),"Score...%d",score);

		return 0;

	}

};

class Enemy {
public:

    int HP1 = 300;
    int HP2 = 300;
    int HP3 = 600;
    int HP4 = 600;
    int HP5 = 600;
    int HP6 = 300;
    int HP7 = 300;
	int HP8 = 300;
    int HP9 = 600;
	int HP10 = 600;
	int HP11 = 600;
	int HP12 = 300;
	int HP13 = 600;

    int img1;
    int img2;
    int img3;
    int img4;
	int img5;
	int img6;
    int img7;
    int img8;
	int img9;
	int img10;
	int img11;
	int img12;
	int img13;

    int imgbosu1;
	int imgbosu2;

    int imgDisappear1;
	int imgDisappear2;
    int imgDisappearbosu1;

    int imgDisappearbosu2;

    int imgbosukougeki1;
    int imgbosukougeki21;
    int imgbosukougeki22;
    int imgbosukougeki23;
	int imgbosukougeki24;

    int imgbosukougekix1;

    int imgbosu2kougeki1;
    int imgbosu2kougeki2;
	int imgbosu2kougeki3;
	int imgbosu2kougeki4;
	int imgbosu2kougekix1;
	int imgbosu2kougekix2;
	int imgbosu2kougekix3;
	int imgbosu2kougekix4;

    int imgWarn;

    int hassya = 10;

    int hassya2 = 8;

	int bosu1randomX;
	int bosu1randomY;

    int LoadImg(void) {

        img1 = LoadGraph("Teki1.png");
        img2 = LoadGraph("Teki1.png");
        img3 = LoadGraph("Teki2.png");
		img4 = LoadGraph("Teki2.png");
		img5 = LoadGraph("Teki2.png");
		img6 = LoadGraph("Teki1.png");
		img7 = LoadGraph("Teki1.png");
		img8 = LoadGraph("Teki1.png");
		img9 = LoadGraph("Teki2.png");
		img10 = LoadGraph("Teki2.png");
		img11 = LoadGraph("Teki2.png");
		img12 = LoadGraph("Teki1.png");
		img13 = LoadGraph("Teki2.png");

		imgbosu1 = LoadGraph("ShootingBosu1.png");
        imgbosu2 = LoadGraph("ShootingBosu2.png");

		imgDisappear1 = LoadGraph("ShootingDisappear1.png");
		imgDisappear2 = LoadGraph("ShootingDisappear2.png");
		imgDisappearbosu1 = LoadGraph("ShootingDisappearbosu1.png");
		imgDisappearbosu2 = LoadGraph("ShootingDisappearbosu1.png");

		imgbosukougeki1 = LoadGraph("Shootingbosukougeki1.png");
		imgbosukougeki21 = LoadGraph("Shootingbosukougeki21.png");
		imgbosukougeki22 = LoadGraph("Shootingbosukougeki22.png");
		imgbosukougeki23 = LoadGraph("Shootingbosukougeki23.png");
		imgbosukougeki24 = LoadGraph("Shootingbosukougeki24.png");

		imgbosukougekix1 = LoadGraph("Shootingbosukougekix1.png");

		imgbosu2kougeki1 = LoadGraph("Shootingbosu2kougeki1.png");
		imgbosu2kougeki2 = LoadGraph("Shootingbosu2kougeki2.png");
		imgbosu2kougeki3 = LoadGraph("Shootingbosu2kougeki3.png");
		imgbosu2kougeki4 = LoadGraph("Shootingbosu2kougeki4.png");

        imgbosu2kougekix1 = LoadGraph("Shootingbosu2kougekix1.png");
		imgbosu2kougekix2 = LoadGraph("Shootingbosu2kougekix4.png");
		imgbosu2kougekix3 = LoadGraph("Shootingbosu2kougekix3.png");
		imgbosu2kougekix4 = LoadGraph("Shootingbosu2kougekix4.png");

        imgWarn = LoadGraph("ShootingWarning.png");

        return 0;

    }

    int Hantei1(void) {

        if ((ballX >= 400) && (ballX <= 480)) {

            if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {


                if (ct > 7) {

                    HP1 -= 5;
                }

            }

            if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {

                if (ct > 7) {

                    HP1 -= 7;
                }

            }

        }

        return 0;

    }

    int Hantei2(void) {

        if ((ballX >= 1000) && (ballX <= 1080)) {

            if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {


                if (ct > 7) {

                    HP2 -= 5;
                }
            }


            if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {


                if (ct > 7) {

                    HP2 -= 7;
                }
            }
        }

        return 0;

    }

    int Hantei3(void) {

        if ((ballX >= 300) && (ballX <= 380)) {

            if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {


                if (ct > 7) {

                    HP3 -= 5;
                }
            }


            if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {

                if (ct > 7) {

                    HP3 -= 7;
                }
            }
        }

        return 0;

    }

    int Hantei4(void) {

        if ((ballX >= 100) && (ballX <= 180)) {

            if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {


                if (ct > 7) {

                    HP4 -= 5;
                }
            }

            if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {


                if (ct > 7) {

                    HP4 -= 7;
                }



            }
        }

        return 0;

    }

    int Hantei5(void) {

        if ((ballX >= 700) && (ballX <= 780)) {

            if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {


                if (ct > 7) {

                    HP5 -= 5;
                }
            }


            if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {


                if (ct > 7) {

                    HP5 -= 7;
                }
            }
        }

        return 0;

    }

    int Hantei6(void) {

        if ((ballX >= 1100) && (ballX <= 1180)) {

            if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {


                if (ct > 7) {

                    HP6 -= 5;
                }
            }


            if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {


                if (ct > 7) {

                    HP6 -= 7;

                }

            }
        }

        return 0;
    }

    int Hantei7(void) {

        if ((ballX >= 100) && (ballX <= 180)) {

            if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {


                if (ct > 7) {

                    HP7 -= 5;
                }
            }


            if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {


                if (ct > 7) {

                    HP7 -= 7;
                }
            }
        }

        return 0;

    }

    int Hantei8(void) {

        if ((ballX >= 800) && (ballX <= 880)) {

            if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {


                if (ct > 7) {

                    HP8 -= 5;
                }
            }


            if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {


                if (ct > 7) {

                    HP8 -= 7;
                }
            }
        }

        return 0;
    }

    int Hantei9(void) {

        if ((ballX >= 300) && (ballX <= 380)) {

            if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {


                if (ct > 7) {

                    HP9 -= 5;
                }
            }


            if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {


                if (ct > 7) {

                    HP9 -= 7;
                }
            }
        }

        return 0;
    }

    int Hantei10(void) {
    
        if ((ballX >= 600) && (ballX <= 680)) {

            if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {


                if (ct > 7) {

                    HP10 -= 5;
                }
            }


            if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {


                if (ct > 7) {

                    HP10 -= 7;
                }
            }
        }

        return 0;
    
    }

    int Hantei11(void) {

        if ((ballX >= 1000) && (ballX <= 1080)) {

            if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {


                if (ct > 7) {

                    HP11 -= 5;
                }
            }


            if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {


                if (ct > 7) {

                    HP11 -= 7;
                }
            }
        }

        return 0;
    
    }

    int Hantei12(void) {

        if ((ballX >= 100) && (ballX <= 180)) {

            if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {


                if (ct > 7) {

                    HP12 -= 5;
                }
            }


            if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {


                if (ct > 7) {

                    HP12 -= 7;
                }
            }
        }

        return 0;

    }

    int Hantei13(void) {

        if ((ballX >= 600) && (ballX <= 680)) {

            if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {


                if (ct > 7) {

                    HP13 -= 5;
                }
            }


            if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {


                if (ct > 7) {

                    HP13 -= 7;
                }

            }
        }

        return 0;

    }

    int KougekiBosu1(void) {

        if (bosu1HP > 0) {

            if ((bosu1ct <= 0)||(bosu1ct >= 80)) {

                DrawGraph(100, Kougekibosu1Y, imgbosukougeki1, TRUE);

            }

            if ((bosu1ct <= 80) && (bosu1ct >= 20)) {

				if (hassya < 0) {
					hassya = 10;
				}

                if (hassya < 3) {

                    DrawGraph(100, Kougekibosu1Y, imgbosukougeki21, TRUE);

                    hassya -= 1;

                }

                if ((hassya >= 3) && (hassya < 5)) {

					DrawGraph(100, Kougekibosu1Y, imgbosukougeki22, TRUE);
					hassya -= 1;
                }

                if ((hassya >= 5) && (hassya < 8)) {

					DrawGraph(100, Kougekibosu1Y, imgbosukougeki23, TRUE);
					hassya -= 1;

                }

                if (hassya >= 8) {

					DrawGraph(100, Kougekibosu1Y, imgbosukougeki24, TRUE);
					hassya -= 1;

                }

            }

        }
        return 0;
    }

    int KougekiBosu2(void) {

        if (KougekiBosu2ct < 0) {

            KougekiBosu2ct += 180;

            KougekiBosu2Y1 = GetRand(600) + 100;
            KougekiBosu2Y2 = GetRand(600) + 100;
            KougekiBosu2Y3 = GetRand(600) + 100;
			KougekiBosu2Y4 = GetRand(600) + 100;
			KougekiBosu2X4 = GetRand(600) + 300;
			KougekiBosu2X5 = GetRand(600) + 300;

        }
        else {

			KougekiBosu2ct -= 1;

        }

        if (KougekiBosu2ct >= 70) {

            DrawGraph(100, KougekiBosu2Y1, imgbosukougeki1, TRUE);
			DrawGraph(100, KougekiBosu2Y2, imgbosukougeki1, TRUE);
			DrawGraph(100, KougekiBosu2Y3, imgbosukougeki1, TRUE);
			DrawGraph(100, KougekiBosu2Y4, imgbosukougeki1, TRUE);
			DrawGraph(KougekiBosu2X4, 0, imgbosukougekix1, TRUE);
            DrawGraph(KougekiBosu2X5, 0, imgbosukougekix1, TRUE);

        }

        if ((KougekiBosu2ct > 0) && (KougekiBosu2ct < 70)) {

            if (hassya2 <= 0) {

				hassya2 = 8;

            }

            if (hassya2 <= 2) {

                DrawGraph(100, KougekiBosu2Y1, imgbosu2kougeki1, TRUE);
                DrawGraph(100, KougekiBosu2Y2, imgbosu2kougeki1, TRUE);
                DrawGraph(100, KougekiBosu2Y3, imgbosu2kougeki1, TRUE);
                DrawGraph(100, KougekiBosu2Y4, imgbosu2kougeki1, TRUE);
				DrawGraph(KougekiBosu2X4, 0, imgbosu2kougekix1, TRUE);
                DrawGraph(KougekiBosu2X5, 0, imgbosu2kougekix1, TRUE);

				hassya2 -= 1;

            }

			if ((hassya2 <= 4) && (hassya2 > 2)) {

				DrawGraph(100, KougekiBosu2Y1, imgbosu2kougeki2, TRUE);
				DrawGraph(100, KougekiBosu2Y2, imgbosu2kougeki2, TRUE);
				DrawGraph(100, KougekiBosu2Y3, imgbosu2kougeki2, TRUE);
				DrawGraph(100, KougekiBosu2Y4, imgbosu2kougeki2, TRUE);
				DrawGraph(KougekiBosu2X4, 0, imgbosu2kougekix2, TRUE);
                DrawGraph(KougekiBosu2X5, 0, imgbosu2kougekix2, TRUE);

				hassya2 -= 1;

			}

            if ((hassya2 <= 6) && (hassya2 > 4)) {
            
				DrawGraph(100, KougekiBosu2Y1, imgbosu2kougeki3, TRUE);
				DrawGraph(100, KougekiBosu2Y2, imgbosu2kougeki3, TRUE);
				DrawGraph(100, KougekiBosu2Y3, imgbosu2kougeki3, TRUE);
				DrawGraph(100, KougekiBosu2Y4, imgbosu2kougeki3, TRUE);
				DrawGraph(KougekiBosu2X4, 0, imgbosu2kougekix3, TRUE);
                DrawGraph(KougekiBosu2X5, 0, imgbosu2kougekix3, TRUE);

				hassya2 -= 1;
            
            }

            if ((hassya2 <= 8) && (hassya2 > 6)) {
            
				DrawGraph(100, KougekiBosu2Y1, imgbosu2kougeki4, TRUE);
				DrawGraph(100, KougekiBosu2Y2, imgbosu2kougeki4, TRUE);
				DrawGraph(100, KougekiBosu2Y3, imgbosu2kougeki4, TRUE);
				DrawGraph(100, KougekiBosu2Y4, imgbosu2kougeki4, TRUE);
				DrawGraph(KougekiBosu2X4, 0, imgbosu2kougekix4, TRUE);
                DrawGraph(KougekiBosu2X5, 0, imgbosu2kougekix4, TRUE);

				hassya2 -= 1;
            
            }

        }


        return 0;
    }

    int HanteiBosu2(void) {

        if ((ballX >= 550) && (ballX <= 650)) {

            if (myY > 500) {

                if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {


                    if (ct > 7) {

                        bosu2HP -= 5;
                    }
                }


                if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {


                    if (ct > 7) {

                        bosu2HP -= 7;
                    }
                }
            }
        }

		return 0;
    }

    int HanteiDisplayBosu1(void) {

        if (bosu1ct != 0) {

            bosu1ct -= 1;

        }

        if (bosu1ct == 0) {

            bosu1randomX = GetRand(1100);

            bosu1randomY = GetRand(500);

            Kougekibosu1Y = GetRand(350) + 350;

            bosu1ct = 120;

        }

        DrawGraph(bosu1randomX, bosu1randomY, imgbosu1, TRUE);

        if ((ballX >= bosu1randomX) && (ballX <= bosu1randomX + 30)) {

            if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {


                if (ct > 7) {

                    bosu1HP -= 5;

                }
            }

            if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {


                if (ct > 7) {

                    bosu1HP -= 7;
                }



            }

        }

        return 0;
    }

    int DisappearBosu1(void) {

        DrawGraph(300, 350, imgDisappearbosu1, TRUE);

        return 0;
    }

    int Display() {

        if ((MainTimer >= 120) && (MainTimer <= 360)) {

            Hantei1();

            if (HP1 > 0) {

                DrawGraph(400, 200, img1, TRUE);

            }
            else {

                DrawGraph(400, 100, imgDisappear1, TRUE);

				score += 10;
            }

        }

        if ((MainTimer >= 300) && (MainTimer <= 480)) {

            Hantei2();

            if (HP2 > 0) {

                DrawGraph(1000, 300, img2, TRUE);

            }
            else {

                DrawGraph(1000, 200, imgDisappear2, TRUE);

				score += 10;

            }

        }
        if ((MainTimer >= 520) && (MainTimer <= 700)) {

            Hantei3();

            if (HP3 > 0) {

                DrawGraph(300, 200, img3, TRUE);

            }
            else {

                DrawGraph(300, 100, imgDisappear2, TRUE);

				score += 30;

            }
        }

        if ((MainTimer >= 600) && (MainTimer <= 800)) {

            Hantei4();

            if (HP4 > 0) {

                DrawGraph(100, 500, img4, TRUE);

            }
            else {

                DrawGraph(100, 400, imgDisappear2,TRUE);

				score += 30;

            }
        }

        if ((MainTimer >= 900) && (MainTimer <= 1100)) {

            Hantei5();

            if (HP5 > 0) {

                DrawGraph(700, 100, img5, TRUE);

            }
            else {

                DrawGraph(700, 0, imgDisappear2, TRUE);

				score += 30;

            }
        }

        if ((MainTimer >= 1050) && (MainTimer <= 1200)) {

            Hantei6();

            if (HP6 > 0) {

                DrawGraph(1100, 350, img6, TRUE);

            }
            else{

                DrawGraph(1100, 250, imgDisappear1, TRUE);

                score += 10;

            }
        }

        if ((MainTimer >= 1150) && (MainTimer <= 1300)) {

            Hantei7();

            if (HP7 > 0) {

                DrawGraph(100, 500, img7, TRUE);

            }
            else {

                DrawGraph(100, 40, imgDisappear1, TRUE);

                score += 10;

            }
        }

        if ((MainTimer >= 1400)&&(MainTimer <= 1600)) {

			DrawGraph(350, 100, imgWarn, TRUE);

        }


        if ((MainTimer >= 1660) && (MainTimer <= 3600)) {

            if (bosu1HP > 0) {

                HanteiDisplayBosu1();

				KougekiBosu1();

            }
            else {

                DisappearBosu1();

				score += 40;

            }
        }

        if ((MainTimer >= 3800) && (MainTimer <= 4000)) {

            if (HP8 > 0) {

				Hantei8();

				DrawGraph(800, 0, img8, TRUE);

			}
            else {

                DrawGraph(800, 50, imgDisappear1, TRUE);

                score += 10;

            }
        }

		if ((MainTimer >= 3900) && (MainTimer <= 4100)) {

			if (HP9 > 0) {

				Hantei9();

				DrawGraph(300, 300, img9, TRUE);

			}
			else {

				DrawGraph(300, 350, imgDisappear2, TRUE);

				score += 30;

			}
		}

		if ((MainTimer >= 4000) && (MainTimer <= 4200)) {

			if (HP10 > 0) {

				Hantei10();

				DrawGraph(600, 100, img10, TRUE);

			}
			else {

				DrawGraph(600, 0, imgDisappear2, TRUE);

				score += 30;

			}
		}

		if ((MainTimer >= 4150) && (MainTimer <= 4300)) {

			if (HP11 > 0) {

				Hantei11();

				DrawGraph(1000, 500, img11, TRUE);

			}
			else {

				DrawGraph(1000, 400, imgDisappear2, TRUE);

				score += 30;

			}
		}

		if ((MainTimer >= 4350) && (MainTimer <= 4500)) {

			if (HP12 > 0) {

				Hantei12();

				DrawGraph(100, 300, img12, TRUE);

			}
			else {

				DrawGraph(100, 200, imgDisappear1, TRUE);

				score += 10;

			}
		}

        if ((MainTimer >= 4530) && (MainTimer <= 4700)) {

			if (HP13 > 0) {

				Hantei13();

				DrawGraph(600, 200, img13, TRUE);

			}
			else {

				DrawGraph(600, 100, imgDisappear2, TRUE);

				score += 30;

			}

        }

        if ((MainTimer >= 4800) && (MainTimer <= 5000)) {

            DrawGraph(350, 100, imgWarn, TRUE);
        }

        if ((MainTimer >= 5100)&&(MainTimer <= 7000)) {

            if (bosu2HP > 0) {

                DrawGraph(550, 200, imgbosu2, TRUE);

				KougekiBosu2();

				HanteiBosu2();

            }
            else {

                DrawGraph(600, 200, imgDisappearbosu2, TRUE);

				score += 40;

            }
        }

        return 0;
    }

    int Kougeki1(void) {

        int Kakuritu = GetRand(100);

        int Which = GetRand(1);

        int RandX = GetRand(1000);

        int RandY = GetRand(400);

        int RandnumX = GetRand(1);

        if (HanteiTime <= 0) {

                if ((Kakuritu == 100) || (Kakuritu == 50)) {

                    TekiHanteiX = RandX;

                    TekiHanteiY = RandY;

                    DrawGraph(TekiHanteiX, TekiHanteiY, Teki1, TRUE);

                    HanteiTime = 1;

                }
        }


        if (HanteiTime == 1) {

            if (TekiHanteiY <700) {

                if (MainTimer <= 720) {

                    TekiHanteiY += 3;

                }

                if ((MainTimer > 720)&&(MainTimer <= 3600)) {

                    TekiHanteiY += 6;

                }

				if (MainTimer > 3600) {

					TekiHanteiY += 9;

				}

                DrawGraph(TekiHanteiX, TekiHanteiY, Teki1, TRUE);

                if (TekiHanteiY >= 699) {

                    HanteiTime = 0;

                }

            }
        }

        return 0;
    }

    int MainTimerCount(void) {

        MainTimer += 1;

        return 0;

    }

};

class NANIKA {
public:

    int Hack(void) {

        if (CheckHitKey(KEY_INPUT_F1)) {

            if (CheckHitKey(KEY_INPUT_AT)) {

                if (CheckHitKey(KEY_INPUT_BACKSLASH)) {

                    MyHP += 100;

                }
            }

        }

        return 0;

    }


};



class Gamewindow {
public:

    Mypolygon Mp;
    Enemy EM;
    NANIKA NK;

    int window(void) {

        int background;

        background = LoadGraph("ShootingGameWindow.png");

        DrawGraph(0, 0, background, TRUE);

        Mp.LoadImg();

        EM.LoadImg();

        while (1) {

            SetDrawScreen(DX_SCREEN_BACK);

            ClearDrawScreen();

            Mp.me();

            EM.MainTimerCount();

            Mp.Timer();

            Mp.MyHantei();

            Mp.Ball();

            EM.Display();

            EM.Kougeki1();

            Mp.HPbar();

			Mp.scoreDisplay();

            NK.Hack();

            ScreenFlip();

            WaitTimer(16);

            if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {

                DxLib_End();

                break;
            }

            if (MyHP <= 0) {
                break;
            }

            ProcessMessage();

            if (MainTimer >= 3600) {
            
				if (bosu1HP > 0) {

					break;

				}
            
            }

			if (MainTimer >= 7000) {

                if (bosu2HP > 0) {

                    break;

                }
			}

        }

        return 0;
    }
};


//-------------------------------------------------------------------ゲームここまで----------------------------------------------------------------------------------


//----------------------------------------------------------------------------終了画面---------------------------------------------------------

class End {
public:

    int img1;
    int img2;

    int Endwindow1(void) {

        img1 = LoadGraph("ShootingEnd1.png");

        SetDrawScreen(DX_SCREEN_BACK);

        ClearDrawScreen();

        DrawGraph(0, 0, img1, TRUE);

        ScreenFlip();

        WaitTimer(3000);

        return 0;
    }

	int Endwindow2(void) {

		img2 = LoadGraph("ShootingEnd2.png");

		SetDrawScreen(DX_SCREEN_BACK);

		ClearDrawScreen();

		DrawGraph(0, 0, img2, TRUE);

		ScreenFlip();

		WaitTimer(3000);

		return 0;


	}
};



////---------------------------------------------------------------------------ここまで-------------------------------------------------------------------
    int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
    {

       ChangeWindowMode(TRUE);

       Homewindow Hw;

       Gamewindow Gw;

       End Ew;

        if (DxLib_Init() == -1)
        {
            return -1;
        }

        Hw.Home();

        ProcessMessage();

        Gw.window();

		if (MyHP < 1) {

			Ew.Endwindow2();

        }
        else {

            Ew.Endwindow1();

        }

        DxLib_End();

        return 0;
    }