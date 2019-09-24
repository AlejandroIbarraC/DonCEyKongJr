/* --------------------------------------------------------------------
 * File: GameUI.h
 * author: @estalvgs1999 & chuzz
 * Description: File containing the main ui methods
 * version: 0.1
 * ITCR™ - sabrosos3G®
 * --------------------------------------------------------------------*/

#ifndef CLIENT_GAMEUI_H
#define CLIENT_GAMEUI_H

#include <stdio.h>
#include <allegro5/allegro.h>
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_image.h"

///Inicio de varibales de la pantalla
#define LARGO_PANTALLA 700
#define ANCHO_PANTALLA 700

// Animation properties
static int length = LARGO_PANTALLA;
static int wide = ANCHO_PANTALLA;
ALLEGRO_BITMAP* bitmap;

// Threads properties
static ALLEGRO_THREAD* _thread = NULL;
static int first_time = 1; // indicates that its true

// Matrix Properties
static volatile int* matrix[24][16];
static int iPrev = -1;
static int jPrev = -1;

// Connection properties
static volatile char* recv_JSON = NULL;
static volatile char* Server_IP_ADDR = "127.0.0.1";
static volatile int server_port = 0;
static int flag = 0;



// Inits the screen components
void init_Matrix();

int draw_Matrix(int key_code, ALLEGRO_DISPLAY* display, ALLEGRO_BITMAP* bitmap);
void draw_Floor();
void draw_Water();
void draw_Vine();

void draw_DKJr();
void draw_Croc();
void draw_Ground();
void draw_Fruit();
void draw_Mario();
void draw_DonkeyKong();

static void* sock_Thread(ALLEGRO_THREAD *thread,void* arg);
void set_ServerPort(int serverPort);

int calc_Xpos(int i);
int calc_Ypos(int j);

#endif //CLIENT_GAMEUI_H
