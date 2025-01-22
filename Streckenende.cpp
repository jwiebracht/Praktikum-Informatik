/*
 * Streckenende.cpp
 *
 *  Created on: 18.01.2025
 *      Author: Jonas
 */

#include "Streckenende.h"

Streckenende::Streckenende(Fahrzeug& fahrzeug, Weg& weg) : Fahrausnahme(fahrzeug, weg) {
}

void Streckenende::vBearbeiten() {
    std::cout << "Streckenende-Ausnahme bei Fahrzeug: "
              << fahrzeug.getName()
              << " auf Weg: "
              << weg.getName()
              << std::endl;
}

Streckenende::~Streckenende() {
	// TODO Auto-generated destructor stub
}

