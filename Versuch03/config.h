/**
 * Praktikum Informatik 1 MMXXVI
 *
 * @file config.h
 * @brief Beinhaltet globale Konfigurationswerte fuer das Othello-Projekt.
 */
// Globale Konfigurationsdatei fuer das gesamte Othello-Projekt.
// 鍏ㄥ眬閰嶇疆鏂囦欢

// Das Spielfeld besitzt 8 Spalten und 8 Zeilen.
#ifndef CONFIG_H_
#define CONFIG_H_

// 8 琛?8 鍒?
/** @brief Definiert die Anzahl der Spalten des Spielfelds. */
const int GROESSE_X = 8;

/** @brief Definiert die Anzahl der Zeilen des Spielfelds. */
const int GROESSE_Y = 8;

/** @brief Steuert, ob die automatisierten Tests ausgefuehrt werden. */
const int TEST = 1;

/** @brief Steuert, ob die Testausgabe zusaetzliche Details anzeigen soll. */
const int AUSFUEHRLICH = 1;

/** @brief Kennzeichnet einen menschlichen Spieler. */
const int MENSCH = 1;
/** @brief Kennzeichnet einen Computerspieler. */
const int COMPUTER = 2;

#endif /* CONFIG_H_ */
