/*
 * main.cpp
 *
 *  Created on: 15.10.2024
 *      Author: jonas
 */
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include <memory>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <random>
#include "math.h"
#include "Weg.h"
#include "vertagt_liste.h"
using namespace std;

void vAufgabe_1a();
void v_Aufgabe_2();
void vAufgabe_3();
void vAufgabe_AB1();
void vAufgabe_4();
void vAufgabe_5();
void vAufgabe_5a();
void vAufgabe_6();
void vAufgabe_6a();
void vAufgabe_6b();
void vAufgabe_7();

int main()
{
	/*
	Fahrzeug Auto1("Jonas");
	Fahrzeug* Auto2 = new Fahrzeug;
	delete Auto2;

	std::unique_ptr<Fahrzeug> Auto3 = std::make_unique<Fahrzeug>("Jonas", 90);
	std::shared_ptr<Fahrzeug> Auto4 = std::make_shared<Fahrzeug>("Emily", 80);
	std::cout << Auto4.use_count() << std::endl;
	std::shared_ptr<Fahrzeug> Auto5 = Auto4;
	std::cout << Auto5.use_count() << std::endl;
	std::vector<std::unique_ptr<Fahrzeug>> vektor;

	for(int i = 0; i<5; ++i)
	{
		dGlobaleZeit += 1.5;
		Auto3->vSimulieren();
		Auto3->vSimulieren();
	}

	Fahrzeug::vKopf();
	Auto3->vAusgeben();
	std::cout << std::endl;
	Auto4->vAusgeben();
	std::cout << std::endl;
	*/





	//vAufgabe_1a();
	//v_Aufgabe_2();
	//vAufgabe_3();
	//vAufgabe_AB1();
	//vAufgabe_4();
	//vAufgabe_5();
	//vAufgabe_5a();
	//vAufgabe_6();
	//vAufgabe_6a();
	//vAufgabe_6b();
	vAufgabe_7();
	return 0;

}

void vAufgabe_1a()
{
	std::vector<std::unique_ptr<Fahrzeug>> fahrzeuge;
	int choice;
	std::string newName;
	double maxSpeed;
	double verbrauch;
	double zeit = 1.0;
	int simulationsSchritte = 5;

	while(true)
	{
	//Menüerstellung
	std::cout << " Willkommen im Menue, was wollen sie machen?: " << std::endl << "(1) Neues Fahrzeug erstellen" << std::endl
																<< "(2) Globale Zeitschritte und Anzahl der Simulationsschritte setzten (default: 1.0 und 5)" << std::endl
																<< "(3) Simuliere alle Fahrzeuge" << std::endl
																<< "(4) Fuelle die Liste mit 4 Fahrzeugen"
																<< std::endl << "(0) Menu beenden" << std::endl;
	std::cin >> choice;

	switch(choice)
	{
	case 1:
		std::cout << "Wie soll ihr Fahrzeug heissen?" << std::endl;
		std::cin >> newName;
		std::cout << "Wie schnell kann das Fahrzeug fahren?" << std::endl;
		std::cin >> maxSpeed;
		std::cout << "Wie viel verbraucht das Fahrzeug?" << std::endl;
		std::cin >> verbrauch;

		fahrzeuge.push_back(std::make_unique<PKW>(newName, maxSpeed, verbrauch));
	break;

	case 2:
		std::cout << "In welchen Schritten soll die Globale Zeit erhoehr werden?" << std::endl;
		std::cin >> zeit; //Zeit wie viel die Globale Uhr pro Simulationsschritt erhöhr wird
		std::cout << "Wie oft soll Simuliert werden?" << std::endl;
		std::cin >> simulationsSchritte; //Anzahl wie viele Simulationsschritte durchgeführt werden sollen
	break;

	case 3:
		if(fahrzeuge.empty() == false)
		{
			std::cout << "Simulation wird ausgefuehrt" << std::endl;
			for(int i=1; i <= simulationsSchritte; ++i)
			{
				dGlobaleZeit += zeit;
				std::cout << std::endl;
				PKW::vKopf();
				std::cout << std::endl << "---------------------------------------------------------------------------------------------------------" << std::endl;
				for(auto& fahrzeug : fahrzeuge)
				{
					fahrzeug->vSimulieren();
					std::cout << *fahrzeug << std::endl;
					std::cout << std::endl;
				}
			}
		}
			else
			{
				std::cout << "Keine Fahrzeuge im Vektor vorhanden" << std::endl;
			}
		break;

	case 4:
		fahrzeuge.push_back(std::make_unique<PKW>("BMW", 130, 10));
		fahrzeuge.push_back(std::make_unique<PKW>("Audi", 190, 15));
		fahrzeuge.push_back(std::make_unique<PKW>("Mercedes", 60, 12));
		fahrzeuge.push_back(std::make_unique<PKW>("Renault", 10, 5));
		fahrzeuge.push_back(std::make_unique<Fahrrad>("Cube", 25));
		fahrzeuge.push_back(std::make_unique<Fahrrad>("HollandRad", 23));
	break;

	case 0:
		std::cout << "Programm wird beendet..." << std::endl;
		return;
	break;

	default:
		std::cout << "ungueltige eingabe" << std::endl;
	break;
	}
	}
}

