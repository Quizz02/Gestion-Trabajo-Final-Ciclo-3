#pragma once
#include "ABB.h"

class Tabla {
private:
	vector<Arbol_Binario<int>> vector_entero;
	vector<Arbol_Binario<char>> vector_caracter;
	vector<Arbol_Binario<string>> vector_string;
	list<string> filas;
	vector<int> *indices;
	vector<string> conversion_f;
	string nombres_columnas;
	string num_columnas;

public:
	Tabla() { indices = new vector<int>(); nombres_columnas = "Edad\tSexo\tEquipo\t"; num_columnas = "0\t0\t0\t"; }

	void Generacion_Tabla(function<bool(Datos<int>, int)> c_i, function<bool(Datos<char>, int)> c_c, function<bool(Datos<string>, int)> c_s) {
		Generar_Tabla(vector_entero, vector_caracter,vector_string,conversion_f, c_i, c_c, c_s);
	}

	void CargarDatos() {
		string a;
		cout << "Ingrese nombre del archivo a cargar: "; cin >> a;
		Cargar_Datos(a,vector_entero, vector_caracter, vector_string, conversion_f);
	}

	void Borrar_Datos() {
		Borrar_Arboles(vector_entero);
		Borrar_Arboles(vector_caracter);
		Borrar_Arboles(vector_string);
	}

