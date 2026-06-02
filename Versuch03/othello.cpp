/** @mainpage
 *
 * Praktikum Informatik 1 MMXXVI <BR>
 * Versuch 3: Komplexere Projekte und Dokumentation
 * <BR>
 * Othello, Tests und Doxygen-Dokumentation
 *
 */

/**
 * Praktikum Informatik 1
 *
 * @file othello.cpp
 *
 * Die Funktionen fuer das Spiel Othello
 */

/**
 * @page othello Othello
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
 * @brief Initialisiert ein Spielfeld fuer ein neues Othello-Spiel.
 *
 * Die Funktion fuellt ein existierendes Spielfeld mit Nullen und erzeugt
 * anschliessend die Startaufstellung.
 *
 * @param spielfeld Spielfeld, das initialisiert wird
 */
// 初始化棋盘并放置开局四个棋子
void initialisiereSpielfeld(int spielfeld[GROESSE_Y][GROESSE_X])
{
    // Setzt zunaechst alle Felder des Spielfelds auf leer.
    for (int j = 0; j < GROESSE_Y; j++)
    {
        for (int i = 0; i < GROESSE_X; i++)
        {
            spielfeld[j][i] = 0;                                // 先把所有格子清空为 0
        }
    }

    // 在棋盘中心放置 Othello 的初始四子
    // Setzt anschliessend die vier Startsteine in die Mitte des Spielfelds.
    spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2 - 1] = 1;        //[3][3] = 1
    spielfeld[GROESSE_Y / 2][GROESSE_X / 2 - 1] = 2;            //[4][3] = 2
    spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2] = 2;            //[3][4] = 2
    spielfeld[GROESSE_Y / 2][GROESSE_X / 2] = 1;                //[4][4] = 1
}

/**
 * @brief Gibt das aktuelle Spielfeld auf der Konsole aus.
 *
 * Der Wert 0 kennzeichnet ein leeres Feld, 1 steht fuer Spieler 1 und
 * 2 fuer Spieler 2. Kreuze symbolisieren Spieler 1, Kreise Spieler 2.
 *
 * @param spielfeld Spielfeld, das ausgegeben wird
 */
// 在控制台中按网格形式输出当前棋盘
void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    // 先输出列标 A|B|C...
    // Gibt zunaechst die Spaltenbezeichnungen aus.
    std::cout << "   | ";

    // Start bei ASCII 65 = A
    for (int i = 65; i < 65 + GROESSE_X; ++i)
    {
        std::cout << ((char) i) << " | "; // 将 ASCII 字母转换为列名
    }

    std::cout << std::endl;

    // 逐行输出棋盘内容
    // Gibt anschliessend jede Zeile des Spielfelds aus.
    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for (int i = 0; i < GROESSE_X; ++i)
        {
            std::cout << "---+";
        }
        std::cout << "---+" << std::endl;                   // 输出分隔线
        std::cout << " " << j + 1 << " |";                  // 输出当前行号

        for (int i = 0; i < GROESSE_X; ++i)
        {
            switch (spielfeld[j][i])
            {
                case 0:                                     // 空格
                    std::cout << "   ";
                    break;
                case 1:                                     // 玩家 1
                    std::cout << " X ";
                    break;
                case 2:                                     // 玩家 2
                    std::cout << " O ";
                    break;

                default:                                    // 若棋盘中出现不是 0/1/2 的值，则直接报错退出
                    std::cout << "Unzulaessige Daten im Spielfeld!" << std::endl;
                    std::cout << "Abbruch .... " << std::endl;
                    exit(0);
                    break;
            }
            std::cout << "|";
        }

        std::cout << std::endl;
    }
}

/**
 * @brief Ermittelt den Gewinner des aktuellen Spielfelds.
 *
 * Dazu werden alle Steine beider Spieler auf dem Spielfeld gezaehlt.
 *
 * @param spielfeld Aktuelles Spielfeld
 * @return 0 bei Unentschieden, 1 bei Sieg von Spieler 1, sonst 2
 */
// 统计双方棋子数量并判断获胜者
int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    // 记录双方棋子数
    int zaehlerSpieler1 = 0;
    int zaehlerSpieler2 = 0;

    // 遍历棋盘，分别统计玩家 1 和玩家 2 的棋子数
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

    // 返回获胜者
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
 * @brief Prueft, ob eine Position innerhalb des Spielfelds liegt.
 *
 * @param posX Index der Spalte
 * @param posY Index der Zeile
 * @return true, wenn die Position innerhalb des Spielfelds liegt, sonst false
 */
