#include "MatrixWDigraph.h"
int infinity = 2147483647;


/* Constructor */
MatrixWDigraph::MatrixWDigraph(const int vertexNum) {
    n = vertexNum;
    e = 0;
    distance = new int[n];
    predecessor = new int[n];
    adjacency_matrix = new int*[n];
    asp_matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        distance[i] = infinity;
        predecessor[i] = i;
        adjacency_matrix[i] = new int[n];
        asp_matrix[i] = new int[n];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (i == j)
                adjacency_matrix[i][j] = 0;
            else 
                adjacency_matrix[i][j] = infinity;
        }
    }
}


/* destructor */
MatrixWDigraph::~MatrixWDigraph() {
    delete[] distance;
    delete[] predecessor;
    delete[] adjacency_matrix;
    delete[] asp_matrix;
}


/* insert edge*/
void MatrixWDigraph::insertEdge(const int u, const int v, const int length) {
    e++;
    adjacency_matrix[u][v] = length;
}


/*show adjacent matrix*/
void MatrixWDigraph::showAdjMatrix() const {
    cout << "  ";
    for(int i = 0 ; i < n; i++)
        cout << setw(5) << i;
    for(int i = 0; i < n; i++) {
        cout << endl << setw(3) << i;
        for(int j = 0; j < n; j++) {
            if(adjacency_matrix[i][j] == infinity) 
                cout << "  INF" << endl;
            else 
                cout << setw(5) << adjacency_matrix[i][j];
        }
    }
    cout << endl;
}


/*  */
void MatrixWDigraph::showDict(const int s, const int x) const
{
    int p;
    stack<int> routine;
    // Vertex selected
    if (s == -1) cout << "         ---      ";
    else cout << setw(11) << s << "       ";
    // Distance
    for (int i = 0; i < n; i++) {
        if (distance[i] == infinity) cout << "  inf";
        else cout << setw(5) << distance[i];
    }
    // Routine & Length
    p = predecessor[x];
    routine.push(x);
    routine.push(p);
    while (distance[p] != 0 && predecessor[p] != p) {
        p = predecessor[p];
        routine.push(p);
    }

    cout << "    " << routine.top();
    routine.pop();
    while (!routine.empty()) {
        cout << " --> " << routine.top();
        routine.pop();
    }
    if (distance[x] < infinity) cout << ", " << distance[x];
    else cout << ", " << "inf";
    cout << endl;
}


/**/
void MatrixWDigraph::Dijkstra(const int v) {
    int c;
    bool *s = new bool[n];
    for(int i = 0; i < n; i++) {
        s[i] = false;
        distance[i] = adjacency_matrix[v][i];
        predecessor[i] = v;
    }

    cout << " Iter  Vertex selected";
    for (int i = 0; i < n; i++) cout << setw(5) << i;
    cout << "   Routine & Length" << endl;

    s[v] = true;
    distance[v] = 0;
    c = -1;

    for(int i = 0; i < n - 1; i++) {
        int u;
        int greedy_min_dist = infinity;
        for(int w = 0; w < n; w++) {
            if (!s[w] && distance[w] < greedy_min_dist) {
                u = w;
                greedy_min_dist = distance[w];
            }

            else if (!s[w] && distance[w] == infinity && greedy_min_dist == infinity) {
                u = w;
            }
        }

        cout << setw(4) << i;
        showDict(c, u);

        s[u] = true;
        for(int w = 0; w < n; w++) {
            if(!s[w] && adjacency_matrix[u][w] != infinity) {
                if(distance[w] == infinity) {
                    distance[w] = distance[u] + adjacency_matrix[u][w];
                    predecessor[w] = u;
                }

                else if (distance[w] > distance[u] + adjacency_matrix[u][w]) {
                    distance[w] = distance[u] + adjacency_matrix[u][w];
                    predecessor[w] = u;
                }
            }
        }
        c = u;
    }
    cout << endl;
}


/**/
void MatrixWDigraph::Bellman_Ford(const int v) {
    bool *s = new bool[n];
    int *previous_distance = new int[n];
    stack<int> node_traversed;

    cout << "  k";
    for(int i = 0 ; i < n; i++)
        cout << setw(5) << i;
    cout << endl;

    cout << "  1";
    for(int i = 0; i < n; i++) {
        distance[i] = adjacency_matrix[v][i];
        previous_distance[i] = adjacency_matrix[v][i];
        if (distance[i] == infinity) {
            s[i] = false;
            cout << "  INF";
        }

        else {
            s[i] = true;
            cout << setw(5) << distance[i];
        }
    }
    cout << endl;

    for(int k = 2; k < n; k++) {
        cout << setw(3) << k;
        for(int u = 0; u < n; u++) {
            if (u != v) {
                for(int i = 0; i < n; i++) {
                    if(!s[i])
                        continue;
                    if(adjacency_matrix[i][u] < infinity && distance[u] > previous_distance[i] + adjacency_matrix[i][u]) {
                        distance[u] = previous_distance[i] + adjacency_matrix[i][u];
                        if(!s[u])
                            node_traversed.push(u);
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(distance[i] == infinity)
                cout << "  INF";
            else 
                cout << setw(5) << distance[i];
            previous_distance[i] = distance[i];
        }
        cout << endl;

        while (!node_traversed.empty()) {
            s[node_traversed.top()] = true;
            node_traversed.pop();
        }
    }
    cout << endl;
}


/**/
void MatrixWDigraph::Floyd() {
    char *matrix_label;

    cout << setw(3) << "A-1";
    for(int i = 0; i < n; i++)
        cout << setw(4) << i;
    cout << endl;

    for(int i = 0; i < n; i++) {
        cout << setw(3) << i;
        for(int j = 0; j < n; j++) {
            asp_matrix[i][j] = adjacency_matrix[i][j];
            if(asp_matrix[i][j] == infinity)
                cout << setw(4) << "INF";
            else 
                cout << setw(4) << asp_matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;



    for(int k = 0; k < n; k++) {
        matrix_label = new char[5];
        sprintf(matrix_label, "A%d", k);
        cout << setw(3) << matrix_label;
        for(int i = 0; i < n ; i++)
            cout << setw(4) << i;
        cout << endl;
        delete[] matrix_label;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(asp_matrix[i][k] != infinity && asp_matrix[k][j] != infinity && asp_matrix[i][j] > asp_matrix[i][k] + asp_matrix[k][j]) {
                    asp_matrix[i][j] =  asp_matrix[i][k] + asp_matrix[k][j];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cout << setw(3) << i;
            for(int j = 0; j < n; j++) {
                if (asp_matrix[i][j] == infinity)
                    cout << setw(4) << "INF";
                else 
                    cout << setw(4) << asp_matrix[i][j];
            }
            cout << endl;
        }

        cout << endl;
    }
}