#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
using namespace std;


// map structure
typedef struct {
    int dx, dy;
} Offsets;

typedef struct {
    int x, y;
    int dir;
} Items;

enum directions {E, S, SE, NE, SW, W, N, NW};


// initialize variable
Offsets navigation[8];
stack<Items> route;
string mazeFileName = "maze.txt";
vector<vector<int>> maze;
vector<vector<int>> mark;


// function initialization
void initialize(int&, int&);
void initialize_mark(int, int);
void navigate();
void path(int, int);
void showMaze(int, int);
void ShowMazeAfterTraverse(int, int);
bool path_recursive(int, int, int&, int&);


// operator overloading
ostream& operator<<(ostream&, Items&);
template<class T>
ostream& operator<<(ostream&, stack<T>&);


// main driver code
int main() {
    int width;
    int length;
    initialize(width, length);
    initialize_mark(width,length);
    navigate();
    showMaze(width, length);
    path(width, length);
    ShowMazeAfterTraverse(width, length);
    //cout << path_recursive(1, 1, width, length) << endl;
    cout << "end" << endl;
    return 0;   
}

/*********************************************************** function declaration ***********************************************/

/* initialize */
/**********************************************************************************
 * @brief initialize the map by reading text file, the format of the text file    *
 * should be width length tuple in the first row, and the map in the further row. *
 * then we create vectors of vectors to initialize the map with given text file   *
 *                                                                                *
 * @param w takes the map width as reference                                      *
 * @param l takes the map length as reference                                     *
 **********************************************************************************/
void initialize(int& w, int& l) {
    ifstream in_file(mazeFileName);

    if(!in_file.is_open())
        cerr << "Cannot open the given filename.";
    else {
        in_file >> w;
        in_file >> l;

        maze.clear();
        vector<int> tempRow;
        char temp;

        for(int i = -1; i <=w; i++)
            tempRow.push_back(3);

        maze.push_back(tempRow);
        
        for(int y = 1; y <= l; y++) {
            tempRow.clear();
            tempRow.push_back(3);
            for(int x = 1; x <= w; x++) {
                in_file >> temp;
                if(x == w && y == l)
                    tempRow.push_back(2);
                else 
                    tempRow.push_back(temp - '0');
            }
            tempRow.push_back(3);
            maze.push_back(tempRow);
        }

        tempRow.clear();
        for(int i = -1; i <=w; i++) 
            tempRow.push_back(3);

        maze.push_back(tempRow);
    }
    in_file.close();
}


/* initialize_mark*/
/****************************************************************
 * @brief this initialize the identical map but with all entries*
 * of 0 for the use of marking visited grid of the maze         *
 *                                                              *
 * @param w takes the map width as variable                     *
 * @param l takes the map length as variable                    *
 ****************************************************************/
void initialize_mark(int w, int l) {
    vector<int> tempRow;
    for(int i = -1; i <= w; i++) {
        tempRow.push_back(1);
    }
    mark.push_back(tempRow);

    for(int i = 1; i <= l; i++) {
        tempRow.clear();
        tempRow.push_back(1);
        for(int j = 1; j <= w; j++)
            tempRow.push_back(0);
        tempRow.push_back(1);
        mark.push_back(tempRow);
    }

    tempRow.clear();

    for(int i = -1; i <= w; i++) {
        tempRow.push_back(1);
    }
    mark.push_back(tempRow);
}


/* navigate*/
/******************************************************
 * @brief this function sets the navigation directions*
 *                                                    *
 ******************************************************/
void navigate() {
   navigation[E].dx = 1;  navigation[E].dy = 0;
   navigation[SE].dx = 1; navigation[SE].dy = 1;
   navigation[S].dx = 0;  navigation[S].dy = 1;
   navigation[SW].dx = -1;navigation[SW].dy = 1;
   navigation[W].dx = -1; navigation[W].dy = 0;
   navigation[NW].dx = -1;navigation[NW].dy = -1;
   navigation[N].dx = 0;  navigation[N].dy = -1;
   navigation[NE].dx = 1; navigation[NE].dy = -1;
}


/*showMaze*/
/*****************************************************************
 * @brief This shows the whole map with numerical representation *
 * where 0 stands for trailable path                             *
 *       1 stands for untrailable path                           *
 *       2 stands for the exit.                                  *
 *                                                               *
 * @param w takes map width as variable                          *
 * @param l takes map length as variable                         *
 *****************************************************************/
void showMaze(int w, int l) {
    for (int y = 0; y <= l + 1; y++) {
        for (int x = 0; x <= w + 1; x++) {
            cout << maze[y][x] << " ";
        }
        cout << endl;
    }
}