void v_Aufgabe_2() {
    int nPKW, nFahrrad;
    std::cout << "Bitte geben Sie die Anzahl der zu erzeugenden PKWs ein: ";
    std::cin >> nPKW;
    std::cout << "Bitte geben Sie die Anzahl der zu erzeugenden Fahrräder ein: ";
    std::cin >> nFahrrad;

    // Vector zur Verwaltung der Fahrzeuge
    std::vector<std::unique_ptr<Fahrzeug>> vecFahrzeuge;

    // PKW-Objekte erstellen und zum Vector hinzufügen
    for (int i = 0; i < nPKW; ++i) {
        std::string name;
        double maxGeschwindigkeit;
        std::cout << "Geben Sie den Namen des PKW " << (i + 1) << " ein: ";
        std::cin >> name;
        std::cout << "Geben Sie die maximale Geschwindigkeit des PKW " << (i + 1) << " ein: ";
        std::cin >> maxGeschwindigkeit;
        double verbrauch;
        std::cout << "Geben Sie den Verbrauch des PKW " << (i + 1) << " ein: ";
        std::cin >> verbrauch;
        vecFahrzeuge.push_back(std::make_unique<PKW>(name, maxGeschwindigkeit, verbrauch));
    }

    // Fahrrad-Objekte erstellen und zum Vector hinzufügen
    for (int i = 0; i < nFahrrad; ++i) {
        std::string name;
        double maxGeschwindigkeit;
        std::cout << "Geben Sie den Namen des Fahrrads " << (i + 1) << " ein: ";
        std::cin >> name;
        std::cout << "Geben Sie die maximale Geschwindigkeit des Fahrrads " << (i + 1) << " ein: ";
        std::cin >> maxGeschwindigkeit;
        vecFahrzeuge.push_back(std::make_unique<Fahrrad>(name, maxGeschwindigkeit));
    }

    double dZeittakt = 0.5; // Zeittakt in Stunden
    double dSimulationsdauer = 3.0; // Gesamt-Simulationsdauer in Stunden

    while (dGlobaleZeit < dSimulationsdauer) {
        dGlobaleZeit += dZeittakt;
        std::cout << "\nSimulation zur Zeit: " << dGlobaleZeit << " Stunden\n";
        PKW::vKopf();
        for (auto& fahrzeug : vecFahrzeuge) {
            fahrzeug->vSimulieren();
            std::cout << std::endl;
            std::cout << *fahrzeug << "\n"; // Ausgabe mit überladenem Operator <<
        }

        // Nach genau 3 Stunden die PKWs volltanken
        if (dGlobaleZeit >= 3.0) {
            for (auto& fahrzeug : vecFahrzeuge) {
                if (auto pkw = dynamic_cast<PKW*>(fahrzeug.get())) {
                    pkw->dTanken(0.0); // Volltanken
                }
            }
        }
    }
}

void vAufgabe_3() {
    // Fahrzeuge simulieren
        double dZeittakt = 0.5; // Zeittakt in Stunden
    double dSimulationsdauer = 3.0; // Gesamt-Simulationsdauer in Stunden

    PKW pkw1("Audi", 150, 8.0);
    PKW pkw2("BMW", 180, 9.0);

    while (dGlobaleZeit < dSimulationsdauer) {
        dGlobaleZeit += dZeittakt;
        pkw1.vSimulieren();
        pkw2.vSimulieren();
    }

    // Vergleich der Fahrzeuge basierend auf der Gesamtstrecke
    if (pkw1 < pkw2) {
        std::cout << pkw1.getName() << " hat eine geringere Gesamtstrecke als " << pkw2.getName() << "." << std::endl;
    } else if (pkw2 < pkw1) {
        std::cout << pkw2.getName() << " hat eine geringere Gesamtstrecke als " << pkw1.getName() << "." << std::endl;
    } else {
        std::cout << pkw1.getName() << " und " << pkw2.getName() << " haben die gleiche Gesamtstrecke." << std::endl;
    }
}

