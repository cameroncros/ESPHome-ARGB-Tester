#include <iostream>
#include <unistd.h>
#include "Color.hpp"

#define byte uint8_t

using namespace esphome;

class RGBRangeView {
    std::vector<Color> *leds;
public:
    explicit RGBRangeView(std::vector<Color> *leds) {
        this->leds = leds;
    }

    RGBRangeView& operator=(const Color &a)
    {
        for (auto & led : *leds) {
            led = a;
        }
        return *this;  // Return a reference to myself.
    }
};


class RGBList {
    public:
    std::vector<Color>* leds;
    RGBRangeView* range_view;

    explicit RGBList(const int size) {
        leds = new std::vector<Color>(size);
        range_view = new RGBRangeView(leds);
    }

    ~RGBList() {
        delete[] leds;
        delete range_view;
    }

    Color& at(const int index) {
        return leds->at(index);
    }

    RGBRangeView all() {
        return RGBRangeView(leds);
    }

    int size() {
        return this->leds->size();
    }

    Color& operator[](int index) {
        return this->leds->at(index);
    }
};


void ESP_LOGD(const char* unused, const char* unused2) {
}
int random(int max) {
    return rand()%max;
}

int random(int min, int max) {
    return (rand() % (max-min))+min;
}

void lambda_fn(RGBList &it, bool initial_run) {
#define ESPColor Color
#define light esphome
#include "lambda.txt"
}


void print_rgb(RGBList &it, const int len) {
    for (int i = 0; i < len; i++) {
        printf("\e[48;2;%i;%i;%im ", it.at(i).red, it.at(i).green, it.at(i).blue);
    }
    fflush(stdout);
    printf("\e[48;2;0;0;0m\n");
}

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    auto rgb = RGBList(50);
    for (int i = 0; i < UINT32_MAX; i++) {
        lambda_fn(rgb, i==0);
        print_rgb(rgb, 50);
        usleep(100000);
    }
    return 0;
}