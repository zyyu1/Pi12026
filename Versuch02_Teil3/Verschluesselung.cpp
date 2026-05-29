///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////
//用二维数组做一个字母替换表,第一行保存明文字母 A-Z，第二行保存密文字母 A-Z 的某种排列，并且每个字母只能出现一次
//然后写加密函数和解密函数，输入一个大写单词，输出原文、加密结果和解密结果

using namespace std;

#include <iostream>
#include <string>

//3.写加密函数
//遍历单词,对每个字母去 lookup 表里查找,用对应的替换字母拼接成新字符串,返回新字符串
string verschluesseln(char schluessel[2][26], string wort)
{
	std::string geheim = "";
	int length = wort.length();
	const int anzahlBuchstaben = 26;

	for(int i = 0; i < length; i++)							//遍历输入单词
	{               	 			
		for( int k = 0; k < anzahlBuchstaben; k++)          //对每个字母在lookup表里查找
		{				
			if(wort[i] == schluessel[0][k])
			{
				geheim = geheim + schluessel[1][k];			//将找到的加密字符加到字符串后面
				break;	
			}
		}
	}

	return geheim;											//返回加密字符串
}


//5.写解密函数 copy from verschluesseln
string entschluesseln(char schluessel[2][26], string wort)
{
	std::string klarText = "";
	int length = wort.length();
	const int anzahlBuchstaben = 26;

	for(int i = 0; i < length; i++)							
	{               	 			
		for( int k = 0; k < anzahlBuchstaben; k++)          
		{				
			if(wort[i] == schluessel[0][k])
			{
				klarText = klarText + schluessel[1][k];			
				break;	
			}
		}
	}
	
	return klarText;
}


int main()
{

	//2.在main中建立 Lookup-Tabelle
	char vlookupTabelle[2][26] =
    {
        {
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
            'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
        },
        {
            'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D',
            'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'
        }
    };

	//weitere Lookup-Tabelle for Entschlüsselung
	char elookupTabelle[2][26] =
    {
		{
            'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D',
            'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'
        },
        {
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
            'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
        }
    };

	//4.Verschlüsselung Testen 在 main 里测试加密

	std::string wort = "";
	std::string geheim;

	//用户输入wort
	std::cout << "Bitte geben Sie ein Wort in Grossbuchstaben ein: " << std::endl;
    std::cin >> wort;

	//加密
	geheim = verschluesseln(vlookupTabelle, wort);

	std::cout << std::endl;
	std::cout << "Verschluesselung testen" << std::endl;
	std::cout << "Eingabetext: " << wort << std::endl;
	std::cout << "Verschluesselt: " << geheim << std::endl;

	//6.输出解密结果
	std::string klarText = "";

	klarText = entschluesseln(elookupTabelle, geheim);
	
	std::cout << std::endl;
	std::cout << "Entschluesselung testen" << std::endl;
	std::cout << "Entschluesselt: " << klarText << std::endl;

	return 0;
}
