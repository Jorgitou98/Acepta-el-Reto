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
    int elem;
    in >> elem;
    if (elem == -1) {
        return BinTree<T>();
    }
    else {
        BinTree<T> left = read_tree<T>(in);
        BinTree<T> right = read_tree<T>(in);
        BinTree<T> result(left, elem, right);
        return result;
    }
}

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct tSolucion {
    bool es_avl;
    int min;
    int max;
    int altura;
};

tSolucion resuelve_problema(BinTree<int> arbol) {
    if (arbol.empty()) return { true, INT_MAX, INT_MIN, 0 };
    tSolucion sol_izqdo = resuelve_problema(arbol.left());
    tSolucion sol_derecho = resuelve_problema(arbol.right());
    if (sol_izqdo.es_avl && sol_derecho.es_avl && abs(sol_izqdo.altura - sol_derecho.altura) <= 1 &&
        arbol.root() > sol_izqdo.max && arbol.root() < sol_derecho.min) {
        int min = sol_izqdo.min;
        if (min == INT_MAX) min = arbol.root();
        int maxi = sol_derecho.max;
        if (maxi == INT_MIN) maxi = arbol.root();
        int altura = max(sol_izqdo.altura, sol_derecho.altura) + 1;
        return { true, min, maxi, altura };
    }
    else {
        return { false, -1, -1, -1 };
    }
}

void resuelve_caso() {
    BinTree<int> arbol = read_tree<int>(cin);
    tSolucion sol = resuelve_problema(arbol);
    if (sol.es_avl) cout << "SI\n";
    else cout << "NO\n";
}


int main() {

    int num_casos;
    cin >> num_casos;
    for (int i = 0; i < num_casos; i++) resuelve_caso();

    return 0;
}