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
void MainMenu(std::unordered_map<int, Pipe>& Pipemap, std::unordered_map<int, KS>& KSmap);
void fix();


int main()
{
    std::unordered_map<int, Pipe> Pipemap;
    std::unordered_map<int, KS> KSmap;
    redirect_output_wrapper cerr_out(std::cerr);
    std::string time = std::format("{:%d_%m_%Y %H_%M_%OS}", std::chrono::system_clock::now());
    std::ofstream logfile("log_" + time + ".txt");
    if (logfile)
        cerr_out.redirect(logfile);
    setlocale(LC_ALL, "RU");
    MainMenu(Pipemap, KSmap);

}


void FindPipename(std::unordered_map<int, Pipe>& Pipemap) {
    std::string name;
    if (Pipemap.empty()) {
        std::cout << "Труб нет" << std::endl << std::endl;
    }
    else {
        std::cout << "Для поиска введите имя: ";
        INPUT_LINE(std::cin, name);

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
void FindPipestate(std::unordered_map<int, Pipe>& Pipemap) {
    bool checkst;
    if (Pipemap.empty()) {
        std::cout << "Труб нет" << std::endl << std::endl;
    }
    else {
        std::cout << "Для поиска введите состояние (0 или 1): ";
        checkst = GetCorrectNumber(0, 1);
        for (int i : FindPipeFilter(Pipemap, checkstate, checkst))
            std::cout << Pipemap[i];
    }
}
void FindKSname(std::unordered_map<int, KS>& KSmap) {
    std::string name;
    if (KSmap.empty()) {
        std::cout << "";
    }
    else {
        std::cout << "Для поиска введите имя: ";
        INPUT_LINE(std::cin, name);
        for (int i : FindKSFilter(KSmap, checknameks, name))
            std::cout << KSmap[i];
    }
}
void FindKSwork(std::unordered_map<int, KS>& KSmap) {
    int work;
    if (KSmap.empty()) {
        std::cout << "КС нет" << std::endl << std::endl;
    }
    else {
        std::cout << "Для поиска введите количество цехов: ";
        work = GetCorrectNumber(1, 10000);
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
void DeleteorСhangenamePipe(std::unordered_map<int, Pipe>& Pipemap) {
    int chois;
    FindPipename(Pipemap);
    std::cout << "1.Изменить" << std::endl;
    std::cout << "2.Удалить" << std::endl;
    chois = GetCorrectNumber(0, 2);
    if (chois == 1) {
        ModifyObjectById(Pipemap);
    }
    if (chois == 2) {
        DeleteObjectById(Pipemap);
    }
    if (chois == 0) {
        return;
    }
}
void DeleteorСhangestatePipe(std::unordered_map<int, Pipe>& Pipemap) {
    int chois;
    FindPipestate(Pipemap);
    std::cout << "1.Изменить" << std::endl;
    std::cout << "2.Удалить" << std::endl;
    chois = GetCorrectNumber(0, 2);
    if (chois == 1) {
        ModifyObjectById(Pipemap);
    }
    if (chois == 2) {
        DeleteObjectById(Pipemap);
    }
    if (chois == 0) {
        return;
    }
}
void DeleteorСhangenameKS(std::unordered_map<int, KS>& KSmap) {
    int chois;
    FindKSname(KSmap);
    std::cout << "1.Изменить" << std::endl;
    std::cout << "2.Удалить" << std::endl;
    chois = GetCorrectNumber(0, 2);
    if (chois == 1) {
        ModifyObjectById(KSmap);
    }
    if (chois == 2) {
        DeleteObjectById(KSmap);
    }
    if (chois == 0) {
        return;
    }
}
void DeleteorСhangeworkKS(std::unordered_map<int, KS>& KSmap) {
    int chois;
    FindKSwork(KSmap);
    std::cout << "1.Изменить" << std::endl;
    std::cout << "2.Удалить" << std::endl;
    chois = GetCorrectNumber(0, 2);
    if (chois == 1) {
        ModifyObjectById(KSmap);
    }
    if (chois == 2) {
        DeleteObjectById(KSmap);
    }
    if (chois == 0) {
        return;
    }
}

void savepipe(std::ofstream& fout, std::unordered_map<int, Pipe>& Pipemap) {

    for (auto& p : Pipemap) {
        fout << p.second;
    }
    
}
void saveks(std::ofstream& fout, std::unordered_map<int, KS>& KSmap) {
    for (auto& g : KSmap) {
        fout << g.second;
    }
}




void MainMenu(std::unordered_map<int, Pipe>& Pipemap, std::unordered_map<int, KS>& KSmap) {

    std::string data;
    int usernumber;
    while (1) {
        PrintMainMenu();
        usernumber = GetCorrectNumber(0, 8);
        switch (usernumber) {
        case 1:
            PipesCreate(Pipemap);
            break;
        case 2:
            
            KSCreate(KSmap);
            break;
        case 3:
            PipesPrint(Pipemap);
            KSPrint(KSmap);
            break;
        case 4:
            PipesPrint(Pipemap);
            if (Pipemap.empty()) {
                std::cout << "Добавьте трубу" << std::endl;
            }
            else {
                ModifyObjectById(Pipemap);
            }
            break;
        case 5:
            KSPrint(KSmap);
            ModifyObjectById(KSmap);
            break;
        case 6: {
            std::ofstream fout;
            std::cout << "Ведите имя файла ";
            INPUT_LINE(std::cin, data);
            fout.open("data.txt", std::ios::out);
            if (fout.is_open()) {
                fout << Pipemap.size() << std::endl;
                savepipe(fout, Pipemap);
                fout << KSmap.size() << std::endl;
                saveks(fout, KSmap);
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
                usernumber = GetCorrectNumber(0, 4);
                switch (usernumber) {
                case 1:
                    DeleteorСhangenamePipe(Pipemap);
                    break;
                case 2:
                    DeleteorСhangestatePipe(Pipemap);
                    break;
                case 3:
                    DeleteorСhangenameKS(KSmap);
                    break;
                case 4:
                    DeleteorСhangeworkKS(KSmap);
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