// 判断一个坐标是否位于棋盘内部
bool aufSpielfeld(const int posX, const int posY)
{
    // Akzeptiert nur Koordinaten innerhalb der festen Spielfeldgroesse.
    if (posX >= 0 && posX < GROESSE_X && posY >= 0 && posY < GROESSE_Y)
    {
        return true;
    }

    return false;
}

/**
 * @brief Prueft, ob ein Zug an einer gegebenen Position gueltig ist.
 *
 * Dazu wird untersucht, ob von der Zielposition aus in mindestens einer
 * Richtung gegnerische Steine von einem eigenen Stein eingeschlossen werden.
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Zu pruefende Spalte
 * @param posY Zu pruefende Zeile
 * @return true, wenn der Zug gueltig ist, sonst false
 */
// 判断当前玩家在指定位置落子是否合法
// Ein Zug ist nur dann gueltig, wenn er mindestens einen gegnerischen Stein einschliesst. 
bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    // 对手编号
    // Berechnet die Spielernummer des Gegners.
    int gegner = 3 - aktuellerSpieler;

    // 坐标越界则不合法
    // Positionen ausserhalb des Spielfelds sind ungueltig.
    if (aufSpielfeld(posX, posY) == 0)
    {
        return false;
    }

    // 目标位置必须为空
    // Es darf nur auf ein freies Feld gesetzt werden.
    if (spielfeld[posY][posX] != 0)
    {
        return false;
    }

    // 检查 8 个方向，只要有一个方向满足夹住对手棋子，就说明这是合法落子
    // Untersucht alle acht Richtungen auf einschliessbare Gegnersteine.
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            if (i == 0 && j == 0)                        // 跳过方向 (0, 0)
            {
                continue;                                // 原地不算一个搜索方向
            }

            // 先走到当前方向上的第一个相邻格
            int posXTemp = posX + i;                     // 临时 x 坐标
            int posYTemp = posY + j;                     // 临时 y 坐标

            // 相邻格越界则换下一个方向
            if (aufSpielfeld(posXTemp, posYTemp) == 0)
            {
                continue;
            }

            // 相邻格必须先是对手棋子
            if (spielfeld[posYTemp][posXTemp] == gegner)
            {
                // 再向前走一步，继续检查后续格子
                posXTemp = posXTemp + i;
                posYTemp = posYTemp + j;
            }
            else
            {
                continue;
            }

            // 沿当前方向持续搜索
            while (aufSpielfeld(posXTemp, posYTemp))
            {
                // 遇到自己的棋子，说明形成夹击
                if (spielfeld[posYTemp][posXTemp] == aktuellerSpieler)
                {
                    return true;
                }

                // 遇到空格，说明这个方向不成立
                else if (spielfeld[posYTemp][posXTemp] == 0)
                {
                    break;                                // 当前方向搜索结束
                }

                // 继续沿当前方向前进
                posXTemp = posXTemp + i;
                posYTemp = posYTemp + j;
            }
        }
    }
    return false;
}

/**
 * @brief Fuehrt einen gueltigen Zug auf dem Spielfeld aus.
 *
 * Dabei wird der neue Stein gesetzt und alle eingeschlossenen gegnerischen
 * Steine werden umgedreht.
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Spalte des Zugs
 * @param posY Zeile des Zugs
 */
