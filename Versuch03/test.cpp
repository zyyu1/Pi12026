/**
 * Praktikum Informatik 1 MMXXVI
 *
 * @file test.cpp
 *
 * Stellt Funktionen zum Testen der Spielfunktionen zur Verfuegung
 */


#include <iostream>
#include "config.h"
#include "test.h"


/*
 * Deklaration der in den Tests verwendeten Funktionen.
 * Dadurch weiss der Compiler, das es sich bei den Namen
 * um Funktionsaufrufe handelt, die in einer anderen Datei
 * definiert sind (extern).
 */
extern void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X]);
extern int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X]);
extern bool aufSpielfeld(const int posX, const int posY);
extern bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X],  const int player, const int posX, const int posY);
extern void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X], const int player, const int posX, const int posY);
extern int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int player);


/**
 * @brief Funktion zum Testen der gewinner() Funktion.
 *
 * @param eingabefeld Das zu testende Spielfeld.
 * @param richtig Der erwartete Gewinner.
 * @param testNummer Nummer des laufenden Tests
 * @return true, wenn der berechnete Gewinner dem erwarteten Gewinner entspricht, sonst false
 */
bool gewinnerTest(const int eingabefeld[GROESSE_Y][GROESSE_X], const int richtig, const int testNummer)
{
    // Startet einen einzelnen Testfall fuer die Gewinnerbestimmung.
    std::cout << "Fuehre Test " << testNummer + 1 << " fuer 'gewinner()' aus ..." << std::endl;
    std::cout << "----------------------------------" << std::endl << std::endl;

    int ergebnis = gewinner(eingabefeld);

    if (ergebnis == richtig)
    {
        std::cout << "Test " << testNummer + 1 << " bestanden!" << std::endl << std::endl;
        return true;
    }
    else
    {
        std::cout << "Test " << testNummer + 1 << " fehlgeschlagen" << std::endl << std::endl;
        
        if (AUSFUEHRLICH == 1)
        {
            // Gibt bei Bedarf das Testspielfeld fuer die Fehlersuche aus.
            // 输出失败时的测试棋盘，便于定位问题
            zeigeSpielfeld(eingabefeld);

            std::cout << std::endl << "Berechnetes Ergebnis: " << ergebnis << std::endl << "Richtiges Ergebnis: " << richtig
                      << std::endl << std::endl;
        }
        return false;
    }
}


/**
 * @brief Funktion zum Testen der aufSpielfeld() Funktion
 *
 * @param posX Index Spalte
 * @param posY Index Zeile
 * @param richtig Das erwartete Ergebnis
 * @param testNummer Nummer des laufenden Tests
 * @return true, wenn der Test bestanden wurde, sonst false
 */
bool aufSpielfeldTest(const int posX, const int posY, const bool richtig, const int testNummer)
{
    // ueberprueft, ob eine gegebene Position auf dem Spielfeld ist

    // Gibt eine kurze Ueberschrift fuer den aktuellen Test aus.
    // 在控制台输出当前测试标题
    std::cout << "Fuehre Test " << testNummer + 1 << " fuer 'aufSpielfeld()' aus ..." << std::endl;
    std::cout << "----------------------------------" << std::endl << std::endl;

    // Ruft die zu testende Funktion auf und speichert das Ergebnis.
    // 调用 aufSpielfeld() 并保存结果
    bool ergebnis = aufSpielfeld(posX, posY);

    // Vergleicht Ist- und Sollwert des Testfalls.
    // 将实际结果与期望结果进行比较
    if (ergebnis == richtig)
    {
        std::cout << "Test " << testNummer + 1 << " bestanden!" << std::endl << std::endl;
        return true;
    }
    else
    {
        std::cout << "Test " << testNummer + 1 << " fehlgeschlagen" << std::endl << std::endl;

        // Im ausfuehrlichen Modus werden zusaetzliche Informationen angezeigt.
        // 在详细模式下输出更多调试信息
        if (AUSFUEHRLICH == 1)
        {
            // Gibt die gepruefte Position zur besseren Analyse aus.
            // 输出被测试的位置
            std::cout << "Position: (" << posX << ", " << posY << ")" << std::endl;
            std::cout << "Berechnetes Ergebnis: " << ergebnis << std::endl;
            std::cout << "Richtiges Ergebnis: " << richtig << std::endl << std::endl;
        }
        return false;
    }
}


