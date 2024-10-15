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





void PrintMainMenu();
void MainMenu();
void fix();
void SavePipe(std::ofstream& fout, const Pipe& p);
void SaveKS(std::ofstream& fout, const KS& g);
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
    std::unordered_map<int, Pipe> Pipemap;
    std::unordered_map<int, KS> KSmap;
    std::unordered_map<int, Pipe> t;
    std::unordered_map<int, KS> filterKS;
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
        /*case 4:
            if (p.name == "") {
                std::cout << "Для редактирования нажмите 1 и создайте трубу" << "\n";
            }
            else {
                PipeСhange(p);
            }
            break;*/
        /*case 5:
            if (g.name == "") {
                std::cout << "Для редактирования нажмите 2 и создайте КС" << "\n";
            }
            else {
                KSChange(g);
            }
            break;*/
        //case 6:{
        //    std::ofstream fout("result.txt", std::ios::out);
        //    if (fout.is_open()) {
        //        if (p.name == "" && g.name == "") {
        //            std::cout << "Нет данных для записи" << "\n";
        //        }
        //        else {
        //            if (p.name != "") {
        //                fout << "pipe" << std::endl;  // Маркер начала данных трубы
        //                SavePipe(fout, p);
        //                std::cout << "Сохранение трубы прошло успешно!\n";
        //            }
        //            if (g.name != "") {
        //                fout << "ks" << std::endl;  // Маркер начала данных КС
        //                SaveKS(fout, g);
        //                std::cout << "Сохранение КС прошло успешно!\n";
        //            }
        //        }
        //        fout.close();  // Закрываем файл
        //    }
        //    else {
        //        std::cout << "Ошибка открытия файла!" << "\n";
        //    }
        //    break;
        //}
        case 7: {
            std::ifstream fin("result.txt", std::ios::in);
            if (fin.is_open()) {
                p = {};
                g = {};
                std::string marker;
                while (fin >> marker) {  // Считываем маркер
                    if (marker == "pipe") {
                        /*p = LoadPipe(fin);*/  // Загружаем данные трубы
                        std::cout << "Труба загружена!\n";
                    }
                    else if (marker == "ks") {
                       /*g =  LoadKS(fin);*/  // Загружаем данные КС
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
        case 8:
            search(p, Pipemap, t);
            searchKS(g, KSmap, filterKS);
            break;
        case 0:
            return;
        }
    }
}






