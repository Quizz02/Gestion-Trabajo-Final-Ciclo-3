#pragma once
#include "CDatos.h"

template<class G>
class Arbol_Binario {
private:
	int cantidad;
	template<class G>
	class Nodo { //COMPOSICION
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

	void buscar(Nodo<G> * nodo, G& valor, bool &encontrar, function<bool(G, G)> criterio) {
		if (nodo == nullptr) {
			encontrar = false;  return;
		}

		if (nodo->dato == valor) {
			encontrar = true; return;
		}
		else if (criterio(valor, nodo->dato)) {
			buscar(nodo->izquierda, valor, encontrar, criterio);
		}
		else {
			buscar(nodo->derecha, valor, encontrar, criterio);
		}
	}

	void Buscar_Por_Inicio(Nodo<G> *nodo, G& numero, function<void(G,G)> criterio) {
		if (nodo == nullptr) { return; }

		Buscar_Por_Inicio(nodo->izquierda, numero, criterio);
		criterio(nodo->dato, numero);
		Buscar_Por_Inicio(nodo->derecha, numero, criterio);
	}

	void enorden(Nodo<G> * nodo, function<void(Datos<G>)> criterio_impresion) {
		if (nodo == nullptr)return;
		else {
			enorden(nodo->izquierda, criterio_impresion);
			criterio_impresion(nodo->dato);
			enorden(nodo->derecha, criterio_impresion);
		}
	}

	void preorden(Nodo<G> * nodo, function<void(Datos<G>)> criterio_impresion) {
		if (nodo == nullptr)return;
		else {
			//criterio_impresion(nodo->dato);
			cout << nodo->dato.GetDato();
			preorden(nodo->izquierda, criterio_impresion);
			preorden(nodo->derecha, criterio_impresion);
		}
	}

	void posorden(Nodo<G> * nodo, function<void(G)> criterio_impresion) {
		if (nodo == nullptr)return;
		else {
			posorden(nodo->izquierda, criterio_impresion);
			posorden(nodo->derecha, criterio_impresion);
			criterio_impresion(nodo->datos);
		}
	}

	void borrar_todo(Nodo<G> * nodo) {
		if (nodo != nullptr) {
			borrar_todo(nodo->izquierda);
			borrar_todo(nodo->derecha);
			delete nodo;
		}
	}

	void Sub_Registro(Nodo<G>* nodo, ofstream& archivo) {
		if (nodo == nullptr) return;
		else {
			Sub_Registro(nodo->izquierda, archivo);
			archivo << nodo->datos.Get_Nombre() << " " << nodo->datos.Get_Importe() << " " << nodo->datos.GetNum_Poliza() << endl;
			Sub_Registro(nodo->derecha, archivo);
		}
	}

	void Guardar_Datos_Private(Nodo<G>* nodo) {
		ofstream escritura("Prueba.txt");
		escritura.clear();

		ofstream archivo("Prueba.txt", ios::app);
		Sub_Registro(nodo, archivo);
		archivo.close();
	}

	void Filtro(Nodo<G>*&nodo, G dato, vector<int>*&vecto, function<bool(Datos<G>, G)>criterio) { //FILTRO PARA HALLAR MENORES A 25 
		if (nodo == nullptr)return;
		Filtro(nodo->izquierda, dato, vecto, criterio);
		if(criterio(nodo->dato, dato)) {
			vecto->push_back(nodo->dato.get_indice());
		}
		Filtro(nodo->derecha, dato, vecto, criterio);
	}

	void Obtener_Datos(Nodo<G> *&nodo, vector<int>*&vecto) {
		if (nodo == nullptr)return;
		Obtener_Datos(nodo->izquierda, vecto);

		for (int i = 0; i < vecto->size(); i++) {
			if (vecto->at(i) == nodo->dato.get_indice()) {
				cout << nodo->dato.GetDato() << " ";
			}
		}
		Obtener_Datos(nodo->derecha, vecto);
	}

public:
	Arbol_Binario() { raiz = nullptr; cantidad = 0; }
	~Arbol_Binario() {}
	void insertar(Datos<G> v, function<bool(Datos<G>, int)> criterio) {
		cantidad++;
		v.Set_Indice(cantidad);
		insertar(raiz, v, criterio);
	}

	void Obtener_Datos(vector<int>*&vecto) {
		Obtener_Datos(raiz, vecto);
	}

	void Filtro(G dato, vector<int>*&vecto, function<bool(Datos<G>, G)>criterio) {
		Filtro(raiz, dato, vecto, criterio);
	}
	bool buscar(G v, function<bool(G, G)> criterio) {
		bool encontrado = false;
		buscar(raiz, v, encontrado, criterio);
		return encontrado;
	}
	void borrar_todo() {
		borrar_todo(raiz);
	}
	void mostrar_orden() {
		mostrar_orden(raiz);
	}
	void enorden(function <void(Datos<G>)>criterio_impresion) {
		enorden(raiz, criterio_impresion);
	}
	void preorden(function <void(Datos<G>)>criterio_impresion) {
		preorden(raiz, criterio_impresion);
	}
	void posorden(function <void(G)>criterio_impresion) {
		posorden(raiz, criterio_impresion);
	}
	void Guardar() {
		Guardar_Datos_Private(raiz);
	}

	void Busqueda_Filtro(G& letra, function<void(G, G)> criterio) {
		Buscar_Por_Inicio(raiz, letra, criterio);
	}

};

void Menu() {
	cout << "1. Incersion de columnas. " << endl;
	cout << "2. Incersion de datos. " << endl;
	cout << "3. Mostrar datos del arbol. " << endl;
	cout << "4. Indexado de datos por columnas. " << endl;
	cout << "5. Seleccion de datos por columnas. " << endl;
	cout << "6. Filtrar. " << endl;
	cout << "7. Ordenamiento de datos por columnas. " << endl;
	cout << "8. Guardar datos en un fichero. " << endl;
	cout << "9. Salir. " << endl;
	cout << "Opcion a elegir: ";
}

void Menu_Filtrado() {
	cout << "1. Filtrar por el mayor. " << endl;
	cout << "2. Filtrar por el menor. " << endl;
	cout << "3. Filtrar si es igual a. " << endl;
	cout << "4. Nombre que inicia con. " << endl;
	cout << "5. Esta contenido en. " << endl;
	cout << "6. No esta contenido en. " << endl;
	cout << "7. Buscar por nombre. " << endl;
	cout << "8. Salir. " << endl;
	cout << "Opcion a elegir: ";
}
