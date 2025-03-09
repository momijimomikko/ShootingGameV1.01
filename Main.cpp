#include "DxLib.h"
<<<<<<< HEAD
//-----------------w-------f--------------------グローバル関数-------------------ってなんだや--------------------------------------------------------------------
=======
#include <iostream>
//--------------------------------------------グローバル関数----------------------ってなんだや--------------------------------------------------------------------
>>>>>>> 77f3a733c769edbadafb3b3c74ba1c8ba644f446

int MyHP = 1000;

int ballX;
int ballY;
int ballX2;
int ballY2;

int ct = 100000;


int HP1 = 300;
int HP2 = 300;
int HP3 = 600;

int MainTimer = 0;

int Teki1;

int TekiHanteiX;

int TekiHanteiY;

int HanteiTime = 0;


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


//-----------------------------------ホーム画面ここから-----------------------------------------------------------------------------------------------
class Changewindow {
public:

    int Change1;

    int Change() {

        Change1 = LoadGraph("ShootingChange1.png");

        DrawGraph(0, 0, Change1, TRUE);


            if (CheckHitKey(KEY_INPUT_Y) == 1) {

            }
            if (CheckHitKey(KEY_INPUT_N) == 1) {
               
            }

        return 0;
    }
};

class Explanewindow {
public:

    int img1;
    int img2;

    int Explane(void){

        img1 = LoadGraph("ShootingGameExplane.png");
        img2 = LoadGraph("ShootingGameExplane2.png");

        DrawGraph(0, 0, img1, TRUE);

       if (CheckHitKey(KEY_INPUT_SPACE) != 0) {

           while (1) {

               WaitTimer(50);

               SetDrawScreen(DX_SCREEN_BACK);

               ClearDrawScreen();

               DrawGraph(0, 0, img2, TRUE);

               ScreenFlip();

               if (CheckHitKey(KEY_INPUT_RETURN) != 0) {
                   break;
               }

           }

       }
        DrawString(1000, 600, "エンターでタイトルに戻る\n\nスペースキーで次のページへ", GetColor(0, 0, 255));


        return 0;
    }
};

class Homewindow {
public:

    Explanewindow Ew;
    Changewindow Cw;
    WindowSetup WS;

    int imghome1;
    int imghome2;
    int imghome3;

    int Home(void) {

        while (1) {

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
            DrawString(1050, 680, "ESCキーで終わる", GetColor(255, 255, 255));

            WS.Windowsetup();

            if (CheckHitKey(KEY_INPUT_A) != 0) {

                while (1){

                    SetDrawScreen(DX_SCREEN_BACK);

                    ClearDrawScreen();

                    Cw.Change();



                    ScreenFlip();

                    if (CheckHitKey(KEY_INPUT_Y) != 0) {
                        break;
                    }

                    if (CheckHitKey(KEY_INPUT_N) != 0) {
                        break;
                    }

                    WaitTimer(50);

                }
            }

            if (CheckHitKey(KEY_INPUT_B) != 0) {

                while (CheckHitKey(KEY_INPUT_RETURN) == 0) {

                    SetDrawScreen(DX_SCREEN_BACK);

                    ClearDrawScreen();

                    Ew.Explane();

                    WS.Windowsetup();

                    ScreenFlip();

                    WaitTimer(50);
                }
            }

            if (CheckHitKey(KEY_INPUT_Y) != 0) {
                break;
            }

            ScreenFlip();

            WaitTimer(50);

            if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {

                DxLib_End();

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

    int myX = 600;
    int myY = 500;

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

        ct += 2;

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

};

class Enemy {
public:


    int img1;
    int img2;

    int HP1 = 300;
    int HP2 = 300;
    int HP3 = 600;
    int HP4 = 300;
    int HP5 = 600;
    int HP6 = 300;
    int HP7 = 300;

    int LoadImg(void) {

        img1 = LoadGraph("Teki1.png");
        img2 = LoadGraph("Teki2.png");

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

    int MainTimerCount(void) {

        MainTimer += 1;

        return 0;

    }

    int Display() {

        if ((MainTimer >= 120) && (MainTimer <= 360)) {

            Hantei1();

            if (HP1 > 0) {

                DrawGraph(400, 200, img1, TRUE);

            }
            else {
                DrawString(400, 100, "やられたぁぁ", GetColor(255,255,255));

                HP1 = -10;
            }
           
        }
        if ((MainTimer >= 300) && (MainTimer <= 480)) {

            Hantei2();

            if (HP2 > 0) {

                DrawGraph(1000, 300, img1, TRUE);

            }
            else {
                DrawString(1000, 200, "やられたぁぁ", GetColor(255, 255, 255));

                HP2 = -10;
            }

        }
        if ((MainTimer >= 520) && (MainTimer <= 700)) {

            Hantei3();

            if (HP3 > 0) {

                DrawGraph(300, 200, img2, TRUE);

            }
            else {
                DrawString(300, 100, "やられたぁぁ", GetColor(0, 133, 255));

            }

            if ((MainTimer >= 600) && (MainTimer <= 1000)) {

                Hantei4();

                if (HP4 > 0) {

                    DrawGraph(100, 500, img2, TRUE);

                }
                else {
                    DrawString(100, 400, "やられたぁぁ", GetColor(0, 133, 255));

                }
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
                if (MainTimer > 720) {

                    TekiHanteiY += 6;

                }

                DrawGraph(TekiHanteiX, TekiHanteiY, Teki1, TRUE);

                if (TekiHanteiY >= 699) {

                    HanteiTime = 0;

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

    int window(void) {

        int background;

        background = LoadGraph("ShootingGameWindow.png");

        DrawGraph(0, 0, background, TRUE);

        Mp.LoadImg();

        EM.LoadImg();

        while (1) {

            SetDrawScreen(DX_SCREEN_BACK);

            ClearDrawScreen();

            EM.MainTimerCount();

            Mp.Timer();

            Mp.me();

            Mp.MyHantei();

            Mp.Ball();

            EM.Display();

            EM.Kougeki1();

            Mp.HPbar();

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

        }

        return 0;
    }
};


//-------------------------------------------------------------------ゲームここまで----------------------------------------------------------------------------------


//----------------------------------------------------------------------------終了画面---------------------------------------------------------

class End {
public:

    int img1;

    int Endwindow(void) {

        img1 = LoadGraph("ShootingEnd.png");

        SetDrawScreen(DX_SCREEN_BACK);

        ClearDrawScreen();

        DrawGraph(0, 0, img1, TRUE);

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

        Ew.Endwindow();

        DxLib_End();

        return 0;
    }
