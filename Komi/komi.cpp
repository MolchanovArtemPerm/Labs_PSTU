#pragma once
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int n;
int** help;
int* result;
int*** matrix;
int win_width;
int win_height;
const int maxSize = 20;
int amountVerts;

template<class T>
class Graph
{
	vector<T> vertList;
	vector<T> labelList;
	bool* visitedVerts = new bool[vertList.size()];
	public:
	int Matrix_temp[maxSize][maxSize] = { 0 };
	Graph();
	~Graph();
	void DrawGraph();
	void InsertEdge(const T& vertex1, const T& vertex2, int weight);
	void InsertVertex(const T& vertex);
	void DeleteVertex();
	int GetVertPos(const T& vertex);
	int GetAmountVerts();
	int GetAmountEdges();
	int GetWeight(const T& vertex1, const T& vertex2);
	bool Empty();
	bool Full();
	vector<T> GetNeighbors(const T& vertex);
	void Print();
};

int R;
struct VertCoord
{
	int x, y;
};

VertCoord vertC[20];
Graph <int> graph;

void Answer(int*** matrix, int n, int** help, int* path)
{
	for (int l = 0; l < n; l++)
	{
		for (int i = 0; i < n; i++)
		{
			int min = 1000000;
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] && min > *matrix[i][j])
				{
					min = *matrix[i][j];
				}
			}
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j])
				{
					*matrix[i][j] -= min;
				}
			}
		}
		for (int j = 0; j < n; j++)
		{
			int min = 1000000;
			for (int i = 0; i < n; i++)
			{
				if (matrix[i][j] && min > *matrix[i][j])
				{
					min = *matrix[i][j];
				}
			}
			for (int i = 0; i < n; i++)
			{
				if (matrix[i][j]) {
					*matrix[i][j] -= min;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				help[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] && !*matrix[i][j])
				{
					int hmin = 1000000;
					int vmin = 1000000;
					for (int l = 0; l < n; l++)
					{
						if (l != i && matrix[l][j] && hmin > *matrix[l][j])
							hmin = *matrix[l][j];
					}
					for (int l = 0; l < n; l++)
					{
						if (l != j && matrix[i][l] && vmin > *matrix[i][l])
							vmin = *matrix[i][l];
					}
					help[i][j] = hmin + vmin;
				}
			}
		}
		int mc = 0, mi = 0, mj = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] && mc < help[i][j])
				{
					mc = help[i][j];
					mi = i;
					mj = j;
				}
			}
		}
		path[mi] = mj;
		for (int i = 0; i < n; i++)
		{
			matrix[i][mj] = nullptr;
		}
		for (int i = 0; i < n; i++)
		{
			matrix[mi][i] = nullptr;
		}
		matrix[mj][mi] = nullptr;
	}
}

void Preparation(int***& matrix, int& n, int**& help, int*& result)
{
	n = amountVerts;
	help = new int*[n];
	result = new int[n];
	matrix = new int**[n];
	for (int i = 0; i <= n; i++)
	{
		help[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int*[n];
		for (int j = 0; j < n; j++)
		{
			if (graph.Matrix_temp[i][j] == 0)
			{
				matrix[i][j] = nullptr;
				continue;
			}
			matrix[i][j] = new int(graph.Matrix_temp[i][j]);
		}
	}
}


void OutResult(int*** matrix, int n, int** help, int* result)
{
	Preparation(matrix, n, help, result);
	int s = 0;
	Answer(matrix, n, help, result);
	cout << "\nОтрезки путей: ";
	for (int i = 0, j = 0; i < n; i++)
	{
		j = result[i];
		cout << i + 1 << " -> " << j + 1 << '\t';
		s += graph.Matrix_temp[i][j];
	}
	cout << endl;
	cout << "\nКратчайший путь: ";
	int temp = 0;
	for (int l = 0; l < n;)
	{
		for (int i = 0, j = 0; i < n; i++)
		{
			if (temp == 0 || i + 1 == temp)
			{
				if (temp == 0) cout << i + 1;
				j = result[i];
				temp = j + 1;
				if (temp > 0)	cout << " -> " << temp;
				l++;
			}
		}
	}
	cout << "\nРасстояние: " << s;
	cout << endl;
}


template<class T>
vector<T> Graph<T>::GetNeighbors(const T& vertex)
{
	vector<T> NeighborsList; // создание списка соседей
	int vertPos = this->GetVertPos(vertex); // вычисление позиции vertex в матрице смежности
	if (vertPos != (-1))
	{
		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i)
		{
			if (this->Matrix_temp[vertPos][i] != 0 && this->Matrix_temp[i][vertPos] != 0) // вычисление соседей
			{
				NeighborsList.push_back(this->vertList[i]);
			}
		}
	}
	return NeighborsList;
}