/*ShowMazeAfterTraverse*/
/**********************************************************
 * @brief This function has identical purpose as show maze*
 * but since we modified the map if there is way out so we*
 * make the map graphicalize by denoting                  *
 * 0 into ' '                                             *
 * 1 into '//'                                            *
 * 2 into '.  '                                           *
 * 3 into '##'                                            *
 * @param w takes map width as variable                   *
 * @param l takes map length as variable                  *
 **********************************************************/
void ShowMazeAfterTraverse(int w, int l) {
    for (int y = 0; y <= l + 1; y++) {
        for (int x = 0; x <= w + 1; x++) {
            switch(maze[y][x])
            {
                case 0:
                    cout << "  ";
                    break;
                case 1:
                    cout << "//";
                    break;
                case 2:
                    cout << ". ";
                    break;
                case 3:
                    cout << "##";
            }
        }
        cout << endl;
    }
}


/* path */
/****************************************************************
 * @brief This function uses iterative method to find whether   *
 * there is way out to the maze                                 *
 *                                                              *
 * @param w takes the map width as variable                     *
 * @param l takes the map length as variable                    * 
 ****************************************************************/
void path(int w, int l) {
    int x, y, dir;
    Items temp;
    temp.x = 1;
    temp.y = 1;
    temp.dir = E;
    mark[1][1] = 1;
    route.push(temp);
    cout << "pushed in: " << temp << endl;

    while(!route.empty()) {
        temp = route.top();
        cout << "popped out: " << temp << endl;
        route.pop();
        x = temp.x;
        y = temp.y;
        dir = temp.dir;

        while (dir < 8) {
            int new_x = x + navigation[dir].dx;
            int new_y = y + navigation[dir].dy;

            if ((new_x == w) && (new_y == l)) {
                Items current;
                current.x = x;
                current.y = y;
                current.dir = dir;
                cout << "Success path: \n";
                cout << route;
                cout << current;
                cout << "  " << new_y << "," << "   " << new_x << endl;
                return;
            }

            if ((!maze[new_y][new_x]) && (!mark[new_y][new_x])) { 
                mark[new_y][new_x] = 1;
                temp.x = x;
                temp.y = y;
                temp.dir = dir;
                route.push(temp);
                cout  << "pushed in: " << temp << endl;
                x = new_x;
                y = new_y;
                dir = E;
            }
            else
                dir++;
        }
    }
    cout << "No path in maze out.\n"; 
}


ostream& operator<<(ostream& os, Items& item) {
    maze[item.y][item.x] = 2;
    os << "  " << item.y << "," << "   " << item.x << ", ";
    switch (item.dir)
    {
    case directions::E:
        os << 'E' << endl;
        break;
    case directions::SE:
        os << "SE" << endl;
        break;
    case directions::S:
        os << "S" << endl;
        break;
    case directions::SW:
        os << "SW" << endl;
        break;
    case directions::W:
        os << "W" << endl;
        break;
    case directions::NW:
        os << "NW" << endl;
        break;
    case directions::N:
        os << "N" << endl;
        break;
    case directions::NE:
        os << "NE" << endl;
        break;
    }
    return os;
}

template<class T>
ostream& operator<<(ostream& os, stack<T>& s) {
    int sum = s.size();
    Items temp_item;
    stack<Items> temp_stack;
    for (int i = 1; i <= sum; i++) {
        temp_item = s.top();
        temp_stack.push(temp_item);
        s.pop();
    }
    for (int i = 1; i <= sum; i++) {
        os << temp_stack.top();
        temp_stack.pop();
    }
    return os;
}

/*path_recursive*/
/**************************************************************
 * @brief this function uses recursive and DFS method to find *
 * whether there is way out to the maze.                      *
 *                                                            *
 * @param x takes the parameter of current col                *
 * @param y takes the parameter of current row                *
 * @param w takes the reference of the maze width             *
 * @param l takes the reference of the maze length            *
 * @return true if path is found to the exit                  *
 * @return false if path isn't found                          *
 **************************************************************/
bool path_recursive(int x, int y, int& w, int& l) {
    Items current;
    current.x = x;
    current.y = y;
    current.dir = E;
    route.push(current);
    mark[current.y][current.x] = 1;
    int count = 8;

    Items newWay;
    while(count--) {
        newWay.x = current.x + navigation[current.dir].dx;
        newWay.y = current.y + navigation[current.dir].dy;
        current.dir += 1;
        if(newWay.x == w && newWay.y == l) {
            cout << "found" << endl;
            cout << route;
            return true;
        }
        if(!maze[newWay.y][newWay.x] && !mark[newWay.y][newWay.x]) {
            if(path_recursive( newWay.x, newWay.y, w, l))
                return true;
            else 
                route.pop();
        }
    }
    return false;
}





