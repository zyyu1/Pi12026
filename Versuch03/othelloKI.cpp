/**
 * Praktikum Informatik 1
 *
 * @file othelloKI.cpp
 *
 * Stellt eine KI fuer das Spiel Othello zur Verfuegung
 */

#include "othelloKI.h"
#include <iostream>

// Diese Funktionen werden in othello.cpp definiert und hier von der KI genutzt.
extern int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler);
extern void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY);
extern bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY);

/**
 * @brief Fuehrt einen moeglichst guenstigen Computerzug aus.
 *
 * Die KI simuliert alle gueltigen Zuege und waehlt den Zug aus,
 * der dem Gegner anschliessend moeglichst wenige Antworten laesst.
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der Spieler, fuer den der Computer zieht
 * @return true, wenn ein Zug ausgefuehrt wurde, sonst false
 */
bool computerZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    // Wenn kein Zug moeglich ist, kann der Computer nichts ausfuehren.
    if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
    {
        return false;
    }

    // Das Hilfsspielfeld dient zum Simulieren aller moeglichen Zuege.
    int voraussehen[GROESSE_Y][GROESSE_X];
    int min_x = 0;
    int min_y = 0;
    int min = GROESSE_X * GROESSE_Y;

    for (int j = 0; j < GROESSE_Y; j++)
    {
        for (int i = 0; i < GROESSE_X; i++)
        {
            // Kopiert das aktuelle Spielfeld fuer eine Zugvorschau.
            for (int cj = 0; cj < GROESSE_Y; cj++)
            {
                for (int ci = 0; ci < GROESSE_X; ci++)
                {
                    voraussehen[cj][ci] = spielfeld[cj][ci];
                }
            }

            if (zugGueltig(voraussehen, aktuellerSpieler, i, j))
            {
                // Simuliert den gueltigen Zug auf dem Hilfsspielfeld.
                zugAusfuehren(voraussehen, aktuellerSpieler, i, j);
                // Bevorzugt einen Zug, der dem Gegner moeglichst wenige Antworten laesst.
                if (moeglicheZuege(voraussehen, 3 - aktuellerSpieler) < min)
                {
                    min = moeglicheZuege(voraussehen, 3 - aktuellerSpieler);
                    min_x = i;
                    min_y = j;
                }
            }
        }
    }

    // Fuehrt den besten gefundenen Zug auf dem echten Spielfeld aus.
    zugAusfuehren(spielfeld, aktuellerSpieler, min_x, min_y);
    std::cout << std::endl << "Spieler " << aktuellerSpieler << " setzt auf "
              << static_cast<char>(min_x + 65) << (min_y + 1) << std::endl;

    return true;
}
