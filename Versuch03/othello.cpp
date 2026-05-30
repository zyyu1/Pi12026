/**
 * Praktikum Informatik 1 
 * 
 *
 * @file main.cpp
 *
 * Die Funktionen fuer das Spiel Othello
 */

/**
* @mainpage Othello
*
* Dokumentation des Spiels Othello im Rahmen des Praktikums Informatik 1.
*
*/

#include <iostream>
#include <string>
#include "config.h"
#include "test.h"
#include "othelloKI.h"


/**
 * @brief Funktion zur ersten Initialisierung eines neuen Spielfelds
 *
 * Diese Funktion fuellt ein existierendes Spielfeld mit Nullen und erzeugt die Startaufstellung.
 *
 * @param spielfeld Spielfeld, das initialisiert wird
 */
 //建立初始化棋盘
void initialisiereSpielfeld(int spielfeld[GROESSE_Y][GROESSE_X])
{
    for (int j = 0; j < GROESSE_Y; j++)
        {
            for(int i = 0; i < GROESSE_X; i++)
            {
                spielfeld[j][i] = 0;                                //把整个棋盘清空，设成 0
            }
        }
        //放四个起始棋子,这里设置为8*8棋盘
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2 - 1] = 1;        //[3][3] = 1
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2 - 1] = 2;            //[4][3] = 2
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2] = 2;            //[3][4] = 2
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2] = 1;                //[4][4] = 1
}


/**
* @brief Ausgabe des Spielfelds auf der Konsole
*
* Ausgabe des aktuellen Spielfelds, 0 bedeutet leeres Feld, 1 ist Spieler 1 und 2 ist Spieler2
* Kreuze symbolisieren Spieler 1, waehrend Kreise Spieler 2 symbolisieren
*
*  @param spielfeld  Spielfeld, das ausgeben wird
*/
//辅助显示函数,把当前棋盘格式化输出到控制台
void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    //打印列标题A|B|C...
    std::cout << "   | ";

    //Start bei ASCII 65 = A                            
    for (int i = 65; i < 65 + GROESSE_X; ++i)
        std::cout << ((char) i) << " | " ; //强制转换类型为字符串

    std::cout << std::endl;

    //逐行输出棋盘
    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for(int i = 0; i < GROESSE_X; ++i)                  
        {
            std::cout << "---+";
        }
        std::cout << "---+" << std::endl;                   //输出分隔线
        std::cout << " " << j + 1 << " |";                  //输出行号


        for (int i = 0; i < GROESSE_X; ++i)
        {
            switch (spielfeld[j][i])
            {
                case 0:                                     //空格
                    std::cout << "   " ;
                    break;
                case 1:                                     //玩家1
                    std::cout << " X ";
                    break;
                case 2:                                     //玩家2
                    std::cout << " O ";
                    break;

                default:                                    //如果棋盘里出现了不是 0/1/2 的值，直接报错退
                    std::cout << "Unzulaessige Daten im Spielfeld!" << std::endl;
                    std::cout << "Abbruch .... " << std::endl;
                    exit(0);
                    break;
            }
            std::cout << "|";
        };  //for i

        std::cout <<  std::endl;

    }  //for j
}


/**
 * @brief Prueft, wer Gewinner ist
 *
 * Zaehlt alle Steine auf dem Feld
 *
 * @param spielfeld Aktuelles Spielfeld, fuer das der Gewinner ermittelt wird
 * @return winner
 */
//游戏结束后,统计棋盘上玩家 1 和玩家 2 的棋子数，返回赢家
int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    //初始化计数器
    int zaehlerSpieler1 = 0;
    int zaehlerSpieler2 = 0;

    //遍历棋盘,统计玩家 1 和玩家 2 的棋子数
    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for (int i = 0; i < GROESSE_X; ++i)
        {
            if (spielfeld[j][i] == 1)
            {
                ++zaehlerSpieler1;
            }
            if (spielfeld[j][i] == 2)
            {
                ++zaehlerSpieler2;
            }

        }
    }

    //判断赢家
    if (zaehlerSpieler1 == zaehlerSpieler2)
    {
        return 0;
    }
    if (zaehlerSpieler1 < zaehlerSpieler2)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}


