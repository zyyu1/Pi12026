/**
 * Praktikum Informatik 1 MMXXVI
 *
 * @file config.h
 *
 * Beinhaltet globale Konfiguration.
 */
// Globale Konfigurationsdatei fuer das gesamte Othello-Projekt.
// 全局配置文件

// Das Spielfeld besitzt 8 Spalten und 8 Zeilen.
#ifndef CONFIG_H_
#define CONFIG_H_

// 8 行 8 列
/** Definiert die Anzahl der Spalten des Spielfelds */
const int GROESSE_X = 8;

/** Definiert die Anzahl der Zeilen des Spielfelds */
const int GROESSE_Y = 8;


/** Definiert, ob die Tests ausgefuehrt werden. 1 ja, 0 nein。是否运行测试 */
const int TEST = 1;

/** Definiert, ob die Ausgabe der Tests ausfuehrlicher sein soll。是否详细输出测试信息 */
const int AUSFUEHRLICH = 1;

/**Definiert die Art eines Spielers */
const int MENSCH = 1;
/** Definiert den Computer als Spielertyp */
const int COMPUTER = 2;


#endif /* CONFIG_H_ */
