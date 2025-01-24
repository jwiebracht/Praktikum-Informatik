/*
 * Kreuzung.cpp
 *
 *  Created on: 24.01.2025
 *      Author: jonas
 */

#include "Kreuzung.h"
#include "Weg.h"
#include "Fahrzeug.h"

Kreuzung::Kreuzung(std::string p_sName) : Simulationsobjekt(p_sName){
	// TODO Auto-generated constructor stub
}

Kreuzung::Kreuzung(std::string p_sName, double tank) : Simulationsobjekt(p_sName), p_dTankstelle(tank)
{

}

void Kreuzung::vAnnahme(std::unique_ptr<Fahrzeug> fahrzeug, double startZeitpunkt)
{
	vTanken(*fahrzeug);
	if(!p_pWege.empty()) (p_pWege.front())->vAnnahme(std::move(fahrzeug), startZeitpunkt);
}

void Kreuzung::vTanken(Fahrzeug& fahrzeug)
{
	if(p_dTankstelle > 0 && fahrzeug.getTankinhalt() < fahrzeug.getTankvolumen())
	{
		fahrzeug.dTanken(std::min(p_dTankstelle, fahrzeug.getTankvolumen() - fahrzeug.getTankinhalt()));
		p_dTankstelle -= std::min(p_dTankstelle, fahrzeug.getTankvolumen() - fahrzeug.getTankinhalt());
	}
}

void Kreuzung::vSimulieren()
{
	for(auto it : p_pWege)
	{
		it->vSimulieren();
	}
}

void Kreuzung::vVerbinde(std::string p_sNameHinweg, std::string p_sNameRueckweg, double weglaenge, std::shared_ptr<Kreuzung> startKreuzung, std::shared_ptr<Kreuzung> zielKreuzung, p_eTempolimit tempolimit)
{
	std::shared_ptr<Weg> hinweg = std::make_shared<Weg>(p_sNameHinweg, weglaenge, tempolimit);
	std::shared_ptr<Weg> rueckweg = std::make_shared<Weg>(p_sNameRueckweg, weglaenge, tempolimit);

	//std::weak_ptr<Weg> pHinweg = hinweg;
	//std::weak_ptr<Weg> pRuekweg = rueckweg;

	//std::weak_ptr<Kreuzung> kreuzung1 = startKreuzung;
	//std::weak_ptr<Kreuzung> kreuzung2 = zielKreuzung;

	hinweg->setZielkreuzung(zielKreuzung);
	rueckweg->setZielkreuzung(startKreuzung);

	startKreuzung->p_pWege.push_back(hinweg);
	zielKreuzung->p_pWege.push_back(rueckweg);
}

std::shared_ptr<Weg> Kreuzung::pZufaelligerWeg(Weg&) const
{
	int anzahl = p_pWege.size();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, anzahl);

    int wegNummer = distrib(gen);
    auto it = std::next(p_pWege.begin(), wegNummer - 1);
    return *it;
}

std::string Kreuzung::getName() const
{
	return p_sName;
}

double Kreuzung::getTankstelleninhalt() const
{
	return p_dTankstelle;
}

void Kreuzung::vAusgeben(std::ostream& out) const
{
	Simulationsobjekt::vAusgeben(out);
}

Kreuzung::~Kreuzung() {
	// TODO Auto-generated destructor stub
}

