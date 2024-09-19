// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>


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
void PipePrint(const Pipe& p);
KS KSCreate();
void KSPrint(const KS& g);
void PipeСhange(Pipe& p);
void KSChange(KS& g);
void PrintMainMenu();
void MainMenu();
void fix();
void SavePipe(std::ofstream& fout, const Pipe& p);
void SaveKS(std::ofstream& fout, const KS& g);
Pipe LoadPipe(std::ifstream& fin);
KS LoadKS(std::ifstream& fin);

int main()
{
    setlocale(LC_ALL, ".1251");
    //SetConsoleCP(1251);
    PrintMainMenu();
    MainMenu();

}

Pipe PipeGen() {

    Pipe p;
    std::cout << "Введите название для трубы: ";
    std::cin >> std::ws;
    getline(std::cin, p.name);
    std::cout << "Введите длину: ";
    while (!(std::cin >> p.length) || p.length <= 0) {
        std::cout << "Ошибка ввода. Введите целое число для длины отличное от нуля: ";
        fix();
    }
    std::cout << "Введите диаметр: ";
    while (!(std::cin >> p.diameter) || p.diameter <= 0) {
        std::cout << "Ошибка ввода. Введите целое число для диаметра: ";
        fix();
    }
    std::cout << "Введите состояние: ";
    while (!(std::cin >> p.state)) {
        std::cout << "Ошибка ввода. Введите 1 для исправно или 0 для в работе ";
        fix();
    }
    return p;
}

void PipePrint(const Pipe& p) {
    std::cout << "\n";
    std::cout << "Название: " << p.name << std::endl;
    std::cout << "Длина: " << p.length << std::endl;
    std::cout << "Диаметр: " << p.diameter << std::endl;
    std::cout << "Состояние: " << (p.state ? "Исправна" : "В ремонте") << std::endl;

}

KS KSCreate() {

    KS g;
    std::cout << "\n";
    std::cout << "Введите название для КС: ";
    std::cin >> std::ws;
    getline(std::cin, g.name);
    std::cout << "Введите количество цехов: ";
    while (!(std::cin >> g.workshops) || g.workshops <= 0) {
        std::cout << "Ошибка ввода. Введите целое число цехов отличное от нуля: ";
        fix();
    }
    std::cout << "Введите количество цехов в работе: ";
    while (!(std::cin >> g.workshops_work) || (g.workshops < g.workshops_work) || g.workshops_work < 0) {
        std::cout << "Ошибка ввода. Введите корректное число цехов в работе (количество цехов в работе должно быть меньше количества цехов): ";
        fix();
    }
    std::cout << "Введите Эффективность: ";
    while (!(std::cin >> g.efficiency) || g.efficiency <= 0 || g.efficiency > 100) {
        std::cout << "Ошибка ввода. Введите целое число эффективности в диапозоне от 1 до 100: ";
        fix();
    }
    return g;
}

void KSPrint(const KS& g) {
    std::cout << "\n";
    std::cout << "Название: " << g.name << std::endl;
    std::cout << "Количество цехов: " << g.workshops << std::endl;
    std::cout << "Количество цехов в работе: " << g.workshops_work << std::endl;
    std::cout << "Эффективность: " << g.efficiency << std::endl;
}

void PipeСhange(Pipe& p) {
    std::cout << "\n";
    std::cout << "Отредактируйте состояние ";
    while (!(std::cin >> p.state)) {
        std::cout << "Ошибка ввода. Введите 1 для исправно или 0 для в работе ";
        fix();
    }
    //PipePrint(p);
}

void KSChange(KS& g) {
    int workshops_work_new;

    std::cout << "\n";
    std::cout << "Отредактируйте состояние ";
    while (!(std::cin >> workshops_work_new)) {
        std::cout << "Ошибка ввода. Введите корректное значение  ";
        fix();
    }
    //KSPrint(g);
    
    if ((workshops_work_new + g.workshops_work) > g.workshops_work || (workshops_work_new + g.workshops_work) <= 0) {
        std::cout << "Введите корректное знаечение: ";
    }
    else {
        g.workshops_work = g.workshops_work + workshops_work_new;
    }
}