void vAufgabe_4()
{
	std::unique_ptr<Weg> weg = std::make_unique<Weg>("Luxenburger", 5, p_eTempolimit::Autobahn);
	Weg::vKopf();
	std::cout << *weg << std::endl;
}

void vAufgabe_5()
{
	Weg weg("Luxenburger", 20, p_eTempolimit::Autobahn);
    double dZeittakt = 0.5; // Zeittakt in Stunden
    double dSimulationsdauer = 5.0; // Gesamt-Simulationsdauer in Stunden

	std::unique_ptr<PKW> auto1 = std::make_unique<PKW>("BMW", 130, 10);
	std::unique_ptr<PKW> auto2 = std::make_unique<PKW>("Audi", 190, 15);
	std::unique_ptr<Fahrrad> fahrrad1 = std::make_unique<Fahrrad>("Cube", 20);

	weg.vAnnahme(std::move(auto1));
	weg.vAnnahme(std::move(auto2));
	weg.vAnnahme(std::move(fahrrad1));;

        for (dGlobaleZeit = 0; dGlobaleZeit < 2; dGlobaleZeit += 0.1)
        {
            Weg::vKopf();
        	weg.vSimulieren();
    		std::cout << weg << std::endl;
        }
}

void vAufgabe_5a() {
    // Weg erstellen
    Weg weg("Luxenburger", 50, p_eTempolimit::Autobahn);
    double dZeittakt = 0.5; // Zeittakt in Stunden
    double dSimulationsdauer = 5.0; // Gesamt-Simulationsdauer in Stunden

    // Fahrzeuge erstellen
    auto auto1 = std::make_unique<PKW>("BMW", 130, 10);
    auto auto2 = std::make_unique<PKW>("Audi", 190, 15);
    auto fahrrad1 = std::make_unique<Fahrrad>("Cube", 20);

    // Fahrzeuge hinzufügen (einige parkend, andere fahrend)
    weg.vAnnahme(std::move(auto1)); // Fahrendes Fahrzeug
    weg.vAnnahme(std::move(auto2), 2.0); // Parkendes Fahrzeug mit Startzeit
    weg.vAnnahme(std::move(fahrrad1)); // Fahrendes Fahrzeug

    // Simulationsschleife
    std::cout << "\nSimulation startet\n";
    Weg::vKopf();

    // Globale Zeit aktualisieren
    for (dGlobaleZeit = 0.0; dGlobaleZeit < dSimulationsdauer; dGlobaleZeit += dZeittakt) {
        std::cout << "\nSimulation zur Zeit: " << dGlobaleZeit << " Stunden\n";

        weg.vSimulieren();

        // Streckeninformationen ausgeben
        weg.vAusgeben(std::cout);
    }
}

void vAufgabe_6() {
    // Weg 1: Landstraße mit Tempolimit
    Weg weg1("Landstraße", 10.0, p_eTempolimit::Ausserorts); // Tempolimit: 100 km/h

    // Weg 2: Autobahn ohne Tempolimit
    Weg weg2("Autobahn", 20.0, p_eTempolimit::Autobahn); // Tempolimit: unbegrenzt

    // Fahrzeuge erstellen
    auto pkw1 = std::make_unique<PKW>("BMW", 120, 10);    // Max: 120 km/h
    auto pkw2 = std::make_unique<PKW>("Audi", 200, 15);   // Max: 200 km/h
    auto fahrrad = std::make_unique<Fahrrad>("Trek", 25); // Max: 25 km/h

    // Fahrzeuge auf die Wege setzen
    weg1.vAnnahme(std::move(pkw1));         // Fahrend auf Weg 1
    weg2.vAnnahme(std::move(pkw2), 1.0);   // Parkend auf Weg 2, Startzeit: 1.0
    weg1.vAnnahme(std::move(fahrrad));     // Fahrend auf Weg 1

    double dSimulationsdauer = 10;
    double dZeittakt = 0.5;

    Weg::vKopf();

    while (dGlobaleZeit < dSimulationsdauer) {
        dGlobaleZeit += dZeittakt;
        weg1.vSimulieren();
        weg2.vSimulieren();
        weg1.vAusgeben(std::cout);
        weg2.vAusgeben(std::cout);
    }

    std::cout << "\n*** Simulation beendet ***\n";
}