template<class T>
void Graph<T>::InsertVertex(const T& vertex)
{
	if (!this->Full())
	{
		this->vertList.push_back(vertex);
	}
	else {
		cout << "Граф уже заполнен. Невозможно добавить новую вершину " << endl;
		return;
	}
}

template<class T>
void Graph<T>::DeleteVertex()
{
	this->vertList.pop_back();
}


template<class T>
int Graph<T>::GetAmountEdges()
{
	int amount = 0; // обнуляем счетчик
	if (!this->Empty()) // проверяем, что граф не пуст
	{ 
		for (int i = 0, vertListSize = this->vertList.size();i < vertListSize; ++i)
		{
			for (int j = 0; j < vertListSize; ++j)
			{
				if (this->Matrix_temp[i][j] == this->Matrix_temp[j][i] && this->Matrix_temp[i][j] != 0) // находим рёбра
				{
					amount += 1; // считаем количество рёбер
				} 
			}
		}
		return (amount / 2); // приводим счетчик к корректному результату и возвращаем его
	}
	else
		return 0; // если граф пуст, возвращаем 0
}

template<class T>
int Graph<T>::GetWeight(const T& vertex1, const T& vertex2)
{
	if (!this->Empty())
	{
		int vertPos1 = GetVertPos(vertex1);
		int vertPos2 = GetVertPos(vertex2);
		return Matrix_temp[vertPos1][vertPos2];
	}
	return 0;
}

template<class T>
int Graph<T>::GetAmountVerts()
{
	return this->vertList.size();
}

template<class T>
bool Graph<T>::Empty()
{
	if (this->vertList.size() != 0)
	{
		return false;
	}
	else
		return true;
}

template<class T>
bool Graph<T>::Full()
{
	return (vertList.size() == maxSize);
}

template <class T>
int Graph<T>::GetVertPos(const T& vertex)
{
	for (int i = 0; i < this->vertList.size(); ++i)
	{
		if (this->vertList[i] == vertex)
		{
			return i;
		}
	}
	return -1;
}

template<class T>
Graph<T>::Graph()
{
	for (int i = 0; i < maxSize; ++i)
	{
		for (int j = 0; j < maxSize; ++j)
		{
			this->Matrix_temp[i][j] = 0;
		}
	}
}

template<class T>
Graph<T>::~Graph()
{
}


Graph <int> MakeGraph()
{
	Graph <int> graph; // создание графа, содержащего вершины с номерами целого типа
	int amountEdges, sourceVertex, targetVertex, edgeWeight; // создание необходимых для ввода графа переменных
	cout << "Введите количество вершин графа: "; cin >> amountVerts; cout << endl; // ввод количества рёбер графа в переменную amountVerts
	cout << "Введите количество ребер графа: "; cin >> amountEdges; cout << endl; // ввод количества рёбер графа в переменную amountEdges
	for (int i = 1; i <= amountVerts; ++i)
	{
		int* vertPtr = &i; // запоминаем адрес вершины с помощью указателя
		graph.InsertVertex(*vertPtr); //передаём ссылку на вершину в функцию InsertVertex; происходит вставка вершины в вектор вершин
	}
	for (int i = 0; i < amountEdges; ++i)
	{
		cout << "Исходная вершина: "; cin >> sourceVertex; cout << endl; // ввод исходной вершины
		int* sourceVertPtr = &sourceVertex; // запоминаем адрес исходной вершины
		cout << "Конечная вершина: "; cin >> targetVertex; cout << endl; // ввод вершины, до которой будет идти ребро от исходной вершины
		int* targetVertPtr = &targetVertex; // запоминаем адрес конечной вершины (до которой будет идти ребро от исходной вершины)

		cout << "Вес ребра: "; cin >> edgeWeight; cout << endl; // ввод числового значения веса ребра в переменную edgeWeight
		graph.InsertEdge(*sourceVertPtr, *targetVertPtr, edgeWeight); // вставка ребра весом edgeWeight между исходной и конечной вершинами
	}
	cout << endl;
	return graph;
}

