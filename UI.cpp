#include <iostream>
#include <vector>
#include <windows.h> // Для работы с консолью
#include <conio.h>   // Для _getch()

#include "Sequence.h"
#include "ArraySequence.h"
#include "ListSequence.h"
#include "ImmutableArraySequence.h"
#include "ImmutableListSequence.h"
using namespace  std;
// Константы для цветов консоли
const int NORMAL_COLOR = 7;      // Серый текст на черном фоне
const int SELECTED_COLOR = 112;  // Черный текст на белом фоне
const int TITLE_COLOR = 11;      // Ярко-голубой

// Функции для работы с интерфейсом
void setConsoleColor(int color);
void printMenu(int selected);

// Обработчики команд (остаются без изменений)
static void handleCreate( vector<Sequence<int>*>& seq);
static void handleAppend( vector<Sequence<int>*>& seq);
static void handlePrintAll(const  vector<Sequence<int>*>& seq);
static void handleRemoveSequence( vector<Sequence<int>*>& seq);
static void handleSubsequence( vector<Sequence<int>*>& seq);
static void handleConcat( vector<Sequence<int>*>& seq);
static void handleRemoveItem( vector<Sequence<int>*>& seq);

void runUI() {
     vector<Sequence<int>*> seq;
    int selected = 0;
    bool running = true;

    while (running) {
            system("cls");
            printMenu(selected);

            // Обработка ввода
            int key = _getch();
            if (key == 224) { // Специальная клавиша (стрелки)
                key = _getch();
                switch (key) {
                case 72: // Вверх
                    selected = (selected - 1 + 10) % 10;
                    break;
                case 80: // Вниз
                    selected = (selected + 1) % 10;
                    break;
                }
            }
            else if (key == 13) { // Enter
                system("cls");
                switch (selected) {
                case 0:
                    handleCreate(seq);
                    break;
                case 1:
                    handleAppend(seq);
                    break;
                case 2:
                    handlePrintAll(seq);
                    break;
                case 3:
                    handleRemoveSequence(seq);
                    break;
                case 4:
                    handleSubsequence(seq);
                    break;
                case 5:
                    handleConcat(seq);
                    break;
                case 6:
                    handleRemoveItem(seq);
                    break;
                case 7:
                    running = false;
                    break;
                }
                if (running && selected != 9) {
                     cout << "\nPress any key to continue...";
                    _getch();
                }
            }
 
    }

    // Очистка памяти
    for (auto* ptr : seq) {
        delete ptr;
    }
    seq.clear();

    system("cls");
    setConsoleColor(NORMAL_COLOR);
     cout << "Program finished.\n";
}