/**
 * @brief Funktion zum Testen der zugGueltig() Funktion
 *
 * @param eingabeFeld Das zu testende Spielfeld
 * @param spieler Der Spieler, fuer den der Zug getestet wird
 * @param posX Index Spalte
 * @param posY Index Zeile
 * @param richtig Das erwartete Ergebnis
 * @param testNummer Nummer des laufenden Tests
 * @return true, wenn der Test bestanden wurde, sonst false
 */
bool zugGueltigTest(const int eingabeFeld[GROESSE_Y][GROESSE_X], const int spieler, const int posX,
                     const int posY, const bool richtig, const int testNummer)
{
    // Prueft einen einzelnen Testfall fuer die Gueltigkeit eines Zugs.

    std::cout << "Fuehre Test " << testNummer + 1 << " fuer 'zugGueltig()' aus ..." << std::endl;
    std::cout << "----------------------------------" << std::endl << std::endl;

    bool ergebnis = zugGueltig(eingabeFeld, spieler, posX, posY);

    if (ergebnis == richtig)
    {
        std::cout << "Test " << testNummer + 1 << " bestanden!" << std::endl << std::endl;
        return true;
    }
    else
    {
        std::cout << "Test " << testNummer + 1 << " fehlgeschlagen" << std::endl << std::endl;

        if (AUSFUEHRLICH == 1)
        {
            // Zeigt das verwendete Spielfeld an, damit Fehler leichter nachvollziehbar sind.
            // 输出当前测试棋盘
            zeigeSpielfeld(eingabeFeld);

            std::cout << "Spieler: " << spieler << std::endl;
            std::cout << "Position: (" << posX << ", " << posY << ")" << std::endl;
            std::cout << "Berechnetes Ergebnis: " << ergebnis << std::endl;
            std::cout << "Richtiges Ergebnis: " << richtig << std::endl << std::endl;
        }
        return false;
    }
}


/**
 * @brief Funktion zum Testen der zugAusfuehren() Funktion
 *
 * @param eingabeFeld Das zu testende Spielfeld
 * @param ergebnisFeld Das korrekte Ergebnis nach Ausfuehren des Zugs
 * @param spieler Der Spieler, fuer den der Zug ausgefuehrt wird
 * @param posX Index Spalte
 * @param posY Index Zeile
 * @param testNummer Nummer des laufenden Tests
 * @return true, wenn der Test bestanden wurde, sonst false
 */
