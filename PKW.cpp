/*
 * PKW.cpp
 *
 *  Created on: 23.10.2024
 *      Author: Jonas
 */

#include "PKW.h"
#include "Weg.h"

PKW::PKW(std::string p_sName, double p_dMaxGeschwindigkeit, double p_dVerbrauch) : Fahrzeug(p_sName, p_dMaxGeschwindigkeit), p_dVerbrauch(p_dVerbrauch), p_dTankvolumen(55), p_dTankinhalt(p_dTankvolumen/2)
{
	std::cout << "PKW erstellt:\n"
	          << "Name: " << p_sName << "\n"
	          << "Max. Geschwindigkeit: " << p_dMaxGeschwindigkeit << " km/h\n"
	          << "Verbrauch: " << p_dVerbrauch << " l/100km\n"
	          << "Tankvolumen: " << p_dTankvolumen << " l\n"
	          << "Tankinhalt: " << p_dTankinhalt << " l\n";
}

PKW::PKW(std::string p_sName, double p_dMaxGeschwindigkeit, double p_dVerbrauch, double p_dTankvolumen) : Fahrzeug(p_sName, p_dMaxGeschwindigkeit), p_dVerbrauch(p_dVerbrauch), p_dTankvolumen(p_dTankvolumen), p_dTankinhalt(p_dTankvolumen/2)
{
	std::cout << "PKW erstellt:\n"
	          << "Name: " << p_sName << "\n"
	          << "Max. Geschwindigkeit: " << p_dMaxGeschwindigkeit << " km/h\n"
	          << "Verbrauch: " << p_dVerbrauch << " l/100km\n"
	          << "Tankvolumen: " << p_dTankvolumen << " l\n"
	          << "Tankinhalt: " << p_dTankinhalt << " l\n";
}

void PKW::vZeichnen(Weg& pWeg) const
{
	double dRelPos = p_dAbschnittStrecke / pWeg.getLaenge();

	if (dRelPos > 1){ dRelPos = 1;}

	bZeichnePKW(p_sName, pWeg.getName(), dRelPos, dGeschwindigkeit(), p_dTankinhalt);
}

double PKW::dTanken(double dMenge)
{
	if(dMenge == 0.0)
	{
		dMenge = p_dTankvolumen - p_dTankinhalt;
		return dMenge;
	}
	if(dMenge > p_dTankvolumen - p_dTankinhalt)
	{
		double neu = p_dTankvolumen - p_dTankinhalt;
		p_dTankinhalt = p_dTankvolumen;
		std::cout << "Es wurden: " << p_dTankvolumen - p_dTankinhalt << " Liter getankt" << std::endl;
		return neu;
	}
	else if(p_dTankvolumen > 0 && dMenge < p_dTankvolumen - p_dTankinhalt)
	{
		p_dTankinhalt += dMenge;
		std::cout << "Es wurden: " << dMenge << " Liter getankt" << std::endl;
		return dMenge;
	}
	return 0.0f;
}

void PKW::vSimulieren()
{
    if (dGlobaleZeit <= p_dZeit)
        return;

    double vergangeneZeit = dGlobaleZeit - p_dZeit;
    double teilStrecke = p_pVerhalten->dStrecke(*this, vergangeneZeit);

    if (teilStrecke == 0)
    {
    	p_dAbschnittStrecke = 0;
        //throw Streckenende(*this, p_pVerhalten->getWeg());
    }
    double verbrauch = p_dVerbrauch * vergangeneZeit;
    p_dTankinhalt = std::max(0.0, p_dTankinhalt - verbrauch);
    if (p_dTankinhalt == 0) {
        std::cout << "Tank ist leer, Fahrzeug: " << p_sName << " wurde gestoppt." << std::endl;
        return; // Fahrzeug darf nicht weiter simuliert werden
    }
    Fahrzeug::vSimulieren();
}


void PKW::vKopf()
{
	Simulationsobjekt::vKopf();
	std::cout << std::setw(20) << "Gesamtverbrauch" << std::setw(15) << "Tankinhalt";
}

void PKW::vAusgeben(std::ostream& out) const
{
	double insgesamterVerbrauch = (p_dGesamtStrecke/100) * p_dVerbrauch;
	Fahrzeug::vAusgeben(out);
	std::cout << std::left;
	std::cout << std::setw(20) << std::fixed << std::setprecision(2) << insgesamterVerbrauch
            << std::setw(20) << std::fixed << std::setprecision(2) << p_dTankinhalt;
}

double PKW::dGeschwindigkeit() const {
    Weg& aktuellerWeg = p_pVerhalten->getWeg();
    double tempolimit = aktuellerWeg.getTempolimit();
    return std::min(p_dMaxGeschwindigkeit, tempolimit);
}

std::unique_ptr<Fahrzeug> PKW::fahrzeugErstellen()
{
	std::string name =  Fahrzeug::generateRandomName();
	std::unique_ptr<PKW> pkw = std::make_unique<PKW>(name, 100, 5);
	return pkw;
}

double PKW::getTankvolumen()
{
	return p_dTankvolumen;
}

double PKW::getTankinhalt()
{
	return p_dTankinhalt;
}

PKW::~PKW() {
	// TODO Auto-generated destructor stub
}

;
