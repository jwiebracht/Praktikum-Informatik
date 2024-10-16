/*
 * Fahrzeug.cpp
 *
 *  Created on: 15.10.2024
 *      Author: jonas
 */

#include "Fahrzeug.h"

int Fahrzeug::p_iMaxID = 0;

Fahrzeug::Fahrzeug() : ID(++p_iMaxID), p_sName("")
{
	std::cout << "Ein Fahrzeug mit dem Namen " << p_sName << " und der ID " << ID << " wurde erstellt." << std::endl;
}

Fahrzeug::Fahrzeug(std::string p_sName) : p_sName(p_sName), ID(++p_iMaxID)
{
	std::cout << "Ein Fahrzeug mit dem Namen " << p_sName << " und der ID " << ID << " wurde erstellt." << std::endl;
}

Fahrzeug::~Fahrzeug() {
	// TODO Auto-generated destructor stub
	std::cout << "Das gelöschte Fahrzeug hatte die ID " << ID << " und den Namen " << p_sName << std::endl;
}

