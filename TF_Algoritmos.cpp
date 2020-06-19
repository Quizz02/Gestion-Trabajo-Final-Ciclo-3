#include "stdafx.h"
#include "ABB.h"

string Equipos[3] = { "UPC", "USIL", "CATOLICA" };
char sexo[2] = { 'M','F' };

int main()
{
	srand(time(NULL));
	list<string> filas;
	vector<int> *poses = new vector<int>();

	auto criterio_insercion = [](Datos<int> n1, int n2) {
		return n1.GetDato() < n2;
	};

	auto criterio_insercion_char = [](Datos<char> n1, char n2) {
		return n1.GetDato() < n2;
	};

	auto criterio_string_insercion = [](Datos<string> n1, int n2) {
		int s=0;
		for (int i = 0; i < n1.GetDato().size(); i++) {
			s += n1.GetDato().at(i);
		}
		return s < n2;
	};

	auto impresion = [](Datos<int> x) {
		cout << x.GetDato() << " " <<x.get_indice() << endl;
	};

	auto impresion_char = [](Datos<char> x) {
		cout << x.GetDato() << " " << x.get_indice() << endl;
	};

	auto impresion_string = [](Datos<string> x) {
		cout << x.GetDato() << " " << x.get_indice() << endl;
	};

	auto obtener_posicion = [](Datos<int> datos, auto valor) {
		return datos.GetDato() <= valor;
	};

	int e,op;
	cout << endl << endl;

	Arbol_Binario<int> arbol_entero;
	Arbol_Binario<char> arbol_caracter;
	Arbol_Binario<string> arbol_string;

	for (int i = 0; i < 20; i++) {
		int ent = 17 + rand() % 22;
		char a = sexo[rand() % 2];
		string b = Equipos[rand() % 3];

		arbol_entero.insertar(ent,criterio_insercion);
		arbol_caracter.insertar(a,criterio_insercion_char);
		arbol_string.insertar(b, criterio_string_insercion);
		string ab = to_string(ent) + " " + a + " " + b;
		//cout << endl << ab << endl;
		filas.push_back(ab);
	}
	
	for (auto it : filas) {
		cout << it << endl;
	}
	

	cout << endl << endl;
	arbol_entero.enorden(impresion);
	
	//cout << endl << endl;
	arbol_caracter.enorden(impresion_char);
	//cout << endl << endl;
	arbol_string.enorden(impresion_string);

	arbol_entero.Filtro(25, poses, obtener_posicion);
	
	
	for (int i = 0; i < poses->size(); i++) {
		cout << poses->at(i) << " ";
	}
	cout << endl;
	arbol_entero.Obtener_Datos(poses);
	cout << endl;
	arbol_caracter.Obtener_Datos(poses);
	cout << endl;
	arbol_string.Obtener_Datos(poses);
	/*
	do {
		system("cls");
		Menu(); cin >> op;
		switch (op) {
		case 1:
			break;

		case 2:
			break;

		case 3: 
			system("pause");
			break;

		case 4:
			break;

		case 5: 
			break;

		case 6:
			int op1;

			do {
				system("cls");
				Menu_Filtrado(); cin >> op1;
				switch (op1){
				case 1:
					break;

				case 2:
					break;

				case 3:
					break;

				case 4:
					//arbol->preorden(impresion);
					cout << endl << endl;

					cout << endl << "BUSQUEDA POR INICIO" << endl;
					cin.ignore();
					if (1) {
						char *n = new char[40];
						cout << "Ingrese nombre de la persona: "; cin.getline(n, 40);
						//arbol->Busqueda_Filtro(n, busqueda);
						system("pause");
						break;
					}

				case 5:
					break;

				case 6:
					break;

				case 7:
		
					cout << endl << endl;

					cin.ignore();
					if (1) {
						char *n = new char[40];
						cout << "Ingrese nombre de la persona: "; cin.getline(n, 40);
						//cout << arbol->buscar(n, cr);
						system("pause");
						break;
					}

				case 8:
					break;

				default:
					cout << "Ingrese una opcion correcta. " << endl;
					system("pause");
					break;
				}
			} while (op1 != 8);

			break;

		case 7:
			break;

		case 8:
			//arbol->Guardar();
			break;

		case 9:
			break;

		default:
			cout << "Ingrese una opcion correcta. " << endl; break;
		}

	} while (op != 9);
	*/
	return 0;
}
