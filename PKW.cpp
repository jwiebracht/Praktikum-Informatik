/*
 * PKW.cpp
 *
 *  Created on: 23.10.2024
 *      Author: Jonas
 */

#include "PKW.h"

PKW::PKW() {
	// TODO Auto-generated constructor stub
}

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

void PKW::dTanken(double dMenge = 0.0)
{
	if(dMenge == 0.0)
	{
		dMenge = p_dTankvolumen - p_dTankinhalt;
	}
	if(dMenge > p_dTankvolumen - p_dTankinhalt)
	{
		p_dTankinhalt = p_dTankvolumen;
		std::cout << "Es wurden: " << p_dTankvolumen - p_dTankinhalt << " Liter getankt" << std::endl;
	}
	else if(p_dTankvolumen > 0 && dMenge < p_dTankvolumen - p_dTankinhalt)
	{
		p_dTankinhalt += dMenge;
		std::cout << "Es wurden: " << dMenge << " Liter getankt" << std::endl;
	}
}

void PKW::vSimulieren()
{
	if(dGlobaleZeit > p_dZeit && p_dTankinhalt > 0)
	{
		//Sicherstellen das das Fahrzeug keinen negativen Tank bekommt
		if(p_dTankinhalt - p_dVerbrauch * (dGlobaleZeit - p_dZeit) < 0)
		{
			p_dTankinhalt = 0;
		}
		else
		{
			p_dTankinhalt = p_dTankinhalt - p_dVerbrauch * (dGlobaleZeit - p_dZeit);
		}
		Fahrzeug::vSimulieren();
	}
	else if(p_dTankinhalt == 0)
	{
		std::cout << "Tank ist leer, Fahrzeug: " << p_sName << " ist liegengeblieben" << std::endl;
	}
}

void PKW::vKopf()
{
	Fahrzeug::vKopf();
	std::cout << std::setw(20) << "Gesamtverbrauch" << std::setw(15) << "Tankinhalt";
}

void PKW::vAusgeben() const
{
	double insgesamterVerbrauch = (p_dGesamtStrecke/100) * p_dVerbrauch;
	Fahrzeug::vAusgeben();
	std::cout << std::left;
	std::cout << std::setw(20) << std::fixed << std::setprecision(2) << insgesamterVerbrauch
            << std::setw(20) << std::fixed << std::setprecision(2) << p_dTankinhalt;
}

double PKW::dGeschwindigkeit() const
{
	return p_dMaxGeschwindigkeit;
}

PKW::~PKW() {
	// TODO Auto-generated destructor stub
}
