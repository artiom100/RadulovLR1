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
    std::unordered_set <int> res;
    redirect_output_wrapper cerr_out(std::cerr);
    std::string time = std::format("{:%d_%m_%Y %H_%M_%OS}", std::chrono::system_clock::now());
    std::ofstream logfile("log_" + time + ".txt");
    if (logfile)
        cerr_out.redirect(logfile);
    setlocale(LC_ALL, "RU");
    MainMenu(Pipemap, KSmap);

}




void PrintMainMenu() {
    std::cout << 
        "1. Добавить трубу" << "\n"
        "2. Добавить КС" << "\n"
        "3. Просмотр всех объектов" << "\n"
        "4. Сохранить" << "\n"
        "5. Загрузить" << "\n"
        "6. Поиск" << "\n"
        "0. Выход" << "\n" << "\n";
}
void Printaddmenu() {
    std::cout << "1.Поиск трубы по имени" << std::endl;
    std::cout << "2.Поиск трубы по состоянию" << std::endl;
    std::cout << "3.Поиск КС по имени" << std::endl;
    std::cout << "4.Поиск КС по цехам" << std::endl;
    std::cout << "0.Выход в основное меню" << std::endl << std::endl;
}
void PrintChois() {
    std::cout << "1.Изменить" << std::endl << "2.Удалить" << std::endl;
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
    std::string name;
    bool state;
    int work;
    int chois;
    std::unordered_set <int> res;
    while (1) {
        PrintMainMenu();
        usernumber = GetCorrectNumber(0, 6);
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
        case 4: {
            std::ofstream fout;
            std::cout << "Ведите имя файла ";
            INPUT_LINE(std::cin, data);
            fout.open(data, std::ios::out);
            if (fout.is_open()) {
                fout << Pipemap.size() << std::endl;
                savepipe(fout, Pipemap);
                fout << KSmap.size() << std::endl;
                saveks(fout, KSmap);
                std::cout << "Сохранение прошло успешно" << std::endl;
            }
            else {
                std::cout << "Не удолось произвести запись в файл." << std::endl;
            }
            break;
        }
        case 5: {
            Load(Pipemap, KSmap);
            break;
        case 6: {
            bool exitSubMenu = false;
            while (!exitSubMenu) {
                Printaddmenu();
                usernumber = GetCorrectNumber(0, 4);
                switch (usernumber) {
                case 1:
                    if (Pipemap.empty()) {
                        std::cout << "Обектов нет" << std::endl;
                        break;
                    }
                    else {
                        std::cout << "Введите имя для поиска ";
                        INPUT_LINE(std::cin, name);
                        res = FindPipeFilter(Pipemap, checknamepipe, name);
                        PrintChois();
                        chois = GetCorrectNumber(1, 2);
                        if (chois == 1) {
                            ChangePipe(Pipemap, res);
                        }
                        if (chois == 2) {
                            DeleteObjectById<Pipe>(Pipemap, res);
                        }
                    }
                    break;
                case 2:
                    if (Pipemap.empty()) {
                        std::cout << "Обектов нет" << std::endl;
                        break;
                    }
                    else {
                        std::cout << "Введите состояние для поиска ";
                        state = GetCorrectNumber(0, 1);
                        res = FindPipeFilter(Pipemap, checkstate, state);
                        PrintChois();
                        chois = GetCorrectNumber(1, 2);
                        if (chois == 1) {
                            ChangePipe(Pipemap, res);
                        }
                        if (chois == 2) {
                            DeleteObjectById<Pipe>(Pipemap, res);
                        }
                    }
                    break;
                case 3:
                    if (KSmap.empty()) {
                        std::cout << "Обектов нет" << std::endl;
                        break;
                    }
                    else {
                        std::cout << "Введите имя для поиска ";
                        INPUT_LINE(std::cin, name);
                        res = FindKSFilter(KSmap, checknameks, name);
                        PrintChois();
                        chois = GetCorrectNumber(1, 2);
                        if (chois == 1) {
                            ChangeKS(KSmap, res);
                        }
                        if (chois == 2) {
                            DeleteObjectById<KS>(KSmap, res);
                        }
                    }
                    break;
                    break;
                case 4:
                    if (KSmap.empty()) {
                        std::cout << "Обектов нет" << std::endl;
                        break;
                    }
                    else {
                        std::cout << "Введите цехи для поиска ";
                        work = GetCorrectNumber(0, 100);
                        res = FindKSFilter(KSmap, workshops, work);
                        PrintChois();
                        chois = GetCorrectNumber(1, 2);
                        if (chois == 1) {
                            ChangeKS(KSmap, res);
                        }
                        if (chois == 2) {
                            DeleteObjectById<KS>(KSmap, res);
                        }
                    }
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
            return;
        }
        }
    }
}