template<class T>
void Graph<T>::InsertEdge(const T& vertex1, const T& vertex2, int weight)
{
	if (this->GetVertPos(vertex1) != (-1) && this->GetVertPos(vertex2) != (-1))
	{
		int vertPos1 = GetVertPos(vertex1);
		int vertPos2 = GetVertPos(vertex2);
		if (this->Matrix_temp[vertPos1][vertPos2] != 0 && this->Matrix_temp[vertPos2][vertPos1] != 0)
		{
			cout << "Ребро между вершинами уже есть" << endl;
			return;
		}
		else
		{
			this->Matrix_temp[vertPos1][vertPos2] = weight;
			this->Matrix_temp[vertPos2][vertPos1] = weight;
		}
	}
	else
	{
		cout << "Обеих вершин (или одной из них) нет в графе " << endl;
		return;
	}
}

template<class T>
void Graph<T>::Print()
{
	if (!this->Empty())
	{
		cout << "Матрица смежности графа: " << endl;
		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i)
		{
			cout << this->vertList[i] << " ";
			for (int j = 0; j < vertListSize; ++j)
			{
				cout << " " << this->Matrix_temp[i][j] << " ";
			}
			cout << endl;
		}

	}

}

void SetCoord(int i, int n)
{
	int Rtemp;
	int x0 = win_width / 2;
	int y0 = win_height / 2;
	if (win_width > win_height)
	{
		R = 5 * (win_height / 13) / n;
		Rtemp = win_height / 2 - R - 10;
	}
	else
	{
		R = 5 * (win_width / 13) / n;
		Rtemp = win_width / 2 - R - 10;
	}
	float theta = 2.0f * 3.1415926f * float(i) / float(n);
	float y1 = Rtemp * cos(theta) + y0;
	float x1 = Rtemp * sin(theta) + x0;
	vertC[i].x = x1;
	vertC[i].y = y1;
}

void DrawCircle(int x, int y, int R) // Рисуем круги
{
	glColor3f(1.0f, 1.0f, 1.0f);
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y1 = R * cos(theta) + y;
		x1 = R * sin(theta) + x;;
		glVertex2f(x1, y1);
	}
	glEnd();
	glColor3f(0.1f, 0.1f, 0.1f);
	float x2, y2;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y2 = R * cos(theta) + y;
		x2 = R * sin(theta) + x;
		glVertex2f(x2, y2);
	}
	glEnd();
}

void DrawText(int nom, int x1, int y1) // Рисуем текст
{
	GLvoid* font = GLUT_BITMAP_HELVETICA_18;
	string s = to_string(nom);
	glRasterPos2i(x1 - 5, y1 - 5);
	for (int j = 0; j < s.length(); j++)
	{
		glutBitmapCharacter(font, s[j]);
	}
}

void DrawVertex(int n) // Рисуем вершины
{
	for (int i = 0; i < n; i++) 
	{
		DrawCircle(vertC[i].x, vertC[i].y, R);
		DrawText(i + 1, vertC[i].x, vertC[i].y);
	}
}

void DrawLine(int text, int x0, int y0, int x1, int y1) // Рисуем ребра неориентированного взвешенного графа
{
	glClearColor(0.0, 0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);
	glEnd();
	DrawText(text, (x0 + x1) / 2 + 10, (y0 + y1) / 2 + 10);
}


template<class T>
void Graph<T>::DrawGraph() // Рисуем граф
{
	int n = vertList.size();
	for (int i = 0; i < n; i++)
	{
		SetCoord(i, n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int a = Matrix_temp[i][j];
			if (a != 0)
			{
				DrawLine(a, vertC[i].x, vertC[i].y, vertC[j].x, vertC[j].y);
			}
		}
	}
	DrawVertex(n);
}

void Change(int w, int h)
{
	win_width = w;
	win_height = h;
	glViewport(0, 0, (GLsizei)win_width, (GLsizei)win_height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLdouble)win_width, 0, (GLdouble)win_height);
	glutPostRedisplay();
}

void DrawMenuText(string text, int x1, int y1) // Рисуем текст меню
{
	GLvoid* font = GLUT_BITMAP_HELVETICA_18;
	string s = text;
	glRasterPos2i(x1, y1);
	for (int j = 0; j < s.length(); j++)
	{
		glutBitmapCharacter(font, s[j]);
	}
}

