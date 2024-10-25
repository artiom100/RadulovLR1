// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include "Pipe.h"
#include "KS.h"
#include "InOut.h"
#include "Tools.h"
#include <unordered_map>
#include <unordered_set>




void PrintMainMenu();
void Printaddmenu();
void MainMenu();
void fix();
std::unordered_map<int, Pipe> Pipemap;
std::unordered_map<int, KS> KSmap;

//void SavePipe(std::ofstream& fout, const Pipe& p);
//void SaveKS(std::ofstream& fout, const KS& g);
//Pipe LoadPipe(std::ifstream& fin);
//KS LoadKS(std::ifstream& fin);

int main()
{
    setlocale(LC_ALL, ".1251");
    MainMenu();

}





//void PipeСhange(Pipe& p) {
//    std::cout << "\n";
//    std::cout << "Отредактируйте состояние ";
//    std::cout << "\n";
//    while (!(std::cin >> p.Getstate())) {
//        std::cout << "Ошибка ввода. Введите 1 для исправно или 0 для в работе ";
//        fix();
//    }
//}

//void KSChange(KS& g) {
//    int workshops_work_new;
//
//    std::cout << "\n";
//    std::cout << "Отредактируйте состояние ";
//    while (!(std::cin >> workshops_work_new)) {
//        std::cout << "Ошибка ввода. Введите корректное значение  ";
//        fix();
//    }
//    //KSPrint(g);
//    
//    if ((workshops_work_new + g.workshops_work) > g.workshops_work || (workshops_work_new + g.workshops_work) <= 0) {
//        std::cout << "Введите корректное знаечение: ";
//    }
//    else {
//        g.workshops_work = g.workshops_work + workshops_work_new;
//    }
//}

std::string name;
void FindPipename() {
    if (Pipemap.empty()) {
        std::cout << "Труб нет" << std::endl << std::endl;
    }
    else {
        std::cout << "Для поиска введите имя: ";
        std::cin >> name;
        for (int i : FindPipeFilter(Pipemap, checknamepipe, name))
            std::cout << Pipemap[i];
    }
   
}
bool checkst;
void FindPipestate() {
   
    if (Pipemap.empty()) {
        std::cout << "Труб нет" << std::endl << std::endl;
    }
    else {
        std::cout << "Для поиска введите состояние (0 или 1): ";
        while (!(std::cin >> checkst)) {
            std::cout << "Ошибка ввода. Введите корректное значение  ";
            fix();
        }
        for (int i : FindPipeFilter(Pipemap, checkstate, checkst))
            std::cout << Pipemap[i];
    }
}
void FindKSname() {
    if (KSmap.empty()) {
        std::cout << "";
    }
    else {
        std::cout << "Для поиска введите имя: ";
        std::cin >> name;
        for (int i : FindKSFilter(KSmap, checknameks, name))
            std::cout << KSmap[i];
    }
}
int work;
void FindKSwork() {
    if (KSmap.empty()) {
        std::cout << "КС нет" << std::endl << std::endl;
    }
    else {
        std::cout << "Для поиска введите количество цехов: ";
        while (!(std::cin >> work)) {
            std::cout << "Ошибка ввода. Введите корректное значение  ";
            fix();
        }
        for (int i : FindKSFilter(KSmap, workshops, work))
            std::cout << KSmap[i];
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
        "8. Поиск" << "\n"
        "0. Выход" << "\n" << "\n";
}
void Printaddmenu() {
    std::cout << "1.Посик трубы по имени" << std::endl;
    std::cout << "2.Посик трубы по состоянию" << std::endl;
    std::cout << "3.Посик КС по имени" << std::endl;
    std::cout << "4.Посик КС по цехам" << std::endl << std::endl;
}


void MainMenu() {
    Pipe p;
    KS g;
    int usernumber;
    

    while (1) {
        PrintMainMenu();
        while (!(std::cin >> usernumber)) {
            std::cout << "Ошибка ввода. Введите корректное значение  ";
            fix();
        }

        switch (usernumber) {
        case 1:
            std::cin >> p;
            PipesCreate(p, Pipemap);
            break;
        case 2:
            std::cin >> g;
            KSCreate(g, KSmap);
            break;
        case 3:
            PipesPrint(Pipemap);
            KSPrint(KSmap);
            break;
        case 7: {
            break;
        }
        case 8: {
            // Подменю для поиска
            bool exitSubMenu = false;
            while (!exitSubMenu) {
                Printaddmenu(); // Печать подменю
                std::cin >> usernumber;
                switch (usernumber) {
                case 1:
                    FindPipename();
                    break;
                case 2:
                    FindPipestate();
                    break;
                case 3:
                    FindKSname();
                    break;
                case 4:
                    FindKSwork();
                    break;
                case 0:
                    exitSubMenu = true;
                    break;
                default:
                    std::cout << "Некорректный ввод. Повторите попытку.\n";
                    break;
                }
            }
            break;
        }
        case 0:
            return; // Завершение программы
        default:
            std::cout << "Некорректный ввод. Попробуйте снова.\n";
            break;
        }
    }
}