void PrintMainMenu() {
    std::cout << 
        "1. Добавить трубу" << "\n"
        "2. Добавить КС" << "\n"
        "3. Просмотр всех объектов" << "\n"
        "4. Редактировать трубу" << "\n"
        "5. Редактировать КС" << "\n"
        "6. Сохранить" << "\n"
        "7. Загрузить" << "\n"
        "0. Выход" << "\n" << "\n";
}

void MainMenu() {
    Pipe p;
    KS g;
    int usernumber;
    while (1) {
        while (!(std::cin >> usernumber)) {
            std::cout << "Ошибка ввода. Введите корректное значение  ";
            fix();
        }
        switch (usernumber) {
        case 1:
            p = PipeGen();
            PipePrint(p);
            break;
        case 2:
            g = KSCreate();
            KSPrint(g);
            break;
        case 3:
            if (p.name == "" && g.name == "") {
                std::cout << "Нет данных для вывода" << "\n";
            }
            else {
                if (p.name != "") {
                    PipePrint(p);  // Выводим данные о трубе, если она существует
                }

                if (g.name != "") {
                    KSPrint(g);  // Выводим данные о KS, если он существует
                }
            }
            break;
        case 4:
            if (p.name == "") {
                std::cout << "Для редактирования нажмите 1 и создайте трубу" << "\n";
            }
            else {
                PipeСhange(p);
            }
            break;
        case 5:
            if (g.name == "") {
                std::cout << "Для редактирования нажмите 2 и создайте КС" << "\n";
            }
            else {
                KSChange(g);
            }
            break;
        case 6:{
            std::ofstream fout("result.txt", std::ios::out);
            if (fout.is_open()) {
                if (p.name == "" && g.name == "") {
                    std::cout << "Нет данных для записи" << "\n";
                }
                else {
                    if (p.name != "") {
                        fout << "pipe" << std::endl;  // Маркер начала данных трубы
                        SavePipe(fout, p);
                        std::cout << "Сохранение трубы прошло успешно!\n";
                    }
                    if (g.name != "") {
                        fout << "ks" << std::endl;  // Маркер начала данных КС
                        SaveKS(fout, g);
                        std::cout << "Сохранение КС прошло успешно!\n";
                    }
                }
                fout.close();  // Закрываем файл
            }
            else {
                std::cout << "Ошибка открытия файла!" << "\n";
            }
            break;
        }
        case 7: {
            std::ifstream fin("result.txt", std::ios::in);
            if (fin.is_open()) {
                p = {};
                g = {};
                std::string marker;
                while (fin >> marker) {  // Считываем маркер
                    if (marker == "pipe") {
                        p = LoadPipe(fin);  // Загружаем данные трубы
                        std::cout << "Труба загружена!\n";
                    }
                    else if (marker == "ks") {
                       g =  LoadKS(fin);  // Загружаем данные КС
                       std::cout << "КС загружена!\n";
                    }
                }
                fin.close();  // Закрываем файл
            }
            else {
                std::cout << "Ошибка открытия файла!" << "\n";
            }
            break;
        }
        case 0:
            return;
        }
    }
}

void fix() {
    std::cin.clear(); // Сброс состояния потока
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void SavePipe(std::ofstream& fout, const Pipe& p)
{
    fout << p.name << std::endl << p.length << std::endl << p.diameter << std::endl << p.state << std::endl;
}

void SaveKS(std::ofstream& fout, const KS& g)
{
    fout << g.name << std::endl << g.workshops << std::endl << g.workshops_work << std::endl << g.efficiency << std::endl;
}

Pipe LoadPipe(std::ifstream& fin)
{
    Pipe p;
    fin >> std::ws;
    getline(fin, p.name);
    fin >> p.length;
    fin >> p.diameter;
    fin >> p.state;

    return p;
}

KS LoadKS(std::ifstream& fin) {
    KS g;
    fin >> std::ws;
    getline(fin, g.name);
    fin >> g.workshops;
    fin >> g.workshops_work;
    fin >> g.efficiency;

    return g;
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