	void Inicio_Tabla(function<bool(Datos<int>, int)> criterio_insercion, function<bool(Datos<char>, int)> criterio_insercion_char, function<bool(Datos<string>, int)> criterio_string_insercion, function<void(Datos<int>)> impresion,
		function<void(Datos<char>)> impresion_char, function<void(Datos<string>)> impresion_string, function<bool(Datos<int>, int)> obtener_mayor, function<bool(Datos<int>, int)> obtener_menor, function<bool(Datos<int>, int)> obtener_igual,
		function<bool(Datos<int>, int)> inicia_con, function<bool(Datos<int>, int)> finaliza_con, function<bool(Datos<int>, int)> no_contiene, function<bool(Datos<int>, int)> contiene, function<bool(Datos<string>, string)> obtener_igual_str,
		function<bool(Datos<string>, string)> obtener_distintos_str, function<bool(Datos<string>, string)> obtener_mayor_str, function<bool(Datos<string>, string)> obtener_menor_str, function<bool(Datos<string>, string)> inicia_con_str,
		function<bool(Datos<string>, string)> finaliza_con_str, function<bool(Datos<string>, string)> no_contiene_str, function<bool(Datos<string>, string)> contiene_str, function<bool(Datos<char>, char)> obtener_igual_char,
		function<bool(Datos<char>, char)> obtener_distinto_char, function<bool(Datos<char>, char)> obtener_menor_char, function<bool(Datos<char>, char)> obtener_mayor_char)
	{
		int e, op;
		Console::ForegroundColor = ConsoleColor::DarkGreen;
		
		//MENU DE COMANDOS 
		do {
			Actualizar_Fila(filas, conversion_f);
			system("cls");
			Menu(); cin >> op;
			switch (op) {
			case 1:
				system("cls");
				int elige;
				cout << "1. Ingresar datos manualmente. " << endl;
				cout << "2. Ingresar datos automaticamente. " << endl;
				cout << "Ingrese opcion: "; cin >> elige;

				if (elige == 1) {
					int op2;
					do {
						system("cls");
						Menu_Columnas(); cin >> op2;
						if (op2 != 4) {
							string ab;
							cout << endl << "Ingrese nombre de la columna a agregar: "; cin >> ab;
							nombres_columnas += "\t" + ab;
						}
						switch (op2) {
						case 1:
							Agregar_Columna_int_manual(vector_entero, conversion_f, criterio_insercion, filas, num_columnas);
							system("pause");
							break;
						case 2:
							Agregar_Columna_char_manual(vector_caracter, conversion_f, criterio_insercion_char, filas, num_columnas);
							system("pause");
							break;
						case 3:
							Agregar_Columna_str_manual(vector_string, conversion_f, criterio_string_insercion, filas, num_columnas);
							system("pause");
							break;
						case 4:
							break;
						default:
							cout << "Ingrese una opcion correcta. " << endl;
							system("pause");
							break;
						}
					} while (op2 != 4);
				}

				if (elige == 2) {
					int op2;
					do {
						system("cls");
						Menu_Columnas(); cin >> op2;
						if (op2 != 4) {
							string ab;
							cout << endl << "Ingrese nombre de la columna a agregar: "; cin >> ab;
							nombres_columnas += "\t" + ab;
						}
						switch (op2) {
						case 1:
							Agregar_Columna_int_automatico(vector_entero, conversion_f, criterio_insercion, filas, num_columnas);
							cout << endl << "Los datos han sido creados correctamente. " << endl;
							system("pause");
							break;
						case 2:
							Agregar_Columna_char_automatico(vector_caracter, conversion_f, criterio_insercion_char, filas, num_columnas);
							cout << endl << "Los datos han sido creados correctamente. " << endl;
							system("pause");
							break;
						case 3:
							Agregar_Columna_str_automatico(vector_string, conversion_f, criterio_string_insercion, filas, num_columnas);
							cout << endl << "Los datos han sido creados correctamente. " << endl;
							system("pause");
							break;
						case 4:
							break;
						default:
							cout << "Ingrese una opcion correcta. " << endl;
							system("pause");
							break;
						}
					} while (op2 != 4);
				}
				break;

			case 2:
				int op_a;
				if (1) {
					system("cls");
					cout << "Seleccione tipo de dato a mostrar en pantalla. " << endl;
					cout << "1. Columnas de enteros. " << endl;
					cout << "2. Columnas de caracteres. " << endl;
					cout << "3. Columnas de cadenas. " << endl;
					cout << "Ingrese opcion: "; cin >> op_a;
					system("cls");

					cout << nombres_columnas << endl;
					cout << num_columnas << endl << endl;
					for (auto it : filas) {
						cout << it << endl;
					}
					cout << endl;

					int p;
					cout << "Ingrese posicion de la columna a mostrar: "; cin >> p;
					system("cls");
					if (op_a == 1) {
						Mostrar_columna_indice(vector_entero, p, impresion);
					}
					if (op_a == 2) {
						Mostrar_columna_indice(vector_caracter, p, impresion_char);
					}
					if (op_a == 3) {
						Mostrar_columna_indice(vector_string, p, impresion_string);
					}
					system("pause");
				}
				break;

			case 3:
				int op1;

				do {
					system("cls");
					Menu_Filtrado(); cin >> op1;
					switch (op1) {
					case 1:
						system("cls");
						if (1) {
							int op_aux;
							cout << "1. Valor numerico" << endl;
							cout << "2. Valor caracter" << endl;
							cout << "3. Cadena" << endl;
							cout << "Ingrese opcion: "; cin >> op_aux;

							cout << endl;
							cout << nombres_columnas << endl;
							cout << num_columnas << endl << endl;
							for (auto it : filas) {
								cout << it << endl;
							}
							cout << endl;

							int pos;
							cout << "Ingrese numero de columna de entero a buscar: ";
							cin >> pos;
							cout << "Ingrese un valor para buscar sus mayores: ";
							if (op_aux == 1) {
								int n;
								cin >> n;
								cout << endl;
								Mostrar_Filtro(vector_entero, conversion_f, obtener_mayor, n, pos);
								system("pause");
							}

							if (op_aux == 2) {
								char n;
								cin >> n;
								n = towupper(n);
								cout << endl;
								Mostrar_Filtro(vector_caracter, conversion_f, obtener_mayor_char, n, pos);
								system("pause");
							}

							if (op_aux == 3) {
								string n;
								cin >> n;
								string a;
								for (auto it : n) {
									a += towupper(it);
								}

								cout << endl;
								Mostrar_Filtro(vector_string, conversion_f, obtener_mayor_str, a, pos);
								system("pause");
							}
						}
						break;

					case 2:
						system("cls");
						if (1) {
							int op_aux;
							cout << "1. Valor numerico" << endl;
							cout << "2. Valor caracter" << endl;
							cout << "3. Cadena" << endl;
							cout << "Ingrese opcion: "; cin >> op_aux;

							cout << endl;
							cout << nombres_columnas << endl;
							cout << num_columnas << endl << endl;
							for (auto it : filas) {
								cout << it << endl;
							}
							cout << endl;

							int pos;
							cout << "Ingrese numero de columna de entero a buscar: ";
							cin >> pos;
							cout << "Ingrese un valor para buscar sus menores: ";
							if (op_aux == 1) {
								int n;
								cin >> n;
								cout << endl;
								Mostrar_Filtro(vector_entero, conversion_f, obtener_menor, n, pos);
								system("pause");
							}

							if (op_aux == 2) {
								char n;
								cin >> n;
								n = towupper(n);
								cout << endl;
								Mostrar_Filtro(vector_caracter, conversion_f, obtener_menor_char, n, pos);
								system("pause");
							}

							if (op_aux == 3) {
								string n;
								cin >> n;
								string a;
								for (auto it : n) {
									a += towupper(it);
								}

								cout << endl;
								Mostrar_Filtro(vector_string, conversion_f, obtener_menor_str, a, pos);
								system("pause");
							}
						}
						break;

					case 3:
						system("cls");
						if (1) {
							int op_aux;
							cout << "1. Valor numerico" << endl;
							cout << "2. Valor caracter" << endl;
							cout << "3. Cadena" << endl;
							cout << "Ingrese opcion: "; cin >> op_aux;

							cout << endl;
							cout << nombres_columnas << endl;
							cout << num_columnas << endl << endl;
							for (auto it : filas) {
								cout << it << endl;
							}
							cout << endl;

							int pos;
							cout << "Ingrese numero de columna a buscar: ";
							cin >> pos;
							cout << "Ingrese un valor para buscar sus iguales: ";
							if (op_aux == 1) {
								int n;
								cin >> n;
								cout << endl;
								Mostrar_Filtro(vector_entero, conversion_f, obtener_igual, n, pos);
								system("pause");
							}

							if (op_aux == 2) {
								char n;
								cin >> n;
								n = towupper(n);
								cout << endl;
								Mostrar_Filtro(vector_caracter, conversion_f, obtener_igual_char, n, pos);
								system("pause");
							}
							if (op_aux == 3) {
								string n, a;
								cin >> n;
								for (auto it : n) {
									a += towupper(it);
								}
								cout << endl;
								Mostrar_Filtro(vector_string, conversion_f, obtener_igual_str, a, pos);
								system("pause");
							}
						}

						break;

					case 4:
						system("cls");
						if (1) {
							int op_aux;
							cout << "1. Valor numerico" << endl;
							cout << "2. Cadena" << endl;
							cout << "Ingrese opcion: "; cin >> op_aux;

							cout << endl;
							cout << nombres_columnas << endl;
							cout << num_columnas << endl << endl;
							for (auto it : filas) {
								cout << it << endl;
							}
							cout << endl;

							int pos;
							cout << "Ingrese numero de columna a buscar: ";
							cin >> pos;
							cout << "Ingrese un valor para buscar: ";
							if (op_aux == 1) {
								int n;
								cin >> n;
								cout << endl;
								Mostrar_Filtro(vector_entero, conversion_f, inicia_con, n, pos);
								system("pause");
							}

							if (op_aux == 2) {
								string n, a;
								cin >> n;
								for (auto it : n) {
									a += towupper(it);
								}
								cout << endl;
								Mostrar_Filtro(vector_string, conversion_f, inicia_con_str, a, pos);
								system("pause");
							}
						}

						break;
					case 5:
						system("cls");
						if (1) {
							int op_aux;
							cout << "1. Valor numerico" << endl;
							cout << "2. Cadena" << endl;
							cout << "Ingrese opcion: "; cin >> op_aux;

							cout << endl;
							cout << nombres_columnas << endl;
							cout << num_columnas << endl << endl;
							for (auto it : filas) {
								cout << it << endl;
							}
							cout << endl;

							int pos;
							cout << "Ingrese numero de columna a buscar: ";
							cin >> pos;
							cout << "Ingrese un valor para buscar: ";
							if (op_aux == 1) {
								int n;
								cin >> n;
								cout << endl;
								Mostrar_Filtro(vector_entero, conversion_f, finaliza_con, n, pos);
								system("pause");
							}

							if (op_aux == 2) {
								string n, a;
								cin >> n;
								for (auto it : n) {
									a += towupper(it);
								}
								cout << endl;
								Mostrar_Filtro(vector_string, conversion_f, finaliza_con_str, a, pos);
								system("pause");
							}
						}
						break;

					case 6:

						system("cls");
						if (1) {
							int op_aux;
							cout << "1. Valor numerico" << endl;
							cout << "2. Cadena" << endl;
							cout << "Ingrese opcion: "; cin >> op_aux;

							cout << endl;
							cout << nombres_columnas << endl;
							cout << num_columnas << endl << endl;
							for (auto it : filas) {
								cout << it << endl;
							}
							cout << endl;

							int pos;
							cout << "Ingrese numero de columna a buscar: ";
							cin >> pos;
							cout << "Ingrese un valor para buscar: ";
							if (op_aux == 1) {
								int n;
								cin >> n;
								cout << endl;
								Mostrar_Filtro(vector_entero, conversion_f, contiene, n, pos);
								system("pause");
							}

							if (op_aux == 2) {
								string n, a;
								cin >> n;
								for (auto it : n) {
									a += towupper(it);
								}
								cout << endl;
								Mostrar_Filtro(vector_string, conversion_f, contiene_str, a, pos);
								system("pause");
							}
						}
						break;

					case 7:

						system("cls");
						if (1) {
							int op_aux;
							cout << "1. Valor numerico" << endl;
							cout << "2. Cadena" << endl;
							cout << "Ingrese opcion: "; cin >> op_aux;

							cout << endl;
							cout << nombres_columnas << endl;
							cout << num_columnas << endl << endl;
							for (auto it : filas) {
								cout << it << endl;
							}
							cout << endl;

							int pos;
							cout << "Ingrese numero de columna a buscar: ";
							cin >> pos;
							cout << "Ingrese un valor para buscar: ";
							if (op_aux == 1) {
								int n;
								cin >> n;
								cout << endl;
								Mostrar_Filtro(vector_entero, conversion_f, no_contiene, n, pos);
								system("pause");
							}

							if (op_aux == 2) {
								string n, a;
								cin >> n;
								for (auto it : n) {
									a += towupper(it);
								}
								cout << endl;
								Mostrar_Filtro(vector_string, conversion_f, no_contiene_str, a, pos);
								system("pause");
							}
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

			case 4:
				system("cls");

				if (1) {
					int op_aux;
					cout << "1. Valor numerico" << endl;
					cout << "2. Valor caracter" << endl;
					cout << "3. Cadena" << endl;
					cout << "Ingrese opcion: "; cin >> op_aux;
					cout << endl;
					cout << nombres_columnas << endl;
					for (auto it : filas) {
						cout << it << endl;
					}

					int pos;
					cout << endl << "Ingrese numero de columna a buscar: "; cin >> pos;
					cout << endl;
					if (op_aux == 1) {
						int aux1;
						cout << "1. Pos-orden" << endl;
						cout << "2. Pre-orden" << endl;
						cout << "3. En-orden" << endl;
						cout << "Ingrese opcion: "; cin >> aux1;
						Ordenar_Todo(vector_entero, conversion_f, aux1, pos);
					}

					if (op_aux == 2) {
						int aux1;
						cout << "1. Pos-orden" << endl;
						cout << "2. Pre-orden" << endl;
						cout << "3. En-orden" << endl;
						cout << "Ingrese opcion: "; cin >> aux1;
						Ordenar_Todo(vector_caracter, conversion_f, aux1, pos);
					}

					if (op_aux == 3) {
						int aux1;
						cout << "1. Pos-orden" << endl;
						cout << "2. Pre-orden" << endl;
						cout << "3. En-orden" << endl;
						cout << "Ingrese opcion: "; cin >> aux1;
						Ordenar_Todo(vector_string, conversion_f, aux1, pos);
					}
					cout << endl;
				}
				system("pause");
				break;

			case 5:
				if (1) {
					system("cls");
					string n;
					cout << "Ingrese nombre del archivo: "; cin >> n;
					Guardar(filas, n);
					cout << "Se ha guardado correctamente. " << endl;
					system("pause");
				}
				break;

			case 6:
				break;
			default:
				cout << "Ingrese una opcion correcta. " << endl; break;
			}

		} while (op != 6);
	}

};

class Controladora {
private:
	vector<Tabla> gestor;

public:
	Controladora() {}
	
	void Inicio(function<bool(Datos<int>, int)> criterio_insercion, function<bool(Datos<char>, int)> criterio_insercion_char, function<bool(Datos<string>, int)> criterio_string_insercion, function<void(Datos<int>)> impresion,
		function<void(Datos<char>)> impresion_char, function<void(Datos<string>)> impresion_string, function<bool(Datos<int>, int)> obtener_mayor, function<bool(Datos<int>, int)> obtener_menor, function<bool(Datos<int>, int)> obtener_igual,
		function<bool(Datos<int>, int)> inicia_con, function<bool(Datos<int>, int)> finaliza_con, function<bool(Datos<int>, int)> no_contiene, function<bool(Datos<int>, int)> contiene, function<bool(Datos<string>, string)> obtener_igual_str,
		function<bool(Datos<string>, string)> obtener_distintos_str, function<bool(Datos<string>, string)> obtener_mayor_str, function<bool(Datos<string>, string)> obtener_menor_str, function<bool(Datos<string>, string)> inicia_con_str,
		function<bool(Datos<string>, string)> finaliza_con_str, function<bool(Datos<string>, string)> no_contiene_str, function<bool(Datos<string>, string)> contiene_str, function<bool(Datos<char>, char)> obtener_igual_char,
		function<bool(Datos<char>, char)> obtener_distinto_char, function<bool(Datos<char>, char)> obtener_menor_char, function<bool(Datos<char>, char)> obtener_mayor_char) {
		int op;
		Console::ForegroundColor = ConsoleColor::DarkGreen;
		do {
			system("cls");
			cout << "-------------MENU PRINCIPAL------------" << endl << endl;
			cout << "1. Ingresar Tabla para una base de datos. " << endl;
			cout << "2. Acceder a una tabla. " << endl;
			cout << "3. Salir. " << endl;
			cout << "Ingrese opcion: "; cin >> op;
			cout << endl;
			switch (op) {
			case 1:
				if(1){
					system("cls");
					Tabla aux;
					int op_a;
					cout << "1. Generar datos aleatorios. " << endl;
					cout << "2. Cargar un archivo existente. " << endl;
					cout << "Ingrese opcion: "; cin >> op_a;
					if (op_a == 1) {
						aux.Generacion_Tabla(criterio_insercion, criterio_insercion_char, criterio_string_insercion);
					}

					if (op_a == 2) {
						system("cls");
						aux.CargarDatos();
					}
					gestor.push_back(aux);
				}
				break;

			case 2:
				if (gestor.size() > 0) {
					int pos;
					cout << "La base de datos tiene " << gestor.size() << " tablas. " << endl << endl;
					cout << "Tablas disponibles: " << endl << endl;
					for (int i = 0; i < gestor.size(); i++) {
						cout <<"Tabla " <<i << "\t";
					}
					cout <<endl << endl << "Ingrese el numero de tabla que desea mostrar: "; cin >> pos;

					gestor.at(pos).Inicio_Tabla(criterio_insercion, criterio_insercion_char, criterio_string_insercion, impresion, impresion_char, impresion_string, obtener_mayor,
						obtener_menor, obtener_igual, inicia_con, finaliza_con, no_contiene, contiene, obtener_igual_str, obtener_distintos_str, obtener_mayor_str,
						obtener_menor_str, inicia_con_str, finaliza_con_str, no_contiene_str, contiene_str, obtener_igual_char, obtener_distinto_char, obtener_menor_char, obtener_mayor_char);
				}
				else {
					cout << "No ha introducido ninguna tabla para realizar esta accion. " << endl;
				}
				break;

			case 3:
					for (size_t i = 0; i < gestor.size(); i++) {
						gestor.at(i).Borrar_Datos();
					}
				break;
			
			default:
				cout << "Ingrese una opcion correcta. " << endl;

			}
		} while (op != 3);
	}

};
