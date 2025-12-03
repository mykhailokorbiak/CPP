#include <iostream>
#include <string>
#include <limits>
using namespace std;
struct Node {
    string name;
    double gain, voltage;
    int inputs;
    Node* next;
    Node(string n, double g, double v, int i)
        : name(n), gain(g), voltage(v), inputs(i), next(nullptr) {}
};
class AmplifierList {
    Node* head = nullptr;
public:
    ~AmplifierList() { clear(); }
    bool empty() const { return head == nullptr; }
    void addFront(string name, double g, double v, int i) {
        Node* n = new Node(name, g, v, i);
        n->next = head;
        head = n;
    }
    void addBack(string name, double g, double v, int i) {
        Node* n = new Node(name, g, v, i);
        if (empty()) head = n;
        else {
            Node* t = head;
            while (t->next) t = t->next;
            t->next = n;
        }
    }
    void addAfter(string target, string name, double g, double v, int i) {
        Node* t = head;
        while (t && t->name != target) t = t->next;
        if (!t) throw runtime_error("Елемент не знайдено.");
        Node* n = new Node(name, g, v, i);
        n->next = t->next;
        t->next = n;
    }
    void deleteFront() {
        if (empty()) throw runtime_error("Список порожній.");
        Node* t = head;
        head = head->next;
        delete t;
    }
    void deleteBack() {
        if (empty()) throw runtime_error("Список порожній.");
        if (!head->next) return deleteFront();
        Node* t = head;
        while (t->next->next) t = t->next;
        delete t->next;
        t->next = nullptr;
    }
    void deleteByName(string target) {
        if (empty()) throw runtime_error("Список порожній.");
        if (head->name == target) return deleteFront();
        Node* t = head;
        while (t->next && t->next->name != target) t = t->next;
        if (!t->next) throw runtime_error("Елемент не знайдено.");
        Node* del = t->next;
        t->next = del->next;
        delete del;
    }
    void display() const {
        if (empty()) { cout << "Список порожній.\n"; return; }
        Node* t = head;
        while (t) {
            cout << t->name << " | G=" << t->gain
                 << " | V=" << t->voltage
                 << " | In=" << t->inputs << "\n";
            t = t->next;
        }
    }
    void clear() {
        while (!empty()) deleteFront();
    }
};
void flush() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
int main() {
    AmplifierList list;
    int choice;
    while (true) {
        cout << "\n1.Додати на початок\n2.Додати в кінець\n3.Додати після\n"
             << "4.Видалити з початку\n5.Видалити з кінця\n6.Видалити за назвою\n"
             << "7.Показати список\n8.Очистити\n0.Вихід\nВаш вибір: ";
        cin >> choice;
        flush();
        if (choice == 0) break;
        try {
            string name, target;
            double g, v; int in;
            switch (choice) {
                case 1:
                    cout << "Назва: "; getline(cin, name);
                    cout << "G V In: "; cin >> g >> v >> in; flush();
                    list.addFront(name, g, v, in);
                    break;
                case 2:
                    cout << "Назва: "; getline(cin, name);
                    cout << "G V In: "; cin >> g >> v >> in; flush();
                    list.addBack(name, g, v, in);
                    break;
                case 3:
                    cout << "Після якого: "; getline(cin, target);
                    cout << "Нова назва: "; getline(cin, name);
                    cout << "G V In: "; cin >> g >> v >> in; flush();
                    list.addAfter(target, name, g, v, in);
                    break;
                case 4: list.deleteFront(); break;
                case 5: list.deleteBack(); break;
                case 6:
                    cout << "Назва для видалення: ";
                    getline(cin, target);
                    list.deleteByName(target);
                    break;
                case 7: list.display(); break;
                case 8: list.clear(); cout << "Очищено.\n"; break;
                default: cout << "Невірний вибір.\n";
            }
        }
        catch (exception &e) {
            cout << "Помилка: " << e.what() << "\n";
        }
    }
    return 0;
}