void vAufgabe_6a() {
    // Grafik initialisieren
    bInitialisiereGrafik(800, 500);

    // Wege erstellen
    Weg weg1("Landstr1", 500, p_eTempolimit::Ausserorts);
    Weg weg2("Landstr2", 500, p_eTempolimit::Innerorts);

    // Straßen zeichnen
    int iKoordinaten[] = {700, 250, 100, 250};
    bZeichneStrasse(weg1.getName(), weg2.getName(), 100, 2, iKoordinaten);

    // Fahrzeuge auf die Wege setzen
    weg1.vAnnahme(std::make_unique<Fahrrad>("Citybike", 40));
    weg1.vAnnahme(std::make_unique<PKW>("Mazda", 60, 6, 10));
    weg1.vAnnahme(std::make_unique<PKW>("Porsche", 70, 6, 60));
    weg2.vAnnahme(std::make_unique<Fahrrad>("BMX", 25));
    //weg1.vAnnahme(std::make_unique<PKW>("Audi", 70, 6, 60), 2);
    weg2.vAnnahme(std::make_unique<Fahrrad>("Mountainbike", 25), 4);

    // Simulationsschleife
    for (int i = 0; i <= 20; ++i) {
        // Fahrzeuge während der Simulation hinzufügen
        if (i == 10) {
            weg1.vAnnahme(std::make_unique<PKW>("VW", 80, 7, 100), 6);
        }

        // Globale Zeit aktualisieren
        dGlobaleZeit += 0.5;
        std::cout << "Aktuelle Zeit: " << dGlobaleZeit << " Stunden" << std::endl;

        // Globale Zeit im Grafikfenster setzen
        vSetzeZeit(dGlobaleZeit);

        // Simulation der Wege und Fahrzeuge
        weg1.vSimulieren();
        weg2.vSimulieren();

        // Informationen der Wege ausgeben
        std::cout << weg1 << std::endl;
        std::cout << weg2 << std::endl;

        // Simulation für kurze Zeit pausieren
        vSleep(1000);
    }

    // Grafik beenden
    vBeendeGrafik();
}