/**
* @brief Ueberprueft fuer zwei Indizes, ob sie auf dem Spielfeld sind
*
* @param posX Index fuer die Spalte
* @param posY Index fuer die Zeile
* @return true, wenn Spalte und Zeile innerhalb des Spielfelds sind, sonst false
*/
//检查位置是否在棋盘范围内
bool aufSpielfeld(const int posX, const int posY)
{
    if (posX >= 0 && posX < GROESSE_X && posY >= 0 && posY < GROESSE_Y)
    {
        return true;
    }
    
    return false;
}


/**
 * @brief Ueberprueft fuer zwei Indizes, ob der Zug gueltig ist
 *
 *  Ueberprueft, ob auf einem benachbarten Feld ein gegnerischer Stein liegt.
 *  Wenn ja, wird diese Richtung solange untersucht, bis ein eigener Stein
 *  gefunden wird. Wird vorher der Spielfeldrand erreicht oder ein leeres Feld
 *  gefunden, wird false zurueckgegeben, sonst true
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Zu ueberpruefende Spalte
 * @param posY Zu ueberpruefende Zeile
 * @return
 */
//判断玩家aktuellerSpieler能否在位置 (posX, posY) 落子
bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    //计算对手
    int gegner = 3 - aktuellerSpieler;              // if aktuellerSpieler == 1 -> gegner = 2
                                                    //  if aktuellerSpieler == 2 -> gegner = 1
   
    //首先确保选择位置合法
    if (aufSpielfeld(posX, posY) == 0)
    {
        return false;
    }
    
    //检查位置是不是空的
    if (spielfeld[posY][posX] != 0) // ist das Feld leer?
    {
        return false;
    }

    // Alle Richtungen ueberpruefen bis erster gueltiger Zug gefunden
    //检查八个方向,上下左右 + 4 个斜角,找到紧邻对手棋子,且后面有自己棋子的位置,就返回 true
    //跳过(0,0)
    //判断1,是否紧邻对手棋子
    //判断2,是否后面有自己棋子
    for (int j = -1; j <= 1; j++)                       //check y
    {
        for (int i = -1; i <= 1; i++)                   //check x
        {
            if(i == 0 && j == 0)                        //跳过(0,0)
            {
                continue;                               //跳过这一次后续代码,进入下一个循环
            }

            //建立用来判断的临时变量,先判断对手棋子
            int posXTemp = posX + i;                    //检查位置的 x 坐标
            int posYTemp = posY + j;                    //检查位置的 y 坐标 

            //确保判断棋子合法
            if(aufSpielfeld(posXTemp,  posYTemp) == 0)
            {
                continue;
            }

            //pos八个方向里有对手棋子
            if(spielfeld[posYTemp][posXTemp] == gegner )
            {
                //迭代temp,继续往这个方向推进,以判断另一面是否有自方棋子
                posXTemp = posXTemp + i;
                posYTemp = posYTemp + j;
            }
            else{
                continue;
            }

            //确保新位置合法
            while(aufSpielfeld(posXTemp, posYTemp)){

                //新位置是自方棋子
                if(spielfeld[posYTemp][posXTemp] == aktuellerSpieler)
                {
                    return true;
                }

                //新位置是空格,位置不合法
                else if(spielfeld[posYTemp][posXTemp] == 0)
                {
                    break;                               //跳出循环
                }

                //新位置是对手棋子,继续迭代
                posXTemp = posXTemp + i;              
                posYTemp = posYTemp + j;
            }
        }
    }
    return false;
}


/**
 * @brief Funktion, die einen Zug ausfuehrt
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Die aktuelle Spalte
 * @param posY Die aktuelle Zeile
 */