void DrawMenu() // Рисуем меню
{
	int height = win_height;

	glColor3f(0.0f, 0.5f, 1.0f);
	glBegin(GL_QUADS);
	glVertex2i(10, win_height - 50);
	glVertex2i(10, win_height - 100);
	glVertex2i(150, win_height - 100);
	glVertex2i(150, win_height - 50);
	glEnd();
	glColor3d(0, 0, 0);
	DrawMenuText("New vertex",30, win_height - 80);

	glColor3f(0.0f, 0.5f, 1.0f);
	glBegin(GL_QUADS);
	glVertex2i(10, win_height - 150);
	glVertex2i(10, win_height - 200);
	glVertex2i(150, win_height - 200);
	glVertex2i(150, win_height - 150);
	glEnd();
	glColor3d(0, 0, 0);
	DrawMenuText("Delete vertex", 25, win_height - 180);


	glColor3f(0.0f, 0.5f, 1.0f);
	glBegin(GL_QUADS);
	glVertex2i(10, win_height - 250);
	glVertex2i(10, win_height - 300);
	glVertex2i(150, win_height - 300);
	glVertex2i(150, win_height - 250);
	glEnd();
	glColor3d(0, 0, 0);
	DrawMenuText("Matrix", 50, win_height - 280);

	glColor3f(0.0f, 0.5f, 1.0f);
	glBegin(GL_QUADS);
	glVertex2i(10, win_height - 350);
	glVertex2i(10, win_height - 400);
	glVertex2i(150, win_height - 400);
	glVertex2i(150, win_height - 350);
	glEnd();
	glColor3d(0, 0, 0);
	DrawMenuText("Result", 50, win_height - 380);

	glColor3f(0.0f, 0.5f, 1.0f);
	glBegin(GL_QUADS);
	glVertex2i(10, win_height - 450);
	glVertex2i(10, win_height - 500);
	glVertex2i(150, win_height - 500);
	glVertex2i(150, win_height - 450);
	glEnd();
	glColor3d(0, 0, 0);
	DrawMenuText("New Graph", 35, win_height - 480);
}

void MouseClick(int btn, int stat, int x, int y)
{
	if (stat == GLUT_DOWN)
	{
		if (x > 10 && x < 150 && y >  50 && y < 100)
		{
			int sourceVertex;
			int targetVertex;
			int edgeWeight;
			cout << "Исходная вершина: "; cin >> sourceVertex; cout << endl;
			int* sourceVertPtr = &sourceVertex;
			cout << "Конечная вершина: "; cin >> targetVertex; cout << endl;
			int* targetVertPtr = &targetVertex;
			if (sourceVertex > amountVerts || targetVertex > amountVerts)
			{
				amountVerts++;
				int* vertPtr = &amountVerts;
				graph.InsertVertex(*vertPtr);
			}
			cout << "Вес ребра: "; cin >> edgeWeight; cout << endl;
			graph.InsertEdge(*sourceVertPtr, *targetVertPtr, edgeWeight);
		}
		if (x > 10 && x < 150 && y > 150 && y < 200)
		{
			int sourceVertex;
			int targetVertex;
			int edgeWeight;
			cout << "Введите вершину: "; cin >> sourceVertex; cout << endl;
			int* sourceVertPtr = &sourceVertex;
			if (sourceVertex == amountVerts)
			{
				amountVerts--;
				graph.DeleteVertex();
			}
			else cout << "Невозможно удалить вершину \n";
		}
		if (x > 10 && x < 150 && y >  250 && y < 300)
		{
			graph.Print();
		}
		if (x > 10 && x < 150 && y >  350 && y < 400)
		{
			OutResult(matrix, n, help, result);
		}
		if (x > 10 && x < 150 && y >  450 && y < 500)
		{
			graph = MakeGraph();
		}
	}
	glutPostRedisplay();
}

void Display()
{
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, win_width, 0, win_height); //ставим начало координат в левый нижний угол
	glViewport(0, 0, win_width, win_height);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	graph.DrawGraph();
	DrawMenu();
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL,"RUS");
	glutInit(&argc, argv);
	graph = MakeGraph();
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1270, 720);
	glutCreateWindow("Graph");
	win_width = glutGet(GLUT_WINDOW_WIDTH);
	win_height = glutGet(GLUT_WINDOW_HEIGHT);
	glutDisplayFunc(Display);
	glutReshapeFunc(Change);
	glutMouseFunc(MouseClick);
	glutMainLoop();
	return 0;
}
