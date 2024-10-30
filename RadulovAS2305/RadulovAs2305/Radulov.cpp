#include <iostream>
#include <string>
#include <fstream>
#include "Pipe.h"
#include "KS.h"
#include "InOut.h"
#include "Tools.h"
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <format>



void PrintMainMenu();
void Printaddmenu();
void MainMenu();
void fix();
std::unordered_map<int, Pipe> Pipemap;
std::unordered_map<int, KS> KSmap;

int main()
{
    redirect_output_wrapper cerr_out(std::cerr);
    std::string time = std::format("{:%d_%m_%Y %H_%M_%OS}", std::chrono::system_clock::now());
    std::ofstream logfile("log_" + time + ".txt");
    if (logfile)
        cerr_out.redirect(logfile);
    setlocale(LC_ALL, "RU");
    MainMenu();

}


void FindPipename() {
    std::string name;
    if (Pipemap.empty()) {
        std::cout << "Труб нет" << std::endl << std::endl;
    }
    else {
        std::cout << "Для поиска введите имя: ";
        std::cin >> name;

        // Выполняем поиск
        std::unordered_set<int> foundPipes = FindPipeFilter(Pipemap, checknamepipe, name);

        // Проверка, найден ли хоть один объект
        if (foundPipes.empty()) {
            std::cout << "Объектов с именем \"" << name << "\" не найдено." << std::endl;
        }
        else {
            for (int i : foundPipes) {
                std::cout << Pipemap[i];
            }
        }
    }
}
void FindPipestate() {
    bool checkst;
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
    std::string name;
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
void FindKSwork() {
    int work;
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
    std::cout << "1.Поиск трубы по имени" << std::endl;
    std::cout << "2.Поиск трубы по состоянию" << std::endl;
    std::cout << "3.Поиск КС по имени" << std::endl;
    std::cout << "4.Поиск КС по цехам" << std::endl;
    std::cout << "0. Выход в основное меню" << std::endl << std::endl;
}
void DeleteorСhangenamePipe() {
    int chois;
    FindPipename();
    std::cout << "1.Изменить" << std::endl;
    std::cout << "2.Удалить" << std::endl;
    std::cin >> chois;
    if (chois == 1) {
        ModifyObjectById(Pipemap);
    }
    if (chois == 2) {
        DeleteObjectById(Pipemap);
    }
}
void DeleteorСhangestatePipe() {
    FindPipestate();
    int chois;
    std::cout << "1.Изменить" << std::endl;
    std::cout << "2.Удалить" << std::endl;
    std::cin >> chois;
    if (chois == 1) {
        ModifyObjectById(Pipemap);
    }
    if (chois == 2) {
        DeleteObjectById(Pipemap);
    }
}
void DeleteorСhangenameKS() {
    int chois;
    FindKSname();
    std::cout << "1.Изменить" << std::endl;
    std::cout << "2.Удалить" << std::endl;
    std::cin >> chois;
    if (chois == 1) {
        ModifyObjectById(KSmap);
    }
    if (chois == 2) {
        DeleteObjectById(KSmap);
    }
}
void DeleteorСhangeworkKS() {
    int chois;
    FindKSwork();
    std::cout << "1.Изменить" << std::endl;
    std::cout << "2.Удалить" << std::endl;
    std::cin >> chois;
    if (chois == 1) {
        ModifyObjectById(KSmap);
    }
    if (chois == 2) {
        DeleteObjectById(KSmap);
    }
}

void savepipe(std::ofstream& fout, const Pipe& p) {
    for (auto& p : Pipemap) {
        fout << p.second;
    }
    
}
void saveks(std::ofstream& fout, const KS& g) {
    for (auto& g : KSmap) {
        fout << g.second;
    }
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
        case 4:
            PipesPrint(Pipemap);
            ModifyObjectById(Pipemap);
            break;
        case 5:
            KSPrint(KSmap);
            ModifyObjectById(KSmap);
            break;
        case 6: {
            std::ofstream fout;
            fout.open("data.txt", std::ios::out);
            if (fout.is_open()) {
                fout << Pipemap.size() << std::endl;
                savepipe(fout, p);
                fout << KSmap.size() << std::endl;
                saveks(fout, g);
            }
            else {
                std::cout << "Не удолось произвести запись в файл.";
            }
            break;
        }
        case 7: {
            Load(Pipemap, KSmap);
            break;
        case 8: {
            bool exitSubMenu = false;
            while (!exitSubMenu) {
                Printaddmenu();
                std::cin >> usernumber;
                
                switch (usernumber) {
                case 1:
                    DeleteorСhangenamePipe();
                    break;
                case 2:
                    DeleteorСhangestatePipe();
                case 3:
                    DeleteorСhangenameKS();
                    break;
                case 4:
                    DeleteorСhangeworkKS();
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
        case 9:

        case 0:
            return;
        default:
            std::cout << "Некорректный ввод. Попробуйте снова.\n";
            break;
        }
        }
    }
}
