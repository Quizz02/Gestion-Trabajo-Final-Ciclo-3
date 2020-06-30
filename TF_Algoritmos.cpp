#include "Control.h"

int main()
{
	Console::CursorVisible = false;
	Controladora *control = new Controladora();
	srand(time(NULL));

	auto criterio_insercion = [](Datos<int> n1, int n2) {
		return n1.GetDato() < n2;
	};

	auto criterio_insercion_char = [](Datos<char> n1, char n2) {
		return n1.GetDato() < n2;
	};

	auto criterio_insercion_string = [](Datos<string> n1, int n2) {
		int s = 0;
		for (int i = 0; i < n1.GetDato().size(); i++) {
			s += n1.GetDato().at(i);
		}
		return s < n2;
	};

	auto impresion = [](Datos<int> x) {
		cout << x.GetDato() << endl;
	};

	auto impresion_char = [](Datos<char> x) {
		cout << x.GetDato() << endl;
	};

	auto impresion_string = [](Datos<string> x) {
		cout << x.GetDato() << endl;
	};

	//FILTRO PARA INT'S
	auto obtener_mayor = [](Datos<int> datos, auto valor) {
		return datos.GetDato() > valor;
	};

	auto obtener_menor = [](Datos<int> datos, auto valor) {
		return datos.GetDato() < valor;
	};

	auto obtener_igual = [](Datos<int> datos, auto valor) {
		return datos.GetDato() == valor;
	};

	auto inicia_con = [](Datos<int> datos, auto valor) {
		string a;
		string aux = to_string(datos.GetDato());
		string aux_valor = to_string(valor);

		for (int i = 0; i < aux.size(); i++) {
			a += aux[i];
			if (a == aux_valor) return true;
		}
	};

	auto finaliza_con = [](Datos<int> datos, auto valor) {
		string a;
		string valo = to_string(valor);
		string dat = to_string(datos.GetDato());
		int pos = dat.size() - valo.size();
		for (int i = pos; i < dat.size(); i++) {
			a += dat[i];
			if (valo == a) return true;
		}
	};

	auto no_contiene = [](Datos<int> datos, auto valor) {
		string va = to_string(valor);
		string dat = to_string(datos.GetDato());
		int ab = dat.find(va);
		if (!(ab >= 0)) return true;
	};

	auto contiene = [](Datos<int> datos, auto valor) {
		string va = to_string(valor);
		string dat = to_string(datos.GetDato());
		int ab = dat.find(va);
		if (ab >= 0) return true;
	};


	//FILTRO PARA STRINGS
	auto obtener_igual_str = [](Datos<string> datos, auto valor) {
		return !(datos.GetDato().compare(valor));
	};

	auto obtener_distinto_str = [](Datos<string> datos, auto valor) {
		return datos.GetDato().compare(valor);
	};

	auto obtener_mayor_str = [](Datos<string> datos, auto valor) {
		int aux = 0, aux1 = 0;
		for (size_t i = 0; i < datos.GetDato().size(); i++) {
			aux += datos.GetDato()[i];
		}

		for (size_t i = 0; i < valor.size(); i++) {
			aux1 += valor[i];
		}

		return aux > aux1;
	};

	auto obtener_menor_str = [](Datos<string> datos, auto valor) {
		int aux = 0, aux1 = 0;
		for (size_t i = 0; i < datos.GetDato().size(); i++) {
			aux += datos.GetDato()[i];
		}

		for (size_t i = 0; i < valor.size(); i++) {
			aux1 += valor[i];
		}

		return aux < aux1;
	};

	auto inicia_con_str = [](Datos<string> datos, auto valor) {
		string a;
		for (int i = 0; i < datos.GetDato().size(); i++) {
			a += datos.GetDato()[i];
			if (a == valor) return true;
		}
	};

	auto finaliza_con_str = [](Datos<string> datos, auto valor) {
		string a;
		int pos = datos.GetDato().size() - valor.size();
		for (int i = pos; i < datos.GetDato().size(); i++) {
			a += datos.GetDato()[i];
			if (valor == a) return true;
		}
	};

	auto no_contiene_str = [](Datos<string> datos, auto valor) {
		int ab = datos.GetDato().find(valor);
		if (!(ab >= 0)) return true;
	};

	auto contiene_str = [](Datos<string> datos, auto valor) {
		int ab = datos.GetDato().find(valor);
		if (ab >= 0) return true;
	};

	//FILTRO PARA CHAR'S
	auto obtener_igual_char = [](Datos<char> datos, auto valor) {
		return !(datos.GetDato().CompareTo(valor));
	};

	auto obtener_distinto_char = [](Datos<char> datos, auto valor) {
		return datos.GetDato().CompareTo(valor);
	};

	auto obtener_menor_char = [](Datos<char> datos, auto valor) {
		return datos.GetDato() < valor;
	};

	auto obtener_mayor_char = [](Datos<char> datos, auto valor) {
		return datos.GetDato() > valor;
	};

	control->Inicio(criterio_insercion, criterio_insercion_char, criterio_insercion_string, impresion, impresion_char, impresion_string, obtener_mayor,
		obtener_menor, obtener_igual, inicia_con, finaliza_con, no_contiene, contiene, obtener_igual_str, obtener_distinto_str, obtener_mayor_str,
		obtener_menor_str, inicia_con_str, finaliza_con_str, no_contiene_str, contiene_str, obtener_igual_char, obtener_distinto_char, obtener_menor_char, obtener_mayor_char);

	return 0;
}
