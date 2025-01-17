/*
 * Weg.cpp
 *
 *  Created on: 17.01.2025
 *      Author: jonas
 */

#include "Weg.h"

Weg::Weg(std::string p_sName) : Simulationsobjekt(p_sName){
	// TODO Auto-generated constructor stub

}

enum Tempolimit
{
	Innerorts = 50,
	Ausserorts = 100,
	Autobahn = std::numeric_limits<int>::max()
};

Weg::~Weg() {
	// TODO Auto-generated destructor stub
}