void vAufgabe_6b()
{
	static std::mt19937 device(0);
	std::uniform_int_distribution<int> dist(1, 10);
	vertagt::VListe<int> liste1;
	for (int i = 0; i < 10; i++)
	{
		liste1.push_back(dist(device)); // Zufallszahlen von 1 bis 10 werden erzeugt, es immer die selben, da selber Seed, selber Anfang
	}
	liste1.vAktualisieren(); // Liste wird aktualisiert

	std::cout << "Liste mit einlesen der Zahlen nach aktualisieren:  " << std::endl;

	for (auto it = liste1.begin(); it != liste1.end(); it++) // Liste ausgeben
	{ // Über Itaerator von Anfang bis Ende durchgehen; It beschreibt aktuelles Objekt
		std::cout << *it << std::endl;
	}

	std::cout << std::endl;

	for (auto it = liste1.begin(); it != liste1.end(); it++)
	{
		if (*it > 5) // Jedes Objekt größer wird gelöscht
		{
			liste1.erase(it); // Objekt wird gelöscht
		}
	}

	std::cout << "Liste nach erase vor aktualisieren: " << std::endl;

	for (auto it = liste1.begin(); it != liste1.end(); it++) // Liste erneut ausgeben
	{ //da vAktualisieren() noch nicht ausgeführt wurde, sollte hier dieselbe Ausgabe erfolgen
		std::cout << *it << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Liste nach erase nach aktualsieren: " << std::endl;

	liste1.vAktualisieren(); // jetzt wird die Liste aktualisiert, damit wird Löschen sichtbar

	for (auto it = liste1.begin(); it != liste1.end(); it++) // Liste wird nach Löschen jetzt ausgebeben
	{
		std::cout << *it << std::endl;
	}

	std::cout << std::endl;

	//Zum Schluss fügen Sie am Anfang und am Ende der Liste noch zwei beliebige (verschiedene) Zahlen ein und geben die Liste zur Kontrolle nochmal aus
	liste1.push_front(4); //Vorne wird die 4 eingefügt
	liste1.push_back(1); // Am Ende wird die 1 hinzugefügt

	liste1.vAktualisieren(); //Liste wird ein letztes Mal aktualsiert

	std::cout << "Liste nach Einfüen der Zahlen und nach aktualisieren: " << std::endl;

	for (auto it = liste1.begin(); it != liste1.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
}

void vAufgabe_7()
{
	shared_ptr<Kreuzung> Kr1 = make_shared<Kreuzung>("Kreuzung1", 0);
	shared_ptr<Kreuzung> Kr2 = make_shared<Kreuzung>("Kreuzung2", 1000);
	shared_ptr<Kreuzung> Kr3 = make_shared<Kreuzung>("Kreuzung3", 0);
	shared_ptr<Kreuzung> Kr4 = make_shared<Kreuzung>("Kreuzung4", 0);

	Kreuzung::vVerbinde("W12", "W21", 40, Kr1, Kr2, p_eTempolimit::Innerorts);
	Kreuzung::vVerbinde("W23a", "W32a", 115, Kr2, Kr3, p_eTempolimit::Autobahn);
	Kreuzung::vVerbinde("W23b", "W32b", 40, Kr2, Kr3, p_eTempolimit::Innerorts);
	Kreuzung::vVerbinde("W24", "W42", 55, Kr2, Kr4, p_eTempolimit::Innerorts);
	Kreuzung::vVerbinde("W34", "W43", 85, Kr3, Kr4, p_eTempolimit::Autobahn);
	Kreuzung::vVerbinde("W44a", "W44b", 130, Kr4, Kr4, p_eTempolimit::Ausserorts);

	bInitialisiereGrafik(1000,800);
	vSleep(500);
	bZeichneKreuzung(680, 40);
	bZeichneKreuzung(680, 300);
	bZeichneKreuzung(680, 570);
	bZeichneKreuzung(320, 300);

	int koordinaten1[] = {680, 40, 680, 300};
	int koordinaten2[] = {680, 300,  850, 300, 970, 390, 970, 500, 850, 570, 680, 570};
	int koordinaten3[] = {680, 300, 680, 570};
	int koordinaten4[] = {680, 300, 320, 300};
	int koordinaten5[] = {680, 570, 500, 570, 350, 510, 320, 420, 320, 300};
	int koordinaten6[] = {320, 300, 170, 300, 70, 250, 80, 90, 200, 60, 320, 150, 320, 300};

	bZeichneStrasse("W12", "W21", 40, 2, koordinaten1);
	bZeichneStrasse("W23a", "W32a", 40, 6, koordinaten2);
	bZeichneStrasse("W23b", "W32b", 40, 2, koordinaten3);
	bZeichneStrasse("W24", "W42", 55, 2, koordinaten4);
	bZeichneStrasse("W34", "W43", 85, 5, koordinaten5);
	bZeichneStrasse("W44a", "W44b", 130, 7, koordinaten6);

	unique_ptr<Fahrzeug> f1 = make_unique<PKW>("Auto1", 40, 5.5, 250);
	unique_ptr<Fahrzeug> f2 = make_unique<Fahrrad>("Fahrrad1", 20);
	Kr1->vAnnahme(move(f1), 0);
	Kr1->vAnnahme(move(f2), 1);

	while(dGlobaleZeit < 10){
		dGlobaleZeit += 0.1;
		Kr1->vSimulieren();
		Kr2->vSimulieren();
		Kr3->vSimulieren();
		Kr4->vSimulieren();
		vSetzeZeit(dGlobaleZeit);
		vSleep(100);
	}

	int x;
	cout << "Gebe 1 ein um Fenster zu schließen";
	cin >> x;
	if(x==1)
	{
		vBeendeGrafik();
	}
}








/*
double dEpsilon = 0.001;
void vAufgabe_AB1() {

    int l = 0; // Laufindex für gezielte AUsgabe
    vector<int> ausgabe{15};
    double dTakt = 0.3;

    std::vector<unique_ptr<Fahrzeug>> vecFahrzeuge;
    vecFahrzeuge.push_back(make_unique <PKW>("Audi", 217, 10.7));
    vecFahrzeuge.push_back(make_unique <Fahrrad>("BMX", 21.4));
    for (dGlobaleZeit = 0; dGlobaleZeit < 6; dGlobaleZeit += dTakt)
    {
        auto itL = find(ausgabe.begin(), ausgabe.end(), l);
        if (itL != ausgabe.end()) {
            std::cout << std::endl << l <<  " Globalezeit = " << dGlobaleZeit << std::endl;
            Fahrzeug::vKopf();
        }

        for (int i = 0; i < (int) vecFahrzeuge.size(); i++)
        {
            vecFahrzeuge[i]->vSimulieren();
            if (fabs(dGlobaleZeit - 3.0) < dTakt/2)
            {
                vecFahrzeuge[i]->dTanken();
            }
            if (itL != ausgabe.end()) {
                std::cout << *vecFahrzeuge[i] << endl;
            }
        }
        l++;
    }
    char c;
    std::cin >> c;
}
*/
