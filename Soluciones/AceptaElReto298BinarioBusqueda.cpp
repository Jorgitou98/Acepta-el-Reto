#include <iostream>
#include <memory>   // shared_ptr, make_shared
#include <stdexcept>
#include <stack>
#include <vector>
#include <queue>
using namespace std;



template <class T>
class bintree {
protected:
	/*
	Nodo que almacena internamente el elemento (de tipo T),
	y punteros al hijo izquierdo y derecho, que pueden ser
	nullptr si el hijo es vacío (no existe).
	*/
	struct TreeNode;
	using Link = std::shared_ptr<TreeNode>;
	struct TreeNode {
		TreeNode(Link const& l, T const& e, Link const& r) : elem(e), left(l), right(r) {};
		T elem;
		Link left, right;
	};

	// constructora privada
	bintree(Link const& r) : raiz(r) {}

	// puntero a la raíz del árbol
	Link raiz;

public:
	// árbol vacío
	bintree() : raiz(nullptr) {}

	// árbol hoja
	bintree(T const& e) :
		raiz(std::make_shared<TreeNode>(nullptr, e, nullptr)) {}

	// árbol con dos hijos
	bintree(bintree<T> const& l, T const& e, bintree<T> const& r) :
		raiz(std::make_shared<TreeNode>(l.raiz, e, r.raiz)) {}

	// constructora por copia, operador de asignación y destructora por defecto

	// consultar si el árbol está vacío
	bool empty() const {
		return raiz == nullptr;
	}

	// consultar la raíz
	T const& root() const {
		if (empty()) throw std::domain_error("El arbol vacio no tiene raiz.");
		else return raiz->elem;
	}

	// consultar el hijo izquierdo
	bintree<T> left() const {
		if (empty()) throw std::domain_error("El arbol vacio no tiene hijo izquierdo.");
		else return bintree<T>(raiz->left);
	}

	// consultar el hijo derecho
	bintree<T> right() const {
		if (empty()) throw std::domain_error("El arbol vacio no tiene hijo derecho.");
		else return bintree(raiz->right);
	}


	// recorridos

	std::vector<T> preorder() const {
		std::vector<T> pre;
		preorder(raiz, pre);
		return pre;
	}

	std::vector<T> inorder() const {
		std::vector<T> in;
		inorder(raiz, in);
		return in;
	}

	std::vector<T> postorder() const {
		std::vector<T> post;
		postorder(raiz, post);
		return post;
	}

	std::vector<T> levelorder() const {
		std::vector<T> levels;
		if (!empty()) {
			std::queue<Link> pendientes;
			pendientes.push(raiz);
			while (!pendientes.empty()) {
				Link sig = pendientes.front();
				pendientes.pop();
				levels.push_back(sig->elem);
				if (sig->left != nullptr)
					pendientes.push(sig->left);
				if (sig->right != nullptr)
					pendientes.push(sig->right);
			}
		}
		return levels;
	}

protected:
	static void preorder(Link a, std::vector<T> & pre) {
		if (a != nullptr) {
			pre.push_back(a->elem);
			preorder(a->left, pre);
			preorder(a->right, pre);
		}
	}

	static void inorder(Link a, std::vector<T> & in) {
		if (a != nullptr) {
			inorder(a->left, in);
			in.push_back(a->elem);
			inorder(a->right, in);
		}
	}

	static void postorder(Link a, std::vector<T> & post) {
		if (a != nullptr) {
			postorder(a->left, post);
			postorder(a->right, post);
			post.push_back(a->elem);
		}
	}

public:
	// iterador que recorre el árbol en inorden
	class const_iterator {
	public:
		T const& operator*() const {
			if (ptr == nullptr) throw std::out_of_range("fuera del arbol");
			return ptr->elem;
		}

		T const* operator->() const {
			return &operator*();
		}

		bool operator==(const_iterator const& other) const {
			return ptr == other.ptr;
		}
		bool operator!=(const_iterator const& other) const {
			return !(*this == other);
		}

		const_iterator & operator++() {  // ++ prefijo
			next();
			return *this;
		}

	private:
		friend class bintree;
		Link ptr;
		std::stack<Link> ancestros;

