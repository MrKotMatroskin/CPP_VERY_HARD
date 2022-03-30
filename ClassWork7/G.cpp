#include <iostream>
#include <string.h>
using namespace std;


struct elem {
    char name[256];
    int v;//масса
    int z;//заряд
};

struct reaction {
    char reagent[256];
    char decay[256];
    int indexInElems;
};

int main() {
    int elemCnt = 0;
    cin >> elemCnt;
    elem* elems = new elem[elemCnt];
    for (int i = 0; i < elemCnt; ++i)
    {
        cin >> elems[i].name >> elems[i].v >> elems[i].z;
    }
    int reactCnt = 0;
    cin >> reactCnt;
    reaction* reactions = new reaction[reactCnt];
    for (int i = 0; i < reactCnt; ++i)
    {
        cin >> reactions[i].reagent >> reactions[i].decay;
        reactions[i].indexInElems = -1;
        for (int j = 0; j < elemCnt; ++j)
        {
            if (!strcmp(reactions[i].reagent, elems[j].name))
            {
                reactions[i].indexInElems = j;
                break;
            }
        }
    }

    for (int i = 0; i < reactCnt; ++i)
    {
        bool found = false;
        int v = elems[reactions[i].indexInElems].v;
        int z = elems[reactions[i].indexInElems].z;
        if (!strcmp(reactions[i].decay, "alpha")) {
            v -= 4;
            z -= 2;
        } else if (!strcmp(reactions[i].decay, "beta+")) {
            z -= 1;
        } else if (!strcmp(reactions[i].decay, "beta-")) {
            z += 1;
        }
        for (int j = 0; j < elemCnt; ++j) {
            if (v == elems[j].v && z == elems[j].z) {
                cout << elems[j].name << " ";
                found = true;
                break;
            }
        }
        if (!found)
            cout << "NO DATA ";
    }
    return 0;
}
