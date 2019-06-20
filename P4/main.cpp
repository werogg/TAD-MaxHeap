#include <cstdlib>
#include <vector>

#include "MaxHeap.h"
#include "Mountain.h"
#include "HeapMountainFinder.h"

using namespace std;

/**-----------------------------------------------**
 * |            |    Inserció    |      Cerca      |
 * |            | Small | LLarg  | Small |  LLarg  |
 * |  MaxHeap   | 0.015 | 0.016  | 1.251 | 255.546 | (s)
 **-----------------------------------------------**/
/*
 * Com es un Heap binary, la inserció la fem pel final, i cada cop
 * anem pujant si el pare es menor que l'element inserit. Llavors
 * la complexitat de la inserció és de O(logn).
 * 
 * La busqueda va eliminant elements fins a trobar l'element desitjat.
 * En el pitjor dels casos haurem d'eliminar tots els elements, llavors
 * la complexitat de la funció de cerca és de O(n).
 */
/**
 * Prints the menu.
 */
void printMenu() {
    cout << "Que vols fer?" << endl
            << "1. Carregar un fitxer" << endl
            << "2. Mostrar arbre per ID en ordre" << endl
            << "3. Cercar muntanyes" << endl
            << "4. Visualitzar la profunditat de l'arbre" << endl
            << "5. Sortir" << endl;
}


/**
 * Main function that takes the full control of the app
 * @param argc Unused argument.
 * @param argv Unused argument.
 * @return 0 If program had no execution problems.
 */
int main(int argc, char** argv) {
    int sel_opt; // Option selected variable
    char sel_big; // Big/Small file selected variable
    HeapMountainFinder* bstmf = nullptr; // BSTMountainFinder init
    
    // Loop while sel_opt is not 5 (exit)
    do {
        printMenu();
        cin >> sel_opt;
        
        // Switch between select options
        switch (sel_opt) {
            
            // Option 1 - Load mountain file
            case 1:
            {
                cout << "Quin arxiu vols (P/G)" << endl;
                cin >> sel_big;
                clock_t t; // Clock to calculate time
                t = clock();
                if (sel_big == 'P' || sel_big == 'p')
                    bstmf = new HeapMountainFinder("Mountain_list_small.txt");
                if (sel_big == 'G' || sel_big == 'g')
                    bstmf = new HeapMountainFinder("Mountain_list.txt");
                t=clock()-t;
                
                cout<<"Ha trigat "<<t<<" clicks and "<<(float)t/CLOCKS_PER_SEC<<" segons!"<<endl;
                break;
            }
                
            // Option 2 - Show mountains loaded 40 by 40
            case 2:
                if (bstmf != nullptr) {
                    bstmf->printHeap();
                }
                else cout << "Primer has de crear un arbre amb la opcio 1 del menu!" << endl;
                break;
            
            // Option 3 - Search counter
            case 3:
            {
                if (bstmf != nullptr)
                {
                    clock_t t; // Clock to calculate time
                    t = clock();
                    cout << "N'hi han " << bstmf->searchCounter("cercaMuntanyes.txt") << " muntanyes vàlides a l'arxiu!" << endl;
                    t=clock()-t;
                    cout<<"Ha trigat "<<t<<" clicks and "<<(float)t/CLOCKS_PER_SEC<<" segons!"<<endl;
                }
                else cout << "Primer has de crear un arbre amb la opcio 1 del menu!" << endl;
                break;
            }
            
            // Option 4 - Get maxheap depth
            case 4: {
                cout << "Profunditat del MaxHeap: " << bstmf->depth() << endl;
                break;
            }
                
            // Option 5 - Exit
            case 5:
                break;
        }
        
    } while (sel_opt != 5);
    
    delete bstmf; // Delete the BSTMountainFinder and other generated objects on exit
    
    return 0;
}
