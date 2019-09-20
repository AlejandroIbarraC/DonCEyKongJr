/* File: donkeyUI.h
 * Author: Sahid Rojas & Esteban Alvarado
 * Description: This library provides a startup window that allows you to
 *              connect through sockets to a server.
 *
 * Version: 2.4 (2019)
 * Instituto Tecnologico de Costa Rica
 *---------------------------------------------------------------------------*/

#ifndef CLIENT_DONKEYUI_H
#define CLIENT_DONKEYUI_H

#include<stdio.h>
#include <gtk-3.0/gtk/gtk.h>

/*
 * This variables are necessaries for the GUI some of them are: Buttons, Entries, Windows,etc
 * the really significant fact is: they must be global.
 */
GtkWidget *window;
GtkWidget *layout;
GtkWidget *image;
GtkWidget *button;
GtkWidget *button2;
GtkWidget *entry;

// Begins the initial window
int init_Donkey(int argc, char *argv[]);

// Collects the user input and convert it into String
static void get_Input(GtkWidget *widget);

#endif //CLIENT_DONKEYUI_H