// 在棋盘上执行一个合法落子，并翻转所有被夹住的对手棋子
void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    //copy from zugGueltig
    // 对手编号
    int gegner = 3 - aktuellerSpieler;

    // Alle Richtungen bearbeiten
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            // aehnlich wie die Funktion zugGueltig(), aber stellen Sie sicher, das alle gegnerischen Steine in
            // allen Richtungen in Ihre eigenen Steine umgewandelt werden

            if (i == 0 && j == 0)                        // 跳过方向 (0, 0)
            {
                continue;                                // 原地不算方向
            }

            // 先走到当前方向上的第一个相邻格
            int posXTemp = posX + i;                     // 临时 x 坐标
            int posYTemp = posY + j;                     // 临时 y 坐标

            // 相邻格越界则换下一个方向
            if (aufSpielfeld(posXTemp, posYTemp) == 0)
            {
                continue;
            }

            // 相邻格必须先是对手棋子
            if (spielfeld[posYTemp][posXTemp] == gegner)
            {
                // 再向前走一步，继续检查后续格子
                posXTemp = posXTemp + i;
                posYTemp = posYTemp + j;
            }
            else
            {
                continue;
            }

            // 沿当前方向持续搜索
            while (aufSpielfeld(posXTemp, posYTemp))
            {
                // 1. 遇到自己的棋子，说明这一段可以回头翻转
                if (spielfeld[posYTemp][posXTemp] == aktuellerSpieler)
                {
                    // 回退一步，准备把夹住的对手棋子逐个翻转
                    posXTemp = posXTemp - i;
                    posYTemp = posYTemp - j;

                    // 一直回退到原落子点前，把路径上的对手棋子都改成当前玩家
                    while (posXTemp != posX || posYTemp != posY)
                    {
                        // 翻转棋子
                        spielfeld[posYTemp][posXTemp] = aktuellerSpieler;

                        // 继续回退
                        posXTemp = posXTemp - i;
                        posYTemp = posYTemp - j;
                    }

                    break;
                }

                // 2. 遇到空格，说明这个方向不成立
                else if (spielfeld[posYTemp][posXTemp] == 0)
                {
                    break;                                // 当前方向搜索结束
                }

                // 3. 仍然是对手棋子，继续沿当前方向前进
                posXTemp = posXTemp + i;
                posYTemp = posYTemp + j;
            }
        }
    }

    // 最后在落子位置放上当前玩家的棋子
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
// 统计当前玩家在整个棋盘上所有合法落子的位置数量
int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    // 统计合法走法数量
    // Zaehlt alle gueltigen Zugpositionen des aktuellen Spielers.
    int anzahlZuege = 0;

    // 遍历整个棋盘，检查每一个位置
    // Durchlaeuft das gesamte Spielfeld und prueft jede Position.
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
 * @brief Ermoeglicht einen menschlichen Zug.
 *
 * Die Funktion erlaubt es einem menschlichen Spieler, einen Zug auf dem Spielfeld durchzufuehren.
 * Sie ueberprueft, ob der eingegebene Zug gueltig ist, und fuehrt ihn aus.
 *
 * @param spielfeld Das aktuelle Spielfeld.
 * @param aktuellerSpieler Der Spieler, der am Zug ist.
 * @return true, wenn der Zug erfolgreich ausgefuehrt wurde, sonst false.
 */

// 处理人类玩家输入，并在输入合法时执行该步
bool menschlicherZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    // 如果当前玩家没有合法走法，就直接返回 false
    // Ohne moegliche Zuege kann der Spieler nichts setzen.
    if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
    {
        return false;
    }

    int posX;
    int posY;
    std::string symbolSpieler;

    // 根据玩家编号设置显示符号
    // Bestimmt das Ausgabesymbol des aktuellen Spielers.
    if (aktuellerSpieler == 1)
    {
        symbolSpieler = "X";
    }
    else
    {
        symbolSpieler = "O";
    }

    // 持续读取输入，直到用户输入一个合法落子
    // Fragt so lange nach einer Eingabe, bis ein gueltiger Zug vorliegt.
    while (true)
    {
        std::string eingabe;
        std::cout << std::endl << "Du bist " << symbolSpieler << ". Dein Zug (z.B. A1, a1): ";
        std::cin >> eingabe;

        // 把类似 A1 的输入转换成数组坐标，例如 A1 -> (0,0)
        // Wandelt die Benutzereingabe von z. B. A1 in Feldkoordinaten um.
        posX = (int) eingabe[0] % 32 - 1;
        posY = (int) eingabe[1] - 49;

        // 如果输入对应的是合法落子，就跳出循环，否则提示重新输入
        // Bei einem gueltigen Zug endet die Eingabeschleife.
        if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY))
        {
            break;
        }
        else
        {
            std::cout << std::endl << "Ungueltige Eingabe !" << std::endl;
        }
    }

    // 执行该步落子
    // Fuehrt den geprueften Zug auf dem Spielfeld aus.
    zugAusfuehren(spielfeld, aktuellerSpieler, posX, posY);
    std::cout << std::endl << "Spieler " << aktuellerSpieler << " setzt auf " << (char) (posX + 65) << (posY + 1) << std::endl;

    return true;
}

/**
 * @brief Steuert den gesamten Spielablauf von Othello.
 *
 * Die Funktion initialisiert das Spielfeld, laesst die Spieler abwechselnd
 * ziehen und beendet das Spiel, sobald beide Spieler keine moeglichen Zuege
 * mehr besitzen.
 *
 * @param spielerTyp Feld mit den Typen der beiden Spieler
 */