bool zugAusfuehrenTest(int eingabeFeld[GROESSE_Y][GROESSE_X], const int ergebnisFeld[GROESSE_Y][GROESSE_X],
                       const int spieler, const int posX, const int posY, const int testNummer)
{
    // Vergleicht das berechnete Spielfeld mit dem erwarteten Sollzustand.

    // Gibt eine Ueberschrift fuer den aktuellen Testfall aus.
    // 在控制台输出当前测试标题
    std::cout << "Fuehre Test " << testNummer + 1 << " fuer 'zugAusfuehren()' aus ..." << std::endl;
    std::cout << "----------------------------------" << std::endl << std::endl;

    // Legt eine Kopie des Eingabefelds an, damit die Originaldaten unveraendert bleiben.
    // 复制输入棋盘，避免直接修改原始测试数据
    int testFeld[GROESSE_Y][GROESSE_X];

    for (int y = 0; y < GROESSE_Y; y++)
    {
        for (int x = 0; x < GROESSE_X; x++)
        {
            testFeld[y][x] = eingabeFeld[y][x];
        }
    }

    // Fuehrt den zu pruefenden Zug auf der Testkopie aus.
    // 执行落子函数
    zugAusfuehren(testFeld, spieler, posX, posY);

    // Vergleicht Feld fuer Feld mit dem erwarteten Ergebnis.
    // 逐格比较计算结果与期望棋盘是否一致
    bool ergebnis = true;

    for (int y = 0; y < GROESSE_Y; y++)
    {
        for (int x = 0; x < GROESSE_X; x++)
        {
            if (testFeld[y][x] != ergebnisFeld[y][x])
            {
                ergebnis = false;
            }
        }
    }

    // Gibt je nach Vergleichsergebnis den Teststatus aus.
    // 根据比较结果输出测试状态
    if (ergebnis == true)
    {
        std::cout << "Test " << testNummer + 1 << " bestanden!" << std::endl << std::endl;
        return true;
    }
    else
    {
        std::cout << "Test " << testNummer + 1 << " fehlgeschlagen" << std::endl << std::endl;

        // Im ausfuehrlichen Modus werden Eingabe, Ergebnis und Sollfeld angezeigt.
        // 在详细模式下输出输入棋盘、计算结果和正确结果
        if (AUSFUEHRLICH == 1)
        {
            std::cout << "Eingabefeld:" << std::endl;
            zeigeSpielfeld(eingabeFeld);

            std::cout << "Berechnetes Feld:" << std::endl;
            zeigeSpielfeld(testFeld);

            std::cout << "Korrektes Feld:" << std::endl;
            zeigeSpielfeld(ergebnisFeld);

            std::cout << "Spieler: " << spieler << std::endl;
            std::cout << "Position: (" << posX << ", " << posY << ")" << std::endl << std::endl;
        }

        return false;
    }
}


/**
 * @brief Funktion zum Testen der moeglicheZuege() Funktion
 *
 * @param eingabeFeld Das zu testende Spielfeld
 * @param spieler Der Spieler, fuer den die moeglichen Zuege gezaehlt werden
 * @param richtig Das erwartete Ergebnis
 * @param testNummer Nummer des laufenden Tests
 * @return true, wenn der Test bestanden wurde, sonst false
 */
bool moeglicheZuegeTest(const int eingabeFeld[GROESSE_Y][GROESSE_X], const int spieler,
                         const int richtig, const int testNummer)
{
    // Prueft die Anzahl der moeglichen Zuege fuer einen Spieler.
    std::cout << "Fuehre Test " << testNummer + 1 << " fuer 'moeglicheZuege()' aus ..." << std::endl;
    std::cout << "----------------------------------" << std::endl << std::endl;

    int ergebnis = moeglicheZuege(eingabeFeld, spieler);

    if(ergebnis == richtig)
    {
        std::cout << "Test " << testNummer + 1 << " bestanden!" << std::endl << std::endl;
        return true;
    }
    else
    {
        std::cout << "Test " << testNummer + 1 << " fehlgeschlagen" << std::endl << std::endl;

        if (AUSFUEHRLICH == 1)
        {
            // Zeigt das aktuelle Testspielfeld im Fehlerfall an.
            // 输出当前测试棋盘
            zeigeSpielfeld(eingabeFeld);

            // Zeigt Spieler, Istwert und Sollwert zur Kontrolle an.
            // 输出玩家编号、计算结果和正确结果
            std::cout << "Spieler: " << spieler << std::endl;
            std::cout << "Berechnetes Ergebnis: " << ergebnis << std::endl;
            std::cout << "Richtiges Ergebnis: " << richtig << std::endl << std::endl;
        }
        return false;
    }
}

/**
 * @brief Fuehrt alle automatisierten Tests aus.
 *
 * @return true, wenn alle Tests bestanden wurden, sonst false
 */
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