//执行落子动作,把子放上去，并且把所有被夹住的对方棋子翻过来
void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    //same, 计算对手
    int gegner = 3 - aktuellerSpieler;

    //Alle Richtungen bearbeiten
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            // aehnlich wie die Funktion zugGueltig(), aber stellen Sie sicher, das alle gegnerischen Steine in
            // allen Richtungen in Ihre eigenen Steine umgewandelt werden

            if(i == 0 && j == 0)                        //跳过(0,0)
            {
                continue;                               //跳过这一次后续代码,进入下一个循环
            }

            //建立用来判断的临时变量,先判断对手棋子
            int posXTemp = posX + i;                    //检查位置的 x 坐标
            int posYTemp = posY + j;                    //检查位置的 y 坐标 

            //确保判断棋子合法
            if(aufSpielfeld(posXTemp,  posYTemp) == 0)
            {
                continue;
            }

             //pos八个方向里有对手棋子
            if(spielfeld[posYTemp][posXTemp] == gegner )
            {
                //迭代temp,继续往这个方向推进,以判断另一面是否有自方棋子
                posXTemp = posXTemp + i;
                posYTemp = posYTemp + j;
            }
            else{
                continue;
            }

             //确保新位置在棋盘上
            while(aufSpielfeld(posXTemp, posYTemp)){

                //1.新位置是自方棋子
                if(spielfeld[posYTemp][posXTemp] == aktuellerSpieler)
                {
                    //迭代temp到上一个对方棋子处
                    posXTemp = posXTemp - i;
                    posYTemp = posYTemp - j;

                    //但这里中间可能还有其他对方棋子,加一个while,一直往回走到(posy,posx)
                    while(posXTemp != posX || posYTemp != posY)
                    {
                        //翻转对方棋子
                        spielfeld[posYTemp][posXTemp] = aktuellerSpieler;

                        //继续迭代
                        posXTemp = posXTemp - i;
                        posYTemp = posYTemp - j;
                    }

                    break;

                }

                //2.新位置是空格,位置不合法
                else if(spielfeld[posYTemp][posXTemp] == 0)
                {
                    break;                               //跳出循环
                }

                //3.新位置是对手棋子,继续迭代
                posXTemp = posXTemp + i;              
                posYTemp = posYTemp + j;
            }
        }
    }

    //在 (posX, posY) 放下当前玩家的新棋子
    spielfeld[posY][posX] = aktuellerSpieler;

}


/**
 * @brief Zaehlt alle moeglichen Zuege eines Spielers.
 *
 * Die Funktion durchsucht das gesamte Spielfeld und prueft fuer jede Position,
 * ob dort ein gueltiger Zug fuer den aktuellen Spieler moeglich ist.
 * Fuer jede gueltige Position wird der Zaehler erhoeht.
 *
 * @param spielfeld Das aktuelle Spielfeld.
 * @param aktuellerSpieler Der Spieler, fuer den die moeglichen Zuege bestimmt werden.
 * @return Anzahl der moeglichen Zuege des Spielers.
 */
//统计某个玩家当前一共有多少个合法走子位置
//把 zugGueltig() 在整个棋盘上跑一遍，然后数一数 true 出现了几次
int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    //引入计数器
    int anzahlZuege = 0;

    //遍历棋盘,统计合法走子位置的数量
    for (int j = 0; j < GROESSE_Y; j++)
    {
        for (int i = 0; i < GROESSE_X; i++)
        {
            if (zugGueltig(spielfeld, aktuellerSpieler, i, j))
            {
                anzahlZuege++;
            }
        }
    }

    return anzahlZuege;

}


/**
 * @brief Ermöglicht einen menschlichen Zug.
 *
 * Die Funktion erlaubt es einem menschlichen Spieler, einen Zug auf dem Spielfeld durchzuführen.
 * Sie überprüft, ob der eingegebene Zug gültig ist, und führt ihn aus.
 *
 * @param spielfeld Das aktuelle Spielfeld.
 * @param aktuellerSpieler Der Spieler, der am Zug ist.
 * @return true, wenn der Zug erfolgreich ausgeführt wurde, sonst false.
 */
//让玩家输入一个合法的走子位置,并且执行这个走子
 bool menschlicherZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    //如果玩家没有合法走子位置了,直接返回 false
    if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
    {
        return false;
    }

    int posX;
    int posY;
    std::string symbolSpieler;

    //确定玩家的符号
    if (aktuellerSpieler == 1)
    {
        symbolSpieler = "X";
    }
    else
    {
        symbolSpieler = "O";
    }

    //让玩家输入一个合法的走子位置,并且执行这个走子
    while (true)
    {
        std::string eingabe;
        std::cout << std::endl << "Du bist " << symbolSpieler << ". Dein Zug (z.B. A1, a1): " ;
        std::cin >> eingabe;
        //把输入转换成坐标,比如 A1 -> (0,0), B1 -> (1,0), A2 -> (0,1) ...
        posX = (int) eingabe[0] % 32 -1;
        posY = (int) eingabe[1] - 49;

        //检查输入是否合法,如果合法就执行走子,否则提示玩家重新输入
        if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY))
        {
            //accept turn;
            break;
        }
        else
        {
            std::cout << std::endl << "Ungueltige Eingabe !" << std::endl;
        }
    }

    //执行走子
    zugAusfuehren(spielfeld, aktuellerSpieler, posX, posY);
    std::cout << std::endl << "Spieler " << aktuellerSpieler << " setzt auf " << (char) (posX + 65) << (posY + 1) << std::endl;

    return true;
}


