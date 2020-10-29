// RBTreeHW.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include "RBTree.h"
#include "RBTreeNode.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";
	RBTree tree = RBTree();
	RBTreeNode(5).insert(&tree);
	RBTreeNode(8).insert(&tree);
	RBTreeNode(3).insert(&tree);
	RBTreeNode(4).insert(&tree);
	RBTreeNode(4).insert(&tree);
	RBTreeNode(15).insert(&tree);
	RBTreeNode(1).insert(&tree);
	RBTreeNode(7).insert(&tree);
	RBTreeNode(9).insert(&tree);
	RBTreeNode(2).insert(&tree);
	RBTreeNode(11).insert(&tree);
	RBTreeNode(6).insert(&tree);
	RBTreeNode(10).insert(&tree);

	tree.printTree();
	cout << tree.find(1) << endl;
}

// Spuštění programu: Ctrl+F5 nebo nabídka Ladit > Spustit bez ladění
// Ladění programu: F5 nebo nabídka Ladit > Spustit ladění

// Tipy pro zahájení práce:
//   1. K přidání nebo správě souborů použijte okno Průzkumník řešení.
//   2. Pro připojení ke správě zdrojového kódu použijte okno Team Explorer.
//   3. K zobrazení výstupu sestavení a dalších zpráv použijte okno Výstup.
//   4. K zobrazení chyb použijte okno Seznam chyb.
//   5. Pokud chcete vytvořit nové soubory kódu, přejděte na Projekt > Přidat novou položku. Pokud chcete přidat do projektu existující soubory kódu, přejděte na Projekt > Přidat existující položku.
//   6. Pokud budete chtít v budoucnu znovu otevřít tento projekt, přejděte na Soubor > Otevřít > Projekt a vyberte příslušný soubor .sln.