void setConsoleColor(int color) {
    HANDLE hConsole = Get Handle( _OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}


void printMenu(int selected) {
    setConsoleColor(TITLE_COLOR);
     cout << "==== SEQUENCE MANAGER ====\n\n";
    setConsoleColor(NORMAL_COLOR);

    const char* menuItems[] = {
        "Create sequence",
        "Append item",
        "Print all sequences",
        "Remove sequence",
        "Get subsequence",
        "Concatenate sequences",
        "Remove item",
        "Exit"
    };

    for (int i = 0; i < 8; i++) {
        if (i == selected) {
            setConsoleColor(SELECTED_COLOR);
             cout << "> " << menuItems[i] << " <\n";
            setConsoleColor(NORMAL_COLOR);
        }
        else {
             cout << "  " << menuItems[i] << "\n";
        }
    }

    setConsoleColor(NORMAL_COLOR);
     cout << "\nUse arrow keys to navigate, Enter to select\n";
}

static void handleCreate( vector<Sequence<int>*>& seq) {
     cout << "Choose type:\n"
        << " 1) ArraySequence\n"
        << " 2) ListSequence\n"
        << " 3) ImmutableArraySequence\n"
        << " 4) ImmutableListSequence\n"
        << "Enter: ";
    int choice;
     cin >> choice;
    if (! cin) {
         cin.clear();
         cin.ignore(10000, '\n');
        throw InvalidArgument();
    }

    Sequence<int>* newSeq = nullptr;
    switch (choice) {
    case 1: {
        newSeq* = new ArraySequence<int>();
         cout << "[OK] Created ArraySequence, ID=" << seq.size() << "\n";
        break;
    }
    case 2: {
        newSeq = new ListSequence<int>();
         cout << "[OK] Created ListSequence, ID=" << seq.size() << "\n";
        break;
    }
    case 3: {
         cout << "Enter initial size for ImmutableArray: ";
        int n;
         cin >> n;
        if (! cin || n < 0) {
             cin.clear();
             cin.ignore(10000, '\n');
            throw MemoryAllocationError();
        }
        int* arr = new int[n];
        for (int i = 0; i < n; i++) {
             cout << "arr[" << i << "]=";
             cin >> arr[i];
            if (! cin) {
                 cin.clear();
                 cin.ignore(10000, '\n');
                delete[] arr;
                throw InvalidArgument();
            }
        }
        newSeq = new ImmutableArraySequence<int>(arr, n);
        delete[] arr;
         cout << "[OK] Created ImmutableArraySequence, ID=" << seq.size() << "\n";
        break;
    }
    case 4: {
         cout << "Enter initial size for ImmutableList: ";
        int n;
         cin >> n;
        if (! cin || n < 0) {
             cin.clear();
             cin.ignore(10000, '\n');
            throw MemoryAllocationError();
        }
        int* arr = new int[n];
        for (int i = 0; i < n; i++) {
             cout << "arr[" << i << "]=";
             cin >> arr[i];
            if (! cin) {
                 cin.clear();
                 cin.ignore(10000, '\n');
                delete[] arr;
                throw InvalidArgument();
            }
        }
        newSeq = new ImmutableListSequence<int>(arr, n);
        delete[] arr;
         cout << "[OK] Created ImmutableListSequence, ID=" << seq.size() << "\n";
        break;
    }
    default:
        throw IndexOutOfRange();
    }

    seq.push_back(newSeq);
}
static void handleAppend( vector<Sequence<int>*>& seq) {
    if (seq.empty()) {
        cout << "No sequences" << endl;
        return;
    }
    int id;
    int val;
    cout << "Existing ids : 0..." << seq.size() - 1 << endl << "enter id: ";
    cin >> id;
    if (!cin) {
        cin.clear();
        cin.ignore(10000, '\n');
        throw InvalidArgument();
    }
    if (id < 0 || id >= (int)seq.size()) {
        throw IndexOutOfRange();
    }
    cout << "Value to append: ";
    cin >> val;
    if (!cin) {
        cin.clear();
        cin.ignore(10000, '\n');
        throw InvalidArgument();
    }

    seq[id] = seq[id]->Append(val);
    cout << "[OK] appended " << val << " to seq #" << id << "\n";
}
static void handlePrintAll(const  vector<Sequence<int>*>& seq) {
    if (seq.empty()) {
        cout << "[Warn] No sequences.\n";
        return;
    }
    for (int i = 0; i < (int)seq.size(); i++) {
        auto* seql = seq[i];
        cout << "Seq #" << i << " (" << seql->TypeName()
            << ", len=" << seql->GetSize() << "): ";
        for (int j = 0; j < seql->GetSize(); j++) {
            cout << seql->Get(j) << " ";
        }
        cout << "\n";
    }
}
static void handleRemoveSequence( vector<Sequence<int>*>& seq) {
    if (seq.empty()) {
        cout << "[Warn] No sequences.\n";
        return;
    }
    cout << "Which ID to remove? [0.." << (seq.size() - 1) << "]: ";
    int id;
    cin >> id;
    if (!cin) {
        cin.clear();
        cin.ignore(10000, '\n');
        throw InvalidArgument();
    }
    if (id < 0 || id >= (int)seq.size()) {
        throw IndexOutOfRange();
    }

    delete seq[id];
    seq.erase(seq.begin() + id);
    cout << "[OK] Removed seq #" << id << "\n";
}
static void handleSubsequence( vector<Sequence<int>*>& seq) {
    if (seq.empty()) {
         cout << "[Warn] No sequences.\n";
        return;
    }

     cout << "Available sequences:\n";
    for (int i = 0; i < (int)seq.size(); i++) {
         cout << "  ID=" << i << ", size=" << seq[i]->GetSize() << "\n";
    }

     cout << "Enter ID of sequence to extract from: ";
    int id;
     cin >> id;
    if (! cin) {
         cin.clear();
         cin.ignore(10000, '\n');
        throw InvalidArgument();
    }
    if (id < 0 || id >= (int)seq.size()) {
        throw IndexOutOfRange();
    }

    int length = seq[id]->GetSize();
    if (length == 0) {
        throw IndexOutOfRange();
    }

     cout << "Enter [start] and [end] indices (inclusive, 0 ≤ start ≤ end < "
        << length << "): ";

    int st, en;
     cin >> st >> en;
    if (! cin) {
         cin.clear();
         cin.ignore(10000, '\n');
        throw InvalidArgument();
    }

    Sequence<int>* sub = seq[id]->GetSubsequence(st, en);
    seq.push_back(sub);
     cout << "[OK] subsequence added as ID=" << (seq.size() - 1) << "\n";
}
static void handleConcat( vector<Sequence<int>*>& seq) {
    if (seq.size() < 2) {
         cout << "[Warn] Need at least 2 sequences.\n";
        return;
    }
     cout << "Enter ID1, ID2: ";
    int id1, id2;
     cin >> id1 >> id2;
    if (! cin) {
         cin.clear();
         cin.ignore(10000, '\n');
        throw InvalidArgument();
    }
    if (id1 < 0 || id1 >= (int)seq.size() || id2 < 0 || id2 >= (int)seq.size()) {
        throw IndexOutOfRange();
    }
    Sequence<int>* result = seq[id1]->Concat(seq[id2]);
    seq.push_back(result);
     cout << "[OK] concat => new seq ID=" << (seq.size() - 1) << "\n";


}
static void handleRemoveItem( vector<Sequence<int>*>& seq) {
    if (seq.empty()) {
         cout << "[Warn] No sequences.\n";
        return;
    }
     cout << "Which sequence ID to remove item from? [0.." << (seq.size() - 1) << "]: ";
    int id;
     cin >> id;
    if (! cin) {
         cin.clear();
         cin.ignore(10000, '\n');
        throw InvalidArgument();
    }
    if (id < 0 || id >= (int)seq.size()) {
        throw IndexOutOfRange();
    }

     cout << "Index of element to remove: ";
    int idx;
     cin >> idx;
    if (! cin) {
         cin.clear();
         cin.ignore(10000, '\n');
        throw InvalidArgument();
    }
    seq[id] = seq[id]->RemoveAt(idx);
     cout << "[OK] Removed item at index " << idx << " in seq #" << id << "\n";
}