/**
 * @brief Steuert den gesamten Spielablauf von Othello.
 *
 * Die Funktion initialisiert das Spielfeld und laesst die Spieler
 * abwechselnd ziehen. Wenn ein Spieler keinen moeglichen Zug hat,
 * muss er passen. Das Spiel endet, wenn beide Spieler keine moeglichen
 * Zuege mehr haben. Anschliessend wird der Gewinner ausgegeben.
 *
 * @param spielerTyp Feld mit den Typen der beiden Spieler.
 */
//进行游戏
 void spielen(const int spielerTyp[2])
{
    int spielfeld[GROESSE_Y][GROESSE_X];

    //Erzeuge Startaufstellung
    initialisiereSpielfeld(spielfeld);

    int aktuellerSpieler = 1;
    zeigeSpielfeld(spielfeld);

    // solange noch Zuege bei einem der beiden Spieler moeglich sind
    //如果玩家 1 或者玩家 2 还有合法走子位置,游戏继续
    while(moeglicheZuege(spielfeld, 1) != 0 || moeglicheZuege(spielfeld, 2) != 0)
    {
        if (moeglicheZuege(spielfeld, aktuellerSpieler) > 0)
        {
            //判断当前玩家是电脑还是人类(COMPUTER = 2, MENSCH = 1)
            if (spielerTyp[aktuellerSpieler - 1] == MENSCH)           //玩家 1 → 下标 0, 玩家 2 → 下标 1
            {
                 menschlicherZug(spielfeld, aktuellerSpieler);
            }
            else
            {
                computerZug(spielfeld, aktuellerSpieler);
            }

        //显示当前棋盘
        zeigeSpielfeld(spielfeld);
        }

        else
        {
        //如果当前玩家没有合法走子位置了,提示玩家过
        std::cout << "Spieler " << aktuellerSpieler << " muss passen." << std::endl;
        }

        //切换玩家
        aktuellerSpieler = 3 - aktuellerSpieler;
    }
    
    switch (gewinner(spielfeld))
    {
        case 0:
            std::cout << "Es ist ein Unentschieden." << std::endl;
            break;

        case 1:
            std::cout << "Spieler 1 gewinnt !" << std::endl;
            break;

        case 2:
            std::cout << "Spieler 2 gewinnt !" << std::endl;
            break;

        default:
            std::cout << "Fehler" << std::endl;
            break;
    }
}

int main()
{
    if (TEST == 1)
    {
        //进行总测试,记录测试结果
        bool gesamtErgebnis = ganzenTestAusfuehren();
        if (gesamtErgebnis == true)
        {
            std::cout << "ALLE TESTS BESTANDEN!" << std::endl;
        }
        else
        {
            std::cout << "MINDESTENS EIN TEST IST FEHLGESCHLAGEN!" << std::endl;
            exit(1);
        }
        std::cout << std::endl << std::endl;
    }
    
    // Die folgenden drei Zeilen werden auskommentiert oder geloescht, nachdem Sie die Funktion spielen()
    // implementiert haben (waeren sonst doppelt)
    //int spielfeld[GROESSE_Y][GROESSE_X];
    //initialisiereSpielfeld(spielfeld);
    //zeigeSpielfeld(spielfeld);

    //int spielerTyp[2] = { MENSCH, COMPUTER };  // Feld, das Informationen ueber den Typ des Spielers enthaelt. MENSCH(=1) oder COPMUTER(=2)
    int spielerTyp[2] = {COMPUTER, COMPUTER };
    //int spielerTyp[2] = {MENSCH, MENSCH };

    spielen(spielerTyp);

    return 0;
}
