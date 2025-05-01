#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <cassert>
#include <memory>

using namespace std;

template <class T> class BinTree {

private:
    struct TreeNode;
    using NodePointer = std::shared_ptr<TreeNode>;

    struct TreeNode {
        TreeNode(const NodePointer& left, const T& elem, const NodePointer& right)
            : elem(elem), left(left), right(right) {}

        T elem;
        NodePointer left, right;
    };

    NodePointer root_node;

    static void display_node(const NodePointer& root, std::ostream& out) {
        if (root == nullptr) {
            out << ".";
        }
        else {
            out << "(";
            display_node(root->left, out);
            out << " " << root->elem << " ";
            display_node(root->right, out);
            out << ")";
        }
    }

public:
    BinTree() : root_node(nullptr) {}

    BinTree(const T& elem)
        : root_node(std::make_shared<TreeNode>(nullptr, elem, nullptr)) {}

    BinTree(const BinTree& left, const T& elem, const BinTree& right)
        : root_node(std::make_shared<TreeNode>(left.root_node, elem,
            right.root_node)) {}

    bool empty() const { return root_node == nullptr; }

    const T& root() const {
        assert(root_node != nullptr);
        return root_node->elem;
    }

    BinTree left() const {
        assert(root_node != nullptr);
        BinTree result;
        result.root_node = root_node->left;
        return result;
    }

    BinTree right() const {
        assert(root_node != nullptr);
        BinTree result;
        result.root_node = root_node->right;
        return result;
    }

    void display(std::ostream& out) const { display_node(root_node, out); }
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const BinTree<T>& tree) {
    tree.display(out);
    return out;
}

template <typename T> BinTree<T> read_tree(std::istream& in) {
    char c;
    in >> c;
    if (c == '.') {
        return BinTree<T>();
    }
    else {
        BinTree<T> left = read_tree<T>(in);
        BinTree<T> right = read_tree<T>(in);
        BinTree<T> result(left, c, right);
        return result;
    }
}

#include <iostream>
#include <algorithm>
using namespace std;

struct tSolucion {
    bool equilibrado;
    int altura;
};

tSolucion es_equilibrado(BinTree<char> const& arbol) {
    if (arbol.empty()) {
        return { true, 0 };
    }
    tSolucion sol_izqdo = es_equilibrado(arbol.left());
    tSolucion sol_derecho = es_equilibrado(arbol.right());
    tSolucion mi_sol;
    mi_sol.equilibrado = sol_izqdo.equilibrado && sol_derecho.equilibrado && abs(sol_izqdo.altura - sol_derecho.altura) <= 1;
    mi_sol.altura = max(sol_izqdo.altura, sol_derecho.altura) + 1;
    return mi_sol;
}


void resuelve_caso() {
    BinTree<char> arbol = read_tree<char>(cin);
    tSolucion sol = es_equilibrado(arbol);
    if (sol.equilibrado) cout << "SI\n";
    else cout << "NO\n";

}

int main() {
    int num_casos;
    cin >> num_casos;
    for (int i = 0; i < num_casos; i++) resuelve_caso();
}