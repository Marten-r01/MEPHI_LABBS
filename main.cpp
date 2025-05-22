#include <iostream>
#include <vector>
#include <windows.h> // ��� ������ � ��������
#include <conio.h>   // ��� _getch()

#include "Sequence.h"
#include "ArraySequence.h"
#include "ListSequence.h"
#include "ImmutableArraySequence.h"
#include "ImmutableListSequence.h"

// ��������� ��� ������ �������
const int NORMAL_COLOR = 7;      // ����� ����� �� ������ ����
const int SELECTED_COLOR = 112;  // ������ ����� �� ����� ����
const int TITLE_COLOR = 11;      // ����-�������

// ������� ��� ������ � �����������
void setConsoleColor(int color);
void printMenu(int selected);

// ����������� ������ (�������� ��� ���������)
static void handleCreate(std::vector<Sequence<int>*>& seqs);
static void handleAppend(std::vector<Sequence<int>*>& seqs);
static void handlePrintAll(const std::vector<Sequence<int>*>& seqs);
static void handleRemoveSequence(std::vector<Sequence<int>*>& seqs);
static void handleSubsequence(std::vector<Sequence<int>*>& seqs);
static void handleConcat(std::vector<Sequence<int>*>& seqs);
static void handleZip(std::vector<Sequence<int>*>& seqs);
static void handleUnzip(std::vector<Sequence<int>*>& seqs);
static void handleRemoveItem(std::vector<Sequence<int>*>& seqs);

void runUI() {
    std::vector<Sequence<int>*> seqs;
    int selected = 0;
    bool running = true;

    while (running) {
        try {
            system("cls");
            printMenu(selected);

            // ��������� �����
            int key = _getch();
            if (key == 224) { // ����������� ������� (�������)
                key = _getch();
                switch (key) {
                case 72: // �����
                    selected = (selected - 1 + 10) % 10;
                    break;
                case 80: // ����
                    selected = (selected + 1) % 10;
                    break;
                }
            }
            else if (key == 13) { // Enter
                system("cls");
                switch (selected) {
                case 0:
                    handleCreate(seqs);
                    break;
                case 1:
                    handleAppend(seqs);
                    break;
                case 2:
                    handlePrintAll(seqs);
                    break;
                case 3:
                    handleRemoveSequence(seqs);
                    break;
                case 4:
                    handleSubsequence(seqs);
                    break;
                case 5:
                    handleConcat(seqs);
                    break;
                case 6:
                    handleZip(seqs);
                    break;
                case 7:
                    handleUnzip(seqs);
                    break;
                case 8:
                    handleRemoveItem(seqs);
                    break;
                case 9:
                    running = false;
                    break;
                }
                if (running && selected != 9) {
                    std::cout << "\nPress any key to continue...";
                    _getch();
                }
            }
        }
        catch (InvalidArgument()) {
            InvalidArgument();
            std::cout << "\nPress any key to continue...";
            _getch();
        }
    }

    // ������� ������
    for (auto* ptr : seqs) {
        delete ptr;
    }
    seqs.clear();

    system("cls");
    setConsoleColor(NORMAL_COLOR);
    std::cout << "Program finished.\n";
}

void setConsoleColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}


void printMenu(int selected) {
    setConsoleColor(TITLE_COLOR);
    std::cout << "==== SEQUENCE MANAGER ====\n\n";
    setConsoleColor(NORMAL_COLOR);

    const char* menuItems[] = {
        "Create sequence",
        "Append item",
        "Print all sequences",
        "Remove sequence",
        "Get subsequence",
        "Concatenate sequences",
        "Zip sequences",
        "Unzip sequence",
        "Remove item",
        "Exit"
    };

    for (int i = 0; i < 10; i++) {
        if (i == selected) {
            setConsoleColor(SELECTED_COLOR);
            std::cout << "> " << menuItems[i] << " <\n";
            setConsoleColor(NORMAL_COLOR);
        }
        else {
            std::cout << "  " << menuItems[i] << "\n";
        }
    }

    setConsoleColor(NORMAL_COLOR);
    std::cout << "\nUse arrow keys to navigate, Enter to select\n";
}

// ��������� �������-����������� �������� ��� ���������
// (handleCreate, handleAppend � �.�.)
static void handleCreate(std::vector<Sequence<int>*>& seqs) {}
static void handleAppend(std::vector<Sequence<int>*>& seqs) {}
static void handlePrintAll(const std::vector<Sequence<int>*>& seqs) {}
static void handleRemoveSequence(std::vector<Sequence<int>*>& seqs) {}
static void handleSubsequence(std::vector<Sequence<int>*>& seqs) {}
static void handleConcat(std::vector<Sequence<int>*>& seqs) {}
static void handleZip(std::vector<Sequence<int>*>& seqs) { }
static void handleUnzip(std::vector<Sequence<int>*>& seqs) {}
static void handleRemoveItem(std::vector<Sequence<int>*>& seqs) {}