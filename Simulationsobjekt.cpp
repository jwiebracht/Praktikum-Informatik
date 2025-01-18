/*
 * Simulationsobjekt.cpp
 *
 *  Created on: 28.11.2024
 *      Author: jonas
 */

#include "Simulationsobjekt.h"

int Simulationsobjekt::p_iMaxID = 0;

Simulationsobjekt::Simulationsobjekt(std::string p_sName) : ID(++p_iMaxID), p_sName(p_sName){
	std::cout << "SimObj mit der ID: " << ID << " und dem Namen: " << p_sName << " wurde erstellt" << std::endl;
}

void Simulationsobjekt::vKopf()
{
    std::cout << std::left;
    std::cout << std::setw(6) << "ID"
              << std::setw(13) << "Name"
              << std::setw(20) << "MaxGeschwindigkeit"
              << std::setw(20) << "Gesamtstrecke"
    			<< std::setw(20) << "Akt. Geschw.";
}

void Simulationsobjekt::vAusgeben(std::ostream& out) const
{
    std::cout << std::left;
    std::cout << std::setw(6) << ID
              << std::setw(13) << p_sName;
}


std::string Simulationsobjekt::getName() const
{
	return p_sName;
}

int Simulationsobjekt::getID() const
{
	return ID;
}

bool operator==(const Simulationsobjekt& one, const Simulationsobjekt& two)
{
	return one.getID() == two.getID();
}

std::ostream& operator<<(std::ostream& out, const Simulationsobjekt& objekt)
{
	objekt.vAusgeben(out);
	return out;
}

Simulationsobjekt::~Simulationsobjekt() {
	// TODO Auto-generated destructor stub
}

