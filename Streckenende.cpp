/*
 * Streckenende.cpp
 *
 *  Created on: 18.01.2025
 *      Author: Jonas
 */

#include "Streckenende.h"
#include "Fahrzeug.h"
#include "Weg.h"

Streckenende::Streckenende(Fahrzeug& fahrzeug, Weg& weg) : Fahrausnahme(fahrzeug, weg) {
}

void Streckenende::vBearbeiten() {
	std::shared_ptr<const Kreuzung> kreuzung = weg.getZielKreuzung();
    std::cout << "Streckenende-Ausnahme bei Fahrzeug: "
              << fahrzeug.getName()
              << " auf Weg: "
              << weg.getName()
              << std::endl;
	std::unique_ptr<Fahrzeug> pFahrzeugKopie = weg.pAbgabe(fahrzeug);
	std::shared_ptr<Weg> naechsterWeg = kreuzung->pZufaelligerWeg(weg);
	naechsterWeg->vAnnahme(std::move(pFahrzeugKopie));
    std::cout << "ZEIT : " << dGlobaleZeit << std::endl
              << "KREUZUNG : " << kreuzung->getName() << " " << std::fixed << std::setprecision(2) << kreuzung->getTankstelleninhalt() << std::endl
              << "WECHSEL : " << weg.getName() << " → " << naechsterWeg->getName() << std::endl
              << "FAHRZEUG : " << fahrzeug.getName() << std::endl;
}

Streckenende::~Streckenende() {
	// TODO Auto-generated destructor stub
}

