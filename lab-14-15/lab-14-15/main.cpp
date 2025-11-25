#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
struct Node {
    string name;
    double gain;
    double voltage;
    int inputs;
    Node* next;
    Node(string n, double g, double v, int i)
        : name(n), gain(g), voltage(v), inputs(i), next(nullptr) {}
};
class AmplifierList {
private:
    Node* head;
public:
    AmplifierList() : head(nullptr) {}
    ~AmplifierList() { clear(); }
    bool isEmpty() const { return head == nullptr; }
    void addFront(string name, double gain, double voltage, int inputs) {
        Node* newNode = new Node(name, gain, voltage, inputs);
        newNode->next = head;
        head = newNode;
        cout << "Елемент додано на початок списку.\n";
    }
    void addBack(string name, double gain, double voltage, int inputs) {
        Node* newNode = new Node(name, gain, voltage, inputs);
        if (isEmpty()) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << "Елемент додано в кінець списку.\n";
    }
    void addAfter(string searchName, string name, double gain, double voltage, int inputs) {
        if (isEmpty()) throw runtime_error("Список порожній!");
        Node* temp = head;
        while (temp && temp->name != searchName)
            temp = temp->next;
        if (!temp) throw runtime_error("Елемент не знайдено!");
        Node* newNode = new Node(name, gain, voltage, inputs);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Елемент додано після " << searchName << ".\n";
    }
    void deleteFront() {
        if (isEmpty()) throw runtime_error("Список порожній!");
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Елемент з початку видалено.\n";
    }
    void deleteBack() {
        if (isEmpty()) throw runtime_error("Список порожній!");
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
        cout << "Елемент з кінця видалено.\n";
    }
    void deleteByName(string searchName) {
        if (isEmpty()) throw runtime_error("Список порожній!");
        if (head->name == searchName) {
            deleteFront();
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->name != searchName)
            temp = temp->next;
        if (!temp->next) throw runtime_error("Елемент не знайдено!");
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
        cout << "Елемент \"" << searchName << "\" видалено.\n";
    }
    void display() const {
        if (isEmpty()) {
            cout << "Список порожній.\n";
            return;
        }
        cout << "\n=== Список операційних підсилювачів ===\n";
        Node* temp = head;
        while (temp) {
            cout << "Назва: " << temp->name
                 << " | Коеф. підсилення: " << temp->gain
                 << " | Напруга живлення: " << temp->voltage
                 << " | Кількість входів: " << temp->inputs << endl;
            temp = temp->next;
        }
        cout << "========================================\n";
    }
    void clear() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        cout << "Список очищено.\n";
    }
};
int main() {
    AmplifierList list;
    int choice;
    while (true) {
        cout << "\n--- МЕНЮ ---\n"
             << "1. Додати на початок\n"
             << "2. Додати в кінець\n"
             << "3. Додати після елемента\n"
             << "4. Видалити з початку\n"
             << "5. Видалити з кінця\n"
             << "6. Видалити за назвою\n"
             << "7. Вивести список\n"
             << "8. Очистити список\n"
             << "0. Вихід\n"
             << "Ваш вибір: ";
        cin >> choice;

        try {
            if (choice == 0) break;
            string name, searchName;
            double gain, voltage;
            int inputs;
            switch (choice) {
                case 1:
                    cout << "Введіть (назва коеф_підсилення напруга входи): ";
                    cin >> name >> gain >> voltage >> inputs;
                    list.addFront(name, gain, voltage, inputs);
                    break;
                case 2:
                    cout << "Введіть (назва коеф_підсилення напруга входи): ";
                    cin >> name >> gain >> voltage >> inputs;
                    list.addBack(name, gain, voltage, inputs);
                    break;
                case 3:
                    cout << "Після якого елемента вставити? ";
                    cin >> searchName;
                    cout << "Введіть (назва коеф_підсилення напруга входи): ";
                    cin >> name >> gain >> voltage >> inputs;
                    list.addAfter(searchName, name, gain, voltage, inputs);
                    break;
                case 4:
                    list.deleteFront();
                    break;
                case 5:
                    list.deleteBack();
                    break;
                case 6:
                    cout << "Введіть назву для видалення: ";
                    cin >> searchName;
                    list.deleteByName(searchName);
                    break;
                case 7:
                    list.display();
                    break;
                case 8:
                    list.clear();
                    break;
                default:
                    cout << "Невірний вибір!\n";
            }
        }
        catch (const exception& e) {
            cerr << "Помилка: " << e.what() << endl;
        }
    }

    cout << "Програму завершено.\n";
    return 0;
}
