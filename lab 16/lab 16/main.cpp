#include <iostream>
#include <memory>
#include "OperationalAmplifier.h"
#include "AmpModules.h"
#include "ListNode.h"
using std::cout;
using std::endl;
void demo_unique_ptr()
{
    cout << "\n=== Демонстрація std::unique_ptr ===\n";
    std::unique_ptr<OperationalAmplifier> item1 =
        std::make_unique<OperationalAmplifier>(100000.0, 12.0, 2);
    item1->print();
    std::unique_ptr<OperationalAmplifier> item2 = std::move(item1);
    cout << "Після std::move:\n";
    cout << "item1.get() = " << item1.get() << " (очікуємо nullptr)\n";
    cout << "item2.get() = " << item2.get() << " (адреса об'єкта)\n";
}
void demo_shared_ptr()
{
    cout << "\n=== Демонстрація std::shared_ptr ===\n";
    auto sp1 = std::make_shared<OperationalAmplifier>(200000.0, 15.0, 3);
    cout << "Початковий use_count = " << sp1->getGain()
         << " (сам об'єкт), лічильник посилань: " << sp1.use_count() << endl;
    auto sp2 = sp1;
    auto sp3 = sp1;
    cout << "Після копіювання в sp2 та sp3, use_count = "
         << sp1.use_count() << endl;
    {
        cout << "Входимо у внутрішній блок...\n";
        auto sp4 = sp1;
        cout << "Всередині блоку use_count = " << sp1.use_count() << endl;
        cout << "Виходимо з блоку...\n";
    }
    cout << "Після виходу з блоку use_count = " << sp1.use_count() << endl;
    cout << "Коли sp1, sp2, sp3 вийдуть з області видимості, "
            "об'єкт буде знищено.\n";
}
void demo_weak_ptr_cycle()
{
    cout << "\n=== Демонстрація std::weak_ptr для розриву циклу ===\n";
    std::shared_ptr<AmpModuleA> a;
    std::shared_ptr<AmpModuleB> b;
    {
        auto ampA = OperationalAmplifier(50000.0, 5.0, 2);
        auto ampB = OperationalAmplifier(75000.0, 5.0, 1);
        a = std::make_shared<AmpModuleA>("Модуль A", ampA);
        b = std::make_shared<AmpModuleB>("Модуль B", ampB);
        a->moduleB = b;
        b->moduleA = a;
        cout << "use_count для a (AmpModuleA): " << a.use_count() << endl;
        cout << "use_count для b (AmpModuleB): " << b.use_count() << endl;
        cout << "Виходимо з внутрішнього блоку, але ще тримаємо a та b "
                "у зовнішній області...\n";
    }
    cout << "Після блоку use_count для a: " << a.use_count() << endl;
    cout << "use_count для b: " << b.use_count() << endl;
    cout << "Тепер обнуляємо зовнішні shared_ptr...\n";
    a.reset();
    b.reset();
    cout << "Після reset() обидва об'єкти мають бути знищені "
            "(див. повідомлення деструкторів вище).\n";
    cout << "\nЯкби у AmpModuleB був std::shared_ptr<AmpModuleA> замість "
            "std::weak_ptr<AmpModuleA>,\nто утворився б цикл сильних посилань, "
            "і лічильники ніколи не ставали б нулем,\nщо призвело б до витоку "
            "пам'яті.\n";
}
void demo_doubly_linked_list()
{
    cout << "\n=== Демонстрація двозв'язного списку на smart pointer'ах ===\n";
    auto n1 = std::make_shared<ListNode>(
        OperationalAmplifier(100000.0, 12.0, 2));
    auto n2 = std::make_shared<ListNode>(
        OperationalAmplifier(150000.0, 15.0, 3));
    auto n3 = std::make_shared<ListNode>(
        OperationalAmplifier(220000.0, 24.0, 4));
    n1->setNext(n2);
    n2->setNext(n3);
    cout << "Рух вперед по списку:\n";
    auto current = n1;
    while (current) {
        current->data.print();
        current = current->next;
    }
    cout << "Рух назад по списку:\n";
    current = n3;
    while (current) {
        current->data.print();
        current = current->getPrev();
    }
    cout << "Після виходу з функції весь список буде автоматично "
            "звільнений.\n";
}
int main()
{
    std::cout << "Лабораторна робота №16. Розумні вказівники.\n";
    demo_unique_ptr();
    demo_shared_ptr();
    demo_weak_ptr_cycle();
    demo_doubly_linked_list();
    cout << "\nКінець програми. Уважно подивись на порядок виклику "
            "деструкторів вище.\n";
    return 0;
}