// 控制整局 Othello 游戏流程
void spielen(const int spielerTyp[2])
{
    int spielfeld[GROESSE_Y][GROESSE_X];

    // Erzeuge Startaufstellung
    initialisiereSpielfeld(spielfeld);

    int aktuellerSpieler = 1;
    zeigeSpielfeld(spielfeld);

    //增加计数器,记录现在执行的轮数
    // Zaehlt die gespielten Runden im laufenden Spiel.
    int runden = 0;

    // solange noch Zuege bei einem der beiden Spieler moeglich sind
    // 只要任意一方还有合法走法，游戏就继续
    while (moeglicheZuege(spielfeld, 1) != 0 || moeglicheZuege(spielfeld, 2) != 0)
    {
        //即使一方不能走了, 记录另一方行动的回合
        runden++;

        if (moeglicheZuege(spielfeld, aktuellerSpieler) > 0)
        {
            // 根据玩家类型决定是人类下棋还是电脑下棋（COMPUTER = 2, MENSCH = 1）
            if (spielerTyp[aktuellerSpieler - 1] == MENSCH)           // 玩家 1 对应下标 0，玩家 2 对应下标 1
            {
                menschlicherZug(spielfeld, aktuellerSpieler);
            }
            else
            {
                computerZug(spielfeld, aktuellerSpieler);
            }

            // 每一步后都重新显示棋盘
            std::cout << "Runden : " << runden << std::endl;
            // Gibt nach jedem erfolgreichen Zug die Rundenzahl und das Feld aus.
            zeigeSpielfeld(spielfeld);
        }
        else
        {
            // 当前玩家没有合法走法，需要跳过本回合
            // Spieler ohne moeglichen Zug muessen in dieser Runde passen.
            std::cout << "Spieler " << aktuellerSpieler << " muss passen." << std::endl;
        }

        // 切换到另一位玩家
        // Wechselt anschliessend zum anderen Spieler.
        aktuellerSpieler = 3 - aktuellerSpieler;
    }

    switch (gewinner(spielfeld))
    {
                // Leeres Feld
                case 0:
            std::cout << "Es ist ein Unentschieden." << std::endl;
            break;

                // Stein von Spieler 1
                case 1:
            std::cout << "Spieler 1 gewinnt !" << std::endl;
            break;

                // Stein von Spieler 2
                case 2:
            std::cout << "Spieler 2 gewinnt !" << std::endl;
            break;

                // Sicherheitsabbruch bei unzulaessigen Feldwerten
                default:
            std::cout << "Fehler" << std::endl;
            break;
    }

}

/**
 * @brief Startet optional die Tests und anschliessend das Othello-Spiel.
 *
 * @return 0 bei erfolgreicher Programmausfuehrung
 */
int main()
{
    if (TEST == 1)
    {
        // 先运行完整测试，确保核心逻辑正确
        // Startet vor dem Spiel alle automatisierten Tests.
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
    //int spielerTyp[2] = {COMPUTER, COMPUTER };
    //int spielerTyp[2] = {MENSCH, MENSCH };

//三种对局情况,执行判断
    // Liest fuer beide Spieler ein, ob Mensch oder Computer verwendet werden soll.
    int spielerTyp[2];
    char eingabe = ' ';

    //spieler 1
    // Konfiguriert den Typ von Spieler 1.
    std::cout << "Ist Spieler 1 ein Computer? (j/n) ";
    std::cin >> eingabe;

    if (eingabe == 'j' || eingabe == 'J')
    {
        spielerTyp[0] = COMPUTER;
    }
    else
    {
        spielerTyp[0] = MENSCH;
    }

    //spieler 2
    std::cout << std::endl;
    // Konfiguriert den Typ von Spieler 2.
    std::cout << "Ist Spieler 2 ein Computer? (j/n) ";
    std::cin >> eingabe;

    if (eingabe == 'j' || eingabe == 'J')
    {
        spielerTyp[1] = COMPUTER;
    }
    else
    {
        spielerTyp[1] = MENSCH;
    }

    std::cout << std::endl;
    std::cout << "Startfeld" << std::endl;

    // 最后调用 spielen() 函数，开始游戏
    // Startet das eigentliche Spiel mit den gewaehlten Spielertypen.
    spielen(spielerTyp);

    

    //判断是否需要重新开始游戏
    // Fragt nach Spielende, ob eine neue Partie gestartet werden soll.
    char neuesSpieleingabe = ' ';

    std::cout << std::endl;
    std::cout << "Neues Spiel? (j/n) "<< std::endl;
    std::cin >> neuesSpieleingabe;

    if (neuesSpieleingabe == 'j' || neuesSpieleingabe == 'J')
    {
        std::cout << std::endl;
        std::cout << "Startfeld" << std::endl;
        spielen(spielerTyp);
    }
    else
    {
        std::cout << "game stops!" << std::endl;
    }

    return 0;
}
