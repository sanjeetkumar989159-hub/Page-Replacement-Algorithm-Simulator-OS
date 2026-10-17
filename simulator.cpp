
#include <iostream>
using namespace std;

int *pages, *frames;
int n, f;

int fifoFault, fifoHit;
int lruFault, lruHit;
int optFault, optHit;

// ================= FIFO FUNCTION =================
void FIFO()
{
    int page_fault = 0, page_hits = 0;
    int i, j, k = 0, found;

    for (i = 0; i < f; i++)
        frames[i] = -1;

    cout << "\n--- FIFO Page Replacement ---\n";
    cout << "Page\tFrames\t\tStatus\n";

    for (i = 0; i < n; i++)
    {
        found = 0;

        for (j = 0; j < f; j++)
        {
            if (frames[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            frames[k] = pages[i];
            k = (k + 1) % f;
            page_fault++;
        }
        else
            page_hits++;

        cout << pages[i] << "\t";

        for (j = 0; j < f; j++)
        {
            if (frames[j] == -1)
                cout << "- ";
            else
                cout << frames[j] << " ";
        }

        cout << "\t\t" << (found ? "Hit" : "Page Fault") << endl;
    }

    fifoFault = page_fault;
    fifoHit = page_hits;

    cout << "Total Page Faults: " << page_fault << endl;
    cout << "Total Page Hits: " << page_hits << endl;
    cout << "Hit Ratio: " << (double)page_hits * 100 / n << "%" << endl;
    cout << "Fault Ratio: " << (double)page_fault * 100 / n << "%" << endl;
}

// ================= LRU FUNCTION =================
void LRU()
{
    int page_fault = 0, page_hits = 0;
    int i, j, found, pos, least;
    int *lastUsed = new int[f];

    for (i = 0; i < f; i++)
    {
        frames[i] = -1;
        lastUsed[i] = -1;
    }

    cout << "\n--- LRU Page Replacement ---\n";
    cout << "Page\tFrames\t\tStatus\n";

    for (i = 0; i < n; i++)
    {
        found = 0;

        for (j = 0; j < f; j++)
        {
            if (frames[j] == pages[i])
            {
                found = 1;
                lastUsed[j] = i;
                break;
            }
        }

        if (found == 0)
        {
            pos = -1;

            for (j = 0; j < f; j++)
            {
                if (frames[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            if (pos == -1)
            {
                least = 0;

                for (j = 1; j < f; j++)
                {
                    if (lastUsed[j] < lastUsed[least])
                        least = j;
                }

                pos = least;
            }

            frames[pos] = pages[i];
            lastUsed[pos] = i;
            page_fault++;
        }
        else
            page_hits++;

        cout << pages[i] << "\t";

        for (j = 0; j < f; j++)
        {
            if (frames[j] == -1)
                cout << "- ";
            else
                cout << frames[j] << " ";
        }

        cout << "\t\t" << (found ? "Hit" : "Page Fault") << endl;
    }

    lruFault = page_fault;
    lruHit = page_hits;

    cout << "Total Page Faults: " << page_fault << endl;
    cout << "Total Page Hits: " << page_hits << endl;
    cout << "Hit Ratio: " << (double)page_hits * 100 / n << "%" << endl;
    cout << "Fault Ratio: " << (double)page_fault * 100 / n << "%" << endl;

    delete[] lastUsed;
}

// ================= OPTIMAL FUNCTION =================
void Optimal()
{
    int page_fault = 0, page_hits = 0;
    int i, j, k, found, pos, farthest, next;

    for (i = 0; i < f; i++)
        frames[i] = -1;

    cout << "\n--- Optimal Page Replacement ---\n";
    cout << "Page\tFrames\t\tStatus\n";

    for (i = 0; i < n; i++)
    {
        found = 0;

        for (j = 0; j < f; j++)
        {
            if (frames[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            pos = -1;

            for (j = 0; j < f; j++)
            {
                if (frames[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            if (pos == -1)
            {
                farthest = -1;

                for (j = 0; j < f; j++)
                {
                    next = n + 1;

                    for (k = i + 1; k < n; k++)
                    {
                        if (frames[j] == pages[k])
                        {
                            next = k;
                            break;
                        }
                    }

                    if (next > farthest)
                    {
                        farthest = next;
                        pos = j;
                    }
                }
            }

            frames[pos] = pages[i];
            page_fault++;
        }
        else
            page_hits++;

        cout << pages[i] << "\t";

        for (j = 0; j < f; j++)
        {
            if (frames[j] == -1)
                cout << "- ";
            else
                cout << frames[j] << " ";
        }

        cout << "\t\t" << (found ? "Hit" : "Page Fault") << endl;
    }

    optFault = page_fault;
    optHit = page_hits;

    cout << "Total Page Faults: " << page_fault << endl;
    cout << "Total Page Hits: " << page_hits << endl;
    cout << "Hit Ratio: " << (double)page_hits * 100 / n << "%" << endl;
    cout << "Fault Ratio: " << (double)page_fault * 100 / n << "%" << endl;
}

// ================= COMPARISON FUNCTION =================
void Compare()
{
    cout << "\n========== PERFORMANCE COMPARISON ==========\n";
    cout << "Algorithm\tPage Faults\tPage Hits\tHit Ratio\tFault Ratio\n";

    cout << "FIFO\t\t" << fifoFault << "\t\t" << fifoHit
         << "\t\t" << (double)fifoHit * 100 / n << "%"
         << "\t\t" << (double)fifoFault * 100 / n << "%" << endl;

    cout << "LRU\t\t" << lruFault << "\t\t" << lruHit
         << "\t\t" << (double)lruHit * 100 / n << "%"
         << "\t\t" << (double)lruFault * 100 / n << "%" << endl;

    cout << "Optimal\t\t" << optFault << "\t\t" << optHit
         << "\t\t" << (double)optHit * 100 / n << "%"
         << "\t\t" << (double)optFault * 100 / n << "%" << endl;
}

// ================= MAIN FUNCTION =================
int main()
{
    int i;

    cout << "Enter number of pages: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of pages!\n";
        return 1;
    }

    pages = new int[n];

    cout << "Enter reference string: ";

    for (i = 0; i < n; i++)
        cin >> pages[i];

    cout << "Enter number of frames: ";
    cin >> f;

    if (f <= 0)
    {
        cout << "Invalid number of frames!\n";
        delete[] pages;
        return 1;
    }

    frames = new int[f];

    FIFO();
    LRU();
    Optimal();
    Compare();

    delete[] pages;
    delete[] frames;

    return 0;
}
