#include "Header.h"
#include <fstream>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <random>
#include <vector>

using namespace std;
int m; bool win = false;
BinarySearchTree::BinarySearchTree() : root(nullptr) {}//konstrukrot

BinarySearchTree::~BinarySearchTree() //destruktor
{
    deleteTree(root);
}

void BinarySearchTree::BinarySearchTreeDelet()//jatek kozben valo felszabaditas miatt
{
    deleteTree(root);
}

//fa felszabaditasa
void BinarySearchTree::deleteTree(TreeNode* node) 
{
    if (node != nullptr) 
    {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

//file-bol valo beolvasas
void BinarySearchTree::buildTreeFromFile(const string& filename) 
{
    ifstream file(filename);
    int n;
    file >> n;
    m = n;
    vector<TreeNode*> sortedWords;

    string word;
    for (int i = 0; i < n; i++) 
    {
        file >> word;
        sortedWords.push_back(new TreeNode(word)); // Hozzárendeljük a sorszámot a szavakhoz
    }

    file.close();
    sort(sortedWords.begin(), sortedWords.end(), [](const TreeNode* a, const TreeNode* b) 
        {
        return a->data < b->data; // Rendezzük az összes szót abc-sorrendben
        });

    buildTreeFromSortedWords(sortedWords); // Bináris keresőfa létrehozása rendezett szavakból

    for (TreeNode* node : sortedWords) 
    {
        delete node;
    }
}

//fa felepiteseben van szerepe
TreeNode* BinarySearchTree::buildTree(vector<TreeNode*>& sortedWords, int start, int end) 
{
    if (start > end) 
    {
        return nullptr;
    }

    int mid = (start + end) / 2;
    TreeNode* node = new TreeNode(sortedWords[mid]->data);
    node->left = buildTree(sortedWords, start, mid - 1);
    node->right = buildTree(sortedWords, mid + 1, end);
    return node;
}

//fa felepiteseben van szerepe
void BinarySearchTree::buildTreeFromSortedWords(vector<TreeNode*>& sortedWords) 
{
    root = buildTree(sortedWords, 0, sortedWords.size() - 1);
}

//kiiratas
void BinarySearchTree::printInOrder(TreeNode* node) 
{
    if (node != nullptr)
    {
        printInOrder(node->left);
        cout << node->data << endl;
        printInOrder(node->right);
    }
}
//kiiratas
void BinarySearchTree::printPostOrder(TreeNode* node)
{
    if (node != nullptr)
    {
        printPostOrder(node->left);
        printPostOrder(node->right);
        cout << node->data << endl;
    }
}


void BinarySearchTree::printTree() 
{
    printInOrder(root);
}
void BinarySearchTree::printTree2()
{
    printPostOrder(root);
}

//szavak beszurasaban van szerepe
void BinarySearchTree::insertWord(const string& newWord)
{
    root = insertWordRecursive(root, newWord);
}

//szavak beszurasa
TreeNode* BinarySearchTree::insertWordRecursive(TreeNode* node, const string& newWord)
{
    if (node == nullptr)
    {
        return new TreeNode(newWord);
    }
    if (newWord < node->data)
    {
        // Rekurzív hívás a bal részfára
        node->left = insertWordRecursive(node->left, newWord);
    }
    else if (newWord > node->data)
    {
        // Rekurzív hívás a jobb részfára
        node->right = insertWordRecursive(node->right, newWord);
    }
    return node;
}

//egy szo torleseban van szerepe
bool BinarySearchTree::deleteWord(const string& torlendo)
{
    root = deleteWordRecursive(root, torlendo);
    return root != nullptr;
}

//egy szo torlese
TreeNode* BinarySearchTree::deleteWordRecursive(TreeNode* node, const string& torlendo)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    else if (torlendo < node->data)
    {
        node->left = deleteWordRecursive(node->left, torlendo);
    }
    else if (torlendo > node->data)
    {
        node->right = deleteWordRecursive(node->right, torlendo);
    }
    else
    {
        if (node->left == nullptr)
        {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr)
        {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }
        TreeNode* utod = getMin(node->right);
        // A törlendő csúcs adatjának cseréje az utód adatával
        node->data = utod->data;
        // Rekurzív hívás az utód törlésére a jobb részfában
        node->right = deleteWordRecursive(node->right, utod->data);
    }
    return node;
}


//a legkisebb elem visszateritese / legbaloldalibb elem
TreeNode* BinarySearchTree::getMin(TreeNode* node)
{
    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}


TreeNode* BinarySearchTree::getutod(TreeNode* node)
{
    TreeNode* utodelozo = node;
    TreeNode* utod = node;
    TreeNode* current = node->right; // A követő a jobb ágon lesz

    while (current != nullptr)
    {
        utodelozo = utod;
        utod = current;
        current = current->left; // Az első bal ágon lévő csúcs lesz a követő
    }

    // Ha a követő nem közvetlenül a törlendő csúcs jobb gyermek csúcsa
    if (utod != node->right)
    {
        utodelozo->left = utod->right; // A követőt a jobb oldali részfához csatlakoztatjuk
        utod->right = node->right; // A követőt a törlendő csúcs jobb oldali részfájához csatlakoztatjuk
    }
    return utod;
}

//akasztofa rajzok
void  BinarySearchTree::Design(int hibak)
{
	switch (hibak)
	{
	case 0:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|        0" << endl;
		cout << "\t\t\t|       /|\\" << endl;
		cout << "\t\t\t|        |" << endl;
		cout << "\t\t\t|       / \\" << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;

	case 1:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|        0" << endl;
		cout << "\t\t\t|       /|\\" << endl;
		cout << "\t\t\t|        |" << endl;
		cout << "\t\t\t|         \\" << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
	case 2:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|        0" << endl;
		cout << "\t\t\t|       /|\\" << endl;
		cout << "\t\t\t|        |" << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
	case 3:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|        0" << endl;
		cout << "\t\t\t|       /|\\" << endl;
		cout << "\t\t\t|         " << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
	case 4:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|        0" << endl;
		cout << "\t\t\t|        |\\" << endl;
		cout << "\t\t\t|         " << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
	case 5:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|        0" << endl;
		cout << "\t\t\t|        |  " << endl;
		cout << "\t\t\t|         " << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
	case 6:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|        0" << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|         " << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
	case 7:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|         " << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|         " << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
	default:
		break;
	}
}

//egy szo kereses a faban
bool BinarySearchTree::searchWord(TreeNode* node, const string& word) 
{
    if (node == nullptr) 
    {
        return false;
    }
    else if (node->data == word)
    {
        return true;
    }
    else if (word < node->data) 
    {
        return searchWord(node->left, word);
    }
    else 
    {
        return searchWord(node->right, word);
    }
}


void BinarySearchTree::jatekpanel()
{
    int live = 7;

    string letter;
    string word;
    string tipp = "";

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, m);

    int randomIndex = dis(gen);
    cout << endl << randomIndex << endl;
    TreeNode* randomNode = searchByIndex(randomIndex);

    if (randomNode != nullptr)
    {
        cout << randomNode->data << endl;
    }
    else {
        cout << "Hiba";
    }

    word = randomNode->data;
    system("cls");

    bool help = false;
    bool csalo = true;

    while (live > 0)
    {
        bool tip = true;
        win = true;
        Design(live);
        PrintWord(word, tipp);
        if (help)
        {
            win = false;
            help = false;
        }

        if (win == true)
            break;
        cout << "\n\nHa tudni akarod az elso betut, ird a `help` kifejezest [Az eleted csokkenni fog!]";
        cout << "\nHa szeretnel tippelni, ird a `tipp` kifejezest:" << endl;
        cout << "\t\t\tFONTOS!!!!" << endl;
        cout << "->Ha a szo benne van a szotarba plusz 1 eletet kapzs\n->Ha NINCS benne a szotarba es nem a kitalalando szo akkor 2 eletet VESZTESZ " << endl;
        cout << "\n\nBetu talalgatasok: " << tipp << endl;
        cout << "\n\nIrjon be egy betut: ";
        cin >> letter;

        int b = 0;
        b = letter.size();

        if (b >= 2)//ha valaki csalni probal es tobb mint 2 szot ir be
        {
            if (letter == "help") // ha segistseget kert
            {
                help = true;
                live--;
                cout << "-->\"" << word[0] << "\"<--" << endl;
                letter = word[0];
                system("pause");
            }
            else if (letter == "tipp")
            {
                tip = false;
                string tippeles;
                cout << "\nMi a tipped: ";
                cin >> tippeles;
                if (tippeles != word)
                {
                    if (searchWord(root, tippeles))
                    {
                        if (live < 7)
                        {
                            live++;
                        }
                        cout << "Benne volt a szotarba!" << endl;
                        deleteWord(tippeles);
                        system("pause");
                    }
                    else
                    {
                        cout << "Nem volt benne ez a szo a szotarba!" << endl;
                        live -= 2;
                        system("pause");
                    }
                }
                else
                {
                    win = true;
                    break;
                }
            }
            else
            {
                system("cls");
                csalo = false;
                live = 0;
            }
        }

        if (!csalo)
        {
            cout << "CSALTAL!" << endl;
        }
        else if (tip)
        {
            tipp += letter[0];

            if (word.find(letter) != -1 || help)
            {
                system("cls");
                continue;
            }
            else
            {
                system("cls");
                live--;
            }
        }
        else
        {
            system("cls");
        }

    }

    if (live == 0) 
    {
        cout << "\n\n\n\t\t\t >>>VESZTETTEL!<<<\n\n";
        cout << "A szo : " << word << endl;
    }
    if (live > 0 && csalo) 
    {
        cout << "\n\n\n\t\t\t >>>NYERTEL!<<<\n\n";
        cout << "A szo : " << word << endl;
    }
    cout << "\n\n\n";
    system("pause");
}



//random generalas eseten index alapjan keresunk
TreeNode* BinarySearchTree::searchByIndex(TreeNode* node, int& currentIndex, int targetIndex) 
{
    if (node == nullptr) 
    {
        return nullptr;
    }

    // Először keresünk a bal részfában
    TreeNode* foundNode = searchByIndex(node->left, currentIndex, targetIndex);

    // Ha a keresés már talált egy csúcsot a megfelelő indexen, visszaadjuk azt
    if (foundNode != nullptr) 
    {
        return foundNode;
    }

    if (currentIndex == targetIndex) 
    {
        return node;
    }

    currentIndex++;

    return searchByIndex(node->right, currentIndex, targetIndex);
}

//random szo generalasaban segit
TreeNode* BinarySearchTree::searchByIndex(int targetIndex) 
{
    int currentIndex = 0;
    return searchByIndex(root, currentIndex, targetIndex);
}

//szo kiirasa
int BinarySearchTree::PrintWord(string word, string letter)
{
    for (int i = 0; i < word.size(); i++)
    {
        if (letter.find(word.at(i)) != -1)
        {
            cout << word.at(i) << " ";
        }
        else
        {
            cout << "_ ";
            win = false;
        }
    }
    return 0;
}