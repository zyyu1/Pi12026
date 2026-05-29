/**
 * Praktikum Informatik 1 MMXXVI
 *
 * @file config.h
 *
 * Beinhaltet globale Konfiguration.
 */
//全局配置文件

#ifndef CONFIG_H_
#define CONFIG_H_

//8行8列
/** Definiert die Anzahl der Spalten des Spielfelds */
const int GROESSE_X = 8;

/** Definiert die Anzahl der Zeilen des Spielfelds */
const int GROESSE_Y = 8;


/** Definiert, ob die Tests ausgefuehrt werden. 1 ja, 0 nein 是否运行测试 TEST*/
const int TEST = 1;

/** Definiert, ob die Ausgabe der Test ausfuehrlicher sein soll 是否详细输出测试信息*/
const int AUSFUEHRLICH = 1;

/**Definiert die Art eines Spielers */
const int MENSCH = 1;
const int COMPUTER = 2;


#endif /* CONFIG_H_ */
