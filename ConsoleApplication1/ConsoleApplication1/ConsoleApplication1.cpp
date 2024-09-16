// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

struct Pipe
{
    std::string name;
    int length;
    int diameter;
    bool state;

};

struct KS {
    std::string name;
    int workshops;
    int workshops_work;
    int efficiency;

};

Pipe PipeGen();
void Pipeprint(Pipe p);
KS KSCreate();
void KSPrint(KS g);

int main()
{
    setlocale(LC_ALL, "RU");
    Pipe p = PipeGen();
    Pipeprint(p);
    KS g = KSCreate();
    KSPrint(g);

}

Pipe PipeGen() {

    Pipe p;
    std::cout << "Введите название для трубы: ";
    std::cin >> p.name;
    std::cout << "Введите длину: ";
    while (!(std::cin >> p.length)) {
        std::cout << "Ошибка ввода. Введите целое число для длины: ";
        std::cin.clear(); // Сброс состояния потока
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "Введите диаметр: ";
    while (!(std::cin >> p.diameter)) {
        std::cout << "Ошибка ввода. Введите целое число для диаметра: ";
        std::cin.clear(); // Сброс состояния потока
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "Введите состояние: ";
    while (!(std::cin >> p.state)) {
        std::cout << "Ошибка ввода. Введите 1 для исправно или 0 для в работе ";
        std::cin.clear(); // Сброс состояния потока
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return p;
}

void Pipeprint(Pipe p) {
    std::cout << "\n";
    std::cout << "Название: " << p.name << std::endl;
    std::cout << "Длина: " << p.length << std::endl;
    std::cout << "Диаметр: " << p.diameter << std::endl;
    std::cout << "Состояние: " << (p.state ? "Исправна" : "В работе") << std::endl;

}

KS KSCreate() {

    KS g;
    std::cout << "\n";
    std::cout << "Введите название для КС: ";
    std::cin >> g.name;
    std::cout << "Введите количество цехов: ";
    while (!(std::cin >> g.workshops)) {
        std::cout << "Ошибка ввода. Введите целое число цехов: ";
        std::cin.clear(); // Сброс состояния потока
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "Введите количество цехов в работе: ";
    while (!(std::cin >> g.workshops_work)) {
        std::cout << "Ошибка ввода. Введите целое число цехов в работе: ";
        std::cin.clear(); // Сброс состояния потока
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "Введите Эффективность: ";
    while (!(std::cin >> g.efficiency)) {
        std::cout << "Ошибка ввода. Введите целое число эффективности: ";
        std::cin.clear(); // Сброс состояния потока
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return g;
}

void KSPrint(KS g) {
    std::cout << "\n";
    std::cout << "Название: " << g.name << std::endl;
    std::cout << "Количество цехов: " << g.workshops << std::endl;
    std::cout << "Количество цехов в работе: " << g.workshops_work << std::endl;
    std::cout << "Эффективность: " << g.efficiency << std::endl;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
