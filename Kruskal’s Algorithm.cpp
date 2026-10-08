#include <iostream>
using namespace std;

struct Edge
{
    int u, v, weight;
};

// Find the parent of a vertex
int findParent(int parent[], int x)
{
    if (parent[x] == x)
        return x;

    return findParent(parent, parent[x]);
}

// Join two sets
void unionSet(int parent[], int u, int v)
{
    int parentU = findParent(parent, u);
    int parentV = findParent(parent, v);

    parent[parentV] = parentU;
}

int main()
{
    int n = 4;

    // Edges: {starting vertex, ending vertex, weight}
    Edge edges[] = {
        {0, 1, 2},
        {0, 2, 3},
        {1, 2, 1},
        {1, 3, 4},
        {2, 3, 5}
    };

    int e = 5;

    // Sort edges according to weight
    for (int i = 0; i < e - 1; i++)
    {
        for (int j = 0; j < e - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    int parent[4];

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int totalCost = 0;
    int count = 0;

    cout << "Edges in Minimum Spanning Tree:\n";

    for (int i = 0; i < e && count < n - 1; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        if (findParent(parent, u) != findParent(parent, v))
        {
            cout << u << " - " << v
                 << " : " << edges[i].weight << endl;

            totalCost += edges[i].weight;

            unionSet(parent, u, v);

            count++;
        }
    }

    cout << "\nMinimum Cost = " << totalCost << endl;

    return 0;
}
