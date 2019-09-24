#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../logic/data/codes.h"
#include "../sockets/clientSocket.h"
#include "donkeyUI.h"
#include "GameUI.h"
#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include <allegro5/allegro_primitives.h>
#include <dumb.h>
#include <windows.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

static int largoPantalla = 700;
static int anchoPantalla = 700;
static volatile int test = 0;

ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_EVENT_QUEUE* event_queue = NULL;
ALLEGRO_TIMER* timer = NULL;
ALLEGRO_BITMAP  *background = NULL;
ALLEGRO_THREAD* thread = NULL;


bool redraw;
bool done;

int init_game() {

    redraw = true;

    al_init();

    al_init_primitives_addon();
    al_init_image_addon();
    al_install_keyboard();

    display = al_create_display(largoPantalla, anchoPantalla);

    background = al_load_bitmap("../src/ui/img/backgrounds/black_bg.jpg");
    al_draw_bitmap(background,0,0,0);


    al_flip_display();

    timer = al_create_timer(1.0 / 15);
    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_start_timer(timer);
    return 0;
}

int run(){
    ALLEGRO_BITMAP* bitmap;
    bitmap = al_load_bitmap("../src/ui/img/backgrounds/black_bg.jpg");

    int draw = 0;
    int action = -1;
    while(!done) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        if (ev.type == ALLEGRO_EVENT_KEY_UP) {
            switch(ev.keyboard.keycode) {
                case ALLEGRO_KEY_ESCAPE:
                    done = true;
            }
        }
        if (ev.type == ALLEGRO_EVENT_KEY_DOWN){
            switch (ev.keyboard.keycode){
                case ALLEGRO_KEY_UP:
                    action = 6;
                    break;
                case ALLEGRO_KEY_DOWN:
                    action = 7;
                    break;
                case ALLEGRO_KEY_RIGHT:
                    action = 1;
                    break;
                case ALLEGRO_KEY_LEFT:
                    action = 2;
                    break;
                case ALLEGRO_KEY_SPACE:
                    action = 3;
                    break;
                case ALLEGRO_KEY_X:
                    action = 5;
                    break;
                case ALLEGRO_KEY_Z:
                    action = 4;
                    break;
            }
        }
        if (draw == 2){
            draw = 0;
            draw_Matrix(action, display, bitmap);
            action = -1;
            al_flip_display();
        }else{
            draw++;
            test += 10;
        }
    }
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);
    return 0;
}

static void* Func_Thread(ALLEGRO_THREAD *thr, void* arg){
    int i = 0;
    while (i == 0){
        printf("%d \n", test);
    }
}

int main() {
    thread = al_create_thread(Func_Thread, "");
    al_start_thread(thread);
    init_game();
    init_Matrix();
    /*struct Kremlin kremlin1 = {0, 1, 9, -1, -1, 1, 1, 0, 22, 0, 0};
    insertKremlin(&kremlin1);
    struct Kremlin kremlin2 = {0, 12, 13, -1, -1, 1, 1, 0, 21, 0, 0};
    insertKremlin(&kremlin2);


    struct Fruit fruit1 = {1, 6, 6, 1, 100, 31, 0};
    insertFruit(&fruit1);
    //struct Fruit fruit2 = {2, 1, 9, 1, 100, 31, 0};
    //insertFruit(&fruit2);
    struct Fruit fruit3 = {3, 14, 6, 1, 100, 32, 0};
    insertFruit(&fruit3);
    struct Fruit fruit4 = {4, 6, 0, 1, 100, 33, 0};
    insertFruit(&fruit4);
    struct Fruit fruit5 = {5, 11, 8, 1, 100, 33, 0};
    insertFruit(&fruit5);*/
    run();

    return 0;
}

#pragma clang diagnostic pop
