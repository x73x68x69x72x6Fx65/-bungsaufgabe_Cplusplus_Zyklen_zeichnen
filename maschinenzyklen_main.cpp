#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <cwchar>
#include <windows.h>

// zur angenehmeren verwendung von chrono und std --> z.b std::cout wird nicht mehr ben�tigt stattdessen nurnoch cout;
using namespace std;
using namespace chrono;

// erstelle grundlayout zum printen
vector<vector<string>> graph = {
    {" ", "^", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "},
    {" ", "|", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "},
    {"1", "|", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "},
    {"0", "|", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "},
    {" ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-","-", "-", "-", "-","-", "-", "-", "-", "-", "-", ">"},
    {" ", " ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "}
};

vector<int> generateData() {
    // erstelle array mit undefinierter gr��e
    vector<int> array;
    for (int i = 0; i < 33; i++) {
        // weise dem array 22 werte je 1 oder 0 random zu
        array.push_back(rand() % 2);
    }
    // gib daten zur�ck
    return array;
}

void printZyklen() {
    // ignoriere diesen part |
    //                       |
    //                       v
    // vergr��ere die Schrift der Konsole
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 28;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    // 
    // 
    // Ausgabe und wichtiger Part beginnt hier : 
    cout << "\n\n--------- Maschinenzyklen darstellen --> Schleifenuebung ---------\n\n\n";
    // zeichne array
    for (const auto& row: graph) {
        for (string cell: row) {
            cout << cell << " ";
           }
        cout << endl;
    }
}

void zeichneZyklen(const vector<int> data) {
    // loope durch alle daten durch und schreibe diese in die zeichnung
    for (size_t i = 0; i < data.size(); i++) {
        // erkenne lows
        if (data[i] == 0) {
            // setze neue Daten auf h�he 1
            graph[2][i + 2] = " ";
            // setze neue Daten auf h�he 0
            graph[3][i + 2] = "_";
        }
        // erkenne highs
        else if (data[i] == 1) {
            // setze neue Daten auf h�he 1
            graph[2][i + 2] = "-";
            // setze neue Daten auf h�he 0
            graph[3][i + 2] = "|";
        }
        // l�sche alte zeichnung
        system("cls");
        // zeichne neue Daten
        printZyklen();
        // starte verz�gerung
        this_thread::sleep_for(milliseconds(150));
    }
}

int main() {
    // initialisierung von srand --> zufallszahl generator
    srand(static_cast<unsigned>(time(nullptr)));
    // update die Zeichnung mit dem generierten Datenpaket
    zeichneZyklen(generateData());
    return 0;
}
