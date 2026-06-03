/**
 * Praktikum Informatik 1 
 * 
 *
 * @file othelloKI.h
 *
 * Stellt eine KI fuer das Spiel Othello zur Verfuegung
 */
// 电脑玩家

#ifndef OTHELLOKI_H_
#define OTHELLOKI_H_

#include "config.h"

/**
 * @brief Berechnet und fuehrt einen Computerzug fuer Othello aus.
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der Spieler, fuer den der Computerzug berechnet wird
 * @return true, wenn ein Zug ausgefuehrt wurde, sonst false
 */
bool computerZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler);

#endif /* OTHELLOKI_H_ */
