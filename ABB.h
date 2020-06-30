#pragma once
#include "CDatos.h"

string Equipos[3] = { "UPC", "USIL", "CATOLICA" };
string sexo[2] = { "M","F" };
string abecedario[26] = { "A", "B", "C", "D", "E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };

template<class G>
class Arbol_Binario {
private:
	int cantidad;
	template<class G>
	class Nodo { //COMPOSICION INNER CLASS
	public:
		Nodo<G> * derecha;
		Nodo<G> * izquierda;
		Datos<G> dato;

		Nodo(Datos<G> da) {
			dato = da;
			derecha = izquierda = nullptr;
		}
	};

	Nodo<G> *raiz;

	void insertar(Nodo<G> *& nodo, Datos<G>& valor, function<bool(Datos<G>, int)> criterio) {
		if (nodo == nullptr) {
			nodo = new Nodo<G>(valor);
		}
		else if (criterio(valor, nodo->dato.get_indice())) {
			insertar(nodo->izquierda, valor, criterio);
		}
		else {
			insertar(nodo->derecha, valor, criterio);
		}
	}

	void enorden_indice(Nodo<G> * nodo, vector<int>&indice) {
		if (nodo == nullptr)return;
		else {
			enorden_indice(nodo->izquierda, indice);
			indice.push_back(nodo->dato.get_indice());
			enorden_indice(nodo->derecha, indice);
		}
	}

	void preorden_indice(Nodo<G> * nodo, vector<int>&indice) {
		if (nodo == nullptr)return;
		else {
			indice.push_back(nodo->dato.get_indice());
			preorden_indice(nodo->izquierda, indice);
			preorden_indice(nodo->derecha, indice);
		}
	}

	void posorden_indice(Nodo<G> * nodo, vector<int>&indice) {
		if (nodo == nullptr)return;
		else {
			posorden_indice(nodo->izquierda, indice);
			posorden_indice(nodo->derecha, indice);
			indice.push_back(nodo->dato.get_indice());
		}
	}

	void borrar_todo(Nodo<G> * nodo) {
		if (nodo != nullptr) {
			borrar_todo(nodo->izquierda);
			borrar_todo(nodo->derecha);
			delete nodo;
		}
	}

	void Filtro(Nodo<G>*&nodo, G dato, vector<int>*&vecto, function<bool(Datos<G>, G)>criterio) { //FILTRO PARA MOSTRAR SEGUN CRITERIOS
		if (nodo == nullptr)return;
		Filtro(nodo->izquierda, dato, vecto, criterio);
		if (criterio(nodo->dato, dato)) {
			vecto->push_back(nodo->dato.get_indice());
		}
		Filtro(nodo->derecha, dato, vecto, criterio);
	}

	void enorden(Nodo<G> * nodo, function<void(Datos<G>)> criterio_impresion) {
		if (nodo == nullptr)return;
		else {
			enorden(nodo->izquierda, criterio_impresion);
			criterio_impresion(nodo->dato);
			enorden(nodo->derecha, criterio_impresion);
		}
	}

public:
	Arbol_Binario() { raiz = nullptr; cantidad = 0; }
	~Arbol_Binario() {}
	void insertar(Datos<G> v, function<bool(Datos<G>, int)> criterio) {
		v.Set_Indice(cantidad);
		cantidad++;
		insertar(raiz, v, criterio);
	}

	void enorden(function <void(Datos<G>)>criterio_impresion) {
		enorden(raiz, criterio_impresion);
	}

	void Filtro(G dato, vector<int>*&vecto, function<bool(Datos<G>, G)>criterio) {
		Filtro(raiz, dato, vecto, criterio);
	}

	void borrar_todo() {
		borrar_todo(raiz);
	}

	void enorden_indice(vector<int>&indice) {
		enorden_indice(raiz, indice);
	}

	void preorden_indice(vector<int>&indice) {
		preorden_indice(raiz, indice);
	}

	void posorden_indice(vector<int>&indice) {
		posorden_indice(raiz, indice);
	}

	int Get_Cantidad() { return cantidad; }
};

void Menu() {
	cout << "1. Incersion de columnas y datos. " << endl;
	cout << "2. Mostrar datos. " << endl;
	cout << "3. Filtrado de datos por columnas. " << endl;
	cout << "4. Ordenamiento de datos por columnas. " << endl;
	cout << "5. Guardar datos en un fichero. " << endl;
	cout << "6. Salir. " << endl;
	cout << "Opcion a elegir: ";
}

void Menu_Filtrado() {
	cout << "1. Filtrar por el mayor. " << endl;
	cout << "2. Filtrar por el menor. " << endl;
	cout << "3. Filtrar si es igual a. " << endl;
	cout << "4. Inicia con. " << endl;
	cout << "5. Finaliza con. " << endl;
	cout << "6. Esta contenido en. " << endl;
	cout << "7. No esta contenido en. " << endl;
	cout << "8. Salir. " << endl;
	cout << "Opcion a elegir: ";
}

void Menu_Columnas() {
	cout << "1.Insertar una columna de numeros. " << endl;
	cout << "2.Insertar una columna de caracteres. " << endl;
	cout << "3.Insertar una columna de letras." << endl;
	cout << "4.Salir. " << endl;
	cout << "Ingrese: ";
}

void Generacion_Codigo(string &a) {
	string aux;

	for (int i = 0; i < 3; i++) {
		aux += abecedario[rand() % 26];
	}
	//a.push_back('S'); ASI SE AGREGA UN CHAR A UN STRING
	for (int i = 0; i < 3; i++) {
		aux += to_string(rand() % 9);
	}
	a = aux;
}

//ACTUALIZA FILAS Y LAS PASA AL VECTOR DE STRINGS CADA VEZ QUE SE AGREGUE UNA COLUMNA
void Actualizar_Fila(list<string> &filas, vector<string> &fil) {
	filas.clear();

	for (int i = 0; i < fil.size(); i++) {
		filas.push_back(fil.at(i));
	}
}

//Genera Datos los datos aleatorios por defecto de la tabla
void Generar_Tabla(vector<Arbol_Binario<int>> &vector_entero, vector<Arbol_Binario<char>> &vector_caracter, vector<Arbol_Binario<string>> &vector_cadena, vector<string>&fc, function<bool(Datos<int>, int)> criterio, function<bool(Datos<char>, int)> criterio_char, function<bool(Datos<string>, int)> criterio_str) {
	Arbol_Binario<int> arbol_entero;
	Arbol_Binario<char> arbol_caracter;
	Arbol_Binario<string> arbol_string;
	int var = 1000;
	int calc = var / 100;
	int cont = 0;
	int asd = 1;
	for (int i = 0; i < var; i++) {
		int ent = 17 + rand() % 22;
		string a = sexo[rand() % 2];
		string b = Equipos[rand() % 3];
		char aa = a.at(0);

		arbol_entero.insertar(ent, criterio);
		arbol_caracter.insertar(aa, criterio_char);
		arbol_string.insertar(b, criterio_str);
		string ab;
		if (b == "UPC" || b == "USIL") {
			ab = to_string(ent) + "\t" + a + "\t" + b + "\t";
		}
		else {
			ab = to_string(ent) + "\t" + a + "\t" + b;
		}

		fc.push_back(ab);
		if (cont == calc) {
			system("cls");
			Console::SetCursorPosition(44, 13); cout << "Generando Datos: ";
			cout << asd << "%" << endl;
			cont = 0;
			asd++;
		}
		cont++;
	}
	vector_entero.push_back(arbol_entero);
	vector_caracter.push_back(arbol_caracter);
	vector_cadena.push_back(arbol_string);
}

void Agregar_Columna_int_manual(vector<Arbol_Binario<int>> &vector_entero, vector<string>&vc, function<bool(Datos<int>, int)> criterio, list<string> &filas, string &num_columnas) {
	Arbol_Binario<int> arbol_aux;
	int tam = vector_entero.size();
	cout << endl;
	for (int i = 0; i < vector_entero.at(0).Get_Cantidad(); i++) {
		int ent;
		cout << endl << "Ingrese numero " << i + 1 << ": "; cin >> ent;
		vc.at(i) += "\t" + to_string(ent);
		arbol_aux.insertar(ent, criterio);
		Actualizar_Fila(filas, vc);
		system("cls");
		for (auto it : filas) { cout << it << endl; }
	}
	cout << endl;
	num_columnas += "\t" + to_string(tam);
	vector_entero.push_back(arbol_aux);
}

void Agregar_Columna_int_automatico(vector<Arbol_Binario<int>> &vector_entero, vector<string>&vc, function<bool(Datos<int>, int)> criterio, list<string> &filas, string &num_columnas) {
	Arbol_Binario<int> arbol_aux;
	int tam = vector_entero.size();
	for (int i = 0; i < vector_entero.at(0).Get_Cantidad(); i++) {
		int ent;
		ent = rand() % 100;
		vc.at(i) += "\t" + to_string(ent);
		arbol_aux.insertar(ent, criterio);
	}
	num_columnas += "\t" + to_string(tam);
	vector_entero.push_back(arbol_aux);
}

void Agregar_Columna_char_manual(vector<Arbol_Binario<char>> &vector_char, vector<string>&vc, function<bool(Datos<char>, char)> criterio_char, list<string> &filas, string &num_columnas) {
	Arbol_Binario<char> arbol_aux;
	int tam = vector_char.size();
	cout << endl;
	for (int i = 0; i < vector_char.at(0).Get_Cantidad(); i++) {
		string aux, a;
		cout << endl << "Ingrese dato " << i + 1 << ": "; cin >> aux;
		a = aux.at(0);
		vc.at(i) += "\t" + a;
		char ab = aux.at(0);
		arbol_aux.insertar(ab, criterio_char);
		Actualizar_Fila(filas, vc);
		system("cls");
		for (auto it : filas) { cout << it << endl; }
	}
	cout << endl;
	num_columnas += "\t" + to_string(tam);
	vector_char.push_back(arbol_aux);
}

void Agregar_Columna_char_automatico(vector<Arbol_Binario<char>> &vector_char, vector<string>&vc, function<bool(Datos<char>, char)> criterio_char, list<string> &filas, string &num_columnas) {
	Arbol_Binario<char> arbol_aux;
	int tam = vector_char.size();
	for (int i = 0; i < vector_char.at(0).Get_Cantidad(); i++) {
		string aux, a;
		aux = abecedario[rand() % 26];
		a = aux.at(0);
		vc.at(i) += "\t" + a;
		char ab = aux.at(0);
		arbol_aux.insertar(ab, criterio_char);
	}
	num_columnas += "\t" + to_string(tam);
	vector_char.push_back(arbol_aux);
}

void Agregar_Columna_str_manual(vector<Arbol_Binario<string>> &vector_string, vector<string>&vc, function<bool(Datos<string>, int)> criterio_str, list<string> &filas, string &num_columnas) {
	Arbol_Binario<string> arbol_aux;
	cout << endl;
	int tam = vector_string.size();
	for (int i = 0; i < vector_string.at(0).Get_Cantidad(); i++) {
		string aux;
		cout << endl << "Ingrese dato " << i + 1 << ": "; cin >> aux;
		vc.at(i) += "\t" + aux;
		arbol_aux.insertar(aux, criterio_str);
		Actualizar_Fila(filas, vc);
		system("cls");
		for (auto it : filas) { cout << it << endl; }
	}
	num_columnas += "\t" + to_string(tam);
	cout << endl;
	vector_string.push_back(arbol_aux);
}

void Agregar_Columna_str_automatico(vector<Arbol_Binario<string>> &vector_string, vector<string>&vc, function<bool(Datos<string>, int)> criterio_str, list<string> &filas, string &num_columnas) {
	Arbol_Binario<string> arbol_aux;
	int tam = vector_string.size();
	for (int i = 0; i < vector_string.at(0).Get_Cantidad(); i++) {
		string aux;
		Generacion_Codigo(aux);
		vc.at(i) += "\t" + aux;
		arbol_aux.insertar(aux, criterio_str);
	}
	num_columnas += "\t" + to_string(tam);
	vector_string.push_back(arbol_aux);
}

template<typename G>
void Mostrar_Filtro(vector<Arbol_Binario<G>> &vector_enteros, vector<string> conv, function<bool(Datos<G>, G)>criterio, G dato, int pos) {
	vector<int> *indices = new vector<int>;

	vector_enteros.at(pos).Filtro(dato, indices, criterio);

	for (int j = 0; j < indices->size(); j++) {
		for (int i = 0; i < conv.size(); i++) {
			if (indices->at(j) == i) {
				cout << conv.at(i) << endl;
			}
		}
	}
}

void Guardar(list<string>fil, string nom) {
	string aux = nom + ".txt";
	ofstream escribir(aux);
	ofstream escribir_2(aux);

	escribir.clear();

	for (auto it : fil) {
		escribir_2 << it << endl;
	}
}

template<typename G>
void Ordenar_Todo(vector<Arbol_Binario<G>> vector_, vector<string>filas, int op, int pos) {
	vector<int>ind;
	system("cls");
	if (op == 1) {
		vector_.at(pos).posorden_indice(ind);

		for (int i = 0; i < filas.size(); i++) {
			cout << filas.at(ind.at(i)) << endl;
		}
	}

	if (op == 2) {
		vector_.at(pos).preorden_indice(ind);

		for (int i = 0; i < filas.size(); i++) {
			cout << filas.at(ind.at(i)) << endl;
		}
	}

	if (op == 3) {
		vector_.at(pos).enorden_indice(ind);

		for (int i = 0; i < filas.size(); i++) {
			cout << filas.at(ind.at(i)) << endl;
		}
	}
}

template<typename G>
void Borrar_Arboles(vector<Arbol_Binario<G>> arbol) {
	for (int i = 0; i < arbol.size(); i++) {
		arbol.at(i).borrar_todo();
	}
}

template<typename G>
void Mostrar_columna_indice(vector<Arbol_Binario<G>> v_c, int pos, function<void(Datos<G>)>criterio_impresion) {
	v_c.at(pos).enorden(criterio_impresion);
}

void Dividir_Campos(istream& registro, Arbol_Binario<int> &aux_int, Arbol_Binario<char> &aux_char, Arbol_Binario<string> &aux_string, function<bool(Datos<int>, int)> insercion, function<bool(Datos<char>, int)> insercion_char, function<bool(Datos<string>, int)> insercion_string, vector<string>&conversion) {
	int dato; char dato_c;
	string tmp, aux, aux_2;

	getline(registro, tmp, '\t');
	dato = stoi(tmp);
	getline(registro, tmp, '\t');
	dato_c = tmp.at(0);
	string ab(1, dato_c);
	getline(registro, tmp, '\t');
	aux = tmp;
	if (ab != "UPC" || ab != "USIL") {
		aux_2 = to_string(dato) + "\t" + ab + "\t" + aux + "\t";
	}
	else {
		aux_2 = to_string(dato) + "\t" + ab + "\t" + aux;
	}

	aux_int.insertar(dato, insercion);
	aux_char.insertar(dato_c, insercion_char);
	aux_string.insertar(aux, insercion_string);

	conversion.push_back(aux_2);
}

void Cargar_Datos(string archivo_n, vector<Arbol_Binario<int>> &vector_entero, vector<Arbol_Binario<char>> &vector_caracter, vector<Arbol_Binario<string>> &vector_string, vector<string>&conversion) {
	string aux = archivo_n + ".txt", cadena;
	ifstream archivo;
	Arbol_Binario<int> aux_int;
	Arbol_Binario<char> aux_char;
	Arbol_Binario<string> aux_str;

	auto insercion = [](Datos<int> n1, int n2) {
		return n1.GetDato() < n2;
	};
	auto insercion_char = [](Datos<char> n1, char n2) {
		return n1.GetDato() < n2;
	};

	auto insercion_string = [](Datos<string> n1, int n2) {
		int s = 0;
		for (int i = 0; i < n1.GetDato().size(); i++) {
			s += n1.GetDato().at(i);
		}
		return s < n2;
	};
	archivo.open(aux);

	while (getline(archivo, cadena)) {
		stringstream ss(cadena);
		Dividir_Campos(ss, aux_int, aux_char, aux_str, insercion, insercion_char, insercion_string, conversion);
	}
	vector_entero.push_back(aux_int);
	vector_caracter.push_back(aux_char);
	vector_string.push_back(aux_str);
}
