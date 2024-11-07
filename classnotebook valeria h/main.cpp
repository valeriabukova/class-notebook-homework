//
//  main.cpp
//  classnotebook valeria h
//
//  Created by Valeria  Bukova on 07.11.2024.
//

#include <iostream>

class Processor {
public:
    char brand[20];
    double frequency;

    Processor(const char* b, double f) : frequency(f) {
        for (int i = 0; i < 20 && b[i] != '\0'; ++i) {
            brand[i] = b[i];
        }
        
        if (frequency < 1.0 || frequency > 5.0) {
            std::cerr << "Неприпустиме значення частоти: " << frequency << " GHz\n";
            frequency = 2.5;
        }
    }

    void displayInfo() const {
        std::cout << "Processor Brand: " << brand << ", Frequency: " << frequency << " GHz\n";
    }
};

class RAM {
public:
    int size;
    char type[10];

    RAM(int s, const char* t) : size(s) {
        for (int i = 0; i < 10 && t[i] != '\0'; ++i) {
            type[i] = t[i];
        }
        if (size <= 0) {
            std::cerr << "Розмір оперативної пам'яті має бути більшим за 0\n";
            size = 4;
        }
    }

    void displayInfo() const {
        std::cout << "RAM Size: " << size << " GB, Type: " << type << '\n';
    }
};

class HardDrive {
public:
    int capacity;
    char type[10];
    HardDrive(int c, const char* t) : capacity(c) {
        for (int i = 0; i < 10 && t[i] != '\0'; ++i) {
            type[i] = t[i];
        }
        if (capacity <= 0) {
            std::cerr << "Ємність жорсткого диска має бути більшою за 0\n";
            capacity = 256;
        }
    }

    void displayInfo() const {
        std::cout << "Hard Drive Capacity: " << capacity << " GB, Type: " << type << '\n';
    }
};

class Screen {
public:
    double size; // inches
    char resolution[15];

    Screen(double s, const char* r) : size(s) {
        for (int i = 0; i < 15 && r[i] != '\0'; ++i) {
            resolution[i] = r[i];
        }
        if (size < 10.0 || size > 20.0) {
            std::cerr << "Неприпустимий розмір екрану: " << size << " дюймів\n";
            size = 15.6;
        }
    }

    void displayInfo() const {
        std::cout << "Screen Size: " << size << " inches, Resolution: " << resolution << '\n';
    }
};

class Keyboard {
public:
    bool backlight;
    char layout[10];

    Keyboard(bool b, const char* l) : backlight(b) {
        for (int i = 0; i < 10 && l[i] != '\0'; ++i) {
            layout[i] = l[i];
        }
    }

    void displayInfo() const {
        std::cout << "Keyboard Layout: " << layout << ", Backlight: " << (backlight ? "Yes" : "No") << '\n';
    }
};

class Battery {
public:
    int capacity;
    double voltage;

    Battery(int c, double v) : capacity(c), voltage(v) {
        if (capacity <= 0) {
            std::cerr << "Ємність батареї має бути більшою за 0\n";
            capacity = 4000;
        }
        if (voltage < 1.0 || voltage > 5.0) {
            std::cerr << "Неприпустиме значення напруги: " << voltage << " V\n";
            voltage = 3.7;
        }
    }

    void displayInfo() const {
        std::cout << "Battery Capacity: " << capacity << " mAh, Voltage: " << voltage << " V\n";
    }
};

class GPU {
public:
    char model[20];
    int memory; // GB

    GPU(const char* m, int mem) : memory(mem) {
        for (int i = 0; i < 20 && m[i] != '\0'; ++i) {
            model[i] = m[i];
        }
        if (memory < 1) {
            std::cerr << "Пам'ять GPU має бути більше 0\n";
            memory = 2;
        }
    }

    void displayInfo() const {
        std::cout << "GPU Model: " << model << ", Memory: " << memory << " GB\n";
    }
};


int main() {
    Processor proc("Intel", 3.5);
    proc.displayInfo();

    RAM ram(16, "DDR4");
    ram.displayInfo();

    HardDrive hd(512, "SSD");
    hd.displayInfo();

    Screen scr(15.6, "1920x1080");
    scr.displayInfo();

    Keyboard kb(true, "QWERTY");
    kb.displayInfo();

    Battery batt(4500, 3.7);
    batt.displayInfo();

    GPU gpu("NVIDIA GTX 1650", 4);
    gpu.displayInfo();

    return 0;
}
