#include <stdio.h>
#include <ctype.h>
#include <malloc.h>

struct page_frame {
    int page;
    int age;
};

int tick = 0;
int length = 0;
struct page_frame* frame;

void error(int page) {
    int min_age = 255;
    for (int i = 0; i < length; i++) {
        if (frame[i].age < min_age) {
            min_age = frame[i].age;
        }
    }
    for (int i = 0; i < length; i++) {
        if (frame[i].age == min_age) {
            frame[i].page = page;
            frame[i].age = 256; // because after it / 2 => it will become 128 = 2^7
            break;
        }
    }
    for (int i = 0; i < length; i++) {
        frame[i].age /= 2;      // new page will become 128
    }
    return;
}

int reference(int page) {
    int hit = -1;
    for (int i = 0; i < length; i++) {
        if (frame[i].page == page) {
            hit = i;
        }
    }
    if (hit != -1) {
        frame[hit].age /= 2;
        frame[hit].age += 128;
        for (int i = 0; i < length; i++) {
            if (i != hit) {
                frame[i].age /= 2;
            }
        }
        tick++;
        return 1;
    } else {
        error(page);
        tick++;
        return 0;
    }
}



int main() {
    length = 10; // we may change it (10, 50, 100)
    frame = calloc(length, sizeof(struct page_frame));
//    printf("Write a length of page frame");
//    scanf("%d", length);
    FILE *fp = fopen("input.txt", "r");
    char c = fgetc(fp);
    int current_number = 0;
    int hit = 0;
    while (c != EOF) {
        if (isdigit(c)){
            current_number = current_number * 10 + (int)(c) - '0';
        }
        c =  fgetc(fp);
        if (c == ' ' || c == EOF) {
            hit += reference(current_number);
            current_number = 0;
        }
    }
    printf("%f", (float)hit / (float)tick);
    return 0;
}