		// constructores privados
		const_iterator() : ptr(nullptr) {}
		const_iterator(Link raiz) { ptr = first(raiz); }

		Link first(Link act) {
			if (act == nullptr) {
				return nullptr;
			}
			else {
				while (act->left != nullptr) {
					ancestros.push(act);
					act = act->left;
				}
				return act;
			}
		}

		void next() {
			if (ptr == nullptr) {
				throw std::range_error("El iterador no puede avanzar");
			}
			else if (ptr->right != nullptr) { // primero del hijo derecho
				ptr = first(ptr->right);
			}
			else if (ancestros.empty()) { // hemos llegado al final
				ptr = nullptr;
			}
			else { // podemos retroceder
				ptr = ancestros.top();
				ancestros.pop();
			}
		}

	};

	const_iterator begin() const {
		return const_iterator(raiz);
	}
	const_iterator end() const {
		return const_iterator();
	}

};

// lee un árbol binario de la entrada estándar
template <typename T>
inline bintree<T> leerArbol(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return{};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol(vacio);
		auto dr = leerArbol(vacio);
		return{ iz, raiz, dr };
	}
}

/* Distinguire varios casos teniendo en cuenta que los hijso sean vacios
*/
void esDeBusqueda(bintree<int> const& arbol, int & mayor, int & menor, bool & deBusqueda){ // Coste O(A), siendo A el numero de nodos del árbol. Se pasa por todos los nodos al menos una vez
	if (arbol.empty()) {
		deBusqueda = true;
	}
	else{
		bool deBusquedaI, deBusquedaD;
		int menorI, menorD, mayorI, mayorD;
		bintree<int> arbolI = arbol.left(), arbolD = arbol.right();

		/* Si sus hijos no son vacíos, han de cumplir la condicion ambos y ser el mayor del izquierdo
		menor que la raiz del actual (eso asegura que todos lo son) y la raiz del actual menor que el menor del derecho
		lo que asegura que todos son mayores
		*/

		if (!arbolI.empty() && !arbolD.empty()){ 
			esDeBusqueda(arbolI, mayorI, menorI, deBusquedaI);
			esDeBusqueda(arbolD, mayorD, menorD, deBusquedaD);
			if (deBusquedaI && deBusquedaD && mayorI < arbol.root() && arbol.root() < menorD){
				mayor = mayorD;
				menor = menorI;
				deBusqueda = true;
			}
			else{ // No devuelvo mayor y menor. Nunca lo uso si alguna de las busquedas devuelve false
				deBusqueda = false;
			}
		}

		/* Si su hijo derecho es vacío, se tiene que cumplir lo mismo con el hijo izquierdo. Con el hijo derecho ya se que se cumple
		Distingo este caso aunque tenga caso base para el derecho porque no puedo comparar arbol.root() con arbolD.root(), que no existe*/

		else if (!arbolI.empty()){
			esDeBusqueda(arbolI, mayorI, menorI, deBusquedaI);
			if (deBusquedaI && mayorI < arbol.root()){
					mayor = arbol.root();
					menor = menorI;
					deBusqueda = true;
			}
			else deBusqueda = false;
		}

		/* Caso analogo al anterior pero siendo el vacío el izquierdo
		*/

		else if (!arbolD.empty()){
			esDeBusqueda(arbolD, mayorD, menorD, deBusquedaD);
			if (deBusquedaD && arbol.root() < menorD){
				mayor = mayorD;
				menor = arbol.root();
				deBusqueda = true;
			}
			else deBusqueda = false;
		}
		/* Si el arbol es una hoja evidentemente cumple la condicion puesto que sus hijos la cumplen
		y no tienen nodos con los que comparar la raiz de arbol. El mayor y el menor son el unico nodo que tiene
		*/
		else{
			mayor = arbol.root();
			menor = arbol.root();
			deBusqueda = true;
		}
	}
}


void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	int menor, mayor; // Para las salidas. No los utilizaré para nada
	bool deBusqueda;
	esDeBusqueda(arbol, mayor, menor, deBusqueda);
	if (deBusqueda) cout << "SI\n";
	else cout << "NO\n";
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}