// 运行全部测试
bool ganzenTestAusfuehren()
{
    // Sammelt die Ergebnisse aller Testgruppen in einer gemeinsamen Rueckgabe.
    bool gesamtErgebnis = true;

    // Jede Testgruppe liegt in einem eigenen Block, damit lokale Namen getrennt bleiben.

    // Testgruppe fuer die Funktion gewinner().
    {
        int eingabeFeld[3][8][8] = {
            {   {1, 2, 1, 2, 1, 2, 1, 2},
                {1, 2, 1, 2, 1, 2, 1, 2},
                {1, 2, 1, 2, 1, 2, 1, 2},
                {1, 2, 1, 2, 1, 2, 1, 2},
                {1, 2, 1, 2, 1, 2, 1, 2},
                {1, 2, 1, 2, 1, 2, 1, 2},
                {1, 2, 1, 2, 1, 2, 1, 2},
                {1, 2, 1, 2, 1, 2, 1, 2}
            },

            {   {1, 1, 2, 1, 1, 2, 1, 1},
                {2, 1, 1, 2, 1, 1, 2, 1},
                {1, 2, 1, 1, 2, 1, 1, 2},
                {1, 1, 2, 1, 1, 2, 1, 1},
                {2, 1, 1, 2, 1, 1, 2, 1},
                {1, 2, 1, 1, 2, 1, 1, 2},
                {1, 1, 2, 1, 1, 2, 1, 1},
                {2, 1, 1, 2, 1, 1, 2, 1}
            },

            {   {1, 2, 2, 1, 2, 2, 1, 2},
                {2, 1, 2, 2, 1, 2, 2, 1},
                {2, 2, 1, 2, 2, 1, 2, 2},
                {1, 2, 2, 1, 2, 2, 1, 2},
                {2, 1, 2, 2, 1, 2, 2, 1},
                {2, 2, 1, 2, 2, 1, 2, 2},
                {1, 2, 2, 1, 2, 2, 1, 2},
                {2, 1, 2, 2, 1, 2, 2, 1}
            }
        };

        int korrektesErgebnis[3] = {0, 1, 2};

        for (int i = 0; i < 3; i++)
        {
            // Verknuepft das Ergebnis des Einzeltests mit dem Gesamtergebnis.
            bool tmp_ergebnis = gewinnerTest(eingabeFeld[i], korrektesErgebnis[i], i);
            if (gesamtErgebnis == true && tmp_ergebnis == false)
            {
                gesamtErgebnis = false;
            }
        }

        std::cout << "Ende des Tests fuer 'gewinner()'" << std::endl << std::endl;
    }


// Testgruppe fuer die Funktion aufSpielfeld()
// 测试 aufSpielfeld()
// ---------- TESTE POSITION IM FELD---------- //
    {
        int position[6][2] = { {2, 3}, {0, 8}, {-1, 7}, {2, -1}, {8, 5}, {-1,8} };   // posX, posY
        bool korrektesErgebnis[6] = {true, false, false, false, false, false};

        for (int i = 0; i < 6; i++)
        {
            // Aktualisiert das Gesamtergebnis anhand des Einzeltests.
            // 执行单个测试并合并总结果
            bool tmp_ergebnis = aufSpielfeldTest(position[i][0], position[i][1], korrektesErgebnis[i], i);

            if (gesamtErgebnis == true && tmp_ergebnis == false)
            {
                gesamtErgebnis = false;
            }
        }

        std::cout << "Ende des Tests fuer 'aufSpielfeld()'" << std::endl << std::endl;
    }

// Testgruppe fuer die Funktion zugGueltig()
// 测试 zugGueltig()
// ---------- TESTE ZUG GUELTIG ---------- //
    {
        int eingabeFeld[7][8][8] = {
                {   {1, 0, 2, 0, 0, 1, 1, 1},
                    {0, 0, 2, 0, 0, 0, 0, 1},
                    {0, 0, 0, 0, 0, 1, 2, 2},
                    {2, 2, 0, 2, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 2, 2, 0},
                    {0, 0, 0, 2, 1, 1, 0, 2},
                    {1, 0, 0, 1, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 1, 0, 1}
                },

                {   {1, 0, 2, 0, 0, 1, 1, 1},
                    {0, 0, 2, 0, 0, 1, 0, 0},
                    {0, 0, 2, 0, 0, 2, 1, 1},
                    {0, 0, 0, 2, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 2, 2, 0},
                    {0, 0, 0, 2, 1, 1, 0, 2},
                    {1, 0, 0, 1, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 1, 0, 1}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 1, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 2, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 1, 0, 0, 2, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 1, 0},
                    {2, 0, 1, 2, 0, 2, 0, 0},
                    {0, 2, 0, 2, 2, 2, 2, 2},
                    {0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 2, 2, 2},
                    {0, 2, 0, 0, 0, 0, 0, 0},
                    {0, 1, 0, 1, 1, 1, 0, 0}
                },

                {   {2, 1, 0, 0, 2, 1, 1, 1},
                    {0, 2, 0, 0, 0, 0, 0, 0},
                    {1, 0, 0, 2, 0, 0, 0, 1},
                    {0, 1, 1, 1, 0, 1, 0, 0},
                    {1, 0, 0, 1, 1, 0, 0, 2},
                    {0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 1, 0, 0, 0, 0, 2, 0},
                    {1, 1, 2, 0, 0, 2, 2, 1}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 0, 0},
                    {0, 0, 0, 0, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {
                    {1, 2, 2, 2, 2, 2, 2, 2},
                    {1, 2, 1, 1, 2, 2, 2, 2},
                    {1, 1, 1, 2, 2, 2, 2, 2},
                    {1, 1, 1, 2, 2, 2, 2, 2},
                    {1, 1, 1, 1, 2, 2, 2, 2},
                    {1, 1, 1, 0, 2, 2, 2, 2},
                    {1, 0, 0, 0, 2, 0, 0, 2},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                }
            };

        int spieler[7] = {1, 2, 2, 1, 2, 1,1};
        int position[7][2] = { {2, 3}, {0, 3}, {4, 3}, {3, 4}, {3, 5}, {3, 4}, {5, 7} };  // posX, posY
        bool korrektesErgebnis[7] = {false, false, false, true, true, false, false};

        for (int i = 0; i < 7; i++)
        {
            // Aktualisiert das Gesamtergebnis anhand des Einzeltests.
            // 执行单个测试并合并总结果
            bool tmp_ergebnis = zugGueltigTest(eingabeFeld[i], spieler[i], position[i][0], position[i][1], korrektesErgebnis[i], i);

            if (gesamtErgebnis == true && tmp_ergebnis == false)
            {
                gesamtErgebnis = false;
            }
        }
    }

// Testgruppe fuer die Funktion zugAusfuehren()
// 测试 zugAusfuehren()
// ---------- TESTE ZUG AUSFUEHREN ---------- //
    {
        int eingabeFeld[10][8][8] = {
                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 1, 2, 2},
                    {2, 2, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 2, 1, 1},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 1, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 2, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 1, 0},
                    {0, 0, 0, 2, 0, 2, 0, 0},
                    {0, 0, 0, 2, 2, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 2, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 1, 0, 0},
                    {0, 0, 0, 1, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 0, 0},
                    {0, 0, 0, 0, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 1, 0},
                    {0, 0, 0, 2, 0, 2, 0, 0},
                    {0, 0, 0, 2, 2, 0, 0, 0},
                    {0, 1, 2, 0, 2, 2, 1, 0},
                    {0, 0, 0, 2, 2, 0, 0, 0},
                    {0, 0, 0, 1, 0, 1, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 2, 0, 0},
                    {0, 0, 0, 0, 1, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 0, 0},
                    {0, 0, 0, 1, 1, 1, 1, 0},
                    {0, 0, 1, 0, 0, 0, 0, 0},
                    {0, 0, 2, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 1, 0, 0, 0, 0, 0, 0},
                    {0, 1, 0, 0, 0, 0, 2, 1},
                    {1, 0, 1, 1, 2, 0, 0, 0},
                    {0, 0, 1, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 1, 0, 1},
                    {0, 0, 0, 0, 0, 2, 2, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 2, 2, 0, 0},
                    {0, 0, 0, 1, 0, 1, 0, 0},
                    {0, 0, 2, 0, 0, 2, 0, 0},
                    {0, 1, 0, 0, 0, 1, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                }
            };

        int ergebnisFeld[10][8][8] {
                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 1, 2, 2},
                    {2, 2, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 2, 1, 1},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 1, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 2, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 1, 0},
                    {0, 0, 0, 2, 0, 1, 0, 0},
                    {0, 0, 0, 2, 1, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 2, 0, 0, 0, 0},
                    {0, 0, 0, 2, 0, 1, 0, 0},
                    {0, 0, 0, 2, 1, 0, 0, 0},
                    {0, 0, 0, 2, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 0, 0},
                    {0, 0, 0, 0, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 1, 0},
                    {0, 0, 0, 1, 0, 1, 0, 0},
                    {0, 0, 0, 1, 1, 0, 0, 0},
                    {0, 1, 1, 1, 1, 1, 1, 0},
                    {0, 0, 0, 1, 1, 0, 0, 0},
                    {0, 0, 0, 1, 0, 1, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 2, 0, 0},
                    {0, 0, 0, 0, 2, 0, 0, 0},
                    {0, 0, 0, 2, 0, 0, 0, 0},
                    {0, 0, 2, 1, 1, 1, 1, 0},
                    {0, 0, 2, 0, 0, 0, 0, 0},
                    {0, 0, 2, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 1, 0, 0, 0, 0, 0, 0},
                    {0, 1, 0, 0, 0, 0, 2, 1},
                    {1, 2, 2, 2, 2, 0, 0, 0},
                    {0, 0, 1, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },
                {   {0, 0, 0, 0, 0, 1, 0, 1},
                    {0, 0, 0, 0, 0, 1, 1, 0},
                    {0, 0, 0, 0, 0, 1, 0, 0},
                    {0, 0, 0, 0, 1, 1, 0, 0},
                    {0, 0, 0, 1, 0, 1, 0, 0},
                    {0, 0, 2, 0, 0, 2, 0, 0},
                    {0, 1, 0, 0, 0, 1, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                }
            };

        int spieler[10]={0,0,0,1,2,0,1,2,2,1};
        int position[10][2]=                       // eine andere, moegliche Darstellung
                    {                              // der gegebenen Positionen posX, posY
                        {0,0},
                        {0,0},
                        {0,0},
                        {3,4},
                        {3,5},
                        {0,0},
                        {3,4},
                        {2,4},
                        {1,4},
                        {5,2}
                    };

        for (int i = 0; i < 10; i++)
        {
            // Aktualisiert das Gesamtergebnis anhand des Einzeltests.
            // 执行单个测试并合并总结果
            bool tmp_ergebnis = zugAusfuehrenTest(eingabeFeld[i], ergebnisFeld[i], spieler[i], position[i][0], position[i][1], i);

            if (gesamtErgebnis == true && tmp_ergebnis == false)
            {
                gesamtErgebnis = false;
            }
        }

        std::cout << "Ende des Tests fuer 'zugAusfuehren()'" << std::endl << std::endl;
    }

// Testgruppe fuer die Funktion moeglicheZuege()
// 测试 moeglicheZuege()
// ---------- TESTE MOEGLICHE ZUEGE ---------- //
{
        int eingabeFeld[2][8][8] 
        {
                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 2, 0, 0, 0},
                    {0, 0, 0, 2, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 2, 1, 0, 0, 0},
                    {0, 0, 0, 2, 1, 1, 0, 0},
                    {0, 0, 0, 2, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                }
        };

        int spieler[2] = {1, 1};
        int korrektesErgebnis[2] = {4, 5};

        for (int i = 0; i < 2; i++)
        {
            // Aktualisiert das Gesamtergebnis anhand des Einzeltests.
            // 执行单个测试并合并总结果
            bool tmp_ergebnis = moeglicheZuegeTest(eingabeFeld[i], spieler[i], korrektesErgebnis[i], i);

            if (gesamtErgebnis == true && tmp_ergebnis == false)
            {
                gesamtErgebnis = false;
            }
        }

        std::cout << "Ende des Tests fuer 'moeglicheZuege()'" << std::endl << std::endl;
    }

    return gesamtErgebnis;

}

